/*
 * TMC4672.c
 *
 *  Created on: 18.07.2017
 *      Author: ed
 */
#include "TMC4672.h"

// motion modes
#define MOTION_MODE_STOPPED    0
#define MOTION_MODE_TORQUE     1
#define MOTION_MODE_VELOCITY   2
#define MOTION_MODE_POSITION   3
#define MOTION_MODE_UQ_UD_EXT  8

// PHI_E selections
#define PHI_E_EXTERNAL   1
#define PHI_E_OPEN_LOOP  2
#define PHI_E_ABN        3
#define PHI_E_HALL       5
#define PHI_E_AENC       6
#define PHI_A_AENC       7

#define STATE_NOTHING_TO_DO    0
#define STATE_START_INIT       1
#define STATE_WAIT_INIT_TIME   2
#define STATE_ESTIMATE_OFFSET  3

// => SPI wrapper
extern int tmc4672_readInt(u8 motor, uint8 address);
extern void tmc4672_writeInt(u8 motor, uint8 address, int value);
extern u16 tmc4672_readRegister16BitValue(u8 motor, u8 address, u8 channel);
extern void tmc4672_writeRegister16BitValue(u8 motor, u8 address, u8 channel, u16 value);
// <= SPI wrapper

void tmc4672_switchToMotionMode(u8 motor, u8 mode)
{
	// switch motion mode
	u32 actualModeRegister = tmc4672_readInt(motor,TMC4672_MODE_RAMP_MODE_MOTION);
	actualModeRegister &= 0xFFFFFF00;
	actualModeRegister |= mode;
	tmc4672_writeInt(motor, TMC4672_MODE_RAMP_MODE_MOTION, actualModeRegister);
}

void tmc4672_setTargetTorque_raw(u8 motor, s32 targetTorque)
{
	tmc4672_switchToMotionMode(motor, MOTION_MODE_TORQUE);
	tmc4672_writeRegister16BitValue(motor, TMC4672_PID_TORQUE_FLUX_TARGET, BIT_16_TO_31, targetTorque);
}

s32 tmc4672_getTargetTorque_raw(u8 motor)
{
	tmc4672_writeInt(motor, TMC4672_INTERIM_ADDR, 0);
	return (s32) tmc4672_readInt(motor, TMC4672_INTERIM_DATA);
}

s32 tmc4672_getActualTorque_raw(u8 motor)
{
	return (s16) tmc4672_readRegister16BitValue(motor, TMC4672_PID_TORQUE_FLUX_ACTUAL, BIT_16_TO_31);
}

s32 tmc4672_getActualRampTorque_raw(u8 motor)
{
	// no ramp implemented
	UNUSED(motor);
	return 0;
}

void tmc4672_setTargetTorque_mA(u8 motor, u16 torqueMeasurementFactor, s32 targetTorque)
{
	tmc4672_switchToMotionMode(motor, MOTION_MODE_TORQUE);
	tmc4672_writeRegister16BitValue(motor, TMC4672_PID_TORQUE_FLUX_TARGET, BIT_16_TO_31, (targetTorque * 256) / (s32) torqueMeasurementFactor);
}

s32 tmc4672_getTargetTorque_mA(u8 motor, u16 torqueMeasurementFactor)
{
	return (tmc4672_getTargetTorque_raw(motor) * (s32) torqueMeasurementFactor) / 256;
}

s32 tmc4672_getActualTorque_mA(u8 motor, u16 torqueMeasurementFactor)
{
	return (tmc4672_getActualTorque_raw(motor) * (s32) torqueMeasurementFactor) / 256;
}

s32 tmc4672_getActualRampTorque_mA(u8 motor, u16 torqueMeasurementFactor)
{
	// no ramp implemented
	UNUSED(motor);
	UNUSED(torqueMeasurementFactor);
	return 0;
}

void tmc4672_setTargetFlux_raw(u8 motor, s32 targetFlux)
{
	// do not change the MOTION_MODE here! target flux can also be used during velocity and position modes
	tmc4672_writeRegister16BitValue(motor, TMC4672_PID_TORQUE_FLUX_TARGET, BIT_0_TO_15, targetFlux);
}

