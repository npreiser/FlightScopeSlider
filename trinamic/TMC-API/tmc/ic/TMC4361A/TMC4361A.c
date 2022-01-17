/*
 * TMC4361A.c
 *
 *  Created on: 18.07.2017
 *      Author: LK
 */

#include "TMC4361A.h"

// Default Register Values
#define R00 0x00006020  // GENERAL_CONF
#define R06 0xFFFFFFFF  // SCALE_VALUES
#define R07 0x00000400  // ENC_IN_CONF
#define R0A 0x00FB0C80  // STEP_CONF
#define R0B 0x82029805  // SPI_STATUS_SELECTION
#define R10 0x00040001  // STP_LENGTH_ADD
#define R12 0x01000000  // GEAR_RATIO
#define R1C 0x00FF00FF  // CL_BETA / CL_GAMMA
#define R1F 0x00000280  // PWM_FREQ / CHOPSYNC_DIV
#define R20 0x00000001  // RAMPMODE
#define R31 0x00F42400  // CLK_FREQ
#define R53 0xFFFFFFFF  // ENC_POS_DEV_TOL_WR
#define R56 0x00A000A0  // SER_CLK_IN_HIGH_WR / SER_CLK_IN_LOW_WR
#define R57 0x00F00000  // SSI_IN_CLK_DELAY_WR / SSI_IN_WTIME_WR
#define R58 0x00000190  // SER_PTIME_WR
#define R62 0x00FFFFFF  // DC_LSPTM_WR / ENC_VEL_ZERO_WR
#define R70 0xAAAAB554  // MSLUT_0_WR
#define R71 0x4A9554AA  // MSLUT_1_WR
#define R72 0x24492929  // MSLUT_2_WR
#define R73 0x10104222  // MSLUT_3_WR
#define R74 0xFBFFFFFF  // MSLUT_4_WR
#define R75 0xB5BB777D  // MSLUT_5_WR
#define R76 0x49295556  // MSLUT_6_WR
#define R77 0x00404222  // MSLUT_7_WR
#define R78 0xFFFF8056  // MSLUTSEL_WR
#define R7A 0x00F70000  // CURRENTA_RD / CURRENTB_RD
#define R7B 0x00F70000  // CURRENTA_SPI_RD / CURRENTB_SPI_RD / TZEROWAIT_WR
#define R7E 0x00F70000  // START_SIN_WR / START_SIN90_120_WR / DAC_OFFSET_WR

const u8 tmc4361A_defaultRegisterAccess[REGISTER_COUNT] =
{
//	0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 7, 1, // 0x00 - 0x0F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 0x10 - 0x1F
	3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 0x20 - 0x2F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 0x30 - 0x3F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 0x40 - 0x4F
	3, 7, 7, 2, 7, 2, 2, 2, 2, 3, 7, 7, 2, 7, 2, 2, // 0x50 - 0x5F
	2, 2, 2, 2, 0, 1, 1, 2, 2, 2, 1, 1, 7, 7, 1, 1, // 0x60 - 0x6F
	2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 7, 7, 2, 3, 1, // 0x70 - 0x7F
};

const s32 tmc4361A_defaultRegisterResetState[REGISTER_COUNT] =
{
//	0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
	R00, 0,   0,   0,   0,   0,   R06, R07, 0,   0,   R0A, R0B, 0,   0,   0,   0,   // 0x00 - 0x0F
	R10, 0,   R12, 0,   0,   0,   0,   0,   0,   0,   0,   0,   R1C, 0,   0,   R1F, // 0x10 - 0x1F
	R20, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x20 - 0x2F
	0,   R31, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x30 - 0x3F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x40 - 0x4F
	0,   0,   0,   R53, 0,   0,   R56, R57, R58, 0,   0,   0,   0,   0,   0,   0,   // 0x50 - 0x5F
	0,   0,   R62, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x60 - 0x6F
	R70, R71, R72, R73, R74, R75, R76, R77, R78, 0,   R7A, R7B, 0,   0,   R7E, 0    // 0x70 - 0x7F
};

