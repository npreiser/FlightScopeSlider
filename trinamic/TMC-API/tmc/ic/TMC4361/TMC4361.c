/*
 * TMC4361.c
 *
 *  Created on: 18.07.2017
 *      Author: LK
 */

#include "TMC4361.h"

// Default Register Values
#define R00  0x00006020  // GENERAL_CONF
#define R06  0xFFFFFFFF  // SCALE_VALUES
#define R07  0x00000400  // ENC_IN_CONF
#define R0A  0x00FB0C80  // STEP_CONF
#define R0B  0x82029805  // SPI_STATUS_SELECTION
#define R10  0x00040001  // STP_LENGTH_ADD
#define R12  0x01000000  // GEAR_RATIO
#define R1C  0x00FF00FF  // CL_BETA / CL_GAMMA
#define R1F  0x00000280  // PWM_FREQ / CHOPSYNC_DIV
#define R20  0x00000001  // RAMPMODE
#define R31  0x00F42400  // CLK_FREQ
#define R53  0xFFFFFFFF  // ENC_POS_DEV_TOL_WR
#define R56  0x00A000A0  // SER_CLK_IN_HIGH_WR / SER_CLK_IN_LOW_WR
#define R57  0x00F00000  // SSI_IN_CLK_DELAY_WR / SSI_IN_WTIME_WR
#define R58  0x00000190  // SER_PTIME_WR
#define R62  0x00FFFFFF  // DC_LSPTM_WR / ENC_VEL_ZERO_WR
#define R70  0xAAAAB554  // MSLUT_0_WR
#define R71  0x4A9554AA  // MSLUT_1_WR
#define R72  0x24492929  // MSLUT_2_WR
#define R73  0x10104222  // MSLUT_3_WR
#define R74  0xFBFFFFFF  // MSLUT_4_WR
#define R75  0xB5BB777D  // MSLUT_5_WR
#define R76  0x49295556  // MSLUT_6_WR
#define R77  0x00404222  // MSLUT_7_WR
#define R78  0xFFFF8056  // MSLUTSEL_WR
#define R7E  0x00F70000  // START_SIN_WR / START_SIN90_120_WR / DAC_OFFSET_WR

/* Register access permissions:
 * 0: none (reserved)
 * 1: read
 * 2: write
 * 3: read/write
 * 7: read^write (seperate functions/values)
 */
const u8 tmc4361_defaultRegisterAccess[REGISTER_COUNT] =
{
//	0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, // 00 - 0F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 10 - 1F
	3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 20 - 2F
	3, 3, 3, 3, 3, 3, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 30 - 3F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 40 - 4F
	3, 7, 3, 2, 7, 2, 2, 2, 2, 3, 7, 7, 2, 7, 2, 2, // 50 - 5F
	2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 1, 1, // 60 - 6F
	2, 2, 2, 2, 2, 2, 2, 2, 2, 7, 1, 1, 7, 2, 2, 1, // 70 - 7F
};

const s32 tmc4361_defaultRegisterResetState[REGISTER_COUNT] =
{
//	0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
	R00, 0,   0,   0,   0,   0,   R06, R07, 0,   0,   R0A, R0B, 0,   0,   0,   0,   // 00 - 0F
	R10, 0,   R12, 0,   0,   0,   0,   0,   0,   0,   0,   0,   R1C, 0,   0,   R1F, // 10 - 1F
	R20, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 20 - 2F
	0,   R31, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 30 - 3F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 40 - 4F
	0,   0,   0,   R53, 0,   0,   R56, R57, R58, 0,   0,   0,   0,   0,   0,   0,   // 50 - 5F
	0,   0,   R62, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 60 - 6F
	R70, R71, R72, R73, R74, R75, R76, R77, R78, 0,   0,   0,   0,   0,   R7E, 0    // 70 - 7F
};

const TMotorConfig tmc4361_motorConfig=
{
	64,    // IRun
	8,     // IStandby
	200,   // Setting Delay
	0      // BoostCurrent
};

const TClosedLoopConfig tmc4361_closedLoopConfig=
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
extern void tmc4361_writeDatagram(uint8 address, uint8 x1, uint8 x2, uint8 x3, uint8 x4);
extern void tmc4361_writeInt(uint8 address, int value);
extern int tmc4361_readInt(uint8 address);
extern unsigned char tmc4361_cover(unsigned char data, unsigned char lastTransfer);
// <= SPI wrapper

void tmc4361_initConfig(TMC4361TypeDef *tmc4361)
{
	tmc4361->velocity  = 0;
	tmc4361->oldTick   = 0;
	tmc4361->oldX      = 0;

	tmc4361->motorConfig       = tmc4361_motorConfig;
	tmc4361->closedLoopConfig  = tmc4361_closedLoopConfig;

	for(int i = 0; i < REGISTER_COUNT; i++)
	{
		tmc4361->registerAccess[i]      = tmc4361_defaultRegisterAccess[i];
		tmc4361->registerResetState[i]  = tmc4361_defaultRegisterResetState[i];
	}
};

