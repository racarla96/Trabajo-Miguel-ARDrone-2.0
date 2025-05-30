/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Example_Getting_Started_UDP.c
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

#include "Example_Getting_Started_UDP.h"
#include "Example_Getting_Started_UDP_private.h"
#include "Example_Getting_Started_UDP_dt.h"

/* Block signals (auto storage) */
B_Example_Getting_Started_UDP_T Example_Getting_Started_UDP_B;

/* Block states (auto storage) */
DW_Example_Getting_Started_UDP_T Example_Getting_Started_UDP_DW;

/* Real-time model */
RT_MODEL_Example_Getting_Started_UDP_T Example_Getting_Started_UDP_M_;
RT_MODEL_Example_Getting_Started_UDP_T *const Example_Getting_Started_UDP_M =
  &Example_Getting_Started_UDP_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Example_Getting_Started_UDP_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Example_Getting_Started_UDP_M, 1));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Example_Getting_Started_UDP_M->Timing.TaskCounters.TID[1])++;
  if ((Example_Getting_Started_UDP_M->Timing.TaskCounters.TID[1]) > 79) {/* Sample time: [0.2s, 0.0s] */
    Example_Getting_Started_UDP_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void Example_Getting_Started_UDP_step0(void) /* Sample time: [0.0025s, 0.0s] */
{
  {                                    /* Sample time: [0.0025s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, Example_Getting_Started_UDP_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0025s, 0.0s] */
    if ((rtmGetTFinal(Example_Getting_Started_UDP_M)!=-1) &&
        !((rtmGetTFinal(Example_Getting_Started_UDP_M)-
           Example_Getting_Started_UDP_M->Timing.taskTime0) >
          Example_Getting_Started_UDP_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Example_Getting_Started_UDP_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Example_Getting_Started_UDP_M)) {
      rtmSetErrorStatus(Example_Getting_Started_UDP_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Example_Getting_Started_UDP_M->Timing.taskTime0 =
    (++Example_Getting_Started_UDP_M->Timing.clockTick0) *
    Example_Getting_Started_UDP_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void Example_Getting_Started_UDP_step1(void) /* Sample time: [0.2s, 0.0s] */
{
  /* S-Function (UDP_Recv_Sfcn): '<Root>/S-Function' */
  Example_Getting_Started_UDP_B.SFunction_o1 = udp_recv
    (Example_Getting_Started_UDP_P.Port_Value,
     Example_Getting_Started_UDP_P.BlockingTimeus_Value,
     &Example_Getting_Started_UDP_B.SFunction_o2[0]);

  /* S-Function (Version_Check): '<Root>/Version Check' */
  versionCheckStep(&Example_Getting_Started_UDP_B.VersionCheck);
  rtExtModeUpload(1, ((Example_Getting_Started_UDP_M->Timing.clockTick1) * 0.2));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.2, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Example_Getting_Started_UDP_M->Timing.clockTick1++;
}

/* Model step wrapper function for compatibility with a static main program */
void Example_Getting_Started_UDP_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Example_Getting_Started_UDP_step0();
    break;

   case 1 :
    Example_Getting_Started_UDP_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Example_Getting_Started_UDP_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Example_Getting_Started_UDP_M, 0,
                sizeof(RT_MODEL_Example_Getting_Started_UDP_T));
  rtmSetTFinal(Example_Getting_Started_UDP_M, -1);
  Example_Getting_Started_UDP_M->Timing.stepSize0 = 0.0025;

  /* External mode info */
  Example_Getting_Started_UDP_M->Sizes.checksums[0] = (4216178221U);
  Example_Getting_Started_UDP_M->Sizes.checksums[1] = (1866367953U);
  Example_Getting_Started_UDP_M->Sizes.checksums[2] = (2888383374U);
  Example_Getting_Started_UDP_M->Sizes.checksums[3] = (2624924003U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Example_Getting_Started_UDP_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Example_Getting_Started_UDP_M->extModeInfo,
      &Example_Getting_Started_UDP_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Example_Getting_Started_UDP_M->extModeInfo,
                        Example_Getting_Started_UDP_M->Sizes.checksums);
    rteiSetTPtr(Example_Getting_Started_UDP_M->extModeInfo, rtmGetTPtr
                (Example_Getting_Started_UDP_M));
  }

  /* block I/O */
  (void) memset(((void *) &Example_Getting_Started_UDP_B), 0,
                sizeof(B_Example_Getting_Started_UDP_T));

  /* states (dwork) */
  (void) memset((void *)&Example_Getting_Started_UDP_DW, 0,
                sizeof(DW_Example_Getting_Started_UDP_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Example_Getting_Started_UDP_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for S-Function (Version_Check): '<Root>/Version Check' */
  versionCheckInit();
}

/* Model terminate function */
void Example_Getting_Started_UDP_terminate(void)
{
  /* Terminate for S-Function (UDP_Recv_Sfcn): '<Root>/S-Function' */
  udp_recv_close();

  /* Terminate for S-Function (Version_Check): '<Root>/Version Check' */
  versionCheckClose();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
