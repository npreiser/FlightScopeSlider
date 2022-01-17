/*
 * TMC4361A.h
 *
 *  Created on: 18.07.2017
 *      Author: LK
 */

#ifndef API_IC_TMC4361A_H
#define API_IC_TMC4361A_H

	#include "../../helpers/API_Header.h"
	#include "TMC4361A_Register.h"
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
	} TMC4361ATypeDef;

	void tmc4361A_initConfig(TMC4361ATypeDef *tmc4361A);
	void tmc4361A_periodicJob(uint32 tick, TMC4361ATypeDef *tmc4361A, ConfigurationTypeDef *TMC4361A_config);
	u8 tmc4361A_reset(ConfigurationTypeDef *TMC4361A_config);
	u8 tmc4361A_restore(ConfigurationTypeDef *TMC4361A_config);
	uint8 tmc4361A_calibrateClosedLoop(uint8 worker0master1);
	uint8 tmc4361A_moveToNextFullstep();

#endif /* API_IC_TMC4361A_H */
