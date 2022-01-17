/*
 * TMC2660.h
 *
 *  Created on: 06.07.2017
 *      Author: LK
 */

#ifndef API_IC_TMC2660_H
#define API_IC_TMC2660_H

	#include "../../helpers/API_Header.h"
	#include "TMC2660_Register.h"
	#include "TMC2660_Mask_Shift.h"

	#define REGISTER_COUNT 8

	#define TMC2660_FIELD_READ(motor, address, mask, shift)           FIELD_READ(tmc2660_readInt, motor, address, mask, shift)
	#define TMC2660_FIELD_WRITE(motor, address, mask, shift, value)   FIELD_WRITE(tmc2660_writeInt, motor, address, mask, shift, value)
	#define TMC2660_FIELD_UPDATE(motor, address, mask, shift, value)  FIELD_UPDATE(tmc2660_readInt, tmc2660_writeInt, motor, address | TMC2660_WRITE, mask, shift, value)

	// Usage note: use 1 TypeDef per IC
	typedef struct {
		uint8 standStillCurrentScale;
		uint32 standStillTimeout;
		uint8 isStandStillOverCurrent;
		uint8 isStandStillCurrentLimit;
		uint8 continuousModeEnable;
		uint8 runCurrentScale;
		int velocity;
		int oldX;
		uint32 oldTick;
		u8 registerAccess[REGISTER_COUNT];
		int32 registerResetState[REGISTER_COUNT];
	} TMC2660TypeDef;

	void tmc2660_initConfig(TMC2660TypeDef *TMC2660);
	void tmc2660_periodicJob(u8 motor, uint32 tick, TMC2660TypeDef *TMC2660, ConfigurationTypeDef *TMC2660_config);
	u8 tmc2660_reset(TMC2660TypeDef *TMC2660, ConfigurationTypeDef *TMC2660_config);
	u8 tmc2660_restore(ConfigurationTypeDef *TMC2660_config);

#endif /* API_IC_TMC2660_H */
