/*
 * myBERToolMex_mex.c
 *
 * Code generation for function 'myBERToolMex'
 *
 * C source code generated on: Mon Feb 25 08:35:27 2013
 *
 */

/* Include files */
#include "mex.h"
#include "myBERToolMex_api.h"
#include "myBERToolMex_initialize.h"
#include "myBERToolMex_terminate.h"

/* Type Definitions */

/* Function Declarations */
static void myBERToolMex_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]);
MEXFUNCTION_LINKAGE mxArray *emlrtMexFcnProperties(void);

/* Variable Definitions */
emlrtContext emlrtContextGlobal = { true, false, EMLRT_VERSION_INFO, NULL, "myBERToolMex", NULL, false, {585839548U,4280471661U,1452683995U,3644522327U}, NULL };
emlrtCTX emlrtRootTLSGlobal = NULL;

/* Function Definitions */
static void myBERToolMex_mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  mxArray *outputs[1];
  mxArray *inputs[5];
  int n = 0;
  int nOutputs = (nlhs < 1 ? 1 : nlhs);
  int nInputs = nrhs;
  myBERToolMexStackData* myBERToolMexStackDataLocal = (myBERToolMexStackData*)mxCalloc(1,sizeof(myBERToolMexStackData));
  /* Check for proper number of arguments. */
  if(nrhs != 5) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:WrongNumberOfInputs","5 inputs required for entry-point 'myBERToolMex'.");
  } else if(nlhs > 1) {
    mexErrMsgIdAndTxt("emlcoder:emlmex:TooManyOutputArguments","Too many output arguments for entry-point 'myBERToolMex'.");
  }
  /* Temporary copy for mex inputs. */
  for (n = 0; n < nInputs; ++n) {
    inputs[n] = (mxArray *)prhs[n];
  }
  /* Module initialization. */
  myBERToolMex_initialize(&emlrtContextGlobal);
  /* Call the function. */
  myBERToolMex_api(myBERToolMexStackDataLocal, (const mxArray**)inputs,(const mxArray**)outputs);
  /* Copy over outputs to the caller. */
  for (n = 0; n < nOutputs; ++n) {
    plhs[n] = emlrtReturnArrayR2009a(outputs[n]);
  }
  /* Module finalization. */
  myBERToolMex_terminate();
  mxFree(myBERToolMexStackDataLocal);
}

void myBERToolMex_atexit_wrapper(void)
{
  myBERToolMex_atexit();
}

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
  /* Initialize the memory manager. */
  mexAtExit(myBERToolMex_atexit_wrapper);
  /* Dispatch the entry-point. */
  myBERToolMex_mexFunction(nlhs, plhs, nrhs, prhs);
}

mxArray *emlrtMexFcnProperties(void)
{
    const char *mexProperties[] = {
        "Version",
        "EntryPoints"};
    const char *epProperties[] = {
        "Name",
        "NumberOfInputs",
        "NumberOfOutputs",
        "ConstantInputs"};
    mxArray *xResult = mxCreateStructMatrix(1,1,2,mexProperties);
    mxArray *xEntryPoints = mxCreateStructMatrix(1,1,4,epProperties);
    mxArray *xInputs = NULL;
    xInputs = mxCreateLogicalMatrix(1, 5);
    mxSetFieldByNumber(xEntryPoints, 0, 0, mxCreateString("myBERToolMex"));
    mxSetFieldByNumber(xEntryPoints, 0, 1, mxCreateDoubleScalar(5));
    mxSetFieldByNumber(xEntryPoints, 0, 2, mxCreateDoubleScalar(1));
    mxSetFieldByNumber(xEntryPoints, 0, 3, xInputs);
    mxSetFieldByNumber(xResult, 0, 0, mxCreateString("8.0.0.783 (R2012b)"));
    mxSetFieldByNumber(xResult, 0, 1, xEntryPoints);

    return xResult;
}
/* End of code generation (myBERToolMex_mex.c) */
