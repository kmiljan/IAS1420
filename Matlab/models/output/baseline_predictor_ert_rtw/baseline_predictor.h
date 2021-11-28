//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: baseline_predictor.h
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
#ifndef RTW_HEADER_baseline_predictor_h_
#define RTW_HEADER_baseline_predictor_h_
#include "rtwtypes.h"
#include "baseline_predictor_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Class declaration for model baseline_predictor
class baseline_predictorModelClass {
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  typedef struct {
    real_T DiscreteTimeIntegrator_DSTATE;// '<Root>/Discrete-Time Integrator'
    real_T UnitDelay_DSTATE;           // '<Root>/Unit Delay'
    uint8_T DiscreteTimeIntegrator_IC_LOADI;// '<Root>/Discrete-Time Integrator' 
  } DW_baseline_predictor_T;

  // External inputs (root inport signals with default storage)
  typedef struct {
    real_T Measuredvalue;              // '<Root>/Measured value'
    real_T Mode;                       // '<Root>/Mode'
    real_T Initialvalue;               // '<Root>/Initial value'
  } ExtU_baseline_predictor_T;

  // External outputs (root outports fed by signals with default storage)
  typedef struct {
    real_T Baseline;                   // '<Root>/Baseline'
  } ExtY_baseline_predictor_T;

  // Parameters (default storage)
  struct P_baseline_predictor_T {
    real_T DiscreteTimeIntegrator_gainval;
                           // Computed Parameter: DiscreteTimeIntegrator_gainval
                              //  Referenced by: '<Root>/Discrete-Time Integrator'

    real_T UnitDelay_InitialCondition; // Expression: 0
                                          //  Referenced by: '<Root>/Unit Delay'

    real_T BaselinepredictorP_Gain;    // Expression: 0.001
                                          //  Referenced by: '<Root>/Baseline predictor P'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_baseline_predictor_T {
    const char_T * volatile errorStatus;
  };

  // Tunable parameters
  static P_baseline_predictor_T baseline_predictor_P;

  // External inputs
  ExtU_baseline_predictor_T baseline_predictor_U;

  // External outputs
  ExtY_baseline_predictor_T baseline_predictor_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // model terminate function
  void terminate();

  // Constructor
  baseline_predictorModelClass();

  // Destructor
  ~baseline_predictorModelClass();

  // Block parameters get method
  const baseline_predictorModelClass::P_baseline_predictor_T
    & getBlockParameters() const;

  // Block parameters set method
  void setBlockParameters(const P_baseline_predictor_T *pbaseline_predictor_P);

  // Root-level structure-based inputs set method

  // Root inports set method
  void setExternalInputs(const ExtU_baseline_predictor_T
    * pExtU_baseline_predictor_T)
  {
    baseline_predictor_U = *pExtU_baseline_predictor_T;
  }

  // Root-level structure-based outputs get method

  // Root outports get method
  const baseline_predictorModelClass::ExtY_baseline_predictor_T
    & getExternalOutputs() const
  {
    return baseline_predictor_Y;
  }

  // Real-Time Model get method
  baseline_predictorModelClass::RT_MODEL_baseline_predictor_T * getRTM();

  // private data and function members
 private:
  // Block states
  DW_baseline_predictor_T baseline_predictor_DW;

  // Real-Time Model
  RT_MODEL_baseline_predictor_T baseline_predictor_M;
};

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
//  '<Root>' : 'baseline_predictor'

#endif                                 // RTW_HEADER_baseline_predictor_h_

//
// File trailer for generated code.
//
// [EOF]
//
