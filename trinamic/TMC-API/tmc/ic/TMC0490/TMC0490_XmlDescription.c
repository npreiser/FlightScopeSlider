
// ===== used for xml file generation =====

// \xml <?xml version="1.0" encoding="UTF-8" standalone="no"?>
// \xml <tmc:product_ic name="IC_NAME" version="1.0" author="BS" xmlns:tmc="http://www.trinamic.com" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://www.trinamic.com http://trinamic.com/bridge/xml/TMC_Schema.xsd">
// \xml <tmc:register_set for="IC_NAME" name="All Registers">

// \xml <tmc:group name="Status information"       id="#TMC0490_GROUP_STATUS_INFORMATION#"></tmc:group>
// \xml <tmc:group name="General settings"         id="#TMC0490_GROUP_GENERAL_SETTINGS#"></tmc:group>
// \xml <tmc:group name="ADCs" 					   id="#TMC0490_GROUP_ADCS#"></tmc:group>
// \xml <tmc:group name="Inputs/Outputs"           id="#TMC0490_GROUP_IO#"></tmc:group>
// \xml <tmc:group name="PWM"                      id="#TMC0490_GROUP_PWM#"></tmc:group>
// \xml <tmc:group name="Decoder ABN"              id="#TMC0490_GROUP_DECODER_ABN#"></tmc:group>
// \xml <tmc:group name="Hall digital"             id="#TMC0490_GROUP_HALL_DIGITAL#"></tmc:group>
// \xml <tmc:group name="Hall analog"              id="#TMC0490_GROUP_HALL_ANALOG#"></tmc:group>
// \xml <tmc:group name="Decoder analog"           id="#TMC0490_GROUP_DECODER_ANALOG#"></tmc:group>
// \xml <tmc:group name="PID regulators"           id="#TMC0490_GROUP_PID_REGULATORS#"></tmc:group>


// \xml <tmc:value_register address="#CHIPINFO_DATA#" name="CHIPINFO_DATA" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="Variant 0">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_TYPE" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_ascii desc="Hardware type (ASCII)." access="R"></tmc:value_ascii>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="0" range_to="0"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 1">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_VERSION" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_version desc="Hardware version (u16.u16)." access="R"></tmc:value_version>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="1" range_to="1"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 2">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_DATE" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_date desc="Hardware date (nibble wise date stamp yyyymmdd)." access="R"></tmc:value_date>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="2" range_to="2"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 3">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_TIME" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_time desc="Hardware time (nibble wise time stamp --hhmmss)" access="R"></tmc:value_time>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="3" range_to="3"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml </tmc:value_register>

