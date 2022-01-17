/*
 * TMC4331.h
 *
 *  Created on: 17.07.2017
 *      Author: LK
 */

#ifndef API_IC_TMC4331_H
#define API_IC_TMC4331_H

	#include "../../helpers/API_Header.h"
	#include "TMC4331_Register.h"
	#include "../TMC43xx/Configs.h"
	#include "TMC4331_Mask_Shift.h"

	#define REGISTER_COUNT 128

	#define TMC4331_FIELD_READ(motor, address, mask, shift)           FIELD_READ(tmc4331_readInt, motor, address, mask, shift)
	#define TMC4331_FIELD_WRITE(motor, address, mask, shift, value)   FIELD_WRITE(tmc4331_writeInt, motor, address, mask, shift, value)
	#define TMC4331_FIELD_UPDATE(motor, address, mask, shift, value)  FIELD_UPDATE(tmc4331_readInt, tmc4331_writeInt, motor, address, mask, shift, value)

	typedef struct
	{
		int velocity, oldX;
		uint32 oldTick;
		int32 registerResetState[REGISTER_COUNT];
		uint8 registerAccess[REGISTER_COUNT];
		TMotorConfig motorConfig;
		TClosedLoopConfig closedLoopConfig;
		uint8 status;
	} TMC4331TypeDef;

	void tmc4331_initConfig(TMC4331TypeDef *tmc4331);
	void tmc4331_periodicJob(uint8 motor, uint32 tick, TMC4331TypeDef *tmc4331, ConfigurationTypeDef *TMC4331_config);
	u8 tmc4331_reset(ConfigurationTypeDef *TMC4331_config);
	u8 tmc4331_restore(ConfigurationTypeDef *TMC4331_config);
	uint8 tmc4331_calibrateClosedLoop(uint8 motor, uint8 worker0master1);
	uint8 tmc4331_moveToNextFullstep(uint8 motor);

#endif /* API_IC_TMC4331_H */
