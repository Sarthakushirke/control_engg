/*
 * Basic_controller_model_Control_Engineering_types.h
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

#ifndef RTW_HEADER_Basic_controller_model_Control_Engineering_types_h_
#define RTW_HEADER_Basic_controller_model_Control_Engineering_types_h_
#include "rtwtypes.h"

/* Custom Type definition for MATLAB Function: '<S3>/SPERTE_measurement_function' */
#include <stdio.h>
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T

struct emxArray_char_T
{
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /* struct_emxArray_char_T */

#ifndef typedef_emxArray_char_T_Basic_control_T
#define typedef_emxArray_char_T_Basic_control_T

typedef struct emxArray_char_T emxArray_char_T_Basic_control_T;

#endif                             /* typedef_emxArray_char_T_Basic_control_T */

/* Parameters (default storage) */
typedef struct P_Basic_controller_model_Control_Engineering_T_
  P_Basic_controller_model_Control_Engineering_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Basic_controller_model_Control_Engineering_T
  RT_MODEL_Basic_controller_model_Control_Engineering_T;

#endif      /* RTW_HEADER_Basic_controller_model_Control_Engineering_types_h_ */
