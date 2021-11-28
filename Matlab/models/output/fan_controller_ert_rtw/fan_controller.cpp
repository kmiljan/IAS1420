//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: fan_controller.cpp
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
#include "fan_controller.h"
#include "fan_controller_private.h"
#include "rt_roundd_snf.h"

void fan_controllerModelClass::fan_controll_SystemCore_release
  (dsp_simulink_MovingAverage_fa_T *obj)
{
  g_dsp_private_SlidingWindowAv_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

void fan_controllerModelClass::fan_controlle_SystemCore_delete
  (dsp_simulink_MovingAverage_fa_T *obj)
{
  fan_controll_SystemCore_release(obj);
}

void fan_controllerModelClass::matlabCodegenHandle_matlabCodeg
  (dsp_simulink_MovingAverage_fa_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    fan_controlle_SystemCore_delete(obj);
  }
}

//
// System initialize for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void fan_controllerModelClass::fan_control_MovingAverage3_Init
  (DW_MovingAverage3_fan_control_T *localDW)
{
  // Start for MATLABSystem: '<Root>/Moving Average3'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->gobj_2.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->gobj_2;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  // InitializeConditions for MATLABSystem: '<Root>/Moving Average3'
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0;
    std::memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 15U * sizeof(real_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
  }

  // End of InitializeConditions for MATLABSystem: '<Root>/Moving Average3'
}

