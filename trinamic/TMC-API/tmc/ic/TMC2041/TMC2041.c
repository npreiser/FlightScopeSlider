/*
 * TMC2041.c
 *
 *  Created on: 14.08.2017
 *      Author: LK
 */

#include "TMC2041.h"

// Default Register values
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
const u8 tmc2041_defaultRegisterAccess[REGISTER_COUNT] = {
//  0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F
	3, 1, 1, 2, 7, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 0x00 - 0x0F
	2, 1, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, // 0x10 - 0x1F
	3, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 0, // 0x20 - 0x2F
	2, 2, 2, 2, 3, 1, 1, 0, 3, 3, 2, 1, 1, 0, 0, 0, // 0x30 - 0x3F
	3, 3, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 0, 0, // 0x40 - 0x4F
	2, 2, 2, 2, 3, 1, 1, 0, 3, 3, 2, 1, 1, 0, 0, 0, // 0x50 - 0x5F
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 3, 2, 2, 1, // 0x60 - 0x6F
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 3, 2, 2, 1  // 0x70 - 0x7F
};

const s32 tmc2041_defaultRegisterResetState[REGISTER_COUNT] = {
//  0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, // 0x00 - 0x0F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, // 0x10 - 0x1F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, // 0x20 - 0x2F
	R30, 0,   R32, 0,   0,   0,   0,   0,   0,   0,   R3A, 0,   0,   0,   0,   0, // 0x30 - 0x3F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, // 0x40 - 0x4F
	R30, 0,   R32, 0,   0,   0,   0,   0,   0,   0,   R3A, 0,   0,   0,   0,   0, // 0x50 - 0x5F
	R60, R61, R62, R63, R64, R65, R66, R67, R68, R69, 0,   0,   R6C, 0,   0,   0, // 0x60 - 0x6F
	0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   R6C, 0,   0,   0  // 0x70 - 0x7F
};	// todo CHECK 3: R6C is used at Register 0x7C ? (LH)

// => SPI wrapper
extern void tmc2041_writeDatagram(u8 motor, uint8 address, uint8 x1, uint8 x2, uint8 x3, uint8 x4);
extern void tmc2041_writeInt(u8 motor, uint8 address, int value);
extern int tmc2041_readInt(u8 motor, uint8 address);
// <= SPI wrapper

void tmc2041_initConfig(TMC2041TypeDef *tmc2041)
{
	tmc2041->velocity[0]      = 0;
	tmc2041->velocity[1]      = 0;
	tmc2041->oldTick          = 0;
	tmc2041->oldX[0]          = 0;
	tmc2041->oldX[1]          = 0;
	tmc2041->vMaxModified[0]  = FALSE;
	tmc2041->vMaxModified[1]  = FALSE;

	for(int i = 0; i < REGISTER_COUNT; i++)
	{
		tmc2041->registerAccess[i]      = tmc2041_defaultRegisterAccess[i];
		tmc2041->registerResetState[i]  = tmc2041_defaultRegisterResetState[i];
	}
};

void tmc2041_writeConfiguration(TMC2041TypeDef *tmc2041, ConfigurationTypeDef *TMC2041_config)
{
	uint8 *ptr = &TMC2041_config->configIndex;
	const int32 *settings = (TMC2041_config->state == CONFIG_RESTORE) ? TMC2041_config->shadowRegister : tmc2041->registerResetState;

	while((*ptr < REGISTER_COUNT) && !IS_WRITEABLE(tmc2041->registerAccess[*ptr]))
		(*ptr)++;

	if(*ptr < REGISTER_COUNT)
	{
		tmc2041_writeInt(0, *ptr, settings[*ptr]);
		(*ptr)++;
	}
	else
	{
		TMC2041_config->state = CONFIG_READY;
	}
}

void tmc2041_periodicJob(u8 motor, uint32 tick, TMC2041TypeDef *tmc2041, ConfigurationTypeDef *TMC2041_config)
{
	int xActual;
	uint32 tickDiff;

	if(TMC2041_config->state != CONFIG_READY)
	{
		tmc2041_writeConfiguration(tmc2041, TMC2041_config);
		return;
	}

	// Calculate velocity every 5 ms
	if((tickDiff = tick - tmc2041->oldTick) >= 5)
	{
		xActual	= tmc2041_readInt(0, TMC2041_XACTUAL(motor));
		TMC2041_config->shadowRegister[TMC2041_XACTUAL(motor)] = xActual;
		tmc2041->velocity[motor] = (int) ((float) (abs(xActual-tmc2041->oldX[motor]) / (float) tickDiff) * 1048.576f);
		tmc2041->oldX[motor] = xActual;

		tmc2041->oldTick = tick;
	}
}

uint8 tmc2041_reset(ConfigurationTypeDef *TMC2041_config)
{
	if(TMC2041_config->state != CONFIG_READY)
		return 0;

	TMC2041_config->state        = CONFIG_RESET;
	TMC2041_config->configIndex  = 0;

	return 1;
}

uint8 tmc2041_restore(ConfigurationTypeDef *TMC2041_config)
{
	if(TMC2041_config->state != CONFIG_READY)
		return 0;

	TMC2041_config->state        = CONFIG_RESTORE;
	TMC2041_config->configIndex  = 0;

	return 1;
}
