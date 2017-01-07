/*
 * myBERToolMex.c
 *
 * Code generation for function 'myBERToolMex'
 *
 * C source code generated on: Mon Feb 25 08:35:27 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myBERToolMex.h"
#include "filter.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7, "myBERToolMex",
  "//ohcincefs01/Space_IRAD/ACarroll/myMatlabLib/Simulation/myBERToolMex.m" };

static emlrtRSInfo b_emlrtRSI = { 9, "myBERToolMex",
  "//ohcincefs01/Space_IRAD/ACarroll/myMatlabLib/Simulation/myBERToolMex.m" };

static emlrtRSInfo c_emlrtRSI = { 12, "myBERToolMex",
  "//ohcincefs01/Space_IRAD/ACarroll/myMatlabLib/Simulation/myBERToolMex.m" };

static emlrtRSInfo d_emlrtRSI = { 13, "myBERToolMex",
  "//ohcincefs01/Space_IRAD/ACarroll/myMatlabLib/Simulation/myBERToolMex.m" };

static emlrtRSInfo e_emlrtRSI = { 5, "myBERToolMex",
  "//ohcincefs01/Space_IRAD/ACarroll/myMatlabLib/Simulation/myBERToolMex.m" };

static emlrtMCInfo emlrtMCI = { 7, 14, "myBERToolMex",
  "//ohcincefs01/Space_IRAD/ACarroll/myMatlabLib/Simulation/myBERToolMex.m" };

static emlrtMCInfo b_emlrtMCI = { 9, 14, "myBERToolMex",
  "//ohcincefs01/Space_IRAD/ACarroll/myMatlabLib/Simulation/myBERToolMex.m" };

static emlrtMCInfo c_emlrtMCI = { 13, 14, "myBERToolMex",
  "//ohcincefs01/Space_IRAD/ACarroll/myMatlabLib/Simulation/myBERToolMex.m" };

static emlrtMCInfo d_emlrtMCI = { 12, 14, "myBERToolMex",
  "//ohcincefs01/Space_IRAD/ACarroll/myMatlabLib/Simulation/myBERToolMex.m" };

/* Function Declarations */
static const mxArray *awgn(const mxArray *b, const mxArray *c, const mxArray *d,
  emlrtMCInfo *location);
static const mxArray *b_emlrt_marshallOut(real_T u);
static const mxArray *b_filter(const mxArray *b, const mxArray *c, const mxArray
  *d, emlrtMCInfo *location);
static const mxArray *c_emlrt_marshallOut(const char_T u[8]);
static const mxArray *d_emlrt_marshallOut(const real_T u[51]);
static const mxArray *e_emlrt_marshallOut(const real_T u[43]);
static const mxArray *emlrt_marshallOut(const real_T u[80000]);
static void upsample(const mxArray *b, const mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static const mxArray *awgn(const mxArray *b, const mxArray *c, const mxArray *d,
  emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m6;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m6, 3, pArrays, "awgn",
    TRUE, location);
}

static const mxArray *b_emlrt_marshallOut(real_T u)
{
  const mxArray *y;
  const mxArray *m2;
  y = NULL;
  m2 = mxCreateDoubleScalar(u);
  emlrtAssign(&y, m2);
  return y;
}

static const mxArray *b_filter(const mxArray *b, const mxArray *c, const mxArray
  *d, emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m7;
  pArrays[0] = b;
  pArrays[1] = c;
  pArrays[2] = d;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m7, 3, pArrays, "filter",
    TRUE, location);
}

static const mxArray *c_emlrt_marshallOut(const char_T u[8])
{
  const mxArray *y;
  static const int32_T iv3[2] = { 1, 8 };

  const mxArray *m3;
  y = NULL;
  m3 = mxCreateCharArray(2, iv3);
  emlrtInitCharArray(8, m3, u);
  emlrtAssign(&y, m3);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const real_T u[51])
{
  const mxArray *y;
  static const int32_T iv4[2] = { 1, 51 };

  const mxArray *m4;
  real_T (*pData)[];
  int32_T i;
  y = NULL;
  m4 = mxCreateNumericArray(2, (int32_T *)&iv4, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T (*)[])mxGetPr(m4);
  for (i = 0; i < 51; i++) {
    (*pData)[i] = u[i];
  }

  emlrtAssign(&y, m4);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const real_T u[43])
{
  const mxArray *y;
  static const int32_T iv5[2] = { 1, 43 };

  const mxArray *m5;
  real_T (*pData)[];
  int32_T i;
  y = NULL;
  m5 = mxCreateNumericArray(2, (int32_T *)&iv5, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T (*)[])mxGetPr(m5);
  for (i = 0; i < 43; i++) {
    (*pData)[i] = u[i];
  }

  emlrtAssign(&y, m5);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[80000])
{
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 80000 };

  const mxArray *m1;
  real_T (*pData)[];
  int32_T i;
  y = NULL;
  m1 = mxCreateNumericArray(2, (int32_T *)&iv2, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T (*)[])mxGetPr(m1);
  for (i = 0; i < 80000; i++) {
    (*pData)[i] = u[i];
  }

  emlrtAssign(&y, m1);
  return y;
}

static void upsample(const mxArray *b, const mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 2, pArrays, "upsample",
                        TRUE, location);
}

const mxArray *myBERToolMex(myBERToolMexStackData *SD, const real_T msgUpSamp
  [80000], real_T HdTx, const real_T HdRx[51], const real_T HdInterp[43], real_T
  snr)
{
  const mxArray *rxInterp;
  static const char_T cv0[8] = { 'm', 'e', 'a', 's', 'u', 'r', 'e', 'd' };

  const mxArray *chlsig = NULL;
  const mxArray *rxFilt = NULL;
  rxInterp = NULL;
  emlrtPushRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);
  filter(HdTx, msgUpSamp, SD->f0.msgFilt);
  emlrtPopRtStackR2012b(&e_emlrtRSI, emlrtRootTLSGlobal);

  /*  TX FIR Filter */
  emlrtPushRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);
  emlrtAssign(&chlsig, awgn(emlrt_marshallOut(SD->f0.msgFilt),
    b_emlrt_marshallOut(snr), c_emlrt_marshallOut(cv0), &emlrtMCI));
  emlrtPopRtStackR2012b(&emlrtRSI, emlrtRootTLSGlobal);

  /*  Add noise */
  emlrtPushRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);
  emlrtAssign(&rxFilt, b_filter(d_emlrt_marshallOut(HdRx), b_emlrt_marshallOut
    (1.0), emlrtAlias(chlsig), &b_emlrtMCI));
  emlrtPopRtStackR2012b(&b_emlrtRSI, emlrtRootTLSGlobal);

  /*  RX FIR Filter */
  /*  Interpolate and adjust for delay */
  emlrtPushRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
  upsample(emlrtAlias(rxFilt), b_emlrt_marshallOut(10.0), &d_emlrtMCI);
  emlrtPopRtStackR2012b(&c_emlrtRSI, emlrtRootTLSGlobal);
  emlrtPushRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  emlrtAssign(&rxInterp, b_filter(e_emlrt_marshallOut(HdInterp),
    b_emlrt_marshallOut(1.0), emlrtAlias(rxFilt), &c_emlrtMCI));
  emlrtPopRtStackR2012b(&d_emlrtRSI, emlrtRootTLSGlobal);
  emlrtDestroyArray(&chlsig);
  emlrtDestroyArray(&rxFilt);
  return rxInterp;
}

/* End of code generation (myBERToolMex.c) */
