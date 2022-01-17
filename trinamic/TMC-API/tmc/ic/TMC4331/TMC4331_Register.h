/*
 * TMC4331_Register.h
 *
 *  Created on: 17.07.2017
 *      Author: LK
 */

#ifndef TMC4331_REGISTER_H
#define TMC4331_REGISTER_H

	#define TMC4331_GENERAL_CONF          0x00
	#define TMC4331_REFERENCE_CONF        0x01
	#define TMC4331_START_CONF            0x02
	#define TMC4331_INPUT_FILT_CONF       0x03
	#define TMC4331_SPIOUT_CONF           0x04
	#define TMC4331_CURRENT_CONF          0x05
	#define TMC4331_SCALE_VALUES          0x06
	#define TMC4331_STEP_CONF             0x0A
	#define TMC4331_SPI_STATUS_SELECTION  0x0B
	#define TMC4331_EVENT_CLEAR_CONF      0x0C
	#define TMC4331_INTR_CONF             0x0D
	#define TMC4331_EVENTS                0x0E
	#define TMC4331_STATUS                0x0F

	#define TMC4331_STP_LENGTH_ADD        0x10
	#define TMC4331_DIR_SETUP_TIME        0x10
	#define TMC4331_START_OUT_ADD         0x11
	#define TMC4331_GEAR_RATIO            0x12
	#define TMC4331_START_DELAY           0x13
	#define TMC4331_CLK_GATING_DELAY      0x14
	#define TMC4331_STDBY_DELAY           0x15
	#define TMC4331_FREEWHEEL_DELAY       0x16
	#define TMC4331_VDRV_SCALE_LIMIT      0x17
	#define TMC4331_PWM_VMAX              0x17
	#define TMC4331_UP_SCALE_DELAY        0x18
	#define TMC4331_HOLD_SCALE_DELAY      0x19
	#define TMC4331_DRV_SCALE_DELAY       0x1A
	#define TMC4331_BOOST_TIME            0x1B
	#define TMC4331_DAC_ADDR_A            0x1D
	#define TMC4331_DAC_ADDR_B            0x1D
	#define TMC4331_SPI_SWITCH_VEL        0x1D
	#define TMC4331_HOME_SAFETY_MARGIN    0x1E
	#define TMC4331_PWM_FREQ              0x1F
	#define TMC4331_CHOPSYNC_DIV          0x1F

	#define TMC4331_RAMPMODE              0x20
	#define TMC4331_XACTUAL               0x21
	#define TMC4331_VACTUAL               0x22
	#define TMC4331_AACTUAL               0x23
	#define TMC4331_VMAX                  0x24
	#define TMC4331_VSTART                0x25
	#define TMC4331_VSTOP                 0x26
	#define TMC4331_VBREAK                0x27
	#define TMC4331_AMAX                  0x28
	#define TMC4331_DMAX                  0x29
	#define TMC4331_ASTART                0x2A
	#define TMC4331_SIGN_AACT             0x2A
	#define TMC4331_DFINAL                0x2B
	#define TMC4331_DSTOP                 0x2C
	#define TMC4331_BOW1                  0x2D
	#define TMC4331_BOW2                  0x2E
	#define TMC4331_BOW3                  0x2F
	#define TMC4331_BOW4                  0x30
	#define TMC4331_CLK_FREQ              0x31

	#define TMC4331_POS_COMP              0x32
	#define TMC4331_VIRT_STOP_LEFT        0x33
	#define TMC4331_VIRT_STOP_RIGHT       0x34
	#define TMC4331_X_HOME                0x35
	#define TMC4331_X_LATCH_RD            0x36
	#define TMC4331_REV_CNT_RD            0x36
	#define TMC4331_X_RANGE_WR            0x36
	#define TMC4331_X_TARGET              0x37

	#define TMC4331_X_PIPE0               0x38
	#define TMC4331_X_PIPE1               0x39
	#define TMC4331_X_PIPE2               0x3A
	#define TMC4331_X_PIPE3               0x3B
	#define TMC4331_X_PIPE4               0x3C
	#define TMC4331_X_PIPE5               0x3D
	#define TMC4331_X_PIPE6               0x3E
	#define TMC4331_X_PIPE7               0x3F

	#define TMC4331_SH_REG0               0x40
	#define TMC4331_SH_REG1               0x41
	#define TMC4331_SH_REG2               0x42
	#define TMC4331_SH_REG3               0x43
	#define TMC4331_SH_REG4               0x44
	#define TMC4331_SH_REG5               0x45
	#define TMC4331_SH_REG6               0x46
	#define TMC4331_SH_REG7               0x47
	#define TMC4331_SH_REG8               0x48
	#define TMC4331_SH_REG9               0x49
	#define TMC4331_SH_REG10              0x4A
	#define TMC4331_SH_REG11              0x4B
	#define TMC4331_SH_REG12              0x4C
	#define TMC4331_SH_REG13              0x4D

	#define TMC4331_CLK_GATING_REG        0x4F
	#define TMC4331_RESET_REG             0x4F

	#define TMC4331_FS_VEL_WR             0x60
	#define TMC4331_DC_VEL_WR             0x60
	#define TMC4331_DC_TIME_WR            0x61
	#define TMC4331_DC_SG_WR              0x61
	#define TMC4331_DC_BLKTIME_WR         0x61
	#define TMC4331_DC_LSPTM_WR           0x62
	#define TMC4331_SYNCHRO_SET           0x64
	#define TMC4331_VSTALL_LIMIT_WR       0x67

	#define TMC4331_COVER_LOW_WR          0x6C
	#define TMC4331_POLLING_STATUS_RD     0x6C
	#define TMC4331_COVER_HIGH_WR         0x6D
	#define TMC4331_POLLING_REG_WR        0x6D
	#define TMC4331_COVER_DRV_LOW_RD      0x6E
	#define TMC4331_COVER_DRV_HIGH_RD     0x6F

	#define TMC4331_MSLUT_0_WR            0x70
	#define TMC4331_MSLUT_1_WR            0x71
	#define TMC4331_MSLUT_2_WR            0x72
	#define TMC4331_MSLUT_3_WR            0x73
	#define TMC4331_MSLUT_4_WR            0x74
	#define TMC4331_MSLUT_5_WR            0x75
	#define TMC4331_MSLUT_6_WR            0x76
	#define TMC4331_MSLUT_7_WR            0x77
	#define TMC4331_MSLUTSEL_WR           0x78
	#define TMC4331_MSCNT_RD              0x79
	#define TMC4331_MSOFFSET_WR           0x79
	#define TMC4331_CURRENTA_RD           0x7A
	#define TMC4331_CURRENTB_RD           0x7A
	#define TMC4331_CURRENTA_SPI_RD       0x7B
	#define TMC4331_CURRENTB_SPI_RD       0x7B
	#define TMC4331_TZEROWAIT_WR          0x7B
	#define TMC4331_SCALE_PARAM_RD        0x7C
	#define TMC4331_CIRCULAR_DEC_WR       0x7C
	#define TMC4331_START_SIN_WR          0x7E
	#define TMC4331_START_SIN90_120_WR    0x7E
	#define TMC4331_DAC_OFFSET_WR         0x7E
	#define TMC4331_VERSION_NO_RD         0x7F

	#define TMC4331_COVER_DONE  (1<<25)

	#define TMC4331_RAMP_HOLD      0
	#define TMC4331_RAMP_TRAPEZ    1
	#define TMC4331_RAMP_SSHAPE    2
	#define TMC4331_RAMP_POSITION  4
	#define TMC4331_RAMP_HOLD      0

	// Write-Bit
	#define TMC4331_WRITE 0x80

	//TMC4331 GENERAL_CONFIG Bits
	#define TMC4331_GCONF_USE_AVSTART                  0x00000001
	#define TMC4331_GCONF_DIRECT_ACC_EN                0x00000002
	#define TMC4331_GCONF_DIRECT_BOW_EN                0x00000004
	#define TMC4331_GCONF_STEP_INACT_POL               0x00000008
	#define TMC4331_GCONF_TOGGLE_STEP                  0x00000010
	#define TMC4331_GCONF_POL_DIR_OUT                  0x00000020
	#define TMC4331_GCONF_INT_SD                       0x00000000
	#define TMC4331_GCONF_EXT_SD_HIGH                  0x00000040
	#define TMC4331_GCONF_EXT_SD_LOW                   0x00000080
	#define TMC4331_GCONF_EXT_SD_TOGGLE                0x000000C0
	#define TMC4331_GCONF_DIR_IN_POL                   0x00000100
	#define TMC4331_GCONF_SD_INDIRECT                  0x00000200
	#define TMC4331_GCONF_ENC_INC                      0x00000000
	#define TMC4331_GCONF_ENC_SSI                      0x00000400
	#define TMC4331_GCONF_ENC_BISS                     0x00000800
	#define TMC4331_GCONF_ENC_SPI                      0x00000C00
	#define TMC4331_GCONF_ENC_DIFF_DIS                 0x00001000
	#define TMC4331_GCONF_STDBY_CLOCK_LOW              0x00000000
	#define TMC4331_GCONF_STDBY_CLOCK_HIGH             0x00002000
	#define TMC4331_GCONF_STDBY_CHOPSYNC               0x00004000
	#define TMC4331_GCONF_STDBY_CLOCK_INT              0x00006000
	#define TMC4331_GCONF_INTR_POL                     0x00008000
	#define TMC4331_GCONF_TARGET_REACHED_POL           0x00010000
	#define TMC4331_GCONF_CLK_GATING_EN                0x00020000
	#define TMC4331_GCONF_CLK_GATING_STDBY_EN          0x00040000
	#define TMC4331_GCONF_FS_EN                        0x00080000
	#define TMC4331_GCONF_FS_SDOUT                     0x00100000
	#define TMC4331_GCONF_DCSTEP_OFF                   0x00000000
	#define TMC4331_GCONF_DCSTEP_AUTO                  0x00200000
	#define TMC4331_GCONF_DCSTEP_TMC21xx               0x00400000
	#define TMC4331_GCONF_DCSTEP_TMC26x                0x00600000
	#define TMC4331_GCONF_PWM_OUT_EN                   0x00800000
	#define TMC4331_GCONF_SER_ENC_OUT_EN               0x01000000
	#define TMC4331_GCONF_SER_ENC_OUT_DIFF             0x02000000
	#define TMC4331_GCONF_AUTO_DIRECT_SD_OFF           0x04000000
	#define TMC4331_GCONF_CIRC_CNT_XLATCH              0x08000000
	#define TMC4331_GCONF_REV_DIR                      0x10000000
	#define TMC4331_GCONF_INTR_TR_PU_PD_EN             0x20000000
	#define TMC4331_GCONF_INTR_WIRED_AND               0x40000000
	#define TMC4331_GCONF_TR_WIRED_AND                 0x80000000

	//TMC4331_SPI_OUT_CONF bits
	#define TMC4331_SPIOUT_OFF                         0x00000000
	#define TMC4331_SPIOUT_TMC23x                      0x00000008
	#define TMC4331_SPIOUT_TMC24x                      0x00000009
	#define TMC4331_SPIOUT_TMC26x_389                  0x0000000A
	#define TMC4331_SPIOUT_TMC26x_389_SD               0x0000000B
	#define TMC4331_SPIOUT_TMC21xx_SD                  0x0000000C
	#define TMC4331_SPIOUT_TMC21xx                     0x0000000D
	#define TMC4331_SPIOUT_SCALE                       0x00000004
	#define TMC4331_SPIOUT_SINLUT                      0x00000005
	#define TMC4331_SPIOUT_DACADDR                     0x00000006
	#define TMC4331_SPIOUT_DAC                         0x00000002
	#define TMC4331_SPIOUT_DAC_INV                     0x00000003
	#define TMC4331_SPIOUT_DAC_MAPPED                  0x00000001
	#define TMC4331_SPIOUT_COVER_ONLY                  0x0000000F
	#define TMC4331_SPIOUT_MD_OFF                      0x00000000
	#define TMC4331_SPIOUT_MD_FALLING                  0x00000010
	#define TMC4331_SPIOUT_MD_NO_STANDBY               0x00000020
	#define TMC4331_SPIOUT_MD_ALWAYS                   0x00000030
	#define TMC4331_SPIOUT_STDBY_ON_STALL              0x00000040
	#define TMC4331_SPIOUT_STALL_FLAG                  0x00000080
	#define TMC4331_STALL_LOAD_LIMIT(x)                ((x & 0x07) << 8)
	#define TMC4331_SPIOUT_PHASE_SHIFT                 0x00000100
	#define TMC4331_SPIOUT_THREE_PHASE_EN              0x00000010
	#define TMC4331_SPIOUT_SCALE_VAL_TR_EN             0x00000020
	#define TMC4331_SPIOUT_DISABLE_POLLING             0x00000040
	#define TMC4331_SPIOUT_ENABLE_SHADOW_DATAGRAMS     0x00000080
	#define TMC4331_SPIOUT_POLL_BLOCK_MULTI(x)         (((x) & 0x0F) << 8)
	#define TMC4331_SPIOUT_COVER_DONE_NOT_FOR_CURRENT  0x00001000

	//TMC4331 ENC_IN configuration bits
	#define TMC4331_ENC_IN_CONF               0x00000007
	#define TMC4331_ENC_IN_MODE_OL            0x00000000
	#define TMC4331_ENC_IN_MODE_CL            0x00400000
	#define TMC4331_ENC_IN_MODE_PID_0         0x00800000
	#define TMC4331_ENC_IN_MODE PID_V         0x00C00000
	#define TMC4331_ENC_IN_CL_CALIBRATION_EN  0x01000000
	#define TMC4331_ENC_IN_CL_EMF_EN          0x02000000
	#define TMC4331_ENC_IN_CL_VLIMIT_EN       0x08000000
	#define TMC4331_ENC_IN_CL_VELOCITY_EN     0x10000000
	#define TMC4331_ENC_IN_SER_VAR_LIMIT      0x80000000

	//TMC4331_CURRENT_CONF bits
	#define TMC4331_CURCONF_HOLD_EN          0x00000001
	#define TMC4331_CURCONF_DRIVE_EN         0x00000002
	#define TMC4331_CURCONF_BOOST_ACC_EN     0x00000004
	#define TMC4331_CURCONF_BOOST_DEC_EN     0x00000008
	#define TMC4331_CURCONF_BOOST_START_EN   0x00000010
	#define TMC4331_CURCONF_SEC_DRIVE_EN     0x00000020
	#define TMC4331_CURCONF_FREEWHEELING_EN  0x00000040
	#define TMC4331_CURCONF_CL_SCALE_EN      0x00000080
	#define TMC4331_CURCONF_PWM_SCALE_REF    0x00000100
	#define TMC4331_CURCONF_PWM_AMPL(x)      (x<<16)

	//TMC4331_SCALE_VALUES bits
	#define TMC4331_SCALEVAL_BOOST(x)  (x & 0xFF)
	#define TMC4331_SCALEVAL_DRV1(x)   ((x & 0xFF) << 8)
	#define TMC4331_SCALEVAL_DRV2(x)   ((x & 0xFF) << 16)
	#define TMC4331_SCALEVAL_HOLD(x)   ((x & 0xFF) << 24)

	//TMC4331_EVENTS register bits
	#define TMC4331_EV_TARGET_REACHED     0x00000001
	#define TMC4331_EV_POSCOMP_REACHED    0x00000002
	#define TMC4331_EV_VELOCITY_REACHED   0x00000004
	#define TMC4331_EV_VZERO              0x00000008
	#define TMC4331_EV_VPOSITIVE          0x00000010
	#define TMC4331_EV_VNEGATIVE          0x00000020
	#define TMC4331_EV_AZERO              0x00000040
	#define TMC4331_EV_APOSITIVE          0x00000080
	#define TMC4331_EV_ANEGATIVE          0x00000100
	#define TMC4331_EV_MAX_PHASE_TRAP     0x00000200
	#define TMC4331_EV_FROZEN             0x00000400
	#define TMC4331_EV_STOP_LEFT          0x00000800
	#define TMC4331_EV_STOP_RIGHT         0x00001000
	#define TMC4331_EV_VIRT_STOP_LEFT     0x00002000
	#define TMC4331_EV_VIRT_STOP_RIGHT    0x00004000
	#define TMC4331_EV_HOME_ERROR         0x00008000
	#define TMC4331_EV_XLATCH_DONE        0x00010000
	#define TMC4331_EV_FS_ACTIVE          0x00020000
	#define TMC4331_EV_ENC_FAIL           0x00040000
	#define TMC4331_EV_N_ACTIVE           0x00080000
	#define TMC4331_EV_ENC_DONE           0x00100000
	#define TMC4331_EV_SER_ENC_DATA_FAIL  0x00200000
	#define TMC4331_EV_CRC_FAIL           0x00400000
	#define TMC4331_EV_SER_DATA_DONE      0x00800000
	#define TMC4331_EV_BISS_FLAG          0x01000000
	#define TMC4331_EV_COVER_DONE         0x02000000
	#define TMC4331_EV_ENC_VZERO          0x04000000
	#define TMC4331_EV_CL_MAX             0x08000000
	#define TMC4331_EV_CL_FIT             0x10000000
	#define TMC4331_EV_STOP_ON_STALL      0x20000000
	#define TMC4331_EV_MOTOR              0x40000000
	#define TMC4331_EV_RST                0x80000000

	//TMC4331_STATUS register bits
	#define TMC4331_ST_TARGET_REACHED          0x00000001
	#define TMC4331_ST_POSCOMP_REACHED         0x00000002
	#define TMC4331_ST_VEL_REACHED             0x00000004
	#define TMC4331_ST_VEL_POS                 0x00000008
	#define TMC4331_ST_VEL_NEG                 0x00000010
	#define TMC4331_ST_RAMP_ACC                0x00000020
	#define TMC4331_ST_RAMP_DEC                0x00000040
	#define TMC4331_ST_STOP_LEFT_ACTIVE        0x00000080
	#define TMC4331_ST_STOP_RIGHT_ACTIVE       0x00000100
	#define TMC4331_ST_VIRT_STOP_LEFT_ACTIVE   0x00000200
	#define TMC4331_ST_VIRT_STOP_RIGHT_ACTIVE  0x00000400
	#define TMC4331_ST_HOME_ERROR              0x00001000
	#define TMC4331_ST_ENC_FAIL                0x00004000

	//TMC4331 ramp modes
	#define TMC4331_RAMPMODE_VEL_HOLD    0
	#define TMC4331_RAMPMODE_VEL_TRAPEZ  1
	#define TMC4331_RAMPMODE_VEL_SSHAPE  2
	#define TMC4331_RAMPMODE_POS_HOLD    4
	#define TMC4331_RAMPMODE_POS_TRAPEZ  5
	#define TMC4331_RAMPMODE_POS_SSHAPE  6

	//TMC4331 reference switch configuration
	#define TMC4331_REFCONF_STOP_LEFT_EN       0x00000001
	#define TMC4331_REFCONF_STOP_RIGHT_EN      0x00000002
	#define TMC4331_REFCONF_POL_STOP_LEFT      0x00000004
	#define TMC4331_REFCONF_POL_STOP_RIGHT     0x00000008
	#define TMC4331_REFCONF_INV_STOP_DIR       0x00000010
	#define TMC4331_REFCONF_SOFT_STOP_EN       0x00000020
	#define TMC4331_REFCONF_VIRT_LEFT_LIM_EN   0x00000040
	#define TMC4331_REFCONF_VIRT_RIGHT_LIM_EN  0x00000080
	#define TMC4331_REFCONF_VIRT_STOP_HARD     0x00000100
	#define TMC4331_REFCONF_VIRT_STOP_LINEAR   0x00000200
	#define TMC4331_REFCONF_CIRCULAR           0x00400000
	#define TMC4331_REFCONF_STOP_ON_STALL      0x04000000
	#define TMC4331_REFCONF_DRV_AFTER_STALL    0x08000000
	#define TMC4331_REFCONF_CIRCULAR_ENC_EN    0x80000000

#endif /* TMC4331_REGISTER_H */
