/*
 * TMC4361.h
 *
 *  Created on: 18.07.2017
 *      Author: LK
 */

#ifndef API_IC_TMC4361_H
#define API_IC_TMC4361_H

	#include "../../helpers/API_Header.h"
	#include "TMC4361_Register.h"
	#include "../TMC43xx/Configs.h"

	#define REGISTER_COUNT 128

	typedef struct
	{
		int velocity;
		int oldX;
		uint32 oldTick;
		int32 registerResetState[REGISTER_COUNT];
		uint8 registerAccess[REGISTER_COUNT];
		TMotorConfig motorConfig;
		TClosedLoopConfig closedLoopConfig;
		uint8 status;
	} TMC4361TypeDef;

	void tmc4361_initConfig(TMC4361TypeDef *tmc4361);
	void tmc4361_periodicJob(uint32 tick, TMC4361TypeDef *tmc4361, ConfigurationTypeDef *TMC4361_config);
	u8 tmc4361_reset(ConfigurationTypeDef *TMC4361_config);
	u8 tmc4361_restore(ConfigurationTypeDef *TMC4361_config);
	uint8 tmc4361_calibrateClosedLoop(uint8 worker0master1);
	uint8 tmc4361_moveToNextFullstep();

#endif /* API_IC_TMC4361_H */
