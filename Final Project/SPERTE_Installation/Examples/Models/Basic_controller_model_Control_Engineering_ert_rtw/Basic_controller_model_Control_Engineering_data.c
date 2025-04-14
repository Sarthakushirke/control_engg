/*
 * Basic_controller_model_Control_Engineering_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Basic_controller_model_Control_Engineering".
 *
 * Model version              : 11.26
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Apr  2 14:28:56 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Basic_controller_model_Control_Engineering.h"

/* Block parameters (default storage) */
P_Basic_controller_model_Control_Engineering_T
  Basic_controller_model_Control_Engineering_P = {
  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S6>/S-Function'
   */
  { 3.0, 6.0 },

  /* Variable: ref_part
   * Referenced by: '<S6>/S-Function'
   */
  { 0.0, 125.0, 0.0, 0.0, 6.2113, -1.0, 125.0, 0.0, 0.0, 24.0, 24.0, 0.0, 0.803,
    0.803, 0.0, 10000.0, 10000.0, 0.0 },

  /* Mask Parameter: Refpower_stat
   * Referenced by: '<S5>/Start setpoint'
   */
  1.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S3>/SPERTE_measurement_samples'
   */
  100000U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S3>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S3>/SPERTE_measurement_function'
   */
  2U,

  /* Computed Parameter: SFunction_P1_Size_k
   * Referenced by: '<S8>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: portid
   * Referenced by: '<S8>/S-Function'
   */
  0.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S8>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: ectimeout
   * Referenced by: '<S8>/S-Function'
   */
  500.0,

  /* Computed Parameter: ec_Ebox_P1_Size
   * Referenced by: '<S7>/ec_Ebox'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S7>/ec_Ebox'
   */
  0.0,

  /* Expression: (2*pi)/(500*4)
   * Referenced by: '<Root>/Quantizer1'
   */
  0.0031415926535897933,

  /* Expression: (2*pi)/(4*500)
   * Referenced by: '<S2>/count2rad'
   */
  0.0031415926535897933,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 0
   * Referenced by: '<S2>/Constant2'
   */
  0.0,

  /* Expression: 1.1
   * Referenced by: '<S1>/Gain1'
   */
  1.1,

  /* Computed Parameter: Dctleadlag2_P1_Size
   * Referenced by: '<S1>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S1>/Dctleadlag2'
   */
  6.6467,

  /* Computed Parameter: Dctleadlag2_P2_Size
   * Referenced by: '<S1>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S1>/Dctleadlag2'
   */
  59.79,

  /* Computed Parameter: Dctleadlag2_P3_Size
   * Referenced by: '<S1>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dctleadlag2'
   */
  0.001,

  /* Computed Parameter: Dctintegrator3_P1_Size
   * Referenced by: '<S1>/Dctintegrator3'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S1>/Dctintegrator3'
   */
  0.958,

  /* Computed Parameter: Dctintegrator3_P2_Size
   * Referenced by: '<S1>/Dctintegrator3'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dctintegrator3'
   */
  0.001,

  /* Computed Parameter: Dctnotch4_P1_Size
   * Referenced by: '<S1>/Dctnotch4'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S1>/Dctnotch4'
   */
  58.0,

  /* Computed Parameter: Dctnotch4_P2_Size
   * Referenced by: '<S1>/Dctnotch4'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S1>/Dctnotch4'
   */
  0.0195,

  /* Computed Parameter: Dctnotch4_P3_Size
   * Referenced by: '<S1>/Dctnotch4'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S1>/Dctnotch4'
   */
  150.0,

  /* Computed Parameter: Dctnotch4_P4_Size
   * Referenced by: '<S1>/Dctnotch4'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S1>/Dctnotch4'
   */
  1.0,

  /* Computed Parameter: Dctnotch4_P5_Size
   * Referenced by: '<S1>/Dctnotch4'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dctnotch4'
   */
  0.001,

  /* Expression: 2.5
   * Referenced by: '<S2>/Saturation'
   */
  2.5,

  /* Expression: -2.5
   * Referenced by: '<S2>/Saturation'
   */
  -2.5,

  /* Expression: 10
   * Referenced by: '<S7>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S7>/Saturation'
   */
  -10.0,

  /* Expression: [0,0,0,0,0,0,0,0]
   * Referenced by: '<S2>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [0,0]
   * Referenced by: '<S2>/Constant'
   */
  { 0.0, 0.0 },

  /* Expression: 1/100
   * Referenced by: '<S7>/Gain'
   */
  0.01,

  /* Computed Parameter: Selectencoder_CurrentSetting
   * Referenced by: '<Root>/Select encoder'
   */
  0U
};
