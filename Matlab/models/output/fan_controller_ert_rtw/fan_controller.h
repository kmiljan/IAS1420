//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: fan_controller.h
//
// Code generated for Simulink model 'fan_controller'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Sat Nov 27 16:21:56 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom Processor
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_fan_controller_h_
#define RTW_HEADER_fan_controller_h_
#include <cmath>
#include <cstring>
#include "rtwtypes.h"
#include "fan_controller_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Class declaration for model fan_controller
class fan_controllerModelClass {
  // public data and function members
 public:
  // Block signals for system '<Root>/Moving Average3'
  typedef struct {
    real_T MovingAverage3;             // '<Root>/Moving Average3'
  } B_MovingAverage3_fan_controll_T;

  // Block states (default storage) for system '<Root>/Moving Average3'
  typedef struct {
    g_dsp_private_SlidingWindowAv_T gobj_1;// '<Root>/Moving Average3'
    g_dsp_private_SlidingWindowAv_T gobj_2;// '<Root>/Moving Average3'
    dsp_simulink_MovingAverage_fa_T obj;// '<Root>/Moving Average3'
    boolean_T objisempty;              // '<Root>/Moving Average3'
  } DW_MovingAverage3_fan_control_T;

  // Block signals for system '<S1>/Moving Average3'
  typedef struct {
    real_T MovingAverage3;             // '<S1>/Moving Average3'
  } B_MovingAverage3_fan_contro_c_T;

  // Block states (default storage) for system '<S1>/Moving Average3'
  typedef struct {
    g_dsp_private_SlidingWindow_h_T gobj_1;// '<S1>/Moving Average3'
    g_dsp_private_SlidingWindow_h_T gobj_2;// '<S1>/Moving Average3'
    dsp_simulink_MovingAverage_e_T obj;// '<S1>/Moving Average3'
    boolean_T objisempty;              // '<S1>/Moving Average3'
  } DW_MovingAverage3_fan_contr_f_T;

  // Block signals (default storage)
  typedef struct {
    real_T IndexVector;                // '<S1>/Index Vector'
    real_T IndexVector_n;              // '<S2>/Index Vector'
    real_T Backlash;                   // '<S6>/Backlash'
    B_MovingAverage3_fan_contro_c_T MovingAverage_pn;// '<S1>/Moving Average3'
    B_MovingAverage3_fan_contro_c_T MovingAverage1_pn;// '<S1>/Moving Average3'
    B_MovingAverage3_fan_contro_c_T MovingAverage2_pn;// '<S1>/Moving Average3'
    B_MovingAverage3_fan_contro_c_T MovingAverage3_pn;// '<S1>/Moving Average3'
    B_MovingAverage3_fan_contro_c_T MovingAverage_p;// '<S1>/Moving Average3'
    B_MovingAverage3_fan_contro_c_T MovingAverage1_p;// '<S1>/Moving Average3'
    B_MovingAverage3_fan_contro_c_T MovingAverage2_p;// '<S1>/Moving Average3'
    B_MovingAverage3_fan_contro_c_T MovingAverage3_p;// '<S1>/Moving Average3'
    B_MovingAverage3_fan_controll_T MovingAverage;// '<Root>/Moving Average3'
    B_MovingAverage3_fan_controll_T MovingAverage2;// '<Root>/Moving Average3'
    B_MovingAverage3_fan_controll_T MovingAverage1;// '<Root>/Moving Average3'
    B_MovingAverage3_fan_controll_T MovingAverage3;// '<Root>/Moving Average3'
  } B_fan_controller_T;

  // Block states (default storage) for system '<Root>'
  typedef struct {
    real_T UnitDelay_DSTATE;           // '<Root>/Unit Delay'
    real_T UnitDelay_DSTATE_e;         // '<S1>/Unit Delay'
    real_T UD_DSTATE;                  // '<S3>/UD'
    real_T UnitDelay_DSTATE_i;         // '<S2>/Unit Delay'
    real_T UD_DSTATE_l;                // '<S4>/UD'
    real_T Downsample_Buffer;          // '<S1>/Downsample'
    real_T Downsample1_Buffer;         // '<Root>/Downsample1'
    real_T Downsample_Buffer_l;        // '<S2>/Downsample'
    real_T Downsample_Buffer_i;        // '<Root>/Downsample'
    real_T PrevY;                      // '<S6>/Backlash'
    int32_T Downsample_Count;          // '<S1>/Downsample'
    int32_T Downsample1_Count;         // '<Root>/Downsample1'
    int32_T Downsample_Count_a;        // '<S2>/Downsample'
    int32_T Downsample_Count_g;        // '<Root>/Downsample'
    uint8_T is_active_c3_fan_controller;// '<Root>/States'
    DW_MovingAverage3_fan_contr_f_T MovingAverage_pn;// '<S1>/Moving Average3'
    DW_MovingAverage3_fan_contr_f_T MovingAverage1_pn;// '<S1>/Moving Average3'
    DW_MovingAverage3_fan_contr_f_T MovingAverage2_pn;// '<S1>/Moving Average3'
    DW_MovingAverage3_fan_contr_f_T MovingAverage3_pn;// '<S1>/Moving Average3'
    DW_MovingAverage3_fan_contr_f_T MovingAverage_p;// '<S1>/Moving Average3'
    DW_MovingAverage3_fan_contr_f_T MovingAverage1_p;// '<S1>/Moving Average3'
    DW_MovingAverage3_fan_contr_f_T MovingAverage2_p;// '<S1>/Moving Average3'
    DW_MovingAverage3_fan_contr_f_T MovingAverage3_p;// '<S1>/Moving Average3'
    DW_MovingAverage3_fan_control_T MovingAverage;// '<Root>/Moving Average3'
    DW_MovingAverage3_fan_control_T MovingAverage2;// '<Root>/Moving Average3'
    DW_MovingAverage3_fan_control_T MovingAverage1;// '<Root>/Moving Average3'
    DW_MovingAverage3_fan_control_T MovingAverage3;// '<Root>/Moving Average3'
  } DW_fan_controller_T;

