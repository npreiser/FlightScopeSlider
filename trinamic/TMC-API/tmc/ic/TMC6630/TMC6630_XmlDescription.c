
// ===== used for xml file generation =====

// \xml <?xml version="1.0" encoding="UTF-8" standalone="no"?>
// \xml <tmc:product_ic name="TMC6630" version="1.0" author="ed" xmlns:tmc="http://www.trinamic.com" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="https://www.trinamic.com https://www.trinamic.com/fileadmin/xml/TMC_Schema.xsd">
// \xml <desc>Three phase motor control IC.</desc>
// \xml <desc>Sensorless six-step BLDC commutation.</desc>

// \xml <tmc:register_set for="TMC6630" name="All Registers">

// \xml <tmc:group name="Status information"       id="#GROUP_STATUS_INFORMATION#"></tmc:group>
// \xml <tmc:group name="ADCs" 					   id="#GROUP_ADCS#"></tmc:group>
// \xml <tmc:group name="Inputs/Outputs"           id="#GROUP_IO#"></tmc:group>
// \xml <tmc:group name="Sensorless"			   id="#GROUP_SENSORLESS#"></tmc:group>
// \xml <tmc:group name="Operation modes"          id="#GROUP_OPERATION_MODES#"></tmc:group>
// \xml <tmc:group name="PWM_cntl mode"            id="#GROUP_PWM_INPUT#"></tmc:group>
// \xml <tmc:group name="PWM_ext mode"			   id="#GROUP_PWM_MODE#"></tmc:group>
// \xml <tmc:group name="Torque mode"			   id="#GROUP_TORQUE_MODE#"></tmc:group>
// \xml <tmc:group name="Velocity mode"            id="#GROUP_VELOCITY_MODE#"></tmc:group>
// \xml <tmc:group name="Position mode"            id="#GROUP_POSITION_MODE#"></tmc:group>
// \xml <tmc:group name="Integration"			   id="#GROUP_INTEGRATION#"></tmc:group>

