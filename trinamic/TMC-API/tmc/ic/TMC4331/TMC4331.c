/*
 * TMC4331.c
 *
 *  Created on: 17.07.2017
 *      Author: LK
 */

#include "TMC4331.h"

// Default Register Values
#define R00  0x00006020  // GENERAL_CONF
#define R06  0xFFFFFFFF  // SCALE_VALUES
#define R0A  0x00FB0C80  // STEP_CONF
#define R0B  0x82029805  // SPI_STATUS_SELECTION
#define R10  0x00040001  // STP_LENGTH_ADD
#define R12  0x01000000  // GEAR_RATIO
#define R1F  0x00000280  // CHOPSYNC_DIV / PWM_FREQ
#define R20  0x00000001  // RAMPMODE
#define R31  0x00F42400  // CLK_FREQ
#define R62  0x00FFFFFF  // DC_LSPTM_WR
#define R70  0xAAAAB554  // MSLUT_0_WR
#define R71  0x4A9554AA  // MSLUT_1_WR
#define R72  0x24492929  // MSLUT_2_WR
#define R73  0x10104222  // MSLUT_3_WR
#define R74  0xFBFFFFFF  // MSLUT_4_WR
#define R75  0xB5BB777D  // MSLUT_5_WR
#define R76  0x49295556  // MSLUT_6_WR
#define R77  0x00404222  // MSLUT_7_WR
#define R78  0xFFFF8056  // MSLUTSEL_WR
#define R7A  0x00F70000  // CURRENTA_RD / CURRENTB_RD
#define R7B  0x00F70000  // CURRENTA_SPI_RD / CURRENTB_SPI_RD / TZEROWAIT_WR
#define R7E  0x00F70000  // START_SIN_WR / START_SIN90_120_WR / DAC_OFFSET_WR

/* Register access permissions:
 * 0: none (reserved)
 * 1: read
 * 2: write
 * 3: read/write
 * 7: read^write (seperate functions/values)
 */
const u8 tmc4331_defaultRegisterAccess[REGISTER_COUNT] =
{
//	0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
	3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 3, 3, 3, 3, 7, 1,  // 0x00 - 0x0F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 3, 3, 3,  // 0x10 - 0x1F
	3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,  // 0x20 - 0x2F
	3, 3, 3, 3, 3, 3, 7, 3, 3, 3, 3, 3, 3, 3, 3, 3,  // 0x30 - 0x3F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 0, 3,  // 0x40 - 0x4F
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  // 0x50 - 0x5F
	2, 2, 2, 0, 2, 0, 0, 2, 0, 0, 0, 0, 7, 7, 1, 1,  // 0x60 - 0x6F
	2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 7, 7, 0, 2, 1   // 0x70 - 0x7F
};

const s32 tmc4331_defaultRegisterResetState[REGISTER_COUNT] =
{
//	0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
	R00, 0,   0,   0,   0,   0,   R06, 0,   0,   0,   R0A, R0B, 0,   0,   0,   0,   // 0x00 - 0x0F
	R10, 0,   R12, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   R1F, // 0x10 - 0x1F
	R20, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x20 - 0x2F
	0,   R31, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x30 - 0x3F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x40 - 0x4F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x50 - 0x5F
	0,   0,   R62, 0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x60 - 0x6F
	R70, R71, R72, R73, R74, R75, R76, R77, R78, R7A, R7B, 0,   0,   0,   R7E, 0    // 0x70 - 0x7F
};

const TMotorConfig tmc4331_motorConfig =
{
	64,   // IRun
	8,    // IStandby
	200,  // Setting Delay
	0     // BoostCurrent
};

const TClosedLoopConfig tmc4331_closedLoopConfig =
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
extern void tmc4331_writeDatagram(uint8 motor, uint8 address, uint8 x1, uint8 x2, uint8 x3, uint8 x4);
extern void tmc4331_writeInt(uint8 motor, uint8 address, int value);
extern int tmc4331_readInt(uint8 motor, uint8 address);
extern unsigned char tmc4331_cover(uint8 motor, uint8 data, uint8 lastTransfer);
// <= SPI wrapper

void tmc4331_initConfig(TMC4331TypeDef *tmc4331)
{
	tmc4331->velocity  = 0;
	tmc4331->oldTick   = 0;
	tmc4331->oldX      = 0;

	tmc4331->motorConfig       = tmc4331_motorConfig;
	tmc4331->closedLoopConfig  = tmc4331_closedLoopConfig;

	for(int i = 0; i < REGISTER_COUNT; i++)
	{
		tmc4331->registerAccess[i]      = tmc4331_defaultRegisterAccess[i];
		tmc4331->registerResetState[i]  = tmc4331_defaultRegisterResetState[i];
	}
};

void tmc4331_writeConfiguration(uint8 motor, TMC4331TypeDef *tmc4331, ConfigurationTypeDef *TMC4331_config)
{
	uint8 *ptr = &TMC4331_config->configIndex;
	const int32 *settings = (TMC4331_config->state == CONFIG_RESTORE) ? TMC4331_config->shadowRegister : tmc4331->registerResetState;

	while((*ptr < REGISTER_COUNT) && !IS_WRITEABLE(tmc4331->registerAccess[*ptr]))
		(*ptr)++;

	if(*ptr < REGISTER_COUNT)
	{
		tmc4331_writeInt(motor, *ptr, settings[*ptr]);
		(*ptr)++;
	}
	else
	{
		TMC4331_config->state = CONFIG_READY;
	}
}

