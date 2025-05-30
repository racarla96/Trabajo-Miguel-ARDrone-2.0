/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Free_Flight_PID_RPY_Sen_data.c
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

#include "Free_Flight_PID_RPY_Sen.h"
#include "Free_Flight_PID_RPY_Sen_private.h"

/* Block parameters (auto storage) */
P_Free_Flight_PID_RPY_Sen_T Free_Flight_PID_RPY_Sen_P = {
  /*  Variable: accelerometerXyzGains
   * Referenced by: '<S31>/Acclerometer Calibration Gains'
   */
  { 512.0, 512.0, 512.0 },

  /*  Variable: accelerometerXyzOffsets
   * Referenced by: '<S31>/Acclerometer Calibration Offsets'
   */
  { 2048.0, 2048.0, 2048.0 },

  /*  Variable: gyroXyzOffsets
   * Referenced by: '<S29>/Constant'
   */
  { 0.0, 0.0, 0.0 },
  -0.04,                               /* Mask Parameter: PIDRP_D
                                        * Referenced by: '<S6>/Derivative Gain'
                                        */
  0.3,                                 /* Mask Parameter: PIDRP_I
                                        * Referenced by: '<S6>/Integral Gain'
                                        */
  -30.0,                               /* Mask Parameter: PIDRP_LowerSaturationLimit
                                        * Referenced by:
                                        *   '<S6>/Saturate'
                                        *   '<S11>/DeadZone'
                                        */
  5.0,                                 /* Mask Parameter: PIDRP_N
                                        * Referenced by: '<S6>/Filter Coefficient'
                                        */
  0.5,                                 /* Mask Parameter: PIDRP_P
                                        * Referenced by: '<S6>/Proportional Gain'
                                        */
  30.0,                                /* Mask Parameter: PIDRP_UpperSaturationLimit
                                        * Referenced by:
                                        *   '<S6>/Saturate'
                                        *   '<S11>/DeadZone'
                                        */
  0.0,                                 /* Mask Parameter: NormalizeVector_maxzero
                                        * Referenced by: '<S33>/Switch'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Cero'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Uno'
                                        */
  0.01,                                /* Expression: 0.01
                                        * Referenced by: '<S8>/Kd'
                                        */
  0.15,                                /* Expression: 0.15
                                        * Referenced by: '<S8>/Kp'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S33>/Constant'
                                        */
  35.0,                                /* Expression: 35
                                        * Referenced by: '<Root>/Empuje'
                                        */
  15.0,                                /* Expression: 15
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  0.001249999674479192,                /* Computed Parameter: Roll_sin_Hsin
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  0.99999921875010167,                 /* Computed Parameter: Roll_sin_HCos
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  -0.84214570511523079,                /* Computed Parameter: Roll_sin_PSin
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  0.53925004529992471,                 /* Computed Parameter: Roll_sin_PCos
                                        * Referenced by: '<Root>/Roll_sin'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Yaw'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Switch'
                                        */
  15.0,                                /* Expression: 15
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  0.5,                                 /* Expression: 0.5
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  0.001249999674479192,                /* Computed Parameter: Pitch_sin_Hsin
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  0.99999921875010167,                 /* Computed Parameter: Pitch_sin_HCos
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  -0.84214570511523079,                /* Computed Parameter: Pitch_sin_PSin
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  0.53925004529992471,                 /* Computed Parameter: Pitch_sin_PCos
                                        * Referenced by: '<Root>/Pitch_sin'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Switch1'
                                        */

  /*  Expression: [0 0]'
   * Referenced by: '<S21>/Unit Delay1'
   */
  { 0.0, 0.0 },

  /*  Expression: eye(2)
   * Referenced by: '<S21>/Unit Delay'
   */
  { 1.0, 0.0, 0.0, 1.0 },

  /*  Expression: [0.0609, 0.0609, 0.0609]
   * Referenced by: '<S36>/Gain'
   */
  { 0.0609, 0.0609, 0.0609 },
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S31>/Invert Axes Definition'
                                        */
  0.2,                                 /* Expression: 0.2
                                        * Referenced by: '<S32>/Gain1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S32>/Unit Delay'
                                        */
  0.8,                                 /* Expression: 0.8
                                        * Referenced by: '<S32>/Gain'
                                        */
  57.295779513082323,                  /* Expression: 180/pi
                                        * Referenced by: '<S19>/Gain4'
                                        */

  /*  Expression: [0 0]'
   * Referenced by: '<S20>/Unit Delay1'
   */
  { 0.0, 0.0 },

  /*  Expression: eye(2)
   * Referenced by: '<S20>/Unit Delay'
   */
  { 1.0, 0.0, 0.0, 1.0 },
  -57.295779513082323,                 /* Expression: -180/pi
                                        * Referenced by: '<S19>/Gain5'
                                        */
  0.0025,                              /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                        * Referenced by: '<S14>/Discrete-Time Integrator1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S14>/Discrete-Time Integrator1'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S14>/Change Sign'
                                        */

  /*  Expression: [20 20]
   * Referenced by: '<S1>/sat_err'
   */
  { 20.0, 20.0 },

  /*  Expression: [-20 -20]
   * Referenced by: '<S1>/sat_err'
   */
  { -20.0, -20.0 },

  /*  Expression: [-5.2 -5.2]
   * Referenced by: '<S1>/Ganancia'
   */
  { -5.2, -5.2 },
  0.07553,                             /* Expression: [0.07553]
                                        * Referenced by: '<S1>/Filtro_vel'
                                        */

  /*  Expression: [1 -0.9245]
   * Referenced by: '<S1>/Filtro_vel'
   */
  { 1.0, -0.9245 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Filtro_vel'
                                        */
  0.0025,                              /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S6>/Integrator'
                                        */
  0.0,                                 /* Expression: InitialConditionForIntegrator
                                        * Referenced by: '<S6>/Integrator'
                                        */
  0.0025,                              /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S6>/Filter'
                                        */
  0.0,                                 /* Expression: InitialConditionForFilter
                                        * Referenced by: '<S6>/Filter'
                                        */
  30.0,                                /* Expression: 30
                                        * Referenced by: '<S1>/sat_err1'
                                        */
  -30.0,                               /* Expression: -30
                                        * Referenced by: '<S1>/sat_err1'
                                        */
  0.00025,                             /* Computed Parameter: Ki_gainval
                                        * Referenced by: '<S8>/Ki'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S8>/Ki'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<S8>/Ki'
                                        */
  -10.0,                               /* Expression: -10
                                        * Referenced by: '<S8>/Ki'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<S1>/Reloj'
                                        */
  40.0,                                /* Computed Parameter: Reloj_Period
                                        * Referenced by: '<S1>/Reloj'
                                        */
  20.0,                                /* Computed Parameter: Reloj_Duty
                                        * Referenced by: '<S1>/Reloj'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Reloj'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S11>/ZeroGain'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  50000.0,                             /* Expression: 50000
                                        * Referenced by: '<S1>/Blocking Time (us)'
                                        */

  /*  Expression: eye(2)
   * Referenced by: '<S18>/Unit Delay2'
   */
  { 1.0, 0.0, 0.0, 1.0 },

  /*  Expression: [0 0 ]
   * Referenced by: '<S18>/Unit Delay1'
   */
  { 0.0, 0.0 },
  15200,                               /* Computed Parameter: Port_Value
                                        * Referenced by: '<S1>/Port'
                                        */

  /*  Computed Parameter: Paro_Value
   * Referenced by: '<S1>/Paro'
   */
  { 0, 0, 0, 0 },
  10,                                  /* Computed Parameter: minThrottle_Value
                                        * Referenced by: '<S1>/minThrottle'
                                        */

  /*  Computed Parameter: MotorMixing_Gain
   * Referenced by: '<S1>/MotorMixing'
   */
  { 1, 1, 1, 1, 1, -1, -1, 1, -1, -1, 1, 1, -1, 1, -1, 1 },
  100,                                 /* Computed Parameter: maxThrottle_Value
                                        * Referenced by: '<S1>/maxThrottle'
                                        */
  100,                                 /* Computed Parameter: Saturation_UpperSat
                                        * Referenced by: '<S3>/Saturation'
                                        */
  0,                                   /* Computed Parameter: Saturation_LowerSat
                                        * Referenced by: '<S3>/Saturation'
                                        */
  511U,                                /* Expression: BitMask
                                        * Referenced by: '<S3>/Bitwise Operator'
                                        */
  32U,                                 /* Expression: BitMask
                                        * Referenced by: '<S3>/Bitwise Operator1'
                                        */
  20931,                               /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S3>/Gain'
                                        */
  0U                                   /* Computed Parameter: Conm_CurrentSetting
                                        * Referenced by: '<Root>/Conm'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
