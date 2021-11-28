//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: fan_controller_types.h
//
// Code generated for Simulink model 'fan_controller'.
//
// Model version                  : 1.7
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Sun Nov 28 11:11:36 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom Processor
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_fan_controller_types_h_
#define RTW_HEADER_fan_controller_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef DEFINED_TYPEDEF_FOR_StatesModeType_
#define DEFINED_TYPEDEF_FOR_StatesModeType_

typedef enum {
  StatesModeType_None = 0,             // Default value
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

#endif                                 //struct_tag_vs0CgRXQOF3v3Ho5FAx8sC

#ifndef typedef_g_dsp_private_SlidingWindowAv_T
#define typedef_g_dsp_private_SlidingWindowAv_T

typedef struct tag_vs0CgRXQOF3v3Ho5FAx8sC g_dsp_private_SlidingWindowAv_T;

#endif                                 //typedef_g_dsp_private_SlidingWindowAv_T

#ifndef struct_tag_PMfBDzoakfdM9QAdfx2o6D
#define struct_tag_PMfBDzoakfdM9QAdfx2o6D

struct tag_PMfBDzoakfdM9QAdfx2o6D
{
  uint32_T f1[8];
};

#endif                                 //struct_tag_PMfBDzoakfdM9QAdfx2o6D

#ifndef typedef_cell_wrap_fan_controller_T
#define typedef_cell_wrap_fan_controller_T

typedef struct tag_PMfBDzoakfdM9QAdfx2o6D cell_wrap_fan_controller_T;

#endif                                 //typedef_cell_wrap_fan_controller_T

#ifndef struct_tag_AxbnolBzt5DX5uskBOpryG
#define struct_tag_AxbnolBzt5DX5uskBOpryG

struct tag_AxbnolBzt5DX5uskBOpryG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_fan_controller_T inputVarSize;
  g_dsp_private_SlidingWindowAv_T *pStatistic;
  int32_T NumChannels;
};

#endif                                 //struct_tag_AxbnolBzt5DX5uskBOpryG

#ifndef typedef_dsp_simulink_MovingAverage_fa_T
#define typedef_dsp_simulink_MovingAverage_fa_T

typedef struct tag_AxbnolBzt5DX5uskBOpryG dsp_simulink_MovingAverage_fa_T;

#endif                                 //typedef_dsp_simulink_MovingAverage_fa_T
#endif                                 // RTW_HEADER_fan_controller_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
