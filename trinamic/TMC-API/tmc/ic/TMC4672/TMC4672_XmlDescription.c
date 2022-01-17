
// ===== used for xml file generation =====

// \xml <?xml version="1.0" encoding="UTF-8" standalone="no"?>
// \xml <tmc:product_ic name="TMC4672" version="1.0" author="ED" xmlns:tmc="http://www.trinamic.com" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="https://www.trinamic.com https://www.trinamic.com/fileadmin/xml/TMC_Schema.xsd">
// \xml <tmc:register_set for="TMC4672" name="All Registers">

// \xml <tmc:group name="Status information"       id="#GROUP_STATUS_INFORMATION#"></tmc:group>
// \xml <tmc:group name="General settings"         id="#GROUP_GENERAL_SETTINGS#"></tmc:group>
// \xml <tmc:group name="ADCs" 					   id="#GROUP_ADCS#"></tmc:group>
// \xml <tmc:group name="Inputs/Outputs"           id="#GROUP_IO#"></tmc:group>
// \xml <tmc:group name="PWM"                      id="#GROUP_PWM#"></tmc:group>
// \xml <tmc:group name="Decoder ABN"              id="#GROUP_DECODER_ABN#"></tmc:group>
// \xml <tmc:group name="Hall digital"             id="#GROUP_HALL_DIGITAL#"></tmc:group>
// \xml <tmc:group name="Decoder analog"           id="#GROUP_DECODER_ANALOG#"></tmc:group>
// \xml <tmc:group name="PID regulators"           id="#GROUP_PID_REGULATORS#"></tmc:group>

// \xml <tmc:value_register address="#TMC4672_CHIPINFO_DATA#" name="CHIPINFO_DATA" size="32" group="#GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="Variant 0">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_TYPE" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_ascii desc="Hardware type (ASCII)." access="R"></tmc:value_ascii>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="0" range_to="0"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 1">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_VERSION" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_version desc="Hardware version (u16.u16)." access="R"></tmc:value_version>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="1" range_to="1"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 2">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_DATE" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_date desc="Hardware date (nibble wise date stamp yyyymmdd)." access="R"></tmc:value_date>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="2" range_to="2"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 3">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_TIME" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_time desc="Hardware time (nibble wise time stamp --hhmmss)" access="R"></tmc:value_time>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="3" range_to="3"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 4">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_VARIANT" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="4" range_to="4"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 5">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="SI_BUILD" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CHIPINFO_ADDR#" shift="0" mask="FFFFFFFF" range_from="5" range_to="5"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_CHIPINFO_ADDR#" name="CHIPINFO_ADDR" size="32"  group="#GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Chip info address</desc>
// \xml       <tmc:value_register_field name="CHIP_INFO_ADDRESS" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="SI_TYPE"></choice_element>
// \xml            <choice_element value="1" desc="SI_VERSION"></choice_element>
// \xml            <choice_element value="2" desc="SI_DATE"></choice_element>
// \xml            <choice_element value="3" desc="SI_TIME"></choice_element>
// \xml            <choice_element value="4" desc="SI_VARIANT"></choice_element>
// \xml            <choice_element value="5" desc="SI_BUILD"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacts address="#TMC4672_CHIPINFO_DATA#"></tmc:register_variant_impacts>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ADC_RAW_DATA#" name="ADC_RAW_DATA" size="32" group="#GROUP_ADCS#">

