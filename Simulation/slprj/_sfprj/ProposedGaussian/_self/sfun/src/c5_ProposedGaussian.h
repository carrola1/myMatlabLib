#ifndef __c5_ProposedGaussian_h__
#define __c5_ProposedGaussian_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
typedef struct {
  char *context;
  char *name;
  char *dominantType;
  char *resolved;
  uint32_T fileLength;
  uint32_T fileTime1;
  uint32_T fileTime2;
} c5_ResolvedFunctionInfo;

typedef struct {
  SimStruct *S;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_ProposedGaussian;
  ChartInfoStruct chartInfo;
} SFc5_ProposedGaussianInstanceStruct;

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
const mxArray *sf_c5_ProposedGaussian_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_ProposedGaussian_get_check_sum(mxArray *plhs[]);
extern void c5_ProposedGaussian_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
