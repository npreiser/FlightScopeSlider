/*
 * TMC4330.c
 *
 *  Created on: 18.07.2017
 *      Author: LK
 */

#include "TMC4330.h"

/* Register access permissions:
 * 0: none (reserved)
 * 1: read
 * 2: write
 * 3: read/write
 * 7: read^write (seperate functions/values)
 */
const u8 tmc4330_defaultRegisterAccess[REGISTER_COUNT] =
{
//  0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, // 0x00 - 0x0F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 0x10 - 0x1F
	3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 0x20 - 0x2F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 0x30 - 0x3F
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // 0x40 - 0x4F
	3, 3, 3, 2, 3, 2, 2, 2, 2, 3, 3, 3, 2, 3, 2, 2, // 0x50 - 0x5F
	2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1, 2, 2, 1, 1, // 0x60 - 0x6F
	2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 3, 2, 2, 1  // 0x70 - 0x7F
};

const s32 tmc4330_defaultRegisterResetState[REGISTER_COUNT] =
{
//	0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   A,   B,   C,   D,   E,   F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x00 - 0x0F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x10 - 0x1F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x20 - 0x2F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x30 - 0x3F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x40 - 0x4F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x50 - 0x5F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   // 0x60 - 0x6F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0    // 0x70 - 0x7F
};

const TMotorConfig tmc4330_motorConfig =
{
	64,   // IRun
	8,    // IStandby
	200,  // Setting Delay
	0     // BoostCurrent
};

const TClosedLoopConfig tmc4330_closedLoopConfig =
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
extern void tmc4330_writeDatagram(uint8 address, uint8 x1, uint8 x2, uint8 x3, uint8 x4);
extern void tmc4330_writeInt(uint8 address, int value);
extern int tmc4330_readInt(uint8 address);
extern unsigned char tmc4330_cover(unsigned char data, unsigned char lastTransfer);
// <= SPI wrapper

void tmc4330_initConfig(TMC4330TypeDef *tmc4330)
{
	tmc4330->velocity  = 0;
	tmc4330->oldTick   = 0;
	tmc4330->oldX      = 0;

	tmc4330->motorConfig       = tmc4330_motorConfig;
	tmc4330->closedLoopConfig  = tmc4330_closedLoopConfig;

	for(int i = 0; i < REGISTER_COUNT; i++)
	{
		tmc4330->registerAccess[i]      = tmc4330_defaultRegisterAccess[i];
		tmc4330->registerResetState[i]  = tmc4330_defaultRegisterResetState[i];
	}
};

void tmc4330_writeConfiguration(TMC4330TypeDef *tmc4330, ConfigurationTypeDef *TMC4330_config)
{
	uint8 *ptr = &TMC4330_config->configIndex;
	const int32 *settings = (TMC4330_config->state == CONFIG_RESTORE) ? TMC4330_config->shadowRegister : tmc4330->registerResetState;

	while((*ptr < REGISTER_COUNT) && !IS_WRITEABLE(tmc4330->registerAccess[*ptr]))
		(*ptr)++;

	if(*ptr < REGISTER_COUNT)
	{
		tmc4330_writeInt(*ptr, settings[*ptr]);
		(*ptr)++;
	}
	else
	{
		TMC4330_config->state = CONFIG_READY;
	}
}

void tmc4330_periodicJob(uint32 tick, TMC4330TypeDef *tmc4330, ConfigurationTypeDef *TMC4330_config)
{
	if(TMC4330_config->state != CONFIG_READY)
	{
		tmc4330_writeConfiguration(tmc4330, TMC4330_config);
		return;
	}

	if((tick - tmc4330->oldTick) != 0)
	{
		tmc4330_calibrateClosedLoop(0);
		tmc4330->oldTick = tick;
	}

//	if(TMC4330_config->state != CONFIG_READY)
//	{
//		tmc4330_writeConfiguration(motor, tmc4330, TMC4330_config);
//		return;
//	}
//
//	int XActual,t;
//
//	if((t = abs(tick-tmc4330->oldTick)) >= 5)	// measured speed dx/dt
//	{
//		XActual				= tmc4330_readInt(motor, TMC4330_XACTUAL);
//		TMC4330_config->shadowRegister[TMC4330_XACTUAL] = XActual;
//		tmc4330->velocity 	= (int) ((float) ((XActual-tmc4330->oldX) / (float) t) 	* (float) 1048.576);
//
//		tmc4330->oldX				= XActual;
//		tmc4330->oldTick				= tick;
//	}
}