const TMotorConfig tmc4361A_motorConfig =
{
	64,   // IRun
	8,    // IStandby
	200,  // Setting Delay
	0     // BoostCurrent
};

const TClosedLoopConfig tmc4361A_closedLoopConfig =
{
	0,           // ClosedLoopMode
	300000,      // GammaVMin
	600000,      // GammaVAdd
	255,         // Gamma
	256,         // Beta
	0,           // Offset
	100,         // CurrentScalerMinimum
	240,         // CurrentScalerMaximum
	0,           // CurrentScalerStartUp
	1000,        // UpscaleDelay
	10000,       // DownscaleDelay
	10000,       // CorrectionVelocityP
	20,          // CorrectionVelocityI
	10,          // CorrectionVelocityIClip
	0,           // CorrectionVelocityDClk
	1073741823,  // CorrectionVelocityDClip
	65536,       // PositionCorrectionP
	100,         // PositionCorrectionTolerance
	100,         // PositionWindow
	0,           // EncVMeanWait
	7,           // EncVMeanFilter
	500,         // EncVMeanInt
	0,           // EncoderCorrectionYOffset
};

// => SPI wrapper
extern void tmc4361A_writeDatagram(uint8 address, uint8 x1, uint8 x2, uint8 x3, uint8 x4);
extern void tmc4361A_writeInt(uint8 address, int value);
extern int tmc4361A_readInt(uint8 address);
extern unsigned char tmc4361A_cover(unsigned char data, unsigned char lastTransfer);
// <= SPI wrapper

void tmc4361A_initConfig(TMC4361ATypeDef *tmc4361A)
{
	tmc4361A->velocity  = 0;
	tmc4361A->oldTick   = 0;
	tmc4361A->oldX      = 0;

	tmc4361A->motorConfig       = tmc4361A_motorConfig;
	tmc4361A->closedLoopConfig  = tmc4361A_closedLoopConfig;

	for(int i = 0; i < REGISTER_COUNT; i++)
	{
		tmc4361A->registerAccess[i]      = tmc4361A_defaultRegisterAccess[i];
		tmc4361A->registerResetState[i]  = tmc4361A_defaultRegisterResetState[i];
	}
};

void tmc4361A_writeConfiguration(TMC4361ATypeDef *tmc4361A, ConfigurationTypeDef *TMC4361A_config)
{
	uint8 *ptr = &TMC4361A_config->configIndex;
	const int32 *settings = (TMC4361A_config->state == CONFIG_RESTORE) ? TMC4361A_config->shadowRegister : tmc4361A->registerResetState;

	while((*ptr < REGISTER_COUNT) && !IS_WRITEABLE(tmc4361A->registerAccess[*ptr]))
		(*ptr)++;

	if(*ptr < REGISTER_COUNT)
	{
		tmc4361A_writeInt(*ptr, settings[*ptr]);
		(*ptr)++;
	}
	else
	{
		TMC4361A_config->state = CONFIG_READY;
	}
}

void tmc4361A_periodicJob(uint32 tick, TMC4361ATypeDef *tmc4361A, ConfigurationTypeDef *TMC4361A_config)
{
	if(TMC4361A_config->state != CONFIG_READY)
	{
		tmc4361A_writeConfiguration(tmc4361A, TMC4361A_config);
		return;
	}
	if((tick - tmc4361A->oldTick) != 0)
	{
		tmc4361A_calibrateClosedLoop(0);
		tmc4361A->oldTick = tick;
	}

//	if(TMC4361A_config->state != CONFIG_READY)
//	{
//		tmc4361A_writeConfiguration(motor, tmc4361A, TMC4361A_config);
//		return;
//	}
//
//	int XActual,t;
//
//	if((t = abs(tick-tmc4361A->oldTick)) >= 5)	// measured speed dx/dt
//	{
//		XActual				= tmc4361A_readInt(motor, TMC4361A_XACTUAL);
//		TMC4361A_config->shadowRegister[TMC4361A_XACTUAL] = XActual;
//		tmc4361A->velocity 	= (int) ((float) ((XActual-tmc4361A->oldX) / (float) t) 	* (float) 1048.576);
//
//		tmc4361A->oldX				= XActual;
//		tmc4361A->oldTick				= tick;
//	}
}

