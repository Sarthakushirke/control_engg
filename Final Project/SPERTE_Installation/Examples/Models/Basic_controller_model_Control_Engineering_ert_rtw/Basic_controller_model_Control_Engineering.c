/*
 * Basic_controller_model_Control_Engineering.c
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
#include "Basic_controller_model_Control_Engineering_types.h"
#include "rtwtypes.h"
#include <string.h>
#include <stddef.h>
#include "Basic_controller_model_Control_Engineering_private.h"
#include <stdio.h>
#include <stdlib.h>
#include "rt_nonfinite.h"
#include <math.h>
#include "Basic_controller_model_Control_Engineering_dt.h"

/* Named constants for MATLAB Function: '<S3>/SPERTE_measurement_function' */
#define Basic_controller_mod_CALL_EVENT (-1)

/* Block signals (default storage) */
B_Basic_controller_model_Control_Engineering_T
  Basic_controller_model_Control_Engineering_B;

/* Block states (default storage) */
DW_Basic_controller_model_Control_Engineering_T
  Basic_controller_model_Control_Engineering_DW;

/* Real-time model */
static RT_MODEL_Basic_controller_model_Control_Engineering_T
  Basic_controller_model_Control_Engineering_M_;
RT_MODEL_Basic_controller_model_Control_Engineering_T *const
  Basic_controller_model_Control_Engineering_M =
  &Basic_controller_model_Control_Engineering_M_;

/* Forward declaration for local functions */
static void Basic_controller_emxInit_char_T(emxArray_char_T_Basic_control_T
  **pEmxArray, int32_T numDimensions);
static void Basic__emxEnsureCapacity_char_T(emxArray_char_T_Basic_control_T
  *emxArray, int32_T oldNumel);
static void Basic_controller_emxFree_char_T(emxArray_char_T_Basic_control_T
  **pEmxArray);
static int8_T Basic_controller_model_filedata(void);
static int8_T Basic_controller_model_C_cfopen(const
  emxArray_char_T_Basic_control_T *cfilename, const char_T *cpermission);
static int32_T Basic_controller_model__cfclose(real_T fid);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Basic_controller_model_Control_Engineering_SetEventsForThisBaseStep
  (boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask
                   (Basic_controller_model_Control_Engineering_M, 2));
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
  if (Basic_controller_model_Control_Engineering_M->Timing.TaskCounters.TID[1] ==
      0) {
    Basic_controller_model_Control_Engineering_M->Timing.RateInteraction.TID1_2 =
      (Basic_controller_model_Control_Engineering_M->Timing.TaskCounters.TID[2] ==
       0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Basic_controller_model_Control_Engineering_M->Timing.perTaskSampleHits[5] =
      Basic_controller_model_Control_Engineering_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Basic_controller_model_Control_Engineering_M->Timing.TaskCounters.TID[2])++;
  if ((Basic_controller_model_Control_Engineering_M->Timing.TaskCounters.TID[2])
      > 7) {                           /* Sample time: [0.002s, 0.0s] */
    Basic_controller_model_Control_Engineering_M->Timing.TaskCounters.TID[2] = 0;
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

static void Basic_controller_emxInit_char_T(emxArray_char_T_Basic_control_T
  **pEmxArray, int32_T numDimensions)
{
  emxArray_char_T_Basic_control_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T_Basic_control_T *)malloc(sizeof
    (emxArray_char_T_Basic_control_T));
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

static void Basic__emxEnsureCapacity_char_T(emxArray_char_T_Basic_control_T
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

static void Basic_controller_emxFree_char_T(emxArray_char_T_Basic_control_T
  **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T_Basic_control_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      free((*pEmxArray)->data);
    }

    free((*pEmxArray)->size);
    free(*pEmxArray);
    *pEmxArray = (emxArray_char_T_Basic_control_T *)NULL;
  }
}

/* Function for MATLAB Function: '<S3>/SPERTE_measurement_function' */
static int8_T Basic_controller_model_filedata(void)
{
  int32_T k;
  int8_T f;
  boolean_T exitg1;
  f = 0;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k - 1 < 20)) {
    if (Basic_controller_model_Control_Engineering_DW.eml_openfiles[(int8_T)k -
        1] == NULL) {
      f = (int8_T)k;
      exitg1 = true;
    } else {
      k++;
    }
  }

  return f;
}

/* Function for MATLAB Function: '<S3>/SPERTE_measurement_function' */
static int8_T Basic_controller_model_C_cfopen(const
  emxArray_char_T_Basic_control_T *cfilename, const char_T *cpermission)
{
  FILE *filestar;
  emxArray_char_T_Basic_control_T *ccfilename;
  int32_T loop_ub;
  int8_T fileid;
  int8_T j;
  fileid = -1;
  j = Basic_controller_model_filedata();
  if (j >= 1) {
    Basic_controller_emxInit_char_T(&ccfilename, 2);
    loop_ub = ccfilename->size[0] * ccfilename->size[1];
    ccfilename->size[0] = 1;
    ccfilename->size[1] = cfilename->size[1] + 1;
    Basic__emxEnsureCapacity_char_T(ccfilename, loop_ub);
    loop_ub = cfilename->size[1];
    if (loop_ub - 1 >= 0) {
      memcpy(&ccfilename->data[0], &cfilename->data[0], (uint32_T)loop_ub *
             sizeof(char_T));
    }

    ccfilename->data[cfilename->size[1]] = '\x00';
    filestar = fopen(&ccfilename->data[0], cpermission);
    Basic_controller_emxFree_char_T(&ccfilename);
    if (filestar != NULL) {
      Basic_controller_model_Control_Engineering_DW.eml_openfiles[j - 1] =
        filestar;
      Basic_controller_model_Control_Engineering_DW.eml_autoflush[j - 1] = true;
      loop_ub = j + 2;
      if (j + 2 > 127) {
        loop_ub = 127;
      }

      fileid = (int8_T)loop_ub;
    }
  }

  return fileid;
}

