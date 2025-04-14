/*
 * Feedforward_tunning_model_Control_Engineering_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Feedforward_tunning_model_Control_Engineering".
 *
 * Model version              : 11.68
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Apr 18 11:17:23 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
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
  sizeof(int32_T),
  sizeof(int64_T),
  sizeof(uint64_T),
  sizeof(uint64_T),
  sizeof(int64_T),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
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
  "physical_connection",
  "int64_T",
  "uint64_T",
  "uint64_T",
  "int64_T",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Feedforward_tunning_model_Control_Engineering_B.Startsetpoint),
    0, 0, 35 }
  ,

  { (char_T *)
    (&Feedforward_tunning_model_Control_Engineering_DW.Downsample_Buffer[0]), 0,
    0, 54 },

  { (char_T *)
    (&Feedforward_tunning_model_Control_Engineering_DW.Velocity_PWORK.LoggedData),
    11, 0, 25 },

  { (char_T *)(&Feedforward_tunning_model_Control_Engineering_DW.sfEvent), 6, 0,
    1 },

  { (char_T *)(&Feedforward_tunning_model_Control_Engineering_DW.NS), 7, 0, 1 },

  { (char_T *)(&Feedforward_tunning_model_Control_Engineering_DW.NF), 4, 0, 1 },

  { (char_T *)
    (&Feedforward_tunning_model_Control_Engineering_DW.is_active_c1_Feedforward_tunnin),
    3, 0, 2 },

  { (char_T *)
    (&Feedforward_tunning_model_Control_Engineering_DW.doneDoubleBufferReInit),
    8, 0, 27 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  8U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)
    (&Feedforward_tunning_model_Control_Engineering_P.SFunction_P1_Size[0]), 0,
    0, 21 },

  { (char_T *)
    (&Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_N_samples),
    7, 0, 1 },

  { (char_T *)
    (&Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_trigger_comman),
    3, 0, 2 },

  { (char_T *)(&Feedforward_tunning_model_Control_Engineering_P.Gain_Gain), 0, 0,
    28 },

  { (char_T *)
    (&Feedforward_tunning_model_Control_Engineering_P.Selectencoder_CurrentSetting),
    3, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  5U,
  rtPTransitions
};

/* [EOF] Feedforward_tunning_model_Control_Engineering_dt.h */