s32 tmc4672_getTargetFlux_raw(u8 motor)
{
	tmc4672_writeInt(motor, TMC4672_INTERIM_ADDR, 1);
	return (s32)tmc4672_readInt(motor, TMC4672_INTERIM_DATA);
}

s32 tmc4672_getActualFlux_raw(u8 motor)
{
	return (s16) tmc4672_readRegister16BitValue(motor, TMC4672_PID_TORQUE_FLUX_ACTUAL, BIT_0_TO_15);
}

void tmc4672_setTargetFlux_mA(u8 motor, u16 torqueMeasurementFactor, s32 targetFlux)
{
	// do not change the MOTION_MODE here! target flux can also be used during velocity and position modes
	tmc4672_writeRegister16BitValue(motor, TMC4672_PID_TORQUE_FLUX_TARGET, BIT_0_TO_15, (targetFlux * 256) / (s32) torqueMeasurementFactor);
}

s32 tmc4672_getTargetFlux_mA(u8 motor, u16 torqueMeasurementFactor)
{
	return (tmc4672_getTargetFlux_raw(motor) * (s32) torqueMeasurementFactor) / 256;
}

s32 tmc4672_getActualFlux_mA(u8 motor, u16 torqueMeasurementFactor)
{
	return (tmc4672_getActualFlux_raw(motor) * (s32) torqueMeasurementFactor) / 256;
}

void tmc4672_setTorqueFluxLimit_mA(u8 motor, u16 torqueMeasurementFactor, s32 max)
{
	tmc4672_writeRegister16BitValue(motor, TMC4672_PID_TORQUE_FLUX_LIMITS, BIT_0_TO_15, (max * 256) / (s32) torqueMeasurementFactor);
}

s32 tmc4672_getTorqueFluxLimit_mA(u8 motor, u16 torqueMeasurementFactor)
{
	return ((s32) tmc4672_readRegister16BitValue(motor, TMC4672_PID_TORQUE_FLUX_LIMITS, BIT_0_TO_15) * (s32) torqueMeasurementFactor) / 256;
}

void tmc4672_setTargetVelocity(u8 motor, s32 targetVelocity)
{
	tmc4672_switchToMotionMode(motor, MOTION_MODE_VELOCITY);
	tmc4672_writeInt(motor, TMC4672_PID_VELOCITY_TARGET, targetVelocity);
}

s32 tmc4672_getTargetVelocity(u8 motor)
{
	return (s32) tmc4672_readInt(motor, TMC4672_PID_VELOCITY_TARGET);

	//tmc4672_writeInt(TMC4672_INTERIM_ADDR, 2);
	//return (s32)tmc4672_readInt(TMC4672_INTERIM_DATA);
}

s32 tmc4672_getActualVelocity(u8 motor)
{
	return (s32) tmc4672_readInt(motor, TMC4672_PID_VELOCITY_ACTUAL);
}

s32 tmc4672_getActualRampVelocity(u8 motor)
{
	UNUSED(motor);
	// no ramp implemented
	return 0;
}

void tmc4672_setAbsolutTargetPosition(u8 motor, s32 targetPosition)
{
	tmc4672_switchToMotionMode(motor, MOTION_MODE_POSITION);
	tmc4672_writeInt(motor, TMC4672_PID_POSITION_TARGET, targetPosition);
}

void tmc4672_setRelativeTargetPosition(u8 motor, s32 relativePosition)
{
	tmc4672_switchToMotionMode(motor, MOTION_MODE_POSITION);
	// determine actual position and add relative position ticks
	tmc4672_writeInt(motor, TMC4672_PID_POSITION_TARGET, (s32) tmc4672_readInt(motor, TMC4672_PID_POSITION_ACTUAL) + relativePosition);
}

s32 tmc4672_getTargetPosition(u8 motor)
{
	return (s32) tmc4672_readInt(motor, TMC4672_PID_POSITION_TARGET);
}

void tmc4672_setActualPosition(u8 motor, s32 actualPosition)
{
	tmc4672_writeInt(motor, TMC4672_PID_POSITION_ACTUAL, actualPosition);
}

s32 tmc4672_getActualPosition(u8 motor)
{
	return (s32) tmc4672_readInt(motor, TMC4672_PID_POSITION_ACTUAL);
}