// \xml    <tmc:register_variant name="Variant 0">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_I0_RAW:" shift="0" mask="0000FFFF" desc="Raw phase current I0">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_I1_RAW" shift="16" mask="FFFF0000" desc="Raw phase current I1">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_ADC_RAW_ADDR#" shift="0" mask="FFFFFFFF" range_from="0" range_to="0"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 1">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_VM_RAW" shift="0" mask="0000FFFF" desc="aw supply voltage value.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_AGPI_A_RAW" shift="16" mask="FFFF0000" desc="Raw analog gpi A value.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_ADC_RAW_ADDR#" shift="0" mask="FFFFFFFF" range_from="1" range_to="1"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 2">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_AGPI_B_RAW" shift="0" mask="0000FFFF" desc="Raw analog gpi B value.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_AENC_UX_RAW" shift="16" mask="FFFF0000" desc="Raw analog encoder signal.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_ADC_RAW_ADDR#" shift="0" mask="FFFFFFFF" range_from="2" range_to="2"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 3">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_AENC_VN_RAW" shift="0" mask="0000FFFF" desc="Raw analog encoder signal.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_AENC_WY_RAW" shift="16" mask="FFFF0000" desc="Raw analog encoder signal.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="R"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_ADC_RAW_ADDR#" shift="0" mask="FFFFFFFF" range_from="3" range_to="3"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ADC_RAW_ADDR#" name="ADC_RAW_ADDR" size="32"  group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>ADC raw data address</desc>
// \xml       <tmc:value_register_field name="ADC_RAW_ADDR" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="ADC_I1_RAW \x26 ADC_I0_RAW"></choice_element>
// \xml            <choice_element value="1" desc="ADC_AGPI_A_RAW \x26 ADC_VM_RAW"></choice_element>
// \xml            <choice_element value="2" desc="ADC_AENC_UX_RAW \x26 ADC_AGPI_B_RAW"></choice_element>
// \xml            <choice_element value="3" desc="ADC_AENC_WY_RAW \x26 ADC_AENC_VN_RAW"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacts address="#TMC4672_ADC_RAW_DATA#"></tmc:register_variant_impacts>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_dsADC_MCFG_B_MCFG_A#" name="dsADC_MCFG_B_MCFG_A" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="cfg_dsmodulator_a" shift="0" mask="00000003" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="int. dsMOD"></choice_element>
// \xml            <choice_element value="1" desc="ext. dsMOD with MCLK input"></choice_element>
// \xml            <choice_element value="2" desc="ext. dsMOD with MCLK output"></choice_element>
// \xml            <choice_element value="3" desc="ext. dsMOD with ext. CMP"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="mclk_polarity_a" shift="2" mask="00000004" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="mdat_polarity_a" shift="3" mask="00000008" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="sel_nclk_mclk_i_a" shift="4" mask="00000010" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="blanking_a" shift="8" mask="000000FF00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="cfg_dsmodulator_b" shift="16" mask="00030000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="int. dsMOD"></choice_element>
// \xml            <choice_element value="1" desc="ext. dsMOD with MCLK input"></choice_element>
// \xml            <choice_element value="2" desc="ext. dsMOD with MCLK output"></choice_element>
// \xml            <choice_element value="3" desc="ext. dsMOD with ext. CMP"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="mclk_polarity_b" shift="18" mask="00040000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="mdat_polarity_b" shift="19" mask="00080000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="sel_nclk_mclk_i_b" shift="20" mask="00100000" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="blanking_b" shift="24" mask="FF000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_dsADC_MCLK_A#" name="dsADC_MCLK_A" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>dsADC group A MCLK constant for frequency adjustmend.</desc>
// \xml       <tmc:value_register_field name="dsADC_MCLK_A" shift="0" mask="FFFFFFFF" desc="fMCLK_A = 2^31 / (fCLK * (dsADC_MCLK_A+1)), dsADC_MCLK_A = (2^31 / (fMCLK * fCLK)) - 1">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="214748365" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_dsADC_MCLK_B#" name="dsADC_MCLK_B" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>dsADC group B MCLK constant for frequency adjustmend.</desc>
// \xml       <tmc:value_register_field name="dsADC_MCLK_B" shift="0" mask="FFFFFFFF" desc="fMCLK_B = 2^31 / (fCLK * (dsADC_MCLK_B+1)), dsADC_MCLK_B = (2^31 / (fMCLK * fCLK)) - 1">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="214748365" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_dsADC_MDEC_B_MDEC_A#" name="dsADC_MDEC_B_MDEC_A" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Decimation configuration register.</desc>
// \xml       <tmc:value_register_field name="dsADC_MDEC_A" shift="0" mask="0000FFFF" desc="0: PWM synchron, others according to register content">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="256" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="dsADC_MDEC_B" shift="16" mask="FFFF0000" desc="0: PWM synchron, others according to register content">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="256" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ADC_I1_SCALE_OFFSET#" name="ADC_I1_SCALE_OFFSET" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_I1_OFFSET" shift="0" mask="0000FFFF" desc="Offset for current ADC channel 1.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_I1_SCALE" shift="16" mask="FFFF0000" desc="Scaling factor for current ADC channel 1.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="256" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ADC_I0_SCALE_OFFSET#" name="ADC_I0_SCALE_OFFSET" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_I0_OFFSET" shift="0" mask="0000FFFF" desc="Offset for current ADC channel 0.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_I0_SCALE" shift="16" mask="FFFF0000" desc="Scaling factor for current ADC channel 0.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="256" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ADC_I_SELECT#" name="ADC_I_SELECT" size="32"  group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_I0_SELECT" shift="0" mask="000000FF" desc="Select input for raw current ADC_I0_RAW.">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="ADCSD_I0_RAW (sigma delta ADC)"></choice_element>
// \xml            <choice_element value="1" desc="ADCSD_I1_RAW (sigma delta ADC)"></choice_element>
// \xml            <choice_element value="2" desc="ADC_I0_EXT (from register)"></choice_element>
// \xml            <choice_element value="3" desc="ADC_I1_EXT (from register)"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_I1_SELECT" shift="8" mask="0000FF00" desc="Select input for raw current ADC_I1_RAW.">
// \xml          <tmc:value_choice default="1" unit="" access="RW">
// \xml            <choice_element value="0" desc="ADCSD_I0_RAW (sigma delta ADC)"></choice_element>
// \xml            <choice_element value="1" desc="ADCSD_I1_RAW (sigma delta ADC)"></choice_element>
// \xml            <choice_element value="2" desc="ADC_I0_EXT (from register)"></choice_element>
// \xml            <choice_element value="3" desc="ADC_I1_EXT (from register)"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
//\xml       <tmc:value_register_field name="reserved" shift="16" mask="00FF0000" desc="">
//\xml          <tmc:value_choice default="0" unit="" access="RW">
//\xml            <choice_element value="0" desc="reserved"></choice_element>
//\xml          </tmc:value_choice>
//\xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_I_UX_SELECT" shift="24" mask="03000000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="UX = ADC_I0 (default)"></choice_element>
// \xml            <choice_element value="1" desc="UX = ADC_I1"></choice_element>
// \xml            <choice_element value="2" desc="UX = ADC_I2"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="ADC_I_V_SELECT" shift="26" mask="0C000000" desc="">
// \xml          <tmc:value_choice default="1" unit="" access="RW">
// \xml            <choice_element value="0" desc="V = ADC_I0"></choice_element>
// \xml            <choice_element value="1" desc="V = ADC_I1 (default)"></choice_element>
// \xml            <choice_element value="2" desc="V = ADC_I2"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="ADC_I_WY_SELECT" shift="28" mask="30000000" desc="">
// \xml          <tmc:value_choice default="2" unit="" access="RW">
// \xml            <choice_element value="0" desc="WY = ADC_I0"></choice_element>
// \xml            <choice_element value="1" desc="WY = ADC_I1"></choice_element>
// \xml            <choice_element value="2" desc="WY = ADC_I2 (default)"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ADC_I1_I0_EXT#" name="ADC_I1_I0_EXT" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_I0_EXT" shift="0" mask="0000FFFF" desc="Register for write of ADC_I0 value from external source (eg. CPU).">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_I1_EXT" shift="16" mask="FFFF0000" desc="Register for write of ADC_I1 value from external source (eg. CPU).">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_DS_ANALOG_INPUT_STAGE_CFG#" name="DS_ANALOG_INPUT_STAGE_CFG" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_I0" shift="0" mask="0000000F" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="INP vs. INN"></choice_element>
// \xml            <choice_element value="1" desc="VDD/4"></choice_element>
// \xml            <choice_element value="2" desc="GND vs. INN"></choice_element>
// \xml            <choice_element value="3" desc="3*VDD/4"></choice_element>
// \xml            <choice_element value="4" desc="INP vs. GND"></choice_element>
// \xml            <choice_element value="5" desc="VDD/4"></choice_element>
// \xml            <choice_element value="6" desc="VDD/2"></choice_element>
// \xml            <choice_element value="7" desc="3*VDD/4"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_I1" shift="4" mask="000000F0" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="INP vs. INN"></choice_element>
// \xml            <choice_element value="1" desc="VDD/4"></choice_element>
// \xml            <choice_element value="2" desc="GND vs. INN"></choice_element>
// \xml            <choice_element value="3" desc="3*VDD/4"></choice_element>
// \xml            <choice_element value="4" desc="INP vs. GND"></choice_element>
// \xml            <choice_element value="5" desc="VDD/4"></choice_element>
// \xml            <choice_element value="6" desc="VDD/2"></choice_element>
// \xml            <choice_element value="7" desc="3*VDD/4"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_VW" shift="8" mask="00000F00" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="INP vs. INN"></choice_element>
// \xml            <choice_element value="1" desc="VDD/4"></choice_element>
// \xml            <choice_element value="2" desc="GND vs. INN"></choice_element>
// \xml            <choice_element value="3" desc="3*VDD/4"></choice_element>
// \xml            <choice_element value="4" desc="INP vs. GND"></choice_element>
// \xml            <choice_element value="5" desc="VDD/4"></choice_element>
// \xml            <choice_element value="6" desc="VDD/2"></choice_element>
// \xml            <choice_element value="7" desc="3*VDD/4"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_AGPI_A" shift="12" mask="0000F000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="INP vs. INN"></choice_element>
// \xml            <choice_element value="1" desc="VDD/4"></choice_element>
// \xml            <choice_element value="2" desc="GND vs. INN"></choice_element>
// \xml            <choice_element value="3" desc="3*VDD/4"></choice_element>
// \xml            <choice_element value="4" desc="INP vs. GND"></choice_element>
// \xml            <choice_element value="5" desc="VDD/4"></choice_element>
// \xml            <choice_element value="6" desc="VDD/2"></choice_element>
// \xml            <choice_element value="7" desc="3*VDD/4"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_AGPI_B" shift="16" mask="000F0000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="INP vs. INN"></choice_element>
// \xml            <choice_element value="1" desc="VDD/4"></choice_element>
// \xml            <choice_element value="2" desc="GND vs. INN"></choice_element>
// \xml            <choice_element value="3" desc="3*VDD/4"></choice_element>
// \xml            <choice_element value="4" desc="INP vs. GND"></choice_element>
// \xml            <choice_element value="5" desc="VDD/4"></choice_element>
// \xml            <choice_element value="6" desc="VDD/2"></choice_element>
// \xml            <choice_element value="7" desc="3*VDD/4"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_AENC_UX" shift="20" mask="00F00000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="INP vs. INN"></choice_element>
// \xml            <choice_element value="1" desc="VDD/4"></choice_element>
// \xml            <choice_element value="2" desc="GND vs. INN"></choice_element>
// \xml            <choice_element value="3" desc="3*VDD/4"></choice_element>
// \xml            <choice_element value="4" desc="INP vs. GND"></choice_element>
// \xml            <choice_element value="5" desc="VDD/4"></choice_element>
// \xml            <choice_element value="6" desc="VDD/2"></choice_element>
// \xml            <choice_element value="7" desc="3*VDD/4"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_AENC_VN" shift="24" mask="0F000000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="INP vs. INN"></choice_element>
// \xml            <choice_element value="1" desc="VDD/4"></choice_element>
// \xml            <choice_element value="2" desc="GND vs. INN"></choice_element>
// \xml            <choice_element value="3" desc="3*VDD/4"></choice_element>
// \xml            <choice_element value="4" desc="INP vs. GND"></choice_element>
// \xml            <choice_element value="5" desc="VDD/4"></choice_element>
// \xml            <choice_element value="6" desc="VDD/2"></choice_element>
// \xml            <choice_element value="7" desc="3*VDD/4"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_AENC_WY" shift="28" mask="F0000000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="INP vs. INN"></choice_element>
// \xml            <choice_element value="1" desc="VDD/4"></choice_element>
// \xml            <choice_element value="2" desc="GND vs. INN"></choice_element>
// \xml            <choice_element value="3" desc="3*VDD/4"></choice_element>
// \xml            <choice_element value="4" desc="INP vs. GND"></choice_element>
// \xml            <choice_element value="5" desc="VDD/4"></choice_element>
// \xml            <choice_element value="6" desc="VDD/2"></choice_element>
// \xml            <choice_element value="7" desc="3*VDD/4"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_0_SCALE_OFFSET#" name="AENC_0_SCALE_OFFSET" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_0_OFFSET" shift="0" mask="0000FFFF" desc="Offset for Analog Encoder ADC channel 0.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AENC_0_SCALE" shift="16" mask="FFFF0000" desc="Scaling factor for Analog Encoder ADC channel 0.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="256" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_1_SCALE_OFFSET#" name="AENC_1_SCALE_OFFSET" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_1_OFFSET" shift="0" mask="0000FFFF" desc="Offset for Analog Encoder ADC channel 1.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AENC_1_SCALE" shift="16" mask="FFFF0000" desc="Scaling factor for Analog Encoder ADC channel 1.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="256" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_2_SCALE_OFFSET#" name="AENC_2_SCALE_OFFSET" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_2_OFFSET" shift="0" mask="0000FFFF" desc="Offset for Analog Encoder ADC channel 2.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AENC_2_SCALE" shift="16" mask="FFFF0000" desc="Scaling factor for Analog Encoder ADC channel 2.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="256" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_SELECT#" name="AENC_SELECT" size="32"  group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_0_SELECT" shift="0" mask="000000FF" desc="Select analog encoder ADC channel for raw analog encoder signal AENC_0_RAW.">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="AENC_UX_RAW (default)"></choice_element>
// \xml            <choice_element value="1" desc="AENC_VN_RAW"></choice_element>
// \xml            <choice_element value="2" desc="AENC_WY_RAW"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AENC_1_SELECT" shift="8" mask="0000FF00" desc="Select analog encoder ADC channel for raw analog encoder signal AENC_1_RAW.">
// \xml          <tmc:value_choice default="1" unit="" access="RW">
// \xml            <choice_element value="0" desc="AENC_UX_RAW"></choice_element>
// \xml            <choice_element value="1" desc="AENC_VN_RAW (default)"></choice_element>
// \xml            <choice_element value="2" desc="AENC_WY_RAW"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AENC_2_SELECT" shift="16" mask="00FF0000" desc="Select analog encoder ADC channel for raw analog encoder signal AENC_2_RAW.">
// \xml          <tmc:value_choice default="2" unit="" access="RW">
// \xml            <choice_element value="0" desc="AENC_UX_RAW"></choice_element>
// \xml            <choice_element value="1" desc="AENC_VN_RAW"></choice_element>
// \xml            <choice_element value="2" desc="AENC_WY_RAW (default)"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ADC_IWY_IUX#" name="ADC_IWY_IUX" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_IUX" shift="0" mask="0000FFFF" desc="Register of scaled current ADC value including signed added offset as input for the FOC.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_IWY" shift="16" mask="FFFF0000" desc="Register of scaled current ADC value including signed added offset as input for the FOC.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ADC_IV#" name="ADC_IV" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_IV" shift="0" mask="0000FFFF" desc="Register of scaled current ADC value including signed added offset as input for the FOC.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_WY_UX#" name="AENC_WY_UX" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_UX" shift="0" mask="0000FFFF" desc="Register of scaled analog encoder value including signed added offset as input for the interpolator.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AENC_WY" shift="16" mask="FFFF0000" desc="Register of scaled analog encoder value including signed added offset as input for the interpolator.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_VN#" name="AENC_VN" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_VN" shift="0" mask="0000FFFF" desc="Register of scaled analog encoder value including signed added offset as input for the interpolator.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PWM_POLARITIES#" name="PWM_POLARITIES" size="32" group="#GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_POLARITIES[0]" shift="0" mask="00000001" desc="polarity of Low Side (LS) gate control signal">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_POLARITIES[1]" shift="1" mask="00000002" desc="polarity of High Side (HS) gate control signal">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_POLARITIES[2]" shift="2" mask="00000004" desc="pulse AB polarity">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_POLARITIES[3]" shift="3" mask="00000008" desc="pulse B polarity">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_POLARITIES[4]" shift="4" mask="00000010" desc="pulse C center polarity">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_POLARITIES[5]" shift="5" mask="00000020" desc="pulse A polarity">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_POLARITIES[6]" shift="6" mask="00000040" desc="pulse zero Z pulse polarity">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_POLARITIES[7]" shift="7" mask="00000080" desc="over current signal polarity">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PWM_MAXCNT#" name="PWM_MAXCNT" size="32" group="#GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_MAXCNT" shift="0" mask="0000FFFF" desc="PWM maximum (count-1), PWM frequency is fPWM[Hz] = 100MHz/(PWM_MAXCNT+1)">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="3999" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PWM_BBM_H_BBM_L#" name="PWM_BBM_H_BBM_L" size="32" group="#GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_BBM_L" shift="0" mask="000000FF" desc="Break Before Make time tBBM_L[10ns] for low side MOS-FET gate control">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="20" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_BBM_H" shift="8" mask="0000FF00" desc="Break Before Make time tBBM_H[10ns] for high side MOS-FET gate control">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="20" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PWM_SV_CHOP#" name="PWM_SV_CHOP" size="32" group="#GROUP_PWM#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_CHOP" shift="0" mask="000000FF" desc="PWM chopper mode, defining how to chopper">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="PWM = OFF, free running"></choice_element>
// \xml            <choice_element value="1" desc="PWM = OFF, Low Side (LS) permanent = ON"></choice_element>
// \xml            <choice_element value="2" desc="PWM = OFF, High Side (HS) permanent = ON"></choice_element>
// \xml            <choice_element value="3" desc="PWM off, free running"></choice_element>
// \xml            <choice_element value="4" desc="PWM off, free running"></choice_element>
// \xml            <choice_element value="5" desc="PWM low side (LS) chopper only, high side (HS) off; not suitable for FOC"></choice_element>
// \xml            <choice_element value="6" desc="PWM high side (HS) chopper only, low side (LS) off; not suitable for FOC"></choice_element>
// \xml            <choice_element value="7" desc="centered PWM for FOC"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_SV" shift="8" mask="00000100" desc="use Space Vector PWM">
// \xml         <tmc:value_bool desc_false="Space Vector PWM disabled" desc_true="Space Vector PWM enabled" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_MOTOR_TYPE_N_POLE_PAIRS#" name="MOTOR_TYPE_N_POLE_PAIRS" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="N_POLE_PAIRS" shift="0" mask="0000FFFF" desc="Number n of pole pairs of the motor for calcualtion phi_e = phi_m / N_POLE_PAIRS.">
// \xml    	     <tmc:value_unsigned min="1" max="#u16_MAX#" default="1" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="MOTOR_TYPE" shift="16" mask="00FF0000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="No motor"></choice_element>
// \xml            <choice_element value="1" desc="Single phase DC motor"></choice_element>
// \xml            <choice_element value="2" desc="Two phase Stepper motor"></choice_element>
// \xml            <choice_element value="3" desc="Three phase BLDC motor"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PHI_E_EXT#" name="PHI_E_EXT" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PHI_E_EXT" shift="0" mask="0000FFFF" desc="Electrical angle phi_e_ext for external writing into this register.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PHI_M_EXT#" name="PHI_M_EXT" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PHI_M_EXT" shift="0" mask="0000FFFF" desc="Mechanical angle phi_m_ext for external writing into this register.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_POSITION_EXT#" name="POSITION_EXT" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="POSITION_EXT" shift="0" mask="FFFFFFFF" desc="Mechanical (multi turn) position for external writing into this register.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_OPENLOOP_MODE#" name="OPENLOOP_MODE" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Control bits how to handle open loop phi.</desc>
// \xml       <tmc:value_register_field name="OPENLOOP_PHI_DIRECTION" shift="12" mask="00001000" desc="Open loop phi direction.">
// \xml         <tmc:value_bool desc_false="positive" desc_true="negative" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_OPENLOOP_ACCELERATION#" name="OPENLOOP_ACCELERATION" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="OPENLOOP_ACCELERATION" shift="0" mask="FFFFFFFF" desc="Acceleration of open loop phi.">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_OPENLOOP_VELOCITY_TARGET#" name="OPENLOOP_VELOCITY_TARGET" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="OPENLOOP_VELOCITY_TARGET" shift="0" mask="FFFFFFFF" desc="Target velocity of open loop phi.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_OPENLOOP_VELOCITY_ACTUAL#" name="OPENLOOP_VELOCITY_ACTUAL" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="OPENLOOP_VELOCITY_ACTUAL" shift="0" mask="FFFFFFFF" desc="Actual velocity of open loop generator.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_OPENLOOP_PHI#" name="OPENLOOP_PHI" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="OPENLOOP_PHI" shift="0" mask="0000FFFF" desc="Angle phi open loop (either mapped to electrical angel phi_e or mechanical angle phi_m).">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RWI"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_UQ_UD_EXT#" name="UQ_UD_EXT" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="UD_EXT" shift="0" mask="0000FFFF" desc="External writable parameter for open loop voltage control mode, usefull during system setup,  U_D component.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="UQ_EXT" shift="16" mask="FFFF0000" desc="External writable parameter for open loop voltage control mode, usefull during system setup,  U_Q component.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_DECODER_MODE#" name="ABN_DECODER_MODE" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Control bits how to handle ABN decoder signals.</desc>
// \xml       <tmc:value_register_field name="apol" shift="0" mask="00000001" desc="Polarity of A pulse.">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="bpol" shift="1" mask="00000002" desc="Polarity of B pulse.">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="npol" shift="2" mask="00000004" desc="Polarity of N pulse.">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="use_abn_as_n" shift="3" mask="00000008" desc="0: Ignore A and B polarity with Npulse = N, 1 : Npulse = N and A and B">
// \xml         <tmc:value_bool desc_false="Ignore A and B polarity with Npulse = N" desc_true="Npulse = N and A and B" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="cln" shift="8" mask="00000100" desc="Clear writes ABN_DECODER_COUNT_N into decoder count at Npulse.">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="direction" shift="12" mask="00001000" desc="Decoder count  direction.">
// \xml         <tmc:value_bool desc_false="positive" desc_true="negative" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_DECODER_PPR#" name="ABN_DECODER_PPR" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ABN_DECODER_PPR" shift="0" mask="00FFFFFF" desc="Decoder pules per mechanical revolution.">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="65536" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_DECODER_COUNT#" name="ABN_DECODER_COUNT" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ABN_DECODER_COUNT" shift="0" mask="00FFFFFF" desc="Raw decoder count; the digital decoder engine counts modulo (decoder_ppr).">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_DECODER_COUNT_N#" name="ABN_DECODER_COUNT_N" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ABN_DECODER_COUNT_N" shift="0" mask="00FFFFFF" desc="Decoder count latched on N pulse, when N pulse clears decoder_count also decoder_count_n is 0.">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_DECODER_PHI_E_PHI_M_OFFSET#" name="ABN_DECODER_PHI_E_PHI_M_OFFSET" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ABN_DECODER_PHI_M_OFFSET" shift="0" mask="0000FFFF" desc="ABN_DECODER_PHI_M_OFFSET to shift (rotate) angle DECODER_PHI_M.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ABN_DECODER_PHI_E_OFFSET" shift="16" mask="FFFF0000" desc="ABN_DECODER_PHI_E_OFFSET to shift (rotate) angle DECODER_PHI_E.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_DECODER_PHI_E_PHI_M#" name="ABN_DECODER_PHI_E_PHI_M" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ABN_DECODER_PHI_M" shift="0" mask="0000FFFF" desc="ABN_DECODER_PHI_M = ABN_DECODER_COUNT * 2^16 / ABN_DECODER_PPR + ABN_DECODER_PHI_M_OFFSET;">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ABN_DECODER_PHI_E" shift="16" mask="FFFF0000" desc="ABN_DECODER_PHI_E = (ABN_DECODER_PHI_M * N_POLE_PAIRS_) + ABN_DECODER_PHI_E_OFFSET">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//\xml <tmc:value_register address="#TMC4672_ABN_DECODER_POSITION#" name="ABN_DECODER_POSITION" size="32" group="#GROUP_DECODER_ABN#">
//\xml    <tmc:register_variant name="DEFAULT">
//\xml       <desc></desc>
//\xml       <tmc:value_register_field name="ABN_DECODER_POSITION" shift="0" mask="FFFFFFFF" desc="ABN decoder multi-turn position.">
//\xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
//\xml       </tmc:value_register_field>
//\xml    </tmc:register_variant>
//\xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_2_DECODER_MODE#" name="ABN_2_DECODER_MODE" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Control bits how to handle ABN_2 decoder signals.</desc>
// \xml       <tmc:value_register_field name="apol" shift="0" mask="00000001" desc="Polarity of A pulse.">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="bpol" shift="1" mask="00000002" desc="Polarity of B pulse.">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="npol" shift="2" mask="00000004" desc="Polarity of N pulse.">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="use_abn_as_n" shift="3" mask="00000008" desc="0: Ignore A and B polarity with Npulse = N, 1 : Npulse = N and A and B">
// \xml         <tmc:value_bool desc_false="Ignore A and B polarity with Npulse = N" desc_true="Npulse = N and A and B" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="cln" shift="8" mask="00000100" desc="Clear writes ABN_2_DECODER_COUNT_N into decoder count at Npulse.">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="direction" shift="12" mask="00001000" desc="Decoder count  direction.">
// \xml         <tmc:value_bool desc_false="positive" desc_true="negative" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_2_DECODER_PPR#" name="ABN_2_DECODER_PPR" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ABN_2_DECODER_PPR" shift="0" mask="00FFFFFF" desc="Decoder_2 pules per mechanical revolution. This 2nd ABN encoder interface is for positioning or velocity control but NOT for motor commutation.">
// \xml    	     <tmc:value_unsigned min="1" max="#u24_MAX#" default="65536" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_2_DECODER_COUNT#" name="ABN_2_DECODER_COUNT" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ABN_2_DECODER_COUNT" shift="0" mask="00FFFFFF" desc="Raw decoder_2 count; the digital decoder engine counts modulo (decoder_2_ppr).">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_2_DECODER_COUNT_N#" name="ABN_2_DECODER_COUNT_N" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ABN_2_DECODER_COUNT_N" shift="0" mask="00FFFFFF" desc="Decoder_2 count latched on N pulse, when N pulse clears decoder_2_count also decoder_2_count_n is 0.">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_2_DECODER_PHI_M_OFFSET#" name="ABN_2_DECODER_PHI_M_OFFSET" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ABN_2_DECODER_PHI_M_OFFSET" shift="0" mask="0000FFFF" desc="ABN_2_DECODER_PHI_M_OFFSET to shift (rotate) angle DECODER_2_PHI_M.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ABN_2_DECODER_PHI_M#" name="ABN_2_DECODER_PHI_M" size="32" group="#GROUP_DECODER_ABN#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ABN_2_DECODER_PHI_M" shift="0" mask="0000FFFF" desc="ABN_2_DECODER_PHI_M = ABN_2_DECODER_COUNT * 2^16 / ABN_2_DECODER_PPR + ABN_2_DECODER_PHI_M_OFFSET;">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//\xml <tmc:value_register address="#TMC4672_ABN_2_DECODER_POSITION#" name="ABN_2_DECODER_POSITION" size="32" group="#GROUP_DECODER_ABN#">
//\xml    <tmc:register_variant name="DEFAULT">
//\xml       <desc></desc>
//\xml       <tmc:value_register_field name="ABN_2_DECODER_POSITION" shift="0" mask="FFFFFFFF" desc="ABN decoder_2 multi-turn position.">
//\xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
//\xml       </tmc:value_register_field>
//\xml    </tmc:register_variant>
//\xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_HALL_MODE#" name="HALL_MODE" size="32" group="#GROUP_HALL_DIGITAL#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Mode for digital Hall Sensors used as position decoder.</desc>
// \xml       <tmc:value_register_field name="polarity" shift="0" mask="00000001" desc="polarity">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="interpolation" shift="8" mask="00000100" desc="interpolation">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="direction" shift="12" mask="00001000" desc="direction">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_BLANK" shift="16" mask="0FFF0000" desc="tBLANK = 10ns * HALL_BLANK">
// \xml    	     <tmc:value_unsigned min="0" max="#u12_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_HALL_POSITION_060_000#" name="HALL_POSITION_060_000" size="32" group="#GROUP_HALL_DIGITAL#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_POSITION_000" shift="0" mask="0000FFFF" desc="s16 hall sensor position at 0\xc2\xb0">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_POSITION_060" shift="16" mask="FFFF0000" desc="s16 hall sensor position at 60\xc2\xb0.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="10922" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_HALL_POSITION_180_120#" name="HALL_POSITION_180_120" size="32" group="#GROUP_HALL_DIGITAL#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_POSITION_120" shift="0" mask="0000FFFF" desc="s16 hall sensor position at 120\xc2\xb0.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="21845" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_POSITION_180" shift="16" mask="FFFF0000" desc="s16 hall sensor position at 180\xc2\xb0.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="-32768" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_HALL_POSITION_300_240#" name="HALL_POSITION_300_240" size="32" group="#GROUP_HALL_DIGITAL#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_POSITION_240" shift="0" mask="0000FFFF" desc="s16 hall sensor position at 240\xc2\xb0.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="-21846" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_POSITION_300" shift="16" mask="FFFF0000" desc="s16 hall sensor position at 300\xc2\xb0.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="-10923" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_HALL_PHI_E_PHI_M_OFFSET#" name="HALL_PHI_E_PHI_M_OFFSET" size="32" group="#GROUP_HALL_DIGITAL#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_PHI_M_OFFSET" shift="0" mask="0000FFFF" desc="Offset of mechanical angle hall_phi_m of hall decoder.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_PHI_E_OFFSET" shift="16" mask="FFFF0000" desc="Offset for electrical angle hall_phi_e of hall decoder.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_HALL_DPHI_MAX#" name="HALL_DPHI_MAX" size="32" group="#GROUP_HALL_DIGITAL#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_DPHI_MAX" shift="0" mask="0000FFFF" desc="Maximum dx for interpolation (default for digital hall: u16/6).">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="10922" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_HALL_PHI_E_INTERPOLATED_PHI_E#" name="HALL_PHI_E_INTERPOLATED_PHI_E" size="32" group="#GROUP_HALL_DIGITAL#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_PHI_E" shift="0" mask="0000FFFF" desc="Raw electrical angle hall_phi_e of hall decoder, selection programmed via HALL_MODE control bit.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="HALL_PHI_E_INTERPOLATED" shift="16" mask="FFFF0000" desc="Interpolated electrical angle hall_phi_e_interpolated, selection programmed via HALL_MODE control bit.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_HALL_PHI_M#" name="HALL_PHI_M" size="32" group="#GROUP_HALL_DIGITAL#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HALL_PHI_M" shift="0" mask="0000FFFF" desc="Mechanical angle hall_phi_m of hall decoder.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_MODE#" name="AENC_DECODER_MODE" size="32" group="#GROUP_DECODER_ANALOG#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Control bits to handle analog hall control signals, analog hall signals are absolute position signals within an electrical period; this is different to analog encoders.</desc>

