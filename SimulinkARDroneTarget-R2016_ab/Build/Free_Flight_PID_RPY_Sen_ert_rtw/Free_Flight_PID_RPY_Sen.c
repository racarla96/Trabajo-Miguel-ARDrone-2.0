/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Free_Flight_PID_RPY_Sen.c
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
#include "Free_Flight_PID_RPY_Sen_dt.h"

/* Block signals (auto storage) */
B_Free_Flight_PID_RPY_Sen_T Free_Flight_PID_RPY_Sen_B;

/* Block states (auto storage) */
DW_Free_Flight_PID_RPY_Sen_T Free_Flight_PID_RPY_Sen_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Free_Flight_PID_RPY_Sen_T Free_Flight_PID_RPY_Sen_PrevZCX;

/* Real-time model */
RT_MODEL_Free_Flight_PID_RPY_Sen_T Free_Flight_PID_RPY_Sen_M_;
RT_MODEL_Free_Flight_PID_RPY_Sen_T *const Free_Flight_PID_RPY_Sen_M =
  &Free_Flight_PID_RPY_Sen_M_;

/* Forward declaration for local functions */
static real_T Free_Flight_PID_RPY_Sen_rt_powd_snf(real_T u0, real_T u1);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Free_Flight_PID_RPY_Sen_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Free_Flight_PID_RPY_Sen_M, 1));
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
  (Free_Flight_PID_RPY_Sen_M->Timing.TaskCounters.TID[1])++;
  if ((Free_Flight_PID_RPY_Sen_M->Timing.TaskCounters.TID[1]) > 39) {/* Sample time: [0.1s, 0.0s] */
    Free_Flight_PID_RPY_Sen_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static real_T Free_Flight_PID_RPY_Sen_rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    Free_Flight_PID_RPY_Sen_B.d0 = fabs(u0);
    Free_Flight_PID_RPY_Sen_B.d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (Free_Flight_PID_RPY_Sen_B.d0 == 1.0) {
        y = (rtNaN);
      } else if (Free_Flight_PID_RPY_Sen_B.d0 > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (Free_Flight_PID_RPY_Sen_B.d1 == 0.0) {
      y = 1.0;
    } else if (Free_Flight_PID_RPY_Sen_B.d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model step function for TID0 */
void Free_Flight_PID_RPY_Sen_step0(void) /* Sample time: [0.0025s, 0.0s] */
{
  /* local block i/o variables */
  int32_T rtb_IMURead_o2;
  uint8_T rtb_DataTypeConversion3[5];
  boolean_T b_p;
  int8_T I[4];
  int32_T k;
  static const real_T Q[4] = { 0.0001, 0.0, 0.0, 0.0001 };

  static const real_T a[4] = { 1.0, 0.0, -0.0025, 1.0 };

  static const real_T b_a[4] = { 0.0025, 0.0, 0.0, 0.0 };

  int8_T I_0[4];
  static const real_T Q_0[4] = { 0.0001, 0.0, 0.0, 0.0001 };

  static const real_T a_0[4] = { 1.0, 0.0, -0.0025, 1.0 };

  static const real_T b_a_0[4] = { 0.0025, 0.0, 0.0, 0.0 };

  char_T *sErr;
  int8_T I_1[4];
  static const real_T a_1[4] = { 1.0, 0.0, 0.0025, 1.0 };

  static const real_T Q_1[4] = { 0.0001, 0.0, 0.0, 0.0001 };

  boolean_T rtb_u;
  ZCEventType zcEvent;
  int16_T rtb_validImuData_vx;
  int16_T rtb_validImuData_vy;
  int16_T rtb_validImuData_vz;
  uint16_T rtb_validImuData_ultrasound;
  int16_T rtb_DataTypeConversion5_idx_0;
  uint16_T rtb_BitwiseOperator_idx_0;
  uint16_T rtb_BitwiseOperator_idx_1;
  uint16_T rtb_BitwiseOperator_idx_2;
  uint16_T rtb_BitwiseOperator_idx_3;
  int8_T rtb_SignDeltaU_0;
  int16_T rtb_MotorMixing;

  {                                    /* Sample time: [0.0025s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(Free_Flight_PID_RPY_Sen_DW.Medidas_SubsysRanBC);

  /* Constant: '<Root>/Empuje' */
  Free_Flight_PID_RPY_Sen_B.Empuje = Free_Flight_PID_RPY_Sen_P.Empuje_Value;

  /* Sin: '<Root>/Roll_sin' */
  if (Free_Flight_PID_RPY_Sen_DW.systemEnable != 0) {
    Free_Flight_PID_RPY_Sen_DW.lastSin = sin
      (Free_Flight_PID_RPY_Sen_P.Roll_sin_Freq *
       Free_Flight_PID_RPY_Sen_M->Timing.taskTime0);
    Free_Flight_PID_RPY_Sen_DW.lastCos = cos
      (Free_Flight_PID_RPY_Sen_P.Roll_sin_Freq *
       Free_Flight_PID_RPY_Sen_M->Timing.taskTime0);
    Free_Flight_PID_RPY_Sen_DW.systemEnable = 0;
  }

  /* DigitalClock: '<Root>/Digital Clock' */
  Free_Flight_PID_RPY_Sen_B.Sum2 = Free_Flight_PID_RPY_Sen_M->Timing.taskTime0;

  /* Constant: '<Root>/Yaw' */
  Free_Flight_PID_RPY_Sen_B.Yaw = Free_Flight_PID_RPY_Sen_P.Yaw_Value;

  /* Switch: '<Root>/Switch' incorporates:
   *  Sin: '<Root>/Roll_sin'
   */
  if (Free_Flight_PID_RPY_Sen_B.Sum2 >
      Free_Flight_PID_RPY_Sen_P.Switch_Threshold) {
    Free_Flight_PID_RPY_Sen_B.Switch = ((Free_Flight_PID_RPY_Sen_DW.lastSin *
      Free_Flight_PID_RPY_Sen_P.Roll_sin_PCos +
      Free_Flight_PID_RPY_Sen_DW.lastCos *
      Free_Flight_PID_RPY_Sen_P.Roll_sin_PSin) *
      Free_Flight_PID_RPY_Sen_P.Roll_sin_HCos +
      (Free_Flight_PID_RPY_Sen_DW.lastCos *
       Free_Flight_PID_RPY_Sen_P.Roll_sin_PCos -
       Free_Flight_PID_RPY_Sen_DW.lastSin *
       Free_Flight_PID_RPY_Sen_P.Roll_sin_PSin) *
      Free_Flight_PID_RPY_Sen_P.Roll_sin_Hsin) *
      Free_Flight_PID_RPY_Sen_P.Roll_sin_Amp +
      Free_Flight_PID_RPY_Sen_P.Roll_sin_Bias;
  } else {
    Free_Flight_PID_RPY_Sen_B.Switch = Free_Flight_PID_RPY_Sen_B.Yaw;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sin: '<Root>/Pitch_sin' */
  if (Free_Flight_PID_RPY_Sen_DW.systemEnable_d != 0) {
    Free_Flight_PID_RPY_Sen_DW.lastSin_c = sin
      (Free_Flight_PID_RPY_Sen_P.Pitch_sin_Freq *
       Free_Flight_PID_RPY_Sen_M->Timing.taskTime0);
    Free_Flight_PID_RPY_Sen_DW.lastCos_b = cos
      (Free_Flight_PID_RPY_Sen_P.Pitch_sin_Freq *
       Free_Flight_PID_RPY_Sen_M->Timing.taskTime0);
    Free_Flight_PID_RPY_Sen_DW.systemEnable_d = 0;
  }

  /* Switch: '<Root>/Switch1' incorporates:
   *  Sin: '<Root>/Pitch_sin'
   */
  if (Free_Flight_PID_RPY_Sen_B.Sum2 >
      Free_Flight_PID_RPY_Sen_P.Switch1_Threshold) {
    Free_Flight_PID_RPY_Sen_B.Switch1 = ((Free_Flight_PID_RPY_Sen_DW.lastSin_c *
      Free_Flight_PID_RPY_Sen_P.Pitch_sin_PCos +
      Free_Flight_PID_RPY_Sen_DW.lastCos_b *
      Free_Flight_PID_RPY_Sen_P.Pitch_sin_PSin) *
      Free_Flight_PID_RPY_Sen_P.Pitch_sin_HCos +
      (Free_Flight_PID_RPY_Sen_DW.lastCos_b *
       Free_Flight_PID_RPY_Sen_P.Pitch_sin_PCos -
       Free_Flight_PID_RPY_Sen_DW.lastSin_c *
       Free_Flight_PID_RPY_Sen_P.Pitch_sin_PSin) *
      Free_Flight_PID_RPY_Sen_P.Pitch_sin_Hsin) *
      Free_Flight_PID_RPY_Sen_P.Pitch_sin_Amp +
      Free_Flight_PID_RPY_Sen_P.Pitch_sin_Bias;
  } else {
    Free_Flight_PID_RPY_Sen_B.Switch1 = Free_Flight_PID_RPY_Sen_B.Yaw;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* SignalConversion: '<Root>/TmpSignal ConversionAtWork_refInport1' */
  Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtWork_refInport1[0] =
    Free_Flight_PID_RPY_Sen_B.Empuje;
  Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtWork_refInport1[1] =
    Free_Flight_PID_RPY_Sen_B.Switch;
  Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtWork_refInport1[2] =
    Free_Flight_PID_RPY_Sen_B.Switch1;
  Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtWork_refInport1[3] =
    Free_Flight_PID_RPY_Sen_B.Yaw;

  /* DataTypeConversion: '<S1>/Data Type Conversion5' */
  Free_Flight_PID_RPY_Sen_B.u0 = floor
    (Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtWork_refInport1[0]);
  if (rtIsNaN(Free_Flight_PID_RPY_Sen_B.u0) || rtIsInf
      (Free_Flight_PID_RPY_Sen_B.u0)) {
    Free_Flight_PID_RPY_Sen_B.u0 = 0.0;
  } else {
    Free_Flight_PID_RPY_Sen_B.u0 = fmod(Free_Flight_PID_RPY_Sen_B.u0, 65536.0);
  }

  rtb_DataTypeConversion5_idx_0 = (int16_T)(Free_Flight_PID_RPY_Sen_B.u0 < 0.0 ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-Free_Flight_PID_RPY_Sen_B.u0 :
    (int32_T)(int16_T)(uint16_T)Free_Flight_PID_RPY_Sen_B.u0);
  Free_Flight_PID_RPY_Sen_B.u0 = floor
    (Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtWork_refInport1[1]);
  if (rtIsNaN(Free_Flight_PID_RPY_Sen_B.u0) || rtIsInf
      (Free_Flight_PID_RPY_Sen_B.u0)) {
    Free_Flight_PID_RPY_Sen_B.u0 = 0.0;
  } else {
    Free_Flight_PID_RPY_Sen_B.u0 = fmod(Free_Flight_PID_RPY_Sen_B.u0, 65536.0);
  }

  Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k = floor
    (Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtWork_refInport1[2]);
  if (rtIsNaN(Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k) || rtIsInf
      (Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k)) {
    Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k = 0.0;
  } else {
    Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k = fmod
      (Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k, 65536.0);
  }

  Free_Flight_PID_RPY_Sen_B.Sum2 = floor
    (Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtWork_refInport1[3]);
  if (rtIsNaN(Free_Flight_PID_RPY_Sen_B.Sum2) || rtIsInf
      (Free_Flight_PID_RPY_Sen_B.Sum2)) {
    Free_Flight_PID_RPY_Sen_B.Sum2 = 0.0;
  } else {
    Free_Flight_PID_RPY_Sen_B.Sum2 = fmod(Free_Flight_PID_RPY_Sen_B.Sum2,
      65536.0);
  }

  /* S-Function (IMU_Sfcn_mex): '<S2>/IMU Read' */
  MDL_IMU_step(&Free_Flight_PID_RPY_Sen_B.IMURead_o1, &rtb_IMURead_o2);

  /* MATLAB Function: '<S4>/Verify IMU Data' */
  /* MATLAB Function 'Verify IMU Data': '<S16>:1' */
  /*  Compare the checksums and checksum flags of packets */
  /*  determines whether a packet is valid, if it is valid it is passed through */
  /*  else the last known valid packet is passed through. */
  if (!Free_Flight_PID_RPY_Sen_DW.storedGoodPacket_not_empty) {
    /* '<S16>:1:8' */
    /* '<S16>:1:9' */
    Free_Flight_PID_RPY_Sen_DW.storedGoodPacket =
      Free_Flight_PID_RPY_Sen_B.IMURead_o1;
    Free_Flight_PID_RPY_Sen_DW.storedGoodPacket_not_empty = true;
  }

  if (!Free_Flight_PID_RPY_Sen_DW.storedBadChecksum_not_empty) {
    /* '<S16>:1:13' */
    /* '<S16>:1:14' */
    Free_Flight_PID_RPY_Sen_DW.storedBadChecksum =
      Free_Flight_PID_RPY_Sen_B.IMURead_o1.chksum;
    Free_Flight_PID_RPY_Sen_DW.storedBadChecksum_not_empty = true;
  }

  if (rtb_IMURead_o2 == 0) {
    /* '<S16>:1:17' */
    /*  checksum flag failed, save the bad packet checksum to compare with future packets */
    /* '<S16>:1:18' */
    rtb_BitwiseOperator_idx_0 = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.ax;
    rtb_BitwiseOperator_idx_1 = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.ay;
    rtb_BitwiseOperator_idx_2 = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.az;
    rtb_validImuData_vx = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.vx;
    rtb_validImuData_vy = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.vy;
    rtb_validImuData_vz = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.vz;
    rtb_validImuData_ultrasound =
      Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.ultrasound;

    /* '<S16>:1:19' */
    Free_Flight_PID_RPY_Sen_DW.storedBadChecksum =
      Free_Flight_PID_RPY_Sen_B.IMURead_o1.chksum;
  } else {
    /*  checksum flag passed but could still be bad data */
    rtb_u = false;
    b_p = true;
    if (!(Free_Flight_PID_RPY_Sen_B.IMURead_o1.chksum ==
          Free_Flight_PID_RPY_Sen_DW.storedBadChecksum)) {
      b_p = false;
    }

    if (b_p) {
      rtb_u = true;
    }

    if (rtb_u) {
      /* '<S16>:1:21' */
      /*  the new data is still the bad data */
      /* '<S16>:1:22' */
      rtb_BitwiseOperator_idx_0 = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.ax;
      rtb_BitwiseOperator_idx_1 = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.ay;
      rtb_BitwiseOperator_idx_2 = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.az;
      rtb_validImuData_vx = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.vx;
      rtb_validImuData_vy = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.vy;
      rtb_validImuData_vz = Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.vz;
      rtb_validImuData_ultrasound =
        Free_Flight_PID_RPY_Sen_DW.storedGoodPacket.ultrasound;
    } else {
      /*  the new packet is not equal to the bad packet, update good packet to new packet */
      /* '<S16>:1:24' */
      Free_Flight_PID_RPY_Sen_DW.storedGoodPacket =
        Free_Flight_PID_RPY_Sen_B.IMURead_o1;

      /* '<S16>:1:25' */
      rtb_BitwiseOperator_idx_0 = Free_Flight_PID_RPY_Sen_B.IMURead_o1.ax;
      rtb_BitwiseOperator_idx_1 = Free_Flight_PID_RPY_Sen_B.IMURead_o1.ay;
      rtb_BitwiseOperator_idx_2 = Free_Flight_PID_RPY_Sen_B.IMURead_o1.az;
      rtb_validImuData_vx = Free_Flight_PID_RPY_Sen_B.IMURead_o1.vx;
      rtb_validImuData_vy = Free_Flight_PID_RPY_Sen_B.IMURead_o1.vy;
      rtb_validImuData_vz = Free_Flight_PID_RPY_Sen_B.IMURead_o1.vz;
      rtb_validImuData_ultrasound =
        Free_Flight_PID_RPY_Sen_B.IMURead_o1.ultrasound;
    }
  }

  /* End of MATLAB Function: '<S4>/Verify IMU Data' */

  /* Gain: '<S36>/Gain' incorporates:
   *  Constant: '<S29>/Constant'
   *  DataTypeConversion: '<S13>/Data Type Conversion'
   *  Sum: '<S29>/Sum'
   *  Sum: '<S29>/Sum1'
   *  Sum: '<S29>/Sum2'
   */
  Free_Flight_PID_RPY_Sen_B.Gain[0] = ((real_T)rtb_validImuData_vx -
    Free_Flight_PID_RPY_Sen_P.gyroXyzOffsets[0]) *
    Free_Flight_PID_RPY_Sen_P.Gain_Gain[0];
  Free_Flight_PID_RPY_Sen_B.Gain[1] = ((real_T)rtb_validImuData_vy -
    Free_Flight_PID_RPY_Sen_P.gyroXyzOffsets[1]) *
    Free_Flight_PID_RPY_Sen_P.Gain_Gain[1];
  Free_Flight_PID_RPY_Sen_B.Gain[2] = ((real_T)rtb_validImuData_vz -
    Free_Flight_PID_RPY_Sen_P.gyroXyzOffsets[2]) *
    Free_Flight_PID_RPY_Sen_P.Gain_Gain[2];

  /* Sum: '<S32>/Add' incorporates:
   *  Constant: '<S31>/Acclerometer Calibration Gains'
   *  Constant: '<S31>/Acclerometer Calibration Offsets'
   *  DataTypeConversion: '<S27>/Data Type Conversion'
   *  Gain: '<S31>/Invert Axes Definition'
   *  Gain: '<S32>/Gain'
   *  Gain: '<S32>/Gain1'
   *  Product: '<S31>/Divide'
   *  Sum: '<S31>/Add'
   *  UnitDelay: '<S32>/Unit Delay'
   */
  Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_0 = ((real_T)
    rtb_BitwiseOperator_idx_0 -
    Free_Flight_PID_RPY_Sen_P.accelerometerXyzOffsets[0]) /
    Free_Flight_PID_RPY_Sen_P.accelerometerXyzGains[0] *
    Free_Flight_PID_RPY_Sen_P.InvertAxesDefinition_Gain *
    Free_Flight_PID_RPY_Sen_P.Gain1_Gain + Free_Flight_PID_RPY_Sen_P.Gain_Gain_h
    * Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_e[0];
  Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_1 = ((real_T)
    rtb_BitwiseOperator_idx_1 -
    Free_Flight_PID_RPY_Sen_P.accelerometerXyzOffsets[1]) /
    Free_Flight_PID_RPY_Sen_P.accelerometerXyzGains[1] *
    Free_Flight_PID_RPY_Sen_P.InvertAxesDefinition_Gain *
    Free_Flight_PID_RPY_Sen_P.Gain1_Gain + Free_Flight_PID_RPY_Sen_P.Gain_Gain_h
    * Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_e[1];
  Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_2 = ((real_T)
    rtb_BitwiseOperator_idx_2 -
    Free_Flight_PID_RPY_Sen_P.accelerometerXyzOffsets[2]) /
    Free_Flight_PID_RPY_Sen_P.accelerometerXyzGains[2] *
    Free_Flight_PID_RPY_Sen_P.InvertAxesDefinition_Gain *
    Free_Flight_PID_RPY_Sen_P.Gain1_Gain + Free_Flight_PID_RPY_Sen_P.Gain_Gain_h
    * Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_e[2];

  /* Sum: '<S33>/Sum of Elements' incorporates:
   *  Math: '<S33>/Math Function'
   */
  Free_Flight_PID_RPY_Sen_B.Conm =
    (Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_0 *
     Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_0 +
     Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_1 *
     Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_1) +
    Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_2 *
    Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_2;

  /* Math: '<S33>/Math Function1'
   *
   * About '<S33>/Math Function1':
   *  Operator: sqrt
   */
  if (Free_Flight_PID_RPY_Sen_B.Conm < 0.0) {
    Free_Flight_PID_RPY_Sen_B.Conm = -sqrt(fabs(Free_Flight_PID_RPY_Sen_B.Conm));
  } else {
    Free_Flight_PID_RPY_Sen_B.Conm = sqrt(Free_Flight_PID_RPY_Sen_B.Conm);
  }

  /* End of Math: '<S33>/Math Function1' */

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Constant'
   *  Product: '<S33>/Product'
   */
  if (Free_Flight_PID_RPY_Sen_B.Conm >
      Free_Flight_PID_RPY_Sen_P.NormalizeVector_maxzero) {
    Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_0 =
      Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_0;
    Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 =
      Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_1;
    Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 =
      Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_2;
  } else {
    Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_0 =
      Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_0 * 0.0;
    Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 =
      Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_1 * 0.0;
    Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 =
      Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_2 * 0.0;
    Free_Flight_PID_RPY_Sen_B.Conm = Free_Flight_PID_RPY_Sen_P.Constant_Value;
  }

  /* End of Switch: '<S33>/Switch' */

  /* Product: '<S33>/Divide' */
  Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_0 /= Free_Flight_PID_RPY_Sen_B.Conm;
  Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 /= Free_Flight_PID_RPY_Sen_B.Conm;
  Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 /= Free_Flight_PID_RPY_Sen_B.Conm;

  /* MATLAB Function: '<S21>/Kalman Tracker' incorporates:
   *  Gain: '<S19>/Gain4'
   *  MATLAB Function: '<S19>/MATLAB Function'
   *  MATLAB Function: '<S20>/Kalman Tracker'
   *  UnitDelay: '<S20>/Unit Delay'
   *  UnitDelay: '<S21>/Unit Delay'
   *  UnitDelay: '<S21>/Unit Delay1'
   */
  /* MATLAB Function 'Navigation System/Kalman Filter/Compute Roll Pitch/Calculate Roll - Pitch/MATLAB Function': '<S23>:1' */
  /* '<S23>:1:3' */
  /* '<S23>:1:4' */
  /* '<S23>:1:5' */
  /* '<S23>:1:7' */
  /* '<S23>:1:8' */
  /* MATLAB Function 'Navigation System/Kalman Filter/Compute Roll Pitch/KF_ROLL/Kalman Tracker': '<S25>:1' */
  /* '<S25>:1:43' */
  /* '<S25>:1:22' */
  /* '<S25>:1:21' */
  /* ------------------------------- */
  /* ---- Predict Stage ------------ */
  /* ------------------------------- */
  /*  pix_value = 5; */
  /* Process Noise */
  /* '<S25>:1:13' */
  /* A matrix */
  /* odutput these values with a unit delay (for algebraic loop), apply initial conditions */
  /* '<S25>:1:21' */
  /* '<S25>:1:22' */
  for (k = 0; k < 2; k++) {
    Free_Flight_PID_RPY_Sen_B.a[k] = 0.0;
    Free_Flight_PID_RPY_Sen_B.a[k] += a[k] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[0];
    Free_Flight_PID_RPY_Sen_B.a[k] += a[k + 2] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[1];
    Free_Flight_PID_RPY_Sen_B.a[k + 2] = 0.0;
    Free_Flight_PID_RPY_Sen_B.a[k + 2] += a[k] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[2];
    Free_Flight_PID_RPY_Sen_B.a[k + 2] += a[k + 2] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[3];
    Free_Flight_PID_RPY_Sen_B.state_correction_j[k] = (a[k + 2] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE[1] + a[k] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE[0]) + b_a[k] *
      Free_Flight_PID_RPY_Sen_B.Gain[0];
    Free_Flight_PID_RPY_Sen_B.covariance_prediction[k] =
      (Free_Flight_PID_RPY_Sen_B.a[k + 2] * -0.0025 +
       Free_Flight_PID_RPY_Sen_B.a[k]) + Q[k];
    Free_Flight_PID_RPY_Sen_B.covariance_prediction[k + 2] =
      (Free_Flight_PID_RPY_Sen_B.a[k] * 0.0 + Free_Flight_PID_RPY_Sen_B.a[k + 2])
      + Q[k + 2];
  }

  /* ------------------------------- */
  /* ---- Estimate Stage ----------- */
  /* ------------------------------- */
  /* H matrix */
  /* Measurement noise from accelerometer angle measurement */
  /*      m_var_r = 1; */
  /* '<S25>:1:37' */
  /* Measurement Z */
  /* Compute Kalman Gain */
  /* '<S25>:1:43' */
  Free_Flight_PID_RPY_Sen_B.Conm = 1.0 / (((0.0 *
    Free_Flight_PID_RPY_Sen_B.covariance_prediction[3] +
    Free_Flight_PID_RPY_Sen_B.covariance_prediction[2]) * 0.0 + (0.0 *
    Free_Flight_PID_RPY_Sen_B.covariance_prediction[1] +
    Free_Flight_PID_RPY_Sen_B.covariance_prediction[0])) + 0.25);

  /* 2x2 matrix */
  /* compute state space correction based on measurement */
  /* '<S25>:1:46' */
  Free_Flight_PID_RPY_Sen_B.Kalman_Gain[0] =
    (Free_Flight_PID_RPY_Sen_B.covariance_prediction[2] * 0.0 +
     Free_Flight_PID_RPY_Sen_B.covariance_prediction[0]) *
    Free_Flight_PID_RPY_Sen_B.Conm;
  Free_Flight_PID_RPY_Sen_B.Kalman_Gain[1] =
    (Free_Flight_PID_RPY_Sen_B.covariance_prediction[3] * 0.0 +
     Free_Flight_PID_RPY_Sen_B.covariance_prediction[1]) *
    Free_Flight_PID_RPY_Sen_B.Conm;
  Free_Flight_PID_RPY_Sen_B.Conm = atan
    (-Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 / sqrt
     (-Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_0 *
      -Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_0 +
      Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 *
      Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2)) *
    Free_Flight_PID_RPY_Sen_P.Gain4_Gain - (0.0 *
    Free_Flight_PID_RPY_Sen_B.state_correction_j[1] +
    Free_Flight_PID_RPY_Sen_B.state_correction_j[0]);

  /* 4x1 vector of states */
  /* compute covariance correction */
  /* '<S25>:1:49' */
  I[0] = 0;
  I[1] = 0;
  I[2] = 0;
  I[3] = 0;

  /* 2x2 covariance matrix */
  /*      corrected_angle_measure = state_correction(1) - Ts*state_correction(2); */
  /* MATLAB Function 'Navigation System/Kalman Filter/Compute Roll Pitch/KF_PITCH/Kalman Tracker': '<S24>:1' */
  /* '<S24>:1:43' */
  /* '<S24>:1:22' */
  /* '<S24>:1:21' */
  /* ------------------------------- */
  /* ---- Predict Stage ------------ */
  /* ------------------------------- */
  /*  pix_value = 5; */
  /* Process Noise */
  /* '<S24>:1:13' */
  /* A matrix */
  /* odutput these values with a unit delay (for algebraic loop), apply initial conditions */
  /* '<S24>:1:21' */
  /* '<S24>:1:22' */
  for (k = 0; k < 2; k++) {
    I[k + (k << 1)] = 1;

    /* MATLAB Function: '<S20>/Kalman Tracker' */
    Free_Flight_PID_RPY_Sen_B.a[k] = 0.0;
    Free_Flight_PID_RPY_Sen_B.a[k] += a_0[k] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[0];
    Free_Flight_PID_RPY_Sen_B.a[k] += a_0[k + 2] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[1];

    /* MATLAB Function: '<S20>/Kalman Tracker' incorporates:
     *  UnitDelay: '<S20>/Unit Delay'
     */
    Free_Flight_PID_RPY_Sen_B.a[k + 2] = 0.0;
    Free_Flight_PID_RPY_Sen_B.a[k + 2] += a_0[k] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[2];
    Free_Flight_PID_RPY_Sen_B.a[k + 2] += a_0[k + 2] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[3];

    /* MATLAB Function: '<S20>/Kalman Tracker' incorporates:
     *  UnitDelay: '<S20>/Unit Delay'
     *  UnitDelay: '<S20>/Unit Delay1'
     */
    Free_Flight_PID_RPY_Sen_B.state_correction_b[k] = (a_0[k + 2] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_k[1] + a_0[k] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_k[0]) + b_a_0[k] *
      Free_Flight_PID_RPY_Sen_B.Gain[1];
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[k] =
      (Free_Flight_PID_RPY_Sen_B.a[k + 2] * -0.0025 +
       Free_Flight_PID_RPY_Sen_B.a[k]) + Q_0[k];
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[k + 2] =
      (Free_Flight_PID_RPY_Sen_B.a[k] * 0.0 + Free_Flight_PID_RPY_Sen_B.a[k + 2])
      + Q_0[k + 2];
    Free_Flight_PID_RPY_Sen_B.state_correction_j[k] +=
      Free_Flight_PID_RPY_Sen_B.Kalman_Gain[k] * Free_Flight_PID_RPY_Sen_B.Conm;
  }

  /* MATLAB Function: '<S20>/Kalman Tracker' incorporates:
   *  Gain: '<S19>/Gain5'
   *  MATLAB Function: '<S19>/MATLAB Function'
   */
  /* ------------------------------- */
  /* ---- Estimate Stage ----------- */
  /* ------------------------------- */
  /* H matrix */
  /* Measurement noise from accelerometer angle measurement */
  /*      m_var_r = 1; */
  /* '<S24>:1:37' */
  /* Measurement Z */
  /* Compute Kalman Gain */
  /* '<S24>:1:43' */
  Free_Flight_PID_RPY_Sen_B.Conm = 1.0 / (((0.0 *
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[3] +
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[2]) * 0.0 + (0.0 *
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[1] +
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[0])) + 1.0);

  /* 2x2 matrix */
  /* compute state space correction based on measurement */
  /* '<S24>:1:46' */
  Free_Flight_PID_RPY_Sen_B.Kalman_Gain_c[0] =
    (Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[2] * 0.0 +
     Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[0]) *
    Free_Flight_PID_RPY_Sen_B.Conm;
  Free_Flight_PID_RPY_Sen_B.Kalman_Gain_c[1] =
    (Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[3] * 0.0 +
     Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[1]) *
    Free_Flight_PID_RPY_Sen_B.Conm;
  Free_Flight_PID_RPY_Sen_B.Conm = atan
    (-Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_0 / sqrt
     (-Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 *
      -Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 +
      Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 *
      Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2)) *
    Free_Flight_PID_RPY_Sen_P.Gain5_Gain - (0.0 *
    Free_Flight_PID_RPY_Sen_B.state_correction_b[1] +
    Free_Flight_PID_RPY_Sen_B.state_correction_b[0]);

  /* 4x1 vector of states */
  /* compute covariance correction */
  /* '<S24>:1:49' */
  I_0[1] = 0;
  I_0[2] = 0;

  /* 2x2 covariance matrix */
  /*      corrected_angle_measure = state_correction(1) - Ts*state_correction(2); */
  I_0[0] = 1;
  Free_Flight_PID_RPY_Sen_B.state_correction_b[0] +=
    Free_Flight_PID_RPY_Sen_B.Kalman_Gain_c[0] * Free_Flight_PID_RPY_Sen_B.Conm;
  I_0[3] = 1;
  Free_Flight_PID_RPY_Sen_B.state_correction_b[1] +=
    Free_Flight_PID_RPY_Sen_B.Kalman_Gain_c[1] * Free_Flight_PID_RPY_Sen_B.Conm;

  /* Gain: '<S14>/Change Sign' incorporates:
   *  DiscreteIntegrator: '<S14>/Discrete-Time Integrator1'
   */
  Free_Flight_PID_RPY_Sen_B.ChangeSign[0] =
    Free_Flight_PID_RPY_Sen_P.ChangeSign_Gain *
    Free_Flight_PID_RPY_Sen_B.state_correction_j[0];
  Free_Flight_PID_RPY_Sen_B.ChangeSign[1] =
    Free_Flight_PID_RPY_Sen_P.ChangeSign_Gain *
    Free_Flight_PID_RPY_Sen_B.state_correction_b[0];
  Free_Flight_PID_RPY_Sen_B.ChangeSign[2] =
    Free_Flight_PID_RPY_Sen_P.ChangeSign_Gain *
    Free_Flight_PID_RPY_Sen_DW.DiscreteTimeIntegrator1_DSTATE;

  /* Sum: '<S1>/Sum' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   */
  Free_Flight_PID_RPY_Sen_B.u0 = (real_T)(int16_T)(Free_Flight_PID_RPY_Sen_B.u0 <
    0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)-Free_Flight_PID_RPY_Sen_B.u0 :
    (int32_T)(int16_T)(uint16_T)Free_Flight_PID_RPY_Sen_B.u0) -
    Free_Flight_PID_RPY_Sen_B.ChangeSign[0];

  /* Saturate: '<S1>/sat_err' */
  if (Free_Flight_PID_RPY_Sen_B.u0 > Free_Flight_PID_RPY_Sen_P.sat_err_UpperSat
      [0]) {
    Free_Flight_PID_RPY_Sen_B.u0 = Free_Flight_PID_RPY_Sen_P.sat_err_UpperSat[0];
  } else {
    if (Free_Flight_PID_RPY_Sen_B.u0 <
        Free_Flight_PID_RPY_Sen_P.sat_err_LowerSat[0]) {
      Free_Flight_PID_RPY_Sen_B.u0 = Free_Flight_PID_RPY_Sen_P.sat_err_LowerSat
        [0];
    }
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  DiscreteTransferFcn: '<S1>/Filtro_vel'
   *  Gain: '<S1>/Ganancia'
   */
  Free_Flight_PID_RPY_Sen_B.IntegralGain[0] =
    Free_Flight_PID_RPY_Sen_P.Ganancia_Gain[0] * Free_Flight_PID_RPY_Sen_B.u0 -
    Free_Flight_PID_RPY_Sen_P.Filtro_vel_NumCoef *
    Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[0];

  /* Sum: '<S1>/Sum' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   */
  Free_Flight_PID_RPY_Sen_B.u0 = (real_T)(int16_T)
    (Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k < 0.0 ? (int32_T)(int16_T)
     -(int16_T)(uint16_T)-Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k :
     (int32_T)(int16_T)(uint16_T)
     Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k) -
    Free_Flight_PID_RPY_Sen_B.ChangeSign[1];

  /* Saturate: '<S1>/sat_err' */
  if (Free_Flight_PID_RPY_Sen_B.u0 > Free_Flight_PID_RPY_Sen_P.sat_err_UpperSat
      [1]) {
    Free_Flight_PID_RPY_Sen_B.u0 = Free_Flight_PID_RPY_Sen_P.sat_err_UpperSat[1];
  } else {
    if (Free_Flight_PID_RPY_Sen_B.u0 <
        Free_Flight_PID_RPY_Sen_P.sat_err_LowerSat[1]) {
      Free_Flight_PID_RPY_Sen_B.u0 = Free_Flight_PID_RPY_Sen_P.sat_err_LowerSat
        [1];
    }
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  DiscreteTransferFcn: '<S1>/Filtro_vel'
   *  Gain: '<S1>/Ganancia'
   */
  Free_Flight_PID_RPY_Sen_B.IntegralGain[1] =
    Free_Flight_PID_RPY_Sen_P.Ganancia_Gain[1] * Free_Flight_PID_RPY_Sen_B.u0 -
    Free_Flight_PID_RPY_Sen_P.Filtro_vel_NumCoef *
    Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[1];

  /* ManualSwitch: '<Root>/Conm' incorporates:
   *  Constant: '<Root>/Cero'
   *  Constant: '<Root>/Uno'
   */
  if (Free_Flight_PID_RPY_Sen_P.Conm_CurrentSetting == 1) {
    Free_Flight_PID_RPY_Sen_B.Conm = Free_Flight_PID_RPY_Sen_P.Uno_Value;
  } else {
    Free_Flight_PID_RPY_Sen_B.Conm = Free_Flight_PID_RPY_Sen_P.Cero_Value;
  }

  /* End of ManualSwitch: '<Root>/Conm' */

  /* Logic: '<S1>/ ' */
  rtb_u = !(Free_Flight_PID_RPY_Sen_B.Conm != 0.0);

  /* DiscreteIntegrator: '<S6>/Integrator' */
  if (rtb_u || (Free_Flight_PID_RPY_Sen_DW.Integrator_PrevResetState != 0)) {
    Free_Flight_PID_RPY_Sen_DW.Integrator_DSTATE[0] =
      Free_Flight_PID_RPY_Sen_P.Integrator_IC;
    Free_Flight_PID_RPY_Sen_DW.Integrator_DSTATE[1] =
      Free_Flight_PID_RPY_Sen_P.Integrator_IC;
  }

  /* DiscreteIntegrator: '<S6>/Filter' */
  if (rtb_u || (Free_Flight_PID_RPY_Sen_DW.Filter_PrevResetState != 0)) {
    Free_Flight_PID_RPY_Sen_DW.Filter_DSTATE[0] =
      Free_Flight_PID_RPY_Sen_P.Filter_IC;
    Free_Flight_PID_RPY_Sen_DW.Filter_DSTATE[1] =
      Free_Flight_PID_RPY_Sen_P.Filter_IC;
  }

  /* Gain: '<S6>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S6>/Filter'
   *  Gain: '<S6>/Derivative Gain'
   *  Sum: '<S6>/SumD'
   */
  Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k =
    (Free_Flight_PID_RPY_Sen_P.PIDRP_D * Free_Flight_PID_RPY_Sen_B.IntegralGain
     [0] - Free_Flight_PID_RPY_Sen_DW.Filter_DSTATE[0]) *
    Free_Flight_PID_RPY_Sen_P.PIDRP_N;

  /* Sum: '<S6>/Sum' incorporates:
   *  DiscreteIntegrator: '<S6>/Integrator'
   *  Gain: '<S6>/Proportional Gain'
   */
  Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 = (Free_Flight_PID_RPY_Sen_P.PIDRP_P *
    Free_Flight_PID_RPY_Sen_B.IntegralGain[0] +
    Free_Flight_PID_RPY_Sen_DW.Integrator_DSTATE[0]) +
    Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k;

  /* Gain: '<S6>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S6>/Filter'
   *  Gain: '<S6>/Derivative Gain'
   *  Sum: '<S6>/SumD'
   */
  Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_0 =
    Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k;
  Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k =
    (Free_Flight_PID_RPY_Sen_P.PIDRP_D * Free_Flight_PID_RPY_Sen_B.IntegralGain
     [1] - Free_Flight_PID_RPY_Sen_DW.Filter_DSTATE[1]) *
    Free_Flight_PID_RPY_Sen_P.PIDRP_N;

  /* Sum: '<S6>/Sum' incorporates:
   *  DiscreteIntegrator: '<S6>/Integrator'
   *  Gain: '<S6>/Proportional Gain'
   */
  Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 = (Free_Flight_PID_RPY_Sen_P.PIDRP_P *
    Free_Flight_PID_RPY_Sen_B.IntegralGain[1] +
    Free_Flight_PID_RPY_Sen_DW.Integrator_DSTATE[1]) +
    Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k;

  /* Sum: '<S1>/Sum2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion5'
   */
  Free_Flight_PID_RPY_Sen_B.Sum2 = (real_T)(int16_T)
    (Free_Flight_PID_RPY_Sen_B.Sum2 < 0.0 ? (int32_T)(int16_T)-(int16_T)
     (uint16_T)-Free_Flight_PID_RPY_Sen_B.Sum2 : (int32_T)(int16_T)(uint16_T)
     Free_Flight_PID_RPY_Sen_B.Sum2) - Free_Flight_PID_RPY_Sen_B.ChangeSign[2];

  /* Saturate: '<S1>/sat_err1' */
  if (Free_Flight_PID_RPY_Sen_B.Sum2 >
      Free_Flight_PID_RPY_Sen_P.sat_err1_UpperSat) {
    Free_Flight_PID_RPY_Sen_B.Sum2 = Free_Flight_PID_RPY_Sen_P.sat_err1_UpperSat;
  } else {
    if (Free_Flight_PID_RPY_Sen_B.Sum2 <
        Free_Flight_PID_RPY_Sen_P.sat_err1_LowerSat) {
      Free_Flight_PID_RPY_Sen_B.Sum2 =
        Free_Flight_PID_RPY_Sen_P.sat_err1_LowerSat;
    }
  }

  /* End of Saturate: '<S1>/sat_err1' */

  /* DiscreteIntegrator: '<S8>/Ki' */
  if (rtb_u || (Free_Flight_PID_RPY_Sen_DW.Ki_PrevResetState != 0)) {
    Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE = Free_Flight_PID_RPY_Sen_P.Ki_IC;
  }

  if (Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE >=
      Free_Flight_PID_RPY_Sen_P.Ki_UpperSat) {
    Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE = Free_Flight_PID_RPY_Sen_P.Ki_UpperSat;
  } else {
    if (Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE <=
        Free_Flight_PID_RPY_Sen_P.Ki_LowerSat) {
      Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE =
        Free_Flight_PID_RPY_Sen_P.Ki_LowerSat;
    }
  }

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<S1>/Paro'
   */
  if (Free_Flight_PID_RPY_Sen_B.Conm >
      Free_Flight_PID_RPY_Sen_P.Switch_Threshold_h) {
    /* SignalConversion: '<S1>/TmpSignal ConversionAtMotorMixingInport1' incorporates:
     *  DataTypeConversion: '<S1>/conv'
     */
    if (Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 >
        Free_Flight_PID_RPY_Sen_P.PIDRP_UpperSaturationLimit) {
      Free_Flight_PID_RPY_Sen_B.Conm =
        Free_Flight_PID_RPY_Sen_P.PIDRP_UpperSaturationLimit;
    } else if (Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 <
               Free_Flight_PID_RPY_Sen_P.PIDRP_LowerSaturationLimit) {
      Free_Flight_PID_RPY_Sen_B.Conm =
        Free_Flight_PID_RPY_Sen_P.PIDRP_LowerSaturationLimit;
    } else {
      Free_Flight_PID_RPY_Sen_B.Conm = Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2;
    }

    Free_Flight_PID_RPY_Sen_B.u0 = fabs(Free_Flight_PID_RPY_Sen_B.Conm);
    if (Free_Flight_PID_RPY_Sen_B.u0 < 4.503599627370496E+15) {
      if (Free_Flight_PID_RPY_Sen_B.u0 >= 0.5) {
        Free_Flight_PID_RPY_Sen_B.Conm = floor(Free_Flight_PID_RPY_Sen_B.Conm +
          0.5);
      } else {
        Free_Flight_PID_RPY_Sen_B.Conm *= 0.0;
      }
    }

    if (rtIsNaN(Free_Flight_PID_RPY_Sen_B.Conm) || rtIsInf
        (Free_Flight_PID_RPY_Sen_B.Conm)) {
      Free_Flight_PID_RPY_Sen_B.u0 = 0.0;
    } else {
      Free_Flight_PID_RPY_Sen_B.u0 = fmod(Free_Flight_PID_RPY_Sen_B.Conm,
        65536.0);
    }

    rtb_validImuData_vx = (int16_T)(Free_Flight_PID_RPY_Sen_B.u0 < 0.0 ?
      (int32_T)(int16_T)-(int16_T)(uint16_T)-Free_Flight_PID_RPY_Sen_B.u0 :
      (int32_T)(int16_T)(uint16_T)Free_Flight_PID_RPY_Sen_B.u0);
    if (Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 >
        Free_Flight_PID_RPY_Sen_P.PIDRP_UpperSaturationLimit) {
      Free_Flight_PID_RPY_Sen_B.Conm =
        Free_Flight_PID_RPY_Sen_P.PIDRP_UpperSaturationLimit;
    } else if (Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 <
               Free_Flight_PID_RPY_Sen_P.PIDRP_LowerSaturationLimit) {
      Free_Flight_PID_RPY_Sen_B.Conm =
        Free_Flight_PID_RPY_Sen_P.PIDRP_LowerSaturationLimit;
    } else {
      Free_Flight_PID_RPY_Sen_B.Conm = Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1;
    }

    Free_Flight_PID_RPY_Sen_B.u0 = fabs(Free_Flight_PID_RPY_Sen_B.Conm);
    if (Free_Flight_PID_RPY_Sen_B.u0 < 4.503599627370496E+15) {
      if (Free_Flight_PID_RPY_Sen_B.u0 >= 0.5) {
        Free_Flight_PID_RPY_Sen_B.Conm = floor(Free_Flight_PID_RPY_Sen_B.Conm +
          0.5);
      } else {
        Free_Flight_PID_RPY_Sen_B.Conm *= 0.0;
      }
    }

    if (rtIsNaN(Free_Flight_PID_RPY_Sen_B.Conm) || rtIsInf
        (Free_Flight_PID_RPY_Sen_B.Conm)) {
      Free_Flight_PID_RPY_Sen_B.u0 = 0.0;
    } else {
      Free_Flight_PID_RPY_Sen_B.u0 = fmod(Free_Flight_PID_RPY_Sen_B.Conm,
        65536.0);
    }

    rtb_validImuData_vy = (int16_T)(Free_Flight_PID_RPY_Sen_B.u0 < 0.0 ?
      (int32_T)(int16_T)-(int16_T)(uint16_T)-Free_Flight_PID_RPY_Sen_B.u0 :
      (int32_T)(int16_T)(uint16_T)Free_Flight_PID_RPY_Sen_B.u0);

    /* DataTypeConversion: '<S1>/conv1' incorporates:
     *  DiscreteIntegrator: '<S8>/Ki'
     *  DiscreteTransferFcn: '<S1>/Filtro_vel'
     *  Gain: '<S8>/Kd'
     *  Gain: '<S8>/Kp'
     *  Sum: '<S8>/Sum'
     */
    Free_Flight_PID_RPY_Sen_B.Conm = (Free_Flight_PID_RPY_Sen_P.Kp_Gain *
      Free_Flight_PID_RPY_Sen_B.Sum2 + Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE) +
      Free_Flight_PID_RPY_Sen_P.Filtro_vel_NumCoef *
      Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[2] *
      Free_Flight_PID_RPY_Sen_P.Kd_Gain;
    Free_Flight_PID_RPY_Sen_B.u0 = fabs(Free_Flight_PID_RPY_Sen_B.Conm);
    if (Free_Flight_PID_RPY_Sen_B.u0 < 4.503599627370496E+15) {
      if (Free_Flight_PID_RPY_Sen_B.u0 >= 0.5) {
        Free_Flight_PID_RPY_Sen_B.Conm = floor(Free_Flight_PID_RPY_Sen_B.Conm +
          0.5);
      } else {
        Free_Flight_PID_RPY_Sen_B.Conm *= 0.0;
      }
    }

    if (rtIsNaN(Free_Flight_PID_RPY_Sen_B.Conm) || rtIsInf
        (Free_Flight_PID_RPY_Sen_B.Conm)) {
      Free_Flight_PID_RPY_Sen_B.u0 = 0.0;
    } else {
      Free_Flight_PID_RPY_Sen_B.u0 = fmod(Free_Flight_PID_RPY_Sen_B.Conm,
        65536.0);
    }

    /* SignalConversion: '<S1>/TmpSignal ConversionAtMotorMixingInport1' incorporates:
     *  DataTypeConversion: '<S1>/conv1'
     */
    rtb_validImuData_vz = (int16_T)(Free_Flight_PID_RPY_Sen_B.u0 < 0.0 ?
      (int32_T)(int16_T)-(int16_T)(uint16_T)-Free_Flight_PID_RPY_Sen_B.u0 :
      (int32_T)(int16_T)(uint16_T)Free_Flight_PID_RPY_Sen_B.u0);

    /* Gain: '<S1>/MotorMixing' incorporates:
     *  SignalConversion: '<S1>/TmpSignal ConversionAtMotorMixingInport1'
     */
    for (k = 0; k < 4; k++) {
      rtb_MotorMixing = (int16_T)((int16_T)
        (Free_Flight_PID_RPY_Sen_P.MotorMixing_Gain[k + 12] *
         rtb_validImuData_vz) + (int16_T)((int16_T)
        (Free_Flight_PID_RPY_Sen_P.MotorMixing_Gain[k + 8] * rtb_validImuData_vy)
        + (int16_T)((int16_T)(Free_Flight_PID_RPY_Sen_P.MotorMixing_Gain[k + 4] *
        rtb_validImuData_vx) + (int16_T)
                    (Free_Flight_PID_RPY_Sen_P.MotorMixing_Gain[k] *
                     rtb_DataTypeConversion5_idx_0))));

      /* Switch: '<S9>/Switch2' incorporates:
       *  Constant: '<S1>/maxThrottle'
       *  Constant: '<S1>/minThrottle'
       *  RelationalOperator: '<S9>/LowerRelop1'
       *  RelationalOperator: '<S9>/UpperRelop'
       *  SignalConversion: '<S1>/TmpSignal ConversionAtMotorMixingInport1'
       *  Switch: '<S9>/Switch'
       */
      if (rtb_MotorMixing > Free_Flight_PID_RPY_Sen_P.maxThrottle_Value) {
        Free_Flight_PID_RPY_Sen_B.Switch_d[k] =
          Free_Flight_PID_RPY_Sen_P.maxThrottle_Value;
      } else if (rtb_MotorMixing < Free_Flight_PID_RPY_Sen_P.minThrottle_Value)
      {
        /* Switch: '<S9>/Switch' incorporates:
         *  Constant: '<S1>/minThrottle'
         */
        Free_Flight_PID_RPY_Sen_B.Switch_d[k] =
          Free_Flight_PID_RPY_Sen_P.minThrottle_Value;
      } else {
        Free_Flight_PID_RPY_Sen_B.Switch_d[k] = rtb_MotorMixing;
      }

      /* End of Switch: '<S9>/Switch2' */
    }

    /* End of Gain: '<S1>/MotorMixing' */
  } else {
    Free_Flight_PID_RPY_Sen_B.Switch_d[0] =
      Free_Flight_PID_RPY_Sen_P.Paro_Value[0];
    Free_Flight_PID_RPY_Sen_B.Switch_d[1] =
      Free_Flight_PID_RPY_Sen_P.Paro_Value[1];
    Free_Flight_PID_RPY_Sen_B.Switch_d[2] =
      Free_Flight_PID_RPY_Sen_P.Paro_Value[2];
    Free_Flight_PID_RPY_Sen_B.Switch_d[3] =
      Free_Flight_PID_RPY_Sen_P.Paro_Value[3];
  }

  /* End of Switch: '<S1>/Switch' */

  /* Saturate: '<S3>/Saturation' */
  if (Free_Flight_PID_RPY_Sen_B.Switch_d[0] >
      Free_Flight_PID_RPY_Sen_P.Saturation_UpperSat) {
    rtb_DataTypeConversion5_idx_0 =
      Free_Flight_PID_RPY_Sen_P.Saturation_UpperSat;
  } else if (Free_Flight_PID_RPY_Sen_B.Switch_d[0] <
             Free_Flight_PID_RPY_Sen_P.Saturation_LowerSat) {
    rtb_DataTypeConversion5_idx_0 =
      Free_Flight_PID_RPY_Sen_P.Saturation_LowerSat;
  } else {
    rtb_DataTypeConversion5_idx_0 = Free_Flight_PID_RPY_Sen_B.Switch_d[0];
  }

  /* S-Function (sfix_bitop): '<S3>/Bitwise Operator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S3>/Gain'
   */
  rtb_BitwiseOperator_idx_0 = (uint16_T)((uint16_T)
    (Free_Flight_PID_RPY_Sen_P.Gain_Gain_f * rtb_DataTypeConversion5_idx_0 >> 12)
    & Free_Flight_PID_RPY_Sen_P.BitwiseOperator_BitMask);

  /* Saturate: '<S3>/Saturation' */
  if (Free_Flight_PID_RPY_Sen_B.Switch_d[1] >
      Free_Flight_PID_RPY_Sen_P.Saturation_UpperSat) {
    rtb_DataTypeConversion5_idx_0 =
      Free_Flight_PID_RPY_Sen_P.Saturation_UpperSat;
  } else if (Free_Flight_PID_RPY_Sen_B.Switch_d[1] <
             Free_Flight_PID_RPY_Sen_P.Saturation_LowerSat) {
    rtb_DataTypeConversion5_idx_0 =
      Free_Flight_PID_RPY_Sen_P.Saturation_LowerSat;
  } else {
    rtb_DataTypeConversion5_idx_0 = Free_Flight_PID_RPY_Sen_B.Switch_d[1];
  }

  /* S-Function (sfix_bitop): '<S3>/Bitwise Operator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S3>/Gain'
   */
  rtb_BitwiseOperator_idx_1 = (uint16_T)((uint16_T)
    (Free_Flight_PID_RPY_Sen_P.Gain_Gain_f * rtb_DataTypeConversion5_idx_0 >> 12)
    & Free_Flight_PID_RPY_Sen_P.BitwiseOperator_BitMask);

  /* Saturate: '<S3>/Saturation' */
  if (Free_Flight_PID_RPY_Sen_B.Switch_d[2] >
      Free_Flight_PID_RPY_Sen_P.Saturation_UpperSat) {
    rtb_DataTypeConversion5_idx_0 =
      Free_Flight_PID_RPY_Sen_P.Saturation_UpperSat;
  } else if (Free_Flight_PID_RPY_Sen_B.Switch_d[2] <
             Free_Flight_PID_RPY_Sen_P.Saturation_LowerSat) {
    rtb_DataTypeConversion5_idx_0 =
      Free_Flight_PID_RPY_Sen_P.Saturation_LowerSat;
  } else {
    rtb_DataTypeConversion5_idx_0 = Free_Flight_PID_RPY_Sen_B.Switch_d[2];
  }

  /* S-Function (sfix_bitop): '<S3>/Bitwise Operator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S3>/Gain'
   */
  rtb_BitwiseOperator_idx_2 = (uint16_T)((uint16_T)
    (Free_Flight_PID_RPY_Sen_P.Gain_Gain_f * rtb_DataTypeConversion5_idx_0 >> 12)
    & Free_Flight_PID_RPY_Sen_P.BitwiseOperator_BitMask);

  /* Saturate: '<S3>/Saturation' */
  if (Free_Flight_PID_RPY_Sen_B.Switch_d[3] >
      Free_Flight_PID_RPY_Sen_P.Saturation_UpperSat) {
    rtb_DataTypeConversion5_idx_0 =
      Free_Flight_PID_RPY_Sen_P.Saturation_UpperSat;
  } else if (Free_Flight_PID_RPY_Sen_B.Switch_d[3] <
             Free_Flight_PID_RPY_Sen_P.Saturation_LowerSat) {
    rtb_DataTypeConversion5_idx_0 =
      Free_Flight_PID_RPY_Sen_P.Saturation_LowerSat;
  } else {
    rtb_DataTypeConversion5_idx_0 = Free_Flight_PID_RPY_Sen_B.Switch_d[3];
  }

  /* S-Function (sfix_bitop): '<S3>/Bitwise Operator' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   *  Gain: '<S3>/Gain'
   */
  rtb_BitwiseOperator_idx_3 = (uint16_T)((uint16_T)
    (Free_Flight_PID_RPY_Sen_P.Gain_Gain_f * rtb_DataTypeConversion5_idx_0 >> 12)
    & Free_Flight_PID_RPY_Sen_P.BitwiseOperator_BitMask);

  /* DataTypeConversion: '<S3>/Data Type Conversion3' incorporates:
   *  ArithShift: '<S3>/Shift Arithmetic'
   *  ArithShift: '<S3>/Shift Arithmetic1'
   *  ArithShift: '<S3>/Shift Arithmetic2'
   *  ArithShift: '<S3>/Shift Arithmetic3'
   *  ArithShift: '<S3>/Shift Arithmetic4'
   *  ArithShift: '<S3>/Shift Arithmetic5'
   *  ArithShift: '<S3>/Shift Arithmetic6'
   *  ArithShift: '<S3>/Shift Arithmetic7'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator1'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator2'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator3'
   *  S-Function (sfix_bitop): '<S3>/Bitwise Operator4'
   */
  rtb_DataTypeConversion3[0] = (uint8_T)((uint16_T)((uint32_T)
    rtb_BitwiseOperator_idx_0 >> 4) |
    Free_Flight_PID_RPY_Sen_P.BitwiseOperator1_BitMask);
  rtb_DataTypeConversion3[1] = (uint8_T)((uint16_T)(rtb_BitwiseOperator_idx_0 <<
    4) | (uint16_T)((uint32_T)rtb_BitwiseOperator_idx_1 >> 5));
  rtb_DataTypeConversion3[2] = (uint8_T)((uint16_T)(rtb_BitwiseOperator_idx_1 <<
    3) | (uint16_T)((uint32_T)rtb_BitwiseOperator_idx_2 >> 6));
  rtb_DataTypeConversion3[3] = (uint8_T)((uint16_T)(rtb_BitwiseOperator_idx_2 <<
    2) | (uint16_T)((uint32_T)rtb_BitwiseOperator_idx_3 >> 7));
  rtb_DataTypeConversion3[4] = (uint8_T)(rtb_BitwiseOperator_idx_3 << 1);

  /* S-Function (ARDrone_Motor): '<S3>/ARDrone_Motor' */
  Free_Flight_PID_RPY_Sen_B.ARDrone_Motor = Motor_Set((uint8_T*)
    &rtb_DataTypeConversion3[0]);

  /* DiscretePulseGenerator: '<S1>/Reloj' */
  Free_Flight_PID_RPY_Sen_B.Conm = (Free_Flight_PID_RPY_Sen_DW.clockTickCounter <
    Free_Flight_PID_RPY_Sen_P.Reloj_Duty) &&
    (Free_Flight_PID_RPY_Sen_DW.clockTickCounter >= 0) ?
    Free_Flight_PID_RPY_Sen_P.Reloj_Amp : 0.0;
  if (Free_Flight_PID_RPY_Sen_DW.clockTickCounter >=
      Free_Flight_PID_RPY_Sen_P.Reloj_Period - 1.0) {
    Free_Flight_PID_RPY_Sen_DW.clockTickCounter = 0;
  } else {
    Free_Flight_PID_RPY_Sen_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Reloj' */

  /* Outputs for Triggered SubSystem: '<S1>/Medidas' incorporates:
   *  TriggerPort: '<S5>/Trigger'
   */
  zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                     &Free_Flight_PID_RPY_Sen_PrevZCX.Medidas_Trig_ZCE,
                     (Free_Flight_PID_RPY_Sen_B.Conm));
  if (zcEvent != NO_ZCEVENT) {
    /* SignalConversion: '<S5>/TmpSignal ConversionAtUDP Send2Inport1' incorporates:
     *  DataTypeConversion: '<S10>/conv'
     *  Fcn: '<S10>/M1'
     *  Fcn: '<S10>/M2'
     *  Fcn: '<S10>/M3'
     *  Fcn: '<S10>/M4'
     *  Sum: '<S10>/Sum'
     */
    Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtUDPSend2Inport1[0] =
      Free_Flight_PID_RPY_Sen_B.ChangeSign[0];
    Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtUDPSend2Inport1[1] =
      Free_Flight_PID_RPY_Sen_B.ChangeSign[1];
    Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtUDPSend2Inport1[2] =
      ((((0.00015618 * Free_Flight_PID_RPY_Sen_rt_powd_snf((real_T)
           Free_Flight_PID_RPY_Sen_B.Switch_d[0], 2.0) + 0.010395 * (real_T)
          Free_Flight_PID_RPY_Sen_B.Switch_d[0]) + 0.13894) + ((0.0001815 *
          Free_Flight_PID_RPY_Sen_rt_powd_snf((real_T)
           Free_Flight_PID_RPY_Sen_B.Switch_d[1], 2.0) + 0.0087242 * (real_T)
          Free_Flight_PID_RPY_Sen_B.Switch_d[1]) + 0.14425)) + ((0.00013478 *
         Free_Flight_PID_RPY_Sen_rt_powd_snf((real_T)
          Free_Flight_PID_RPY_Sen_B.Switch_d[2], 2.0) + 0.0073295 * (real_T)
         Free_Flight_PID_RPY_Sen_B.Switch_d[2]) + 0.11698)) + ((0.00014306 *
      Free_Flight_PID_RPY_Sen_rt_powd_snf((real_T)
      Free_Flight_PID_RPY_Sen_B.Switch_d[3], 2.0) + 0.0057609 * (real_T)
      Free_Flight_PID_RPY_Sen_B.Switch_d[3]) + 0.13362);

    /* Update for S-Function (sdspToNetwork): '<S5>/UDP Send2' */
    sErr = GetErrorBuffer(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U]);
    LibUpdate_Network(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U],
                      &Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtUDPSend2Inport1
                      [0U], 3);
    if (*sErr != 0) {
      rtmSetErrorStatus(Free_Flight_PID_RPY_Sen_M, sErr);
      rtmSetStopRequested(Free_Flight_PID_RPY_Sen_M, 1);
    }

    /* End of Update for S-Function (sdspToNetwork): '<S5>/UDP Send2' */
    Free_Flight_PID_RPY_Sen_DW.Medidas_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S1>/Medidas' */

  /* DeadZone: '<S11>/DeadZone' incorporates:
   *  Gain: '<S11>/ZeroGain'
   */
  if (Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 >
      Free_Flight_PID_RPY_Sen_P.PIDRP_UpperSaturationLimit) {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c =
      Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 -
      Free_Flight_PID_RPY_Sen_P.PIDRP_UpperSaturationLimit;
  } else if (Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 >=
             Free_Flight_PID_RPY_Sen_P.PIDRP_LowerSaturationLimit) {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c = 0.0;
  } else {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c =
      Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 -
      Free_Flight_PID_RPY_Sen_P.PIDRP_LowerSaturationLimit;
  }

  /* RelationalOperator: '<S11>/NotEqual' incorporates:
   *  Gain: '<S11>/ZeroGain'
   */
  b_p = (Free_Flight_PID_RPY_Sen_P.ZeroGain_Gain *
         Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 !=
         Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c);

  /* Signum: '<S11>/SignDeltaU' */
  if (Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c < 0.0) {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c = -1.0;
  } else if (Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c > 0.0) {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c = 1.0;
  } else {
    if (Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c == 0.0) {
      Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c = 0.0;
    }
  }

  /* Gain: '<S6>/Integral Gain' */
  Free_Flight_PID_RPY_Sen_B.Conm = Free_Flight_PID_RPY_Sen_P.PIDRP_I *
    Free_Flight_PID_RPY_Sen_B.IntegralGain[0];

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  DataTypeConversion: '<S11>/DataTypeConv1'
   *  DataTypeConversion: '<S11>/DataTypeConv2'
   *  DeadZone: '<S11>/DeadZone'
   *  Logic: '<S11>/AND'
   *  RelationalOperator: '<S11>/Equal'
   */
  if (Free_Flight_PID_RPY_Sen_B.Conm < 0.0) {
    Free_Flight_PID_RPY_Sen_B.u0 = -1.0;
  } else if (Free_Flight_PID_RPY_Sen_B.Conm > 0.0) {
    Free_Flight_PID_RPY_Sen_B.u0 = 1.0;
  } else if (Free_Flight_PID_RPY_Sen_B.Conm == 0.0) {
    Free_Flight_PID_RPY_Sen_B.u0 = 0.0;
  } else {
    Free_Flight_PID_RPY_Sen_B.u0 = Free_Flight_PID_RPY_Sen_B.Conm;
  }

  Free_Flight_PID_RPY_Sen_B.u0 = floor(Free_Flight_PID_RPY_Sen_B.u0);
  if (rtIsNaN(Free_Flight_PID_RPY_Sen_B.u0) || rtIsInf
      (Free_Flight_PID_RPY_Sen_B.u0)) {
    Free_Flight_PID_RPY_Sen_B.u0 = 0.0;
  } else {
    Free_Flight_PID_RPY_Sen_B.u0 = fmod(Free_Flight_PID_RPY_Sen_B.u0, 256.0);
  }

  if (Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c < 128.0) {
    rtb_SignDeltaU_0 = (int8_T)Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c;
  } else {
    rtb_SignDeltaU_0 = MAX_int8_T;
  }

  if (b_p && ((Free_Flight_PID_RPY_Sen_B.u0 < 0.0 ? (int32_T)(int8_T)-(int8_T)
               (uint8_T)-Free_Flight_PID_RPY_Sen_B.u0 : (int32_T)(int8_T)
               (uint8_T)Free_Flight_PID_RPY_Sen_B.u0) == rtb_SignDeltaU_0)) {
    Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 =
      Free_Flight_PID_RPY_Sen_P.Constant_Value_b;
  } else {
    Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2 = Free_Flight_PID_RPY_Sen_B.Conm;
  }

  /* DeadZone: '<S11>/DeadZone' incorporates:
   *  Gain: '<S11>/ZeroGain'
   */
  if (Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 >
      Free_Flight_PID_RPY_Sen_P.PIDRP_UpperSaturationLimit) {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c =
      Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 -
      Free_Flight_PID_RPY_Sen_P.PIDRP_UpperSaturationLimit;
  } else if (Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 >=
             Free_Flight_PID_RPY_Sen_P.PIDRP_LowerSaturationLimit) {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c = 0.0;
  } else {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c =
      Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 -
      Free_Flight_PID_RPY_Sen_P.PIDRP_LowerSaturationLimit;
  }

  /* RelationalOperator: '<S11>/NotEqual' incorporates:
   *  Gain: '<S11>/ZeroGain'
   */
  b_p = (Free_Flight_PID_RPY_Sen_P.ZeroGain_Gain *
         Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_1 !=
         Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c);

  /* Signum: '<S11>/SignDeltaU' */
  if (Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c < 0.0) {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c = -1.0;
  } else if (Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c > 0.0) {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c = 1.0;
  } else {
    if (Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c == 0.0) {
      Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c = 0.0;
    }
  }

  /* Gain: '<S6>/Integral Gain' */
  Free_Flight_PID_RPY_Sen_B.Conm = Free_Flight_PID_RPY_Sen_P.PIDRP_I *
    Free_Flight_PID_RPY_Sen_B.IntegralGain[1];

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   *  DataTypeConversion: '<S11>/DataTypeConv1'
   *  DataTypeConversion: '<S11>/DataTypeConv2'
   *  Logic: '<S11>/AND'
   *  RelationalOperator: '<S11>/Equal'
   */
  if (Free_Flight_PID_RPY_Sen_B.Conm < 0.0) {
    Free_Flight_PID_RPY_Sen_B.u0 = -1.0;
  } else if (Free_Flight_PID_RPY_Sen_B.Conm > 0.0) {
    Free_Flight_PID_RPY_Sen_B.u0 = 1.0;
  } else if (Free_Flight_PID_RPY_Sen_B.Conm == 0.0) {
    Free_Flight_PID_RPY_Sen_B.u0 = 0.0;
  } else {
    Free_Flight_PID_RPY_Sen_B.u0 = Free_Flight_PID_RPY_Sen_B.Conm;
  }

  Free_Flight_PID_RPY_Sen_B.u0 = floor(Free_Flight_PID_RPY_Sen_B.u0);
  if (rtIsNaN(Free_Flight_PID_RPY_Sen_B.u0) || rtIsInf
      (Free_Flight_PID_RPY_Sen_B.u0)) {
    Free_Flight_PID_RPY_Sen_B.u0 = 0.0;
  } else {
    Free_Flight_PID_RPY_Sen_B.u0 = fmod(Free_Flight_PID_RPY_Sen_B.u0, 256.0);
  }

  if (Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c < 128.0) {
    rtb_SignDeltaU_0 = (int8_T)Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c;
  } else {
    rtb_SignDeltaU_0 = MAX_int8_T;
  }

  if (b_p && ((Free_Flight_PID_RPY_Sen_B.u0 < 0.0 ? (int32_T)(int8_T)-(int8_T)
               (uint8_T)-Free_Flight_PID_RPY_Sen_B.u0 : (int32_T)(int8_T)
               (uint8_T)Free_Flight_PID_RPY_Sen_B.u0) == rtb_SignDeltaU_0)) {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c =
      Free_Flight_PID_RPY_Sen_P.Constant_Value_b;
  } else {
    Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c = Free_Flight_PID_RPY_Sen_B.Conm;
  }

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  DataTypeConversion: '<S13>/Data Type Conversion1'
   */
  /* MATLAB Function 'Navigation System/Measurement calibration correction/MATLAB Function': '<S30>:1' */
  /* '<S30>:1:4' */
  if (rtb_validImuData_ultrasound < 10000) {
    /* '<S30>:1:11' */
    /* '<S30>:1:12' */
    Free_Flight_PID_RPY_Sen_DW.validHeight = ((real_T)
      rtb_validImuData_ultrasound - 880.0) / 26.533;
  }

  /* MATLAB Function: '<S18>/Kalman Tracker' incorporates:
   *  MATLAB Function: '<S15>/MATLAB Function'
   *  UnitDelay: '<S18>/Unit Delay1'
   *  UnitDelay: '<S18>/Unit Delay2'
   */
  /* '<S30>:1:15' */
  /* MATLAB Function 'Navigation System/Kalman Filter/Ultrasound Estimator/Kalman Tracker': '<S26>:1' */
  /* '<S26>:1:47' */
  /* '<S26>:1:27' */
  /* '<S26>:1:26' */
  /* ------------------------------- */
  /* ---- Predict Stage ------------ */
  /* ------------------------------- */
  /* our states: */
  /*   [Wx Wy Wz Bx By Bz   ] */
  /*  */
  /* Process Noise */
  /* '<S26>:1:18' */
  /* A matrix */
  /* odutput these values with a unit delay (for algebraic loop), apply initial conditions */
  /* '<S26>:1:26' */
  /* '<S26>:1:27' */
  for (k = 0; k < 2; k++) {
    Free_Flight_PID_RPY_Sen_B.a[k] = 0.0;
    Free_Flight_PID_RPY_Sen_B.a[k] += a_1[k] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[0];
    Free_Flight_PID_RPY_Sen_B.a[k] += a_1[k + 2] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[1];
    Free_Flight_PID_RPY_Sen_B.a[k + 2] = 0.0;
    Free_Flight_PID_RPY_Sen_B.a[k + 2] += a_1[k] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[2];
    Free_Flight_PID_RPY_Sen_B.a[k + 2] += a_1[k + 2] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[3];
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_[k] =
      (Free_Flight_PID_RPY_Sen_B.a[k + 2] * 0.0025 +
       Free_Flight_PID_RPY_Sen_B.a[k]) + Q_1[k];
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_[k + 2] =
      (Free_Flight_PID_RPY_Sen_B.a[k] * 0.0 + Free_Flight_PID_RPY_Sen_B.a[k + 2])
      + Q_1[k + 2];
    Free_Flight_PID_RPY_Sen_B.IntegralGain[k] = a_1[k + 2] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_h[1] + a_1[k] *
      Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_h[0];
  }

  /* ------------------------------- */
  /* ---- Estimate Stage ----------- */
  /* ------------------------------- */
  /* H matrix */
  /* Measurement noise */
  /*      m_var_r = 1; */
  /* '<S26>:1:41' */
  /* Measurement Z */
  /* Compute Kalman Gain */
  /* '<S26>:1:47' */
  Free_Flight_PID_RPY_Sen_B.Conm = 1.0 / (((0.0 *
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_[3] +
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_[2]) * 0.0 + (0.0 *
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_[1] +
    Free_Flight_PID_RPY_Sen_B.covariance_prediction_[0])) + 1.0);

  /* 2x2 matrix */
  /* compute state space correction based on measurement */
  /* '<S26>:1:50' */
  Free_Flight_PID_RPY_Sen_B.ZeroGain[0] =
    (Free_Flight_PID_RPY_Sen_B.covariance_prediction_[2] * 0.0 +
     Free_Flight_PID_RPY_Sen_B.covariance_prediction_[0]) *
    Free_Flight_PID_RPY_Sen_B.Conm;
  Free_Flight_PID_RPY_Sen_B.ZeroGain[1] =
    (Free_Flight_PID_RPY_Sen_B.covariance_prediction_[3] * 0.0 +
     Free_Flight_PID_RPY_Sen_B.covariance_prediction_[1]) *
    Free_Flight_PID_RPY_Sen_B.Conm;
  Free_Flight_PID_RPY_Sen_B.Conm = Free_Flight_PID_RPY_Sen_DW.validHeight - (0.0
    * Free_Flight_PID_RPY_Sen_B.IntegralGain[1] +
    Free_Flight_PID_RPY_Sen_B.IntegralGain[0]);

  /* 2x1 vector of states */
  /* compute covariance correction */
  /* '<S26>:1:53' */
  I_1[1] = 0;
  I_1[2] = 0;

  /* 2x2 covariance matrix */
  I_1[0] = 1;
  Free_Flight_PID_RPY_Sen_B.IntegralGain[0] +=
    Free_Flight_PID_RPY_Sen_B.ZeroGain[0] * Free_Flight_PID_RPY_Sen_B.Conm;
  I_1[3] = 1;
  Free_Flight_PID_RPY_Sen_B.IntegralGain[1] +=
    Free_Flight_PID_RPY_Sen_B.ZeroGain[1] * Free_Flight_PID_RPY_Sen_B.Conm;

  /* Update for Sin: '<Root>/Roll_sin' */
  Free_Flight_PID_RPY_Sen_B.Conm = Free_Flight_PID_RPY_Sen_DW.lastSin;
  Free_Flight_PID_RPY_Sen_DW.lastSin = Free_Flight_PID_RPY_Sen_DW.lastSin *
    Free_Flight_PID_RPY_Sen_P.Roll_sin_HCos + Free_Flight_PID_RPY_Sen_DW.lastCos
    * Free_Flight_PID_RPY_Sen_P.Roll_sin_Hsin;
  Free_Flight_PID_RPY_Sen_DW.lastCos = Free_Flight_PID_RPY_Sen_DW.lastCos *
    Free_Flight_PID_RPY_Sen_P.Roll_sin_HCos - Free_Flight_PID_RPY_Sen_B.Conm *
    Free_Flight_PID_RPY_Sen_P.Roll_sin_Hsin;

  /* Update for Sin: '<Root>/Pitch_sin' */
  Free_Flight_PID_RPY_Sen_B.Conm = Free_Flight_PID_RPY_Sen_DW.lastSin_c;
  Free_Flight_PID_RPY_Sen_DW.lastSin_c = Free_Flight_PID_RPY_Sen_DW.lastSin_c *
    Free_Flight_PID_RPY_Sen_P.Pitch_sin_HCos +
    Free_Flight_PID_RPY_Sen_DW.lastCos_b *
    Free_Flight_PID_RPY_Sen_P.Pitch_sin_Hsin;
  Free_Flight_PID_RPY_Sen_DW.lastCos_b = Free_Flight_PID_RPY_Sen_DW.lastCos_b *
    Free_Flight_PID_RPY_Sen_P.Pitch_sin_HCos - Free_Flight_PID_RPY_Sen_B.Conm *
    Free_Flight_PID_RPY_Sen_P.Pitch_sin_Hsin;

  /* Update for UnitDelay: '<S32>/Unit Delay' */
  Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_e[0] =
    Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_0;
  Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_e[1] =
    Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_1;
  Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_e[2] =
    Free_Flight_PID_RPY_Sen_B.rtb_DataTypeConversion_idx_2;
  for (k = 0; k < 2; k++) {
    /* Update for UnitDelay: '<S21>/Unit Delay1' */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE[k] =
      Free_Flight_PID_RPY_Sen_B.state_correction_j[k];

    /* MATLAB Function: '<S21>/Kalman Tracker' */
    Free_Flight_PID_RPY_Sen_B.a[k] = (real_T)I[k] -
      Free_Flight_PID_RPY_Sen_B.Kalman_Gain[k];
    Free_Flight_PID_RPY_Sen_B.a[k + 2] = (real_T)I[k + 2] -
      Free_Flight_PID_RPY_Sen_B.Kalman_Gain[k] * 0.0;

    /* Update for UnitDelay: '<S21>/Unit Delay' incorporates:
     *  MATLAB Function: '<S21>/Kalman Tracker'
     */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[k] = 0.0;
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[k] +=
      Free_Flight_PID_RPY_Sen_B.a[k] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction[0];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[k] +=
      Free_Flight_PID_RPY_Sen_B.a[k + 2] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction[1];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[k + 2] = 0.0;
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[k + 2] +=
      Free_Flight_PID_RPY_Sen_B.a[k] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction[2];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[k + 2] +=
      Free_Flight_PID_RPY_Sen_B.a[k + 2] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction[3];

    /* Update for UnitDelay: '<S20>/Unit Delay1' */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_k[k] =
      Free_Flight_PID_RPY_Sen_B.state_correction_b[k];

    /* MATLAB Function: '<S20>/Kalman Tracker' */
    Free_Flight_PID_RPY_Sen_B.I[k] = (real_T)I_0[k] -
      Free_Flight_PID_RPY_Sen_B.Kalman_Gain_c[k];
    Free_Flight_PID_RPY_Sen_B.I[k + 2] = (real_T)I_0[k + 2] -
      Free_Flight_PID_RPY_Sen_B.Kalman_Gain_c[k] * 0.0;

    /* Update for UnitDelay: '<S20>/Unit Delay' incorporates:
     *  MATLAB Function: '<S20>/Kalman Tracker'
     */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[k] = 0.0;
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[k] +=
      Free_Flight_PID_RPY_Sen_B.I[k] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[0];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[k] +=
      Free_Flight_PID_RPY_Sen_B.I[k + 2] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[1];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[k + 2] = 0.0;
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[k + 2] +=
      Free_Flight_PID_RPY_Sen_B.I[k] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[2];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[k + 2] +=
      Free_Flight_PID_RPY_Sen_B.I[k + 2] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction_m[3];
  }

  /* Update for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
  Free_Flight_PID_RPY_Sen_DW.DiscreteTimeIntegrator1_DSTATE +=
    Free_Flight_PID_RPY_Sen_P.DiscreteTimeIntegrator1_gainval *
    Free_Flight_PID_RPY_Sen_B.Gain[2];

  /* Update for DiscreteTransferFcn: '<S1>/Filtro_vel' */
  Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[0] =
    (Free_Flight_PID_RPY_Sen_B.Gain[0] -
     Free_Flight_PID_RPY_Sen_P.Filtro_vel_DenCoef[1] *
     Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[0]) /
    Free_Flight_PID_RPY_Sen_P.Filtro_vel_DenCoef[0];
  Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[1] =
    (Free_Flight_PID_RPY_Sen_B.Gain[1] -
     Free_Flight_PID_RPY_Sen_P.Filtro_vel_DenCoef[1] *
     Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[1]) /
    Free_Flight_PID_RPY_Sen_P.Filtro_vel_DenCoef[0];
  Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[2] =
    (Free_Flight_PID_RPY_Sen_B.Gain[2] -
     Free_Flight_PID_RPY_Sen_P.Filtro_vel_DenCoef[1] *
     Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[2]) /
    Free_Flight_PID_RPY_Sen_P.Filtro_vel_DenCoef[0];

  /* Update for DiscreteIntegrator: '<S6>/Integrator' */
  if (!rtb_u) {
    Free_Flight_PID_RPY_Sen_DW.Integrator_DSTATE[0] +=
      Free_Flight_PID_RPY_Sen_P.Integrator_gainval *
      Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_2;
    Free_Flight_PID_RPY_Sen_DW.Integrator_DSTATE[1] +=
      Free_Flight_PID_RPY_Sen_P.Integrator_gainval *
      Free_Flight_PID_RPY_Sen_B.rtb_SignDeltaU_c;
  }

  Free_Flight_PID_RPY_Sen_DW.Integrator_PrevResetState = (int8_T)rtb_u;

  /* End of Update for DiscreteIntegrator: '<S6>/Integrator' */

  /* Update for DiscreteIntegrator: '<S6>/Filter' */
  if (!rtb_u) {
    Free_Flight_PID_RPY_Sen_DW.Filter_DSTATE[0] +=
      Free_Flight_PID_RPY_Sen_P.Filter_gainval *
      Free_Flight_PID_RPY_Sen_B.rtb_conv_idx_0;
    Free_Flight_PID_RPY_Sen_DW.Filter_DSTATE[1] +=
      Free_Flight_PID_RPY_Sen_P.Filter_gainval *
      Free_Flight_PID_RPY_Sen_B.rtb_FilterCoefficient_k;
  }

  Free_Flight_PID_RPY_Sen_DW.Filter_PrevResetState = (int8_T)rtb_u;

  /* End of Update for DiscreteIntegrator: '<S6>/Filter' */

  /* Update for DiscreteIntegrator: '<S8>/Ki' */
  if (!rtb_u) {
    Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE += Free_Flight_PID_RPY_Sen_P.Ki_gainval
      * Free_Flight_PID_RPY_Sen_B.Sum2;
    if (Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE >=
        Free_Flight_PID_RPY_Sen_P.Ki_UpperSat) {
      Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE =
        Free_Flight_PID_RPY_Sen_P.Ki_UpperSat;
    } else {
      if (Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE <=
          Free_Flight_PID_RPY_Sen_P.Ki_LowerSat) {
        Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE =
          Free_Flight_PID_RPY_Sen_P.Ki_LowerSat;
      }
    }
  }

  Free_Flight_PID_RPY_Sen_DW.Ki_PrevResetState = (int8_T)rtb_u;

  /* End of Update for DiscreteIntegrator: '<S8>/Ki' */
  for (k = 0; k < 2; k++) {
    /* MATLAB Function: '<S18>/Kalman Tracker' */
    Free_Flight_PID_RPY_Sen_B.a[k] = (real_T)I_1[k] -
      Free_Flight_PID_RPY_Sen_B.ZeroGain[k];
    Free_Flight_PID_RPY_Sen_B.a[k + 2] = (real_T)I_1[k + 2] -
      Free_Flight_PID_RPY_Sen_B.ZeroGain[k] * 0.0;

    /* Update for UnitDelay: '<S18>/Unit Delay2' incorporates:
     *  MATLAB Function: '<S18>/Kalman Tracker'
     */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[k] = 0.0;
    Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[k] +=
      Free_Flight_PID_RPY_Sen_B.a[k] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction_[0];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[k] +=
      Free_Flight_PID_RPY_Sen_B.a[k + 2] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction_[1];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[k + 2] = 0.0;
    Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[k + 2] +=
      Free_Flight_PID_RPY_Sen_B.a[k] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction_[2];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[k + 2] +=
      Free_Flight_PID_RPY_Sen_B.a[k + 2] *
      Free_Flight_PID_RPY_Sen_B.covariance_prediction_[3];

    /* Update for UnitDelay: '<S18>/Unit Delay1' */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_h[k] =
      Free_Flight_PID_RPY_Sen_B.IntegralGain[k];
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, Free_Flight_PID_RPY_Sen_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0025s, 0.0s] */
    if ((rtmGetTFinal(Free_Flight_PID_RPY_Sen_M)!=-1) &&
        !((rtmGetTFinal(Free_Flight_PID_RPY_Sen_M)-
           Free_Flight_PID_RPY_Sen_M->Timing.taskTime0) >
          Free_Flight_PID_RPY_Sen_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Free_Flight_PID_RPY_Sen_M, "Simulation finished");
    }

    if (rtmGetStopRequested(Free_Flight_PID_RPY_Sen_M)) {
      rtmSetErrorStatus(Free_Flight_PID_RPY_Sen_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Free_Flight_PID_RPY_Sen_M->Timing.taskTime0 =
    (++Free_Flight_PID_RPY_Sen_M->Timing.clockTick0) *
    Free_Flight_PID_RPY_Sen_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void Free_Flight_PID_RPY_Sen_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  /* S-Function (UDP_Recv_Sfcn): '<S1>/S-Function' */
  Free_Flight_PID_RPY_Sen_B.SFunction_o1 = udp_recv
    (Free_Flight_PID_RPY_Sen_P.Port_Value,
     Free_Flight_PID_RPY_Sen_P.BlockingTimeus_Value,
     &Free_Flight_PID_RPY_Sen_B.SFunction_o2[0]);

  /* Unpack: <S1>/Byte Unpack */
  (void) memcpy(&Free_Flight_PID_RPY_Sen_B.ByteUnpack[0],
                &Free_Flight_PID_RPY_Sen_B.SFunction_o2[0],
                32);
  rtExtModeUpload(1, ((Free_Flight_PID_RPY_Sen_M->Timing.clockTick1) * 0.1));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Free_Flight_PID_RPY_Sen_M->Timing.clockTick1++;
}

/* Model step wrapper function for compatibility with a static main program */
void Free_Flight_PID_RPY_Sen_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Free_Flight_PID_RPY_Sen_step0();
    break;

   case 1 :
    Free_Flight_PID_RPY_Sen_step1();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Free_Flight_PID_RPY_Sen_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Free_Flight_PID_RPY_Sen_M, 0,
                sizeof(RT_MODEL_Free_Flight_PID_RPY_Sen_T));
  rtmSetTFinal(Free_Flight_PID_RPY_Sen_M, -1);
  Free_Flight_PID_RPY_Sen_M->Timing.stepSize0 = 0.0025;

  /* External mode info */
  Free_Flight_PID_RPY_Sen_M->Sizes.checksums[0] = (1929515908U);
  Free_Flight_PID_RPY_Sen_M->Sizes.checksums[1] = (3259548639U);
  Free_Flight_PID_RPY_Sen_M->Sizes.checksums[2] = (2351579559U);
  Free_Flight_PID_RPY_Sen_M->Sizes.checksums[3] = (802697372U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[13];
    Free_Flight_PID_RPY_Sen_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = (sysRanDType *)
      &Free_Flight_PID_RPY_Sen_DW.Medidas_SubsysRanBC;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Free_Flight_PID_RPY_Sen_M->extModeInfo,
      &Free_Flight_PID_RPY_Sen_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Free_Flight_PID_RPY_Sen_M->extModeInfo,
                        Free_Flight_PID_RPY_Sen_M->Sizes.checksums);
    rteiSetTPtr(Free_Flight_PID_RPY_Sen_M->extModeInfo, rtmGetTPtr
                (Free_Flight_PID_RPY_Sen_M));
  }

  /* block I/O */
  (void) memset(((void *) &Free_Flight_PID_RPY_Sen_B), 0,
                sizeof(B_Free_Flight_PID_RPY_Sen_T));

  /* states (dwork) */
  (void) memset((void *)&Free_Flight_PID_RPY_Sen_DW, 0,
                sizeof(DW_Free_Flight_PID_RPY_Sen_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Free_Flight_PID_RPY_Sen_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 18;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    char_T *sErr;

    /* Start for DiscretePulseGenerator: '<S1>/Reloj' */
    Free_Flight_PID_RPY_Sen_DW.clockTickCounter = 0;

    /* Start for Triggered SubSystem: '<S1>/Medidas' */
    /* Start for S-Function (sdspToNetwork): '<S5>/UDP Send2' */
    sErr = GetErrorBuffer(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U]);
    CreateUDPInterface(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U]);
    if (*sErr == 0) {
      LibCreate_Network(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U], 1,
                        "0.0.0.0", -1, "192.168.1.2", 50000, 8192, 8, 0);
    }

    if (*sErr == 0) {
      LibStart(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U]);
    }

    if (*sErr != 0) {
      DestroyUDPInterface(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U]);
      if (*sErr != 0) {
        rtmSetErrorStatus(Free_Flight_PID_RPY_Sen_M, sErr);
        rtmSetStopRequested(Free_Flight_PID_RPY_Sen_M, 1);
      }
    }

    /* End of Start for S-Function (sdspToNetwork): '<S5>/UDP Send2' */
    /* End of Start for SubSystem: '<S1>/Medidas' */
    /* Start for S-Function (Init_Actuator): '<Root>/Initialize_Actuators' */
    Actuator_Initialization();
    Free_Flight_PID_RPY_Sen_PrevZCX.Medidas_Trig_ZCE = UNINITIALIZED_ZCSIG;

    /* InitializeConditions for UnitDelay: '<S21>/Unit Delay1' */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE[0] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay1_InitialCondition[0];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE[1] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay1_InitialCondition[1];

    /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[0] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition[0];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[1] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition[1];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[2] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition[2];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE[3] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition[3];

    /* InitializeConditions for S-Function (IMU_Sfcn_mex): '<S2>/IMU Read' */
    MDL_IMU_start();

    /* InitializeConditions for UnitDelay: '<S32>/Unit Delay' */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_e[0] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition_a;
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_e[1] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition_a;
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_e[2] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition_a;

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay1' */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_k[0] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay1_InitialCondition_f[0];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_k[1] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay1_InitialCondition_f[1];

    /* InitializeConditions for UnitDelay: '<S20>/Unit Delay' */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[0] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition_k[0];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[1] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition_k[1];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[2] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition_k[2];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay_DSTATE_h[3] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay_InitialCondition_k[3];

    /* InitializeConditions for DiscreteIntegrator: '<S14>/Discrete-Time Integrator1' */
    Free_Flight_PID_RPY_Sen_DW.DiscreteTimeIntegrator1_DSTATE =
      Free_Flight_PID_RPY_Sen_P.DiscreteTimeIntegrator1_IC;

    /* InitializeConditions for DiscreteTransferFcn: '<S1>/Filtro_vel' */
    Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[0] =
      Free_Flight_PID_RPY_Sen_P.Filtro_vel_InitialStates;
    Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[1] =
      Free_Flight_PID_RPY_Sen_P.Filtro_vel_InitialStates;
    Free_Flight_PID_RPY_Sen_DW.Filtro_vel_states[2] =
      Free_Flight_PID_RPY_Sen_P.Filtro_vel_InitialStates;

    /* InitializeConditions for DiscreteIntegrator: '<S6>/Integrator' */
    Free_Flight_PID_RPY_Sen_DW.Integrator_PrevResetState = 0;
    Free_Flight_PID_RPY_Sen_DW.Integrator_DSTATE[0] =
      Free_Flight_PID_RPY_Sen_P.Integrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S6>/Filter' */
    Free_Flight_PID_RPY_Sen_DW.Filter_DSTATE[0] =
      Free_Flight_PID_RPY_Sen_P.Filter_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S6>/Integrator' */
    Free_Flight_PID_RPY_Sen_DW.Integrator_DSTATE[1] =
      Free_Flight_PID_RPY_Sen_P.Integrator_IC;

    /* InitializeConditions for DiscreteIntegrator: '<S6>/Filter' */
    Free_Flight_PID_RPY_Sen_DW.Filter_DSTATE[1] =
      Free_Flight_PID_RPY_Sen_P.Filter_IC;
    Free_Flight_PID_RPY_Sen_DW.Filter_PrevResetState = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S8>/Ki' */
    Free_Flight_PID_RPY_Sen_DW.Ki_DSTATE = Free_Flight_PID_RPY_Sen_P.Ki_IC;
    Free_Flight_PID_RPY_Sen_DW.Ki_PrevResetState = 0;

    /* InitializeConditions for UnitDelay: '<S18>/Unit Delay2' */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[0] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay2_InitialCondition[0];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[1] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay2_InitialCondition[1];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[2] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay2_InitialCondition[2];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay2_DSTATE[3] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay2_InitialCondition[3];

    /* InitializeConditions for UnitDelay: '<S18>/Unit Delay1' */
    Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_h[0] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay1_InitialCondition_d[0];
    Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE_h[1] =
      Free_Flight_PID_RPY_Sen_P.UnitDelay1_InitialCondition_d[1];

    /* SystemInitialize for MATLAB Function: '<S4>/Verify IMU Data' */
    Free_Flight_PID_RPY_Sen_DW.storedGoodPacket_not_empty = false;
    Free_Flight_PID_RPY_Sen_DW.storedBadChecksum_not_empty = false;

    /* SystemInitialize for MATLAB Function: '<S15>/MATLAB Function' */
    Free_Flight_PID_RPY_Sen_DW.validHeight = 0.0;

    /* Enable for Sin: '<Root>/Roll_sin' */
    Free_Flight_PID_RPY_Sen_DW.systemEnable = 1;

    /* Enable for Sin: '<Root>/Pitch_sin' */
    Free_Flight_PID_RPY_Sen_DW.systemEnable_d = 1;
  }
}

/* Model terminate function */
void Free_Flight_PID_RPY_Sen_terminate(void)
{
  char_T *sErr;

  /* Terminate for S-Function (IMU_Sfcn_mex): '<S2>/IMU Read' */
  MDL_IMU_term();

  /* Terminate for Triggered SubSystem: '<S1>/Medidas' */
  /* Terminate for S-Function (sdspToNetwork): '<S5>/UDP Send2' */
  sErr = GetErrorBuffer(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U]);
  LibTerminate(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U]);
  if (*sErr != 0) {
    rtmSetErrorStatus(Free_Flight_PID_RPY_Sen_M, sErr);
    rtmSetStopRequested(Free_Flight_PID_RPY_Sen_M, 1);
  }

  LibDestroy(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U], 1);
  DestroyUDPInterface(&Free_Flight_PID_RPY_Sen_DW.UDPSend2_NetworkLib[0U]);

  /* End of Terminate for S-Function (sdspToNetwork): '<S5>/UDP Send2' */
  /* End of Terminate for SubSystem: '<S1>/Medidas' */
  /* Terminate for S-Function (UDP_Recv_Sfcn): '<S1>/S-Function' */
  udp_recv_close();

  /* Terminate for S-Function (Init_Actuator): '<Root>/Initialize_Actuators' */
  Actuator_Stop();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