// \xml <tmc:value_register address="#CHIPINFO_ADDR#" name="CHIPINFO_ADDR" size="32"  group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Chip info address</desc>
// \xml       <tmc:value_register_field name="CHIP_INFO_ADDRESS" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="SI_TYPE"></choice_element>
// \xml            <choice_element value="1" desc="SI_VERSION"></choice_element>
// \xml            <choice_element value="2" desc="SI_DATE"></choice_element>
// \xml            <choice_element value="3" desc="SI_TIME"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacts address="#CHIPINFO_DATA#"></tmc:register_variant_impacts>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#STATUS_WORD#" name="STATUS_WORD" size="32" group="#TMC0490_GROUP_EMPTY#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATUS_WORD" shift="0" mask="0000FFFF" desc="description of STATUS_WORD">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#COMMAND_WORD#" name="COMMAND_WORD" size="32" group="#TMC0490_GROUP_EMPTY#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="COMMAND_WORD" shift="0" mask="FFFFFFFF" desc="description of COMMAND_WORD">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#P_FAK_BUCK#" name="P_FAK_BUCK" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="P_FAK_BUCK" shift="0" mask="0000FFFF" desc="description of P_FAK_BUCK">
// \xml    	     <tmc:value_unsigned min="0" max="#S16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#I_FAK_BUCK#" name="I_FAK_BUCK" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="I_FAK_BUCK" shift="0" mask="0000FFFF" desc="description of I_FAK_BUCK">
// \xml    	     <tmc:value_unsigned min="0" max="#S16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#P_FAK_BOOST#" name="P_FAK_BOOST" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="P_FAK_BOOST" shift="0" mask="0000FFFF" desc="description of P_FAK_BOOST">
// \xml    	     <tmc:value_unsigned min="0" max="#S16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#I_FAK_BOOST#" name="I_FAK_BOOST" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="I_FAK_BOOST" shift="0" mask="0000FFFF" desc="description of I_FAK_BOOST">
// \xml    	     <tmc:value_unsigned min="0" max="#S16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#U_MAX_RAIL#" name="U_MAX_RAIL" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="U_MAX_RAIL" shift="0" mask="0000FFFF" desc="description of U_MAX_RAIL">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#U_MIN_RAIL#" name="U_MIN_RAIL" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="U_MIN_RAIL" shift="0" mask="0000FFFF" desc="description of U_MIN_RAIL">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#U_MAX_SCAP#" name="U_MAX_SCAP" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="U_MAX_SCAP" shift="0" mask="0000FFFF" desc="description of U_MAX_SCAP">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#U_MIN_SCAP#" name="U_MIN_SCAP" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="U_MIN_SCAP" shift="0" mask="0000FFFF" desc="description of U_MIN_SCAP">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#U_NOM_RAIL#" name="U_NOM_RAIL" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="U_NOM_RAIL" shift="0" mask="0000FFFF" desc="description of U_NOM_RAIL">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#DELTA_VOLT#" name="DELTA_VOLT" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DELTA_VOLT" shift="0" mask="0000FFFF" desc="description of DELTA_VOLT">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#U_TARGET_RAIL#" name="U_TARGET_RAIL" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="U_TARGET_RAIL" shift="0" mask="0000FFFF" desc="description of U_TARGET_RAIL">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#I_MAX_SW#" name="I_MAX_SW" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="I_MAX_SW" shift="0" mask="0000FFFF" desc="description of I_MAX_SW">
// \xml    	     <tmc:value_unsigned min="0" max="#S16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#I_MAX_RAIL#" name="I_MAX_RAIL" size="32" group="#TMC0490_GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="I_MAX_RAIL" shift="0" mask="0000FFFF" desc="description of I_MAX_RAIL">
// \xml    	     <tmc:value_unsigned min="0" max="#S16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#OSCI_MAIN_CONFIG_REG#" name="OSCI_MAIN_CONFIG_REG" size="32" group="#TMC0490_GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="OSCI_MAIN_CONFIG_REG" shift="0" mask="FFFFFFFF" desc="description of OSCI_MAIN_CONFIG_REG">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#OSCI_PRETRIGGER_CONFIG_REG#" name="OSCI_PRETRIGGER_CONFIG_REG" size="32" group="#TMC0490_GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="OSCI_PRETRIGGER_CONFIG_REG" shift="0" mask="0000FFFF" desc="description of OSCI_PRETRIGGER_CONFIG_REG">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#OSCI_DATA_ADDRESS#" name="OSCI_DATA_ADDRESS" size="32" group="#TMC0490_GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="OSCI_DATA_ADDRESS" shift="0" mask="0000FFFF" desc="description of OSCI_DATA_ADDRESS">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#OSCI_STATUS#" name="OSCI_STATUS" size="32" group="#TMC0490_GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="OSCI_STATUS" shift="0" mask="0000FFFF" desc="description of OSCI_STATUS">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#OSCI_OUTPUT_DATA#" name="OSCI_OUTPUT_DATA" size="32" group="#TMC0490_GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="OSCI_OUTPUT_DATA" shift="0" mask="FFFFFFFF" desc="description of OSCI_OUTPUT_DATA">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#ADC_I_RAIL_RAW#" name="ADC_I_RAIL_RAW" size="32" group="#TMC0490_GROUP_IO#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_I_RAIL_RAW" shift="0" mask="0000FFFF" desc="description of ADC_I_RAIL_RAW">
// \xml    	     <tmc:value_unsigned min="0" max="#S16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#ADC_I_SW_RAW#" name="ADC_I_SW_RAW" size="32" group="#TMC0490_GROUP_IO#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_I_SW_RAW" shift="0" mask="0000FFFF" desc="description of ADC_I_SW_RAW">
// \xml    	     <tmc:value_unsigned min="0" max="#S16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#ADC_U_RAIL_RAW#" name="ADC_U_RAIL_RAW" size="32" group="#TMC0490_GROUP_IO#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_U_RAIL_RAW" shift="0" mask="0000FFFF" desc="description of ADC_U_RAIL_RAW">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#ADC_U_CAP_RAW#" name="ADC_U_CAP_RAW" size="32" group="#TMC0490_GROUP_IO#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_U_CAP_RAW" shift="0" mask="0000FFFF" desc="description of ADC_U_CAP_RAW">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#PWM_VALUE_HS#" name="PWM_VALUE_HS" size="32" group="#TMC0490_GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_VALUE_HS" shift="0" mask="0000FFFF" desc="description of PWM_VALUE_HS">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#PWM_VALUE_LS#" name="PWM_VALUE_LS" size="32" group="#TMC0490_GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_VALUE_LS" shift="0" mask="0000FFFF" desc="description of PWM_VALUE_LS">
// \xml    	     <tmc:value_unsigned min="0" max="#U16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#I_STATE_BUCK#" name="I_STATE_BUCK" size="32" group="#TMC0490_GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="I_STATE_BUCK" shift="0" mask="FFFFFFFF" desc="description of I_STATE_BUCK">
// \xml    	     <tmc:value_unsigned min="0" max="#S32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#I_STATE_BOOST#" name="I_STATE_BOOST" size="32" group="#TMC0490_GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="I_STATE_BOOST" shift="0" mask="FFFFFFFF" desc="description of I_STATE_BOOST">
// \xml    	     <tmc:value_unsigned min="0" max="#S32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#DEBUG_AXIS_PARAM_0#" name="DEBUG_AXIS_PARAM_0" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_AXIS_PARAM_0" shift="0" mask="FFFFFFFF" desc="description of DEBUG_AXIS_PARAM_0">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#DEBUG_AXIS_PARAM_1#" name="DEBUG_AXIS_PARAM_1" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_AXIS_PARAM_1" shift="0" mask="FFFFFFFF" desc="description of DEBUG_AXIS_PARAM_1">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#DEBUG_AXIS_PARAM_2#" name="DEBUG_AXIS_PARAM_2" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_AXIS_PARAM_2" shift="0" mask="FFFFFFFF" desc="description of DEBUG_AXIS_PARAM_2">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#DEBUG_AXIS_PARAM_3#" name="DEBUG_AXIS_PARAM_3" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_AXIS_PARAM_3" shift="0" mask="FFFFFFFF" desc="description of DEBUG_AXIS_PARAM_3">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#DEBUG_AXIS_PARAM_4#" name="DEBUG_AXIS_PARAM_4" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_AXIS_PARAM_4" shift="0" mask="FFFFFFFF" desc="description of DEBUG_AXIS_PARAM_4">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#DEBUG_AXIS_PARAM_5#" name="DEBUG_AXIS_PARAM_5" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_AXIS_PARAM_5" shift="0" mask="FFFFFFFF" desc="description of DEBUG_AXIS_PARAM_5">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#DEBUG_AXIS_PARAM_6#" name="DEBUG_AXIS_PARAM_6" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_AXIS_PARAM_6" shift="0" mask="FFFFFFFF" desc="description of DEBUG_AXIS_PARAM_6">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#DEBUG_AXIS_PARAM_7#" name="DEBUG_AXIS_PARAM_7" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_AXIS_PARAM_7" shift="0" mask="FFFFFFFF" desc="description of DEBUG_AXIS_PARAM_7">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#STATE_VAR_PARAM_0#" name="STATE_VAR_PARAM_0" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATE_VAR_PARAM_0" shift="0" mask="FFFFFFFF" desc="description of STATE_VAR_PARAM_0">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#STATE_VAR_PARAM_1#" name="STATE_VAR_PARAM_1" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATE_VAR_PARAM_1" shift="0" mask="FFFFFFFF" desc="description of STATE_VAR_PARAM_1">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#STATE_VAR_PARAM_2#" name="STATE_VAR_PARAM_2" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATE_VAR_PARAM_2" shift="0" mask="FFFFFFFF" desc="description of STATE_VAR_PARAM_2">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#STATE_VAR_PARAM_3#" name="STATE_VAR_PARAM_3" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATE_VAR_PARAM_3" shift="0" mask="FFFFFFFF" desc="description of STATE_VAR_PARAM_3">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#STATE_VAR_PARAM_4#" name="STATE_VAR_PARAM_4" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATE_VAR_PARAM_4" shift="0" mask="FFFFFFFF" desc="description of STATE_VAR_PARAM_4">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#STATE_VAR_PARAM_5#" name="STATE_VAR_PARAM_5" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATE_VAR_PARAM_5" shift="0" mask="FFFFFFFF" desc="description of STATE_VAR_PARAM_5">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#STATE_VAR_PARAM_6#" name="STATE_VAR_PARAM_6" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATE_VAR_PARAM_6" shift="0" mask="FFFFFFFF" desc="description of STATE_VAR_PARAM_6">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#STATE_VAR_PARAM_7#" name="STATE_VAR_PARAM_7" size="32" group="#TMC0490_GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATE_VAR_PARAM_7" shift="0" mask="FFFFFFFF" desc="description of STATE_VAR_PARAM_7">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#SCU_INPUTS_RAW#" name="SCU_INPUTS_RAW" size="32" group="#TMC0490_GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SCU_INPUTS_RAW" shift="0" mask="FFFFFFFF" desc="description of SCU_INPUTS_RAW">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#SCU_OUTPUTS_RAW#" name="SCU_OUTPUTS_RAW" size="32" group="#TMC0490_GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SCU_OUTPUTS_RAW" shift="0" mask="FFFFFFFF" desc="description of SCU_OUTPUTS_RAW">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#STATUS_FLAGS#" name="STATUS_FLAGS" size="32" group="#TMC0490_GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATUS_FLAGS" shift="0" mask="FFFFFFFF" desc="description of STATUS_FLAGS">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#WARNING_MASK#" name="WARNING_MASK" size="32" group="#TMC0490_GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="WARNING_MASK" shift="0" mask="FFFFFFFF" desc="description of WARNING_MASK">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>


// \xml <tmc:value_register address="#ERROR_MASK#" name="ERROR_MASK" size="32" group="#TMC0490_GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ERROR_MASK" shift="0" mask="FFFFFFFF" desc="description of ERROR_MASK">
// \xml    	     <tmc:value_unsigned min="0" max="#U32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml </tmc:register_set>
// \xml </tmc:product_ic>