s32 tmc4672_getActualRampPosition(u8 motor)
{
	UNUSED(motor);
	// no ramp implemented
	return 0;
}

// encoder initialization
void tmc4672_doEncoderInitializationMode0(u8 motor, u8 *initState, u16 initWaitTime, u16 *actualInitWaitTime, u16 startVoltage)
{
	static uint16 last_Phi_E_Selection = 0;
	static uint32 last_UQ_UD_EXT = 0;
	static s16 last_PHI_E_EXT = 0;

	switch (*initState)
	{
	case STATE_NOTHING_TO_DO:
		*actualInitWaitTime = 0;
		break;
	case STATE_START_INIT: // started by writing 1 to initState

		// save actual set values for PHI_E_SELECTION, UQ_UD_EXT, and PHI_E_EXT
		last_Phi_E_Selection = (u16) tmc4672_readRegister16BitValue(motor, TMC4672_PHI_E_SELECTION, BIT_0_TO_15);
		last_UQ_UD_EXT = (u32) tmc4672_readInt(motor, TMC4672_UQ_UD_EXT);
		last_PHI_E_EXT = (s16) tmc4672_readRegister16BitValue(motor, TMC4672_PHI_E_EXT, BIT_0_TO_15);

		// set ABN_DECODER_PHI_E_OFFSET to zero
		tmc4672_writeRegister16BitValue(motor, TMC4672_ABN_DECODER_PHI_E_PHI_M_OFFSET, BIT_16_TO_31, 0);

		// select phi_e_ext
		tmc4672_writeRegister16BitValue(motor, TMC4672_PHI_E_SELECTION, BIT_0_TO_15, 1);

		// set an initialization voltage on UD_EXT (to the flux, not the torque!)
		tmc4672_writeRegister16BitValue(motor, TMC4672_UQ_UD_EXT, BIT_16_TO_31, 0);
		tmc4672_writeRegister16BitValue(motor, TMC4672_UQ_UD_EXT, BIT_0_TO_15, startVoltage);

		// set the "zero" angle
		tmc4672_writeRegister16BitValue(motor, TMC4672_PHI_E_EXT, BIT_0_TO_15, 0);

		*initState = STATE_WAIT_INIT_TIME;
		break;
	case STATE_WAIT_INIT_TIME:
		// wait until initialization time is over (until no more vibration on the motor)
		(*actualInitWaitTime)++;
		if(*actualInitWaitTime >= initWaitTime)
		{
			// set internal encoder value to zero
			tmc4672_writeInt(motor, TMC4672_ABN_DECODER_COUNT, 0);

			// switch back to last used UQ_UD_EXT setting
			tmc4672_writeInt(motor, TMC4672_UQ_UD_EXT, last_UQ_UD_EXT);

			// set PHI_E_EXT back to last value
			tmc4672_writeRegister16BitValue(motor, TMC4672_PHI_E_EXT, BIT_0_TO_15, last_PHI_E_EXT);

			// switch back to last used PHI_E_SELECTION setting
			tmc4672_writeRegister16BitValue(motor, TMC4672_PHI_E_SELECTION, BIT_0_TO_15, last_Phi_E_Selection);

			// go to next state
			*initState = STATE_ESTIMATE_OFFSET;
		}
		break;
	case STATE_ESTIMATE_OFFSET:
		// todo ADD 2: do offset estimation here #3

		// wait for N-Channel if available

		// go to ready state
		*initState = STATE_NOTHING_TO_DO;
		break;
	default:
		*initState = STATE_NOTHING_TO_DO;
		break;
	}
}

s16 tmc4672_getS16CircleDifference(s16 newValue, s16 oldValue)
{
	return (newValue - oldValue);
}

