/*
 * m1_data.cpp
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

#include "m1.h"
#include "m1_private.h"

/* Block parameters (default storage) */
P_m1_T m1ModelClass::m1_P = {
  /* Variable: initial_h
   * Referenced by: '<S3>/UD'
   */
  49.6,

  /* Variable: initial_t
   * Referenced by: '<S4>/UD'
   */
  24.4,

  /* Expression: 0
   * Referenced by: '<S6>/Constant'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Unit Delay'
   */
  0.0,

  /* Expression: 50
   * Referenced by: '<Root>/IC'
   */
  50.0,

  /* Expression: 0
   * Referenced by: '<S1>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Downsample'
   */
  0.0,

  /* Expression: initial_h
   * Referenced by: '<Root>/Downsample1'
   */
  49.6,

  /* Expression: 16
   * Referenced by: '<Root>/Gain'
   */
  16.0,

  /* Expression: 25
   * Referenced by: '<Root>/IC1'
   */
  25.0,

  /* Expression: 0
   * Referenced by: '<S2>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Downsample'
   */
  0.0,

  /* Expression: initial_t
   * Referenced by: '<Root>/Downsample'
   */
  24.4,

  /* Expression: 16
   * Referenced by: '<Root>/Gain1'
   */
  16.0,

  /* Expression: 30
   * Referenced by: '<S6>/Saturation'
   */
  30.0,

  /* Expression: 0
   * Referenced by: '<S6>/Saturation'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S6>/Backlash'
   */
  2.0,

  /* Expression: 0
   * Referenced by: '<S6>/Backlash'
   */
  0.0,

  /* Expression: 30/4
   * Referenced by: '<S6>/Quantizer'
   */
  7.5
};
