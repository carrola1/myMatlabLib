/*
 * myBERToolMex.h
 *
 * Code generation for function 'myBERToolMex'
 *
 * C source code generated on: Mon Feb 25 08:35:27 2013
 *
 */

#ifndef __MYBERTOOLMEX_H__
#define __MYBERTOOLMEX_H__
/* Include files */
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "blascompat32.h"
#include "rtwtypes.h"
#include "myBERToolMex_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *myBERToolMex(myBERToolMexStackData *SD, const real_T msgUpSamp[80000], real_T HdTx, const real_T HdRx[51], const real_T HdInterp[43], real_T snr);
#endif
/* End of code generation (myBERToolMex.h) */