// \xml       <tmc:value_register_field name="AENC_DECODER_MODE[0]" shift="0" mask="00000001" desc="nXY_UVW : 0: SinCos Mode // 1: 0\xc2\xb0 120\xc2\xb0 240\xc2\xb0 Mode">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="AENC_DECODER_MODE[12]" shift="12" mask="00001000" desc="decoder count  direction">
// \xml         <tmc:value_bool desc_false="positive" desc_true="negative" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_N_MASK_N_THRESHOLD#" name="AENC_DECODER_N_THRESHOLD" size="32" group="#GROUP_DECODER_ANALOG#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_DECODER_N_THRESHOLD" shift="0" mask="0000FFFF" desc="Threshold for generating of N pulse from analog AENC_N signal (only needed for analog SinCos encoders with analog N signal).">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AENC_DECODER_N_MASK" shift="16" mask="FFFF0000" desc="Optional position mask (position) for the analog N pulse within phi_a period to be and-ed with the digital N pulse generated via aenc_decoder_n_threshold.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_PHI_A_RAW#" name="AENC_DECODER_PHI_A_RAW" size="32" group="#GROUP_DECODER_ANALOG#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_DECODER_PHI_A_RAW" shift="0" mask="0000FFFF" desc="Raw analog angle phi calculated from analog AENC inputs (analog hall, analog SinCos, ...).">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_PHI_A_OFFSET#" name="AENC_DECODER_PHI_A_OFFSET" size="32" group="#GROUP_DECODER_ANALOG#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_DECODER_PHI_A_OFFSET" shift="0" mask="0000FFFF" desc="Offset for angle phi from analog decoder (analog hall, analog SinCos, ...).">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_PHI_A#" name="AENC_DECODER_PHI_A" size="32" group="#GROUP_DECODER_ANALOG#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_DECODER_PHI_A" shift="0" mask="0000FFFF" desc="Resulting phi available for the FOC (phi_e might need to be calculated from this angle via aenc_decoder_ppr, for analog hall sensors phi_a might be used directly as phi_e depends on analog hall signal type).">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_PPR#" name="AENC_DECODER_PPR" size="32" group="#GROUP_DECODER_ANALOG#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_DECODER_PPR" shift="0" mask="0000FFFF" desc="Number of periods per revolution also called lines per revolution (different nomenclatur compared to digital ABN encoders).">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="1" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_COUNT#" name="AENC_DECODER_COUNT" size="32" group="#GROUP_DECODER_ANALOG#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_DECODER_COUNT" shift="0" mask="FFFFFFFF" desc="Decoder position, raw unscaled.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_COUNT_N#" name="AENC_DECODER_COUNT_N" size="32" group="#GROUP_DECODER_ANALOG#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_DECODER_COUNT_N" shift="0" mask="FFFFFFFF" desc=" Latched decoder position on analog N pulse event.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_PHI_E_PHI_M_OFFSET#" name="AENC_DECODER_PHI_E_PHI_M_OFFSET" size="32" group="#GROUP_DECODER_ANALOG#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_DECODER_PHI_M_OFFSET" shift="0" mask="0000FFFF" desc="Offset for mechanical angle phi_m.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AENC_DECODER_PHI_E_OFFSET" shift="16" mask="FFFF0000" desc="Offset for electrical angle phi_e.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_PHI_E_PHI_M#" name="AENC_DECODER_PHI_E_PHI_M" size="32" group="#GROUP_DECODER_ANALOG#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_DECODER_PHI_M" shift="0" mask="0000FFFF" desc="Resulting angle phi_m.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="AENC_DECODER_PHI_E" shift="16" mask="FFFF0000" desc="Resulting angle phi_e.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_AENC_DECODER_POSITION#" name="AENC_DECODER_POSITION" size="32" group="#GROUP_EMPTY#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="AENC_DECODER_POSITION" shift="0" mask="FFFFFFFF" desc="Multi-turn position.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//\xml <tmc:value_register address="#TMC4672_PIDIN_TORQUE_TARGET_FLUX_TARGET#" name="PIDIN_TORQUE_TARGET_FLUX_TARGET" size="32" group="#GROUP_PID_REGULATORS#">
//\xml    <tmc:register_variant name="DEFAULT">
//\xml       <desc>Target torque and target flux at PI controller inputs.</desc>
//\xml       <tmc:value_register_field name="PIDIN_FLUX_TARGET" shift="0" mask="0000FFFF" desc="">
//\xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
//\xml       </tmc:value_register_field>
//\xml       <tmc:value_register_field name="PIDIN_TORQUE_TARGET" shift="16" mask="FFFF0000" desc="">
//\xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
//\xml       </tmc:value_register_field>
//\xml    </tmc:register_variant>
//\xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PIDIN_VELOCITY_TARGET#" name="PIDIN_VELOCITY_TARGET" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDIN_VELOCITY_TARGET" shift="0" mask="FFFFFFFF" desc="Target velocity at PI controller input.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PIDIN_POSITION_TARGET#" name="PIDIN_POSITION_TARGET" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDIN_POSITION_TARGET" shift="0" mask="FFFFFFFF" desc="Target position at PI controller input.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_CONFIG_DATA#" name="CONFIG_DATA" size="32" group="#GROUP_PID_REGULATORS#">

