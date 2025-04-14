/*
 * Feedforward_tunning_model_Control_Engineering.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Feedforward_tunning_model_Control_Engineering".
 *
 * Model version              : 11.56
 * Simulink Coder version : 23.2 (R2023b) 01-Aug-2023
 * C source code generated on : Thu Apr  4 12:21:10 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Feedforward_tunning_model_Control_Engineering.h"
#include "Feedforward_tunning_model_Control_Engineering_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <stddef.h>
#include "Feedforward_tunning_model_Control_Engineering_private.h"
#include "rt_nonfinite.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Feedforward_tunning_model_Control_Engineering_dt.h"

/* Named constants for MATLAB Function: '<S5>/SPERTE_measurement_function' */
#define Feedforward_tunning__CALL_EVENT (-1)

/* Block signals (default storage) */
B_Feedforward_tunning_model_Control_Engineering_T
  Feedforward_tunning_model_Control_Engineering_B;

/* Block states (default storage) */
DW_Feedforward_tunning_model_Control_Engineering_T
  Feedforward_tunning_model_Control_Engineering_DW;

/* Real-time model */
static RT_MODEL_Feedforward_tunning_model_Control_Engineering_T
  Feedforward_tunning_model_Control_Engineering_M_;
RT_MODEL_Feedforward_tunning_model_Control_Engineering_T *const
  Feedforward_tunning_model_Control_Engineering_M =
  &Feedforward_tunning_model_Control_Engineering_M_;

/* Forward declaration for local functions */
static void Feedforward_tunn_emxInit_char_T(emxArray_char_T_Feedforward_t_T
  **pEmxArray, int32_T numDimensions);
static void Feedfo_emxEnsureCapacity_char_T(emxArray_char_T_Feedforward_t_T
  *emxArray, int32_T oldNumel);
static void Feedforward_tunn_emxFree_char_T(emxArray_char_T_Feedforward_t_T
  **pEmxArray);
static int8_T Feedforward_tunning_mo_filedata(void);
static int8_T Feedforward_tunning_mode_cfopen(const
  emxArray_char_T_Feedforward_t_T *cfilename, const char_T *cpermission);
