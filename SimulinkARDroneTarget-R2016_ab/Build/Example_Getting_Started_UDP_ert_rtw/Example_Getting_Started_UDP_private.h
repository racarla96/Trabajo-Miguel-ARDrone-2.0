/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Example_Getting_Started_UDP_private.h
 *
 * Code generated for Simulink model 'Example_Getting_Started_UDP'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 8.11 (R2016b) 25-Aug-2016
 * C/C++ source code generated on : Fri Apr 29 10:42:17 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_Example_Getting_Started_UDP_private_h_
#define RTW_HEADER_Example_Getting_Started_UDP_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "Example_Getting_Started_UDP.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void Example_Getting_Started_UDP_step0(void);
extern void Example_Getting_Started_UDP_step1(void);

#endif                                 /* RTW_HEADER_Example_Getting_Started_UDP_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
