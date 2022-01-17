/*
 * StepDir.h
 *
 *  Created on: 08.12.2017
 *      Author: LH
 */

#ifndef TMC_HELPERS_STEPDIR_H_
#define TMC_HELPERS_STEPDIR_H_

	#include "TypeDefs.h"

	// Precision of the binary value of velocity & position accumulators
	// For pulse/sec being equal to the velocity and acceleration scalars,
	// set the frequency of the interrupt calling StepDir_tick() to 2^ACCU_PRECISION
	#define ACCU_PRECISION  17

	// 1 per motor
	#define CHANNELS 2

	#define SEQUENCE_BUFFER_SIZE 256

	typedef enum {
		LEFT,
		RIGHT
	} Direction;

	// Sequence point typedefs
	typedef enum TriggerCondition
	{
		TRIGGER_NEVER,
		TRIGGER_ALWAYS,
		TRIGGER_VELOCITY_LT,  // velocity <= threshold
		TRIGGER_VELOCITY_GT,  // velocity >= threshold
		TRIGGER_POSITION_LT,  // position <= threshold
		TRIGGER_POSITION_GT   // position >= threshold
	} TriggerCondition;

	typedef enum SequenceAction
	{
		ACTION_STOP,         // Hard stop - Blocks further motions. While moving only use this as emergency off
		ACTION_NONE,         // Usable to wait for special conditions (position was > 100, now <100 again)
		ACTION_ACCELERATION,
		ACTION_VELOCITY,
		ACTION_POSITION
	} SequenceAction;

	typedef struct
	{
		TriggerCondition  condition;
		int32             threshold;  // Value compared to when trigger action is TRIGGER_POSITION or TRIGGER_VELOCITY
		SequenceAction    action;
		int32             value;
	} SequencePoint;

	// StepDir Channel Typedef
	typedef struct {
		// Acceleration
		uint32 acceleration;

		// Velocity
		int32 velocity;
		Direction velocityDirection;
		int32 velocityAccu;

		// Position
		int32 position;
		Direction positionDirection;
		int32 positionAccu;

		// Flags
		uint8 channelHalted;
		// Callbacks: Step & Dir pin controls

	} StepDirChannel;



	/* Movement functions:
	 * rotate
	 * stop
	 * moveTo
	 * moveRel
	 *
	 * Infrastructure functions:
	 * StepDir_tick
	 * StepDir_reset // used to clear ACTION_STOP's block
	 */
	void StepDir_tick(void);

#endif /* TMC_HELPERS_STEPDIR_H_ */
