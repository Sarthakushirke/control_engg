/*
 * FRF_model_Control_Engineering.c
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
#include "FRF_model_Control_Engineering_types.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "FRF_model_Control_Engineering_private.h"
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "FRF_model_Control_Engineering_dt.h"

/* Named constants for MATLAB Function: '<S2>/SPERTE_measurement_function' */
#define FRF_model_Control_En_CALL_EVENT (-1)

/* Block signals (default storage) */
B_FRF_model_Control_Engineering_T FRF_model_Control_Engineering_B;

/* Block states (default storage) */
DW_FRF_model_Control_Engineering_T FRF_model_Control_Engineering_DW;

/* Real-time model */
static RT_MODEL_FRF_model_Control_Engineering_T FRF_model_Control_Engineering_M_;
RT_MODEL_FRF_model_Control_Engineering_T *const FRF_model_Control_Engineering_M =
  &FRF_model_Control_Engineering_M_;

/* Forward declaration for local functions */
static void FRF_model_Contro_emxInit_char_T(emxArray_char_T_FRF_model_Con_T
  **pEmxArray, int32_T numDimensions);
static void FRF_mo_emxEnsureCapacity_char_T(emxArray_char_T_FRF_model_Con_T
  *emxArray, int32_T oldNumel);
static void FRF_model_Contro_emxFree_char_T(emxArray_char_T_FRF_model_Con_T
  **pEmxArray);
static int8_T FRF_model_Control_Engi_filedata(void);
static int8_T FRF_model_Control_Engine_cfopen(const
  emxArray_char_T_FRF_model_Con_T *cfilename, const char_T *cpermission);
