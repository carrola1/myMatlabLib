/*
 * myBERToolMex_terminate.c
 *
 * Code generation for function 'myBERToolMex_terminate'
 *
 * C source code generated on: Mon Feb 25 08:35:27 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myBERToolMex.h"
#include "myBERToolMex_terminate.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void myBERToolMex_atexit(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void myBERToolMex_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (myBERToolMex_terminate.c) */
