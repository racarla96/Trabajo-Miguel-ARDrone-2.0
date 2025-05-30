/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Free_Flight_PID_RPY_Sen.h
 *
 * Code generated for Simulink model 'Free_Flight_PID_RPY_Sen'.
 *
 * Model version                  : 1.1047
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Apr 29 11:49:28 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Free_Flight_PID_RPY_Sen_h_
#define RTW_HEADER_Free_Flight_PID_RPY_Sen_h_
#include <string.h>
#include <math.h>
#include <float.h>
#include <stddef.h>
#ifndef Free_Flight_PID_RPY_Sen_COMMON_INCLUDES_
# define Free_Flight_PID_RPY_Sen_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "IMU_Navdata.h"
#include "motor.h"
#include "udp_recv.h"
#include "udp.h"
#include "act_init.h"
#include "HostLib_Network.h"
#endif                                 /* Free_Flight_PID_RPY_Sen_COMMON_INCLUDES_ */

#include "Free_Flight_PID_RPY_Sen_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_zcfcn.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (auto storage) */
typedef struct {
  IMU_Packets IMURead_o1;              /* '<S2>/IMU Read' */
  real_T TmpSignalConversionAtWork_refInport1[4];
  real_T covariance_prediction[4];
  real_T covariance_prediction_m[4];
  real_T covariance_prediction_[4];
  real_T a[4];
  real_T I[4];
  real_T Gain[3];                      /* '<S36>/Gain' */
  real_T ChangeSign[3];                /* '<S14>/Change Sign' */
  real_T ByteUnpack[4];                /* '<S1>/Byte Unpack' */
  real_T TmpSignalConversionAtUDPSend2Inport1[3];
  real_T Kalman_Gain[2];
  real_T Kalman_Gain_c[2];
  real_T IntegralGain[2];              /* '<S6>/Integral Gain' */
  real_T ZeroGain[2];                  /* '<S11>/ZeroGain' */
  real_T state_correction_j[2];        /* '<S21>/Kalman Tracker' */
  real_T state_correction_b[2];        /* '<S20>/Kalman Tracker' */
  real_T Empuje;                       /* '<Root>/Empuje' */
  real_T Yaw;                          /* '<Root>/Yaw' */
  real_T Switch;                       /* '<Root>/Switch' */
  real_T Switch1;                      /* '<Root>/Switch1' */
  real_T Conm;                         /* '<Root>/Conm' */
  real_T Sum2;                         /* '<S1>/Sum2' */
  real_T rtb_FilterCoefficient_k;
  real_T rtb_SignDeltaU_c;
  real_T rtb_DataTypeConversion_idx_0;
  real_T rtb_DataTypeConversion_idx_1;
  real_T rtb_DataTypeConversion_idx_2;
  real_T rtb_conv_idx_0;
  real_T rtb_conv_idx_1;
  real_T rtb_conv_idx_2;
  real_T u0;
  real_T d0;
  real_T d1;
  int32_T SFunction_o1;                /* '<S1>/S-Function' */
  int16_T Switch_d[4];                 /* '<S1>/Switch' */
  uint16_T ARDrone_Motor;              /* '<S3>/ARDrone_Motor' */
  uint8_T SFunction_o2[32];            /* '<S1>/S-Function' */
} B_Free_Flight_PID_RPY_Sen_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  IMU_Packets storedGoodPacket;        /* '<S4>/Verify IMU Data' */
  real_T UnitDelay1_DSTATE[2];         /* '<S21>/Unit Delay1' */
  real_T UnitDelay_DSTATE[4];          /* '<S21>/Unit Delay' */
  real_T UnitDelay_DSTATE_e[3];        /* '<S32>/Unit Delay' */
  real_T UnitDelay1_DSTATE_k[2];       /* '<S20>/Unit Delay1' */
  real_T UnitDelay_DSTATE_h[4];        /* '<S20>/Unit Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S14>/Discrete-Time Integrator1' */
  real_T Filtro_vel_states[3];         /* '<S1>/Filtro_vel' */
  real_T Integrator_DSTATE[2];         /* '<S6>/Integrator' */
  real_T Filter_DSTATE[2];             /* '<S6>/Filter' */
  real_T Ki_DSTATE;                    /* '<S8>/Ki' */
  real_T UnitDelay2_DSTATE[4];         /* '<S18>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_h[2];       /* '<S18>/Unit Delay1' */
  real_T lastSin;                      /* '<Root>/Roll_sin' */
  real_T lastCos;                      /* '<Root>/Roll_sin' */
  real_T lastSin_c;                    /* '<Root>/Pitch_sin' */
  real_T lastCos_b;                    /* '<Root>/Pitch_sin' */
  real_T validHeight;                  /* '<S15>/MATLAB Function' */
  real_T UDPSend2_NetworkLib[137];     /* '<S5>/UDP Send2' */
  struct {
    void *LoggedData;
  } Work_ang_PWORK;                    /* '<Root>/Work_ang' */

  struct {
    void *LoggedData;
  } Work_pwm_PWORK;                    /* '<Root>/Work_pwm' */

  struct {
    void *LoggedData;
  } Work_ref_PWORK;                    /* '<Root>/Work_ref' */

  struct {
    void *LoggedData;
  } Work_vel_PWORK;                    /* '<Root>/Work_vel' */

  int32_T systemEnable;                /* '<Root>/Roll_sin' */
  int32_T systemEnable_d;              /* '<Root>/Pitch_sin' */
  int32_T clockTickCounter;            /* '<S1>/Reloj' */
  uint16_T storedBadChecksum;          /* '<S4>/Verify IMU Data' */
  int8_T Integrator_PrevResetState;    /* '<S6>/Integrator' */
  int8_T Filter_PrevResetState;        /* '<S6>/Filter' */
  int8_T Ki_PrevResetState;            /* '<S8>/Ki' */
  int8_T Medidas_SubsysRanBC;          /* '<S1>/Medidas' */
  boolean_T storedGoodPacket_not_empty;/* '<S4>/Verify IMU Data' */
  boolean_T storedBadChecksum_not_empty;/* '<S4>/Verify IMU Data' */
} DW_Free_Flight_PID_RPY_Sen_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Medidas_Trig_ZCE;         /* '<S1>/Medidas' */
} PrevZCX_Free_Flight_PID_RPY_Sen_T;