// \xml    <tmc:register_variant name="Variant 1">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_x_a_1" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="1" range_to="1"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 2">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_x_a_2" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="2" range_to="2"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 4">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_x_b_0" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="4" range_to="4"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 5">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_x_b_1" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="5" range_to="5"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 6">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_x_b_2" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="6" range_to="6"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 7">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_x_enable" shift="0" mask="FFFFFFFF" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="7" range_to="7"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 9">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_v_a_1" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="9" range_to="9"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 10">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_v_a_2" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="10" range_to="10"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 12">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_v_b_0" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="12" range_to="12"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 13">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_v_b_1" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="13" range_to="13"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 14">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_v_b_2" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="14" range_to="14"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 15">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_v_enable" shift="0" mask="FFFFFFFF" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="15" range_to="15"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 17">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_t_a_1" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="17" range_to="17"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 18">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_t_a_2" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="18" range_to="18"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 20">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_t_b_0" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="20" range_to="20"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 21">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_t_b_1" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="21" range_to="21"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 22">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_t_b_2" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="22" range_to="22"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 23">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_t_enable" shift="0" mask="FFFFFFFF" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="23" range_to="23"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 25">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_f_a_1" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="25" range_to="25"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 26">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_f_a_2" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="26" range_to="26"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 28">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_f_b_0" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="28" range_to="28"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 29">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_f_b_1" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="29" range_to="29"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 30">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_f_b_2" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="30" range_to="30"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 31">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="biquad_f_enable" shift="0" mask="FFFFFFFF" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="31" range_to="31"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 32">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="prbs_amplitude" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="32" range_to="32"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 33">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="prbs_down_sampling_ratio" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="33" range_to="33"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 40">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="feed_forward_velocity_gain" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="40" range_to="40"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 41">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="feed_forward_velicity_filter_constant" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="41" range_to="41"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 42">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="feed_forward_torque_gain" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="42" range_to="42"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 43">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="feed_forward_torgue_filter_constant" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="43" range_to="43"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 50">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_METER_PPTM_MIN_POS_DEV" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="50" range_to="50"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 51">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ref_switch_config" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="51" range_to="51"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 52">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="Encoder_Init_hall_Enable" shift="0" mask="00000001" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="52" range_to="52"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 53">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DIG_Hall" shift="0" mask="000000FF" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ENC1" shift="8" mask="0000FF00" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ENC2" shift="16" mask="00FF0000" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="53" range_to="53"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 58">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="enc_init_mini_move_i_factor_enc_init_mini_move_cfg" shift="0" mask="0000FFFF" desc="">
// \xml         <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="58" range_to="58"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 59">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="enc_init_mini_move_u_d_max_enc_init_mini_move_i_d_max" shift="0" mask="0000FFFF" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="enc_init_mini_move_i_d_max" shift="0" mask="0000FFFF" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="59" range_to="59"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 62">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_CONTROL_MODE" shift="0" mask="000000FF" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="62" range_to="62"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 63">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_TARGET_MODE" shift="0" mask="000000FF" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="63" range_to="63"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 64">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_N0" shift="0" mask="0000FFFF" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="64" range_to="64"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 65">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_N1" shift="0" mask="0000FFFF" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="65" range_to="65"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 66">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_N2" shift="0" mask="0000FFFF" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="66" range_to="66"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 67">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_ACCU_DIFF" shift="0" mask="0000FFFF" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="67" range_to="67"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 68">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_P_FACTOR" shift="0" mask="0000FFFF" desc="">
// \xml         <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="68" range_to="68"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 69">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_OL_FREQUENCY" shift="0" mask="FFFFFFFF" desc="">
// \xml         <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="69" range_to="69"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 70">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_OL_AMPLITUDE" shift="0" mask="FFFFFFFF" desc="">
// \xml         <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="70" range_to="70"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 71">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_UD_TARGET" shift="0" mask="00000001" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="52" range_to="52"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 71">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_UQ_TARGET" shift="0" mask="00000001" desc="">
// \xml         <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="52" range_to="52"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 72">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_ID_TARGET" shift="0" mask="00000001" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="52" range_to="52"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 73">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_IQ_TARGET" shift="0" mask="00000001" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="52" range_to="52"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 74">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_EMF_CONSTANT" shift="0" mask="00000001" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="52" range_to="52"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 75">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="BC_T_SWITCH_MAX" shift="0" mask="00000001" desc="">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_CONFIG_ADDR#" shift="0" mask="FFFFFFFF" range_from="52" range_to="52"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_CONFIG_ADDR#" name="CONFIG_ADDR" size="32"  group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Config address</desc>
// \xml       <tmc:value_register_field name="CONFIG_ADDR" shift="0" mask="FFFFFFFF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="1" desc="biquad_x_a_1"></choice_element>
// \xml            <choice_element value="2" desc="biquad_x_a_2"></choice_element>
// \xml            <choice_element value="4" desc="biquad_x_b_0"></choice_element>
// \xml            <choice_element value="5" desc="biquad_x_b_1"></choice_element>
// \xml            <choice_element value="6" desc="biquad_x_b_2"></choice_element>
// \xml            <choice_element value="7" desc="biquad_x_enable"></choice_element>
// \xml            <choice_element value="9" desc="biquad_v_a_1"></choice_element>
// \xml            <choice_element value="10" desc="biquad_v_a_2"></choice_element>
// \xml            <choice_element value="12" desc="biquad_v_b_0"></choice_element>
// \xml            <choice_element value="13" desc="biquad_v_b_1"></choice_element>
// \xml            <choice_element value="14" desc="biquad_v_b_2"></choice_element>
// \xml            <choice_element value="15" desc="biquad_v_enable"></choice_element>
// \xml            <choice_element value="17" desc="biquad_t_a_1"></choice_element>
// \xml            <choice_element value="18" desc="biquad_t_a_2"></choice_element>
// \xml            <choice_element value="20" desc="biquad_t_b_0"></choice_element>
// \xml            <choice_element value="21" desc="biquad_t_b_1"></choice_element>
// \xml            <choice_element value="22" desc="biquad_t_b_2"></choice_element>
// \xml            <choice_element value="23" desc="biquad_t_enable"></choice_element>
// \xml            <choice_element value="25" desc="biquad_f_a_1"></choice_element>
// \xml            <choice_element value="26" desc="biquad_f_a_2"></choice_element>
// \xml            <choice_element value="28" desc="biquad_f_b_0"></choice_element>
// \xml            <choice_element value="29" desc="biquad_f_b_1"></choice_element>
// \xml            <choice_element value="30" desc="biquad_f_b_2"></choice_element>
// \xml            <choice_element value="31" desc="biquad_f_enable"></choice_element>
// \xml            <choice_element value="32" desc="prbs_amplitude"></choice_element>
// \xml            <choice_element value="33" desc="prbs_down_sampling_ratio"></choice_element>
// \xml            <choice_element value="40" desc="feed_forward_velocity_gain"></choice_element>
// \xml            <choice_element value="41" desc="feed_forward_velicity_filter_constant"></choice_element>
// \xml            <choice_element value="42" desc="feed_forward_torque_gain"></choice_element>
// \xml            <choice_element value="43" desc="feed_forward_torgue_filter_constant"></choice_element>
// \xml            <choice_element value="50" desc="VELOCITY_METER_PPTM_MIN_POS_DEV"></choice_element>
// \xml            <choice_element value="51" desc="ref_switch_config"></choice_element>
// \xml            <choice_element value="52" desc="Encoder_Init_hall_Enable"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacts address="#TMC4672_CONFIG_DATA#"></tmc:register_variant_impacts>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//\xml <tmc:value_register address="#TMC4672_AENC_DECODER_POSITION#" name="AENC_DECODER_POSITION" size="32" group="#GROUP_DECODER_ANALOG#">
//\xml    <tmc:register_variant name="DEFAULT">
//\xml       <desc></desc>
//\xml       <tmc:value_register_field name="AENC_DECODER_POSITION" shift="0" mask="FFFFFFFF" desc="Multi turn position.">
//\xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
//\xml       </tmc:value_register_field>
//\xml    </tmc:register_variant>
//\xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_VELOCITY_SELECTION#" name="VELOCITY_SELECTION" size="32"  group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="VELOCITY_SELECTION" shift="0" mask="000000FF" desc="Selects the source of the velocity source for velocity measurement.">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="phi_e selected via PHI_E_SELECTION"></choice_element>
// \xml            <choice_element value="1" desc="phi_e_ext"></choice_element>
// \xml            <choice_element value="2" desc="phi_e_openloop"></choice_element>
// \xml            <choice_element value="3" desc="phi_e_abn"></choice_element>
// \xml            <choice_element value="4" desc="reserved"></choice_element>
// \xml            <choice_element value="5" desc="phi_e_hal"></choice_element>
// \xml            <choice_element value="6" desc="phi_e_aenc"></choice_element>
// \xml            <choice_element value="7" desc="phi_a_aenc"></choice_element>
// \xml            <choice_element value="8" desc="reserved"></choice_element>
// \xml            <choice_element value="9" desc="phi_m_abn"></choice_element>
// \xml            <choice_element value="10" desc="phi_m_abn_2"></choice_element>
// \xml            <choice_element value="11" desc="phi_m_aenc"></choice_element>
// \xml            <choice_element value="12" desc="phi_m_hal"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="VELOCITY_METER_SELECTION" shift="8" mask="0000FF00" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="default velocity meter (fixed frequency sampling)"></choice_element>
// \xml            <choice_element value="1" desc="advanced velocity meter (time difference measurement)"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_POSITION_SELECTION#" name="POSITION_SELECTION" size="32"  group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Selects the source of the actual position.</desc>
// \xml       <tmc:value_register_field name="POSITION_SELECTION" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="phi_e selected via PHI_E_SELECTION"></choice_element>
// \xml            <choice_element value="1" desc="phi_e_ext"></choice_element>
// \xml            <choice_element value="2" desc="phi_e_openloop"></choice_element>
// \xml            <choice_element value="3" desc="phi_e_abn"></choice_element>
// \xml            <choice_element value="4" desc="reserved"></choice_element>
// \xml            <choice_element value="5" desc="phi_e_hal"></choice_element>
// \xml            <choice_element value="6" desc="phi_e_aenc"></choice_element>
// \xml            <choice_element value="7" desc="phi_a_aenc"></choice_element>
// \xml            <choice_element value="8" desc="reserved"></choice_element>
// \xml            <choice_element value="9" desc="phi_m_abn"></choice_element>
// \xml            <choice_element value="10" desc="phi_m_abn_2"></choice_element>
// \xml            <choice_element value="11" desc="phi_m_aenc"></choice_element>
// \xml            <choice_element value="12" desc="phi_m_hal"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PHI_E_SELECTION#" name="PHI_E_SELECTION" size="32"  group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Selection of phi resp. encoder source for rotor position angle phi_e that is used as the input for the FOC for commutation.</desc>
// \xml       <tmc:value_register_field name="PHI_E_SELECTION" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="reserved"></choice_element>
// \xml            <choice_element value="1" desc="phi_e_ext"></choice_element>
// \xml            <choice_element value="2" desc="phi_e_openloop"></choice_element>
// \xml            <choice_element value="3" desc="phi_e_abn"></choice_element>
// \xml            <choice_element value="4" desc="reserved"></choice_element>
// \xml            <choice_element value="5" desc="phi_e_hal"></choice_element>
// \xml            <choice_element value="6" desc="phi_e_aenc"></choice_element>
// \xml            <choice_element value="7" desc="phi_a_aenc"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PHI_E#" name="PHI_E" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PHI_E" shift="0" mask="0000FFFF" desc="Angle used for the inner FOC loop.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_FLUX_P_FLUX_I#" name="PID_FLUX_P_FLUX_I" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>P and I parameter for the flux regulator.</desc>
// \xml       <tmc:value_register_field name="PID_FLUX_I" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_FLUX_P" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_TORQUE_P_TORQUE_I#" name="PID_TORQUE_P_TORQUE_I" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>P and I parameter for the torque regulator.</desc>
// \xml       <tmc:value_register_field name="PID_TORQUE_I" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_TORQUE_P" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_VELOCITY_P_VELOCITY_I#" name="PID_VELOCITY_P_VELOCITY_I" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>P and I parameter for the velocity regulator.</desc>
// \xml       <tmc:value_register_field name="PID_VELOCITY_I" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_VELOCITY_P" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_POSITION_P_POSITION_I#" name="PID_POSITION_P_POSITION_I" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>P and I parameter for the position regulator.</desc>
// \xml       <tmc:value_register_field name="PID_POSITION_I" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_POSITION_P" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="0" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_TORQUE_FLUX_TARGET_DDT_LIMITS#" name="PID_TORQUE_FLUX_TARGET_DDT_LIMITS" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_TORQUE_FLUX_TARGET_DDT_LIMITS" shift="0" mask="FFFFFFFF" desc="Limits of change in time [d/dt] of the target torque and target flux.">
// \xml    	     <tmc:value_unsigned min="0" max="#s16_MAX#" default="#s16_MAX#" unit="[1/\u00B5s]" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PIDOUT_UQ_UD_LIMITS#" name="PIDOUT_UQ_UD_LIMITS" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDOUT_UQ_UD_LIMITS" shift="0" mask="0000FFFF" desc="Two dimensional circular limiter for inputs of iPark.">
// \xml    	     <tmc:value_unsigned min="0" max="#u15_MAX#" default="23169" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_TORQUE_FLUX_LIMITS#" name="PID_TORQUE_FLUX_LIMITS" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_TORQUE_FLUX_LIMITS" shift="0" mask="0000FFFF" desc="PID torque limt and PID flux limit, limits the target values coming from the target registers.">
// \xml    	     <tmc:value_unsigned min="0" max="#u15_MAX#" default="#u15_MAX#" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_ACCELERATION_LIMIT#" name="PID_ACCELERATION_LIMIT" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_ACCELERATION_LIMIT" shift="0" mask="FFFFFFFF" desc="Acceleration limit.">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="2147483647" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_VELOCITY_LIMIT#" name="PID_VELOCITY_LIMIT" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_VELOCITY_LIMIT" shift="0" mask="FFFFFFFF" desc="Velocity limit.">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="2147483647" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_POSITION_LIMIT_LOW#" name="PID_POSITION_LIMIT_LOW" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_POSITION_LIMIT_LOW" shift="0" mask="FFFFFFFF" desc="Position limit low, programmable positon barrier.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="-2147483647" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_POSITION_LIMIT_HIGH#" name="PID_POSITION_LIMIT_HIGH" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_POSITION_LIMIT_HIGH" shift="0" mask="FFFFFFFF" desc="Position limit high, programmable positon barrier.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="2147483647" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_MODE_RAMP_MODE_MOTION#" name="MODE_RAMP_MODE_MOTION" size="32"  group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Register for selection of ramp mode and for selection of motion mode.</desc>
// \xml       <tmc:value_register_field name="MODE_MOTION" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="stopped_mode"></choice_element>
// \xml            <choice_element value="1" desc="torque_mode"></choice_element>
// \xml            <choice_element value="2" desc="velocity_mode"></choice_element>
// \xml            <choice_element value="3" desc="position_mode"></choice_element>
// \xml            <choice_element value="4" desc="prbs_flux_mode"></choice_element>
// \xml            <choice_element value="5" desc="prbs_torque_mode"></choice_element>
// \xml            <choice_element value="6" desc="prbs_velocity_mode"></choice_element>
// \xml            <choice_element value="7" desc="prbs_position_mode"></choice_element>
// \xml            <choice_element value="8" desc="uq_ud_ext"></choice_element>
// \xml            <choice_element value="9" desc="enc_init_mini_move"></choice_element>
// \xml            <choice_element value="10" desc="AGPI_A torque_mode"></choice_element>
// \xml            <choice_element value="11" desc="AGPI_A velocity_mode"></choice_element>
// \xml            <choice_element value="12" desc="AGPI_A position_mode"></choice_element>
// \xml            <choice_element value="13" desc="PWM_I torque_mode"></choice_element>
// \xml            <choice_element value="14" desc="PWM_I velocity_mode"></choice_element>
// \xml            <choice_element value="15" desc="PWM_I position_mode"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="MODE_RAMP" shift="8" mask="0000FF00" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="no velocity ramping"></choice_element>
// \xml            <choice_element value="1" desc="reserved"></choice_element>
// \xml            <choice_element value="2" desc="reserved"></choice_element>
// \xml            <choice_element value="3" desc="reserved"></choice_element>
// \xml            <choice_element value="4" desc="reserved"></choice_element>
// \xml            <choice_element value="5" desc="reserved"></choice_element>
// \xml            <choice_element value="6" desc="reserved"></choice_element>
// \xml            <choice_element value="7" desc="reserved"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="MODE_FF" shift="16" mask="00FF0000" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="disabled"></choice_element>
// \xml            <choice_element value="1" desc="feed forward velocity control"></choice_element>
// \xml            <choice_element value="2" desc="feed forward torque control"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="MODE_PID_SMPL" shift="24" mask="7F000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="127" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="MODE_PID_TYPE" shift="31" mask="80000000" desc="">
// \xml         <tmc:value_bool desc_false="Classical PI parallel architecture" desc_true="Advanced PI sequential architecture" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_TORQUE_FLUX_TARGET#" name="PID_TORQUE_FLUX_TARGET" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Register of target torque and target flux (for torque mode).</desc>
// \xml       <tmc:value_register_field name="PID_FLUX_TARGET" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_TORQUE_TARGET" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_TORQUE_FLUX_OFFSET#" name="PID_TORQUE_FLUX_OFFSET" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Register of torque and flux offset.</desc>
// \xml       <tmc:value_register_field name="PID_FLUX_OFFSET" shift="0" mask="0000FFFF" desc="Flux offset for feed forward control.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_TORQUE_OFFSET" shift="16" mask="FFFF0000" desc="Torque offset for feed forward control.">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_VELOCITY_TARGET#" name="PID_VELOCITY_TARGET" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_VELOCITY_TARGET" shift="0" mask="FFFFFFFF" desc="Target velocity register (for velocity mode).">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_VELOCITY_OFFSET#" name="PID_VELOCITY_OFFSET" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_VELOCITY_OFFSET" shift="0" mask="FFFFFFFF" desc="Velocity offset for feed forward control.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_POSITION_TARGET#" name="PID_POSITION_TARGET" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_POSITION_TARGET" shift="0" mask="FFFFFFFF" desc="Target position register (for position mode).">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_TORQUE_FLUX_ACTUAL#" name="PID_TORQUE_FLUX_ACTUAL" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Actual torque and actual flux.</desc>
// \xml       <tmc:value_register_field name="PID_FLUX_ACTUAL" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_TORQUE_ACTUAL" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_VELOCITY_ACTUAL#" name="PID_VELOCITY_ACTUAL" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_VELOCITY_ACTUAL" shift="0" mask="FFFFFFFF" desc="Actual velocity.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_POSITION_ACTUAL#" name="PID_POSITION_ACTUAL" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_POSITION_ACTUAL" shift="0" mask="FFFFFFFF" desc="Actual multi turn position for positioning. WRITE on PID_POSITION_ACTUAL writes same value into PID_POSITION_TARGET to avoid unwanted move.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_ERROR_DATA#" name="PID_ERROR_DATA" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="Variant 0">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_TORQUE_ERROR" shift="0" mask="FFFFFFFF" desc="PID torque error.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_PID_ERROR_ADDR#" shift="0" mask="FFFFFFFF" range_from="0" range_to="0"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 1">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_FLUX_ERROR" shift="0" mask="FFFFFFFF" desc="PID flux error.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_PID_ERROR_ADDR#" shift="0" mask="FFFFFFFF" range_from="1" range_to="1"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 2">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_VELOCITY_ERROR" shift="0" mask="FFFFFFFF" desc="PID velocity error.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_PID_ERROR_ADDR#" shift="0" mask="FFFFFFFF" range_from="2" range_to="2"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 3">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_POSITION_ERROR" shift="0" mask="FFFFFFFF" desc="PID position error.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_PID_ERROR_ADDR#" shift="0" mask="FFFFFFFF" range_from="3" range_to="3"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 4">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_TORQUE_ERROR_SUM" shift="0" mask="FFFFFFFF" desc="PID torque error.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_PID_ERROR_ADDR#" shift="0" mask="FFFFFFFF" range_from="4" range_to="4"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 5">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_FLUX_ERROR_SUM" shift="0" mask="FFFFFFFF" desc="PID flux error sum.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_PID_ERROR_ADDR#" shift="0" mask="FFFFFFFF" range_from="5" range_to="5"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 6">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_VELOCITY_ERROR_SUM" shift="0" mask="FFFFFFFF" desc="PID velocity error sum.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_PID_ERROR_ADDR#" shift="0" mask="FFFFFFFF" range_from="6" range_to="6"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 7">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_POSITION_ERROR_SUM" shift="0" mask="FFFFFFFF" desc="PID position error sum.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_PID_ERROR_ADDR#" shift="0" mask="FFFFFFFF" range_from="7" range_to="7"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_PID_ERROR_ADDR#" name="PID_ERROR_ADDR" size="32"  group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>PID error address</desc>
// \xml       <tmc:value_register_field name="PID_ERROR_ADDR" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="PID_TORQUE_ERROR"></choice_element>
// \xml            <choice_element value="1" desc="PID_FLUX_ERROR"></choice_element>
// \xml            <choice_element value="2" desc="PID_VELOCITY_ERROR"></choice_element>
// \xml            <choice_element value="3" desc="PID_POSITION_ERROR"></choice_element>
// \xml            <choice_element value="4" desc="PID_TORQUE_ERROR_SUM"></choice_element>
// \xml            <choice_element value="5" desc="PID_FLUX_ERROR_SUM"></choice_element>
// \xml            <choice_element value="6" desc="PID_VELOCITY_ERROR_SUM"></choice_element>
// \xml            <choice_element value="7" desc="PID_POSITION_ERROR_SUM"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacts address="#TMC4672_PID_ERROR_DATA#"></tmc:register_variant_impacts>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_INTERIM_DATA#" name="INTERIM_DATA" size="32" group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="Variant 0">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDIN_TARGET_TORQUE" shift="0" mask="FFFFFFFF" desc="PIDIN target torque.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="0" range_to="0"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 1">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDIN_TARGET_FLUX" shift="0" mask="FFFFFFFF" desc="PIDIN target flux.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="1" range_to="1"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 2">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDIN_TARGET_VELOCITY" shift="0" mask="FFFFFFFF" desc="PIDIN target velocity.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="2" range_to="2"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 3">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDIN_TARGET_POSITION" shift="0" mask="FFFFFFFF" desc="PIDIN target position.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="3" range_to="3"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 4">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDOUT_TARGET_TORQUE" shift="0" mask="FFFFFFFF" desc="PIDOUT target torque.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="4" range_to="4"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 5">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDOUT_TARGET_FLUX" shift="0" mask="FFFFFFFF" desc="PIDOUT target flux.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="5" range_to="5"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 6">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDOUT_TARGET_VELOCITY" shift="0" mask="FFFFFFFF" desc="PIDOUT target velocity.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="6" range_to="6"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 7">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PIDOUT_TARGET_POSITION" shift="0" mask="FFFFFFFF" desc="PIDOUT target position.">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="7" range_to="7"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 8">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FOC_IUX" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="FOC_IWY" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="8" range_to="8"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 9">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FOC_IV" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="9" range_to="9"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 10">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FOC_IA" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="FOC_IB" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="10" range_to="10"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 11">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FOC_ID" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="FOC_IQ" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="11" range_to="11"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 12">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FOC_UD" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="FOC_UQ" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="12" range_to="12"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 13">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FOC_UD_LIMITED" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="FOC_UQ_LIMITED" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="13" range_to="13"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 14">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FOC_UA" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="FOC_UB" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="14" range_to="14"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 15">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FOC_UUX" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="FOC_UWY" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="15" range_to="15"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 16">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FOC_UV" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="16" range_to="16"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 17">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_UX" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PWM_WY" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="17" range_to="17"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 18">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PWM_V" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="18" range_to="18"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 19">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_I_0" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_I_1" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="19" range_to="19"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 20">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_FLUX_ACTUAL_DIV256" shift="0" mask="000000FF" desc="">
// \xml    	     <tmc:value_signed min="#s8_MIN#" max="#s8_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_TORQUE_ACTUAL_DIV256" shift="8" mask="0000FF00" desc="">
// \xml    	     <tmc:value_signed min="#s8_MIN#" max="#s8_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_FLUX_TARGET_DIV256" shift="16" mask="00FF0000" desc="">
// \xml    	     <tmc:value_signed min="#s8_MIN#" max="#s8_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_TORQUE_TARGET_DIV256" shift="24" mask="FF000000" desc="">
// \xml    	     <tmc:value_signed min="#s8_MIN#" max="#s8_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="20" range_to="20"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 21">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_TORQUE_ACTUAL" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_TORQUE_TARGET" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="21" range_to="21"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 22">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_FLUX_ACTUAL" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_FLUX_TARGET" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="22" range_to="22"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 23">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_VELOCITY_ACTUAL_DIV256" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_VELOCITY_TARGET_DIV256" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="23" range_to="23"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 24">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_VELOCITY_ACTUAL_LSB" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_VELOCITY_TARGET_LSB" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="24" range_to="24"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 25">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_POSITION_ACTUAL_DIV256" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_POSITION_TARGET_DIV256" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="25" range_to="25"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 26">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="PID_POSITION_ACTUAL_LSB" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="PID_POSITION_TARGET_LSB" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="26" range_to="26"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 27">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FF_VELOCITY" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="27" range_to="27"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 28">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="FF_TORQUE" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="28" range_to="28"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 29">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ACTUAL_VELOCITY_PPTM" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="29" range_to="29"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 30">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="REF_SWITCH_STATUS" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="30" range_to="30"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 31">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="HOME_POSITION" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="31" range_to="31"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 32">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="LEFT_POSITION" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="32" range_to="32"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 33">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="RIGHT_POSITION" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="33" range_to="33"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 34">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ENC_INIT_HALL_STATUS" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="34" range_to="34"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 35">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ENC_INIT_HALL_PHI_E_ABN_OFFSET" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="35" range_to="35"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 36">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ENC_INIT_HALL_PHI_E_AENC_OFFSET" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="36" range_to="36"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 37">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ENC_INIT_HALL_PHI_A_AENC_OFFSET" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="37" range_to="37"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 40">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ENC_INIT_MINI_MOVE_STATUS" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ENC_INIT_MINI_MOVE_U_D" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="40" range_to="40"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 41">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ENC_INIT_MINI_MOVE_PHI_E_OFFSET" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ENC_INIT_MINI_MOVE_PHI_E" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="41" range_to="41"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 192">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_0" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_1" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="192" range_to="192"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 193">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_2" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_3" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="193" range_to="193"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 194">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_4" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_5" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="194" range_to="194"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 195">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_6" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_7" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="195" range_to="195"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 196">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_8" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_9" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="196" range_to="196"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 197">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_10" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_11" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="197" range_to="197"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 198">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_12" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_13" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="198" range_to="198"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 199">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_14" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_15" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="199" range_to="199"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 200">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_16" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="200" range_to="200"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 201">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_17" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="201" range_to="201"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 202">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_18" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="202" range_to="202"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 203">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="DEBUG_VALUE_19" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="203" range_to="203"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 208">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CONFIG_REG_0" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="208" range_to="208"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 209">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CONFIG_REG_1" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="209" range_to="209"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 210">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CTRL_PARAM_0" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="CTRL_PARAM_1" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="210" range_to="210"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 211">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="CTRL_PARAM_2" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="CTRL_PARAM_3" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="211" range_to="211"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 212">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATUS_REG_0" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="212" range_to="212"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 213">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATUS_REG_1" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="213" range_to="213"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 214">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATUS_PARAM_0" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="STATUS_PARAM_1" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="214" range_to="214"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml    <tmc:register_variant name="Variant 215">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="STATUS_PARAM_2" shift="0" mask="0000FFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="STATUS_PARAM_3" shift="16" mask="FFFF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacted_by address="#TMC4672_INTERIM_ADDR#" shift="0" mask="FFFFFFFF" range_from="215" range_to="215"></tmc:register_variant_impacted_by>
// \xml    </tmc:register_variant>

// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_INTERIM_ADDR#" name="INTERIM_ADDR" size="32"  group="#GROUP_PID_REGULATORS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Internal interim values.</desc>
// \xml       <tmc:value_register_field name="INTERIM_ADDR" shift="0" mask="000000FF" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="PIDIN_TARGET_TORQUE"></choice_element>
// \xml            <choice_element value="1" desc="PIDIN_TARGET_FLUX"></choice_element>
// \xml            <choice_element value="2" desc="PIDIN_TARGET_VELOCITY"></choice_element>
// \xml            <choice_element value="3" desc="PIDIN_TARGET_POSITION"></choice_element>
// \xml            <choice_element value="4" desc="PIDOUT_TARGET_TORQUE"></choice_element>
// \xml            <choice_element value="5" desc="PIDOUT_TARGET_FLUX"></choice_element>
// \xml            <choice_element value="6" desc="PIDOUT_TARGET_VELOCITY"></choice_element>
// \xml            <choice_element value="7" desc="PIDOUT_TARGET_POSITION"></choice_element>
// \xml            <choice_element value="8" desc="FOC_IWY_IUX"></choice_element>
// \xml            <choice_element value="9" desc="FOC_IV"></choice_element>
// \xml            <choice_element value="10" desc="FOC_IB_IA"></choice_element>
// \xml            <choice_element value="11" desc="FOC_IQ_ID"></choice_element>
// \xml            <choice_element value="12" desc="FOC_UQ_UD"></choice_element>
// \xml            <choice_element value="13" desc="FOC_UQ_UD_LIMITED"></choice_element>
// \xml            <choice_element value="14" desc="FOC_UB_UA"></choice_element>
// \xml            <choice_element value="15" desc="FOC_UWY_UUX"></choice_element>
// \xml            <choice_element value="16" desc="FOC_UV"></choice_element>
// \xml            <choice_element value="17" desc="PWM_WY_UX"></choice_element>
// \xml            <choice_element value="18" desc="PWM_UV"></choice_element>
// \xml            <choice_element value="19" desc="ADC_I1_I0"></choice_element>
// \xml            <choice_element value="20" desc="PID_TORQUE_TARGET_FLUX_TARGET_TORQUE_ACTUAL_FLUX_ACTUAL_DIV256"></choice_element>
// \xml            <choice_element value="21" desc="PID_TORQUE_TARGET_TORQUE_ACTUAL"></choice_element>
// \xml            <choice_element value="22" desc="PID_FLUX_TARGET_FLUX_ACTUAL"></choice_element>
// \xml            <choice_element value="23" desc="PID_VELOCITY_TARGET_VELOCITY_ACTUAL_DIV256"></choice_element>
// \xml            <choice_element value="24" desc="PID_VELOCITY_TARGET_VELOCITY_ACTUAL"></choice_element>
// \xml            <choice_element value="25" desc="PID_POSITION_TARGET_POSITION_ACTUAL_DIV256"></choice_element>
// \xml            <choice_element value="26" desc="PID_POSITION_TARGET_POSITION_ACTUAL"></choice_element>
// \xml            <choice_element value="27" desc="FF_VELOCITY"></choice_element>
// \xml            <choice_element value="28" desc="FF_TORQUE"></choice_element>
// \xml            <choice_element value="29" desc="ACTUAL_VELOCITY_PPTM"></choice_element>
// \xml            <choice_element value="30" desc="REF_SWITCH_STATUS"></choice_element>
// \xml            <choice_element value="31" desc="HOME_POSITION"></choice_element>
// \xml            <choice_element value="32" desc="LEFT_POSITION"></choice_element>
// \xml            <choice_element value="33" desc="RIGHT_POSITION"></choice_element>
// \xml            <choice_element value="34" desc="ENC_INIT_HALL_STATUS"></choice_element>
// \xml            <choice_element value="35" desc="ENC_INIT_HALL_PHI_E_ABN_OFFSET"></choice_element>
// \xml            <choice_element value="36" desc="ENC_INIT_HALL_PHI_E_AENC_OFFSET"></choice_element>
// \xml            <choice_element value="37" desc="ENC_INIT_HALL_PHI_A_AENC_OFFSET"></choice_element>
// \xml            <choice_element value="40" desc="enc_init_mini_move_u_d_status"></choice_element>
// \xml            <choice_element value="41" desc="enc_init_mini_move_phi_e_phi_e_offset"></choice_element>
// \xml            <choice_element value="192" desc="DEBUG_VALUE_1_0"></choice_element>
// \xml            <choice_element value="193" desc="DEBUG_VALUE_3_2"></choice_element>
// \xml            <choice_element value="194" desc="DEBUG_VALUE_5_4"></choice_element>
// \xml            <choice_element value="195" desc="DEBUG_VALUE_7_6"></choice_element>
// \xml            <choice_element value="196" desc="DEBUG_VALUE_9_8"></choice_element>
// \xml            <choice_element value="197" desc="DEBUG_VALUE_11_10"></choice_element>
// \xml            <choice_element value="198" desc="DEBUG_VALUE_13_12"></choice_element>
// \xml            <choice_element value="199" desc="DEBUG_VALUE_15_14"></choice_element>
// \xml            <choice_element value="200" desc="DEBUG_VALUE_16"></choice_element>
// \xml            <choice_element value="201" desc="DEBUG_VALUE_17"></choice_element>
// \xml            <choice_element value="202" desc="DEBUG_VALUE_18"></choice_element>
// \xml            <choice_element value="203" desc="DEBUG_VALUE_19"></choice_element>
// \xml            <choice_element value="208" desc="CONFIG_REG_0"></choice_element>
// \xml            <choice_element value="209" desc="CONFIG_REG_1"></choice_element>
// \xml            <choice_element value="210" desc="CTRL_PARAM_10"></choice_element>
// \xml            <choice_element value="211" desc="CTRL_PARAM_32"></choice_element>
// \xml            <choice_element value="212" desc="STATUS_REG_0"></choice_element>
// \xml            <choice_element value="213" desc="STATUS_REG_1"></choice_element>
// \xml            <choice_element value="214" desc="STATUS_PARAM_10"></choice_element>
// \xml            <choice_element value="215" desc="STATUS_PARAM_32"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml       <tmc:register_variant_impacts address="#TMC4672_INTERIM_DATA#"></tmc:register_variant_impacts>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_WATCHDOG_CFG#" name="WATCHDOG_CFG" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="WATCHDOG_CFG" shift="0" mask="00000003" desc="">
// \xml          <tmc:value_choice default="0" unit="" access="RW">
// \xml            <choice_element value="0" desc="No action on watchdog error"></choice_element>
// \xml            <choice_element value="1" desc="PWM and power stage disable on watchdog error"></choice_element>
// \xml            <choice_element value="2" desc="Global reset on watchdog error"></choice_element>
// \xml            <choice_element value="3" desc="reserved"></choice_element>
// \xml          </tmc:value_choice>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_ADC_VM_LIMITS#" name="ADC_VM_LIMITS" size="32" group="#GROUP_ADCS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADC_VM_LIMIT_LOW" shift="0" mask="0000FFFF" desc="Low limit for brake chopper output BRAKE_OUT.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="65535" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADC_VM_LIMIT_HIGH" shift="16" mask="FFFF0000" desc="High limit for brake chopper output BRAKE_OUT.">
// \xml    	     <tmc:value_unsigned min="0" max="#u16_MAX#" default="65535" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_INPUTS_RAW#" name="TMC4672_INPUTS_RAW" size="32" group="#GROUP_IO#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Raw input signals PWM_IN, DIR, STP, Digital Hall Inputs, and digital ABN encoder inputs as raw signals for direct read out for system setup and validation during development phase.</desc>

