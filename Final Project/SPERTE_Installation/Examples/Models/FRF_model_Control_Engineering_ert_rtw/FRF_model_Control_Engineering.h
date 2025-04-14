/*
 * FRF_model_Control_Engineering.h
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

#ifndef RTW_HEADER_FRF_model_Control_Engineering_h_
#define RTW_HEADER_FRF_model_Control_Engineering_h_
#ifndef FRF_model_Control_Engineering_COMMON_INCLUDES_
#define FRF_model_Control_Engineering_COMMON_INCLUDES_
#include <stdio.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                      /* FRF_model_Control_Engineering_COMMON_INCLUDES_ */

#include "FRF_model_Control_Engineering_types.h"
#include <stddef.h>
#include <string.h>
#include <float.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetSampleHitArray
#define rtmGetSampleHitArray(rtm)      ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
#define rtmGetStepSize(rtm)            ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
#define rtmGet_TimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmGetTStart
#define rtmGetTStart(rtm)              ((rtm)->Timing.tStart)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTimeOfLastOutput
#define rtmGetTimeOfLastOutput(rtm)    ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Buffer[3];                    /* '<S3>/Buffer' */
  real32_T xout[3];
  size_t bytesOutSizet;
  real_T Gain1;                        /* '<S6>/Gain1' */
  real_T Dctleadlag2;                  /* '<S6>/Dctleadlag2' */
  real_T Dctnotch3;                    /* '<S6>/Dctnotch3' */
  real_T Dct1lowpass4;                 /* '<S6>/Dct1lowpass4' */
  real_T Dctnotch5;                    /* '<S6>/Dctnotch5' */
  real_T Dctintegrator6;               /* '<S6>/Dctintegrator6' */
  real_T Startsetpoint;                /* '<S4>/Start setpoint' */
  real_T SFunction[3];                 /* '<S5>/S-Function' */
  real_T Gain1_j;                      /* '<S1>/Gain1' */
  real_T Dctpd;                        /* '<S1>/Dctpd' */
  real_T Dct2lowpass;                  /* '<S1>/Dct2lowpass' */
  real_T Downsample[3];                /* '<S3>/Downsample' */
  real_T Sum;                          /* '<Root>/Sum' */
  int32_T nbytes;
  int32_T i;
  uint32_T qY;
} B_FRF_model_Control_Engineering_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T NextOutput;                   /* '<Root>/Noise' */
  real_T Downsample_Buffer[3];         /* '<S3>/Downsample' */
  real_T fileID;                       /* '<S2>/SPERTE_measurement_function' */
  real_T Dctleadlag2_RWORK[2];         /* '<S6>/Dctleadlag2' */
  real_T Dctnotch3_RWORK[4];           /* '<S6>/Dctnotch3' */
  real_T Dct1lowpass4_RWORK[2];        /* '<S6>/Dct1lowpass4' */
  real_T Dctnotch5_RWORK[4];           /* '<S6>/Dctnotch5' */
  real_T Dctintegrator6_RWORK[2];      /* '<S6>/Dctintegrator6' */
  real_T SFunction_RWORK[50];          /* '<S5>/S-Function' */
  real_T Dctpd_RWORK[2];               /* '<S1>/Dctpd' */
  real_T Dct2lowpass_RWORK[4];         /* '<S1>/Dct2lowpass' */
  struct {
    void *LoggedData;
  } Live_Scope_PWORK;                  /* '<S3>/Live_Scope' */

  FILE* eml_openfiles[20];             /* '<S2>/SPERTE_measurement_function' */
  int32_T sfEvent;                     /* '<S2>/SPERTE_measurement_function' */
  uint32_T RandSeed;                   /* '<Root>/Noise' */
  uint32_T NS;                         /* '<S2>/SPERTE_measurement_function' */
  int16_T NF;                          /* '<S2>/SPERTE_measurement_function' */
  uint8_T is_active_c1_FRF_model_Control_;/* '<S2>/SPERTE_measurement_function' */
  uint8_T busy;                        /* '<S2>/SPERTE_measurement_function' */
  boolean_T doneDoubleBufferReInit;    /* '<S2>/SPERTE_measurement_function' */
  boolean_T fileID_not_empty;          /* '<S2>/SPERTE_measurement_function' */
  boolean_T NF_not_empty;              /* '<S2>/SPERTE_measurement_function' */
  boolean_T busy_not_empty;            /* '<S2>/SPERTE_measurement_function' */
  boolean_T NS_not_empty;              /* '<S2>/SPERTE_measurement_function' */
  boolean_T eml_openfiles_not_empty;   /* '<S2>/SPERTE_measurement_function' */
  boolean_T eml_autoflush[20];         /* '<S2>/SPERTE_measurement_function' */
  boolean_T eml_autoflush_not_empty;   /* '<S2>/SPERTE_measurement_function' */
} DW_FRF_model_Control_Engineering_T;