// \xml <tmc:value_register address="#TMC6630_CHIPINFO_DATA#" name="CHIPINFO_DATA" size="32" group="#GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="Variant 0">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_TYPE" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_ascii desc="Hardware type (ASCII)." access="R"></tmc:value_ascii>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC6630_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="0" range_to="0"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 1">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_VERSION" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_version desc="Hardware version (u16.u16)." access="R"></tmc:value_version>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC6630_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="1" range_to="1"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 2">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_DATE" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_date desc="Hardware date (nibble wise date stamp yyyymmdd)." access="R"></tmc:value_date>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC6630_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="2" range_to="2"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 3">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_TIME" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_time desc="Hardware time (nibble wise time stamp --hhmmss)" access="R"></tmc:value_time>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC6630_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="3" range_to="3"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 4">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_VARIANT" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC6630_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="4" range_to="4"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_CHIPINFO_ADDR#" name="CHIPINFO_ADDR" size="32"  group="#GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Chip info address</desc>
// \xml       <tmc:value_register_field name="CHIP_INFO_ADDRESS" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="SI_TYPE"></choice_element>
// \xml            <choice_element value="1" desc="SI_VERSION"></choice_element>
// \xml            <choice_element value="2" desc="SI_DATE"></choice_element>
// \xml            <choice_element value="3" desc="SI_TIME"></choice_element>
// \xml            <choice_element value="4" desc="SI_VARIANT"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacts address="#TMC6630_CHIPINFO_DATA#"></tmc:register_variant_impacts>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_GENERAL_CONF#" name="GENERAL_CONF" size="32" group="#GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DISABLE_S2G" shift="0" mask="00000001" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DISABLE_S2VS" shift="1" mask="00000002" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SHORT_DELAY" shift="2" mask="00000004" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PROTECT_PARALLEL" shift="3" mask="00000008" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="SHORT_RETRY" shift="4" mask="00000030" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="3" default="1" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="FILTER_SHORT" shift="6" mask="000000C0" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="3" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="S2G_DAC" shift="8" mask="00000F00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="15" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="S2VS_DAC" shift="12" mask="0000F000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="15" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="SHORT_DELAY" shift="16" mask="00030000" desc="">
// \xml          <tmc:value_choice default="1" unit="" access="RW">
// \xml            <choice_element value="0" desc="Weak"></choice_element>
// \xml            <choice_element value="1" desc="Weak+Medium (TEMP_PREWARNING)"></choice_element>
// \xml            <choice_element value="2" desc="Medium"></choice_element>
// \xml            <choice_element value="3" desc="Strong"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="AMPLIFIER_OFF" shift="18" mask="00040000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="AMPLIFICATION" shift="19" mask="00080000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TEMP_SHUTOFF_LIMIT" shift="20" mask="00300000" desc="">
// \xml          <tmc:value_choice default="1" unit="" access="RW">
// \xml            <choice_element value="0" desc="No temperature shutoff"></choice_element>
// \xml            <choice_element value="1" desc="136 degree"></choice_element>
// \xml            <choice_element value="2" desc="143 degree"></choice_element>
// \xml            <choice_element value="3" desc="150 degree"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="FILT_ISENSE" shift="22" mask="00C00000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="3" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="DISABLE_STOP_MODE_AT_TARGET0" shift="24" mask="01000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="DISABLE_EXT_DIR" shift="25" mask="02000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="UNUSED" shift="26" mask="04000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="UNUSED" shift="27" mask="08000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="UNUSED" shift="28" mask="10000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="UNUSED" shift="29" mask="20000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="UNUSED" shift="30" mask="40000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="UNUSED" shift="31" mask="80000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_STATUS#" name="STATUS" size="32" group="#GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="LS_U_SHORT" shift="0" mask="00000001" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HS_U_SHORT" shift="1" mask="00000002" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="LS_V_SHORT" shift="2" mask="00000004" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HS_V_SHORT" shift="3" mask="00000008" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="LS_W_SHORT" shift="4" mask="00000010" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HS_W_SHORT" shift="5" mask="00000020" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEMP_PREWARNING" shift="6" mask="00000040" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEMP_SHUTOFF" shift="7" mask="00000080" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="STST" shift="8" mask="00000100" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="UV_CP" shift="9" mask="00000200" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TONE_ACTIVE" shift="10" mask="00000400" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SHORTS_LS_DETECTED" shift="11" mask="00000800" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SHORTS_HS_DETECTED" shift="12" mask="00001000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="STDBY_STATE" shift="13" mask="00006000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="R">
// \xml            <choice_element value="0" desc="no standby"></choice_element>
// \xml            <choice_element value="1" desc="STOP_MODE 0x00 active"></choice_element>
// \xml            <choice_element value="2" desc="STDBY active"></choice_element>
// \xml            <choice_element value="3" desc="STOP_MODE_0x01 active"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="RST_DONE" shift="15" mask="00008000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="LS_U_SHORT_SELECT" shift="16" mask="00010000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HS_U_SHORT_SELECT" shift="17" mask="00020000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="LS_V_SHORT_SELECT" shift="18" mask="00040000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HS_V_SHORT_SELECT" shift="19" mask="00080000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="LS_W_SHORT_SELECT" shift="20" mask="00100000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HS_W_SHORT_SELECT" shift="21" mask="00200000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEMP_PREWARNING_SELECT" shift="22" mask="00400000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEMP_SHUTOFF_SELECT" shift="23" mask="00800000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="STST_SELECT" shift="24" mask="01000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="UV_CP_SELECT" shift="25" mask="02000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SHORTS_LS_DETECTED_SELECT" shift="27" mask="08000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SHORTS_HS_DETECTED_SELECT" shift="28" mask="10000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="RST_DONE_SELECT" shift="31" mask="80000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_INPUT_RAW#" name="INPUT_RAW" size="32" group="#GROUP_IO#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>