void tmc4672_doEncoderInitializationMode2(u8 motor, u8 *initState, u16 *actualInitWaitTime)
{
	static s16 hall_phi_e_old = 0;
	static s16 hall_phi_e_new = 0;
	static s16 actual_coarse_offset = 0;

	switch (*initState)
	{
	case STATE_NOTHING_TO_DO:
		*actualInitWaitTime = 0;
		break;
	case STATE_START_INIT: // started by writing 1 to initState
		// turn hall_mode interpolation off (read, clear bit 8, write back)
		tmc4672_writeInt(motor, TMC4672_HALL_MODE, tmc4672_readInt(motor, TMC4672_HALL_MODE) & 0xFFFFFEFF);

		// set ABN_DECODER_PHI_E_OFFSET to zero
		tmc4672_writeRegister16BitValue(motor, TMC4672_ABN_DECODER_PHI_E_PHI_M_OFFSET, BIT_16_TO_31, 0);

		// read actual hall angle
		hall_phi_e_old = (s16) tmc4672_readRegister16BitValue(motor, TMC4672_HALL_PHI_E_INTERPOLATED_PHI_E, BIT_0_TO_15);

		// read actual abn_decoder angle and compute difference to actual hall angle
		actual_coarse_offset = tmc4672_getS16CircleDifference(hall_phi_e_old, (s16) tmc4672_readRegister16BitValue(motor, TMC4672_ABN_DECODER_PHI_E_PHI_M, BIT_16_TO_31));

		// set ABN_DECODER_PHI_E_OFFSET to actual hall-abn-difference, to use the actual hall angle for coarse initialization
		tmc4672_writeRegister16BitValue(motor, TMC4672_ABN_DECODER_PHI_E_PHI_M_OFFSET, BIT_16_TO_31, actual_coarse_offset);

		*initState = STATE_WAIT_INIT_TIME;
		break;
	case STATE_WAIT_INIT_TIME:
		// read actual hall angle
		hall_phi_e_new = (s16) tmc4672_readRegister16BitValue(motor, TMC4672_HALL_PHI_E_INTERPOLATED_PHI_E, BIT_0_TO_15);

		// wait until hall angle changed
		if(hall_phi_e_old != hall_phi_e_new)
		{
			// estimated value = old value + diff between old and new (handle s16 overrun)
			s16 hall_phi_e_estimated = hall_phi_e_old + tmc4672_getS16CircleDifference(hall_phi_e_new, hall_phi_e_old)/2;

			// read actual abn_decoder angle and consider last set abn_decoder_offset
			s16 abn_phi_e_actual = (s16) tmc4672_readRegister16BitValue(motor, TMC4672_ABN_DECODER_PHI_E_PHI_M, BIT_16_TO_31) - actual_coarse_offset;

			// set ABN_DECODER_PHI_E_OFFSET to actual estimated angle - abn_phi_e_actual difference
			tmc4672_writeRegister16BitValue(motor, TMC4672_ABN_DECODER_PHI_E_PHI_M_OFFSET, BIT_16_TO_31, tmc4672_getS16CircleDifference(hall_phi_e_estimated, abn_phi_e_actual));

			// go to ready state
			*initState = STATE_NOTHING_TO_DO;
		}
		break;
	default:
		*initState = STATE_NOTHING_TO_DO;
		break;
	}
}

void tmc4672_checkEncoderInitialization(u8 motor, u32 actualSystick, u8 initMode, u8 *initState, u16 initWaitTime, u16 *actualInitWaitTime, u16 startVoltage)
{
	// use the systick as 1ms timer for encoder initialization
	static uint32 lastSystick = 0;
	if(actualSystick != lastSystick)
	{
		// needs timer to use the wait time
		if(initMode == 0)
		{
			tmc4672_doEncoderInitializationMode0(motor, initState, initWaitTime, actualInitWaitTime, startVoltage);
		}
		lastSystick = actualSystick;
	}

	// needs no timer
	if(initMode == 2)
	{
		tmc4672_doEncoderInitializationMode2(motor, initState, actualInitWaitTime);
	}
}

void tmc4672_periodicJob(u8 motor, u32 actualSystick, u8 initMode, u8 *initState, u16 initWaitTime, u16 *actualInitWaitTime, u16 startVoltage)
{
	tmc4672_checkEncoderInitialization(motor, actualSystick, initMode, initState, initWaitTime, actualInitWaitTime, startVoltage);
}

