/*
 * TMC0490_Registers.h
 *
 *  Created on: 18.07.2016
 *      Author: bs, ed
 */

#ifndef TMC0490_REGISTERS_H_
#define TMC0490_REGISTERS_H_

	// ===== TMC0490 register set =====

	// --- status information ---
	#define CHIPINFO_DATA               0x00
	#define CHIPINFO_ADDR               0x01
	#define STATUS_WORD                 0x02
	#define COMMAND_WORD                0x03
	#define P_FAK_BUCK                  0x04
	#define I_FAK_BUCK                  0x05
	#define P_FAK_BOOST                 0x06
	#define I_FAK_BOOST                 0x07
	#define U_MAX_RAIL                  0x08
	#define U_MIN_RAIL                  0x09
	#define U_MAX_SCAP                  0x0A
	#define U_MIN_SCAP                  0x0B
	#define U_NOM_RAIL                  0x0C
	#define DELTA_VOLT                  0x0D
	#define U_TARGET_RAIL               0x0E
	#define I_MAX_SW                    0x0F
	#define I_MAX_RAIL                  0x10
	#define OSCI_MAIN_CONFIG_REG        0x11
	#define OSCI_PRETRIGGER_CONFIG_REG  0x12
	#define OSCI_DATA_ADDRESS           0x13
	#define OSCI_STATUS                 0x14
	#define OSCI_OUTPUT_DATA            0x15
	#define ADC_I_RAIL_RAW              0x20
	#define ADC_I_SW_RAW                0x21
	#define ADC_U_RAIL_RAW              0x22
	#define ADC_U_CAP_RAW               0x23
	#define PWM_VALUE_HS                0x24
	#define PWM_VALUE_LS                0x25
	#define I_STATE_BUCK                0x26
	#define I_STATE_BOOST               0x27
	#define DEBUG_AXIS_PARAM_0          0x30
	#define DEBUG_AXIS_PARAM_1          0x31
	#define DEBUG_AXIS_PARAM_2          0x32
	#define DEBUG_AXIS_PARAM_3          0x33
	#define DEBUG_AXIS_PARAM_4          0x34
	#define DEBUG_AXIS_PARAM_5          0x35
	#define DEBUG_AXIS_PARAM_6          0x36
	#define DEBUG_AXIS_PARAM_7          0x37
	#define STATE_VAR_PARAM_0           0x38
	#define STATE_VAR_PARAM_1           0x39
	#define STATE_VAR_PARAM_2           0x3A
	#define STATE_VAR_PARAM_3           0x3B
	#define STATE_VAR_PARAM_4           0x3C
	#define STATE_VAR_PARAM_5           0x3D
	#define STATE_VAR_PARAM_6           0x3E
	#define STATE_VAR_PARAM_7           0x3F
	#define SCU_INPUTS_RAW              0x76
	#define SCU_OUTPUTS_RAW             0x77
	#define STATUS_FLAGS                0x7C
	#define WARNING_MASK                0x7D
	#define ERROR_MASK                  0x7E

#endif /* TMC0490_REGISTERS_H_ */
