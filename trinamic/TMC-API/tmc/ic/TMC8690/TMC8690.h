/*
 * TMC8690.h
 *
 *  Created on: 18.07.2016
 *      Author: bs, ed
 */

#ifndef API_IC_TMC8690_H
#define API_IC_TMC8690_H
	#define ENABLE_IC_SCOPE

	#include "../../helpers/API_Header.h"
	#include "TMC8690_Register.h"
	#include "TMC8690_Mask_Shift.h"

	#define TMC8690_FIELD_READ(motor, address, mask, shift) \
		FIELD_READ(tmc8690_readInt, motor, address, mask, shift)
	#define TMC8690_FIELD_WRITE(motor, address, mask, shift, value) \
		FIELD_WRITE(tmc8690_writeInt, motor, address, mask, shift, value)
	#define TMC8690_FIELD_UPDATE(motor, address, mask, shift, value) \
		FIELD_UPDATE(tmc8690_readInt, tmc8690_writeInt, motor, address, mask, shift, value)

//	void tmc8690_init();
//	void tmc8690_periodicJob(u32 actualSystick);

#endif /* API_IC_TMC8690_H_ */
