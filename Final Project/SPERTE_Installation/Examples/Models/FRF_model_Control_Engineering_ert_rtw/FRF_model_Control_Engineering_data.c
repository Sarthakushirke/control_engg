/*
 * FRF_model_Control_Engineering_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "FRF_model_Control_Engineering".
 *
 * Model version              : 11.23
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Tue Apr 16 11:48:06 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FRF_model_Control_Engineering.h"

/* Block parameters (default storage) */
P_FRF_model_Control_Engineering_T FRF_model_Control_Engineering_P = {
  /* Computed Parameter: SFunction_P1_Size
   * Referenced by: '<S5>/S-Function'
   */
  { 3.0, 6.0 },

  /* Variable: ref_part
   * Referenced by: '<S5>/S-Function'
   */
  { 0.0, 125.0, 0.0, 0.0, 6.2113, -1.0, 125.0, 0.0, 0.0, 24.0, 24.0, 0.0, 0.803,
    0.803, 0.0, 10000.0, 10000.0, 0.0 },

  /* Mask Parameter: Refpower_stat
   * Referenced by: '<S4>/Start setpoint'
   */
  1.0,

  /* Mask Parameter: MeasurementBlock_N_samples
   * Referenced by: '<S2>/SPERTE_measurement_samples'
   */
  100000U,

  /* Mask Parameter: MeasurementBlock_trigger_comman
   * Referenced by: '<S2>/SPERTE_measurement_trigger_command'
   */
  0U,

  /* Mask Parameter: MeasurementBlock_triggertype
   * Referenced by: '<S2>/SPERTE_measurement_function'
   */
  2U,

  /* Expression: 0
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Computed Parameter: Noise_StdDev
   * Referenced by: '<Root>/Noise'
   */
  0.63245553203367588,

  /* Expression: 0
   * Referenced by: '<Root>/Noise'
   */
  0.0,

  /* Expression: 0.348
   * Referenced by: '<S6>/Gain1'
   */
  0.348,

  /* Computed Parameter: Dctleadlag2_P1_Size
   * Referenced by: '<S6>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S6>/Dctleadlag2'
   */
  2.6,

  /* Computed Parameter: Dctleadlag2_P2_Size
   * Referenced by: '<S6>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S6>/Dctleadlag2'
   */
  200.0,

  /* Computed Parameter: Dctleadlag2_P3_Size
   * Referenced by: '<S6>/Dctleadlag2'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S6>/Dctleadlag2'
   */
  0.001,

  /* Computed Parameter: Dctnotch3_P1_Size
   * Referenced by: '<S6>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S6>/Dctnotch3'
   */
  56.0,

  /* Computed Parameter: Dctnotch3_P2_Size
   * Referenced by: '<S6>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S6>/Dctnotch3'
   */
  0.016,

  /* Computed Parameter: Dctnotch3_P3_Size
   * Referenced by: '<S6>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S6>/Dctnotch3'
   */
  130.0,

  /* Computed Parameter: Dctnotch3_P4_Size
   * Referenced by: '<S6>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S6>/Dctnotch3'
   */
  0.3,

  /* Computed Parameter: Dctnotch3_P5_Size
   * Referenced by: '<S6>/Dctnotch3'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S6>/Dctnotch3'
   */
  0.001,

  /* Computed Parameter: Dct1lowpass4_P1_Size
   * Referenced by: '<S6>/Dct1lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S6>/Dct1lowpass4'
   */
  200.0,

  /* Computed Parameter: Dct1lowpass4_P2_Size
   * Referenced by: '<S6>/Dct1lowpass4'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S6>/Dct1lowpass4'
   */
  0.001,

  /* Computed Parameter: Dctnotch5_P1_Size
   * Referenced by: '<S6>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S6>/Dctnotch5'
   */
  3.0,

  /* Computed Parameter: Dctnotch5_P2_Size
   * Referenced by: '<S6>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: b_num
   * Referenced by: '<S6>/Dctnotch5'
   */
  0.5,

  /* Computed Parameter: Dctnotch5_P3_Size
   * Referenced by: '<S6>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S6>/Dctnotch5'
   */
  4.0,

  /* Computed Parameter: Dctnotch5_P4_Size
   * Referenced by: '<S6>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S6>/Dctnotch5'
   */
  0.05,

  /* Computed Parameter: Dctnotch5_P5_Size
   * Referenced by: '<S6>/Dctnotch5'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S6>/Dctnotch5'
   */
  0.001,

  /* Computed Parameter: Dctintegrator6_P1_Size
   * Referenced by: '<S6>/Dctintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: f_num
   * Referenced by: '<S6>/Dctintegrator6'
   */
  1.5,

  /* Computed Parameter: Dctintegrator6_P2_Size
   * Referenced by: '<S6>/Dctintegrator6'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S6>/Dctintegrator6'
   */
  0.001,

  /* Expression: (2*pi)/(500*4)
   * Referenced by: '<Root>/Quantizer1'
   */
  0.0031415926535897933,

  /* Expression: 1
   * Referenced by: '<S1>/Gain1'
   */
  1.0,

  /* Computed Parameter: Dctpd_P1_Size
   * Referenced by: '<S1>/Dctpd'
   */
  { 1.0, 1.0 },

  /* Expression: kp
   * Referenced by: '<S1>/Dctpd'
   */
  0.5,

  /* Computed Parameter: Dctpd_P2_Size
   * Referenced by: '<S1>/Dctpd'
   */
  { 1.0, 1.0 },

  /* Expression: kv
   * Referenced by: '<S1>/Dctpd'
   */
  0.05,

  /* Computed Parameter: Dctpd_P3_Size
   * Referenced by: '<S1>/Dctpd'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dctpd'
   */
  0.001,

  /* Computed Parameter: Dct2lowpass_P1_Size
   * Referenced by: '<S1>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: f_den
   * Referenced by: '<S1>/Dct2lowpass'
   */
  200.0,

  /* Computed Parameter: Dct2lowpass_P2_Size
   * Referenced by: '<S1>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: b_den
   * Referenced by: '<S1>/Dct2lowpass'
   */
  0.7,

  /* Computed Parameter: Dct2lowpass_P3_Size
   * Referenced by: '<S1>/Dct2lowpass'
   */
  { 1.0, 1.0 },

  /* Expression: 0.001
   * Referenced by: '<S1>/Dct2lowpass'
   */
  0.001
};
