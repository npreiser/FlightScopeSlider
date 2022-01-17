/*
 * TMC4671.h
 *
 *  Created on: 30.09.2016
 *      Author: ed
 */

#ifndef API_IC_TMC4671_H
#define API_IC_TMC4671_H

	#include "../../helpers/API_Header.h"
	#include "TMC4671_Register.h"
	#include "TMC4671_Mask_Shift.h"

	void tmc4671_periodicJob(u8 motor, u32 actualSystick, u8 initMode, u8 *initState, u16 initWaitTime, u16 *actualInitWaitTime, u16 startVoltage);

	// initialization functions
	void tmc4671_startEncoderInitialization(u8 mode, u8 *initMode, u8 *initState);
	void tmc4671_updatePhiSelectionAndInitialize(u8 motor, u8 actualPhiESelection, u8 desiredPhiESelection, u8 initMode, u8 *initState);

	// === modes of operation ===
	void tmc4671_switchToMotionMode(u8 motor, u8 mode);

	// torque mode
	void tmc4671_setTargetTorque_raw(u8 motor, s32 targetTorque);
	s32 tmc4671_getTargetTorque_raw(u8 motor);
	s32 tmc4671_getActualTorque_raw(u8 motor);
	s32 tmc4671_getActualRampTorque_raw(u8 motor);

	void tmc4671_setTargetTorque_mA(u8 motor, u16 torqueMeasurementFactor, s32 targetTorque);
	s32 tmc4671_getTargetTorque_mA(u8 motor, u16 torqueMeasurementFactor);
	s32 tmc4671_getActualTorque_mA(u8 motor, u16 torqueMeasurementFactor);
	s32 tmc4671_getActualRampTorque_mA(u8 motor, u16 torqueMeasurementFactor);

	// flux
	void tmc4671_setTargetFlux_raw(u8 motor, s32 targetFlux);
	s32 tmc4671_getTargetFlux_raw(u8 motor);
	s32 tmc4671_getActualFlux_raw(u8 motor);

	void tmc4671_setTargetFlux_mA(u8 motor, u16 torqueMeasurementFactor, s32 targetFlux);
	s32 tmc4671_getTargetFlux_mA(u8 motor, u16 torqueMeasurementFactor);
	s32 tmc4671_getActualFlux_mA(u8 motor, u16 torqueMeasurementFactor);

	// torque/flux limit
	void tmc4671_setTorqueFluxLimit_mA(u8 motor, u16 torqueMeasurementFactor, s32 max);
	s32 tmc4671_getTorqueFluxLimit_mA(u8 motor, u16 torqueMeasurementFactor);

	// velocity mode
	void tmc4671_setTargetVelocity(u8 motor, s32 targetVelocity);
	s32 tmc4671_getTargetVelocity(u8 motor);
	s32 tmc4671_getActualVelocity(u8 motor);
	s32 tmc4671_getActualRampVelocity(u8 motor);

	// position mode
	void tmc4671_setAbsolutTargetPosition(u8 motor, s32 targetPosition);
	void tmc4671_setRelativeTargetPosition(u8 motor, s32 relativePosition);
	s32 tmc4671_getTargetPosition(u8 motor);
	void tmc4671_setActualPosition(u8 motor, s32 actualPosition);
	s32 tmc4671_getActualPosition(u8 motor);
	s32 tmc4671_getActualRampPosition(u8 motor);

	// evaluation
	void tmc4671_disablePWM(u8 motor);
	void tmc4671_load_BLDC_Eval_Defaults(u8 motor);
	void tmc4671_load_Stepper_Eval_Defaults(u8 motor);
	void tmc4671_start_Open_Loop_Test(u8 motor);
	void tmc4671_load_Hall_Config(u8 motor, u32 mode, u16 PHI_M_Offset, u16 PHI_E_Offset);
	void tmc4671_load_ABN_Config(u8 motor);
	void tmc4671_loadDefaultPISettings(u8 motor);

#endif /* API_IC_TMC4671_H */
