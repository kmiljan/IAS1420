//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: baseline_predictor.cpp
//
// Code generated for Simulink model 'baseline_predictor'.
//
// Model version                  : 1.8
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Sun Nov 28 11:37:32 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: Custom Processor->Custom Processor
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "baseline_predictor.h"
#include "baseline_predictor_private.h"

// Model step function
void baseline_predictorModelClass::step()
{
  real_T rtb_DiscreteTimeIntegrator;

  // DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   Inport: '<Root>/Initial value'

  if (baseline_predictor_DW.DiscreteTimeIntegrator_IC_LOADI != 0) {
    baseline_predictor_DW.DiscreteTimeIntegrator_DSTATE =
      baseline_predictor_U.Initialvalue;
  }

  rtb_DiscreteTimeIntegrator =
    baseline_predictor_DW.DiscreteTimeIntegrator_DSTATE;

  // Outport: '<Root>/Baseline' incorporates:
  //   DiscreteIntegrator: '<Root>/Discrete-Time Integrator'

  baseline_predictor_Y.Baseline =
    baseline_predictor_DW.DiscreteTimeIntegrator_DSTATE;

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator'
  baseline_predictor_DW.DiscreteTimeIntegrator_IC_LOADI = 0U;

  // MultiPortSwitch: '<Root>/Index Vector' incorporates:
  //   Inport: '<Root>/Measured value'
  //   Inport: '<Root>/Mode'

  if (static_cast<int32_T>(baseline_predictor_U.Mode) == 0) {
    baseline_predictor_DW.UnitDelay_DSTATE = baseline_predictor_U.Measuredvalue;
  }

  // End of MultiPortSwitch: '<Root>/Index Vector'

  // Update for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' incorporates:
  //   Gain: '<Root>/Baseline predictor P'
  //   Sum: '<Root>/Add'

  baseline_predictor_DW.DiscreteTimeIntegrator_DSTATE +=
    (baseline_predictor_DW.UnitDelay_DSTATE -
     baseline_predictor_DW.DiscreteTimeIntegrator_DSTATE) *
    baseline_predictor_P.BaselinepredictorP_Gain *
    baseline_predictor_P.DiscreteTimeIntegrator_gainval;

  // Update for MultiPortSwitch: '<Root>/Index Vector' incorporates:
  //   UnitDelay: '<Root>/Unit Delay'

  baseline_predictor_DW.UnitDelay_DSTATE = rtb_DiscreteTimeIntegrator;
}

// Model initialize function
void baseline_predictorModelClass::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<Root>/Discrete-Time Integrator' 
  baseline_predictor_DW.DiscreteTimeIntegrator_IC_LOADI = 1U;

  // InitializeConditions for MultiPortSwitch: '<Root>/Index Vector' incorporates:
  //   UnitDelay: '<Root>/Unit Delay'

  baseline_predictor_DW.UnitDelay_DSTATE =
    baseline_predictor_P.UnitDelay_InitialCondition;
}

// Model terminate function
void baseline_predictorModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
baseline_predictorModelClass::baseline_predictorModelClass():
  baseline_predictor_U()
  ,baseline_predictor_Y()
  ,baseline_predictor_DW()
  ,baseline_predictor_M()
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
  return baseline_predictor_P;
}

// Block parameters set method
void baseline_predictorModelClass::setBlockParameters(const
  P_baseline_predictor_T *pbaseline_predictor_P)
{
  baseline_predictor_P = *pbaseline_predictor_P;
}

// Real-Time Model get method
baseline_predictorModelClass::RT_MODEL_baseline_predictor_T
  * baseline_predictorModelClass::getRTM()
{
  return (&baseline_predictor_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
