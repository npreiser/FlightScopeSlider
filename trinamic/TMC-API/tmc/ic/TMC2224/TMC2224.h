/*
 * TMC2224.h
 *
 *  Created on: 07.07.2017
 *      Author: LK
 */

#ifndef API_IC_TMC2224_H
#define API_IC_TMC2224_H

	#include "../../helpers/API_Header.h"
	#include "TMC2224_Register.h"

	#define REGISTER_COUNT 128

	// Usage note: use 1 TypeDef per IC
	typedef struct {
		int velocity;
		int oldX;
		uint32 oldTick;
		int32 registerResetState[REGISTER_COUNT];
		uint8 registerAccess[REGISTER_COUNT];
		bool vMaxModified;
	} TMC2224TypeDef;

	void tmc2224_initConfig(TMC2224TypeDef *TMC2224);
	void tmc2224_periodicJob(u8 motor, uint32 tick, TMC2224TypeDef *TMC2224, ConfigurationTypeDef *TMC2224_config);
	u8 tmc2224_reset(ConfigurationTypeDef *TMC2224_config);
	u8 tmc2224_restore(ConfigurationTypeDef *TMC2224_config);

#endif /* API_IC_TMC2224_H */
