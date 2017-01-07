/*
 * filter.c
 *
 * Code generation for function 'filter'
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
static emlrtRSInfo f_emlrtRSI = { 140, "filter",
  "C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/datafun/filter.m" };

static emlrtRSInfo g_emlrtRSI = { 144, "filter",
  "C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/datafun/filter.m" };

static emlrtRSInfo h_emlrtRSI = { 11, "eml_int_forloop_overflow_check",
  "C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo i_emlrtRSI = { 49, "eml_int_forloop_overflow_check",
  "C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtRSInfo j_emlrtRSI = { 42, "eml_xaxpy",
  "C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/eml/blas/eml_xaxpy.m" };

static emlrtRSInfo l_emlrtRSI = { 25, "eml_blas_xaxpy",
  "C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtRSInfo n_emlrtRSI = { 66, "eml_blas_xaxpy",
  "C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/eml/blas/external/eml_blas_xaxpy.m"
};

static emlrtMCInfo e_emlrtMCI = { 50, 9, "eml_int_forloop_overflow_check",
  "C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo f_emlrtMCI = { 49, 15, "eml_int_forloop_overflow_check",
  "C:/Program Files/MATLAB/R2012b/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

/* Function Declarations */
static void check_forloop_overflow_error(boolean_T overflow);
static void error(const mxArray *b, emlrtMCInfo *location);
static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location);

/* Function Definitions */
static void check_forloop_overflow_error(boolean_T overflow)
{
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 34 };

  const mxArray *m0;
  static const char_T cv1[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o',
    'l', 'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o',
    'p', '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 23 };

  static const char_T cv2[23] = { 'c', 'o', 'd', 'e', 'r', '.', 'i', 'n', 't',
    'e', 'r', 'n', 'a', 'l', '.', 'i', 'n', 'd', 'e', 'x', 'I', 'n', 't' };

  if (!overflow) {
  } else {
    emlrtPushRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
    y = NULL;
    m0 = mxCreateCharArray(2, iv0);
    emlrtInitCharArray(34, m0, cv1);
    emlrtAssign(&y, m0);
    b_y = NULL;
    m0 = mxCreateCharArray(2, iv1);
    emlrtInitCharArray(23, m0, cv2);
    emlrtAssign(&b_y, m0);
    error(message(y, b_y, &e_emlrtMCI), &f_emlrtMCI);
    emlrtPopRtStackR2012b(&i_emlrtRSI, emlrtRootTLSGlobal);
  }
}

static void error(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "error", TRUE,
                        location);
}

static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location)
{
  const mxArray *pArrays[2];
  const mxArray *m8;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m8, 2, pArrays, "message",
    TRUE, location);
}

void filter(real_T b, const real_T x[80000], real_T y[80000])
{
  int32_T n;
  int32_T incx;
  int32_T incy;
  memset(&y[0], 0, 80000U * sizeof(real_T));
  if (b == 0.0) {
    emlrtPushRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
    check_forloop_overflow_error(FALSE);
    emlrtPopRtStackR2012b(&h_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&f_emlrtRSI, emlrtRootTLSGlobal);
    for (n = 0; n < 80000; n++) {
      y[n] += 0.0 * x[n];
    }
  } else {
    emlrtPushRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPushRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
    n = 80000;
    incx = 1;
    incy = 1;
    emlrtPushRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
    daxpy32(&n, &b, &x[0], &incx, &y[0], &incy);
    emlrtPopRtStackR2012b(&n_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&l_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&j_emlrtRSI, emlrtRootTLSGlobal);
    emlrtPopRtStackR2012b(&g_emlrtRSI, emlrtRootTLSGlobal);
  }
}

/* End of code generation (filter.c) */