/* Function for MATLAB Function: '<S3>/SPERTE_measurement_function' */
static int32_T Basic_controller_model__cfclose(real_T fid)
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
    f = Basic_controller_model_Control_Engineering_DW.eml_openfiles[b_fileid - 3];
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
      Basic_controller_model_Control_Engineering_DW.eml_openfiles[fileid - 3] =
        NULL;
      Basic_controller_model_Control_Engineering_DW.eml_autoflush[fileid - 3] =
        true;
    }
  }

  return st;
}

/* Model step function for TID0 */
void Basic_controller_model_Control_Engineering_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  FILE *f;
  emxArray_char_T_Basic_control_T *str;
  emxArray_char_T_Basic_control_T *str_0;
  int8_T b_fileid;
  boolean_T autoflush;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Constant: '<S5>/Start setpoint' */
  Basic_controller_model_Control_Engineering_B.Startsetpoint =
    Basic_controller_model_Control_Engineering_P.Refpower_stat;

  /* S-Function (ref3b): '<S6>/S-Function' */

  /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Supervisor): '<S8>/S-Function' */

  /* Level2 S-Function Block: '<S8>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }

  /* S-Function (ec_Ebox): '<S7>/ec_Ebox' */

  /* Level2 S-Function Block: '<S7>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[2];
    sfcnOutputs(rts,0);
  }

  /* Quantizer: '<Root>/Quantizer1' */
  Basic_controller_model_Control_Engineering_B.Input = rt_roundd_snf
    (Basic_controller_model_Control_Engineering_B.SFunction[2] /
     Basic_controller_model_Control_Engineering_P.Quantizer1_Interval) *
    Basic_controller_model_Control_Engineering_P.Quantizer1_Interval;

  /* ManualSwitch: '<Root>/Select encoder' incorporates:
   *  Gain: '<S2>/count2rad'
   */
  if (Basic_controller_model_Control_Engineering_P.Selectencoder_CurrentSetting ==
      1) {
    Basic_controller_model_Control_Engineering_B.Error =
      Basic_controller_model_Control_Engineering_P.count2rad_Gain *
      Basic_controller_model_Control_Engineering_B.ec_Ebox_o2[0];
  } else {
    Basic_controller_model_Control_Engineering_B.Error =
      Basic_controller_model_Control_Engineering_P.count2rad_Gain *
      Basic_controller_model_Control_Engineering_B.ec_Ebox_o2[1];
  }

  /* Gain: '<Root>/Gain' incorporates:
   *  ManualSwitch: '<Root>/Select encoder'
   */
  Basic_controller_model_Control_Engineering_B.Output =
    Basic_controller_model_Control_Engineering_P.Gain_Gain *
    Basic_controller_model_Control_Engineering_B.Error;

  /* Sum: '<Root>/Sum' */
  Basic_controller_model_Control_Engineering_B.Error =
    Basic_controller_model_Control_Engineering_B.Input -
    Basic_controller_model_Control_Engineering_B.Output;

  /* MATLAB Function: '<S3>/SPERTE_measurement_function' incorporates:
   *  Constant: '<S3>/SPERTE_measurement_samples'
   *  Constant: '<S3>/SPERTE_measurement_trigger_command'
   *  SignalConversion generated from: '<S9>/ SFunction '
   */
  Basic_controller_model_Control_Engineering_DW.sfEvent =
    Basic_controller_mod_CALL_EVENT;
  if ((((Basic_controller_model_Control_Engineering_P.MeasurementBlock_triggertype
         == 1) &&
        (Basic_controller_model_Control_Engineering_P.MeasurementBlock_trigger_comman
         == 1)) ||
       ((Basic_controller_model_Control_Engineering_P.MeasurementBlock_triggertype
         == 2) &&
        (Basic_controller_model_Control_Engineering_P.MeasurementBlock_trigger_comman
         == 1))) && (Basic_controller_model_Control_Engineering_DW.busy != 1)) {
    Basic_controller_model_Control_Engineering_B.nbytes = (int32_T)snprintf(NULL,
      0, "measurement_%d.bin", Basic_controller_model_Control_Engineering_DW.NF)
      + 1;
    Basic_controller_emxInit_char_T(&str, 2);
    Basic_controller_model_Control_Engineering_B.i = str->size[0] * str->size[1];
    str->size[0] = 1;
    str->size[1] = Basic_controller_model_Control_Engineering_B.nbytes;
    Basic__emxEnsureCapacity_char_T(str,
      Basic_controller_model_Control_Engineering_B.i);
    snprintf(&str->data[0], (size_t)
             Basic_controller_model_Control_Engineering_B.nbytes,
             "measurement_%d.bin",
             Basic_controller_model_Control_Engineering_DW.NF);
    if (Basic_controller_model_Control_Engineering_B.nbytes - 1 < 1) {
      Basic_controller_model_Control_Engineering_B.nbytes = -1;
    } else {
      Basic_controller_model_Control_Engineering_B.nbytes -= 2;
    }

    Basic_controller_emxInit_char_T(&str_0, 2);
    Basic_controller_model_Control_Engineering_B.i = str_0->size[0] *
      str_0->size[1];
    str_0->size[0] = 1;
    str_0->size[1] = Basic_controller_model_Control_Engineering_B.nbytes + 1;
    Basic__emxEnsureCapacity_char_T(str_0,
      Basic_controller_model_Control_Engineering_B.i);
    if (Basic_controller_model_Control_Engineering_B.nbytes >= 0) {
      memcpy(&str_0->data[0], &str->data[0], (uint32_T)
             (Basic_controller_model_Control_Engineering_B.nbytes + 1) * sizeof
             (char_T));
    }

    Basic_controller_emxFree_char_T(&str);
    b_fileid = Basic_controller_model_C_cfopen(str_0, "wb");
    Basic_controller_emxFree_char_T(&str_0);
    Basic_controller_model_Control_Engineering_DW.fileID = b_fileid;
    Basic_controller_model_Control_Engineering_B.nbytes =
      Basic_controller_model_Control_Engineering_DW.NF + 1;
    if (Basic_controller_model_Control_Engineering_DW.NF + 1 > 32767) {
      Basic_controller_model_Control_Engineering_B.nbytes = 32767;
    }

    Basic_controller_model_Control_Engineering_DW.NF = (int16_T)
      Basic_controller_model_Control_Engineering_B.nbytes;
    Basic_controller_model_Control_Engineering_DW.busy = 1U;
    Basic_controller_model_Control_Engineering_DW.NS = 0U;
  }

  if (Basic_controller_model_Control_Engineering_DW.busy == 1) {
    if (Basic_controller_model_Control_Engineering_DW.NS <
        Basic_controller_model_Control_Engineering_P.MeasurementBlock_N_samples)
    {
      b_fileid = (int8_T)Basic_controller_model_Control_Engineering_DW.fileID;
      if (((int8_T)Basic_controller_model_Control_Engineering_DW.fileID < 0) ||
          (Basic_controller_model_Control_Engineering_DW.fileID != (int8_T)
           Basic_controller_model_Control_Engineering_DW.fileID)) {
        b_fileid = -1;
      }

      if (b_fileid >= 3) {
        autoflush =
          Basic_controller_model_Control_Engineering_DW.eml_autoflush[b_fileid -
          3];
        f = Basic_controller_model_Control_Engineering_DW.eml_openfiles[b_fileid
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

      if (!(Basic_controller_model_Control_Engineering_DW.fileID != 0.0)) {
        f = NULL;
      }

      if (!(f == NULL)) {
        Basic_controller_model_Control_Engineering_B.xout[0] = (real32_T)
          Basic_controller_model_Control_Engineering_B.Input;
        Basic_controller_model_Control_Engineering_B.xout[1] = (real32_T)
          Basic_controller_model_Control_Engineering_B.Output;
        Basic_controller_model_Control_Engineering_B.xout[2] = (real32_T)
          Basic_controller_model_Control_Engineering_B.Error;
        Basic_controller_model_Control_Engineering_B.bytesOutSizet = fwrite
          (&Basic_controller_model_Control_Engineering_B.xout[0], sizeof
           (real32_T), (size_t)3, f);
        if (((real_T)Basic_controller_model_Control_Engineering_B.bytesOutSizet >
             0.0) && autoflush) {
          fflush(f);
        }
      }

      Basic_controller_model_Control_Engineering_B.qY =
        Basic_controller_model_Control_Engineering_DW.NS + 1U;
      if (Basic_controller_model_Control_Engineering_DW.NS + 1U <
          Basic_controller_model_Control_Engineering_DW.NS) {
        Basic_controller_model_Control_Engineering_B.qY = MAX_uint32_T;
      }

      Basic_controller_model_Control_Engineering_DW.NS =
        Basic_controller_model_Control_Engineering_B.qY;
    } else {
      Basic_controller_model__cfclose
        (Basic_controller_model_Control_Engineering_DW.fileID);
      Basic_controller_model_Control_Engineering_DW.busy = 0U;
      Basic_controller_model_Control_Engineering_DW.NS = 0U;
    }
  }

  /* End of MATLAB Function: '<S3>/SPERTE_measurement_function' */

  /* SignalConversion: '<S4>/Buffer' */
  Basic_controller_model_Control_Engineering_B.Buffer[0] =
    Basic_controller_model_Control_Engineering_B.Input;
  Basic_controller_model_Control_Engineering_B.Buffer[1] =
    Basic_controller_model_Control_Engineering_B.Output;
  Basic_controller_model_Control_Engineering_B.Buffer[2] =
    Basic_controller_model_Control_Engineering_B.Error;

  /* RateTransition: '<S4>/Downsample' */
  if (Basic_controller_model_Control_Engineering_M->Timing.RateInteraction.TID1_2)
  {
    Basic_controller_model_Control_Engineering_DW.Downsample_Buffer[0] =
      Basic_controller_model_Control_Engineering_B.Buffer[0];
    Basic_controller_model_Control_Engineering_DW.Downsample_Buffer[1] =
      Basic_controller_model_Control_Engineering_B.Buffer[1];
    Basic_controller_model_Control_Engineering_DW.Downsample_Buffer[2] =
      Basic_controller_model_Control_Engineering_B.Buffer[2];
  }

  /* End of RateTransition: '<S4>/Downsample' */

  /* Gain: '<S1>/Gain1' */
  Basic_controller_model_Control_Engineering_B.Gain1 =
    Basic_controller_model_Control_Engineering_P.Gain1_Gain *
    Basic_controller_model_Control_Engineering_B.Error;

  /* S-Function (dleadlag): '<S1>/Dctleadlag2' */

  /* Level2 S-Function Block: '<S1>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[3];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dweakint): '<S1>/Dctintegrator3' */

  /* Level2 S-Function Block: '<S1>/Dctintegrator3' (dweakint) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[4];
    sfcnOutputs(rts,0);
  }

  /* S-Function (dnotch): '<S1>/Dctnotch4' */

  /* Level2 S-Function Block: '<S1>/Dctnotch4' (dnotch) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[5];
    sfcnOutputs(rts,0);
  }

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  if (Basic_controller_model_Control_Engineering_B.Dctnotch4 >
      Basic_controller_model_Control_Engineering_P.Saturation_UpperSat) {
    Basic_controller_model_Control_Engineering_B.Input =
      Basic_controller_model_Control_Engineering_P.Saturation_UpperSat;
  } else if (Basic_controller_model_Control_Engineering_B.Dctnotch4 <
             Basic_controller_model_Control_Engineering_P.Saturation_LowerSat) {
    Basic_controller_model_Control_Engineering_B.Input =
      Basic_controller_model_Control_Engineering_P.Saturation_LowerSat;
  } else {
    Basic_controller_model_Control_Engineering_B.Input =
      Basic_controller_model_Control_Engineering_B.Dctnotch4;
  }

  /* Saturate: '<S7>/Saturation' */
  if (Basic_controller_model_Control_Engineering_B.Input >
      Basic_controller_model_Control_Engineering_P.Saturation_UpperSat_d) {
    /* Saturate: '<S7>/Saturation' */
    Basic_controller_model_Control_Engineering_B.Saturation[0] =
      Basic_controller_model_Control_Engineering_P.Saturation_UpperSat_d;
  } else if (Basic_controller_model_Control_Engineering_B.Input <
             Basic_controller_model_Control_Engineering_P.Saturation_LowerSat_e)
  {
    /* Saturate: '<S7>/Saturation' */
    Basic_controller_model_Control_Engineering_B.Saturation[0] =
      Basic_controller_model_Control_Engineering_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S7>/Saturation' */
    Basic_controller_model_Control_Engineering_B.Saturation[0] =
      Basic_controller_model_Control_Engineering_B.Input;
  }

  /* Saturate: '<S2>/Saturation' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  if (Basic_controller_model_Control_Engineering_P.Constant2_Value >
      Basic_controller_model_Control_Engineering_P.Saturation_UpperSat) {
    Basic_controller_model_Control_Engineering_B.Input =
      Basic_controller_model_Control_Engineering_P.Saturation_UpperSat;
  } else if (Basic_controller_model_Control_Engineering_P.Constant2_Value <
             Basic_controller_model_Control_Engineering_P.Saturation_LowerSat) {
    Basic_controller_model_Control_Engineering_B.Input =
      Basic_controller_model_Control_Engineering_P.Saturation_LowerSat;
  } else {
    Basic_controller_model_Control_Engineering_B.Input =
      Basic_controller_model_Control_Engineering_P.Constant2_Value;
  }

  /* Saturate: '<S7>/Saturation' */
  if (Basic_controller_model_Control_Engineering_B.Input >
      Basic_controller_model_Control_Engineering_P.Saturation_UpperSat_d) {
    /* Saturate: '<S7>/Saturation' */
    Basic_controller_model_Control_Engineering_B.Saturation[1] =
      Basic_controller_model_Control_Engineering_P.Saturation_UpperSat_d;
  } else if (Basic_controller_model_Control_Engineering_B.Input <
             Basic_controller_model_Control_Engineering_P.Saturation_LowerSat_e)
  {
    /* Saturate: '<S7>/Saturation' */
    Basic_controller_model_Control_Engineering_B.Saturation[1] =
      Basic_controller_model_Control_Engineering_P.Saturation_LowerSat_e;
  } else {
    /* Saturate: '<S7>/Saturation' */
    Basic_controller_model_Control_Engineering_B.Saturation[1] =
      Basic_controller_model_Control_Engineering_B.Input;
  }

  /* Constant: '<S2>/Constant1' */
  memcpy(&Basic_controller_model_Control_Engineering_B.Constant1[0],
         &Basic_controller_model_Control_Engineering_P.Constant1_Value[0],
         sizeof(real_T) << 3U);

  /* Gain: '<S7>/Gain' incorporates:
   *  Constant: '<S2>/Constant'
   */
  Basic_controller_model_Control_Engineering_B.Gain[0] =
    Basic_controller_model_Control_Engineering_P.Gain_Gain_g *
    Basic_controller_model_Control_Engineering_P.Constant_Value[0];
  Basic_controller_model_Control_Engineering_B.Gain[1] =
    Basic_controller_model_Control_Engineering_P.Gain_Gain_g *
    Basic_controller_model_Control_Engineering_P.Constant_Value[1];

  /* External mode */
  rtExtModeUploadCheckTrigger(3);
  rtExtModeUpload(1, (real_T)
                  Basic_controller_model_Control_Engineering_M->Timing.t[0]);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(Basic_controller_model_Control_Engineering_M)!=-1) &&
        !((rtmGetTFinal(Basic_controller_model_Control_Engineering_M)-
           Basic_controller_model_Control_Engineering_M->Timing.t[0]) >
          Basic_controller_model_Control_Engineering_M->Timing.t[0] *
          (DBL_EPSILON))) {
      rtmSetErrorStatus(Basic_controller_model_Control_Engineering_M,
                        "Simulation finished");
    }

    if (rtmGetStopRequested(Basic_controller_model_Control_Engineering_M)) {
      rtmSetErrorStatus(Basic_controller_model_Control_Engineering_M,
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
  if (!(++Basic_controller_model_Control_Engineering_M->Timing.clockTick0)) {
    ++Basic_controller_model_Control_Engineering_M->Timing.clockTickH0;
  }

  Basic_controller_model_Control_Engineering_M->Timing.t[0] =
    Basic_controller_model_Control_Engineering_M->Timing.clockTick0 *
    Basic_controller_model_Control_Engineering_M->Timing.stepSize0 +
    Basic_controller_model_Control_Engineering_M->Timing.clockTickH0 *
    Basic_controller_model_Control_Engineering_M->Timing.stepSize0 *
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
  if (!(++Basic_controller_model_Control_Engineering_M->Timing.clockTick1)) {
    ++Basic_controller_model_Control_Engineering_M->Timing.clockTickH1;
  }

  Basic_controller_model_Control_Engineering_M->Timing.t[1] =
    Basic_controller_model_Control_Engineering_M->Timing.clockTick1 *
    Basic_controller_model_Control_Engineering_M->Timing.stepSize1 +
    Basic_controller_model_Control_Engineering_M->Timing.clockTickH1 *
    Basic_controller_model_Control_Engineering_M->Timing.stepSize1 *
    4294967296.0;
}

/* Model step function for TID2 */
void Basic_controller_model_Control_Engineering_step2(void) /* Sample time: [0.002s, 0.0s] */
{
  /* RateTransition: '<S4>/Downsample' */
  Basic_controller_model_Control_Engineering_B.Downsample[0] =
    Basic_controller_model_Control_Engineering_DW.Downsample_Buffer[0];
  Basic_controller_model_Control_Engineering_B.Downsample[1] =
    Basic_controller_model_Control_Engineering_DW.Downsample_Buffer[1];
  Basic_controller_model_Control_Engineering_B.Downsample[2] =
    Basic_controller_model_Control_Engineering_DW.Downsample_Buffer[2];
  rtExtModeUpload(2, (real_T)
                  (((Basic_controller_model_Control_Engineering_M->Timing.clockTick2
                     +Basic_controller_model_Control_Engineering_M->Timing.clockTickH2*
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
  Basic_controller_model_Control_Engineering_M->Timing.clockTick2++;
  if (!Basic_controller_model_Control_Engineering_M->Timing.clockTick2) {
    Basic_controller_model_Control_Engineering_M->Timing.clockTickH2++;
  }
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Basic_controller_model_Control_Engineering_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Basic_controller_model_Control_Engineering_step0();
    break;

   case 2 :
    Basic_controller_model_Control_Engineering_step2();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Basic_controller_model_Control_Engineering_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Basic_controller_model_Control_Engineering_M, 0,
                sizeof(RT_MODEL_Basic_controller_model_Control_Engineering_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr
      (&Basic_controller_model_Control_Engineering_M->solverInfo,
       &Basic_controller_model_Control_Engineering_M->Timing.simTimeStep);
    rtsiSetTPtr(&Basic_controller_model_Control_Engineering_M->solverInfo,
                &rtmGetTPtr(Basic_controller_model_Control_Engineering_M));
    rtsiSetStepSizePtr(&Basic_controller_model_Control_Engineering_M->solverInfo,
                       &Basic_controller_model_Control_Engineering_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr
      (&Basic_controller_model_Control_Engineering_M->solverInfo,
       (&rtmGetErrorStatus(Basic_controller_model_Control_Engineering_M)));
    rtsiSetRTModelPtr(&Basic_controller_model_Control_Engineering_M->solverInfo,
                      Basic_controller_model_Control_Engineering_M);
  }

  rtsiSetSimTimeStep(&Basic_controller_model_Control_Engineering_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&Basic_controller_model_Control_Engineering_M->solverInfo,
                    "FixedStepDiscrete");
  Basic_controller_model_Control_Engineering_M->solverInfoPtr =
    (&Basic_controller_model_Control_Engineering_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      Basic_controller_model_Control_Engineering_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "Basic_controller_model_Control_Engineering_M points to
       static memory which is guaranteed to be non-NULL" */
    Basic_controller_model_Control_Engineering_M->Timing.sampleTimeTaskIDPtr = (
      &mdlTsMap[0]);
    Basic_controller_model_Control_Engineering_M->Timing.sampleTimes =
      (&Basic_controller_model_Control_Engineering_M->Timing.sampleTimesArray[0]);
    Basic_controller_model_Control_Engineering_M->Timing.offsetTimes =
      (&Basic_controller_model_Control_Engineering_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Basic_controller_model_Control_Engineering_M->Timing.sampleTimes[0] = (0.0);
    Basic_controller_model_Control_Engineering_M->Timing.sampleTimes[1] =
      (0.00025);
    Basic_controller_model_Control_Engineering_M->Timing.sampleTimes[2] = (0.002);

    /* task offsets */
    Basic_controller_model_Control_Engineering_M->Timing.offsetTimes[0] = (0.0);
    Basic_controller_model_Control_Engineering_M->Timing.offsetTimes[1] = (0.0);
    Basic_controller_model_Control_Engineering_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Basic_controller_model_Control_Engineering_M,
             &Basic_controller_model_Control_Engineering_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      Basic_controller_model_Control_Engineering_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Basic_controller_model_Control_Engineering_M->Timing.perTaskSampleHitsArray;
    Basic_controller_model_Control_Engineering_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Basic_controller_model_Control_Engineering_M->Timing.sampleHits =
      (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Basic_controller_model_Control_Engineering_M, -1);
  Basic_controller_model_Control_Engineering_M->Timing.stepSize0 = 0.00025;
  Basic_controller_model_Control_Engineering_M->Timing.stepSize1 = 0.00025;

  /* External mode info */
  Basic_controller_model_Control_Engineering_M->Sizes.checksums[0] = (642678769U);
  Basic_controller_model_Control_Engineering_M->Sizes.checksums[1] =
    (1884691429U);
  Basic_controller_model_Control_Engineering_M->Sizes.checksums[2] =
    (3006653366U);
  Basic_controller_model_Control_Engineering_M->Sizes.checksums[3] =
    (1298444517U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    Basic_controller_model_Control_Engineering_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr
      (Basic_controller_model_Control_Engineering_M->extModeInfo,
       &Basic_controller_model_Control_Engineering_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr
      (Basic_controller_model_Control_Engineering_M->extModeInfo,
       Basic_controller_model_Control_Engineering_M->Sizes.checksums);
    rteiSetTPtr(Basic_controller_model_Control_Engineering_M->extModeInfo,
                rtmGetTPtr(Basic_controller_model_Control_Engineering_M));
  }

  Basic_controller_model_Control_Engineering_M->solverInfoPtr =
    (&Basic_controller_model_Control_Engineering_M->solverInfo);
  Basic_controller_model_Control_Engineering_M->Timing.stepSize = (0.00025);
  rtsiSetFixedStepSize(&Basic_controller_model_Control_Engineering_M->solverInfo,
                       0.00025);
  rtsiSetSolverMode(&Basic_controller_model_Control_Engineering_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  (void) memset(((void *) &Basic_controller_model_Control_Engineering_B), 0,
                sizeof(B_Basic_controller_model_Control_Engineering_T));

  /* states (dwork) */
  (void) memset((void *)&Basic_controller_model_Control_Engineering_DW, 0,
                sizeof(DW_Basic_controller_model_Control_Engineering_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Basic_controller_model_Control_Engineering_M->SpecialInfo.mappingInfo =
      (&dtInfo);
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
      &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.sfcnInfo;
    Basic_controller_model_Control_Engineering_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (Basic_controller_model_Control_Engineering_M)));
    Basic_controller_model_Control_Engineering_M->Sizes.numSampTimes = (3);
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &Basic_controller_model_Control_Engineering_M->Sizes.numSampTimes);
    Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs[0]
      = (&rtmGetTPtr(Basic_controller_model_Control_Engineering_M)[0]);
    Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs[1]
      = (&rtmGetTPtr(Basic_controller_model_Control_Engineering_M)[1]);
    Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs[2]
      = (&rtmGetTPtr(Basic_controller_model_Control_Engineering_M)[2]);
    rtssSetTPtrPtr(sfcnInfo,
                   Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart
                     (Basic_controller_model_Control_Engineering_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal
                     (Basic_controller_model_Control_Engineering_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (Basic_controller_model_Control_Engineering_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &Basic_controller_model_Control_Engineering_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (Basic_controller_model_Control_Engineering_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &Basic_controller_model_Control_Engineering_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &Basic_controller_model_Control_Engineering_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &Basic_controller_model_Control_Engineering_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &Basic_controller_model_Control_Engineering_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &Basic_controller_model_Control_Engineering_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo,
                      &Basic_controller_model_Control_Engineering_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &Basic_controller_model_Control_Engineering_M->solverInfoPtr);
  }

  Basic_controller_model_Control_Engineering_M->Sizes.numSFcns = (6);

  /* register each child */
  {
    (void) memset((void *)
                  &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  6*sizeof(SimStruct));
    Basic_controller_model_Control_Engineering_M->childSfunctions =
      (&Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.childSFunctionPtrs
       [0]);

    {
      int_T i;
      for (i = 0; i < 6; i++) {
        Basic_controller_model_Control_Engineering_M->childSfunctions[i] =
          (&Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.childSFunctions
           [i]);
      }
    }

    /* Level2 S-Function Block: Basic_controller_model_Control_Engineering/<S6>/S-Function (ref3b) */
    {
      SimStruct *rts =
        Basic_controller_model_Control_Engineering_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Basic_controller_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] =
            &Basic_controller_model_Control_Engineering_B.Startsetpoint;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 3);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Basic_controller_model_Control_Engineering_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "Basic_controller_model_Control_Engineering/Subsystem/S-Function");
      ssSetRTModel(rts,Basic_controller_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.SFunction_P1_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Basic_controller_model_Control_Engineering_DW.SFunction_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 50);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Basic_controller_model_Control_Engineering_DW.SFunction_RWORK
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

    /* Level2 S-Function Block: Basic_controller_model_Control_Engineering/<S8>/S-Function (ec_Supervisor) */
    {
      SimStruct *rts =
        Basic_controller_model_Control_Engineering_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Basic_controller_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Basic_controller_model_Control_Engineering_B.SFunction_b));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "Basic_controller_model_Control_Engineering/Fourth Order Motion System/Ethercat Supervisor/S-Function");
      ssSetRTModel(rts,Basic_controller_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.SFunction_P1_Size_k);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.SFunction_P2_Size);
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

    /* Level2 S-Function Block: Basic_controller_model_Control_Engineering/<S7>/ec_Ebox (ec_Ebox) */
    {
      SimStruct *rts =
        Basic_controller_model_Control_Engineering_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Basic_controller_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);
        ssSetInputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);
        ssSetInputPortIsContinuousQuantity(rts, 1, 0);
        ssSetInputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = Basic_controller_model_Control_Engineering_B.Saturation;
          sfcnUPtrs[1] =
            &Basic_controller_model_Control_Engineering_B.Saturation[1];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 2);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = Basic_controller_model_Control_Engineering_B.Gain;
          sfcnUPtrs[1] = &Basic_controller_model_Control_Engineering_B.Gain[1];
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidthAsInt(rts, 1, 2);
        }

        /* port 2 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.UPtrs2;

          {
            int_T i1;
            const real_T *u2 =
              Basic_controller_model_Control_Engineering_B.Constant1;
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
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 3);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        ssSetOutputPortUnit(rts, 1, 0);
        ssSetOutputPortUnit(rts, 2, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 1, 0);
        ssSetOutputPortIsContinuousQuantity(rts, 2, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 2);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            Basic_controller_model_Control_Engineering_B.ec_Ebox_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidthAsInt(rts, 1, 2);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            Basic_controller_model_Control_Engineering_B.ec_Ebox_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidthAsInt(rts, 2, 8);
          ssSetOutputPortSignal(rts, 2, ((real_T *)
            Basic_controller_model_Control_Engineering_B.ec_Ebox_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "ec_Ebox");
      ssSetPath(rts,
                "Basic_controller_model_Control_Engineering/Fourth Order Motion System/Ethercat E-box/ec_Ebox");
      ssSetRTModel(rts,Basic_controller_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.ec_Ebox_P1_Size);
      }

      /* registration */
      ec_Ebox(rts);
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

    /* Level2 S-Function Block: Basic_controller_model_Control_Engineering/<S1>/Dctleadlag2 (dleadlag) */
    {
      SimStruct *rts =
        Basic_controller_model_Control_Engineering_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [3]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [3]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Basic_controller_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [3]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [3]);
        ssSetPeriodicStatesInfo(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.UPtrs0;
          sfcnUPtrs[0] = &Basic_controller_model_Control_Engineering_B.Gain1;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Basic_controller_model_Control_Engineering_B.Dctleadlag2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctleadlag2");
      ssSetPath(rts,
                "Basic_controller_model_Control_Engineering/Basic_controller_block/Dctleadlag2");
      ssSetRTModel(rts,Basic_controller_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.Dctleadlag2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.Dctleadlag2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.Dctleadlag2_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Basic_controller_model_Control_Engineering_DW.Dctleadlag2_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Basic_controller_model_Control_Engineering_DW.Dctleadlag2_RWORK
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

    /* Level2 S-Function Block: Basic_controller_model_Control_Engineering/<S1>/Dctintegrator3 (dweakint) */
    {
      SimStruct *rts =
        Basic_controller_model_Control_Engineering_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [4]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [4]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Basic_controller_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [4]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [4]);
        ssSetPeriodicStatesInfo(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [4]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.UPtrs0;
          sfcnUPtrs[0] =
            &Basic_controller_model_Control_Engineering_B.Dctleadlag2;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Basic_controller_model_Control_Engineering_B.Dctintegrator3));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctintegrator3");
      ssSetPath(rts,
                "Basic_controller_model_Control_Engineering/Basic_controller_block/Dctintegrator3");
      ssSetRTModel(rts,Basic_controller_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 2);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.Dctintegrator3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.Dctintegrator3_P2_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Basic_controller_model_Control_Engineering_DW.Dctintegrator3_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Basic_controller_model_Control_Engineering_DW.Dctintegrator3_RWORK
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

    /* Level2 S-Function Block: Basic_controller_model_Control_Engineering/<S1>/Dctnotch4 (dnotch) */
    {
      SimStruct *rts =
        Basic_controller_model_Control_Engineering_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap =
        Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.blkInfo2
                         [5]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.inputOutputPortInfo2
        [5]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts,
                       Basic_controller_model_Control_Engineering_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods2
                           [5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods3
                           [5]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.methods4
                           [5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.statesInfo2
                         [5]);
        ssSetPeriodicStatesInfo(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.periodicStatesInfo
          [5]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortInfo
          [0]);
        ssSetPortInfoForInputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForInputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.inputPortCoSimAttribute
          [0]);
        ssSetInputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.UPtrs0;
          sfcnUPtrs[0] =
            &Basic_controller_model_Control_Engineering_B.Dctintegrator3;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidthAsInt(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.outputPortInfo
          [0]);
        ssSetPortInfoForOutputs(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);
        _ssSetPortInfo2ForOutputCoSimAttribute(rts,
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.outputPortCoSimAttribute
          [0]);
        ssSetOutputPortIsContinuousQuantity(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidthAsInt(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &Basic_controller_model_Control_Engineering_B.Dctnotch4));
        }
      }

      /* path info */
      ssSetModelName(rts, "Dctnotch4");
      ssSetPath(rts,
                "Basic_controller_model_Control_Engineering/Basic_controller_block/Dctnotch4");
      ssSetRTModel(rts,Basic_controller_model_Control_Engineering_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.Dctnotch4_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.Dctnotch4_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.Dctnotch4_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.Dctnotch4_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       Basic_controller_model_Control_Engineering_P.Dctnotch4_P5_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &Basic_controller_model_Control_Engineering_DW.Dctnotch4_RWORK
                 [0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &Basic_controller_model_Control_Engineering_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        ssSetNumDWorkAsInt(rts, 1);

        /* RWORK */
        ssSetDWorkWidthAsInt(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &Basic_controller_model_Control_Engineering_DW.Dctnotch4_RWORK
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
  }

  /* Start for Constant: '<S5>/Start setpoint' */
  Basic_controller_model_Control_Engineering_B.Startsetpoint =
    Basic_controller_model_Control_Engineering_P.Refpower_stat;

  /* Start for S-Function (ec_Supervisor): '<S8>/S-Function' */
  /* Level2 S-Function Block: '<S8>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dleadlag): '<S1>/Dctleadlag2' */
  /* Level2 S-Function Block: '<S1>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dweakint): '<S1>/Dctintegrator3' */
  /* Level2 S-Function Block: '<S1>/Dctintegrator3' (dweakint) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (dnotch): '<S1>/Dctnotch4' */
  /* Level2 S-Function Block: '<S1>/Dctnotch4' (dnotch) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S2>/Constant1' */
  memcpy(&Basic_controller_model_Control_Engineering_B.Constant1[0],
         &Basic_controller_model_Control_Engineering_P.Constant1_Value[0],
         sizeof(real_T) << 3U);

  {
    int32_T i;

    /* InitializeConditions for S-Function (ref3b): '<S6>/S-Function' */
    /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
    {
      SimStruct *rts =
        Basic_controller_model_Control_Engineering_M->childSfunctions[0];
      sfcnInitializeConditions(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* SystemInitialize for MATLAB Function: '<S3>/SPERTE_measurement_function' */
    for (i = 0; i < 20; i++) {
      Basic_controller_model_Control_Engineering_DW.eml_autoflush[i] = false;
    }

    Basic_controller_model_Control_Engineering_DW.eml_autoflush_not_empty = true;
    for (i = 0; i < 20; i++) {
      Basic_controller_model_Control_Engineering_DW.eml_openfiles[i] = NULL;
    }

    Basic_controller_model_Control_Engineering_DW.eml_openfiles_not_empty = true;
    Basic_controller_model_Control_Engineering_DW.NF = 0;
    Basic_controller_model_Control_Engineering_DW.NF_not_empty = true;
    Basic_controller_model_Control_Engineering_DW.NS = 0U;
    Basic_controller_model_Control_Engineering_DW.NS_not_empty = true;
    Basic_controller_model_Control_Engineering_DW.fileID = 0.0;
    Basic_controller_model_Control_Engineering_DW.fileID_not_empty = true;
    Basic_controller_model_Control_Engineering_DW.busy = 0U;
    Basic_controller_model_Control_Engineering_DW.busy_not_empty = true;
    Basic_controller_model_Control_Engineering_DW.doneDoubleBufferReInit = false;
    Basic_controller_model_Control_Engineering_DW.sfEvent =
      Basic_controller_mod_CALL_EVENT;

    /* End of SystemInitialize for MATLAB Function: '<S3>/SPERTE_measurement_function' */
  }
}

/* Model terminate function */
void Basic_controller_model_Control_Engineering_terminate(void)
{
  /* Terminate for S-Function (ref3b): '<S6>/S-Function' */
  /* Level2 S-Function Block: '<S6>/S-Function' (ref3b) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Supervisor): '<S8>/S-Function' */
  /* Level2 S-Function Block: '<S8>/S-Function' (ec_Supervisor) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (ec_Ebox): '<S7>/ec_Ebox' */
  /* Level2 S-Function Block: '<S7>/ec_Ebox' (ec_Ebox) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dleadlag): '<S1>/Dctleadlag2' */
  /* Level2 S-Function Block: '<S1>/Dctleadlag2' (dleadlag) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[3];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dweakint): '<S1>/Dctintegrator3' */
  /* Level2 S-Function Block: '<S1>/Dctintegrator3' (dweakint) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (dnotch): '<S1>/Dctnotch4' */
  /* Level2 S-Function Block: '<S1>/Dctnotch4' (dnotch) */
  {
    SimStruct *rts =
      Basic_controller_model_Control_Engineering_M->childSfunctions[5];
    sfcnTerminate(rts);
  }
}