// \xml       <tmc:value_register_field name="DRV_EN" shift="0" mask="00000001" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="EXT_GATE_SG_ON" shift="1" mask="00000002" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="BL_U_INPUT" shift="2" mask="00000004" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="BH_U_INPUT" shift="3" mask="00000008" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="BL_V_INPUT" shift="4" mask="00000010" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="BH_V_INPUT" shift="5" mask="00000020" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="BL_W_INPUT" shift="6" mask="00000040" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="BH_W_INPUT" shift="7" mask="00000080" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="S2G_U" shift="8" mask="00000100" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="S2G_V" shift="9" mask="00000200" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="S2G_W" shift="10" mask="00000400" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="S2VS_U" shift="11" mask="00000800" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="S2VS_V" shift="12" mask="00001000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="S2VS_W" shift="13" mask="00002000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="UV_CP" shift="14" mask="00004000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="OTP_IN" shift="15" mask="00008000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TEMP_PRE" shift="16" mask="00010000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="OV136" shift="17" mask="00020000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="OV143" shift="18" mask="00040000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="OV150" shift="19" mask="00080000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="COMP_U_VW" shift="20" mask="00100000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="COMP_V_UW" shift="21" mask="00200000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="COMP_W_UV" shift="22" mask="00400000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="COMP_DAC" shift="23" mask="00800000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="PWM_CNTL" shift="24" mask="01000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="CLK_WD_ERROR" shift="25" mask="02000000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="INPUTS_RAW[26]" shift="26" mask="04000000" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="INPUTS_RAW[27]" shift="27" mask="08000000" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="INPUTS_RAW[28]" shift="28" mask="10000000" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="INPUTS_RAW[29]" shift="29" mask="20000000" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="INPUTS_RAW[30]" shift="30" mask="40000000" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="INPUTS_RAW[31]" shift="31" mask="80000000" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_COMP_RAW_WVU#" name="COMP_RAW_WVU" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="COMP_RAW_U" shift="0" mask="000003FF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u10_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="COMP_RAW_V" shift="10" mask="000FFC00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u10_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="COMP_RAW_W" shift="20" mask="3FF00000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u10_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_ADC_RAW_N_CALCULATED_U_BEMF#" name="ADC_RAW_N_CALCULATED_U_BEMF" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="U_BEMF" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_RAW_N_CALCULATED" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_Z_BLK_CNTS_FILT_LENGTH_NCALC#" name="Z_BLK_CNTS_FILT_LENGTH_NCALC" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FILT_LENGTH_NCALC" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="Filter through 1 value (filter off)"></choice_element>
// \xml            <choice_element value="1" desc="Filter through 2 values"></choice_element>
// \xml            <choice_element value="2" desc="Filter through 4 values"></choice_element>
// \xml            <choice_element value="3" desc="Filter through 8 values"></choice_element>
// \xml            <choice_element value="4" desc="Filter through 16 values"></choice_element>
// \xml            <choice_element value="5" desc="Filter through 32 values"></choice_element>
// \xml            <choice_element value="6" desc="Filter through 64 values"></choice_element>
// \xml            <choice_element value="7" desc="Filter through 128 values"></choice_element>
// \xml            <choice_element value="8" desc="Filter through 256 values"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="Z_BLK_CNTS" shift="8" mask="0000FF00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_AUTO_ZERO_VAL_IB_COMP#" name="AUTO_ZERO_VAL_IB_COMP" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="IB_COMP" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AUTO_ZERO_VAL" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_IB_OFFSET_CONF_FILT_LENGTH#" name="IB_OFFSET_CONF_FILT_LENGTH" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FILT_LENGTH_IB" shift="0" mask="000000FF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="8" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="IB_CONF" shift="8" mask="00000300" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="No action"></choice_element>
// \xml            <choice_element value="1" desc="AUTO_ZERO_START"></choice_element>
// \xml            <choice_element value="2" desc="USE_EXT_COMP_VAL"></choice_element>
// \xml            <choice_element value="3" desc="USE_EXT_COMP_VAL_AS_AUTOZERO"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="EXT_COMP_VAL[0]" shift="12" mask="00001000" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="EXT_COMP_VAL[1]" shift="13" mask="00002000" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="EXT_COMP_VAL[2]" shift="14" mask="00004000" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="EXT_COMP_VAL[3]" shift="15" mask="00008000" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="IB_OFFSET" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_DIR_HALL_ACTUAL_ADC_IB#" name="DIR_HALL_ACTUAL_ADC_IB" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_IB_FILTERED" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_ACTUAL" shift="16" mask="00FF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DIR" shift="24" mask="01000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_TRIGGER_PWM_CNT_SG_HALL_STATE#" name="TRIGGER_PWM_CNT_SG_HALL_STATE" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="TRIGGER_HALL_STATE" shift="0" mask="000000FF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TRIGGER_SG" shift="8" mask="0000FF00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TRIGGER_PWM_CNT" shift="16" mask="00FF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="ANAOUT_SW" shift="24" mask="FF000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_AUTO_SWITCH_ON_OFF#" name="AUTO_SWITCH_ON_OFF" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AUTO_SWITCH_OFF" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AUTO_SWITCH_ON" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_START_CONF#" name="START_CONF" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="START_VALUE" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u15_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="START_ALIGNMENT_EXP" shift="16" mask="00FF0000" desc="Exponent for number of PWM-Intervals during Startphase.">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_EXT/START_VALUE" shift="24" mask="FF000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_OP_MODE#" name="OP_MODE" size="32" group="#GROUP_OPERATION_MODES#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="MOTION_MODE" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="Stop"></choice_element>
// \xml            <choice_element value="2" desc="PWM_Ext mode"></choice_element>
// \xml            <choice_element value="3" desc="PWM_CNTL mode"></choice_element>
// \xml            <choice_element value="4" desc="Torque mode"></choice_element>
// \xml            <choice_element value="5" desc="Torque_CNTL mode"></choice_element>
// \xml            <choice_element value="8" desc="Velocity mode"></choice_element>
// \xml            <choice_element value="9" desc="Velocity_CNTL mode"></choice_element>
// \xml            <choice_element value="16" desc="Inductance Sensing mode, 0 after Induct-HallValue"></choice_element>
// \xml            <choice_element value="32" desc="Inductance Sensing mode, float after Induct-HallValue"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="STOP_MODE" shift="8" mask="0000FF00" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="PWM=0, all float (default)"></choice_element>
// \xml            <choice_element value="1" desc="PWM=0, all gnd, pwm ddt enabled"></choice_element>
// \xml            <choice_element value="2" desc="PWM=0, all gnd"></choice_element>
// \xml            <choice_element value="4" desc="PWM=0, use  any hall state"></choice_element>
// \xml            <choice_element value="16" desc="PWM=x,  use actual hall state"></choice_element>
// \xml            <choice_element value="32" desc="TORQUE_TARGET=0"></choice_element>
// \xml            <choice_element value="64" desc="VEL_TARGET=0"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="COMMUTATION_MODE" shift="16" mask="00FF0000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="Block"></choice_element>
// \xml            <choice_element value="1" desc="Advanced Trapezoidal"></choice_element>
// \xml            <choice_element value="2" desc="Block/Advanced Trapezoidal"></choice_element>
// \xml            <choice_element value="4" desc="Controlled Sine (angle and amplifier)"></choice_element>
// \xml            <choice_element value="8" desc="Direct PWM control"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_IN_DIR" shift="24" mask="01000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="1" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//==================== pwm settings ====================