uint8 tmc4361A_reset(ConfigurationTypeDef *TMC4361A_config)
{
	if(TMC4361A_config->state != CONFIG_READY)
		return 0;

	TMC4361A_config->state        = CONFIG_RESET;
	TMC4361A_config->configIndex  = 0;

	return 1;
}

uint8 tmc4361A_restore(ConfigurationTypeDef *TMC4361A_config)
{
	if(TMC4361A_config->state != CONFIG_READY)
		return 0;

	TMC4361A_config->state        = CONFIG_RESTORE;
	TMC4361A_config->configIndex  = 0;

	return 1;
}

uint8 tmc4361A_moveToNextFullstep()
{
	int32 value;
	int32 mscnt;

	if(tmc4361A_readInt(TMC4361A_VACTUAL)) // motor must be stopped
		return 0;
	tmc4361A_writeInt(TMC4361A_RAMPMODE, 4);              // positioning & hold mode
	tmc4361A_writeInt(TMC4361A_VMAX, 10000 << 8);         // low velocity

	mscnt = tmc4361A_readInt(TMC4361A_MSCNT_RD) & 0x3FF;  // position in microstep table
	value = mscnt & 0xFF;                                 // if last 8 bits are 0 its a multiple of 256
	value = 128 - value;                                  // assuming 256µsteps fullsteps are 128+n*256

	if(!value) // fullstep position reached
		return 1;

	value = tmc4361A_readInt(TMC4361A_XACTUAL) + value;   // distance to next fullstep, assume 256µsteps resolution
	tmc4361A_writeInt(TMC4361A_X_TARGET, value);          // move to next fullstep

	return 0;
}

uint8 tmc4361A_calibrateClosedLoop(uint8 worker0master1)
{
	static uint8 state = 0;
	static uint32 amax = 0;
	static uint32 dmax = 0;

	uint32 uvalue;

	if(worker0master1 && !state)
		state = 1;

	switch(state)
	{
	case 1:
		amax = tmc4361A_readInt(TMC4361A_AMAX);
		dmax = tmc4361A_readInt(TMC4361A_DMAX);

		tmc4361A_writeInt(TMC4361A_RAMPMODE, 4);                      // positioning & hold mode
		tmc4361A_writeInt(TMC4361A_AMAX, (amax>1000) ? amax : 1000);  // acceleration
		tmc4361A_writeInt(TMC4361A_DMAX, (dmax>1000) ? dmax : 1000);  // deceleration
		tmc4361A_writeInt(TMC4361A_VMAX, 0);                          // velocity
		state = 2;
		break;
	case 2:
		uvalue = tmc4361A_readInt(TMC4361A_ENC_IN_CONF);
		uvalue &= ~(1<<24);  // clear calibration bit
		uvalue &= ~(3<<22);  // open loop
		tmc4361A_writeInt(TMC4361A_ENC_IN_CONF, uvalue);

		if(tmc4361A_moveToNextFullstep()) // move to next fullstep, motor must be stopped, poll until finished
			state = 3;
		break;
	case 3:
		uvalue = tmc4361A_readInt(TMC4361A_ENC_IN_CONF) | (1<<24);
		tmc4361A_writeInt(TMC4361A_ENC_IN_CONF, uvalue); // start calibration
		state = 4;
		break;
	case 4:
		if(worker0master1)
			break;

		uvalue = tmc4361A_readInt(TMC4361A_ENC_IN_CONF) & ~(1<<24);
		tmc4361A_writeInt(TMC4361A_ENC_IN_CONF, uvalue); // clear calibration bit

		uvalue = tmc4361A_readInt(TMC4361A_ENC_IN_CONF);
		uvalue |= (1<<22); // closed loop
		tmc4361A_writeInt(TMC4361A_ENC_IN_CONF, uvalue);

		state = 5;
		break;
	case 5:
//			if(worker0master1)	//keep to make polling possible for this function
		state = 0;
		return 1;
		break;
	default:
		break;
	}
	return 0;
}