static int32_T FRF_model_Control_Engin_cfclose(real_T fid);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void FRF_model_Control_Engineering_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(FRF_model_Control_Engineering_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (FRF_model_Control_Engineering_M->Timing.TaskCounters.TID[1] == 0) {
    FRF_model_Control_Engineering_M->Timing.RateInteraction.TID1_2 =
      (FRF_model_Control_Engineering_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    FRF_model_Control_Engineering_M->Timing.perTaskSampleHits[5] =
      FRF_model_Control_Engineering_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (FRF_model_Control_Engineering_M->Timing.TaskCounters.TID[2])++;
  if ((FRF_model_Control_Engineering_M->Timing.TaskCounters.TID[2]) > 7) {/* Sample time: [0.002s, 0.0s] */
    FRF_model_Control_Engineering_M->Timing.TaskCounters.TID[2] = 0;
  }
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

static void FRF_model_Contro_emxInit_char_T(emxArray_char_T_FRF_model_Con_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_FRF_model_Con_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_FRF_model_Con_T *)malloc(sizeof
    (emxArray_char_T_FRF_model_Con_T));
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)malloc(sizeof(int32_T) * (uint32_T)numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void FRF_mo_emxEnsureCapacity_char_T(emxArray_char_T_FRF_model_Con_T
  *emxArray, int32_T oldNumel)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = malloc((uint32_T)i * sizeof(char_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * (uint32_T)oldNumel);
      if (emxArray->canFreeData) {
        free(emxArray->data);
      }
    }

    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void FRF_model_Contro_emxFree_char_T(emxArray_char_T_FRF_model_Con_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_FRF_model_Con_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_FRF_model_Con_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S2>/SPERTE_measurement_function' */
static int8_T FRF_model_Control_Engi_filedata(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (FRF_model_Control_Engineering_DW.eml_openfiles[(int8_T)k - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S2>/SPERTE_measurement_function' */
static int8_T FRF_model_Control_Engine_cfopen(const
  emxArray_char_T_FRF_model_Con_T *cfilename, const char_T *cpermission)
{
  FILE *filestar;
  emxArray_char_T_FRF_model_Con_T *ccfilename;
  int32_T loop_ub;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = FRF_model_Control_Engi_filedata();
  if (j >= 1) {
    FRF_model_Contro_emxInit_char_T(&ccfilename, 2);
    loop_ub = ccfilename->size[0] * ccfilename->size[1];
    ccfilename->size[0] = 1;
    ccfilename->size[1] = cfilename->size[1] + 1;
    FRF_mo_emxEnsureCapacity_char_T(ccfilename, loop_ub);
    loop_ub = cfilename->size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&ccfilename->data[0], &cfilename->data[0], (uint32_T)loop_ub *
             sizeof(char_T));
    }

    ccfilename->data[cfilename->size[1]] = '\x00';
    filestar = fopen(&ccfilename->data[0], cpermission);
    FRF_model_Contro_emxFree_char_T(&ccfilename);
    if (filestar != NULL) {
      FRF_model_Control_Engineering_DW.eml_openfiles[j - 1] = filestar;
      FRF_model_Control_Engineering_DW.eml_autoflush[j - 1] = true;
      loop_ub = j + 2;
      if (j + 2 > 127) {
        loop_ub = 127;
      }

      fileid = (int8_T)loop_ub;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S2>/SPERTE_measurement_function' */
static int32_T FRF_model_Control_Engin_cfclose(real_T fid)
{
  FILE *f;
  int32_T cst;
  int32_T st;
  int8_T b_fileid;
  int8_T fileid;
  st = -1;
  fileid = (int8_T)fid;
  if (((int8_T)fid < 0) || (fid != (int8_T)fid)) {
    fileid = -1;
  }

  b_fileid = fileid;
  if (fileid < 0) {
    b_fileid = -1;
  }

  if (b_fileid >= 3) {
    f = FRF_model_Control_Engineering_DW.eml_openfiles[b_fileid - 3];
  } else if (b_fileid == 0) {
    f = stdin;
  } else if (b_fileid == 1) {
    f = stdout;
  } else if (b_fileid == 2) {
    f = stderr;
  } else {
    f = NULL;
  }

  if ((f != NULL) && (fileid >= 3)) {
    cst = fclose(f);
    if (cst == 0) {
      st = 0;
      FRF_model_Control_Engineering_DW.eml_openfiles[fileid - 3] = NULL;
      FRF_model_Control_Engineering_DW.eml_autoflush[fileid - 3] = true;
    }
  }

  return st;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function for TID0 */
void FRF_model_Control_Engineering_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  FILE *f;
  emxArray_char_T_FRF_model_Con_T *str;
  emxArray_char_T_FRF_model_Con_T *str_0;
  int8_T b_fileid;
  boolean_T autoflush;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Gain: '<S6>/Gain1' incorporates:
   *  RandomNumber: '<Root>/Noise'
   */
  FRF_model_Control_Engineering_B.Gain1 =
    FRF_model_Control_Engineering_P.Gain1_Gain *
    FRF_model_Control_Engineering_DW.NextOutput;

  /* S-Function (dleadlag): '<S6>/Dctleadlag2' */

  /* Level2 S-Function Block: '<S6>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S6>/Dctnotch3' */

  /* Level2 S-Function Block: '<S6>/Dctnotch3' (dnotch) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass1): '<S6>/Dct1lowpass4' */

  /* Level2 S-Function Block: '<S6>/Dct1lowpass4' (dlowpass1) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S6>/Dctnotch5' */

  /* Level2 S-Function Block: '<S6>/Dctnotch5' (dnotch) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dweakint): '<S6>/Dctintegrator6' */

  /* Level2 S-Function Block: '<S6>/Dctintegrator6' (dweakint) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* Constant: '<S4>/Start setpoint' */
  FRF_model_Control_Engineering_B.Startsetpoint =
    FRF_model_Control_Engineering_P.Refpower_stat;

  /* S-Function (ref3b): '<S5>/S-Function' */

  /* Level2 S-Function Block: '<S5>/S-Function' (ref3b) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* MATLAB Function: '<S2>/SPERTE_measurement_function' incorporates:
   *  Constant: '<S2>/SPERTE_measurement_samples'
   *  Constant: '<S2>/SPERTE_measurement_trigger_command'
   *  RandomNumber: '<Root>/Noise'
   *  SignalConversion generated from: '<S7>/ SFunction '
   */
  FRF_model_Control_Engineering_DW.sfEvent = FRF_model_Control_En_CALL_EVENT;
  if ((((FRF_model_Control_Engineering_P.MeasurementBlock_triggertype == 1) &&
        (FRF_model_Control_Engineering_P.MeasurementBlock_trigger_comman == 1)) ||
       ((FRF_model_Control_Engineering_P.MeasurementBlock_triggertype == 2) &&
        (FRF_model_Control_Engineering_P.MeasurementBlock_trigger_comman == 1)))
      && (FRF_model_Control_Engineering_DW.busy != 1)) {
    FRF_model_Control_Engineering_B.nbytes = (int32_T)snprintf(NULL, 0,
      "measurement_%d.bin", FRF_model_Control_Engineering_DW.NF) + 1;
    FRF_model_Contro_emxInit_char_T(&str, 2);
    FRF_model_Control_Engineering_B.i = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = FRF_model_Control_Engineering_B.nbytes;
    FRF_mo_emxEnsureCapacity_char_T(str, FRF_model_Control_Engineering_B.i);
    snprintf(&str->data[0], (size_t)FRF_model_Control_Engineering_B.nbytes,
             "measurement_%d.bin", FRF_model_Control_Engineering_DW.NF);
    if (FRF_model_Control_Engineering_B.nbytes - 1 < 1) {
      FRF_model_Control_Engineering_B.nbytes = -1;
    } else {
      FRF_model_Control_Engineering_B.nbytes -= 2;
    }

    FRF_model_Contro_emxInit_char_T(&str_0, 2);
    FRF_model_Control_Engineering_B.i = str_0->size[0] * str_0->size[1];
    str_0->size[0] = 1;
    str_0->size[1] = FRF_model_Control_Engineering_B.nbytes + 1;
    FRF_mo_emxEnsureCapacity_char_T(str_0, FRF_model_Control_Engineering_B.i);
    if (FRF_model_Control_Engineering_B.nbytes >= 0) {
      memcpy(&str_0->data[0], &str->data[0], (uint32_T)
             (FRF_model_Control_Engineering_B.nbytes + 1) * sizeof(char_T));
    }

    FRF_model_Contro_emxFree_char_T(&str);
    b_fileid = FRF_model_Control_Engine_cfopen(str_0, "wb");
    FRF_model_Contro_emxFree_char_T(&str_0);
    FRF_model_Control_Engineering_DW.fileID = b_fileid;
    FRF_model_Control_Engineering_B.nbytes = FRF_model_Control_Engineering_DW.NF
      + 1;
    if (FRF_model_Control_Engineering_DW.NF + 1 > 32767) {
      FRF_model_Control_Engineering_B.nbytes = 32767;
    }

    FRF_model_Control_Engineering_DW.NF = (int16_T)
      FRF_model_Control_Engineering_B.nbytes;
    FRF_model_Control_Engineering_DW.busy = 1U;
    FRF_model_Control_Engineering_DW.NS = 0U;
  }

  if (FRF_model_Control_Engineering_DW.busy == 1) {
    if (FRF_model_Control_Engineering_DW.NS <
        FRF_model_Control_Engineering_P.MeasurementBlock_N_samples) {
      b_fileid = (int8_T)FRF_model_Control_Engineering_DW.fileID;
      if (((int8_T)FRF_model_Control_Engineering_DW.fileID < 0) ||
          (FRF_model_Control_Engineering_DW.fileID != (int8_T)
           FRF_model_Control_Engineering_DW.fileID)) {
        b_fileid = -1;
      }

      if (b_fileid >= 3) {
        autoflush = FRF_model_Control_Engineering_DW.eml_autoflush[b_fileid - 3];
        f = FRF_model_Control_Engineering_DW.eml_openfiles[b_fileid - 3];
      } else if (b_fileid == 0) {
        f = stdin;
        autoflush = true;
      } else if (b_fileid == 1) {
        f = stdout;
        autoflush = true;
      } else if (b_fileid == 2) {
        f = stderr;
        autoflush = true;
      } else {
        f = NULL;
        autoflush = true;
      }

      if (!(FRF_model_Control_Engineering_DW.fileID != 0.0)) {
        f = NULL;
      }

      if (!(f == NULL)) {
        FRF_model_Control_Engineering_B.xout[0] = (real32_T)
          FRF_model_Control_Engineering_DW.NextOutput;
        FRF_model_Control_Engineering_B.xout[1] = (real32_T)
          FRF_model_Control_Engineering_B.Dctintegrator6;
        FRF_model_Control_Engineering_B.xout[2] = (real32_T)
          FRF_model_Control_Engineering_DW.NextOutput;
        FRF_model_Control_Engineering_B.bytesOutSizet = fwrite
          (&FRF_model_Control_Engineering_B.xout[0], sizeof(real32_T), (size_t)3,
           f);
        if (((real_T)FRF_model_Control_Engineering_B.bytesOutSizet > 0.0) &&
            autoflush) {
          fflush(f);
        }
      }

      FRF_model_Control_Engineering_B.qY = FRF_model_Control_Engineering_DW.NS +
        1U;
      if (FRF_model_Control_Engineering_DW.NS + 1U <
          FRF_model_Control_Engineering_DW.NS) {
        FRF_model_Control_Engineering_B.qY = MAX_uint32_T;
      }

      FRF_model_Control_Engineering_DW.NS = FRF_model_Control_Engineering_B.qY;
    } else {
      FRF_model_Control_Engin_cfclose(FRF_model_Control_Engineering_DW.fileID);
      FRF_model_Control_Engineering_DW.busy = 0U;
      FRF_model_Control_Engineering_DW.NS = 0U;
    }
  }

  /* End of MATLAB Function: '<S2>/SPERTE_measurement_function' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Quantizer: '<Root>/Quantizer1'
   */
  FRF_model_Control_Engineering_B.Sum = rt_roundd_snf
    (FRF_model_Control_Engineering_B.SFunction[2] /
     FRF_model_Control_Engineering_P.Quantizer1_Interval) *
    FRF_model_Control_Engineering_P.Quantizer1_Interval -
    FRF_model_Control_Engineering_B.Dctintegrator6;

  /* SignalConversion: '<S3>/Buffer' */
  FRF_model_Control_Engineering_B.Buffer[0] = 0.0;
  FRF_model_Control_Engineering_B.Buffer[1] =
    FRF_model_Control_Engineering_B.Dctintegrator6;
  FRF_model_Control_Engineering_B.Buffer[2] =
    FRF_model_Control_Engineering_B.Sum;

  /* RateTransition: '<S3>/Downsample' */
  if (FRF_model_Control_Engineering_M->Timing.RateInteraction.TID1_2) {
    FRF_model_Control_Engineering_DW.Downsample_Buffer[0] =
      FRF_model_Control_Engineering_B.Buffer[0];
    FRF_model_Control_Engineering_DW.Downsample_Buffer[1] =
      FRF_model_Control_Engineering_B.Buffer[1];
    FRF_model_Control_Engineering_DW.Downsample_Buffer[2] =
      FRF_model_Control_Engineering_B.Buffer[2];
  }

  /* End of RateTransition: '<S3>/Downsample' */

  /* Gain: '<S1>/Gain1' */
  FRF_model_Control_Engineering_B.Gain1_j =
    FRF_model_Control_Engineering_P.Gain1_Gain_b *
    FRF_model_Control_Engineering_B.Sum;

  /* S-Function (dpd): '<S1>/Dctpd' */

  /* Level2 S-Function Block: '<S1>/Dctpd' (dpd) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass2): '<S1>/Dct2lowpass' */

  /* Level2 S-Function Block: '<S1>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* Update for RandomNumber: '<Root>/Noise' */
  FRF_model_Control_Engineering_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
    (&FRF_model_Control_Engineering_DW.RandSeed) *
    FRF_model_Control_Engineering_P.Noise_StdDev +
    FRF_model_Control_Engineering_P.Noise_Mean;

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, (real_T)FRF_model_Control_Engineering_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(FRF_model_Control_Engineering_M)!=-1) &&
        !((rtmGetTFinal(FRF_model_Control_Engineering_M)-
           FRF_model_Control_Engineering_M->Timing.t[0]) >
          FRF_model_Control_Engineering_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(FRF_model_Control_Engineering_M, "Simulation finished");
    }

    if (rtmGetStopRequested(FRF_model_Control_Engineering_M)) {
      rtmSetErrorStatus(FRF_model_Control_Engineering_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++FRF_model_Control_Engineering_M->Timing.clockTick0)) {
    ++FRF_model_Control_Engineering_M->Timing.clockTickH0;
  }

  FRF_model_Control_Engineering_M->Timing.t[0] =
    FRF_model_Control_Engineering_M->Timing.clockTick0 *
    FRF_model_Control_Engineering_M->Timing.stepSize0 +
    FRF_model_Control_Engineering_M->Timing.clockTickH0 *
    FRF_model_Control_Engineering_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++FRF_model_Control_Engineering_M->Timing.clockTick1)) {
    ++FRF_model_Control_Engineering_M->Timing.clockTickH1;
  }

  FRF_model_Control_Engineering_M->Timing.t[1] =
    FRF_model_Control_Engineering_M->Timing.clockTick1 *
    FRF_model_Control_Engineering_M->Timing.stepSize1 +
    FRF_model_Control_Engineering_M->Timing.clockTickH1 *
    FRF_model_Control_Engineering_M->Timing.stepSize1 * 4294967296.0;
}

/* Model step function for TID2 */
void FRF_model_Control_Engineering_step2(void) /* Sample time: [0.002s, 0.0s] */
{
  /* RateTransition: '<S3>/Downsample' */
  FRF_model_Control_Engineering_B.Downsample[0] =
    FRF_model_Control_Engineering_DW.Downsample_Buffer[0];
  FRF_model_Control_Engineering_B.Downsample[1] =
    FRF_model_Control_Engineering_DW.Downsample_Buffer[1];
  FRF_model_Control_Engineering_B.Downsample[2] =
    FRF_model_Control_Engineering_DW.Downsample_Buffer[2];
  rtExtModeUpload(2, (real_T)
                  (((FRF_model_Control_Engineering_M->Timing.clockTick2+
                     FRF_model_Control_Engineering_M->Timing.clockTickH2*
                     4294967296.0)) * 0.002));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.002, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  FRF_model_Control_Engineering_M->Timing.clockTick2++;
  if (!FRF_model_Control_Engineering_M->Timing.clockTick2) {
    FRF_model_Control_Engineering_M->Timing.clockTickH2++;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void FRF_model_Control_Engineering_step(int_T tid)
{
  switch (tid) {
   case 0 :
    FRF_model_Control_Engineering_step0();
    break;

   case 2 :
    FRF_model_Control_Engineering_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void FRF_model_Control_Engineering_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)FRF_model_Control_Engineering_M, 0,
                sizeof(RT_MODEL_FRF_model_Control_Engineering_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&FRF_model_Control_Engineering_M->solverInfo,
                          &FRF_model_Control_Engineering_M->Timing.simTimeStep);
    rtsiSetTPtr(&FRF_model_Control_Engineering_M->solverInfo, &rtmGetTPtr
                (FRF_model_Control_Engineering_M));
    rtsiSetStepSizePtr(&FRF_model_Control_Engineering_M->solverInfo,
                       &FRF_model_Control_Engineering_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&FRF_model_Control_Engineering_M->solverInfo,
                          (&rtmGetErrorStatus(FRF_model_Control_Engineering_M)));
    rtsiSetRTModelPtr(&FRF_model_Control_Engineering_M->solverInfo,
                      FRF_model_Control_Engineering_M);
  }

  rtsiSetSimTimeStep(&FRF_model_Control_Engineering_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&FRF_model_Control_Engineering_M->solverInfo,
                    "FixedStepDiscrete");
  FRF_model_Control_Engineering_M->solverInfoPtr =
    (&FRF_model_Control_Engineering_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      FRF_model_Control_Engineering_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "FRF_model_Control_Engineering_M points to
       static memory which is guaranteed to be non-NULL" */
    FRF_model_Control_Engineering_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    FRF_model_Control_Engineering_M->Timing.sampleTimes =
      (&FRF_model_Control_Engineering_M->Timing.sampleTimesArray[0]);
    FRF_model_Control_Engineering_M->Timing.offsetTimes =
      (&FRF_model_Control_Engineering_M->Timing.offsetTimesArray[0]);

    /* task periods */
    FRF_model_Control_Engineering_M->Timing.sampleTimes[0] = (0.0);
    FRF_model_Control_Engineering_M->Timing.sampleTimes[1] = (0.00025);
    FRF_model_Control_Engineering_M->Timing.sampleTimes[2] = (0.002);

    /* task offsets */
    FRF_model_Control_Engineering_M->Timing.offsetTimes[0] = (0.0);
    FRF_model_Control_Engineering_M->Timing.offsetTimes[1] = (0.0);
    FRF_model_Control_Engineering_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(FRF_model_Control_Engineering_M,
             &FRF_model_Control_Engineering_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      FRF_model_Control_Engineering_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      FRF_model_Control_Engineering_M->Timing.perTaskSampleHitsArray;
    FRF_model_Control_Engineering_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    FRF_model_Control_Engineering_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(FRF_model_Control_Engineering_M, -1);
  FRF_model_Control_Engineering_M->Timing.stepSize0 = 0.00025;
  FRF_model_Control_Engineering_M->Timing.stepSize1 = 0.00025;

  /* External mode info */
  FRF_model_Control_Engineering_M->Sizes.checksums[0] = (3382277239U);
  FRF_model_Control_Engineering_M->Sizes.checksums[1] = (897400545U);
  FRF_model_Control_Engineering_M->Sizes.checksums[2] = (161020584U);
  FRF_model_Control_Engineering_M->Sizes.checksums[3] = (1759505767U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    FRF_model_Control_Engineering_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(FRF_model_Control_Engineering_M->extModeInfo,
      &FRF_model_Control_Engineering_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(FRF_model_Control_Engineering_M->extModeInfo,
                        FRF_model_Control_Engineering_M->Sizes.checksums);
    rteiSetTPtr(FRF_model_Control_Engineering_M->extModeInfo, rtmGetTPtr
                (FRF_model_Control_Engineering_M));
  }

  FRF_model_Control_Engineering_M->solverInfoPtr =
    (&FRF_model_Control_Engineering_M->solverInfo);
  FRF_model_Control_Engineering_M->Timing.stepSize = (0.00025);
  rtsiSetFixedStepSize(&FRF_model_Control_Engineering_M->solverInfo, 0.00025);
  rtsiSetSolverMode(&FRF_model_Control_Engineering_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &FRF_model_Control_Engineering_B), 0,
                sizeof(B_FRF_model_Control_Engineering_T));

  /* states (dwork) */
  (void) memset((void *)&FRF_model_Control_Engineering_DW, 0,
                sizeof(DW_FRF_model_Control_Engineering_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    FRF_model_Control_Engineering_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 23;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &FRF_model_Control_Engineering_M->NonInlinedSFcns.sfcnInfo;
    FRF_model_Control_Engineering_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (FRF_model_Control_Engineering_M)));
    FRF_model_Control_Engineering_M->Sizes.numSampTimes = (3);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &FRF_model_Control_Engineering_M->Sizes.numSampTimes);
    FRF_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs[0] =
      (&rtmGetTPtr(FRF_model_Control_Engineering_M)[0]);
    FRF_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs[1] =
      (&rtmGetTPtr(FRF_model_Control_Engineering_M)[1]);
    FRF_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs[2] =
      (&rtmGetTPtr(FRF_model_Control_Engineering_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,
                   FRF_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(FRF_model_Control_Engineering_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(FRF_model_Control_Engineering_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (FRF_model_Control_Engineering_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &FRF_model_Control_Engineering_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (FRF_model_Control_Engineering_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &FRF_model_Control_Engineering_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &FRF_model_Control_Engineering_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &FRF_model_Control_Engineering_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &FRF_model_Control_Engineering_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &FRF_model_Control_Engineering_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &FRF_model_Control_Engineering_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &FRF_model_Control_Engineering_M->solverInfoPtr);
  }

  FRF_model_Control_Engineering_M->Sizes.numSFcns = (8);

  /* register each child */
  {
    (void) memset((void *)
                  &FRF_model_Control_Engineering_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  8*sizeof(SimStruct));
    FRF_model_Control_Engineering_M->childSfunctions =
      (&FRF_model_Control_Engineering_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 8; i++) {
        FRF_model_Control_Engineering_M->childSfunctions[i] =
          (&FRF_model_Control_Engineering_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: FRF_model_Control_Engineering/<S6>/Dctleadlag2 (dleadlag) */
    {
      SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FRF_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FRF_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &FRF_model_Control_Engineering_B.Gain1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &FRF_model_Control_Engineering_B.Dctleadlag2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag2");
      ssSetPath(rts,
                "FRF_model_Control_Engineering/Without_notch_controller/Dctleadlag2");
      ssSetRTModel(rts,FRF_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctleadlag2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctleadlag2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctleadlag2_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &FRF_model_Control_Engineering_DW.Dctleadlag2_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FRF_model_Control_Engineering_DW.Dctleadlag2_RWORK[0]);
      }

      /* registration */
      dleadlag(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: FRF_model_Control_Engineering/<S6>/Dctnotch3 (dnotch) */
    {
      SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FRF_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FRF_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &FRF_model_Control_Engineering_B.Dctleadlag2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &FRF_model_Control_Engineering_B.Dctnotch3));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch3");
      ssSetPath(rts,
                "FRF_model_Control_Engineering/Without_notch_controller/Dctnotch3");
      ssSetRTModel(rts,FRF_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctnotch3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctnotch3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctnotch3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctnotch3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctnotch3_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &FRF_model_Control_Engineering_DW.Dctnotch3_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FRF_model_Control_Engineering_DW.Dctnotch3_RWORK[0]);
      }

      /* registration */
      dnotch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: FRF_model_Control_Engineering/<S6>/Dct1lowpass4 (dlowpass1) */
    {
      SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FRF_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FRF_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn2.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &FRF_model_Control_Engineering_B.Dctnotch3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &FRF_model_Control_Engineering_B.Dct1lowpass4));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct1lowpass4");
      ssSetPath(rts,
                "FRF_model_Control_Engineering/Without_notch_controller/Dct1lowpass4");
      ssSetRTModel(rts,FRF_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FRF_model_Control_Engineering_P.Dct1lowpass4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FRF_model_Control_Engineering_P.Dct1lowpass4_P2_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &FRF_model_Control_Engineering_DW.Dct1lowpass4_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FRF_model_Control_Engineering_DW.Dct1lowpass4_RWORK
                   [0]);
      }

      /* registration */
      dlowpass1(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: FRF_model_Control_Engineering/<S6>/Dctnotch5 (dnotch) */
    {
      SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FRF_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2[3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FRF_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn3.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &FRF_model_Control_Engineering_B.Dct1lowpass4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &FRF_model_Control_Engineering_B.Dctnotch5));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch5");
      ssSetPath(rts,
                "FRF_model_Control_Engineering/Without_notch_controller/Dctnotch5");
      ssSetRTModel(rts,FRF_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctnotch5_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctnotch5_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctnotch5_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctnotch5_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctnotch5_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &FRF_model_Control_Engineering_DW.Dctnotch5_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FRF_model_Control_Engineering_DW.Dctnotch5_RWORK[0]);
      }

      /* registration */
      dnotch(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: FRF_model_Control_Engineering/<S6>/Dctintegrator6 (dweakint) */
    {
      SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FRF_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2[4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FRF_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo[4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn4.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] = &FRF_model_Control_Engineering_B.Dctnotch5;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &FRF_model_Control_Engineering_B.Dctintegrator6));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctintegrator6");
      ssSetPath(rts,
                "FRF_model_Control_Engineering/Without_notch_controller/Dctintegrator6");
      ssSetRTModel(rts,FRF_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctintegrator6_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctintegrator6_P2_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &FRF_model_Control_Engineering_DW.Dctintegrator6_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &FRF_model_Control_Engineering_DW.Dctintegrator6_RWORK[0]);
      }

      /* registration */
      dweakint(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: FRF_model_Control_Engineering/<S5>/S-Function (ref3b) */
    {
      SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FRF_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2[5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FRF_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo[5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn5.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] = &FRF_model_Control_Engineering_B.Startsetpoint;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            FRF_model_Control_Engineering_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "FRF_model_Control_Engineering/Subsystem/S-Function");
      ssSetRTModel(rts,FRF_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FRF_model_Control_Engineering_P.SFunction_P1_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &FRF_model_Control_Engineering_DW.SFunction_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 50);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FRF_model_Control_Engineering_DW.SFunction_RWORK[0]);
      }

      /* registration */
      ref3b(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: FRF_model_Control_Engineering/<S1>/Dctpd (dpd) */
    {
      SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FRF_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2[6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FRF_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [6]);
        ssSetPeriodicStatesInfo(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn6.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] = &FRF_model_Control_Engineering_B.Gain1_j;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn6.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &FRF_model_Control_Engineering_B.Dctpd));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctpd");
      ssSetPath(rts,
                "FRF_model_Control_Engineering/Controller (motor side)/Dctpd");
      ssSetRTModel(rts,FRF_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctpd_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctpd_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       FRF_model_Control_Engineering_P.Dctpd_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &FRF_model_Control_Engineering_DW.Dctpd_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FRF_model_Control_Engineering_DW.Dctpd_RWORK[0]);
      }

      /* registration */
      dpd(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: FRF_model_Control_Engineering/<S1>/Dct2lowpass (dlowpass2) */
    {
      SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap =
        FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &FRF_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2[7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, FRF_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &FRF_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &FRF_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [7]);
        ssSetPeriodicStatesInfo(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn7.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] = &FRF_model_Control_Engineering_B.Dctpd;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        ssSetPortInfoForOutputs(rts,
          &FRF_model_Control_Engineering_M->
          NonInlinedSFcns.Sfcn7.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &FRF_model_Control_Engineering_B.Dct2lowpass));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct2lowpass");
      ssSetPath(rts,
                "FRF_model_Control_Engineering/Controller (motor side)/Dct2lowpass");
      ssSetRTModel(rts,FRF_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       FRF_model_Control_Engineering_P.Dct2lowpass_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       FRF_model_Control_Engineering_P.Dct2lowpass_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       FRF_model_Control_Engineering_P.Dct2lowpass_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &FRF_model_Control_Engineering_DW.Dct2lowpass_RWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &FRF_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &FRF_model_Control_Engineering_DW.Dct2lowpass_RWORK[0]);
      }

      /* registration */
      dlowpass2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Start for S-Function (dleadlag): '<S6>/Dctleadlag2' */
  /* Level2 S-Function Block: '<S6>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S6>/Dctnotch3' */
  /* Level2 S-Function Block: '<S6>/Dctnotch3' (dnotch) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass1): '<S6>/Dct1lowpass4' */
  /* Level2 S-Function Block: '<S6>/Dct1lowpass4' (dlowpass1) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S6>/Dctnotch5' */
  /* Level2 S-Function Block: '<S6>/Dctnotch5' (dnotch) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dweakint): '<S6>/Dctintegrator6' */
  /* Level2 S-Function Block: '<S6>/Dctintegrator6' (dweakint) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S4>/Start setpoint' */
  FRF_model_Control_Engineering_B.Startsetpoint =
    FRF_model_Control_Engineering_P.Refpower_stat;

  /* Start for S-Function (dpd): '<S1>/Dctpd' */
  /* Level2 S-Function Block: '<S1>/Dctpd' (dpd) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass2): '<S1>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S1>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  {
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for RandomNumber: '<Root>/Noise' */
    tmp = floor(FRF_model_Control_Engineering_P.Noise_Seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    FRF_model_Control_Engineering_DW.RandSeed = ((((tseed - ((uint32_T)i << 16U))
      + (uint32_T)t) << 16U) + (uint32_T)t) + (uint32_T)i;
    if (FRF_model_Control_Engineering_DW.RandSeed < 1U) {
      FRF_model_Control_Engineering_DW.RandSeed = 1144108930U;
    } else if (FRF_model_Control_Engineering_DW.RandSeed > 2147483646U) {
      FRF_model_Control_Engineering_DW.RandSeed = 2147483646U;
    }

    FRF_model_Control_Engineering_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&FRF_model_Control_Engineering_DW.RandSeed) *
      FRF_model_Control_Engineering_P.Noise_StdDev +
      FRF_model_Control_Engineering_P.Noise_Mean;

    /* End of InitializeConditions for RandomNumber: '<Root>/Noise' */

    /* InitializeConditions for S-Function (ref3b): '<S5>/S-Function' */
    /* Level2 S-Function Block: '<S5>/S-Function' (ref3b) */
    {
      SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[5];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* SystemInitialize for MATLAB Function: '<S2>/SPERTE_measurement_function' */
    for (i = 0; i < 20; i++) {
      FRF_model_Control_Engineering_DW.eml_autoflush[i] = false;
    }

    FRF_model_Control_Engineering_DW.eml_autoflush_not_empty = true;
    for (i = 0; i < 20; i++) {
      FRF_model_Control_Engineering_DW.eml_openfiles[i] = NULL;
    }

    FRF_model_Control_Engineering_DW.eml_openfiles_not_empty = true;
    FRF_model_Control_Engineering_DW.NF = 0;
    FRF_model_Control_Engineering_DW.NF_not_empty = true;
    FRF_model_Control_Engineering_DW.NS = 0U;
    FRF_model_Control_Engineering_DW.NS_not_empty = true;
    FRF_model_Control_Engineering_DW.fileID = 0.0;
    FRF_model_Control_Engineering_DW.fileID_not_empty = true;
    FRF_model_Control_Engineering_DW.busy = 0U;
    FRF_model_Control_Engineering_DW.busy_not_empty = true;
    FRF_model_Control_Engineering_DW.doneDoubleBufferReInit = false;
    FRF_model_Control_Engineering_DW.sfEvent = FRF_model_Control_En_CALL_EVENT;

    /* End of SystemInitialize for MATLAB Function: '<S2>/SPERTE_measurement_function' */
  }
}

/* Model terminate function */
void FRF_model_Control_Engineering_terminate(void)
{
  /* Terminate for S-Function (dleadlag): '<S6>/Dctleadlag2' */
  /* Level2 S-Function Block: '<S6>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S6>/Dctnotch3' */
  /* Level2 S-Function Block: '<S6>/Dctnotch3' (dnotch) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass1): '<S6>/Dct1lowpass4' */
  /* Level2 S-Function Block: '<S6>/Dct1lowpass4' (dlowpass1) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S6>/Dctnotch5' */
  /* Level2 S-Function Block: '<S6>/Dctnotch5' (dnotch) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dweakint): '<S6>/Dctintegrator6' */
  /* Level2 S-Function Block: '<S6>/Dctintegrator6' (dweakint) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ref3b): '<S5>/S-Function' */
  /* Level2 S-Function Block: '<S5>/S-Function' (ref3b) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dpd): '<S1>/Dctpd' */
  /* Level2 S-Function Block: '<S1>/Dctpd' (dpd) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass2): '<S1>/Dct2lowpass' */
  /* Level2 S-Function Block: '<S1>/Dct2lowpass' (dlowpass2) */
  {
    SimStruct *rts = FRF_model_Control_Engineering_M->childSfunctions[7];
    sfcnTerminate(rts);
  }
}
