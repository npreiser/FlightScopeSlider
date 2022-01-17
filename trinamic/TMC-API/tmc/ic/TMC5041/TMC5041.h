/*
 * TMC5062.h
 *
 *  Created on: 07.07.2017
 *      Author: LK
 */

#ifndef API_IC_TMC5041_H
#define API_IC_TMC5041_H

	#include "../../helpers/API_Header.h"
	#include "TMC5041_Register.h"
	#include "TMC5041_Mask_Shift.h"

	#define REGISTER_COUNT 128

	#define TMC5041_FIELD_READ(motor, address, mask, shift)           FIELD_READ(tmc5041_readInt, motor, address, mask, shift)
	#define TMC5041_FIELD_WRITE(motor, address, mask, shift, value)   FIELD_WRITE(tmc5041_writeInt, motor, address, mask, shift, value)
	#define TMC5041_FIELD_UPDATE(motor, address, mask, shift, value)  FIELD_UPDATE(tmc5041_readInt, tmc5041_writeInt, motor, address, mask, shift, value)

	// Usage note: use 1 TypeDef per IC
	typedef struct {
		int velocity[2], oldX[2];
		uint32 oldTick;
		int32 registerResetState[REGISTER_COUNT];
		uint8 registerAccess[REGISTER_COUNT];
		bool vMaxModified[2];
	} TMC5041TypeDef;

	void tmc5041_initConfig(TMC5041TypeDef *TMC5041);
	void tmc5041_periodicJob(u8 motor, uint32 tick, TMC5041TypeDef *TMC5041, ConfigurationTypeDef *TMC5041_config);
	u8 tmc5041_reset(ConfigurationTypeDef *TMC5041_config);
	u8 tmc5041_restore(ConfigurationTypeDef *TMC5041_config);

#endif /* API_IC_TMC5041_H */
