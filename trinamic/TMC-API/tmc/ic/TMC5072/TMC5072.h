/*
 * TMC5072.h
 *
 *  Created on: 06.07.2017
 *      Author: LK
 *    Based on: TMC562-MKL.h (26.01.2012 OK)
 */

#ifndef API_IC_TMC5072_H
#define API_IC_TMC5072_H

	#include "../../helpers/API_Header.h"
	#include "TMC5072_Register.h"
	#include "TMC5072_Mask_Shift.h"

	#define REGISTER_COUNT 128

	#define TMC5072_FIELD_READ(motor, address, mask, shift) \
		FIELD_READ(tmc5072_readInt, motor, address, mask, shift)
	#define TMC5072_FIELD_WRITE(motor, address, mask, shift, value) \
		FIELD_WRITE(tmc5072_writeInt, motor, address, mask, shift, value)
	#define TMC5072_FIELD_UPDATE(motor, address, mask, shift, value) \
		FIELD_UPDATE(tmc5072_readInt, tmc5072_writeInt, motor, address, mask, shift, value)

	// Usage note: use 1 TypeDef per IC
	typedef struct {
		int velocity[2], oldX[2];
		uint32 oldTick;
		int32 registerResetState[REGISTER_COUNT];
		uint8 registerAccess[REGISTER_COUNT];
		bool vMaxModified[2];
	} TMC5072TypeDef;

	void tmc5072_initConfig(TMC5072TypeDef *TMC5072);
	void tmc5072_periodicJob(u8 motor, uint32 tick, TMC5072TypeDef *TMC5072, ConfigurationTypeDef *TMC5072_config);
	u8 tmc5072_reset(ConfigurationTypeDef *TMC5072_config);
	u8 tmc5072_restore(ConfigurationTypeDef *TMC5072_config);

#endif /* API_IC_TMC5072_H*/
