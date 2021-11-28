//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: baseline_predictor.cpp
//
// Code generated for Simulink model 'baseline_predictor'.
//
// Model version                  : 1.9
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Sun Nov 28 12:39:16 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom Processor
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "baseline_predictor.h"
#include "baseline_predictor_private.h"

baseline_predictorModelClass::P_baseline_predictor_T
  baseline_predictorModelClass::baseline_predictor_rtP = {
  // Expression: 0
  //  Referenced by: '<Root>/Unit Delay'

  0.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<Root>/Discrete-Time Integrator'

  1.0,

  // Expression: 0.001
  //  Referenced by: '<Root>/Baseline predictor P'

  0.001
};

// System initialize for referenced model: 'baseline_predictor'
void baseline_predictorModelClass::init(void)
{
  // InitializeConditions for UnitDelay: '<Root>/Unit Delay'
  baseline_predictor_DW.UnitDelay_DSTATE =
    baseline_predictor_rtP.UnitDelay_InitialCondition;

  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  baseline_predictor_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;
}

// Output and update for referenced model: 'baseline_predictor'
void baseline_predictorModelClass::step(const real_T *rtu_Measuredvalue, const
  real_T *rtu_Mode, const real_T *rtu_Initialvalue, real_T *rty_Baseline)
{
  real_T rtb_IndexVector;

  // MultiPortSwitch: '<Root>/Index Vector' incorporates:
  //   UnitDelay: '<Root>/Unit Delay'

  if (static_cast<int32_T>(*rtu_Mode) == 0) {
    rtb_IndexVector = *rtu_Measuredvalue;
  } else {
    rtb_IndexVector = baseline_predictor_DW.UnitDelay_DSTATE;
  }

  // End of MultiPortSwitch: '<Root>/Index Vector'

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  if (baseline_predictor_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    baseline_predictor_DW.DiscreteTimeIntegrator_DSTATE = *rtu_Initialvalue;
  }

  *rty_Baseline = baseline_predictor_DW.DiscreteTimeIntegrator_DSTATE;

  // End of DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  // Update for UnitDelay: '<Root>/Unit Delay'
  baseline_predictor_DW.UnitDelay_DSTATE = *rty_Baseline;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   Gain: '<Root>/Baseline predictor P'
  //   Sum: '<Root>/Add'

  baseline_predictor_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;
  baseline_predictor_DW.DiscreteTimeIntegrator_DSTATE += (rtb_IndexVector -
    *rty_Baseline) * baseline_predictor_rtP.BaselinepredictorP_Gain *
    baseline_predictor_rtP.DiscreteTimeIntegrator_gainval;
}

// Constructor
baseline_predictorModelClass::baseline_predictorModelClass():
  baseline_predictor_DW()
{
  // Currently there is no constructor body generated.
}

// Destructor
baseline_predictorModelClass::~baseline_predictorModelClass()
{
  // Currently there is no destructor body generated.
}

// Block parameters get method
const baseline_predictorModelClass::P_baseline_predictor_T
  & baseline_predictorModelClass::getBlockParameters() const
{
  return baseline_predictor_rtP;
}

// Block parameters set method
void baseline_predictorModelClass::setBlockParameters(const
  P_baseline_predictor_T *pbaseline_predictor_rtP)
{
  baseline_predictor_rtP = *pbaseline_predictor_rtP;
}

// Real-Time Model get method
baseline_predictorModelClass::RT_MODEL_baseline_predictor_T
  * baseline_predictorModelClass::getRTM()
{
  return (&baseline_predictor_M);
}

// member function to setup error status pointer
void baseline_predictorModelClass::setErrorStatusPointer(const char_T
  **rt_errorStatus)
{
  rtmSetErrorStatusPointer((&baseline_predictor_M), rt_errorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
