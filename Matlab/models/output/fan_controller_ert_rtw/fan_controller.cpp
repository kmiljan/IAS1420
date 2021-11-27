//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: fan_controller.cpp
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

real_T fan_controllerModelClass::SlidingWindowAverageCG_stepImpl
  (g_dsp_private_SlidingWindow_h_T *obj, real_T u)
{
  real_T y;
  real_T cumRevIndex;
  real_T csum;
  real_T csumrev[511];
  real_T z;
  int32_T z_tmp;
  std::memcpy(&csumrev[0], &obj->pCumSumRev[0], 511U * sizeof(real_T));
  csum = obj->pCumSum + u;
  z_tmp = static_cast<int32_T>(obj->pCumRevIndex) - 1;
  z = obj->pCumSumRev[z_tmp] + csum;
  csumrev[z_tmp] = u;
  if (obj->pCumRevIndex != 511.0) {
    cumRevIndex = obj->pCumRevIndex + 1.0;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    for (z_tmp = 509; z_tmp >= 0; z_tmp--) {
      csumrev[z_tmp] += csumrev[z_tmp + 1];
    }
  }

  y = z / 512.0;
  obj->pCumSum = csum;
  std::memcpy(&obj->pCumSumRev[0], &csumrev[0], 511U * sizeof(real_T));
  obj->pCumRevIndex = cumRevIndex;
  return y;
}

void fan_controllerModelClass::fan_contro_SystemCore_release_m
  (dsp_simulink_MovingAverage_e_T *obj)
{
  g_dsp_private_SlidingWindow_h_T *obj_0;
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    obj_0 = obj->pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->isInitialized = 2;
    }

    obj->NumChannels = -1;
  }
}

void fan_controllerModelClass::fan_control_SystemCore_delete_a
  (dsp_simulink_MovingAverage_e_T *obj)
{
  fan_contro_SystemCore_release_m(obj);
}

void fan_controllerModelClass::matlabCodegenHandle_matlabCod_g
  (dsp_simulink_MovingAverage_e_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    fan_control_SystemCore_delete_a(obj);
  }
}

//
// System initialize for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void fan_controllerModelClass::fan_contr_MovingAverage3_c_Init
  (DW_MovingAverage3_fan_contr_f_T *localDW)
{
  // Start for MATLABSystem: '<S1>/Moving Average3'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.NumChannels = 1;
  localDW->gobj_2.isInitialized = 0;
  localDW->obj.pStatistic = &localDW->gobj_2;
  localDW->obj.isSetupComplete = true;
  localDW->obj.TunablePropsChanged = false;

  // InitializeConditions for MATLABSystem: '<S1>/Moving Average3'
  if (localDW->obj.pStatistic->isInitialized == 1) {
    localDW->obj.pStatistic->pCumSum = 0.0;
    std::memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 511U * sizeof(real_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
  }

  // End of InitializeConditions for MATLABSystem: '<S1>/Moving Average3'
}

//
// Output and update for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void fan_controllerModelClass::fan_controller_MovingAverage3_p(real_T rtu_0,
  B_MovingAverage3_fan_contro_c_T *localB, DW_MovingAverage3_fan_contr_f_T
  *localDW)
{
  // MATLABSystem: '<S1>/Moving Average3'
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
    std::memset(&localDW->obj.pStatistic->pCumSumRev[0], 0, 511U * sizeof(real_T));
    localDW->obj.pStatistic->pCumRevIndex = 1.0;
  }

  localB->MovingAverage3 = SlidingWindowAverageCG_stepImpl
    (localDW->obj.pStatistic, rtu_0);

  // End of MATLABSystem: '<S1>/Moving Average3'
}

