/*
 * TMC5062.c
 *
 *  Created on: 06.07.2017
 *      Author: LK
 *    Based on: TMC562-MKL.h (26.01.2012 OK)
 */

#include "TMC5062.h"

// Default Register Values
#define R30 0x00071703  // IHOLD_IRUN
#define R32 0x00FFFFFF  // VHIGH
#define R3A 0x00010000  // ENC_CONST
#define R60 0xAAAAB554  // MSLUT[0]
#define R61 0x4A9554AA  // MSLUT[1]
#define R62 0x24492929  // MSLUT[2]
#define R63 0x10104222  // MSLUT[3]
#define R64 0xFBFFFFFF  // MSLUT[4]
#define R65 0xB5BB777D  // MSLUT[5]
#define R66 0x49295556  // MSLUT[6]
#define R67 0x00404222  // MSLUT[7]
#define R68 0xFFFF8056  // MSLUTSEL
#define R69 0x00F70000  // MSLUTSTART
#define R6C 0x000101D5  // CHOPCONF

/* Register access permissions:
 * 0: none (reserved)
 * 1: read
 * 2: write
 * 3: read/write
 * 7: read^write (seperate functions/values)
 */
const u8 tmc5062_defaultRegisterAccess[REGISTER_COUNT] = {
//	0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
	3, 1, 1, 2, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x00 - 0x0F
	2, 1, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, // 0x10 - 0x1F
	3, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 0, // 0x20 - 0x2F
	2, 2, 2, 2, 3, 1, 1, 0, 3, 3, 2, 1, 1, 0, 0, 0, // 0x30 - 0x3F
	3, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 0, // 0x40 - 0x4F
	2, 2, 2, 2, 3, 1, 1, 0, 3, 3, 2, 1, 1, 0, 0, 0, // 0x50 - 0x5F
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 3, 2, 2, 1, // 0x60 - 0x6F
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 3, 2, 2, 1  // 0x70 - 0x7F
};

const s32 tmc5062_defaultRegisterResetState[REGISTER_COUNT] = {
//	0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, // 0x00 - 0x0F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, // 0x10 - 0x1F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, // 0x20 - 0x2F
	R30, 0,   R32, 0,   0,   0,   0,   0,   0,   0,   R3A, 0,   0,   0,   0,   0, // 0x30 - 0x3F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, // 0x40 - 0x4F
	R30, 0,   R32, 0,   0,   0,   0,   0,   0,   0,   R3A, 0,   0,   0,   0,   0, // 0x50 - 0x5F
	R60, R61, R62, R63, R64, R65, R66, R67, R68, R69, 0,   0,   R6C, 0,   0,   0, // 0x60 - 0x6F
	R60, R61, R62, R63, R64, R65, R66, R67, R68, R69, 0,   0,   R6C, 0,   0,   0  // 0x70 - 0x7F
};

// => SPI wrapper
extern void tmc5062_writeDatagram(u8 motor, uint8 address, uint8 x1, uint8 x2, uint8 x3, uint8 x4);
extern void tmc5062_writeInt(u8 motor, uint8 address, int value);
extern int tmc5062_readInt(u8 motor, uint8 address);
// <= SPI wrapper

void tmc5062_initConfig(TMC5062TypeDef *tmc5062)
{
	tmc5062->velocity[0]      = 0;
	tmc5062->velocity[1]      = 0;
	tmc5062->oldTick          = 0;
	tmc5062->oldX[0]          = 0;
	tmc5062->oldX[1]          = 0;
	tmc5062->vMaxModified[0]  = FALSE;
	tmc5062->vMaxModified[1]  = FALSE;

	int i;
	for(i = 0; i < REGISTER_COUNT; i++)
	{
		tmc5062->registerAccess[i]      = tmc5062_defaultRegisterAccess[i];
		tmc5062->registerResetState[i]  = tmc5062_defaultRegisterResetState[i];
	}
};

void tmc5062_writeConfiguration(TMC5062TypeDef *tmc5062, ConfigurationTypeDef *TMC5062_config)
{
	uint8 *ptr = &TMC5062_config->configIndex;
	const int32 *settings = (TMC5062_config->state == CONFIG_RESTORE) ? TMC5062_config->shadowRegister : tmc5062->registerResetState;

	while((*ptr < REGISTER_COUNT) && !IS_WRITEABLE(tmc5062->registerAccess[*ptr]))
		(*ptr)++;

	if(*ptr < REGISTER_COUNT)
	{
		tmc5062_writeInt(0, *ptr, settings[*ptr]);
		(*ptr)++;
	}
	else
	{
		TMC5062_config->state = CONFIG_READY;
	}
}

void tmc5062_periodicJob(u8 motor, uint32 tick, TMC5062TypeDef *tmc5062, ConfigurationTypeDef *TMC5062_config)
{
	int xActual;
	uint32 tickDiff;

	if(TMC5062_config->state != CONFIG_READY)
	{
		tmc5062_writeConfiguration(tmc5062, TMC5062_config);
		return;
	}

	if((tickDiff = tick - tmc5062->oldTick) >= 5)
	{
		xActual	= tmc5062_readInt(0, TMC5062_XACTUAL(motor));
		TMC5062_config->shadowRegister[TMC5062_XACTUAL(motor)] = xActual;
		tmc5062->velocity[motor] = (int) ((float) (abs(xActual-tmc5062->oldX[motor]) / (float) tickDiff) * (float) 1048.576);
		if(tmc5062_readInt(0, TMC5062_VACTUAL(motor))<0) tmc5062->velocity[motor] *= -1;
		tmc5062->oldX[motor] = xActual;

		// Not per motor:
		/*xActual	= tmc5062_readInt(motor, TMC5062_XACTUAL_1);
		TMC562v3_config->shadowRegister[TMC5062_XACTUAL_1] = xActual;
		TMC562V3.velocityMotor1 = (int) ((float) (abs(xActual-oldX[0]) / (float) t) * (float) 1048.576);
		tmc5062->oldX	= xActual;

		xActual	= readInt(TMC5062_XACTUAL_2);
		TMC562v3_config->shadowRegister[TMC5062_XACTUAL_2] = xActual;
		TMC562V3.velocityMotor2 = (int) ((float) (abs(xActual-oldX[1]) / (float) t)	* (float) 1048.576);
		tmc5062->oldX	= xActual;*/

		tmc5062->oldTick = tick;
	}
}

uint8 tmc5062_reset(ConfigurationTypeDef *TMC5062_config)
{
	if(TMC5062_config->state != CONFIG_READY)
		return 0;

	TMC5062_config->state        = CONFIG_RESET;
	TMC5062_config->configIndex  = 0;

	return 1;
}

uint8 tmc5062_restore(ConfigurationTypeDef *TMC5062_config)
{
	if(TMC5062_config->state != CONFIG_READY)
		return 0;

	TMC5062_config->state        = CONFIG_RESTORE;
	TMC5062_config->configIndex  = 0;

	return 1;
}
