/*
 * Free_Flight_PID_RPY_Sen_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Free_Flight_PID_RPY_Sen".
 *
 * Model version              : 1.1047
 * Simulink Coder version : 8.11 (R2016b) 25-Aug-2016
 * C source code generated on : Fri Apr 29 11:49:28 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(IMU_Packets),
  sizeof(struct_5JPrVIIyMJvsnF3ilQUpkH),
  sizeof(int16_T),
  sizeof(int32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "IMU_Packets",
  "struct_5JPrVIIyMJvsnF3ilQUpkH",
  "int16_T",
  "int32_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Free_Flight_PID_RPY_Sen_B.TmpSignalConversionAtWork_refInport1[0]),
    0, 0, 4 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_B.Gain[0]), 0, 0, 13 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_B.Empuje), 0, 0, 4 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_B.SFunction_o1), 6, 0, 1 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_B.Switch_d[0]), 4, 0, 4 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_B.ARDrone_Motor), 5, 0, 1 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_B.SFunction_o2[0]), 3, 0, 32 }
  ,

  { (char_T *)(&Free_Flight_PID_RPY_Sen_DW.storedGoodPacket), 14, 0, 1 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_DW.UnitDelay1_DSTATE[0]), 0, 0, 172 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_DW.Work_ang_PWORK.LoggedData), 11, 0, 4
  },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_DW.systemEnable), 6, 0, 3 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_DW.storedBadChecksum), 5, 0, 1 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_DW.Integrator_PrevResetState), 2, 0, 4 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_DW.storedGoodPacket_not_empty), 8, 0, 2
  }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  14U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Free_Flight_PID_RPY_Sen_P.accelerometerXyzGains[0]), 0, 0, 97 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_P.Port_Value), 6, 0, 1 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_P.Paro_Value[0]), 4, 0, 24 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_P.BitwiseOperator_BitMask), 5, 0, 2 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_P.Gain_Gain_f), 16, 0, 1 },

  { (char_T *)(&Free_Flight_PID_RPY_Sen_P.Conm_CurrentSetting), 3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] Free_Flight_PID_RPY_Sen_dt.h */