/* Parameters (auto storage) */
struct P_Free_Flight_PID_RPY_Sen_T_ {
  real_T accelerometerXyzGains[3];     /* Variable: accelerometerXyzGains
                                        * Referenced by: '<S31>/Acclerometer Calibration Gains'
                                        */
  real_T accelerometerXyzOffsets[3];   /* Variable: accelerometerXyzOffsets
                                        * Referenced by: '<S31>/Acclerometer Calibration Offsets'
                                        */
  real_T gyroXyzOffsets[3];            /* Variable: gyroXyzOffsets
                                        * Referenced by: '<S29>/Constant'
                                        */
  real_T PIDRP_D;                      /* Mask Parameter: PIDRP_D
                                        * Referenced by: '<S6>/Derivative Gain'
                                        */
  real_T PIDRP_I;                      /* Mask Parameter: PIDRP_I
                                        * Referenced by: '<S6>/Integral Gain'
                                        */
  real_T PIDRP_LowerSaturationLimit;   /* Mask Parameter: PIDRP_LowerSaturationLimit
                                        * Referenced by:
                                        *   '<S6>/Saturate'
                                        *   '<S11>/DeadZone'
                                        */
  real_T PIDRP_N;                      /* Mask Parameter: PIDRP_N
                                        * Referenced by: '<S6>/Filter Coefficient'
                                        */
  real_T PIDRP_P;                      /* Mask Parameter: PIDRP_P
                                        * Referenced by: '<S6>/Proportional Gain'
                                        */
  real_T PIDRP_UpperSaturationLimit;   /* Mask Parameter: PIDRP_UpperSaturationLimit
                                        * Referenced by:
                                        *   '<S6>/Saturate'
                                        *   '<S11>/DeadZone'
                                        */
  real_T NormalizeVector_maxzero;      /* Mask Parameter: NormalizeVector_maxzero
                                        * Referenced by: '<S33>/Switch'
                                        */
  real_T Cero_Value;                   /* Expression: 0
                                        * Referenced by: '<Root>/Cero'
                                        */
  real_T Uno_Value;                    /* Expression: 1
                                        * Referenced by: '<Root>/Uno'
                                        */
  real_T Kd_Gain;                      /* Expression: 0.01
                                        * Referenced by: '<S8>/Kd'
                                        */
  real_T Kp_Gain;                      /* Expression: 0.15
                                        * Referenced by: '<S8>/Kp'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  real_T Empuje_Value;                 /* Expression: 35
                                        * Referenced by: '<Root>/Empuje'
                                        */
  real_T Roll_sin_Amp;                 /* Expression: 15
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  real_T Roll_sin_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  real_T Roll_sin_Freq;                /* Expression: 0.5
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  real_T Roll_sin_Hsin;                /* Computed Parameter: Roll_sin_Hsin
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  real_T Roll_sin_HCos;                /* Computed Parameter: Roll_sin_HCos
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  real_T Roll_sin_PSin;                /* Computed Parameter: Roll_sin_PSin
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  real_T Roll_sin_PCos;                /* Computed Parameter: Roll_sin_PCos
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  real_T Yaw_Value;                    /* Expression: 0
                                        * Referenced by: '<Root>/Yaw'
                                        */
  real_T Switch_Threshold;             /* Expression: 2
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Pitch_sin_Amp;                /* Expression: 15
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  real_T Pitch_sin_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  real_T Pitch_sin_Freq;               /* Expression: 0.5
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  real_T Pitch_sin_Hsin;               /* Computed Parameter: Pitch_sin_Hsin
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  real_T Pitch_sin_HCos;               /* Computed Parameter: Pitch_sin_HCos
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  real_T Pitch_sin_PSin;               /* Computed Parameter: Pitch_sin_PSin
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  real_T Pitch_sin_PCos;               /* Computed Parameter: Pitch_sin_PCos
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  real_T Switch1_Threshold;            /* Expression: 2
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T UnitDelay1_InitialCondition[2];/* Expression: [0 0]'
                                         * Referenced by: '<S21>/Unit Delay1'
                                         */
  real_T UnitDelay_InitialCondition[4];/* Expression: eye(2)
                                        * Referenced by: '<S21>/Unit Delay'
                                        */
  real_T Gain_Gain[3];                 /* Expression: [0.0609, 0.0609, 0.0609]
                                        * Referenced by: '<S36>/Gain'
                                        */
  real_T InvertAxesDefinition_Gain;    /* Expression: -1
                                        * Referenced by: '<S31>/Invert Axes Definition'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.2
                                        * Referenced by: '<S32>/Gain1'
                                        */
  real_T UnitDelay_InitialCondition_a; /* Expression: 0
                                        * Referenced by: '<S32>/Unit Delay'
                                        */
  real_T Gain_Gain_h;                  /* Expression: 0.8
                                        * Referenced by: '<S32>/Gain'
                                        */
  real_T Gain4_Gain;                   /* Expression: 180/pi
                                        * Referenced by: '<S19>/Gain4'
                                        */
  real_T UnitDelay1_InitialCondition_f[2];/* Expression: [0 0]'
                                           * Referenced by: '<S20>/Unit Delay1'
                                           */
  real_T UnitDelay_InitialCondition_k[4];/* Expression: eye(2)
                                          * Referenced by: '<S20>/Unit Delay'
                                          */
  real_T Gain5_Gain;                   /* Expression: -180/pi
                                        * Referenced by: '<S19>/Gain5'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S14>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S14>/Discrete-Time Integrator1'
                                        */
  real_T ChangeSign_Gain;              /* Expression: -1
                                        * Referenced by: '<S14>/Change Sign'
                                        */
  real_T sat_err_UpperSat[2];          /* Expression: [20 20]
                                        * Referenced by: '<S1>/sat_err'
                                        */
  real_T sat_err_LowerSat[2];          /* Expression: [-20 -20]
                                        * Referenced by: '<S1>/sat_err'
                                        */
  real_T Ganancia_Gain[2];             /* Expression: [-5.2 -5.2]
                                        * Referenced by: '<S1>/Ganancia'
                                        */
  real_T Filtro_vel_NumCoef;           /* Expression: [0.07553]
                                        * Referenced by: '<S1>/Filtro_vel'
                                        */
  real_T Filtro_vel_DenCoef[2];        /* Expression: [1 -0.9245]
                                        * Referenced by: '<S1>/Filtro_vel'
                                        */
  real_T Filtro_vel_InitialStates;     /* Expression: 0
                                        * Referenced by: '<S1>/Filtro_vel'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S6>/Integrator'
                                        */
  real_T Integrator_IC;                /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S6>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S6>/Filter'
                                        */
  real_T Filter_IC;                    /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S6>/Filter'
                                        */
  real_T sat_err1_UpperSat;            /* Expression: 30
                                        * Referenced by: '<S1>/sat_err1'
                                        */
  real_T sat_err1_LowerSat;            /* Expression: -30
                                        * Referenced by: '<S1>/sat_err1'
                                        */
  real_T Ki_gainval;                   /* Computed Parameter: Ki_gainval
                                        * Referenced by: '<S8>/Ki'
                                        */
  real_T Ki_IC;                        /* Expression: 0
                                        * Referenced by: '<S8>/Ki'
                                        */
  real_T Ki_UpperSat;                  /* Expression: 10
                                        * Referenced by: '<S8>/Ki'
                                        */
  real_T Ki_LowerSat;                  /* Expression: -10
                                        * Referenced by: '<S8>/Ki'
                                        */
  real_T Switch_Threshold_h;           /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Reloj_Amp;                    /* Expression: 1
                                        * Referenced by: '<S1>/Reloj'
                                        */
  real_T Reloj_Period;                 /* Computed Parameter: Reloj_Period
                                        * Referenced by: '<S1>/Reloj'
                                        */
  real_T Reloj_Duty;                   /* Computed Parameter: Reloj_Duty
                                        * Referenced by: '<S1>/Reloj'
                                        */
  real_T Reloj_PhaseDelay;             /* Expression: 0
                                        * Referenced by: '<S1>/Reloj'
                                        */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S11>/ZeroGain'
                                        */
  real_T Constant_Value_b;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T BlockingTimeus_Value;         /* Expression: 50000
                                        * Referenced by: '<S1>/Blocking Time (us)'
                                        */
  real_T UnitDelay2_InitialCondition[4];/* Expression: eye(2)
                                         * Referenced by: '<S18>/Unit Delay2'
                                         */
  real_T UnitDelay1_InitialCondition_d[2];/* Expression: [0 0 ]
                                           * Referenced by: '<S18>/Unit Delay1'
                                           */
  int32_T Port_Value;                  /* Computed Parameter: Port_Value
                                        * Referenced by: '<S1>/Port'
                                        */
  int16_T Paro_Value[4];               /* Computed Parameter: Paro_Value
                                        * Referenced by: '<S1>/Paro'
                                        */
  int16_T minThrottle_Value;           /* Computed Parameter: minThrottle_Value
                                        * Referenced by: '<S1>/minThrottle'
                                        */
  int16_T MotorMixing_Gain[16];        /* Computed Parameter: MotorMixing_Gain
                                        * Referenced by: '<S1>/MotorMixing'
                                        */
  int16_T maxThrottle_Value;           /* Computed Parameter: maxThrottle_Value
                                        * Referenced by: '<S1>/maxThrottle'
                                        */
  int16_T Saturation_UpperSat;         /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S3>/Saturation'
                                        */
  int16_T Saturation_LowerSat;         /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S3>/Saturation'
                                        */
  uint16_T BitwiseOperator_BitMask;    /* Expression: BitMask
                                        * Referenced by: '<S3>/Bitwise Operator'
                                        */
  uint16_T BitwiseOperator1_BitMask;   /* Expression: BitMask
                                        * Referenced by: '<S3>/Bitwise Operator1'
                                        */
  int16_T Gain_Gain_f;                 /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S3>/Gain'
                                        */
  uint8_T Conm_CurrentSetting;         /* Computed Parameter: Conm_CurrentSetting
                                        * Referenced by: '<Root>/Conm'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Free_Flight_PID_RPY_Sen_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Free_Flight_PID_RPY_Sen_T Free_Flight_PID_RPY_Sen_P;

/* Block signals (auto storage) */
extern B_Free_Flight_PID_RPY_Sen_T Free_Flight_PID_RPY_Sen_B;

/* Block states (auto storage) */
extern DW_Free_Flight_PID_RPY_Sen_T Free_Flight_PID_RPY_Sen_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_Free_Flight_PID_RPY_Sen_T Free_Flight_PID_RPY_Sen_PrevZCX;

/* External function called from main */
extern void Free_Flight_PID_RPY_Sen_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Free_Flight_PID_RPY_Sen_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void Free_Flight_PID_RPY_Sen_initialize(void);
extern void Free_Flight_PID_RPY_Sen_step(int_T tid);
extern void Free_Flight_PID_RPY_Sen_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Free_Flight_PID_RPY_Sen_T *const Free_Flight_PID_RPY_Sen_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Free_Flight_PID_RPY_Sen'
 * '<S1>'   : 'Free_Flight_PID_RPY_Sen/Control'
 * '<S2>'   : 'Free_Flight_PID_RPY_Sen/Inertial Measurement'
 * '<S3>'   : 'Free_Flight_PID_RPY_Sen/Motores'
 * '<S4>'   : 'Free_Flight_PID_RPY_Sen/Navigation System'
 * '<S5>'   : 'Free_Flight_PID_RPY_Sen/Control/Medidas'
 * '<S6>'   : 'Free_Flight_PID_RPY_Sen/Control/PID RP'
 * '<S7>'   : 'Free_Flight_PID_RPY_Sen/Control/PID RP2'
 * '<S8>'   : 'Free_Flight_PID_RPY_Sen/Control/PID Yaw'
 * '<S9>'   : 'Free_Flight_PID_RPY_Sen/Control/Saturation Dynamic'
 * '<S10>'  : 'Free_Flight_PID_RPY_Sen/Control/calc_empuje'
 * '<S11>'  : 'Free_Flight_PID_RPY_Sen/Control/PID RP/Clamping circuit'
 * '<S12>'  : 'Free_Flight_PID_RPY_Sen/Control/PID RP2/Clamping circuit'
 * '<S13>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Create Measurement Bus'
 * '<S14>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter'
 * '<S15>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction'
 * '<S16>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Verify IMU Data'
 * '<S17>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter/Compute Roll Pitch'
 * '<S18>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter/Ultrasound Estimator'
 * '<S19>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter/Compute Roll Pitch/Calculate Roll - Pitch'
 * '<S20>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter/Compute Roll Pitch/KF_PITCH'
 * '<S21>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter/Compute Roll Pitch/KF_ROLL'
 * '<S22>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter/Compute Roll Pitch/Seperate Data'
 * '<S23>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter/Compute Roll Pitch/Calculate Roll - Pitch/MATLAB Function'
 * '<S24>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter/Compute Roll Pitch/KF_PITCH/Kalman Tracker'
 * '<S25>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter/Compute Roll Pitch/KF_ROLL/Kalman Tracker'
 * '<S26>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Kalman Filter/Ultrasound Estimator/Kalman Tracker'
 * '<S27>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction/Accelerometer calibration'
 * '<S28>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction/Calibration_Scale_and_Offset'
 * '<S29>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction/Gyro offset'
 * '<S30>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction/MATLAB Function'
 * '<S31>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction/Accelerometer calibration/Apply calibration parameters'
 * '<S32>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction/Accelerometer calibration/Low pass filter'
 * '<S33>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction/Accelerometer calibration/Normalize Vector'
 * '<S34>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction/Calibration_Scale_and_Offset/Normalize Vector'
 * '<S35>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction/Calibration_Scale_and_Offset/Process Magnetometer'
 * '<S36>'  : 'Free_Flight_PID_RPY_Sen/Navigation System/Measurement calibration correction/Gyro offset/Process Raw Rate Gyro Data'
 */
#endif                                 /* RTW_HEADER_Free_Flight_PID_RPY_Sen_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
