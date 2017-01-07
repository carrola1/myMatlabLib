/*
 * myBERToolMex_api.c
 *
 * Code generation for function 'myBERToolMex_api'
 *
 * C source code generated on: Mon Feb 25 08:35:27 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myBERToolMex.h"
#include "myBERToolMex_api.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[80000];
static real_T c_emlrt_marshallIn(const mxArray *HdTx, const char_T *identifier);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static real_T (*e_emlrt_marshallIn(const mxArray *HdRx, const char_T *identifier))
  [51];
static real_T (*emlrt_marshallIn(const mxArray *msgUpSamp, const char_T
  *identifier))[80000];
static real_T (*f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[51];
static real_T (*g_emlrt_marshallIn(const mxArray *HdInterp, const char_T
  *identifier))[43];
static real_T (*h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[43];
static real_T (*i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[80000];
static real_T j_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static real_T (*k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[51];
static real_T (*l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[43];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[80000]
{
  real_T (*y)[80000];
  y = i_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T c_emlrt_marshallIn(const mxArray *HdTx, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = d_emlrt_marshallIn(emlrtAlias(HdTx), &thisId);
  emlrtDestroyArray(&HdTx);
  return y;
}

static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = j_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const mxArray *HdRx, const char_T *identifier))
  [51]
{
  real_T (*y)[51];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = f_emlrt_marshallIn(emlrtAlias(HdRx), &thisId);
  emlrtDestroyArray(&HdRx);
  return y;
}
  static real_T (*emlrt_marshallIn(const mxArray *msgUpSamp, const char_T
  *identifier))[80000]
{
  real_T (*y)[80000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = b_emlrt_marshallIn(emlrtAlias(msgUpSamp), &thisId);
  emlrtDestroyArray(&msgUpSamp);
  return y;
}

static real_T (*f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[51]
{
  real_T (*y)[51];
  y = k_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*g_emlrt_marshallIn(const mxArray *HdInterp, const char_T
  *identifier))[43]
{
  real_T (*y)[43];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = h_emlrt_marshallIn(emlrtAlias(HdInterp), &thisId);
  emlrtDestroyArray(&HdInterp);
  return y;
}

static real_T (*h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[43]
{
  real_T (*y)[43];
  y = l_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*i_emlrt_marshallIn(const mxArray *src, const
  emlrtMsgIdentifier *msgId))[80000]
{
  real_T (*ret)[80000];
  int32_T iv6[2];
  int32_T i0;
  for (i0 = 0; i0 < 2; i0++) {
    iv6[i0] = 1 + 79999 * i0;
  }

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 2U,
    iv6);
  ret = (real_T (*)[80000])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T j_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*k_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[51]
{
  real_T (*ret)[51];
  int32_T iv7[2];
  int32_T i1;
  for (i1 = 0; i1 < 2; i1++) {
    iv7[i1] = 1 + 50 * i1;
  }

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 2U,
    iv7);
  ret = (real_T (*)[51])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*l_emlrt_marshallIn(const mxArray *src, const
  emlrtMsgIdentifier *msgId))[43]
{
  real_T (*ret)[43];
  int32_T iv8[2];
  int32_T i2;
  for (i2 = 0; i2 < 2; i2++) {
    iv8[i2] = 1 + 42 * i2;
  }

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", FALSE, 2U,
    iv8);
  ret = (real_T (*)[43])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void myBERToolMex_api(myBERToolMexStackData *SD, const mxArray * const prhs[5],
                      const mxArray *plhs[1])
{
  real_T (*msgUpSamp)[80000];
  real_T HdTx;
  real_T (*HdRx)[51];
  real_T (*HdInterp)[43];
  real_T snr;
  const mxArray *rxInterp;

  /* Marshall function inputs */
  msgUpSamp = emlrt_marshallIn(emlrtAlias(prhs[0]), "msgUpSamp");
  HdTx = c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "HdTx");
  HdRx = e_emlrt_marshallIn(emlrtAlias(prhs[2]), "HdRx");
  HdInterp = g_emlrt_marshallIn(emlrtAlias(prhs[3]), "HdInterp");
  snr = c_emlrt_marshallIn(emlrtAliasP(prhs[4]), "snr");

  /* Invoke the target function */
  rxInterp = myBERToolMex(SD, *msgUpSamp, HdTx, *HdRx, *HdInterp, snr);

  /* Marshall function outputs */
  plhs[0] = rxInterp;
}

/* End of code generation (myBERToolMex_api.c) */