// \xml <tmc:value_register address="#TMC6630_PWM_BBM_CHOP_OPTS#" name="PWM_BBM_CHOP_OPTS" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SOUND_EN" shift="0" mask="00000001" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="USE_DYNAMIC_PWM" shift="1" mask="00000002" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="USE_PWM_LIMIT_DDT" shift="2" mask="00000004" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="USE_ADAPTIV_PWM" shift="3" mask="00000008" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="USE_EXT_GATE_SG" shift="4" mask="00000010" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="EXT_GATE_SG_DIFF_ENABLE" shift="5" mask="00000020" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="PWM_MAXCNTLIM" shift="6" mask="000000C0" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="256"></choice_element>
// \xml            <choice_element value="1" desc="1/4 * MAXCNT"></choice_element>
// \xml            <choice_element value="2" desc="1/2 * MAXCNT"></choice_element>
// \xml            <choice_element value="3" desc="3/4 * MAXCNT"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="CHOP_OPTS" shift="8" mask="00000700" desc="">
// \xml          <tmc:value_choice default="2" unit="" access="RW">
// \xml            <choice_element value="0" desc="Centered twisted HS/LS"></choice_element>
// \xml            <choice_element value="1" desc="HS=on, LS=chop"></choice_element>
// \xml            <choice_element value="2" desc="HS=chop, LS=on"></choice_element>
// \xml            <choice_element value="3" desc="HS=chop, LS=chop"></choice_element>
// \xml            <choice_element value="4" desc="Bipolar LS/HS-Chopper"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="PWM_BBM" shift="16" mask="00FF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="8" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_FREQ_MAXCNT#" name="PWM_FREQ_MAXCNT" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_MAXCNT" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_FREQ" shift="16" mask="00070000" desc="">
// \xml          <tmc:value_choice default="4" unit="" access="RW">
// \xml            <choice_element value="0" desc="200 kHz"></choice_element>
// \xml            <choice_element value="1" desc="100 kHz"></choice_element>
// \xml            <choice_element value="2" desc="80 kHz"></choice_element>
// \xml            <choice_element value="3" desc="50 kHz"></choice_element>
// \xml            <choice_element value="4" desc="32 kHz (default)"></choice_element>
// \xml            <choice_element value="5" desc="25 kHz"></choice_element>
// \xml            <choice_element value="6" desc="20 kHz"></choice_element>
// \xml            <choice_element value="7" desc="16 kHz"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="USE_PWM_FREQ_DIRECTLY" shift="5" mask="00080000" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="CLK_FREQ" shift="24" mask="03000000" desc="">
// \xml          <tmc:value_choice default="4" unit="" access="RW">
// \xml            <choice_element value="0" desc="100 / 64 MHz"></choice_element>
// \xml            <choice_element value="1" desc="50 / 32 MHz"></choice_element>
// \xml            <choice_element value="2" desc="25 / 16 MHz"></choice_element>
// \xml            <choice_element value="3" desc="12.5 / 8MHz"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="CLK_CORE" shift="5" mask="08000000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="100 MHz"></choice_element>
// \xml            <choice_element value="1" desc="60 MHz"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_LIMIT_HIGH_LOW#" name="PWM_LIMIT_HIGH_LOW" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_LIMIT_LOW" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_LIMIT_HIGH" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_LIMIT_DDT#" name="PWM_LIMIT_DDT" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_LIMIT_DDT" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_VALUE#" name="PWM_VALUE" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_VALUE" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_MAXCNT_INT_VALUE_INT#" name="PWM_MAXCNT_INT_VALUE_INT" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_VALUE_INT" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_MAXCNT_INT" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_VALUE_DEBUG#" name="PWM_VALUE_DEBUG" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CNT_PWM_CYCLES" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_VALUE_RELATIV_ACTUAL" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_VALUE_RELATIV#" name="PWM_VALUE_RELATIV" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_VALUE_RELATIV" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_MIN_STALL_VALUE#" name="PWM_MIN_STALL_VALUE" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_MIN_STALL_VALUE" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_SOUND_OPTS#" name="SOUND_OPTS" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="TONE_FREQ" shift="0" mask="0000FFFF" desc="tone_frequency [Hz] = PWM-frequency / TONE_FREQ">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TONE_LOUDNESS" shift="16" mask="00FF0000" desc="PWM_VALUE_OFFSET = TONE_LOUDNESS * 128">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TONE_DURATION" shift="24" mask="FF000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="[10ms]" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_LED_CONF#" name="LED_CONF" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="LED_BLUE" shift="0" mask="000000FF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="LED_GREEN" shift="8" mask="0000FF00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="LED_RED" shift="16" mask="00FF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="LED_FREQ" shift="24" mask="0F000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="15" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//==================== sensorless settings ====================

