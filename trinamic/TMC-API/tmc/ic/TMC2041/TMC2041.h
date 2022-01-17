/*
 * TMC2041.h
 *
 *  Created on: 14.08.2017
 *      Author: LK
 */

#ifndef API_IC_TMC5072_H
#define API_IC_TMC5072_H

	#include "../../helpers/API_Header.h"
	#include "TMC2041_Register.h"
	#include "TMC2041_Mask_Shift.h"

	#define REGISTER_COUNT 128

	#define TMC2041_FIELD_READ(motor, address, mask, shift)	\
		FIELD_READ(tmc2041_readInt, motor, address, mask, shift)
	#define TMC2041_FIELD_WRITE(motor, address, mask, shift, value) \
		FIELD_WRITE(tmc2041_writeInt, motor, address, mask, shift, value)
	#define TMC2041_FIELD_UPDATE(motor, address, mask, shift, value) \
		FIELD_UPDATE(tmc2041_readInt, tmc2041_writeInt, motor, address, mask, shift, value)

	typedef struct {
		int velocity[2];
		int oldX[2];
		uint32 oldTick;
		int32 registerResetState[REGISTER_COUNT];
		uint8 registerAccess[REGISTER_COUNT];
		bool vMaxModified[2];
	} TMC2041TypeDef;

	void tmc2041_initConfig(TMC2041TypeDef *TMC2041);
	void tmc2041_periodicJob(u8 motor, uint32 tick, TMC2041TypeDef *TMC2041, ConfigurationTypeDef *TMC2041_config);
	u8 tmc2041_reset(ConfigurationTypeDef *TMC2041_config);
	u8 tmc2041_restore(ConfigurationTypeDef *TMC2041_config);

#endif /* API_IC_TMC5072_H */