// \xml       <tmc:value_register_field name="A of ABN_RAW" shift="0" mask="00000001" desc="A of ABN_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="B of ABN_RAW" shift="1" mask="00000002" desc="B of ABN_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="N of ABN_RAW" shift="2" mask="00000004" desc="N of ABN_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="3" mask="00000008" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="A of ABN_2_RAW" shift="4" mask="00000010" desc="A of ABN_2_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="B of ABN_2_RAW" shift="5" mask="00000020" desc="B of ABN_2_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="N of ABN_2_RAW" shift="6" mask="00000040" desc="N of ABN_2_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="7" mask="00000080" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="HALL_UX of HALL_RAW" shift="8" mask="00000100" desc="HALL_UX of HALL_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="HALL_V of HALL_RAW" shift="9" mask="00000200" desc="HALL_V of HALL_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="HALL_WY of HALL_RAW" shift="10" mask="00000400" desc="HALL_WY of HALL_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="11" mask="00000800" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="REF_SW_R_RAW" shift="12" mask="00001000" desc="REF_SW_R_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="REF_SW_H_RAW" shift="13" mask="00002000" desc="REF_SW_H_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="REF_SW_L_RAW" shift="14" mask="00004000" desc="REF_SW_L_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="ENABLE_IN_RAW" shift="15" mask="00008000" desc="ENABLE_IN_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STP of DIRSTP_RAW" shift="16" mask="00010000" desc="STP of DIRSTP_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="DIR of DIRSTP_RAW" shift="17" mask="00020000" desc="DIR of DIRSTP_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="PWM_IN_RAW" shift="18" mask="00040000" desc="PWM_IN_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="19" mask="00080000" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="HALL_UX_FILT" shift="20" mask="00100000" desc="ESI_0 of ESI_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="HALL_V_FILT" shift="21" mask="00200000" desc="ESI_1 of ESI_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="HALL_WY_FILT" shift="22" mask="00400000" desc="ESI_2 of ESI_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="23" mask="00800000" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="24" mask="01000000" desc="CFG_0 of CFG">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="25" mask="02000000" desc="CFG_1 of CFG">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="26" mask="04000000" desc="CFG_2 of CFG">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="27" mask="08000000" desc="CFG_3 of CFG">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="PWM_IDLE_L_RAW" shift="28" mask="10000000" desc="PWM_IDLE_L_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="PWM_IDLE_H_RAW" shift="29" mask="20000000" desc="PWM_IDLE_H_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="30" mask="40000000" desc="DRV_ERR_IN_RAW">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="-" shift="31" mask="80000000" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_OUTPUTS_RAW#" name="TMC4672_OUTPUTS_RAW" size="32" group="#GROUP_IO#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>