uint8 tmc4330_reset(ConfigurationTypeDef *TMC4330_config)
{
	if(TMC4330_config->state != CONFIG_READY)
		return 0;

	TMC4330_config->state        = CONFIG_RESET;
	TMC4330_config->configIndex  = 0;

	return 1;
}

uint8 tmc4330_restore(ConfigurationTypeDef *TMC4330_config)
{
	if(TMC4330_config->state != CONFIG_READY)
		return 0;

	TMC4330_config->state        = CONFIG_RESTORE;
	TMC4330_config->configIndex  = 0;

	return 1;
}

uint8 tmc4330_moveToNextFullstep()
{
	int32 value;
	int32 mscnt;

	// motor must be stopped
	if(tmc4330_readInt(TMC4330_VACTUAL))
		return 0;

	tmc4330_writeInt(TMC4330_RAMPMODE, 4);     // positioning & hold mode
	tmc4330_writeInt(TMC4330_VMAX, 10000<<8);  // low velocity

	mscnt = tmc4330_readInt(TMC4330_MSCNT_RD) & 0x3FF;  // position in microstep table
	value = mscnt & 0xFF;                               // if last 8 bits are 0 its a multiple of 256
	value = 128-value;                                  // assuming 256µsteps fullsteps are 128+n*256

	if(!value) // fullstep position reached
		return 1;

	value = tmc4330_readInt(TMC4330_XACTUAL) + value;   // distance to next fullstep, assume 256µsteps resolution
	tmc4330_writeInt(TMC4330_X_TARGET, value);          // move to next fullstep

	return 0;
}

uint8 tmc4330_calibrateClosedLoop(uint8 worker0master1)
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
		amax = tmc4330_readInt(TMC4330_AMAX);
		dmax = tmc4330_readInt(TMC4330_DMAX);

		tmc4330_writeInt(TMC4330_RAMPMODE, 4);                      // positioning & hold mode
		tmc4330_writeInt(TMC4330_AMAX, (amax>1000) ? amax : 1000);  // acceleration
		tmc4330_writeInt(TMC4330_DMAX, (dmax>1000) ? dmax : 1000);  // deceleration
		tmc4330_writeInt(TMC4330_VMAX, 0);                          // velocity
		state = 2;
		break;
	case 2:
		uvalue = tmc4330_readInt(TMC4330_ENC_IN_CONF);
		uvalue &= ~(1<<24);               // clear calibration bit
		uvalue &= ~(3<<22);               // open loop
		tmc4330_writeInt(TMC4330_ENC_IN_CONF, uvalue);
		if(tmc4330_moveToNextFullstep())  // move to next fullstep, motor must be stopped, poll until finished
			state = 3;
		break;
	case 3:
		uvalue = tmc4330_readInt(TMC4330_ENC_IN_CONF) | (1<<24);
		tmc4330_writeInt(TMC4330_ENC_IN_CONF, uvalue);  // start calibration
		state = 4;
		break;
	case 4:
		if(worker0master1)
			break;
		uvalue = tmc4330_readInt(TMC4330_ENC_IN_CONF) & ~(1<<24);
		tmc4330_writeInt(TMC4330_ENC_IN_CONF, uvalue);  // clear calibration bit

		uvalue = tmc4330_readInt(TMC4330_ENC_IN_CONF);
		uvalue |= (1<<22);                              // closed loop
		tmc4330_writeInt(TMC4330_ENC_IN_CONF, uvalue);

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
