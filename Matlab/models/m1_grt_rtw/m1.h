/*
 * m1.h
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

#ifndef RTW_HEADER_m1_h_
#define RTW_HEADER_m1_h_
#include <cmath>
#include <cstring>
#include <cfloat>
#include <stddef.h>
#include "rtw_modelmap.h"
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#include "m1_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include <stddef.h>
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals for system '<Root>/Moving Average3' */
typedef struct {
  real_T MovingAverage3;               /* '<Root>/Moving Average3' */
} B_MovingAverage3_m1_T;

/* Block states (default storage) for system '<Root>/Moving Average3' */
typedef struct {
  g_dsp_private_SlidingWindowAv_T gobj_1;/* '<Root>/Moving Average3' */
  g_dsp_private_SlidingWindowAv_T gobj_2;/* '<Root>/Moving Average3' */
  dsp_simulink_MovingAverage_m1_T obj; /* '<Root>/Moving Average3' */
  boolean_T objisempty;                /* '<Root>/Moving Average3' */
} DW_MovingAverage3_m1_T;

/* Block signals for system '<S1>/Moving Average3' */
typedef struct {
  real_T MovingAverage3;               /* '<S1>/Moving Average3' */
} B_MovingAverage3_m1_c_T;

/* Block states (default storage) for system '<S1>/Moving Average3' */
typedef struct {
  g_dsp_private_SlidingWindow_h_T gobj_1;/* '<S1>/Moving Average3' */
  g_dsp_private_SlidingWindow_h_T gobj_2;/* '<S1>/Moving Average3' */
  dsp_simulink_MovingAverage_e_T obj;  /* '<S1>/Moving Average3' */
  boolean_T objisempty;                /* '<S1>/Moving Average3' */
} DW_MovingAverage3_m1_f_T;

/* Block signals (default storage) */
typedef struct {
  real_T IndexVector;                  /* '<S1>/Index Vector' */
  real_T IndexVector_l;                /* '<S2>/Index Vector' */
  real_T Backlash;                     /* '<S6>/Backlash' */
  StatesModeType StatesMode;           /* '<Root>/States' */
  B_MovingAverage3_m1_c_T MovingAverage_pn;/* '<S1>/Moving Average3' */
  B_MovingAverage3_m1_c_T MovingAverage1_pn;/* '<S1>/Moving Average3' */
  B_MovingAverage3_m1_c_T MovingAverage2_pn;/* '<S1>/Moving Average3' */
  B_MovingAverage3_m1_c_T MovingAverage3_pn;/* '<S1>/Moving Average3' */
  B_MovingAverage3_m1_c_T MovingAverage_p;/* '<S1>/Moving Average3' */
  B_MovingAverage3_m1_c_T MovingAverage1_p;/* '<S1>/Moving Average3' */
  B_MovingAverage3_m1_c_T MovingAverage2_p;/* '<S1>/Moving Average3' */
  B_MovingAverage3_m1_c_T MovingAverage3_p;/* '<S1>/Moving Average3' */
  B_MovingAverage3_m1_T MovingAverage; /* '<Root>/Moving Average3' */
  B_MovingAverage3_m1_T MovingAverage2;/* '<Root>/Moving Average3' */
  B_MovingAverage3_m1_T MovingAverage1;/* '<Root>/Moving Average3' */
  B_MovingAverage3_m1_T MovingAverage3;/* '<Root>/Moving Average3' */
} B_m1_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<Root>/Unit Delay' */
  real_T UnitDelay_DSTATE_o;           /* '<S1>/Unit Delay' */
  real_T UD_DSTATE;                    /* '<S3>/UD' */
  real_T UnitDelay_DSTATE_k;           /* '<S2>/Unit Delay' */
  real_T UD_DSTATE_n;                  /* '<S4>/UD' */
  real_T Downsample_Buffer;            /* '<S1>/Downsample' */
  real_T Downsample1_Buffer;           /* '<Root>/Downsample1' */
  real_T Downsample_Buffer_a;          /* '<S2>/Downsample' */
  real_T Downsample_Buffer_f;          /* '<Root>/Downsample' */
  real_T PrevY;                        /* '<S6>/Backlash' */
  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } Humidity_PWORK;                    /* '<Root>/Humidity' */

  struct {
    void *TimePtr;
    void *DataPtr;
    void *RSimInfoPtr;
  } Temperature_PWORK;                 /* '<Root>/Temperature' */

  int32_T Downsample_Count;            /* '<S1>/Downsample' */
  int32_T Downsample1_Count;           /* '<Root>/Downsample1' */
  int32_T Downsample_Count_b;          /* '<S2>/Downsample' */
  int32_T Downsample_Count_i;          /* '<Root>/Downsample' */
  struct {
    int_T PrevIndex;
  } Humidity_IWORK;                    /* '<Root>/Humidity' */

  struct {
    int_T PrevIndex;
  } Temperature_IWORK;                 /* '<Root>/Temperature' */

  uint8_T is_active_c3_m1;             /* '<Root>/States' */
  boolean_T IC_FirstOutputTime;        /* '<Root>/IC' */
  boolean_T IC1_FirstOutputTime;       /* '<Root>/IC1' */
  DW_MovingAverage3_m1_f_T MovingAverage_pn;/* '<S1>/Moving Average3' */
  DW_MovingAverage3_m1_f_T MovingAverage1_pn;/* '<S1>/Moving Average3' */
  DW_MovingAverage3_m1_f_T MovingAverage2_pn;/* '<S1>/Moving Average3' */
  DW_MovingAverage3_m1_f_T MovingAverage3_pn;/* '<S1>/Moving Average3' */
  DW_MovingAverage3_m1_f_T MovingAverage_p;/* '<S1>/Moving Average3' */
  DW_MovingAverage3_m1_f_T MovingAverage1_p;/* '<S1>/Moving Average3' */
  DW_MovingAverage3_m1_f_T MovingAverage2_p;/* '<S1>/Moving Average3' */
  DW_MovingAverage3_m1_f_T MovingAverage3_p;/* '<S1>/Moving Average3' */
  DW_MovingAverage3_m1_T MovingAverage;/* '<Root>/Moving Average3' */
  DW_MovingAverage3_m1_T MovingAverage2;/* '<Root>/Moving Average3' */
  DW_MovingAverage3_m1_T MovingAverage1;/* '<Root>/Moving Average3' */
  DW_MovingAverage3_m1_T MovingAverage3;/* '<Root>/Moving Average3' */
} DW_m1_T;

