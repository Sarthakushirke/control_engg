/*
 * FRF_model_Control_Engineering_private.h
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

#ifndef RTW_HEADER_FRF_model_Control_Engineering_private_h_
#define RTW_HEADER_FRF_model_Control_Engineering_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "FRF_model_Control_Engineering_types.h"
#include "FRF_model_Control_Engineering.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u);
extern real_T rt_roundd_snf(real_T u);
extern void dleadlag(SimStruct *rts);
extern void dnotch(SimStruct *rts);
extern void dlowpass1(SimStruct *rts);
extern void dweakint(SimStruct *rts);
extern void ref3b(SimStruct *rts);
extern void dpd(SimStruct *rts);
extern void dlowpass2(SimStruct *rts);

#endif                 /* RTW_HEADER_FRF_model_Control_Engineering_private_h_ */
