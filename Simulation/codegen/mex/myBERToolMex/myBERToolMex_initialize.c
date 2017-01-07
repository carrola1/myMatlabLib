/*
 * myBERToolMex_initialize.c
 *
 * Code generation for function 'myBERToolMex_initialize'
 *
 * C source code generated on: Mon Feb 25 08:35:27 2013
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "myBERToolMex.h"
#include "myBERToolMex_initialize.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const volatile char_T *emlrtBreakCheckR2012bFlagVar;

/* Function Declarations */

/* Function Definitions */
void myBERToolMex_initialize(emlrtContext *aContext)
{
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, aContext, NULL, 1);
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, FALSE, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLicenseCheckR2012b(emlrtRootTLSGlobal, "Signal_Toolbox", 2);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (myBERToolMex_initialize.c) */