// \xml <tmc:value_register address="#TMC6630_SINCOMM_AMPLITUDE_PHI#" name="SINCOMM_AMPLITUDE_PHI" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SINCOMM_PHI" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SINCOMM_AMPLITUDE" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_SINCOMM_SIN_COS#" name="SINCOMM_SIN_COS" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SINCOMM_COS" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SINCOMM_SIN" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_SINCOMM_SCALED_U_V_W#" name="SINCOMM_SCALED_U_V_W" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SINCOMM_SCALED_W" shift="0" mask="000003FF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SINCOMM_SCALED_V" shift="10" mask="000FFC00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SINCOMM_SCALED_U" shift="20" mask="3FF00000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_SINCOMM_DIRECT_U_V_W#" name="SINCOMM_DIRECT_U_V_W" size="32" group="#GROUP_PWM_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SINCOMM_DIRECT_W" shift="0" mask="000003FF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SINCOMM_DIRECT_V" shift="10" mask="000FFC00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="SINCOMM_DIRECT_U" shift="20" mask="3FF00000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_CROSSING_OPTS#" name="CROSSING_OPTS" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>

// \xml       <tmc:value_register_field name="USE_HALL_DUR_TARGET" shift="0" mask="00000001" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="CNT_ONLY_FLOAT" shift="1" mask="00000002" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="true" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="DIR_PROTECT" shift="2" mask="00000004" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="true" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DISABLE_FLOAT_TREND_FOR_WRONG_HALL" shift="3" mask="00000008" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="USE_EXT_COMP_COMMU0_EVAL" shift="4" mask="00000030" desc="">
// \xml          <tmc:value_choice default="2" unit="" access="RW">
// \xml            <choice_element value="0" desc="CompEval"></choice_element>
// \xml            <choice_element value="1" desc="CompEval with ChopOn"></choice_element>
// \xml            <choice_element value="2" desc="CompEval with ChopOn and considering BBM"></choice_element>
// \xml            <choice_element value="3" desc="CompEval with delayed ChopOn"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="USE_EXT_COMP_COMMU1_EVAL" shift="6" mask="000000C0" desc="">
// \xml          <tmc:value_choice default="2" unit="" access="RW">
// \xml            <choice_element value="0" desc="CompEval"></choice_element>
// \xml            <choice_element value="1" desc="CompEval with ChopOn"></choice_element>
// \xml            <choice_element value="2" desc="CompEval with ChopOn and considering BBM"></choice_element>
// \xml            <choice_element value="3" desc="CompEval with delayed ChopOn"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STALL_PREVENT_EN" shift="8" mask="00000100" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="true" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STALL_CNT_ONLY_FLOAT" shift="9" mask="00000200" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STALL_BLK_LIMIT" shift="10" mask="00000C00" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="BLK_INTEGRAL   > INTEGRAL(A+B)"></choice_element>
// \xml            <choice_element value="1" desc="BLK_INTEGRAL/2 > INTEGRAL(A+B)"></choice_element>
// \xml            <choice_element value="2" desc="BLK_INTEGRAL/4 > INTEGRAL(A+B)"></choice_element>
// \xml            <choice_element value="3" desc="BLK_INTEGRAL/8 > INTEGRAL(A+B)"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="HALL_DURATION_FILT_LENGTH" shift="16" mask="00FF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="2" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_HALL_DUR_EXT#" name="HALL_DUR_EXT" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_DUR_EXT" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_CROSSING_CNTS_MIN#" name="CROSSING_CNTS_MIN" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CROSSING_CNTS_MIN" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_CROSSING_CNTS_MAX#" name="CROSSING_CNTS_MAX" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CROSSING_CNTS_MAX" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="2097152" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_HALL_NEXT_HALL_ACTUAL_CROSSING#" name="HALL_NEXT_HALL_ACTUAL_CROSSING" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CROSSING_VALUE" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_ACTUAL" shift="16" mask="00FF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_NEXT" shift="24" mask="FF000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_CROSSING_FILT#" name="CROSSING_FILT" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CROSSING_FILT" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_CROSSING_SIGNAL_COUNT#" name="CROSSING_SIGNAL_COUNT" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CROSSING_COUNT" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="CROSSING_SIGNAL" shift="24" mask="FF000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_HALL_DUR_P_I#" name="HALL_DUR_P_I" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_DUR_I" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_DUR_P" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_HALL_DURATION#" name="HALL_DURATION" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_DURATION" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_HALL_DURATION_PI#" name="HALL_DURATION_PI" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_DURATION_PI" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_HALL_DURATION_FLT#" name="HALL_DURATION_FLT" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_DURATION_FLT" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//==================== ??? modes ====================

