/*
 * m1_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "m1".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Mon Nov 15 14:24:38 2021
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM 10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_m1_types_h_
#define RTW_HEADER_m1_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_StatesModeType_
#define DEFINED_TYPEDEF_FOR_StatesModeType_

typedef enum {
  StatesModeType_None = 0,             /* Default value */
  StatesModeType_OFF,
  StatesModeType_Detected,
  StatesModeType_Stable,
  StatesModeType_Stopping
} StatesModeType;

#endif

#ifndef struct_tag_vs0CgRXQOF3v3Ho5FAx8sC
#define struct_tag_vs0CgRXQOF3v3Ho5FAx8sC

struct tag_vs0CgRXQOF3v3Ho5FAx8sC
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[15];
  real_T pCumRevIndex;
};

#endif                                 /*struct_tag_vs0CgRXQOF3v3Ho5FAx8sC*/

#ifndef typedef_g_dsp_private_SlidingWindowAv_T
#define typedef_g_dsp_private_SlidingWindowAv_T

typedef struct tag_vs0CgRXQOF3v3Ho5FAx8sC g_dsp_private_SlidingWindowAv_T;

#endif                               /*typedef_g_dsp_private_SlidingWindowAv_T*/

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 /*struct_tag_PMfBDzoakfdM9QAdfx2o6D*/

#ifndef typedef_cell_wrap_m1_T
#define typedef_cell_wrap_m1_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_m1_T;

#endif                                 /*typedef_cell_wrap_m1_T*/

#ifndef struct_tag_AxbnolBzt5DX5uskBOpryG
#define struct_tag_AxbnolBzt5DX5uskBOpryG

struct tag_AxbnolBzt5DX5uskBOpryG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_m1_T inputVarSize;
  g_dsp_private_SlidingWindowAv_T *pStatistic;
  int32_T NumChannels;
};

#endif                                 /*struct_tag_AxbnolBzt5DX5uskBOpryG*/

#ifndef typedef_dsp_simulink_MovingAverage_m1_T
#define typedef_dsp_simulink_MovingAverage_m1_T

typedef struct tag_AxbnolBzt5DX5uskBOpryG dsp_simulink_MovingAverage_m1_T;

#endif                               /*typedef_dsp_simulink_MovingAverage_m1_T*/

#ifndef struct_tag_s79JTaJHzrtgmwQAFOfFmF
#define struct_tag_s79JTaJHzrtgmwQAFOfFmF

struct tag_s79JTaJHzrtgmwQAFOfFmF
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[511];
  real_T pCumRevIndex;
};

#endif                                 /*struct_tag_s79JTaJHzrtgmwQAFOfFmF*/

#ifndef typedef_g_dsp_private_SlidingWindow_h_T
#define typedef_g_dsp_private_SlidingWindow_h_T

typedef struct tag_s79JTaJHzrtgmwQAFOfFmF g_dsp_private_SlidingWindow_h_T;

#endif                               /*typedef_g_dsp_private_SlidingWindow_h_T*/

#ifndef struct_tag_wDEYHy0oo1UK5Yb5CXFYKG
#define struct_tag_wDEYHy0oo1UK5Yb5CXFYKG

struct tag_wDEYHy0oo1UK5Yb5CXFYKG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_m1_T inputVarSize;
  g_dsp_private_SlidingWindow_h_T *pStatistic;
  int32_T NumChannels;
};

#endif                                 /*struct_tag_wDEYHy0oo1UK5Yb5CXFYKG*/

#ifndef typedef_dsp_simulink_MovingAverage_e_T
#define typedef_dsp_simulink_MovingAverage_e_T

typedef struct tag_wDEYHy0oo1UK5Yb5CXFYKG dsp_simulink_MovingAverage_e_T;

#endif                                /*typedef_dsp_simulink_MovingAverage_e_T*/

/* Parameters (default storage) */
typedef struct P_m1_T_ P_m1_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_m1_T RT_MODEL_m1_T;

#endif                                 /* RTW_HEADER_m1_types_h_ */