/* Parameters (default storage) */
struct P_FRF_model_Control_Engineering_T_ {
  real_T SFunction_P1_Size[2];         /* Computed Parameter: SFunction_P1_Size
                                        * Referenced by: '<S5>/S-Function'
                                        */
  real_T ref_part[18];                 /* Variable: ref_part
                                        * Referenced by: '<S5>/S-Function'
                                        */
  real_T Refpower_stat;                /* Mask Parameter: Refpower_stat
                                        * Referenced by: '<S4>/Start setpoint'
                                        */
  uint32_T MeasurementBlock_N_samples;
                                   /* Mask Parameter: MeasurementBlock_N_samples
                                    * Referenced by: '<S2>/SPERTE_measurement_samples'
                                    */
  uint8_T MeasurementBlock_trigger_comman;
                              /* Mask Parameter: MeasurementBlock_trigger_comman
                               * Referenced by: '<S2>/SPERTE_measurement_trigger_command'
                               */
  uint8_T MeasurementBlock_triggertype;
                                 /* Mask Parameter: MeasurementBlock_triggertype
                                  * Referenced by: '<S2>/SPERTE_measurement_function'
                                  */
  real_T Noise_Mean;                   /* Expression: 0
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Noise_StdDev;                 /* Computed Parameter: Noise_StdDev
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Noise_Seed;                   /* Expression: 0
                                        * Referenced by: '<Root>/Noise'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.348
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Dctleadlag2_P1_Size[2];      /* Computed Parameter: Dctleadlag2_P1_Size
                                       * Referenced by: '<S6>/Dctleadlag2'
                                       */
  real_T Dctleadlag2_P1;               /* Expression: f_num
                                        * Referenced by: '<S6>/Dctleadlag2'
                                        */
  real_T Dctleadlag2_P2_Size[2];      /* Computed Parameter: Dctleadlag2_P2_Size
                                       * Referenced by: '<S6>/Dctleadlag2'
                                       */
  real_T Dctleadlag2_P2;               /* Expression: f_den
                                        * Referenced by: '<S6>/Dctleadlag2'
                                        */
  real_T Dctleadlag2_P3_Size[2];      /* Computed Parameter: Dctleadlag2_P3_Size
                                       * Referenced by: '<S6>/Dctleadlag2'
                                       */
  real_T Dctleadlag2_P3;               /* Expression: 0.001
                                        * Referenced by: '<S6>/Dctleadlag2'
                                        */
  real_T Dctnotch3_P1_Size[2];         /* Computed Parameter: Dctnotch3_P1_Size
                                        * Referenced by: '<S6>/Dctnotch3'
                                        */
  real_T Dctnotch3_P1;                 /* Expression: f_num
                                        * Referenced by: '<S6>/Dctnotch3'
                                        */
  real_T Dctnotch3_P2_Size[2];         /* Computed Parameter: Dctnotch3_P2_Size
                                        * Referenced by: '<S6>/Dctnotch3'
                                        */
  real_T Dctnotch3_P2;                 /* Expression: b_num
                                        * Referenced by: '<S6>/Dctnotch3'
                                        */
  real_T Dctnotch3_P3_Size[2];         /* Computed Parameter: Dctnotch3_P3_Size
                                        * Referenced by: '<S6>/Dctnotch3'
                                        */
  real_T Dctnotch3_P3;                 /* Expression: f_den
                                        * Referenced by: '<S6>/Dctnotch3'
                                        */
  real_T Dctnotch3_P4_Size[2];         /* Computed Parameter: Dctnotch3_P4_Size
                                        * Referenced by: '<S6>/Dctnotch3'
                                        */
  real_T Dctnotch3_P4;                 /* Expression: b_den
                                        * Referenced by: '<S6>/Dctnotch3'
                                        */
  real_T Dctnotch3_P5_Size[2];         /* Computed Parameter: Dctnotch3_P5_Size
                                        * Referenced by: '<S6>/Dctnotch3'
                                        */
  real_T Dctnotch3_P5;                 /* Expression: 0.001
                                        * Referenced by: '<S6>/Dctnotch3'
                                        */
  real_T Dct1lowpass4_P1_Size[2];    /* Computed Parameter: Dct1lowpass4_P1_Size
                                      * Referenced by: '<S6>/Dct1lowpass4'
                                      */
  real_T Dct1lowpass4_P1;              /* Expression: f_den
                                        * Referenced by: '<S6>/Dct1lowpass4'
                                        */
  real_T Dct1lowpass4_P2_Size[2];    /* Computed Parameter: Dct1lowpass4_P2_Size
                                      * Referenced by: '<S6>/Dct1lowpass4'
                                      */
  real_T Dct1lowpass4_P2;              /* Expression: 0.001
                                        * Referenced by: '<S6>/Dct1lowpass4'
                                        */
  real_T Dctnotch5_P1_Size[2];         /* Computed Parameter: Dctnotch5_P1_Size
                                        * Referenced by: '<S6>/Dctnotch5'
                                        */
  real_T Dctnotch5_P1;                 /* Expression: f_num
                                        * Referenced by: '<S6>/Dctnotch5'
                                        */
  real_T Dctnotch5_P2_Size[2];         /* Computed Parameter: Dctnotch5_P2_Size
                                        * Referenced by: '<S6>/Dctnotch5'
                                        */
  real_T Dctnotch5_P2;                 /* Expression: b_num
                                        * Referenced by: '<S6>/Dctnotch5'
                                        */
  real_T Dctnotch5_P3_Size[2];         /* Computed Parameter: Dctnotch5_P3_Size
                                        * Referenced by: '<S6>/Dctnotch5'
                                        */
  real_T Dctnotch5_P3;                 /* Expression: f_den
                                        * Referenced by: '<S6>/Dctnotch5'
                                        */
  real_T Dctnotch5_P4_Size[2];         /* Computed Parameter: Dctnotch5_P4_Size
                                        * Referenced by: '<S6>/Dctnotch5'
                                        */
  real_T Dctnotch5_P4;                 /* Expression: b_den
                                        * Referenced by: '<S6>/Dctnotch5'
                                        */
  real_T Dctnotch5_P5_Size[2];         /* Computed Parameter: Dctnotch5_P5_Size
                                        * Referenced by: '<S6>/Dctnotch5'
                                        */
  real_T Dctnotch5_P5;                 /* Expression: 0.001
                                        * Referenced by: '<S6>/Dctnotch5'
                                        */
  real_T Dctintegrator6_P1_Size[2];/* Computed Parameter: Dctintegrator6_P1_Size
                                    * Referenced by: '<S6>/Dctintegrator6'
                                    */
  real_T Dctintegrator6_P1;            /* Expression: f_num
                                        * Referenced by: '<S6>/Dctintegrator6'
                                        */
  real_T Dctintegrator6_P2_Size[2];/* Computed Parameter: Dctintegrator6_P2_Size
                                    * Referenced by: '<S6>/Dctintegrator6'
                                    */
  real_T Dctintegrator6_P2;            /* Expression: 0.001
                                        * Referenced by: '<S6>/Dctintegrator6'
                                        */
  real_T Quantizer1_Interval;          /* Expression: (2*pi)/(500*4)
                                        * Referenced by: '<Root>/Quantizer1'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: 1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Dctpd_P1_Size[2];             /* Computed Parameter: Dctpd_P1_Size
                                        * Referenced by: '<S1>/Dctpd'
                                        */
  real_T Dctpd_P1;                     /* Expression: kp
                                        * Referenced by: '<S1>/Dctpd'
                                        */
  real_T Dctpd_P2_Size[2];             /* Computed Parameter: Dctpd_P2_Size
                                        * Referenced by: '<S1>/Dctpd'
                                        */
  real_T Dctpd_P2;                     /* Expression: kv
                                        * Referenced by: '<S1>/Dctpd'
                                        */
  real_T Dctpd_P3_Size[2];             /* Computed Parameter: Dctpd_P3_Size
                                        * Referenced by: '<S1>/Dctpd'
                                        */
  real_T Dctpd_P3;                     /* Expression: 0.001
                                        * Referenced by: '<S1>/Dctpd'
                                        */
  real_T Dct2lowpass_P1_Size[2];      /* Computed Parameter: Dct2lowpass_P1_Size
                                       * Referenced by: '<S1>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P1;               /* Expression: f_den
                                        * Referenced by: '<S1>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P2_Size[2];      /* Computed Parameter: Dct2lowpass_P2_Size
                                       * Referenced by: '<S1>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P2;               /* Expression: b_den
                                        * Referenced by: '<S1>/Dct2lowpass'
                                        */
  real_T Dct2lowpass_P3_Size[2];      /* Computed Parameter: Dct2lowpass_P3_Size
                                       * Referenced by: '<S1>/Dct2lowpass'
                                       */
  real_T Dct2lowpass_P3;               /* Expression: 0.001
                                        * Referenced by: '<S1>/Dct2lowpass'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_FRF_model_Control_Engineering_T {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[3];
    SimStruct childSFunctions[8];
    SimStruct *childSFunctionPtrs[8];
    struct _ssBlkInfo2 blkInfo2[8];
    struct _ssSFcnModelMethods2 methods2[8];
    struct _ssSFcnModelMethods3 methods3[8];
    struct _ssSFcnModelMethods4 methods4[8];
    struct _ssStatesInfo2 statesInfo2[8];
    ssPeriodicStatesInfo periodicStatesInfo[8];
    struct _ssPortInfo2 inputOutputPortInfo2[8];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[2];
      mxArray *params[2];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[1];
      mxArray *params[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssInPortUnit inputPortUnits[1];
      struct _ssInPortCoSimAttribute inputPortCoSimAttribute[1];
      real_T const *UPtrs0[1];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssOutPortUnit outputPortUnits[1];
      struct _ssOutPortCoSimAttribute outputPortCoSimAttribute[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;
  } NonInlinedSFcns;

  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_FRF_model_Control_Engineering_T FRF_model_Control_Engineering_P;

/* Block signals (default storage) */
extern B_FRF_model_Control_Engineering_T FRF_model_Control_Engineering_B;

/* Block states (default storage) */
extern DW_FRF_model_Control_Engineering_T FRF_model_Control_Engineering_DW;

/* External function called from main */
extern void FRF_model_Control_Engineering_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void FRF_model_Control_Engineering_initialize(void);
extern void FRF_model_Control_Engineering_step0(void);
extern void FRF_model_Control_Engineering_step2(void);
extern void FRF_model_Control_Engineering_step(int_T tid);
extern void FRF_model_Control_Engineering_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FRF_model_Control_Engineering_T *const
  FRF_model_Control_Engineering_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Gain' : Unused code path elimination
 * Block '<Root>/Select encoder' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'FRF_model_Control_Engineering'
 * '<S1>'   : 'FRF_model_Control_Engineering/Controller (motor side)'
 * '<S2>'   : 'FRF_model_Control_Engineering/Measurement Block'
 * '<S3>'   : 'FRF_model_Control_Engineering/Real-time scope'
 * '<S4>'   : 'FRF_model_Control_Engineering/Ref power'
 * '<S5>'   : 'FRF_model_Control_Engineering/Subsystem'
 * '<S6>'   : 'FRF_model_Control_Engineering/Without_notch_controller'
 * '<S7>'   : 'FRF_model_Control_Engineering/Measurement Block/SPERTE_measurement_function'
 */
#endif                         /* RTW_HEADER_FRF_model_Control_Engineering_h_ */