//
// Output and update for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void fan_controllerModelClass::fan_controller_MovingAverage3(real_T rtu_0,
  B_MovingAverage3_fan_controll_T *localB, DW_MovingAverage3_fan_control_T
  *localDW)
{
  real_T cumRevIndex;
  real_T csum;
  real_T csumrev[15];
  real_T z;
  int32_T z_tmp;

  // MATLABSystem: '<Root>/Moving Average3'
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  if (localDW->obj.pStatistic->isInitialized != 1) {
    localDW->obj.pStatistic->isSetupComplete = false;
    localDW->obj.pStatistic->isInitialized = 1;
    localDW->obj.pStatistic->pCumSum = 0.0;
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
    localDW->obj.pStatistic->isSetupComplete = true;
    localDW->obj.pStatistic->pCumSum = 0.0;
    std::memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 15U * sizeof(real_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
  }

  cumRevIndex = localDW->obj.pStatistic->pCumRevIndex;
  csum = localDW->obj.pStatistic->pCumSum;
  for (z_tmp = 0; z_tmp < 15; z_tmp++) {
    csumrev[z_tmp] = localDW->obj.pStatistic->pCumSumRev[z_tmp];
  }

  csum += rtu_0;
  z_tmp = static_cast<int32_T>(cumRevIndex) - 1;
  z = csumrev[z_tmp] + csum;
  csumrev[z_tmp] = rtu_0;
  if (cumRevIndex != 15.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (z_tmp = 13; z_tmp >= 0; z_tmp--) {
      csumrev[z_tmp] += csumrev[z_tmp + 1];
    }
  }

  localDW->obj.pStatistic->pCumSum = csum;
  std::memcpy(&localDW->obj.pStatistic->pCumSumRev[0], &csumrev[0], 15U * sizeof
              (real_T));
  localDW->obj.pStatistic->pCumRevIndex = cumRevIndex;
  localB->MovingAverage3 = z / 16.0;

  // End of MATLABSystem: '<Root>/Moving Average3'
}

//
// Termination for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void fan_controllerModelClass::fan_control_MovingAverage3_Term
  (DW_MovingAverage3_fan_control_T *localDW)
{
  // Terminate for MATLABSystem: '<Root>/Moving Average3'
  matlabCodegenHandle_matlabCodeg(&localDW->obj);
}

// Model step function
void fan_controllerModelClass::step()
{
  // local block i/o variables
  real_T rtb_Humidityerror;
  real_T rtb_Diff;
  real_T rtb_Add1;
  real_T rtb_Diff_l;
  real_T rtb_Desiredventpower;
  real_T rtb_TSamp;
  real_T rtb_Gain;
  real_T rtb_TSamp_g;
  int32_T rtb_enabled;

  // Outport: '<Root>/Output enabled' incorporates:
  //   UnitDelay: '<Root>/Unit Delay'

  fan_controller_Y.Outputenabled = fan_controller_DW.UnitDelay_DSTATE;

  // ModelReference: '<Root>/Humidity baseline predictor' incorporates:
  //   Constant: '<Root>/Constant'
  //   Inport: '<Root>/Humidity sensor value'
  //   Outport: '<Root>/Humidity baseline'
  //   UnitDelay: '<Root>/Unit Delay'

  Humidity_baseline_prMDLOBJ1.step(&fan_controller_U.Humiditysensorvalue,
    &fan_controller_DW.UnitDelay_DSTATE, &fan_controller_P.Constant_Value_f,
    &fan_controller_Y.Humiditybaseline);

  // Sum: '<Root>/Add' incorporates:
  //   Inport: '<Root>/Humidity sensor value'
  //   Outport: '<Root>/Humidity baseline'

  rtb_Humidityerror = fan_controller_U.Humiditysensorvalue -
    fan_controller_Y.Humiditybaseline;
  fan_controller_MovingAverage3(rtb_Humidityerror,
    &fan_controller_B.MovingAverage, &fan_controller_DW.MovingAverage);

  // DownSample: '<Root>/Downsample1'
  if (fan_controller_DW.Downsample1_Count == 0) {
    rtb_Desiredventpower = fan_controller_B.MovingAverage.MovingAverage3;
  } else {
    rtb_Desiredventpower = fan_controller_DW.Downsample1_Buffer;
  }

  // End of DownSample: '<Root>/Downsample1'

  // SampleTimeMath: '<S1>/TSamp'
  //
  //  About '<S1>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //   Multiplication by K = weightedTsampQuantized is being
  //   done implicitly by changing the scaling of the input signal.
  //   No work needs to be done here.  Downstream blocks may need
  //   to do work to handle the scaling of the output; this happens
  //   automatically.

  rtb_TSamp = rtb_Desiredventpower;

  // Sum: '<S1>/Diff' incorporates:
  //   SampleTimeMath: '<S1>/TSamp'
  //   UnitDelay: '<S1>/UD'
  //
  //  About '<S1>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //   Multiplication by K = weightedTsampQuantized is being
  //   done implicitly by changing the scaling of the input signal.
  //   No work needs to be done here.  Downstream blocks may need
  //   to do work to handle the scaling of the output; this happens
  //   automatically.
  //
  //  Block description for '<S1>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  rtb_Diff = rtb_Desiredventpower - fan_controller_DW.UD_DSTATE;
  fan_controller_MovingAverage3(rtb_Diff, &fan_controller_B.MovingAverage2,
    &fan_controller_DW.MovingAverage2);

  // Gain: '<Root>/Gain'
  rtb_Gain = fan_controller_P.Gain_Gain *
    fan_controller_B.MovingAverage2.MovingAverage3;

  // Outport: '<Root>/Humidity change'
  fan_controller_Y.Humiditychange = rtb_Gain;

  // ModelReference: '<Root>/Humidity baseline predictor1' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Inport: '<Root>/Temperature sensor value'
  //   Outport: '<Root>/Temperature baseline'
  //   UnitDelay: '<Root>/Unit Delay'

  Humidity_baseline_prMDLOBJ2.step(&fan_controller_U.Temperaturesensorvalue,
    &fan_controller_DW.UnitDelay_DSTATE, &fan_controller_P.Constant1_Value,
    &fan_controller_Y.Temperaturebaseline);

  // Sum: '<Root>/Add1' incorporates:
  //   Inport: '<Root>/Temperature sensor value'
  //   Outport: '<Root>/Temperature baseline'

  rtb_Add1 = fan_controller_U.Temperaturesensorvalue -
    fan_controller_Y.Temperaturebaseline;
  fan_controller_MovingAverage3(rtb_Add1, &fan_controller_B.MovingAverage1,
    &fan_controller_DW.MovingAverage1);

  // DownSample: '<Root>/Downsample'
  if (fan_controller_DW.Downsample_Count == 0) {
    rtb_Desiredventpower = fan_controller_B.MovingAverage1.MovingAverage3;
  } else {
    rtb_Desiredventpower = fan_controller_DW.Downsample_Buffer;
  }

  // End of DownSample: '<Root>/Downsample'

  // SampleTimeMath: '<S2>/TSamp'
  //
  //  About '<S2>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //   Multiplication by K = weightedTsampQuantized is being
  //   done implicitly by changing the scaling of the input signal.
  //   No work needs to be done here.  Downstream blocks may need
  //   to do work to handle the scaling of the output; this happens
  //   automatically.

  rtb_TSamp_g = rtb_Desiredventpower;

  // Sum: '<S2>/Diff' incorporates:
  //   SampleTimeMath: '<S2>/TSamp'
  //   UnitDelay: '<S2>/UD'
  //
  //  About '<S2>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )
  //   Multiplication by K = weightedTsampQuantized is being
  //   done implicitly by changing the scaling of the input signal.
  //   No work needs to be done here.  Downstream blocks may need
  //   to do work to handle the scaling of the output; this happens
  //   automatically.
  //
  //  Block description for '<S2>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  rtb_Diff_l = rtb_Desiredventpower - fan_controller_DW.UD_DSTATE_l;
  fan_controller_MovingAverage3(rtb_Diff_l, &fan_controller_B.MovingAverage3,
    &fan_controller_DW.MovingAverage3);

  // Chart: '<Root>/States' incorporates:
  //   Outport: '<Root>/State ID'

  if (fan_controller_DW.is_active_c3_fan_controller == 0U) {
    fan_controller_DW.is_active_c3_fan_controller = 1U;

    // Outport: '<Root>/State ID'
    fan_controller_Y.StateID = StatesModeType_OFF;
    rtb_enabled = 0;
  } else {
    switch (fan_controller_Y.StateID) {
     case StatesModeType_OFF:
      rtb_enabled = 0;
      if (rtb_Gain > 4.0) {
        fan_controller_Y.StateID = StatesModeType_Detected;
        rtb_enabled = 1;
      }
      break;

     case StatesModeType_Detected:
      rtb_enabled = 1;
      if (rtb_Gain < -5.0) {
        fan_controller_Y.StateID = StatesModeType_OFF;
        rtb_enabled = 0;
      } else {
        if (rtb_Humidityerror > 10.0) {
          fan_controller_Y.StateID = StatesModeType_Stable;
        }
      }
      break;

     case StatesModeType_Stable:
      rtb_enabled = 1;
      if (rtb_Humidityerror < 8.0) {
        fan_controller_Y.StateID = StatesModeType_Stopping;
        rtb_enabled = 0;
      }
      break;

     default:
      // State Stopping
      fan_controller_Y.StateID = StatesModeType_OFF;
      rtb_enabled = 0;
      break;
    }
  }

  // End of Chart: '<Root>/States'

  // Outport: '<Root>/Temperature change' incorporates:
  //   Gain: '<Root>/Gain1'

  fan_controller_Y.Temperaturechange = fan_controller_P.Gain1_Gain *
    fan_controller_B.MovingAverage3.MovingAverage3;

  // MultiPortSwitch: '<S4>/Index Vector' incorporates:
  //   Constant: '<S4>/Constant'
  //   UnitDelay: '<Root>/Unit Delay'

  if (static_cast<int32_T>(fan_controller_DW.UnitDelay_DSTATE) == 0) {
    rtb_Desiredventpower = fan_controller_P.Constant_Value;
  } else {
    rtb_Desiredventpower = rtb_Humidityerror;
  }

  // End of MultiPortSwitch: '<S4>/Index Vector'

  // Saturate: '<S4>/Saturation'
  if (rtb_Desiredventpower > fan_controller_P.Saturation_UpperSat) {
    rtb_Desiredventpower = fan_controller_P.Saturation_UpperSat;
  } else {
    if (rtb_Desiredventpower < fan_controller_P.Saturation_LowerSat) {
      rtb_Desiredventpower = fan_controller_P.Saturation_LowerSat;
    }
  }

  // End of Saturate: '<S4>/Saturation'

  // Backlash: '<S4>/Backlash'
  rtb_Gain = fan_controller_P.Backlash_BacklashWidth / 2.0;
  if (rtb_Desiredventpower < fan_controller_DW.PrevY - rtb_Gain) {
    fan_controller_B.Backlash = rtb_Desiredventpower + rtb_Gain;
  } else if (rtb_Desiredventpower <= fan_controller_DW.PrevY + rtb_Gain) {
    fan_controller_B.Backlash = fan_controller_DW.PrevY;
  } else {
    fan_controller_B.Backlash = rtb_Desiredventpower - rtb_Gain;
  }

  // End of Backlash: '<S4>/Backlash'

  // Outport: '<Root>/Requested vent power level' incorporates:
  //   Quantizer: '<S4>/Quantizer'

  fan_controller_Y.Requestedventpowerlevel = rt_roundd_snf
    (fan_controller_B.Backlash / fan_controller_P.Quantizer_Interval) *
    fan_controller_P.Quantizer_Interval;

  // Update for UnitDelay: '<Root>/Unit Delay'
  fan_controller_DW.UnitDelay_DSTATE = rtb_enabled;

  // Update for DownSample: '<Root>/Downsample1'
  if (fan_controller_DW.Downsample1_Count == 0) {
    fan_controller_DW.Downsample1_Buffer =
      fan_controller_B.MovingAverage.MovingAverage3;
  }

  fan_controller_DW.Downsample1_Count++;
  if (fan_controller_DW.Downsample1_Count == 16) {
    fan_controller_DW.Downsample1_Count = 0;
  }

  // End of Update for DownSample: '<Root>/Downsample1'

  // Update for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  fan_controller_DW.UD_DSTATE = rtb_TSamp;

  // Update for DownSample: '<Root>/Downsample'
  if (fan_controller_DW.Downsample_Count == 0) {
    fan_controller_DW.Downsample_Buffer =
      fan_controller_B.MovingAverage1.MovingAverage3;
  }

  fan_controller_DW.Downsample_Count++;
  if (fan_controller_DW.Downsample_Count == 16) {
    fan_controller_DW.Downsample_Count = 0;
  }

  // End of Update for DownSample: '<Root>/Downsample'

  // Update for UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  fan_controller_DW.UD_DSTATE_l = rtb_TSamp_g;

  // Update for Backlash: '<S4>/Backlash'
  fan_controller_DW.PrevY = fan_controller_B.Backlash;
}

// Model initialize function
void fan_controllerModelClass::initialize()
{
  // Model Initialize function for ModelReference Block: '<Root>/Humidity baseline predictor' 

  // Set error status pointer for ModelReference Block: '<Root>/Humidity baseline predictor' 
  Humidity_baseline_prMDLOBJ1.setErrorStatusPointer(rtmGetErrorStatusPointer
    ((&fan_controller_M)));

  // Model Initialize function for ModelReference Block: '<Root>/Humidity baseline predictor1' 

  // Set error status pointer for ModelReference Block: '<Root>/Humidity baseline predictor1' 
  Humidity_baseline_prMDLOBJ2.setErrorStatusPointer(rtmGetErrorStatusPointer
    ((&fan_controller_M)));

  // InitializeConditions for UnitDelay: '<Root>/Unit Delay'
  fan_controller_DW.UnitDelay_DSTATE =
    fan_controller_P.UnitDelay_InitialCondition;

  // InitializeConditions for DownSample: '<Root>/Downsample1'
  fan_controller_DW.Downsample1_Count = 1;
  fan_controller_DW.Downsample1_Buffer = fan_controller_P.Downsample1_ic;

  // InitializeConditions for UnitDelay: '<S1>/UD'
  //
  //  Block description for '<S1>/UD':
  //
  //   Store in Global RAM

  fan_controller_DW.UD_DSTATE = fan_controller_P.DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for DownSample: '<Root>/Downsample'
  fan_controller_DW.Downsample_Count = 1;
  fan_controller_DW.Downsample_Buffer = fan_controller_P.Downsample_ic;

  // InitializeConditions for UnitDelay: '<S2>/UD'
  //
  //  Block description for '<S2>/UD':
  //
  //   Store in Global RAM

  fan_controller_DW.UD_DSTATE_l =
    fan_controller_P.DiscreteDerivative1_ICPrevScale;

  // InitializeConditions for Backlash: '<S4>/Backlash'
  fan_controller_DW.PrevY = fan_controller_P.Backlash_InitialOutput;

  // SystemInitialize for ModelReference: '<Root>/Humidity baseline predictor' incorporates:
  //   Constant: '<Root>/Constant'
  //   Inport: '<Root>/Humidity sensor value'
  //   Outport: '<Root>/Humidity baseline'
  //   UnitDelay: '<Root>/Unit Delay'

  Humidity_baseline_prMDLOBJ1.init();

  // SystemInitialize for ModelReference: '<Root>/Humidity baseline predictor1' incorporates:
  //   Constant: '<Root>/Constant1'
  //   Inport: '<Root>/Temperature sensor value'
  //   Outport: '<Root>/Temperature baseline'
  //   UnitDelay: '<Root>/Unit Delay'

  Humidity_baseline_prMDLOBJ2.init();

  // SystemInitialize for Outport: '<Root>/State ID' incorporates:
  //   Chart: '<Root>/States'

  fan_controller_Y.StateID = StatesModeType_None;
  fan_control_MovingAverage3_Init(&fan_controller_DW.MovingAverage);
  fan_control_MovingAverage3_Init(&fan_controller_DW.MovingAverage2);
  fan_control_MovingAverage3_Init(&fan_controller_DW.MovingAverage1);
  fan_control_MovingAverage3_Init(&fan_controller_DW.MovingAverage3);
}

// Model terminate function
void fan_controllerModelClass::terminate()
{
  fan_control_MovingAverage3_Term(&fan_controller_DW.MovingAverage);
  fan_control_MovingAverage3_Term(&fan_controller_DW.MovingAverage2);
  fan_control_MovingAverage3_Term(&fan_controller_DW.MovingAverage1);
  fan_control_MovingAverage3_Term(&fan_controller_DW.MovingAverage3);
}

// Constructor
fan_controllerModelClass::fan_controllerModelClass():
  fan_controller_U()
  ,fan_controller_Y()
  ,fan_controller_B()
  ,fan_controller_DW()
  ,fan_controller_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
fan_controllerModelClass::~fan_controllerModelClass()
{
  // Currently there is no destructor body generated.
}

// Block parameters get method
const fan_controllerModelClass::P_fan_controller_T & fan_controllerModelClass::
  getBlockParameters() const
{
  return fan_controller_P;
}

// Block parameters set method
void fan_controllerModelClass::setBlockParameters(const P_fan_controller_T
  *pfan_controller_P)
{
  fan_controller_P = *pfan_controller_P;
}

// Real-Time Model get method
fan_controllerModelClass::RT_MODEL_fan_controller_T * fan_controllerModelClass::
  getRTM()
{
  return (&fan_controller_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
