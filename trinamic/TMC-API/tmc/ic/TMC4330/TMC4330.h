/*
 * TMC4330.h
 *
 *  Created on: 18.07.2017
 *      Author: LK
 */

#ifndef API_IC_TMC4330_H
#define API_IC_TMC4330_H

	#include "../../helpers/API_Header.h"
	#include "TMC4330_Register.h"
	#include "../TMC43xx/Configs.h"

	#define REGISTER_COUNT 128

	typedef struct
	{
		int velocity, oldX;
		uint32 oldTick;
		int32 registerResetState[REGISTER_COUNT];
		uint8 registerAccess[REGISTER_COUNT];
		TMotorConfig motorConfig;
		TClosedLoopConfig closedLoopConfig;
		uint8 status;
	} TMC4330TypeDef;

	void tmc4330_initConfig(TMC4330TypeDef *tmc4330);
	void tmc4330_periodicJob(uint32 tick, TMC4330TypeDef *tmc4330, ConfigurationTypeDef *TMC4330_config);
	u8 tmc4330_reset(ConfigurationTypeDef *TMC4330_config);
	u8 tmc4330_restore(ConfigurationTypeDef *TMC4330_config);
	uint8 tmc4330_calibrateClosedLoop(uint8 worker0master1);
	uint8 tmc4330_moveToNextFullstep();

#endif /* API_IC_TMC4330_H */