void tmc4672_startEncoderInitialization(u8 mode, u8 *initMode, u8 *initState)
{
	// allow only a new initialization if no actual initialization is running
	if(*initState == STATE_NOTHING_TO_DO)
	{
		if(mode == 0)		// estimate offset
		{
			// set mode
			*initMode = 0;

			// start initialization
			*initState = STATE_START_INIT;
		}
		else if(mode == 2)	// use hall sensor signals
		{
			// set mode
			*initMode = 2;

			// start initialization
			*initState = STATE_START_INIT;
		}
	}
}

void tmc4672_disablePWM(u8 motor)
{
	tmc4672_writeInt(motor, TMC4672_PWM_SV_CHOP, 0);
}

void tmc4672_load_BLDC_Eval_Defaults(u8 motor)
{
	tmc4672_writeInt(motor, TMC4672_MOTOR_TYPE_N_POLE_PAIRS, 0x000010004);  // select 4 pole pairs and motor type BLDC
	tmc4672_writeInt(motor, TMC4672_PWM_POLARITIES, 1);                     // Low Side 1, and High Side 0
	tmc4672_writeInt(motor, TMC4672_PWM_SV_CHOP, 7);                        // centered PWM for FOC
}

void tmc4672_load_Stepper_Eval_Defaults(u8 motor)
{
	tmc4672_writeInt(motor, TMC4672_MOTOR_TYPE_N_POLE_PAIRS, 50);  // select 50 pole pairs and motor type Stepper
	tmc4672_writeInt(motor, TMC4672_PWM_POLARITIES, 0);            // Low Side 0, and High Side 0
	tmc4672_writeInt(motor, TMC4672_PWM_SV_CHOP, 7);               // centered PWM for FOC
}

void tmc4672_start_Open_Loop_Test(u8 motor)
{
	tmc4672_writeInt(motor, TMC4672_PHI_E_SELECTION, PHI_E_OPEN_LOOP);
	tmc4672_writeRegister16BitValue(motor, TMC4672_MODE_RAMP_MODE_MOTION, BIT_0_TO_15, MOTION_MODE_UQ_UD_EXT);
	tmc4672_writeInt(motor, TMC4672_UQ_UD_EXT, 2000);            // select UQ_EXT=0, UD_EXT=2000
	tmc4672_writeInt(motor, TMC4672_OPENLOOP_ACCELERATION, 60);  // 60 [rpm/s]
	tmc4672_writeInt(motor, TMC4672_OPENLOOP_VELOCITY_TARGET, 5);
}

void tmc4672_load_Hall_Config(u8 motor, u32 mode, u16 PHI_M_Offset, u16 PHI_E_Offset)
{
	tmc4672_writeInt(motor, TMC4672_HALL_MODE, mode);
	tmc4672_writeRegister16BitValue(motor, TMC4672_HALL_PHI_E_PHI_M_OFFSET, BIT_0_TO_15, PHI_M_Offset);
	tmc4672_writeRegister16BitValue(motor, TMC4672_HALL_PHI_E_PHI_M_OFFSET, BIT_16_TO_31, PHI_E_Offset);
	tmc4672_writeRegister16BitValue(motor, TMC4672_MODE_RAMP_MODE_MOTION, BIT_0_TO_15, MOTION_MODE_STOPPED);
	tmc4672_writeInt(motor, TMC4672_PHI_E_SELECTION, PHI_E_HALL);
}

void tmc4672_load_ABN_Config(u8 motor)
{
	tmc4672_writeRegister16BitValue(motor, TMC4672_MODE_RAMP_MODE_MOTION, BIT_0_TO_15, MOTION_MODE_STOPPED);
	tmc4672_writeInt(motor, TMC4672_PHI_E_SELECTION, PHI_E_ABN);
}

void tmc4672_loadDefaultPISettings(u8 motor)
{
	tmc4672_writeInt(motor, TMC4672_PID_FLUX_P_FLUX_I, 0x00FF0200);
	tmc4672_writeInt(motor, TMC4672_PID_TORQUE_P_TORQUE_I, 0x00FF0200);
	tmc4672_writeInt(motor, TMC4672_PID_VELOCITY_P_VELOCITY_I, 0x00FF0200);
	tmc4672_writeInt(motor, TMC4672_PID_POSITION_P_POSITION_I, 0x00200000);
}