// \xml <tmc:value_register address="#TMC6630_VELOCITY_PID_OPTS#" name="VELOCITY_PID_OPTS" size="32" group="#GROUP_OPERATION_MODES#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="USE_TORQUE_LIMIT_DDT" shift="0" mask="00000001" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="USE_VELOCITY_LIMIT_DDT" shift="1" mask="00000002" desc="">
// \xml          <tmc:value_bool desc_false="disabled" desc_true="enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TORQUE_START_MODE" shift="2" mask="0000000C" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="Torque_I = 1, Torque_Target=StartValue"></choice_element>
// \xml            <choice_element value="1" desc="Torque_DDT = 1, Torque_Target=StartValue"></choice_element>
// \xml            <choice_element value="2" desc="PWM_DDT on"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TORQUE_TRIGGER_CNT" shift="8" mask="0000FF00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="VELOCITY_TRIGGER_CNT" shift="16" mask="00FF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="VELOCITY_FILT_LENGTH" shift="24" mask="FF000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//==================== Torque mode ====================

// \xml <tmc:value_register address="#TMC6630_TORQUE_P_I#" name="TORQUE_P_I" size="32" group="#GROUP_TORQUE_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="TORQUE_I" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TORQUE_P" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_TORQUE_MAX_MIN#" name="TORQUE_MAX_MIN" size="32" group="#GROUP_TORQUE_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="TORQUE_MIN" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TORQUE_MAX" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_TORQUE_TARGET_LIMIT_DDT#" name="TORQUE_TARGET_LIMIT_DDT" size="32" group="#GROUP_TORQUE_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="TORQUE_LIMIT_DDT" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TORQUE_TARGET" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_TORQUE_ERROR_PWM_VALUE#" name="TORQUE_ERROR_PWM_VALUE" size="32" group="#GROUP_TORQUE_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="TORQUE_PWM_VALUE" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TORQUE_ERROR" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_TORQUE_ERROR_SUM#" name="TORQUE_ERROR_SUM" size="32" group="#GROUP_TORQUE_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="TORQUE_ERROR_SUM" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//==================== VELOCITY mode ====================

