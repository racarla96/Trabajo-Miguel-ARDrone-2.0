/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Example_Getting_Started_UDP.h
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

#ifndef RTW_HEADER_Example_Getting_Started_UDP_h_
#define RTW_HEADER_Example_Getting_Started_UDP_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Example_Getting_Started_UDP_COMMON_INCLUDES_
# define Example_Getting_Started_UDP_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "udp_recv.h"
#include "udp.h"
#include "versionCheck.h"
#endif                                 /* Example_Getting_Started_UDP_COMMON_INCLUDES_ */

#include "Example_Getting_Started_UDP_types.h"

/* Shared type includes */
#include "multiword_types.h"

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
  int32_T SFunction_o1;                /* '<Root>/S-Function' */
  uint8_T SFunction_o2[32];            /* '<Root>/S-Function' */
  uint8_T VersionCheck;                /* '<Root>/Version Check' */
} B_Example_Getting_Started_UDP_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_Example_Getting_Started_UDP_T;

/* Parameters (auto storage) */
struct P_Example_Getting_Started_UDP_T_ {
  real_T BlockingTimeus_Value;         /* Expression: 50000
                                        * Referenced by: '<Root>/Blocking Time (us)'
                                        */
  int32_T Port_Value;                  /* Computed Parameter: Port_Value
                                        * Referenced by: '<Root>/Port'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Example_Getting_Started_UDP_T {
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
extern P_Example_Getting_Started_UDP_T Example_Getting_Started_UDP_P;

/* Block signals (auto storage) */
extern B_Example_Getting_Started_UDP_T Example_Getting_Started_UDP_B;

/* Block states (auto storage) */
extern DW_Example_Getting_Started_UDP_T Example_Getting_Started_UDP_DW;

/* External function called from main */
extern void Example_Getting_Started_UDP_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void Example_Getting_Started_UDP_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void Example_Getting_Started_UDP_initialize(void);
extern void Example_Getting_Started_UDP_step(int_T tid);
extern void Example_Getting_Started_UDP_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Example_Getting_Started_UDP_T *const
  Example_Getting_Started_UDP_M;

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
 * '<Root>' : 'Example_Getting_Started_UDP'
 */
#endif                                 /* RTW_HEADER_Example_Getting_Started_UDP_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