void tmc4331_periodicJob(uint8 motor, uint32 tick, TMC4331TypeDef *tmc4331, ConfigurationTypeDef *TMC4331_config)
{
	if(TMC4331_config->state != CONFIG_READY)
	{
		tmc4331_writeConfiguration(motor, tmc4331, TMC4331_config);
		return;
	}

	if((tick - tmc4331->oldTick) != 0)
	{
		tmc4331_calibrateClosedLoop(motor, 0);
		tmc4331->oldTick = tick;
	}

//	if(TMC4331_config->state != CONFIG_READY)
//	{
//		tmc4331_writeConfiguration(motor, tmc4331, TMC4331_config);
//		return;
//	}
//
//	int XActual,t;
//
//	if((t = abs(tick-tmc4331->oldTick)) >= 5)	// measured speed dx/dt
//	{
//		XActual				= tmc4331_readInt(motor, TMC4331_XACTUAL);
//		TMC4331_config->shadowRegister[TMC4331_XACTUAL] = XActual;
//		tmc4331->velocity 	= (int) ((float) ((XActual-tmc4331->oldX) / (float) t) 	* (float) 1048.576);
//
//		tmc4331->oldX				= XActual;
//		tmc4331->oldTick				= tick;
//	}
}

uint8 tmc4331_reset(ConfigurationTypeDef *TMC4331_config)
{
	if(TMC4331_config->state != CONFIG_READY)
		return 0;

	TMC4331_config->state        = CONFIG_RESET;
	TMC4331_config->configIndex  = 0;

	return 1;
}

uint8 tmc4331_restore(ConfigurationTypeDef *TMC4331_config)
{
	if(TMC4331_config->state != CONFIG_READY)
		return 0;

	TMC4331_config->state        = CONFIG_RESTORE;
	TMC4331_config->configIndex  = 0;

	return 1;
}

uint8 tmc4331_moveToNextFullstep(uint8 motor)
{
	int32 value;
	int32 mscnt;

	if(tmc4331_readInt(motor, TMC4331_VACTUAL)) // motor must be stopped
		return 0;

	tmc4331_writeInt(motor, TMC4331_RAMPMODE, 4);              // positioning & hold mode
	tmc4331_writeInt(motor, TMC4331_VMAX, 10000<<8);           // low velocity

	mscnt = tmc4331_readInt(motor, TMC4331_MSCNT_RD) & 0x3FF;  // position in microstep table
	value = mscnt & 0xFF;                                      // if last 8 bits are 0 its a multiple of 256
	value = 128-value;                                         // assuming 256µsteps fullsteps are 128+n*256

	if(!value) // fullstep position reached
		return 1;

	value = tmc4331_readInt(motor, TMC4331_XACTUAL) + value;   // distance to next fullstep, assume 256µsteps resolution
	tmc4331_writeInt(motor, TMC4331_X_TARGET, value);          // move to next fullstep

	return 0;
}

uint8 tmc4331_calibrateClosedLoop(uint8 motor, uint8 worker0master1)
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
		amax = tmc4331_readInt(motor, TMC4331_AMAX);
		dmax = tmc4331_readInt(motor, TMC4331_DMAX);

		tmc4331_writeInt(motor, TMC4331_RAMPMODE, 4);                      // positioning & hold mode
		tmc4331_writeInt(motor, TMC4331_AMAX, (amax>1000) ? amax : 1000);  // acceleration
		tmc4331_writeInt(motor, TMC4331_DMAX, (dmax>1000) ? dmax : 1000);  // deceleration
		tmc4331_writeInt(motor, TMC4331_VMAX, 0);                          // velocity
		state = 2;
		break;
	case 2:
		uvalue = tmc4331_readInt(motor, TMC4331_ENC_IN_CONF);
		uvalue &= ~(1<<24);  // clear calibration bit
		uvalue &= ~(3<<22);  // open loop
		tmc4331_writeInt(motor, TMC4331_ENC_IN_CONF, uvalue);
		if(tmc4331_moveToNextFullstep(motor)) // move to next fullstep, motor must be stopped, poll until finished
			state = 3;
		break;
	case 3:
		uvalue = tmc4331_readInt(motor, TMC4331_ENC_IN_CONF) | (1<<24);
		tmc4331_writeInt(motor, TMC4331_ENC_IN_CONF, uvalue);  // start calibration
		state = 4;
		break;
	case 4:
		if(worker0master1)
			break;
		uvalue = tmc4331_readInt(motor, TMC4331_ENC_IN_CONF) & ~(1<<24);
		tmc4331_writeInt(motor, TMC4331_ENC_IN_CONF, uvalue);  // clear calibration bit

		uvalue = tmc4331_readInt(motor, TMC4331_ENC_IN_CONF);
		uvalue |= (1<<22);  // closed loop
		tmc4331_writeInt(motor, TMC4331_ENC_IN_CONF, uvalue);

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
