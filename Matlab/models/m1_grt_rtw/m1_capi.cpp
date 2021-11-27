/*
 * m1_capi.cpp
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

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "m1_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "m1.h"
#include "m1_capi.h"
#include "m1_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

static rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 0, TARGET_STRING("m1/Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 1, TARGET_STRING("m1/Gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 2, TARGET_STRING("m1/IC"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 3, TARGET_STRING("m1/IC1"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 4, TARGET_STRING("m1/Downsample"),
    TARGET_STRING("ic"), 0, 0, 0 },

  { 5, TARGET_STRING("m1/Downsample1"),
    TARGET_STRING("ic"), 0, 0, 0 },

  { 6, TARGET_STRING("m1/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 7, TARGET_STRING("m1/Baseline predictor filter/Downsample"),
    TARGET_STRING("ic"), 0, 0, 0 },

  { 8, TARGET_STRING("m1/Baseline predictor filter/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 9, TARGET_STRING("m1/Baseline predictor filter1/Downsample"),
    TARGET_STRING("ic"), 0, 0, 0 },

  { 10, TARGET_STRING("m1/Baseline predictor filter1/Unit Delay"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 11, TARGET_STRING("m1/Vent power control/Backlash"),
    TARGET_STRING("BacklashWidth"), 0, 0, 0 },

  { 12, TARGET_STRING("m1/Vent power control/Backlash"),
    TARGET_STRING("InitialOutput"), 0, 0, 0 },

  { 13, TARGET_STRING("m1/Vent power control/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 14, TARGET_STRING("m1/Vent power control/Quantizer"),
    TARGET_STRING("QuantizationInterval"), 0, 0, 0 },

  { 15, TARGET_STRING("m1/Vent power control/Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 16, TARGET_STRING("m1/Vent power control/Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Block states information */
