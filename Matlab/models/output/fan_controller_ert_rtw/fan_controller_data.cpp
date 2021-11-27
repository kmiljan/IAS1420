//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: fan_controller_data.cpp
//
// Code generated for Simulink model 'fan_controller'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Sat Nov 27 19:59:47 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom Processor
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "fan_controller.h"
#include "fan_controller_private.h"

// Block parameters (default storage)
fan_controllerModelClass::P_fan_controller_T fan_controllerModelClass::
  fan_controller_P = {
  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S3>/UD'

  50.0,

  // Mask Parameter: DiscreteDerivative1_ICPrevScale
  //  Referenced by: '<S4>/UD'

  25.0,

  // Expression: 0
  //  Referenced by: '<S6>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<Root>/Unit Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S1>/Unit Delay'

  0.0,

  // Expression: initial_h
  //  Referenced by: '<S1>/Downsample'

  50.0,

  // Expression: initial_h
  //  Referenced by: '<Root>/Downsample1'

  50.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S3>/TSamp'

  5.0,

  // Expression: 16
  //  Referenced by: '<Root>/Gain'

  16.0,

  // Expression: 0
  //  Referenced by: '<S2>/Unit Delay'

  0.0,

  // Expression: initial_t
  //  Referenced by: '<S2>/Downsample'

  25.0,

  // Expression: initial_t
  //  Referenced by: '<Root>/Downsample'

  25.0,

  // Computed Parameter: TSamp_WtEt_l
  //  Referenced by: '<S4>/TSamp'

  5.0,

  // Expression: 16
  //  Referenced by: '<Root>/Gain1'

  16.0,

  // Expression: 30
  //  Referenced by: '<S6>/Saturation'

  30.0,

  // Expression: 0
  //  Referenced by: '<S6>/Saturation'

  0.0,

  // Expression: 2
  //  Referenced by: '<S6>/Backlash'

  2.0,

  // Expression: 0
  //  Referenced by: '<S6>/Backlash'

  0.0,

  // Expression: 30/4
  //  Referenced by: '<S6>/Quantizer'

  7.5
};

//
// File trailer for generated code.
//
// [EOF]
//