// \xml <tmc:value_register address="#TMC6630_VELOCITY_P_I#" name="VELOCITY_P_I" size="32" group="#GROUP_VELOCITY_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_I" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="VELOCITY_P" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_VELOCITY_MAX#" name="VELOCITY_MAX" size="32" group="#GROUP_VELOCITY_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_MAX" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s24_MIN#" max="#s24_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_VELOCITY_MIN#" name="VELOCITY_MIN" size="32" group="#GROUP_VELOCITY_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_MIN" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s24_MIN#" max="#s24_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_VELOCITY_LIMIT_DDT#" name="VELOCITY_LIMIT_DDT" size="32" group="#GROUP_VELOCITY_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_LIMIT_DDT" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_VELOCITY_TARGET#" name="VELOCITY_TARGET" size="32" group="#GROUP_VELOCITY_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_TARGET" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s24_MIN#" max="#s24_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_VELOCITY_ACTUAL#" name="VELOCITY_ACTUAL" size="32" group="#GROUP_VELOCITY_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_ACTUAL" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s24_MIN#" max="#s24_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_VELOCITY_ERROR#" name="VELOCITY_ERROR" size="32" group="#GROUP_VELOCITY_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_ERROR" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s24_MIN#" max="#s24_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_VELOCITY_ERROR_SUM#" name="VELOCITY_ERROR_SUM" size="32" group="#GROUP_VELOCITY_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_ERROR_SUM" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_VELOCITY_TORQUE_TARGET#" name="VELOCITY_TORQUE_TARGET" size="32" group="#GROUP_VELOCITY_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_TORQUE_TARGET" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s24_MIN#" max="#s24_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//==================== position mode ====================

