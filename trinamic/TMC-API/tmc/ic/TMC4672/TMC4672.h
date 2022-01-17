/*
 * TMC4672.h
 *
 *  Created on: 18.07.2017
 *      Author: ed
 */

#ifndef API_IC_TMC4672_H
#define API_IC_TMC4672_H

	#include "../../helpers/API_Header.h"
	#include "TMC4672_Register.h"
	#include "TMC4672_Mask_Shift.h"

	void tmc4672_periodicJob(u8 motor, u32 actualSystick, u8 initMode, u8 *initState, u16 initWaitTime, u16 *actualInitWaitTime, u16 startVoltage);

	// encoder functions
	void tmc4672_startEncoderInitialization(u8 mode, u8 *initMode, u8 *initState);

	// === modes of operation ===
	void tmc4672_switchToMotionMode(u8 motor, u8 mode);

	// torque mode
	void tmc4672_setTargetTorque_raw(u8 motor, s32 targetTorque);
	s32 tmc4672_getTargetTorque_raw(u8 motor);
	s32 tmc4672_getActualTorque_raw(u8 motor);
	s32 tmc4672_getActualRampTorque_raw(u8 motor);

	void tmc4672_setTargetTorque_mA(u8 motor, u16 torqueMeasurementFactor, s32 targetTorque);
	s32 tmc4672_getTargetTorque_mA(u8 motor, u16 torqueMeasurementFactor);
	s32 tmc4672_getActualTorque_mA(u8 motor, u16 torqueMeasurementFactor);
	s32 tmc4672_getActualRampTorque_mA(u8 motor, u16 torqueMeasurementFactor);

	// flux
	void tmc4672_setTargetFlux_raw(u8 motor, s32 targetFlux);
	s32 tmc4672_getTargetFlux_raw(u8 motor);
	s32 tmc4672_getActualFlux_raw(u8 motor);

	void tmc4672_setTargetFlux_mA(u8 motor, u16 torqueMeasurementFactor, s32 targetFlux);
	s32 tmc4672_getTargetFlux_mA(u8 motor, u16 torqueMeasurementFactor);
	s32 tmc4672_getActualFlux_mA(u8 motor, u16 torqueMeasurementFactor);

	// torque/flux limit
	void tmc4672_setTorqueFluxLimit_mA(u8 motor, u16 torqueMeasurementFactor, s32 max);
	s32 tmc4672_getTorqueFluxLimit_mA(u8 motor, u16 torqueMeasurementFactor);

	// velocity mode
	void tmc4672_setTargetVelocity(u8 motor, s32 targetVelocity);
	s32 tmc4672_getTargetVelocity(u8 motor);
	s32 tmc4672_getActualVelocity(u8 motor);
	s32 tmc4672_getActualRampVelocity(u8 motor);

	// position mode
	void tmc4672_setAbsolutTargetPosition(u8 motor, s32 targetPosition);
	void tmc4672_setRelativeTargetPosition(u8 motor, s32 relativePosition);
	s32 tmc4672_getTargetPosition(u8 motor);
	void tmc4672_setActualPosition(u8 motor, s32 actualPosition);
	s32 tmc4672_getActualPosition(u8 motor);
	s32 tmc4672_getActualRampPosition(u8 motor);

	// evaluation
	void tmc4672_disablePWM(u8 motor);
	void tmc4672_load_BLDC_Eval_Defaults(u8 motor);
	void tmc4672_load_Stepper_Eval_Defaults(u8 motor);
	void tmc4672_start_Open_Loop_Test(u8 motor);
	void tmc4672_load_Hall_Config(u8 motor, u32 mode, u16 PHI_M_Offset, u16 PHI_E_Offset);
	void tmc4672_load_ABN_Config(u8 motor);
	void tmc4672_loadDefaultPISettings(u8 motor);

#endif /* API_IC_TMC4672_H */