void tmc4361_writeConfiguration(TMC4361TypeDef *tmc4361, ConfigurationTypeDef *TMC4361_config)
{
	uint8 *ptr = &TMC4361_config->configIndex;
	const int32 *settings = (TMC4361_config->state == CONFIG_RESTORE) ? TMC4361_config->shadowRegister : tmc4361->registerResetState;

	while((*ptr < REGISTER_COUNT) && !IS_WRITEABLE(tmc4361->registerAccess[*ptr]))
		(*ptr)++;

	if(*ptr < REGISTER_COUNT)
	{
		tmc4361_writeInt(*ptr, settings[*ptr]);
		(*ptr)++;
	}
	else
	{
		TMC4361_config->state = CONFIG_READY;
		*ptr = 0;
	}
}

void tmc4361_periodicJob(uint32 tick, TMC4361TypeDef *tmc4361, ConfigurationTypeDef *TMC4361_config)
{
	if(TMC4361_config->state != CONFIG_READY)
	{
		tmc4361_writeConfiguration(tmc4361, TMC4361_config);
		return;
	}

	if((tick - tmc4361->oldTick) != 0)
	{
		tmc4361_calibrateClosedLoop(0);
		tmc4361->oldTick = tick;
	}

//	if(TMC4361_config->state != CONFIG_READY)
//	{
//		tmc4361_writeConfiguration(motor, tmc4361, TMC4361_config);
//		return;
//	}
//
//	int XActual,t;
//
//	if((t = abs(tick-tmc4361->oldTick)) >= 5)	// measured speed dx/dt
//	{
//		XActual				= tmc4361_readInt(motor, TMC4361_XACTUAL);
//		TMC4361_config->shadowRegister[TMC4361_XACTUAL] = XActual;
//		tmc4361->velocity 	= (int) ((float) ((XActual-tmc4361->oldX) / (float) t) 	* (float) 1048.576);
//
//		tmc4361->oldX				= XActual;
//		tmc4361->oldTick				= tick;
//	}
}

uint8 tmc4361_reset(ConfigurationTypeDef *TMC4361_config)
{
	if(TMC4361_config->state != CONFIG_READY)
		return 0;

	TMC4361_config->state        = CONFIG_RESET;
	TMC4361_config->configIndex  = 0;

	return 1;
}

uint8 tmc4361_restore(ConfigurationTypeDef *TMC4361_config)
{
	if(TMC4361_config->state != CONFIG_READY)
		return 0;

	TMC4361_config->state        = CONFIG_RESTORE;
	TMC4361_config->configIndex  = 0;

	return 1;
}

uint8 tmc4361_moveToNextFullstep()
{
	int32 value;
	int32 mscnt;

	if(tmc4361_readInt(TMC4361_VACTUAL)) // motor must be stopped
		return 0;

	tmc4361_writeInt(TMC4361_RAMPMODE, 4);                  // positioning & hold mode
	tmc4361_writeInt(TMC4361_VMAX, 10000<<8);               // low velocity

	mscnt = tmc4361_readInt(TMC4361_MSCNT_RD) & 0x3FF;      // position in microstep table
	value = mscnt & 0xFF;                                   // if last 8 bits are 0 its a multiple of 256
	value = 128-value;                                      // assuming 256µsteps fullsteps are 128+n*256

	if(!value) // fullstep position reached
		return 1;

	value = tmc4361_readInt(TMC4361_XACTUAL) + value;       // distance to next fullstep, assume 256µsteps resolution
	tmc4361_writeInt(TMC4361_X_TARGET, value);              // move to next fullstep

	return 0;
}

uint8 tmc4361_calibrateClosedLoop(uint8 worker0master1)
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
		amax = tmc4361_readInt(TMC4361_AMAX);
		dmax = tmc4361_readInt(TMC4361_DMAX);

		tmc4361_writeInt(TMC4361_RAMPMODE, 4);                      // positioning & hold mode
		tmc4361_writeInt(TMC4361_AMAX, (amax>1000) ? amax : 1000);  // acceleration
		tmc4361_writeInt(TMC4361_DMAX, (dmax>1000) ? dmax : 1000);  // deceleration
		tmc4361_writeInt(TMC4361_VMAX, 0);                          // velocity
		state = 2;
		break;
	case 2:
		uvalue = tmc4361_readInt(TMC4361_ENC_IN_CONF);
		uvalue &= ~(1<<24);                                         // clear calibration bit
		uvalue &= ~(3<<22);                                         // open loop
		tmc4361_writeInt(TMC4361_ENC_IN_CONF, uvalue);
		if(tmc4361_moveToNextFullstep())                            // move to next fullstep, motor must be stopped, poll until finished
			state = 3;
		break;
	case 3:
		uvalue = tmc4361_readInt(TMC4361_ENC_IN_CONF) | (1<<24);
		tmc4361_writeInt(TMC4361_ENC_IN_CONF, uvalue);              // start calibration
		state = 4;
		break;
	case 4:
		if(worker0master1)
			break;
		uvalue = tmc4361_readInt(TMC4361_ENC_IN_CONF) & ~(1<<24);
		tmc4361_writeInt(TMC4361_ENC_IN_CONF, uvalue);              // clear calibration bit

		uvalue = tmc4361_readInt(TMC4361_ENC_IN_CONF);
		uvalue |= (1<<22);                                          // closed loop
		tmc4361_writeInt(TMC4361_ENC_IN_CONF, uvalue);

		state = 5;
		break;
	case 5:
//			if(worker0master1)	// keep to make polling possible for this function
		state = 0;
		return 1;
		break;
	default:
		break;
	}
	return 0;
}