/* Parameters (default storage) */
struct P_m1_T_ {
  real_T initial_h;                    /* Variable: initial_h
                                        * Referenced by: '<S3>/UD'
                                        */
  real_T initial_t;                    /* Variable: initial_t
                                        * Referenced by: '<S4>/UD'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<Root>/Unit Delay'
                                        */
  real_T IC_Value;                     /* Expression: 50
                                        * Referenced by: '<Root>/IC'
                                        */
  real_T UnitDelay_InitialCondition_p; /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  real_T Downsample_ic;                /* Expression: 0
                                        * Referenced by: '<S1>/Downsample'
                                        */
  real_T Downsample1_ic;               /* Expression: initial_h
                                        * Referenced by: '<Root>/Downsample1'
                                        */
  real_T Gain_Gain;                    /* Expression: 16
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T IC1_Value;                    /* Expression: 25
                                        * Referenced by: '<Root>/IC1'
                                        */
  real_T UnitDelay_InitialCondition_e; /* Expression: 0
                                        * Referenced by: '<S2>/Unit Delay'
                                        */
  real_T Downsample_ic_p;              /* Expression: 0
                                        * Referenced by: '<S2>/Downsample'
                                        */
  real_T Downsample_ic_l;              /* Expression: initial_t
                                        * Referenced by: '<Root>/Downsample'
                                        */
  real_T Gain1_Gain;                   /* Expression: 16
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 30
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S6>/Saturation'
                                        */
  real_T Backlash_BacklashWidth;       /* Expression: 2
                                        * Referenced by: '<S6>/Backlash'
                                        */
  real_T Backlash_InitialOutput;       /* Expression: 0
                                        * Referenced by: '<S6>/Backlash'
                                        */
  real_T Quantizer_Interval;           /* Expression: 30/4
                                        * Referenced by: '<S6>/Quantizer'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_m1_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
    void* dataAddress[24];
    int32_T* vardimsAddress[24];
    RTWLoggingFcnPtr loggingPtrs[24];
  } DataMapInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Function to get C API Model Mapping Static Info */
extern const rtwCAPI_ModelMappingStaticInfo*
  m1_GetCAPIStaticMap(void);

/* Class declaration for model m1 */
class m1ModelClass {
  /* public data and function members */
 public:
  /* model initialize function */
  void initialize();

  /* model step function */
  void step();

  /* model terminate function */
  void terminate();

  /* Constructor */
  m1ModelClass();

  /* Destructor */
  ~m1ModelClass();

  /* Real-Time Model get method */
  RT_MODEL_m1_T * getRTM();

  /* private data and function members */
 private:
  /* Tunable parameters */
  static P_m1_T m1_P;

  /* Block signals */
  B_m1_T m1_B;

  /* Block states */
  DW_m1_T m1_DW;

  /* Real-Time Model */
  RT_MODEL_m1_T m1_M;

  /* private member function(s) for subsystem '<Root>/Moving Average3'*/
  void m1_MovingAverage3_Init(DW_MovingAverage3_m1_T *localDW);
  void m1_MovingAverage3(real_T rtu_0, B_MovingAverage3_m1_T *localB,
    DW_MovingAverage3_m1_T *localDW);
  void m1_MovingAverage3_Term(DW_MovingAverage3_m1_T *localDW);
  void m1_SystemCore_release(dsp_simulink_MovingAverage_m1_T *obj);
  void m1_SystemCore_delete(dsp_simulink_MovingAverage_m1_T *obj);
  void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_m1_T *obj);

  /* private member function(s) for subsystem '<S1>/Moving Average3'*/
  void m1_MovingAverage3_l_Init(DW_MovingAverage3_m1_f_T *localDW);
  void m1_MovingAverage3_p(real_T rtu_0, B_MovingAverage3_m1_c_T *localB,
    DW_MovingAverage3_m1_f_T *localDW);
  void m1_MovingAverage3_a_Term(DW_MovingAverage3_m1_f_T *localDW);
  real_T SlidingWindowAverageCG_stepImpl(g_dsp_private_SlidingWindow_h_T *obj,
    real_T u);
  void m1_SystemCore_release_m(dsp_simulink_MovingAverage_e_T *obj);
  void m1_SystemCore_delete_a(dsp_simulink_MovingAverage_e_T *obj);
  void matlabCodegenHandle_matlabCod_g(dsp_simulink_MovingAverage_e_T *obj);
};

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
 * '<Root>' : 'm1'
 * '<S1>'   : 'm1/Baseline predictor filter'
 * '<S2>'   : 'm1/Baseline predictor filter1'
 * '<S3>'   : 'm1/Discrete Derivative'
 * '<S4>'   : 'm1/Discrete Derivative1'
 * '<S5>'   : 'm1/States'
 * '<S6>'   : 'm1/Vent power control'
 */
#endif                                 /* RTW_HEADER_m1_h_ */