static rtwCAPI_States rtBlockStates[] = {
  /* addrMapIndex, contStateStartIndex, blockPath,
   * stateName, pathAlias, dWorkIndex, dataTypeIndex, dimIndex,
   * fixPtIdx, sTimeIndex, isContinuous, hierInfoIdx, flatElemIdx
   */
  { 17, -1, TARGET_STRING("m1/Unit Delay"),
    TARGET_STRING("DSTATE"), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  { 18, -1, TARGET_STRING("m1/Baseline predictor filter/Unit Delay"),
    TARGET_STRING("DSTATE"), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  { 19, -1, TARGET_STRING("m1/Baseline predictor filter1/Unit Delay"),
    TARGET_STRING("DSTATE"), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  { 20, -1, TARGET_STRING("m1/Discrete Derivative/UD"),
    TARGET_STRING("DSTATE"), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  { 21, -1, TARGET_STRING("m1/Discrete Derivative1/UD"),
    TARGET_STRING("DSTATE"), "", 0, 0, 0, 0, 0, 0, -1, 0 },

  {
    0, -1, (NULL), (NULL), (NULL), 0, 0, 0, 0, 0, 0, -1, 0
  }
};

/* Tunable variable parameters */
static rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 22, TARGET_STRING("initial_h"), 0, 0, 0 },

  { 23, TARGET_STRING("initial_t"), 0, 0, 0 },

  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Initialize Data Address */
static void m1_InitializeDataAddr(void* dataAddr[], P_m1_T *m1_P, DW_m1_T *m1_DW)
{
  dataAddr[0] = (void*) (&m1_P->Gain_Gain);
  dataAddr[1] = (void*) (&m1_P->Gain1_Gain);
  dataAddr[2] = (void*) (&m1_P->IC_Value);
  dataAddr[3] = (void*) (&m1_P->IC1_Value);
  dataAddr[4] = (void*) (&m1_P->Downsample_ic_l);
  dataAddr[5] = (void*) (&m1_P->Downsample1_ic);
  dataAddr[6] = (void*) (&m1_P->UnitDelay_InitialCondition);
  dataAddr[7] = (void*) (&m1_P->Downsample_ic);
  dataAddr[8] = (void*) (&m1_P->UnitDelay_InitialCondition_p);
  dataAddr[9] = (void*) (&m1_P->Downsample_ic_p);
  dataAddr[10] = (void*) (&m1_P->UnitDelay_InitialCondition_e);
  dataAddr[11] = (void*) (&m1_P->Backlash_BacklashWidth);
  dataAddr[12] = (void*) (&m1_P->Backlash_InitialOutput);
  dataAddr[13] = (void*) (&m1_P->Constant_Value);
  dataAddr[14] = (void*) (&m1_P->Quantizer_Interval);
  dataAddr[15] = (void*) (&m1_P->Saturation_UpperSat);
  dataAddr[16] = (void*) (&m1_P->Saturation_LowerSat);
  dataAddr[17] = (void*) (&m1_DW->UnitDelay_DSTATE);
  dataAddr[18] = (void*) (&m1_DW->UnitDelay_DSTATE_o);
  dataAddr[19] = (void*) (&m1_DW->UnitDelay_DSTATE_k);
  dataAddr[20] = (void*) (&m1_DW->UD_DSTATE);
  dataAddr[21] = (void*) (&m1_DW->UD_DSTATE_n);
  dataAddr[22] = (void*) (&m1_P->initial_h);
  dataAddr[23] = (void*) (&m1_P->initial_t);
}

#endif

/* Initialize Data Run-Time Dimension Buffer Address */
#ifndef HOST_CAPI_BUILD

static void m1_InitializeVarDimsAddr(int32_T* vardimsAddr[])
{
  vardimsAddr[0] = (NULL);
}

#endif

#ifndef HOST_CAPI_BUILD

/* Initialize logging function pointers */
static void m1_InitializeLoggingFunctions(RTWLoggingFcnPtr loggingPtrs[])
{
  loggingPtrs[0] = (NULL);
  loggingPtrs[1] = (NULL);
  loggingPtrs[2] = (NULL);
  loggingPtrs[3] = (NULL);
  loggingPtrs[4] = (NULL);
  loggingPtrs[5] = (NULL);
  loggingPtrs[6] = (NULL);
  loggingPtrs[7] = (NULL);
  loggingPtrs[8] = (NULL);
  loggingPtrs[9] = (NULL);
  loggingPtrs[10] = (NULL);
  loggingPtrs[11] = (NULL);
  loggingPtrs[12] = (NULL);
  loggingPtrs[13] = (NULL);
  loggingPtrs[14] = (NULL);
  loggingPtrs[15] = (NULL);
  loggingPtrs[16] = (NULL);
  loggingPtrs[17] = (NULL);
  loggingPtrs[18] = (NULL);
  loggingPtrs[19] = (NULL);
  loggingPtrs[20] = (NULL);
  loggingPtrs[21] = (NULL);
  loggingPtrs[22] = (NULL);
  loggingPtrs[23] = (NULL);
}

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer, enumStorageType */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1                                    /* 1 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  1.0, 0.0
};

/* Fixed Point Map */
static rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { static_cast<const void *>(&rtcapiStoredFloats[0]), static_cast<const void *>
    (&rtcapiStoredFloats[1]), 0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { (NULL), 0,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 17,
    rtModelParameters, 2 },

  { rtBlockStates, 5 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1235920427U,
    2475299645U,
    3628168922U,
    2912111513U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  m1_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void m1_InitializeDataMapInfo(RT_MODEL_m1_T *const m1_M, P_m1_T *m1_P, DW_m1_T
  *m1_DW)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(m1_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(m1_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(m1_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  m1_InitializeDataAddr(m1_M->DataMapInfo.dataAddress, m1_P, m1_DW);
  rtwCAPI_SetDataAddressMap(m1_M->DataMapInfo.mmi, m1_M->DataMapInfo.dataAddress);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  m1_InitializeVarDimsAddr(m1_M->DataMapInfo.vardimsAddress);
  rtwCAPI_SetVarDimsAddressMap(m1_M->DataMapInfo.mmi,
    m1_M->DataMapInfo.vardimsAddress);

  /* Set Instance specific path */
  rtwCAPI_SetPath(m1_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetFullPath(m1_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API logging function pointers into the Real-Time Model Data structure */
  m1_InitializeLoggingFunctions(m1_M->DataMapInfo.loggingPtrs);
  rtwCAPI_SetLoggingPtrs(m1_M->DataMapInfo.mmi, m1_M->DataMapInfo.loggingPtrs);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(m1_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(m1_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(m1_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void m1_host_InitializeDataMapInfo(m1_host_DataMapInfo_T *dataMap, const char *
    path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: m1_capi.cpp */