//
// Termination for atomic system:
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//    synthesized block
//
void fan_controllerModelClass::fan_contr_MovingAverage3_a_Term
  (DW_MovingAverage3_fan_contr_f_T *localDW)
{
  // Terminate for MATLABSystem: '<S1>/Moving Average3'
  matlabCodegenHandle_matlabCod_g(&localDW->obj);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

// Model step function
void fan_controllerModelClass::step()
{
  // local block i/o variables
  real_T rtb_Downsample;
  real_T rtb_Humidityerror;
  real_T rtb_Diff;
  real_T rtb_Downsample_p;
  real_T rtb_Add1;
  real_T rtb_Diff_l;
  real_T halfDeadBand;
  real_T rtb_TSamp;
  real_T rtb_Gain;
  real_T rtb_TSamp_g;
  int32_T rtb_enabled;

  // Outport: '<Root>/Output enabled' incorporates:
  //   UnitDelay: '<Root>/Unit Delay'

  fan_controller_Y.Outputenabled = fan_controller_DW.UnitDelay_DSTATE;

  // MultiPortSwitch: '<S1>/Index Vector' incorporates:
  //   Inport: '<Root>/Humidity sensor value'
  //   UnitDelay: '<Root>/Unit Delay'
  //   UnitDelay: '<S1>/Unit Delay'

  if (static_cast<int32_T>(fan_controller_DW.UnitDelay_DSTATE) == 0) {
    fan_controller_B.IndexVector = fan_controller_U.Humiditysensorvalue;
  } else {
    fan_controller_B.IndexVector = fan_controller_DW.UnitDelay_DSTATE_e;
  }

  // End of MultiPortSwitch: '<S1>/Index Vector'

  // DownSample: '<S1>/Downsample'
  if (fan_controller_DW.Downsample_Count == 0) {
    rtb_Downsample = fan_controller_B.IndexVector;
  } else {
    rtb_Downsample = fan_controller_DW.Downsample_Buffer;
  }

  // End of DownSample: '<S1>/Downsample'
  fan_controller_MovingAverage3_p(rtb_Downsample,
    &fan_controller_B.MovingAverage_p, &fan_controller_DW.MovingAverage_p);
  fan_controller_MovingAverage3_p
    (fan_controller_B.MovingAverage_p.MovingAverage3,
     &fan_controller_B.MovingAverage1_p, &fan_controller_DW.MovingAverage1_p);
  fan_controller_MovingAverage3_p
    (fan_controller_B.MovingAverage1_p.MovingAverage3,
     &fan_controller_B.MovingAverage2_p, &fan_controller_DW.MovingAverage2_p);
  fan_controller_MovingAverage3_p
    (fan_controller_B.MovingAverage2_p.MovingAverage3,
     &fan_controller_B.MovingAverage3_p, &fan_controller_DW.MovingAverage3_p);

  // Sum: '<Root>/Add' incorporates:
  //   Inport: '<Root>/Humidity sensor value'

  rtb_Humidityerror = fan_controller_U.Humiditysensorvalue -
    fan_controller_B.MovingAverage3_p.MovingAverage3;
  fan_controller_MovingAverage3(rtb_Humidityerror,
    &fan_controller_B.MovingAverage, &fan_controller_DW.MovingAverage);

  // DownSample: '<Root>/Downsample1'
  if (fan_controller_DW.Downsample1_Count == 0) {
    rtb_TSamp_g = fan_controller_B.MovingAverage.MovingAverage3;
  } else {
    rtb_TSamp_g = fan_controller_DW.Downsample1_Buffer;
  }

  // End of DownSample: '<Root>/Downsample1'

  // SampleTimeMath: '<S3>/TSamp'
  //
  //  About '<S3>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp = rtb_TSamp_g * fan_controller_P.TSamp_WtEt;

  // Sum: '<S3>/Diff' incorporates:
  //   UnitDelay: '<S3>/UD'
  //
  //  Block description for '<S3>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  rtb_Diff = rtb_TSamp - fan_controller_DW.UD_DSTATE;
  fan_controller_MovingAverage3(rtb_Diff, &fan_controller_B.MovingAverage2,
    &fan_controller_DW.MovingAverage2);

  // Gain: '<Root>/Gain'
  rtb_Gain = fan_controller_P.Gain_Gain *
    fan_controller_B.MovingAverage2.MovingAverage3;

  // MultiPortSwitch: '<S2>/Index Vector' incorporates:
  //   Inport: '<Root>/Temperature sensor value'
  //   UnitDelay: '<Root>/Unit Delay'
  //   UnitDelay: '<S2>/Unit Delay'

  if (static_cast<int32_T>(fan_controller_DW.UnitDelay_DSTATE) == 0) {
    fan_controller_B.IndexVector_n = fan_controller_U.Temperaturesensorvalue;
  } else {
    fan_controller_B.IndexVector_n = fan_controller_DW.UnitDelay_DSTATE_i;
  }

  // End of MultiPortSwitch: '<S2>/Index Vector'

  // DownSample: '<S2>/Downsample'
  if (fan_controller_DW.Downsample_Count_a == 0) {
    rtb_Downsample_p = fan_controller_B.IndexVector_n;
  } else {
    rtb_Downsample_p = fan_controller_DW.Downsample_Buffer_l;
  }

  // End of DownSample: '<S2>/Downsample'
  fan_controller_MovingAverage3_p(rtb_Downsample_p,
    &fan_controller_B.MovingAverage_pn, &fan_controller_DW.MovingAverage_pn);
  fan_controller_MovingAverage3_p
    (fan_controller_B.MovingAverage_pn.MovingAverage3,
     &fan_controller_B.MovingAverage1_pn, &fan_controller_DW.MovingAverage1_pn);
  fan_controller_MovingAverage3_p
    (fan_controller_B.MovingAverage1_pn.MovingAverage3,
     &fan_controller_B.MovingAverage2_pn, &fan_controller_DW.MovingAverage2_pn);
  fan_controller_MovingAverage3_p
    (fan_controller_B.MovingAverage2_pn.MovingAverage3,
     &fan_controller_B.MovingAverage3_pn, &fan_controller_DW.MovingAverage3_pn);

  // Sum: '<Root>/Add1' incorporates:
  //   Inport: '<Root>/Temperature sensor value'

  rtb_Add1 = fan_controller_U.Temperaturesensorvalue -
    fan_controller_B.MovingAverage3_pn.MovingAverage3;
  fan_controller_MovingAverage3(rtb_Add1, &fan_controller_B.MovingAverage1,
    &fan_controller_DW.MovingAverage1);

  // DownSample: '<Root>/Downsample'
  if (fan_controller_DW.Downsample_Count_g == 0) {
    rtb_TSamp_g = fan_controller_B.MovingAverage1.MovingAverage3;
  } else {
    rtb_TSamp_g = fan_controller_DW.Downsample_Buffer_i;
  }

  // End of DownSample: '<Root>/Downsample'

  // SampleTimeMath: '<S4>/TSamp'
  //
  //  About '<S4>/TSamp':
  //   y = u * K where K = 1 / ( w * Ts )

  rtb_TSamp_g *= fan_controller_P.TSamp_WtEt_l;

  // Sum: '<S4>/Diff' incorporates:
  //   UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S4>/Diff':
  //
  //   Add in CPU
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  rtb_Diff_l = rtb_TSamp_g - fan_controller_DW.UD_DSTATE_l;
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

  // Outport: '<Root>/Temperature baseline'
  fan_controller_Y.Temperaturebaseline =
    fan_controller_B.MovingAverage3_pn.MovingAverage3;

  // Outport: '<Root>/Humidity change'
  fan_controller_Y.Humiditychange = rtb_Gain;

  // MultiPortSwitch: '<S6>/Index Vector' incorporates:
  //   Constant: '<S6>/Constant'
  //   UnitDelay: '<Root>/Unit Delay'

  if (static_cast<int32_T>(fan_controller_DW.UnitDelay_DSTATE) == 0) {
    rtb_Gain = fan_controller_P.Constant_Value;
  } else {
    rtb_Gain = rtb_Humidityerror;
  }

  // End of MultiPortSwitch: '<S6>/Index Vector'

  // Saturate: '<S6>/Saturation'
  if (rtb_Gain > fan_controller_P.Saturation_UpperSat) {
    rtb_Gain = fan_controller_P.Saturation_UpperSat;
  } else {
    if (rtb_Gain < fan_controller_P.Saturation_LowerSat) {
      rtb_Gain = fan_controller_P.Saturation_LowerSat;
    }
  }

  // End of Saturate: '<S6>/Saturation'

  // Backlash: '<S6>/Backlash'
  halfDeadBand = fan_controller_P.Backlash_BacklashWidth / 2.0;
  if (rtb_Gain < fan_controller_DW.PrevY - halfDeadBand) {
    fan_controller_B.Backlash = rtb_Gain + halfDeadBand;
  } else if (rtb_Gain <= fan_controller_DW.PrevY + halfDeadBand) {
    fan_controller_B.Backlash = fan_controller_DW.PrevY;
  } else {
    fan_controller_B.Backlash = rtb_Gain - halfDeadBand;
  }

  // End of Backlash: '<S6>/Backlash'

  // Outport: '<Root>/Requested vent power level' incorporates:
  //   Quantizer: '<S6>/Quantizer'

  fan_controller_Y.Requestedventpowerlevel = rt_roundd_snf
    (fan_controller_B.Backlash / fan_controller_P.Quantizer_Interval) *
    fan_controller_P.Quantizer_Interval;

  // Outport: '<Root>/Humidity baseline'
  fan_controller_Y.Humiditybaseline =
    fan_controller_B.MovingAverage3_p.MovingAverage3;

  // Update for UnitDelay: '<Root>/Unit Delay'
  fan_controller_DW.UnitDelay_DSTATE = rtb_enabled;

  // Update for UnitDelay: '<S1>/Unit Delay'
  fan_controller_DW.UnitDelay_DSTATE_e =
    fan_controller_B.MovingAverage3_p.MovingAverage3;

  // Update for DownSample: '<S1>/Downsample'
  if (fan_controller_DW.Downsample_Count == 0) {
    fan_controller_DW.Downsample_Buffer = fan_controller_B.IndexVector;
  }

  fan_controller_DW.Downsample_Count++;
  if (fan_controller_DW.Downsample_Count == 128) {
    fan_controller_DW.Downsample_Count = 0;
  }

  // End of Update for DownSample: '<S1>/Downsample'

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

  // Update for UnitDelay: '<S3>/UD'
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  fan_controller_DW.UD_DSTATE = rtb_TSamp;

  // Update for UnitDelay: '<S2>/Unit Delay'
  fan_controller_DW.UnitDelay_DSTATE_i =
    fan_controller_B.MovingAverage3_pn.MovingAverage3;

  // Update for DownSample: '<S2>/Downsample'
  if (fan_controller_DW.Downsample_Count_a == 0) {
    fan_controller_DW.Downsample_Buffer_l = fan_controller_B.IndexVector_n;
  }

  fan_controller_DW.Downsample_Count_a++;
  if (fan_controller_DW.Downsample_Count_a == 128) {
    fan_controller_DW.Downsample_Count_a = 0;
  }

  // End of Update for DownSample: '<S2>/Downsample'

  // Update for DownSample: '<Root>/Downsample'
  if (fan_controller_DW.Downsample_Count_g == 0) {
    fan_controller_DW.Downsample_Buffer_i =
      fan_controller_B.MovingAverage1.MovingAverage3;
  }

  fan_controller_DW.Downsample_Count_g++;
  if (fan_controller_DW.Downsample_Count_g == 16) {
    fan_controller_DW.Downsample_Count_g = 0;
  }

  // End of Update for DownSample: '<Root>/Downsample'

  // Update for UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  fan_controller_DW.UD_DSTATE_l = rtb_TSamp_g;

  // Update for Backlash: '<S6>/Backlash'
  fan_controller_DW.PrevY = fan_controller_B.Backlash;
}

// Model initialize function
void fan_controllerModelClass::initialize()
{
  // InitializeConditions for UnitDelay: '<Root>/Unit Delay'
  fan_controller_DW.UnitDelay_DSTATE =
    fan_controller_P.UnitDelay_InitialCondition;

  // InitializeConditions for UnitDelay: '<S1>/Unit Delay'
  fan_controller_DW.UnitDelay_DSTATE_e =
    fan_controller_P.UnitDelay_InitialCondition_j;

  // InitializeConditions for DownSample: '<S1>/Downsample'
  fan_controller_DW.Downsample_Buffer = fan_controller_P.Downsample_ic;

  // InitializeConditions for DownSample: '<Root>/Downsample1'
  fan_controller_DW.Downsample1_Count = 1;
  fan_controller_DW.Downsample1_Buffer = fan_controller_P.Downsample1_ic;

  // InitializeConditions for UnitDelay: '<S3>/UD'
  //
  //  Block description for '<S3>/UD':
  //
  //   Store in Global RAM

  fan_controller_DW.UD_DSTATE = fan_controller_P.DiscreteDerivative_ICPrevScaled;

  // InitializeConditions for UnitDelay: '<S2>/Unit Delay'
  fan_controller_DW.UnitDelay_DSTATE_i =
    fan_controller_P.UnitDelay_InitialCondition_i;

  // InitializeConditions for DownSample: '<S2>/Downsample'
  fan_controller_DW.Downsample_Buffer_l = fan_controller_P.Downsample_ic_e;

  // InitializeConditions for DownSample: '<Root>/Downsample'
  fan_controller_DW.Downsample_Count_g = 1;
  fan_controller_DW.Downsample_Buffer_i = fan_controller_P.Downsample_ic_j;

  // InitializeConditions for UnitDelay: '<S4>/UD'
  //
  //  Block description for '<S4>/UD':
  //
  //   Store in Global RAM

  fan_controller_DW.UD_DSTATE_l =
    fan_controller_P.DiscreteDerivative1_ICPrevScale;

  // InitializeConditions for Backlash: '<S6>/Backlash'
  fan_controller_DW.PrevY = fan_controller_P.Backlash_InitialOutput;

  // SystemInitialize for Outport: '<Root>/State ID' incorporates:
  //   Chart: '<Root>/States'

  fan_controller_Y.StateID = StatesModeType_None;
  fan_contr_MovingAverage3_c_Init(&fan_controller_DW.MovingAverage_p);
  fan_contr_MovingAverage3_c_Init(&fan_controller_DW.MovingAverage1_p);
  fan_contr_MovingAverage3_c_Init(&fan_controller_DW.MovingAverage2_p);
  fan_contr_MovingAverage3_c_Init(&fan_controller_DW.MovingAverage3_p);
  fan_control_MovingAverage3_Init(&fan_controller_DW.MovingAverage);
  fan_control_MovingAverage3_Init(&fan_controller_DW.MovingAverage2);
  fan_contr_MovingAverage3_c_Init(&fan_controller_DW.MovingAverage_pn);
  fan_contr_MovingAverage3_c_Init(&fan_controller_DW.MovingAverage1_pn);
  fan_contr_MovingAverage3_c_Init(&fan_controller_DW.MovingAverage2_pn);
  fan_contr_MovingAverage3_c_Init(&fan_controller_DW.MovingAverage3_pn);
  fan_control_MovingAverage3_Init(&fan_controller_DW.MovingAverage1);
  fan_control_MovingAverage3_Init(&fan_controller_DW.MovingAverage3);
}

// Model terminate function
void fan_controllerModelClass::terminate()
{
  fan_contr_MovingAverage3_a_Term(&fan_controller_DW.MovingAverage_p);
  fan_contr_MovingAverage3_a_Term(&fan_controller_DW.MovingAverage1_p);
  fan_contr_MovingAverage3_a_Term(&fan_controller_DW.MovingAverage2_p);
  fan_contr_MovingAverage3_a_Term(&fan_controller_DW.MovingAverage3_p);
  fan_control_MovingAverage3_Term(&fan_controller_DW.MovingAverage);
  fan_control_MovingAverage3_Term(&fan_controller_DW.MovingAverage2);
  fan_contr_MovingAverage3_a_Term(&fan_controller_DW.MovingAverage_pn);
  fan_contr_MovingAverage3_a_Term(&fan_controller_DW.MovingAverage1_pn);
  fan_contr_MovingAverage3_a_Term(&fan_controller_DW.MovingAverage2_pn);
  fan_contr_MovingAverage3_a_Term(&fan_controller_DW.MovingAverage3_pn);
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
