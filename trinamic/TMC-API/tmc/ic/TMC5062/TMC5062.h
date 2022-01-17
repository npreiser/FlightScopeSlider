/*
 * TMC5062.h
 *
 *  Created on: 07.07.2017
 *      Author: LK
 *    Based on: TMC562-MKL.h (26.01.2012 OK)
 */

#ifndef API_IC_TMC5062_H
#define API_IC_TMC5062_H

	#include "../../helpers/API_Header.h"
	#include "TMC5062_Register.h"
	#include "TMC5062_Mask_Shift.h"

	#define REGISTER_COUNT 128

	#define TMC5062_FIELD_READ(motor, address, mask, shift) \
		FIELD_READ(tmc5062_readInt, motor, address, mask, shift)
	#define TMC5062_FIELD_WRITE(motor, address, mask, shift, value) \
		FIELD_WRITE(tmc5062_writeInt, motor, address, mask, shift, value)
	#define TMC5062_FIELD_UPDATE(motor, address, mask, shift, value) \
		FIELD_UPDATE(tmc5062_readInt, tmc5062_writeInt, motor, address, mask, shift, value)

	// Usage note: use 1 TypeDef per IC
	typedef struct {
		int velocity[2], oldX[2];
		uint32 oldTick;
		int32 registerResetState[REGISTER_COUNT];
		uint8 registerAccess[REGISTER_COUNT];
		bool vMaxModified[2];
	} TMC5062TypeDef;

	void tmc5062_initConfig(TMC5062TypeDef *TMC5062);
	void tmc5062_periodicJob(u8 motor, uint32 tick, TMC5062TypeDef *TMC5062, ConfigurationTypeDef *TMC5062_config);
	u8 tmc5062_reset(ConfigurationTypeDef *TMC5062_config);
	u8 tmc5062_restore(ConfigurationTypeDef *TMC5062_config);

#endif /* API_IC_TMC5062_H */