// \xml       <tmc:value_register_field name="TMC4672_OUTPUTS_RAW[0]" shift="0" mask="00000001" desc="PWM_UX1_L">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TMC4672_OUTPUTS_RAW[1]" shift="1" mask="00000002" desc="PWM_UX1_H">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TMC4672_OUTPUTS_RAW[2]" shift="2" mask="00000004" desc="PWM_VX2_L">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TMC4672_OUTPUTS_RAW[3]" shift="3" mask="00000008" desc="PWM_VX2_H">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TMC4672_OUTPUTS_RAW[4]" shift="4" mask="00000010" desc="PWM_WY1_L">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TMC4672_OUTPUTS_RAW[5]" shift="5" mask="00000020" desc="PWM_WY1_H">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TMC4672_OUTPUTS_RAW[6]" shift="6" mask="00000040" desc="PWM_Y2_L">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="TMC4672_OUTPUTS_RAW[7]" shift="7" mask="00000080" desc="PWM_Y2_H">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="R"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_STEP_WIDTH#" name="STEP_WIDTH" size="32" group="#GROUP_IO#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Step direction Interface Control Register.</desc>
// \xml       <tmc:value_register_field name="STEP_WIDTH" shift="0" mask="FFFFFFFF" desc="STEP WIDTH = 0 => STP pulses ignored, resulting direction = DIR XOR sign(STEP_WIDTH), effects PID_POSITION_TARGET">
// \xml    	     <tmc:value_signed min="#s32_MIN#" max="#s32_MAX#" default="0" unit="" access="RW"></tmc:value_signed>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_UART_BPS#" name="UART_BPS" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="UART_BPS" shift="0" mask="00FFFFFF" desc="9600, 115200, 921600, 3000000 (default=9600)">
// \xml    	     <tmc:value_unsigned min="0" max="#u24_MAX#" default="9600" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_UART_ADDRS#" name="UART_ADDRS" size="32" group="#GROUP_GENERAL_SETTINGS#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="ADDR_A" shift="0" mask="000000FF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADDR_B" shift="8" mask="0000FF00" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADDR_C" shift="16" mask="00FF0000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml       <tmc:value_register_field name="ADDR_D" shift="24" mask="FF000000" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u8_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_GPIO_dsADCI_CONFIG#" name="GPIO_dsADCI_CONFIG" size="32" group="#GROUP_IO#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc></desc>
// \xml       <tmc:value_register_field name="GPIO_dsADCI_CONFIG" shift="0" mask="FFFFFFFF" desc="Configuration of GPIO (enable, disable, input, output, analog dsADC input)">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

