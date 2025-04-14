/*
 * Feedforward_tunning_model_Control_Engineering_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Feedforward_tunning_model_Control_Engineering".
 *
 * Model version              : 11.65
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Apr 16 11:38:21 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Feedforward_tunning_model_Control_Engineering.h"

/* Block parameters (default storage) */
P_Feedforward_tunning_model_Control_Engineering_T
  Feedforward_tunning_model_Control_Engineering_P = {
  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S8>/S-Function'
   */
  { 3.0, 6.0 },

  /* Variable: ref_part
   * Referenced by: '<S8>/S-Function'
   */
  { 0.0, 125.0, 0.0, 0.0, 6.2113, -1.0, 125.0, 0.0, 0.0, 24.0, 24.0, 0.0, 0.803,
    0.803, 0.0, 10000.0, 10000.0, 0.0 },

  /* Mask Parameter: Kfc_gain
   * Referenced by: '<S3>/Slider Gain'
   */
  0.031,

  /* Mask Parameter: Kfa_gain
   * Referenced by: '<S2>/Slider Gain'
   */
  0.0004,

  /* Mask Parameter: Kfv_gain
   * Referenced by: '<S4>/Slider Gain'
   */
  1.0E-5,

  /* Mask Parameter: Refpower_stat
   * Referenced by: '<S7>/Start setpoint'
   */
  1.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S5>/SPERTE_measurement_samples'
   */
  100000U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S5>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S5>/SPERTE_measurement_function'
   */
  2U,

  /* Computed Parameter: SFunction_P1_Size_k
   * Referenced by: '<S11>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: portid
   * Referenced by: '<S11>/S-Function'
   */
  0.0,

  /* Computed Parameter: SFunction_P2_Size
   * Referenced by: '<S11>/S-Function'
   */
  { 1.0, 1.0 },

  /* Expression: ectimeout
   * Referenced by: '<S11>/S-Function'
   */
  500.0,

  /* Computed Parameter: ec_Ebox_P1_Size
   * Referenced by: '<S10>/ec_Ebox'
   */
  { 1.0, 1.0 },

  /* Expression: link_id
   * Referenced by: '<S10>/ec_Ebox'
   */
  0.0,

  /* Expression: (2*pi)/(4*500)
   * Referenced by: '<S1>/count2rad'
   */
  0.0031415926535897933,

  /* Expression: 0
   * Referenced by: '<S1>/Constant2'
   */
  0.0,

  /* Expression: (2*pi)/(500*4)
   * Referenced by: '<Root>/Quantizer1'
   */
  0.0031415926535897933,

  /* Expression: -1
   * Referenced by: '<Root>/Gain'
   */
  -1.0,

  /* Expression: 0.33
   * Referenced by: '<S9>/Gain1'
   */
  0.33,

  /* Computed Parameter: Dctleadlag2_P1_Size
   * Referenced by: '<S9>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S9>/Dctleadlag2'
   */
  4.5,

  /* Computed Parameter: Dctleadlag2_P2_Size
   * Referenced by: '<S9>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S9>/Dctleadlag2'
   */
  150.0,

  /* Computed Parameter: Dctleadlag2_P3_Size
   * Referenced by: '<S9>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S9>/Dctleadlag2'
   */
  0.001,

  /* Computed Parameter: Dctnotch3_P1_Size
   * Referenced by: '<S9>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S9>/Dctnotch3'
   */
  58.0,

  /* Computed Parameter: Dctnotch3_P2_Size
   * Referenced by: '<S9>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S9>/Dctnotch3'
   */
  0.015,

  /* Computed Parameter: Dctnotch3_P3_Size
   * Referenced by: '<S9>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S9>/Dctnotch3'
   */
  130.0,

  /* Computed Parameter: Dctnotch3_P4_Size
   * Referenced by: '<S9>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S9>/Dctnotch3'
   */
  0.3,

  /* Computed Parameter: Dctnotch3_P5_Size
   * Referenced by: '<S9>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S9>/Dctnotch3'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass4_P1_Size
   * Referenced by: '<S9>/Dct1lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S9>/Dct1lowpass4'
   */
  200.0,

  /* Computed Parameter: Dct1lowpass4_P2_Size
   * Referenced by: '<S9>/Dct1lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S9>/Dct1lowpass4'
   */
  0.001,

  /* Computed Parameter: Dctnotch5_P1_Size
   * Referenced by: '<S9>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S9>/Dctnotch5'
   */
  3.0,

  /* Computed Parameter: Dctnotch5_P2_Size
   * Referenced by: '<S9>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S9>/Dctnotch5'
   */
  0.5,

  /* Computed Parameter: Dctnotch5_P3_Size
   * Referenced by: '<S9>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S9>/Dctnotch5'
   */
  4.0,

  /* Computed Parameter: Dctnotch5_P4_Size
   * Referenced by: '<S9>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S9>/Dctnotch5'
   */
  0.05,

  /* Computed Parameter: Dctnotch5_P5_Size
   * Referenced by: '<S9>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S9>/Dctnotch5'
   */
  0.001,

  /* Computed Parameter: Dctintegrator6_P1_Size
   * Referenced by: '<S9>/Dctintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S9>/Dctintegrator6'
   */
  1.5,

  /* Computed Parameter: Dctintegrator6_P2_Size
   * Referenced by: '<S9>/Dctintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S9>/Dctintegrator6'
   */
  0.001,

  /* Expression: 2.5
   * Referenced by: '<S1>/Saturation'
   */
  2.5,

  /* Expression: -2.5
   * Referenced by: '<S1>/Saturation'
   */
  -2.5,

  /* Expression: 10
   * Referenced by: '<S10>/Saturation'
   */
  10.0,

  /* Expression: -10
   * Referenced by: '<S10>/Saturation'
   */
  -10.0,

  /* Expression: [0,0,0,0,0,0,0,0]
   * Referenced by: '<S1>/Constant1'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: [0,0]
   * Referenced by: '<S1>/Constant'
   */
  { 0.0, 0.0 },

  /* Expression: 1/100
   * Referenced by: '<S10>/Gain'
   */
  0.01,

  /* Computed Parameter: Selectencoder_CurrentSetting
   * Referenced by: '<Root>/Select encoder'
   */
  1U
};