static int32_T Feedforward_tunning_mod_cfclose(real_T fid);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Feedforward_tunning_model_Control_Engineering_SetEventsForThisBaseStep
  (boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask
                   (Feedforward_tunning_model_Control_Engineering_M, 2));
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
  if (Feedforward_tunning_model_Control_Engineering_M->Timing.TaskCounters.TID[1]
      == 0) {
    Feedforward_tunning_model_Control_Engineering_M->Timing.RateInteraction.TID1_2
      =
      (Feedforward_tunning_model_Control_Engineering_M->Timing.TaskCounters.TID
       [2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Feedforward_tunning_model_Control_Engineering_M->Timing.perTaskSampleHits[5]
      =
      Feedforward_tunning_model_Control_Engineering_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Feedforward_tunning_model_Control_Engineering_M->Timing.TaskCounters.TID[2])
    ++;
  if ((Feedforward_tunning_model_Control_Engineering_M->Timing.TaskCounters.TID
       [2]) > 7) {                     /* Sample time: [0.002s, 0.0s] */
    Feedforward_tunning_model_Control_Engineering_M->Timing.TaskCounters.TID[2] =
      0;
  }
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

static void Feedforward_tunn_emxInit_char_T(emxArray_char_T_Feedforward_t_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_Feedforward_t_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Feedforward_t_T *)malloc(sizeof
    (emxArray_char_T_Feedforward_t_T));
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

static void Feedfo_emxEnsureCapacity_char_T(emxArray_char_T_Feedforward_t_T
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

static void Feedforward_tunn_emxFree_char_T(emxArray_char_T_Feedforward_t_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_Feedforward_t_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_Feedforward_t_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S5>/SPERTE_measurement_function' */
static int8_T Feedforward_tunning_mo_filedata(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles[(int8_T)k
        - 1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S5>/SPERTE_measurement_function' */
static int8_T Feedforward_tunning_mode_cfopen(const
  emxArray_char_T_Feedforward_t_T *cfilename, const char_T *cpermission)
{
  FILE *filestar;
  emxArray_char_T_Feedforward_t_T *ccfilename;
  int32_T loop_ub;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Feedforward_tunning_mo_filedata();
  if (j >= 1) {
    Feedforward_tunn_emxInit_char_T(&ccfilename, 2);
    loop_ub = ccfilename->size[0] * ccfilename->size[1];
    ccfilename->size[0] = 1;
    ccfilename->size[1] = cfilename->size[1] + 1;
    Feedfo_emxEnsureCapacity_char_T(ccfilename, loop_ub);
    loop_ub = cfilename->size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&ccfilename->data[0], &cfilename->data[0], (uint32_T)loop_ub *
             sizeof(char_T));
    }

    ccfilename->data[cfilename->size[1]] = '\x00';
    filestar = fopen(&ccfilename->data[0], cpermission);
    Feedforward_tunn_emxFree_char_T(&ccfilename);
    if (filestar != NULL) {
      Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles[j - 1] =
        filestar;
      Feedforward_tunning_model_Control_Engineering_DW.eml_autoflush[j - 1] =
        true;
      loop_ub = j + 2;
      if (j + 2 > 127) {
        loop_ub = 127;
      }

      fileid = (int8_T)loop_ub;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S5>/SPERTE_measurement_function' */
static int32_T Feedforward_tunning_mod_cfclose(real_T fid)
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
    f = Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles[b_fileid
      - 3];
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
      Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles[fileid - 3]
        = NULL;
      Feedforward_tunning_model_Control_Engineering_DW.eml_autoflush[fileid - 3]
        = true;
    }
  }

  return st;
}

/* Model step function for TID0 */
void Feedforward_tunning_model_Control_Engineering_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  FILE *f;
  emxArray_char_T_Feedforward_t_T *str;
  emxArray_char_T_Feedforward_t_T *str_0;
  int8_T b_fileid;
  boolean_T autoflush;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Constant: '<S7>/Start setpoint' */
  Feedforward_tunning_model_Control_Engineering_B.Startsetpoint =
    Feedforward_tunning_model_Control_Engineering_P.Refpower_stat;

  /* S-Function (ref3b): '<S9>/S-Function' */

  /* Level2 S-Function Block: '<S9>/S-Function' (ref3b) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Supervisor): '<S11>/S-Function' */

  /* Level2 S-Function Block: '<S11>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Ebox): '<S10>/ec_Ebox' */

  /* Level2 S-Function Block: '<S10>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Quantizer: '<Root>/Quantizer1' */
  Feedforward_tunning_model_Control_Engineering_B.Input = rt_roundd_snf
    (Feedforward_tunning_model_Control_Engineering_B.SFunction[2] /
     Feedforward_tunning_model_Control_Engineering_P.Quantizer1_Interval) *
    Feedforward_tunning_model_Control_Engineering_P.Quantizer1_Interval;

  /* ManualSwitch: '<Root>/Select encoder' */
  if (Feedforward_tunning_model_Control_Engineering_P.Selectencoder_CurrentSetting
      == 1) {
    /* ManualSwitch: '<Root>/Select encoder' incorporates:
     *  Gain: '<S1>/count2rad'
     */
    Feedforward_tunning_model_Control_Engineering_B.Output =
      Feedforward_tunning_model_Control_Engineering_P.count2rad_Gain *
      Feedforward_tunning_model_Control_Engineering_B.ec_Ebox_o2[0];
  } else {
    /* ManualSwitch: '<Root>/Select encoder' incorporates:
     *  Gain: '<Root>/Gain'
     *  Gain: '<S1>/count2rad'
     */
    Feedforward_tunning_model_Control_Engineering_B.Output =
      Feedforward_tunning_model_Control_Engineering_P.count2rad_Gain *
      Feedforward_tunning_model_Control_Engineering_B.ec_Ebox_o2[1] *
      Feedforward_tunning_model_Control_Engineering_P.Gain_Gain;
  }

  /* End of ManualSwitch: '<Root>/Select encoder' */

  /* Sum: '<Root>/Sum' */
  Feedforward_tunning_model_Control_Engineering_B.Error =
    Feedforward_tunning_model_Control_Engineering_B.Input -
    Feedforward_tunning_model_Control_Engineering_B.Output;

  /* Gain: '<S8>/Gain1' */
  Feedforward_tunning_model_Control_Engineering_B.Gain1 =
    Feedforward_tunning_model_Control_Engineering_P.Gain1_Gain *
    Feedforward_tunning_model_Control_Engineering_B.Error;

  /* S-Function (dleadlag): '<S8>/Dctleadlag2' */

  /* Level2 S-Function Block: '<S8>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S8>/Dctnotch3' */

  /* Level2 S-Function Block: '<S8>/Dctnotch3' (dnotch) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dlowpass1): '<S8>/Dct1lowpass4' */

  /* Level2 S-Function Block: '<S8>/Dct1lowpass4' (dlowpass1) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S8>/Dctnotch5' */

  /* Level2 S-Function Block: '<S8>/Dctnotch5' (dnotch) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[6];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S8>/Dctnotch6' */

  /* Level2 S-Function Block: '<S8>/Dctnotch6' (dnotch) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[7];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dweakint): '<S8>/Dctintegrator7' */

  /* Level2 S-Function Block: '<S8>/Dctintegrator7' (dweakint) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[8];
    sfcnOutputs(rts,0);
  }

  /* Signum: '<Root>/Sign' */
  if (rtIsNaN(Feedforward_tunning_model_Control_Engineering_B.SFunction[1])) {
    Feedforward_tunning_model_Control_Engineering_B.u0 = (rtNaN);
  } else if (Feedforward_tunning_model_Control_Engineering_B.SFunction[1] < 0.0)
  {
    Feedforward_tunning_model_Control_Engineering_B.u0 = -1.0;
  } else {
    Feedforward_tunning_model_Control_Engineering_B.u0 =
      (Feedforward_tunning_model_Control_Engineering_B.SFunction[1] > 0.0);
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  Gain: '<S2>/Slider Gain'
   *  Gain: '<S3>/Slider Gain'
   *  Gain: '<S4>/Slider Gain'
   *  Signum: '<Root>/Sign'
   */
  Feedforward_tunning_model_Control_Engineering_B.u0 =
    ((Feedforward_tunning_model_Control_Engineering_P.Kfc_gain *
      Feedforward_tunning_model_Control_Engineering_B.u0 +
      Feedforward_tunning_model_Control_Engineering_P.Kfa_gain *
      Feedforward_tunning_model_Control_Engineering_B.SFunction[0]) +
     Feedforward_tunning_model_Control_Engineering_P.Kfv_gain *
     Feedforward_tunning_model_Control_Engineering_B.SFunction[1]) +
    Feedforward_tunning_model_Control_Engineering_B.Dctintegrator7;

  /* Saturate: '<S1>/Saturation' */
  if (Feedforward_tunning_model_Control_Engineering_B.u0 >
      Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat) {
    Feedforward_tunning_model_Control_Engineering_B.u0 =
      Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat;
  } else if (Feedforward_tunning_model_Control_Engineering_B.u0 <
             Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat)
  {
    Feedforward_tunning_model_Control_Engineering_B.u0 =
      Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat;
  }

  /* Saturate: '<S10>/Saturation' */
  if (Feedforward_tunning_model_Control_Engineering_B.u0 >
      Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat_d) {
    /* Saturate: '<S10>/Saturation' */
    Feedforward_tunning_model_Control_Engineering_B.Saturation[0] =
      Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat_d;
  } else if (Feedforward_tunning_model_Control_Engineering_B.u0 <
             Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat_e)
  {
    /* Saturate: '<S10>/Saturation' */
    Feedforward_tunning_model_Control_Engineering_B.Saturation[0] =
      Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S10>/Saturation' */
    Feedforward_tunning_model_Control_Engineering_B.Saturation[0] =
      Feedforward_tunning_model_Control_Engineering_B.u0;
  }

  /* Saturate: '<S1>/Saturation' incorporates:
   *  Constant: '<S1>/Constant2'
   */
  if (Feedforward_tunning_model_Control_Engineering_P.Constant2_Value >
      Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat) {
    Feedforward_tunning_model_Control_Engineering_B.u0 =
      Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat;
  } else if (Feedforward_tunning_model_Control_Engineering_P.Constant2_Value <
             Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat)
  {
    Feedforward_tunning_model_Control_Engineering_B.u0 =
      Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat;
  } else {
    Feedforward_tunning_model_Control_Engineering_B.u0 =
      Feedforward_tunning_model_Control_Engineering_P.Constant2_Value;
  }

  /* Saturate: '<S10>/Saturation' */
  if (Feedforward_tunning_model_Control_Engineering_B.u0 >
      Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat_d) {
    /* Saturate: '<S10>/Saturation' */
    Feedforward_tunning_model_Control_Engineering_B.Saturation[1] =
      Feedforward_tunning_model_Control_Engineering_P.Saturation_UpperSat_d;
  } else if (Feedforward_tunning_model_Control_Engineering_B.u0 <
             Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat_e)
  {
    /* Saturate: '<S10>/Saturation' */
    Feedforward_tunning_model_Control_Engineering_B.Saturation[1] =
      Feedforward_tunning_model_Control_Engineering_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S10>/Saturation' */
    Feedforward_tunning_model_Control_Engineering_B.Saturation[1] =
      Feedforward_tunning_model_Control_Engineering_B.u0;
  }

  /* MATLAB Function: '<S5>/SPERTE_measurement_function' incorporates:
   *  Constant: '<S5>/SPERTE_measurement_samples'
   *  Constant: '<S5>/SPERTE_measurement_trigger_command'
   *  SignalConversion generated from: '<S12>/ SFunction '
   */
  Feedforward_tunning_model_Control_Engineering_DW.sfEvent =
    Feedforward_tunning__CALL_EVENT;
  if ((((Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_triggertype
         == 1) &&
        (Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_trigger_comman
         == 1)) ||
       ((Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_triggertype
         == 2) &&
        (Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_trigger_comman
         == 1))) && (Feedforward_tunning_model_Control_Engineering_DW.busy != 1))
  {
    Feedforward_tunning_model_Control_Engineering_B.nbytes = (int32_T)snprintf
      (NULL, 0, "measurement_%d.bin",
       Feedforward_tunning_model_Control_Engineering_DW.NF) + 1;
    Feedforward_tunn_emxInit_char_T(&str, 2);
    Feedforward_tunning_model_Control_Engineering_B.i = str->size[0] * str->
      size[1];
    str->size[0] = 1;
    str->size[1] = Feedforward_tunning_model_Control_Engineering_B.nbytes;
    Feedfo_emxEnsureCapacity_char_T(str,
      Feedforward_tunning_model_Control_Engineering_B.i);
    snprintf(&str->data[0], (size_t)
             Feedforward_tunning_model_Control_Engineering_B.nbytes,
             "measurement_%d.bin",
             Feedforward_tunning_model_Control_Engineering_DW.NF);
    if (Feedforward_tunning_model_Control_Engineering_B.nbytes - 1 < 1) {
      Feedforward_tunning_model_Control_Engineering_B.nbytes = -1;
    } else {
      Feedforward_tunning_model_Control_Engineering_B.nbytes -= 2;
    }

    Feedforward_tunn_emxInit_char_T(&str_0, 2);
    Feedforward_tunning_model_Control_Engineering_B.i = str_0->size[0] *
      str_0->size[1];
    str_0->size[0] = 1;
    str_0->size[1] = Feedforward_tunning_model_Control_Engineering_B.nbytes + 1;
    Feedfo_emxEnsureCapacity_char_T(str_0,
      Feedforward_tunning_model_Control_Engineering_B.i);
    if (Feedforward_tunning_model_Control_Engineering_B.nbytes >= 0) {
      memcpy(&str_0->data[0], &str->data[0], (uint32_T)
             (Feedforward_tunning_model_Control_Engineering_B.nbytes + 1) *
             sizeof(char_T));
    }

    Feedforward_tunn_emxFree_char_T(&str);
    b_fileid = Feedforward_tunning_mode_cfopen(str_0, "wb");
    Feedforward_tunn_emxFree_char_T(&str_0);
    Feedforward_tunning_model_Control_Engineering_DW.fileID = b_fileid;
    Feedforward_tunning_model_Control_Engineering_B.nbytes =
      Feedforward_tunning_model_Control_Engineering_DW.NF + 1;
    if (Feedforward_tunning_model_Control_Engineering_DW.NF + 1 > 32767) {
      Feedforward_tunning_model_Control_Engineering_B.nbytes = 32767;
    }

    Feedforward_tunning_model_Control_Engineering_DW.NF = (int16_T)
      Feedforward_tunning_model_Control_Engineering_B.nbytes;
    Feedforward_tunning_model_Control_Engineering_DW.busy = 1U;
    Feedforward_tunning_model_Control_Engineering_DW.NS = 0U;
  }

  if (Feedforward_tunning_model_Control_Engineering_DW.busy == 1) {
    if (Feedforward_tunning_model_Control_Engineering_DW.NS <
        Feedforward_tunning_model_Control_Engineering_P.MeasurementBlock_N_samples)
    {
      b_fileid = (int8_T)Feedforward_tunning_model_Control_Engineering_DW.fileID;
      if (((int8_T)Feedforward_tunning_model_Control_Engineering_DW.fileID < 0) ||
          (Feedforward_tunning_model_Control_Engineering_DW.fileID != (int8_T)
           Feedforward_tunning_model_Control_Engineering_DW.fileID)) {
        b_fileid = -1;
      }

      if (b_fileid >= 3) {
        autoflush =
          Feedforward_tunning_model_Control_Engineering_DW.eml_autoflush[b_fileid
          - 3];
        f =
          Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles[b_fileid
          - 3];
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

      if (!(Feedforward_tunning_model_Control_Engineering_DW.fileID != 0.0)) {
        f = NULL;
      }

      if (!(f == NULL)) {
        Feedforward_tunning_model_Control_Engineering_B.xout[0] = (real32_T)
          Feedforward_tunning_model_Control_Engineering_B.Input;
        Feedforward_tunning_model_Control_Engineering_B.xout[1] = (real32_T)
          Feedforward_tunning_model_Control_Engineering_B.Output;
        Feedforward_tunning_model_Control_Engineering_B.xout[2] = (real32_T)
          Feedforward_tunning_model_Control_Engineering_B.Error;
        Feedforward_tunning_model_Control_Engineering_B.bytesOutSizet = fwrite
          (&Feedforward_tunning_model_Control_Engineering_B.xout[0], sizeof
           (real32_T), (size_t)3, f);
        if (((real_T)
             Feedforward_tunning_model_Control_Engineering_B.bytesOutSizet > 0.0)
            && autoflush) {
          fflush(f);
        }
      }

      Feedforward_tunning_model_Control_Engineering_B.qY =
        Feedforward_tunning_model_Control_Engineering_DW.NS + 1U;
      if (Feedforward_tunning_model_Control_Engineering_DW.NS + 1U <
          Feedforward_tunning_model_Control_Engineering_DW.NS) {
        Feedforward_tunning_model_Control_Engineering_B.qY = MAX_uint32_T;
      }

      Feedforward_tunning_model_Control_Engineering_DW.NS =
        Feedforward_tunning_model_Control_Engineering_B.qY;
    } else {
      Feedforward_tunning_mod_cfclose
        (Feedforward_tunning_model_Control_Engineering_DW.fileID);
      Feedforward_tunning_model_Control_Engineering_DW.busy = 0U;
      Feedforward_tunning_model_Control_Engineering_DW.NS = 0U;
    }
  }

  /* End of MATLAB Function: '<S5>/SPERTE_measurement_function' */

  /* RateTransition: '<S6>/Downsample' */
  if (Feedforward_tunning_model_Control_Engineering_M->Timing.RateInteraction.TID1_2)
  {
    Feedforward_tunning_model_Control_Engineering_DW.Downsample_Buffer[0] =
      Feedforward_tunning_model_Control_Engineering_B.Input;
    Feedforward_tunning_model_Control_Engineering_DW.Downsample_Buffer[1] =
      Feedforward_tunning_model_Control_Engineering_B.Output;
    Feedforward_tunning_model_Control_Engineering_DW.Downsample_Buffer[2] =
      Feedforward_tunning_model_Control_Engineering_B.Error;
  }

  /* End of RateTransition: '<S6>/Downsample' */
  /* Constant: '<S1>/Constant1' */
  memcpy(&Feedforward_tunning_model_Control_Engineering_B.Constant1[0],
         &Feedforward_tunning_model_Control_Engineering_P.Constant1_Value[0],
         sizeof(real_T) << 3U);

  /* Gain: '<S10>/Gain' incorporates:
   *  Constant: '<S1>/Constant'
   */
  Feedforward_tunning_model_Control_Engineering_B.Gain[0] =
    Feedforward_tunning_model_Control_Engineering_P.Gain_Gain_g *
    Feedforward_tunning_model_Control_Engineering_P.Constant_Value[0];
  Feedforward_tunning_model_Control_Engineering_B.Gain[1] =
    Feedforward_tunning_model_Control_Engineering_P.Gain_Gain_g *
    Feedforward_tunning_model_Control_Engineering_P.Constant_Value[1];

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, (real_T)
                  Feedforward_tunning_model_Control_Engineering_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Feedforward_tunning_model_Control_Engineering_M)!=-1) &&
        !((rtmGetTFinal(Feedforward_tunning_model_Control_Engineering_M)-
           Feedforward_tunning_model_Control_Engineering_M->Timing.t[0]) >
          Feedforward_tunning_model_Control_Engineering_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(Feedforward_tunning_model_Control_Engineering_M,
                        "Simulation finished");
    }

    if (rtmGetStopRequested(Feedforward_tunning_model_Control_Engineering_M)) {
      rtmSetErrorStatus(Feedforward_tunning_model_Control_Engineering_M,
                        "Simulation finished");
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
  if (!(++Feedforward_tunning_model_Control_Engineering_M->Timing.clockTick0)) {
    ++Feedforward_tunning_model_Control_Engineering_M->Timing.clockTickH0;
  }

  Feedforward_tunning_model_Control_Engineering_M->Timing.t[0] =
    Feedforward_tunning_model_Control_Engineering_M->Timing.clockTick0 *
    Feedforward_tunning_model_Control_Engineering_M->Timing.stepSize0 +
    Feedforward_tunning_model_Control_Engineering_M->Timing.clockTickH0 *
    Feedforward_tunning_model_Control_Engineering_M->Timing.stepSize0 *
    4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Feedforward_tunning_model_Control_Engineering_M->Timing.clockTick1)) {
    ++Feedforward_tunning_model_Control_Engineering_M->Timing.clockTickH1;
  }

  Feedforward_tunning_model_Control_Engineering_M->Timing.t[1] =
    Feedforward_tunning_model_Control_Engineering_M->Timing.clockTick1 *
    Feedforward_tunning_model_Control_Engineering_M->Timing.stepSize1 +
    Feedforward_tunning_model_Control_Engineering_M->Timing.clockTickH1 *
    Feedforward_tunning_model_Control_Engineering_M->Timing.stepSize1 *
    4294967296.0;
}

/* Model step function for TID2 */
void Feedforward_tunning_model_Control_Engineering_step2(void) /* Sample time: [0.002s, 0.0s] */
{
  /* RateTransition: '<S6>/Downsample' */
  Feedforward_tunning_model_Control_Engineering_B.Downsample[0] =
    Feedforward_tunning_model_Control_Engineering_DW.Downsample_Buffer[0];
  Feedforward_tunning_model_Control_Engineering_B.Downsample[1] =
    Feedforward_tunning_model_Control_Engineering_DW.Downsample_Buffer[1];
  Feedforward_tunning_model_Control_Engineering_B.Downsample[2] =
    Feedforward_tunning_model_Control_Engineering_DW.Downsample_Buffer[2];
  rtExtModeUpload(2, (real_T)
                  (((Feedforward_tunning_model_Control_Engineering_M->Timing.clockTick2
                     +Feedforward_tunning_model_Control_Engineering_M->Timing.clockTickH2*
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
  Feedforward_tunning_model_Control_Engineering_M->Timing.clockTick2++;
  if (!Feedforward_tunning_model_Control_Engineering_M->Timing.clockTick2) {
    Feedforward_tunning_model_Control_Engineering_M->Timing.clockTickH2++;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Feedforward_tunning_model_Control_Engineering_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Feedforward_tunning_model_Control_Engineering_step0();
    break;

   case 2 :
    Feedforward_tunning_model_Control_Engineering_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Feedforward_tunning_model_Control_Engineering_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Feedforward_tunning_model_Control_Engineering_M, 0,
                sizeof(RT_MODEL_Feedforward_tunning_model_Control_Engineering_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr
      (&Feedforward_tunning_model_Control_Engineering_M->solverInfo,
       &Feedforward_tunning_model_Control_Engineering_M->Timing.simTimeStep);
    rtsiSetTPtr(&Feedforward_tunning_model_Control_Engineering_M->solverInfo,
                &rtmGetTPtr(Feedforward_tunning_model_Control_Engineering_M));
    rtsiSetStepSizePtr
      (&Feedforward_tunning_model_Control_Engineering_M->solverInfo,
       &Feedforward_tunning_model_Control_Engineering_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr
      (&Feedforward_tunning_model_Control_Engineering_M->solverInfo,
       (&rtmGetErrorStatus(Feedforward_tunning_model_Control_Engineering_M)));
    rtsiSetRTModelPtr
      (&Feedforward_tunning_model_Control_Engineering_M->solverInfo,
       Feedforward_tunning_model_Control_Engineering_M);
  }

  rtsiSetSimTimeStep
    (&Feedforward_tunning_model_Control_Engineering_M->solverInfo,
     MAJOR_TIME_STEP);
  rtsiSetSolverName(&Feedforward_tunning_model_Control_Engineering_M->solverInfo,
                    "FixedStepDiscrete");
  Feedforward_tunning_model_Control_Engineering_M->solverInfoPtr =
    (&Feedforward_tunning_model_Control_Engineering_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      Feedforward_tunning_model_Control_Engineering_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Feedforward_tunning_model_Control_Engineering_M points to
       static memory which is guaranteed to be non-NULL" */
    Feedforward_tunning_model_Control_Engineering_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    Feedforward_tunning_model_Control_Engineering_M->Timing.sampleTimes =
      (&Feedforward_tunning_model_Control_Engineering_M->
       Timing.sampleTimesArray[0]);
    Feedforward_tunning_model_Control_Engineering_M->Timing.offsetTimes =
      (&Feedforward_tunning_model_Control_Engineering_M->
       Timing.offsetTimesArray[0]);

    /* task periods */
    Feedforward_tunning_model_Control_Engineering_M->Timing.sampleTimes[0] =
      (0.0);
    Feedforward_tunning_model_Control_Engineering_M->Timing.sampleTimes[1] =
      (0.00025);
    Feedforward_tunning_model_Control_Engineering_M->Timing.sampleTimes[2] =
      (0.002);

    /* task offsets */
    Feedforward_tunning_model_Control_Engineering_M->Timing.offsetTimes[0] =
      (0.0);
    Feedforward_tunning_model_Control_Engineering_M->Timing.offsetTimes[1] =
      (0.0);
    Feedforward_tunning_model_Control_Engineering_M->Timing.offsetTimes[2] =
      (0.0);
  }

  rtmSetTPtr(Feedforward_tunning_model_Control_Engineering_M,
             &Feedforward_tunning_model_Control_Engineering_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      Feedforward_tunning_model_Control_Engineering_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Feedforward_tunning_model_Control_Engineering_M->Timing.perTaskSampleHitsArray;
    Feedforward_tunning_model_Control_Engineering_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Feedforward_tunning_model_Control_Engineering_M->Timing.sampleHits =
      (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Feedforward_tunning_model_Control_Engineering_M, 50.0);
  Feedforward_tunning_model_Control_Engineering_M->Timing.stepSize0 = 0.00025;
  Feedforward_tunning_model_Control_Engineering_M->Timing.stepSize1 = 0.00025;

  /* External mode info */
  Feedforward_tunning_model_Control_Engineering_M->Sizes.checksums[0] =
    (47953028U);
  Feedforward_tunning_model_Control_Engineering_M->Sizes.checksums[1] =
    (2527338178U);
  Feedforward_tunning_model_Control_Engineering_M->Sizes.checksums[2] =
    (981917322U);
  Feedforward_tunning_model_Control_Engineering_M->Sizes.checksums[3] =
    (838329712U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    Feedforward_tunning_model_Control_Engineering_M->extModeInfo =
      (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr
      (Feedforward_tunning_model_Control_Engineering_M->extModeInfo,
       &Feedforward_tunning_model_Control_Engineering_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr
      (Feedforward_tunning_model_Control_Engineering_M->extModeInfo,
       Feedforward_tunning_model_Control_Engineering_M->Sizes.checksums);
    rteiSetTPtr(Feedforward_tunning_model_Control_Engineering_M->extModeInfo,
                rtmGetTPtr(Feedforward_tunning_model_Control_Engineering_M));
  }

  Feedforward_tunning_model_Control_Engineering_M->solverInfoPtr =
    (&Feedforward_tunning_model_Control_Engineering_M->solverInfo);
  Feedforward_tunning_model_Control_Engineering_M->Timing.stepSize = (0.00025);
  rtsiSetFixedStepSize
    (&Feedforward_tunning_model_Control_Engineering_M->solverInfo, 0.00025);
  rtsiSetSolverMode(&Feedforward_tunning_model_Control_Engineering_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &Feedforward_tunning_model_Control_Engineering_B), 0,
                sizeof(B_Feedforward_tunning_model_Control_Engineering_T));

  /* states (dwork) */
  (void) memset((void *)&Feedforward_tunning_model_Control_Engineering_DW, 0,
                sizeof(DW_Feedforward_tunning_model_Control_Engineering_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Feedforward_tunning_model_Control_Engineering_M->SpecialInfo.mappingInfo = (
      &dtInfo);
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
      &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.sfcnInfo;
    Feedforward_tunning_model_Control_Engineering_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (Feedforward_tunning_model_Control_Engineering_M)));
    Feedforward_tunning_model_Control_Engineering_M->Sizes.numSampTimes = (3);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &Feedforward_tunning_model_Control_Engineering_M->Sizes.numSampTimes);
    Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs
      [0] = (&rtmGetTPtr(Feedforward_tunning_model_Control_Engineering_M)[0]);
    Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs
      [1] = (&rtmGetTPtr(Feedforward_tunning_model_Control_Engineering_M)[1]);
    Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs
      [2] = (&rtmGetTPtr(Feedforward_tunning_model_Control_Engineering_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,
                   Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart
                     (Feedforward_tunning_model_Control_Engineering_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal
                     (Feedforward_tunning_model_Control_Engineering_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Feedforward_tunning_model_Control_Engineering_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &Feedforward_tunning_model_Control_Engineering_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (Feedforward_tunning_model_Control_Engineering_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Feedforward_tunning_model_Control_Engineering_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Feedforward_tunning_model_Control_Engineering_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Feedforward_tunning_model_Control_Engineering_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &Feedforward_tunning_model_Control_Engineering_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Feedforward_tunning_model_Control_Engineering_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo,
                      &Feedforward_tunning_model_Control_Engineering_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &Feedforward_tunning_model_Control_Engineering_M->solverInfoPtr);
  }

  Feedforward_tunning_model_Control_Engineering_M->Sizes.numSFcns = (9);

  /* register each child */
  {
    (void) memset((void *)
                  &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  9*sizeof(SimStruct));
    Feedforward_tunning_model_Control_Engineering_M->childSfunctions =
      (&Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.childSFunctionPtrs
       [0]);

    {
      int_T i;
      for (i = 0; i < 9; i++) {
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[i] =
          (&Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.childSFunctions
           [i]);
      }
    }

    /* Level2 S-Function Block: Feedforward_tunning_model_Control_Engineering/<S9>/S-Function (ref3b) */
    {
      SimStruct *rts =
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Feedforward_tunning_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] =
            &Feedforward_tunning_model_Control_Engineering_B.Startsetpoint;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Feedforward_tunning_model_Control_Engineering_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "Feedforward_tunning_model_Control_Engineering/Subsystem/S-Function");
      ssSetRTModel(rts,Feedforward_tunning_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.SFunction_P1_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Feedforward_tunning_model_Control_Engineering_DW.SFunction_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 50);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Feedforward_tunning_model_Control_Engineering_DW.SFunction_RWORK
                   [0]);
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

    /* Level2 S-Function Block: Feedforward_tunning_model_Control_Engineering/<S11>/S-Function (ec_Supervisor) */
    {
      SimStruct *rts =
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Feedforward_tunning_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Feedforward_tunning_model_Control_Engineering_B.SFunction_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "Feedforward_tunning_model_Control_Engineering/Fourth Order Motion System/Ethercat Supervisor/S-Function");
      ssSetRTModel(rts,Feedforward_tunning_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.SFunction_P1_Size_k);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.SFunction_P2_Size);
      }

      /* registration */
      ec_Supervisor(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCsAsInt(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: Feedforward_tunning_model_Control_Engineering/<S10>/ec_Ebox (ec_Ebox) */
    {
      SimStruct *rts =
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Feedforward_tunning_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] =
            Feedforward_tunning_model_Control_Engineering_B.Saturation;
          sfcnUPtrs[1] =
            &Feedforward_tunning_model_Control_Engineering_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = Feedforward_tunning_model_Control_Engineering_B.Gain;
          sfcnUPtrs[1] = &Feedforward_tunning_model_Control_Engineering_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.UPtrs2;

          {
            int_T i1;
            const real_T *u2 =
              Feedforward_tunning_model_Control_Engineering_B.Constant1;
            for (i1=0; i1 < 8; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidthAsInt(rts, 2, 8);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Feedforward_tunning_model_Control_Engineering_B.ec_Ebox_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 2);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            Feedforward_tunning_model_Control_Engineering_B.ec_Ebox_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidthAsInt(rts, 2, 8);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            Feedforward_tunning_model_Control_Engineering_B.ec_Ebox_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_Ebox");
      ssSetPath(rts,
                "Feedforward_tunning_model_Control_Engineering/Fourth Order Motion System/Ethercat E-box/ec_Ebox");
      ssSetRTModel(rts,Feedforward_tunning_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.ec_Ebox_P1_Size);
      }

      /* registration */
      ec_Ebox(rts);
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
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: Feedforward_tunning_model_Control_Engineering/<S8>/Dctleadlag2 (dleadlag) */
    {
      SimStruct *rts =
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Feedforward_tunning_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Feedforward_tunning_model_Control_Engineering_B.Gain1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Feedforward_tunning_model_Control_Engineering_B.Dctleadlag2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag2");
      ssSetPath(rts,
                "Feedforward_tunning_model_Control_Engineering/Robust_performance_controller_block/Dctleadlag2");
      ssSetRTModel(rts,Feedforward_tunning_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctleadlag2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctleadlag2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctleadlag2_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Feedforward_tunning_model_Control_Engineering_DW.Dctleadlag2_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Feedforward_tunning_model_Control_Engineering_DW.Dctleadlag2_RWORK
                   [0]);
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

    /* Level2 S-Function Block: Feedforward_tunning_model_Control_Engineering/<S8>/Dctnotch3 (dnotch) */
    {
      SimStruct *rts =
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Feedforward_tunning_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] =
            &Feedforward_tunning_model_Control_Engineering_B.Dctleadlag2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Feedforward_tunning_model_Control_Engineering_B.Dctnotch3));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch3");
      ssSetPath(rts,
                "Feedforward_tunning_model_Control_Engineering/Robust_performance_controller_block/Dctnotch3");
      ssSetRTModel(rts,Feedforward_tunning_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch3_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Feedforward_tunning_model_Control_Engineering_DW.Dctnotch3_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Feedforward_tunning_model_Control_Engineering_DW.Dctnotch3_RWORK
                   [0]);
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

    /* Level2 S-Function Block: Feedforward_tunning_model_Control_Engineering/<S8>/Dct1lowpass4 (dlowpass1) */
    {
      SimStruct *rts =
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Feedforward_tunning_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] =
            &Feedforward_tunning_model_Control_Engineering_B.Dctnotch3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Feedforward_tunning_model_Control_Engineering_B.Dct1lowpass4));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dct1lowpass4");
      ssSetPath(rts,
                "Feedforward_tunning_model_Control_Engineering/Robust_performance_controller_block/Dct1lowpass4");
      ssSetRTModel(rts,Feedforward_tunning_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dct1lowpass4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dct1lowpass4_P2_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Feedforward_tunning_model_Control_Engineering_DW.Dct1lowpass4_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Feedforward_tunning_model_Control_Engineering_DW.Dct1lowpass4_RWORK
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

    /* Level2 S-Function Block: Feedforward_tunning_model_Control_Engineering/<S8>/Dctnotch5 (dnotch) */
    {
      SimStruct *rts =
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [6]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [6]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Feedforward_tunning_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [6]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [6]);
        ssSetPeriodicStatesInfo(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.UPtrs0;
          sfcnUPtrs[0] =
            &Feedforward_tunning_model_Control_Engineering_B.Dct1lowpass4;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Feedforward_tunning_model_Control_Engineering_B.Dctnotch5));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch5");
      ssSetPath(rts,
                "Feedforward_tunning_model_Control_Engineering/Robust_performance_controller_block/Dctnotch5");
      ssSetRTModel(rts,Feedforward_tunning_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch5_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Feedforward_tunning_model_Control_Engineering_DW.Dctnotch5_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Feedforward_tunning_model_Control_Engineering_DW.Dctnotch5_RWORK
                   [0]);
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

    /* Level2 S-Function Block: Feedforward_tunning_model_Control_Engineering/<S8>/Dctnotch6 (dnotch) */
    {
      SimStruct *rts =
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [7]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [7]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Feedforward_tunning_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [7]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [7]);
        ssSetPeriodicStatesInfo(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.UPtrs0;
          sfcnUPtrs[0] =
            &Feedforward_tunning_model_Control_Engineering_B.Dctnotch5;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Feedforward_tunning_model_Control_Engineering_B.Dctnotch6));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch6");
      ssSetPath(rts,
                "Feedforward_tunning_model_Control_Engineering/Robust_performance_controller_block/Dctnotch6");
      ssSetRTModel(rts,Feedforward_tunning_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch6_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch6_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch6_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch6_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctnotch6_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Feedforward_tunning_model_Control_Engineering_DW.Dctnotch6_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Feedforward_tunning_model_Control_Engineering_DW.Dctnotch6_RWORK
                   [0]);
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

    /* Level2 S-Function Block: Feedforward_tunning_model_Control_Engineering/<S8>/Dctintegrator7 (dweakint) */
    {
      SimStruct *rts =
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap =
        Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [8]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [8]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Feedforward_tunning_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [8]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [8]);
        ssSetPeriodicStatesInfo(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [8]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.UPtrs0;
          sfcnUPtrs[0] =
            &Feedforward_tunning_model_Control_Engineering_B.Dctnotch6;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Feedforward_tunning_model_Control_Engineering_B.Dctintegrator7));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctintegrator7");
      ssSetPath(rts,
                "Feedforward_tunning_model_Control_Engineering/Robust_performance_controller_block/Dctintegrator7");
      ssSetRTModel(rts,Feedforward_tunning_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctintegrator7_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Feedforward_tunning_model_Control_Engineering_P.Dctintegrator7_P2_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Feedforward_tunning_model_Control_Engineering_DW.Dctintegrator7_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Feedforward_tunning_model_Control_Engineering_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Feedforward_tunning_model_Control_Engineering_DW.Dctintegrator7_RWORK
                   [0]);
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
  }

  /* Start for Constant: '<S7>/Start setpoint' */
  Feedforward_tunning_model_Control_Engineering_B.Startsetpoint =
    Feedforward_tunning_model_Control_Engineering_P.Refpower_stat;

  /* Start for S-Function (ec_Supervisor): '<S11>/S-Function' */
  /* Level2 S-Function Block: '<S11>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dleadlag): '<S8>/Dctleadlag2' */
  /* Level2 S-Function Block: '<S8>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S8>/Dctnotch3' */
  /* Level2 S-Function Block: '<S8>/Dctnotch3' (dnotch) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dlowpass1): '<S8>/Dct1lowpass4' */
  /* Level2 S-Function Block: '<S8>/Dct1lowpass4' (dlowpass1) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S8>/Dctnotch5' */
  /* Level2 S-Function Block: '<S8>/Dctnotch5' (dnotch) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S8>/Dctnotch6' */
  /* Level2 S-Function Block: '<S8>/Dctnotch6' (dnotch) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dweakint): '<S8>/Dctintegrator7' */
  /* Level2 S-Function Block: '<S8>/Dctintegrator7' (dweakint) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S1>/Constant1' */
  memcpy(&Feedforward_tunning_model_Control_Engineering_B.Constant1[0],
         &Feedforward_tunning_model_Control_Engineering_P.Constant1_Value[0],
         sizeof(real_T) << 3U);

  {
    int32_T i;

    /* InitializeConditions for S-Function (ref3b): '<S9>/S-Function' */
    /* Level2 S-Function Block: '<S9>/S-Function' (ref3b) */
    {
      SimStruct *rts =
        Feedforward_tunning_model_Control_Engineering_M->childSfunctions[0];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* SystemInitialize for MATLAB Function: '<S5>/SPERTE_measurement_function' */
    for (i = 0; i < 20; i++) {
      Feedforward_tunning_model_Control_Engineering_DW.eml_autoflush[i] = false;
    }

    Feedforward_tunning_model_Control_Engineering_DW.eml_autoflush_not_empty =
      true;
    for (i = 0; i < 20; i++) {
      Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles[i] = NULL;
    }

    Feedforward_tunning_model_Control_Engineering_DW.eml_openfiles_not_empty =
      true;
    Feedforward_tunning_model_Control_Engineering_DW.NF = 0;
    Feedforward_tunning_model_Control_Engineering_DW.NF_not_empty = true;
    Feedforward_tunning_model_Control_Engineering_DW.NS = 0U;
    Feedforward_tunning_model_Control_Engineering_DW.NS_not_empty = true;
    Feedforward_tunning_model_Control_Engineering_DW.fileID = 0.0;
    Feedforward_tunning_model_Control_Engineering_DW.fileID_not_empty = true;
    Feedforward_tunning_model_Control_Engineering_DW.busy = 0U;
    Feedforward_tunning_model_Control_Engineering_DW.busy_not_empty = true;
    Feedforward_tunning_model_Control_Engineering_DW.doneDoubleBufferReInit =
      false;
    Feedforward_tunning_model_Control_Engineering_DW.sfEvent =
      Feedforward_tunning__CALL_EVENT;

    /* End of SystemInitialize for MATLAB Function: '<S5>/SPERTE_measurement_function' */
  }
}

/* Model terminate function */
void Feedforward_tunning_model_Control_Engineering_terminate(void)
{
  /* Terminate for S-Function (ref3b): '<S9>/S-Function' */
  /* Level2 S-Function Block: '<S9>/S-Function' (ref3b) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Supervisor): '<S11>/S-Function' */
  /* Level2 S-Function Block: '<S11>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Ebox): '<S10>/ec_Ebox' */
  /* Level2 S-Function Block: '<S10>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S8>/Dctleadlag2' */
  /* Level2 S-Function Block: '<S8>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S8>/Dctnotch3' */
  /* Level2 S-Function Block: '<S8>/Dctnotch3' (dnotch) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dlowpass1): '<S8>/Dct1lowpass4' */
  /* Level2 S-Function Block: '<S8>/Dct1lowpass4' (dlowpass1) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S8>/Dctnotch5' */
  /* Level2 S-Function Block: '<S8>/Dctnotch5' (dnotch) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S8>/Dctnotch6' */
  /* Level2 S-Function Block: '<S8>/Dctnotch6' (dnotch) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dweakint): '<S8>/Dctintegrator7' */
  /* Level2 S-Function Block: '<S8>/Dctintegrator7' (dweakint) */
  {
    SimStruct *rts =
      Feedforward_tunning_model_Control_Engineering_M->childSfunctions[8];
    sfcnTerminate(rts);
  }
}