//\xml <tmc:value_register address="#TMC4672_PID_TORQUE_TARGET_ACTUAL#" name="PID_TORQUE_TARGET_ACTUAL" size="32" group="#GROUP_PID_REGULATORS#">
//\xml    <tmc:register_variant name="DEFAULT">
//\xml       <desc></desc>
//\xml       <tmc:value_register_field name="PID_TORQUE_ACTUAL" shift="0" mask="0000FFFF" desc="">
//\xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
//\xml       </tmc:value_register_field>
//\xml       <tmc:value_register_field name="PID_TORQUE_TARGET" shift="16" mask="FFFF0000" desc="">
//\xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
//\xml       </tmc:value_register_field>
//\xml    </tmc:register_variant>
//\xml </tmc:value_register>

//\xml <tmc:value_register address="#TMC4672_PID_FLUX_TARGET_ACTUAL#" name="PID_FLUX_TARGET_ACTUAL" size="32" group="#GROUP_PID_REGULATORS#">
//\xml    <tmc:register_variant name="DEFAULT">
//\xml       <desc></desc>
//\xml       <tmc:value_register_field name="PID_FLUX_ACTUAL" shift="0" mask="0000FFFF" desc="">
//\xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
//\xml       </tmc:value_register_field>
//\xml       <tmc:value_register_field name="PID_FLUX_TARGET" shift="16" mask="FFFF0000" desc="">
//\xml    	     <tmc:value_signed min="#s16_MIN#" max="#s16_MAX#" default="0" unit="" access="R"></tmc:value_signed>
//\xml       </tmc:value_register_field>
//\xml    </tmc:register_variant>
//\xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_STATUS_FLAGS#" name="STATUS_FLAGS" size="32" group="#GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Status Flag Bitvector Vector, individual status bits are set to '1' on error condition pulse '1' and remain '1' until they are over written by '0' values via register access; error condition '1' have priority over register write access.</desc>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[0]" shift="0" mask="00000001" desc="pid_x_target_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[1]" shift="1" mask="00000002" desc="pid_x_target_ddt_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[2]" shift="2" mask="00000004" desc="pid_x_errsum_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[3]" shift="3" mask="00000008" desc="pid_x_output_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[4]" shift="4" mask="00000010" desc="pid_v_target_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[5]" shift="5" mask="00000020" desc="pid_v_target_ddt_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[6]" shift="6" mask="00000040" desc="pid_v_errsum_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[7]" shift="7" mask="00000080" desc="pid_v_output_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[8]" shift="8" mask="00000100" desc="pid_id_target_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[9]" shift="9" mask="00000200" desc="pid_id_target_ddt_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[10]" shift="10" mask="00000400" desc="pid_id_errsum_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[11]" shift="11" mask="00000800" desc="pid_id_output_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[12]" shift="12" mask="00001000" desc="pid_iq_target_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[13]" shift="13" mask="00002000" desc="pid_iq_target_ddt_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[14]" shift="14" mask="00004000" desc="pid_iq_errsum_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[15]" shift="15" mask="00008000" desc="pid_iq_output_limit">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[16]" shift="16" mask="00010000" desc="ipark_cirlim_limit_u_d">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[17]" shift="17" mask="00020000" desc="ipark_cirlim_limit_u_q">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[18]" shift="18" mask="00040000" desc="ipark_cirlim_limit_u_r">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[19]" shift="19" mask="00080000" desc="not_PLL_locked">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[20]" shift="20" mask="00100000" desc="ref_sw_r">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[21]" shift="21" mask="00200000" desc="ref_sw_h">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[22]" shift="22" mask="00400000" desc="ref_sw_l">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[23]" shift="23" mask="00800000" desc="---">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[24]" shift="24" mask="01000000" desc="pwm_min">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[25]" shift="25" mask="02000000" desc="pwm_max">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[26]" shift="26" mask="04000000" desc="adc_i_clipped">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[27]" shift="27" mask="08000000" desc="aenc_clipped">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[28]" shift="28" mask="10000000" desc="enc_n">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[29]" shift="29" mask="20000000" desc="enc_2_n">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[30]" shift="30" mask="40000000" desc="aenc_n">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml       <tmc:value_register_field name="STATUS_FLAGS[31]" shift="31" mask="80000000" desc="wd_error">
// \xml         <tmc:value_bool desc_false="off" desc_true="on" default="false" access="RW"></tmc:value_bool>
// \xml       </tmc:value_register_field>

// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml <tmc:value_register address="#TMC4672_STATUS_MASK#" name="STATUS_MASK" size="32" group="#GROUP_STATUS_INFORMATION#">
// \xml    <tmc:register_variant name="DEFAULT">
// \xml       <desc>Status Masks to select Status Flags for IRQ Condition, driving STATUS_OUT.</desc>
// \xml       <tmc:value_register_field name="WARNING_MASK" shift="0" mask="FFFFFFFF" desc="">
// \xml    	     <tmc:value_unsigned min="0" max="#u32_MAX#" default="0" unit="" access="RW"></tmc:value_unsigned>
// \xml       </tmc:value_register_field>
// \xml    </tmc:register_variant>
// \xml </tmc:value_register>

// \xml </tmc:register_set>
// \xml </tmc:product_ic>