// \xml <tmc:value_register address="#TMC6630_TORQUE_TARGET_LIMIT_DDT_OUT#" name="TORQUE_TARGET_LIMIT_DDT_OUT" size="32" group="#GROUP_POSITION_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="TORQUE_TARGET_LIMIT_DDT_OUT" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_VELOCITY_TARGET_LIMIT_DDT_OUT#" name="VELOCITY_TARGET_LIMIT_DDT_OUT" size="32" group="#GROUP_POSITION_MODE#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_TARGET_LIMIT_DDT_OUT" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s24_MIN#" max="#s24_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//==================== PWM input ====================

// \xml <tmc:value_register address="#TMC6630_PWM_CNTL_FILTER_MAXCNT_LENGTH#" name="PWM_CNTL_FILTER_MAXCNT_LENGTH" size="32" group="#GROUP_PWM_INPUT#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_CNTL_FILTER_LENGTH" shift="0" mask="000000FF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_CNTL_FILTER_MAXCNT" shift="8" mask="FFFFFF00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_CNTL_LIMIT_MAX_SHORT_CNT#" name="PWM_CNTL_LIMIT_MAX_SHORT_CNT" size="32" group="#GROUP_PWM_INPUT#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_CNTL_MAX_SHORT_CNT" shift="0" mask="000FFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u20_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_CNTL_LIMIT" shift="20" mask="FFF00000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u12_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_CNTL_DUTY_MAX_MIN#" name="PWM_CNTL_DUTY_MAX_MIN" size="32" group="#GROUP_PWM_INPUT#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_CNTL_DUTY_MIN" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_CNTL_DUTY_MAX" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_PWM_CNTL_DUTY_FILTERED_CALC#" name="PWM_CNTL_DUTY_FILTERED_CALC" size="32" group="#GROUP_PWM_INPUT#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_CNTL_DUTY_FILTERED" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_UART_BPS#" name="UART_BPS" size="32" group="#GROUP_PWM_INPUT#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="UART_BPS" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="115200" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_TEST_VECTOR#" name="TEST_VECTOR" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="TEST_VECTOR[0]" shift="0" mask="00000001" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEST_VECTOR[1]" shift="1" mask="00000002" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEST_VECTOR[2]" shift="2" mask="00000004" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEST_VECTOR[3]" shift="3" mask="00000008" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEST_VECTOR[4]" shift="4" mask="00000010" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEST_VECTOR[5]" shift="5" mask="00000020" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEST_VECTOR[6]" shift="6" mask="00000040" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="TEST_VECTOR[7]" shift="7" mask="00000080" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_HIGH_FLOAT_LOW#" name="HIGH_FLOAT_LOW" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="LOW" shift="0" mask="000003FF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="FLOAT" shift="10" mask="000FFC00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HIGH" shift="20" mask="3FF00000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_INTEGRAL_ACTUAL#" name="INTEGRAL_ACTUAL" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="INTEGRAL_ACTUAL" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s24_MIN#" max="#s24_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_INTEGRAL_LAST#" name="INTEGRAL_LAST" size="32" group="#GROUP_SENSORLESS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="INTEGRAL_LAST" shift="0" mask="00FFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s24_MIN#" max="#s24_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_CNT01_INTEGRAL_LAST#" name="CNT01_INTEGRAL_LAST" size="32" group="#GROUP_INTEGRATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CNT01_INTEGRAL_LAST" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_CNT01_INTEGRAL#" name="CNT01_INTEGRAL" size="32" group="#GROUP_INTEGRATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CNT01_INTEGRAL" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC6630_ORDER#" name="ORDER" size="32" group="#GROUP_OPERATION_MODES#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ORDER" shift="0" mask="00FFFFFF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="No order"></choice_element>
// \xml            <choice_element value="5395284" desc="0x525354 = RST (Event)"></choice_element>
// \xml            <choice_element value="5461060" desc="0x535444 = STDby (STATE)"></choice_element>
// \xml            <choice_element value="5198928" desc="0x4F5450 = OTP (STATE)"></choice_element>
// \xml            <choice_element value="4477526" desc="0x445256 = DRV off (STATE)"></choice_element>
// \xml            <choice_element value="4409419" desc="0x43484B = CHecK (STATE)"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml </tmc:register_set>
// \xml </tmc:product_ic>
