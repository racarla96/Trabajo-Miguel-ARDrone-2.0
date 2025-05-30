/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Free_Flight_PID_RPY_Sen_types.h
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

#ifndef RTW_HEADER_Free_Flight_PID_RPY_Sen_types_h_
#define RTW_HEADER_Free_Flight_PID_RPY_Sen_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "IMU_Navdata.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_5JPrVIIyMJvsnF3ilQUpkH_
#define DEFINED_TYPEDEF_FOR_struct_5JPrVIIyMJvsnF3ilQUpkH_

typedef struct {
  real_T Gain_X;
  real_T Gain_Y;
  real_T Gain_Z;
} struct_5JPrVIIyMJvsnF3ilQUpkH;

#endif

/* Parameters (auto storage) */
typedef struct P_Free_Flight_PID_RPY_Sen_T_ P_Free_Flight_PID_RPY_Sen_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Free_Flight_PID_RPY_Sen_T
  RT_MODEL_Free_Flight_PID_RPY_Sen_T;

#endif                                 /* RTW_HEADER_Free_Flight_PID_RPY_Sen_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