  // External inputs (root inport signals with default storage)
  typedef struct {
    real_T Humiditysensorvalue;        // '<Root>/Humidity sensor value'
    real_T Temperaturesensorvalue;     // '<Root>/Temperature sensor value'
  } ExtU_fan_controller_T;

  // External outputs (root outports fed by signals with default storage)
  typedef struct {
    real_T Outputenabled;              // '<Root>/Output enabled'
    StatesModeType StateID;            // '<Root>/State ID'
    real_T Humiditybaseline;           // '<Root>/Humidity baseline'
    real_T Humiditychange;             // '<Root>/Humidity change'
    real_T Temperaturebaseline;        // '<Root>/Temperature baseline'
    real_T Temperaturechange;          // '<Root>/Temperature change'
    real_T Requestedventpowerlevel;    // '<Root>/Requested vent power level'
  } ExtY_fan_controller_T;

  // Real-time Model Data Structure
  struct RT_MODEL_fan_controller_T {
    const char_T * volatile errorStatus;
  };

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  fan_controllerModelClass();

  // Destructor
  ~fan_controllerModelClass();

  // Root-level structure-based inputs set method

  // Root inports set method
  void setExternalInputs(const ExtU_fan_controller_T* pExtU_fan_controller_T)
  {
    fan_controller_U = *pExtU_fan_controller_T;
  }

  // Root-level structure-based outputs get method

  // Root outports get method
  const fan_controllerModelClass::ExtY_fan_controller_T & getExternalOutputs()
    const
  {
    return fan_controller_Y;
  }

  // Real-Time Model get method
  fan_controllerModelClass::RT_MODEL_fan_controller_T * getRTM();

  // private data and function members
 private:
  // Block signals
  B_fan_controller_T fan_controller_B;

  // Block states
  DW_fan_controller_T fan_controller_DW;

  // External inputs
  ExtU_fan_controller_T fan_controller_U;

  // External outputs
  ExtY_fan_controller_T fan_controller_Y;

  // Real-Time Model
  RT_MODEL_fan_controller_T fan_controller_M;

  // private member function(s) for subsystem '<Root>/Moving Average3'
  void fan_control_MovingAverage3_Init(DW_MovingAverage3_fan_control_T *localDW);
  void fan_controller_MovingAverage3(real_T rtu_0,
    B_MovingAverage3_fan_controll_T *localB, DW_MovingAverage3_fan_control_T
    *localDW);
  void fan_control_MovingAverage3_Term(DW_MovingAverage3_fan_control_T *localDW);
  void fan_controll_SystemCore_release(dsp_simulink_MovingAverage_fa_T *obj);
  void fan_controlle_SystemCore_delete(dsp_simulink_MovingAverage_fa_T *obj);
  void matlabCodegenHandle_matlabCodeg(dsp_simulink_MovingAverage_fa_T *obj);

  // private member function(s) for subsystem '<S1>/Moving Average3'
  void fan_contr_MovingAverage3_c_Init(DW_MovingAverage3_fan_contr_f_T *localDW);
  void fan_controller_MovingAverage3_p(real_T rtu_0,
    B_MovingAverage3_fan_contro_c_T *localB, DW_MovingAverage3_fan_contr_f_T
    *localDW);
  void fan_contr_MovingAverage3_a_Term(DW_MovingAverage3_fan_contr_f_T *localDW);
  real_T SlidingWindowAverageCG_stepImpl(g_dsp_private_SlidingWindow_h_T *obj,
    real_T u);
  void fan_contro_SystemCore_release_m(dsp_simulink_MovingAverage_e_T *obj);
  void fan_control_SystemCore_delete_a(dsp_simulink_MovingAverage_e_T *obj);
  void matlabCodegenHandle_matlabCod_g(dsp_simulink_MovingAverage_e_T *obj);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S3>/Data Type Duplicate' : Unused code path elimination
//  Block '<S4>/Data Type Duplicate' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'fan_controller'
//  '<S1>'   : 'fan_controller/Baseline predictor filter'
//  '<S2>'   : 'fan_controller/Baseline predictor filter1'
//  '<S3>'   : 'fan_controller/Discrete Derivative'
//  '<S4>'   : 'fan_controller/Discrete Derivative1'
//  '<S5>'   : 'fan_controller/States'
//  '<S6>'   : 'fan_controller/Vent power control'

#endif                                 // RTW_HEADER_fan_controller_h_

//
// File trailer for generated code.
//
// [EOF]
//
