/*
 * TMC2130.h
 *
 *  Created on: 26.01.2017
 *      Author: BS / ED
 */

#ifndef API_IC_TMC2130_H
#define API_IC_TMC2130_H

	#include "../../helpers/API_Header.h"
	#include "TMC2130_Register.h"
	#include "TMC2130_Mask_Shift.h"

	#define REGISTER_COUNT 128

	#define TMC2130_FIELD_READ(motor, address, mask, shift) \
		FIELD_READ(tmc2130_readInt, motor, address, mask, shift)
	#define TMC2130_FIELD_WRITE(motor, address, mask, shift, value) \
		FIELD_WRITE(tmc2130_writeInt, motor, address, mask, shift, value)
	#define TMC2130_FIELD_UPDATE(motor, address, mask, shift, value) \
		FIELD_UPDATE(tmc2130_readInt, tmc2130_writeInt, motor, address, mask, shift, value)

	typedef struct
	{
		int velocity;
		int32 registerResetState[REGISTER_COUNT];
		uint8 registerAccess[REGISTER_COUNT];
	} TMC2130TypeDef;

	void TMC2130_initConfig(TMC2130TypeDef *Rhino_TMC2130);
	void TMC2130_periodicJob(u8 motor, uint32 tick, TMC2130TypeDef *Rhino_TMC2130, ConfigurationTypeDef *TMC2130_config);
	uint8 TMC2130_reset(ConfigurationTypeDef *TMC2130_config);
	uint8 TMC2130_restore(ConfigurationTypeDef *TMC2130_config);

#endif /* API_IC_TMC2130_H */
