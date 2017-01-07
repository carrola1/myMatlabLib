/* Include files */

#include "blascompat32.h"
#include "ProposedGaussian_sfun.h"
#include "c4_ProposedGaussian.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "ProposedGaussian_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c4_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc4_ProposedGaussianInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c4_ProposedGaussian(void);
static void initialize_params_c4_ProposedGaussian(void);
static void enable_c4_ProposedGaussian(void);
static void disable_c4_ProposedGaussian(void);
static void c4_update_debugger_state_c4_ProposedGaussian(void);
static const mxArray *get_sim_state_c4_ProposedGaussian(void);
static void set_sim_state_c4_ProposedGaussian(const mxArray *c4_st);
static void finalize_c4_ProposedGaussian(void);
static void sf_c4_ProposedGaussian(void);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber);
static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u);
static const mxArray *c4_emlrt_marshallOut(uint8_T c4_u);
static real_T c4_emlrt_marshallIn(const mxArray *c4_accum, char *c4_name);
static real_T c4_b_emlrt_marshallIn(const mxArray *c4_randOut, char *c4_name);
static uint8_T c4_c_emlrt_marshallIn(const mxArray
  *c4_b_is_active_c4_ProposedGaussian, char *c4_name);
static void init_io_bus_offset(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c4_ProposedGaussian(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c4_is_active_c4_ProposedGaussian = 0U;
}

static void initialize_params_c4_ProposedGaussian(void)
{
}

static void enable_c4_ProposedGaussian(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c4_ProposedGaussian(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c4_update_debugger_state_c4_ProposedGaussian(void)
{
}

static const mxArray *get_sim_state_c4_ProposedGaussian(void)
{
  const mxArray *c4_st = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_u;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_c_y = NULL;
  real_T *c4_accum;
  real_T *c4_randOut;
  c4_randOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c4_accum = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellarray(3));
  c4_u = *c4_accum;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_u = *c4_randOut;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_setcell(c4_y, 2, c4_emlrt_marshallOut
                 (chartInstance.c4_is_active_c4_ProposedGaussian));
  sf_mex_assign(&c4_st, c4_y);
  return c4_st;
}

static void set_sim_state_c4_ProposedGaussian(const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T *c4_accum;
  real_T *c4_randOut;
  c4_randOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c4_accum = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  chartInstance.c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *c4_accum = c4_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c4_u, 0)), "accum");
  *c4_randOut = c4_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c4_u, 1)),
    "randOut");
  chartInstance.c4_is_active_c4_ProposedGaussian = c4_c_emlrt_marshallIn
    (sf_mex_dup(sf_mex_getcell(c4_u, 2)),
     "is_active_c4_ProposedGaussian");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_ProposedGaussian();
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_ProposedGaussian(void)
{
}

static void sf_c4_ProposedGaussian(void)
{
  uint8_T c4_previousEvent;
  real_T c4_Bit;
  real_T c4_LastBit;
  real_T c4_LastAccum;
  real_T c4_LastRand;
  real_T c4_nargout = 2.0;
  real_T c4_nargin = 4.0;
  real_T c4_accum;
  real_T c4_randOut;
  real_T c4_a;
  real_T *c4_b_Bit;
  real_T *c4_b_LastBit;
  real_T *c4_b_LastAccum;
  real_T *c4_b_LastRand;
  real_T *c4_b_randOut;
  real_T *c4_b_accum;
  c4_b_LastAccum = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c4_b_Bit = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c4_b_LastRand = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c4_b_randOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c4_b_LastBit = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c4_b_accum = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,1);
  _SFD_DATA_RANGE_CHECK(*c4_b_Bit, 0U);
  _SFD_DATA_RANGE_CHECK(*c4_b_LastBit, 1U);
  _SFD_DATA_RANGE_CHECK(*c4_b_LastAccum, 2U);
  _SFD_DATA_RANGE_CHECK(*c4_b_LastRand, 3U);
  _SFD_DATA_RANGE_CHECK(*c4_b_randOut, 4U);
  _SFD_DATA_RANGE_CHECK(*c4_b_accum, 5U);
  c4_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,1);
  c4_Bit = *c4_b_Bit;
  c4_LastBit = *c4_b_LastBit;
  c4_LastAccum = *c4_b_LastAccum;
  c4_LastRand = *c4_b_LastRand;
  sf_debug_symbol_scope_push(8U, 0U);
  sf_debug_symbol_scope_add("nargout", &c4_nargout, c4_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c4_nargin, c4_sf_marshall);
  sf_debug_symbol_scope_add("accum", &c4_accum, c4_sf_marshall);
  sf_debug_symbol_scope_add("randOut", &c4_randOut, c4_sf_marshall);
  sf_debug_symbol_scope_add("LastRand", &c4_LastRand, c4_sf_marshall);
  sf_debug_symbol_scope_add("LastAccum", &c4_LastAccum, c4_sf_marshall);
  sf_debug_symbol_scope_add("LastBit", &c4_LastBit, c4_sf_marshall);
  sf_debug_symbol_scope_add("Bit", &c4_Bit, c4_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  if (CV_EML_IF(0, 0, c4_Bit != c4_LastBit)) {
    _SFD_EML_CALL(0,4);
    c4_accum = c4_LastAccum + 1.0;
    _SFD_EML_CALL(0,5);
    if (CV_EML_IF(0, 1, c4_accum == 4.0)) {
      _SFD_EML_CALL(0,6);
      c4_accum = 0.0;
      _SFD_EML_CALL(0,7);
      c4_a = c4_LastRand;
      c4_randOut = c4_a * -1.0;
    } else {
      _SFD_EML_CALL(0,9);
      c4_randOut = c4_LastRand;
    }
  } else {
    _SFD_EML_CALL(0,12);
    c4_accum = c4_LastAccum;
    _SFD_EML_CALL(0,13);
    c4_randOut = c4_LastRand;
  }

  _SFD_EML_CALL(0,-13);
  sf_debug_symbol_scope_pop();
  *c4_b_randOut = c4_randOut;
  *c4_b_accum = c4_accum;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,1);
  _sfEvent_ = c4_previousEvent;
  sf_debug_check_for_state_inconsistency(_ProposedGaussianMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber)
{
}

static const mxArray *c4_sf_marshall(void *c4_chartInstance, void *c4_u)
{
  const mxArray *c4_y = NULL;
  real_T c4_b_u;
  const mxArray *c4_b_y = NULL;
  c4_y = NULL;
  c4_b_u = *((real_T *)c4_u);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c4_y, c4_b_y);
  return c4_y;
}

const mxArray *sf_c4_ProposedGaussian_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_ResolvedFunctionInfo c4_info[14];
  c4_ResolvedFunctionInfo (*c4_b_info)[14];
  const mxArray *c4_m0 = NULL;
  int32_T c4_i0;
  c4_ResolvedFunctionInfo *c4_r0;
  c4_nameCaptureInfo = NULL;
  c4_b_info = (c4_ResolvedFunctionInfo (*)[14])c4_info;
  (*c4_b_info)[0].context = "";
  (*c4_b_info)[0].name = "ne";
  (*c4_b_info)[0].dominantType = "double";
  (*c4_b_info)[0].resolved = "[B]ne";
  (*c4_b_info)[0].fileLength = 0U;
  (*c4_b_info)[0].fileTime1 = 0U;
  (*c4_b_info)[0].fileTime2 = 0U;
  (*c4_b_info)[1].context = "";
  (*c4_b_info)[1].name = "plus";
  (*c4_b_info)[1].dominantType = "double";
  (*c4_b_info)[1].resolved = "[B]plus";
  (*c4_b_info)[1].fileLength = 0U;
  (*c4_b_info)[1].fileTime1 = 0U;
  (*c4_b_info)[1].fileTime2 = 0U;
  (*c4_b_info)[2].context = "";
  (*c4_b_info)[2].name = "eq";
  (*c4_b_info)[2].dominantType = "double";
  (*c4_b_info)[2].resolved = "[B]eq";
  (*c4_b_info)[2].fileLength = 0U;
  (*c4_b_info)[2].fileTime1 = 0U;
  (*c4_b_info)[2].fileTime2 = 0U;
  (*c4_b_info)[3].context = "";
  (*c4_b_info)[3].name = "uminus";
  (*c4_b_info)[3].dominantType = "double";
  (*c4_b_info)[3].resolved = "[B]uminus";
  (*c4_b_info)[3].fileLength = 0U;
  (*c4_b_info)[3].fileTime1 = 0U;
  (*c4_b_info)[3].fileTime2 = 0U;
  (*c4_b_info)[4].context = "";
  (*c4_b_info)[4].name = "mtimes";
  (*c4_b_info)[4].dominantType = "double";
  (*c4_b_info)[4].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[4].fileLength = 2408U;
  (*c4_b_info)[4].fileTime1 = 1227635002U;
  (*c4_b_info)[4].fileTime2 = 0U;
  (*c4_b_info)[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[5].name = "nargin";
  (*c4_b_info)[5].dominantType = "";
  (*c4_b_info)[5].resolved = "[B]nargin";
  (*c4_b_info)[5].fileLength = 0U;
  (*c4_b_info)[5].fileTime1 = 0U;
  (*c4_b_info)[5].fileTime2 = 0U;
  (*c4_b_info)[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[6].name = "gt";
  (*c4_b_info)[6].dominantType = "double";
  (*c4_b_info)[6].resolved = "[B]gt";
  (*c4_b_info)[6].fileLength = 0U;
  (*c4_b_info)[6].fileTime1 = 0U;
  (*c4_b_info)[6].fileTime2 = 0U;
  (*c4_b_info)[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[7].name = "isa";
  (*c4_b_info)[7].dominantType = "double";
  (*c4_b_info)[7].resolved = "[B]isa";
  (*c4_b_info)[7].fileLength = 0U;
  (*c4_b_info)[7].fileTime1 = 0U;
  (*c4_b_info)[7].fileTime2 = 0U;
  (*c4_b_info)[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[8].name = "isinteger";
  (*c4_b_info)[8].dominantType = "double";
  (*c4_b_info)[8].resolved = "[B]isinteger";
  (*c4_b_info)[8].fileLength = 0U;
  (*c4_b_info)[8].fileTime1 = 0U;
  (*c4_b_info)[8].fileTime2 = 0U;
  (*c4_b_info)[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[9].name = "isscalar";
  (*c4_b_info)[9].dominantType = "double";
  (*c4_b_info)[9].resolved = "[B]isscalar";
  (*c4_b_info)[9].fileLength = 0U;
  (*c4_b_info)[9].fileTime1 = 0U;
  (*c4_b_info)[9].fileTime2 = 0U;
  (*c4_b_info)[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[10].name = "strcmp";
  (*c4_b_info)[10].dominantType = "char";
  (*c4_b_info)[10].resolved = "[B]strcmp";
  (*c4_b_info)[10].fileLength = 0U;
  (*c4_b_info)[10].fileTime1 = 0U;
  (*c4_b_info)[10].fileTime2 = 0U;
  (*c4_b_info)[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[11].name = "size";
  (*c4_b_info)[11].dominantType = "double";
  (*c4_b_info)[11].resolved = "[B]size";
  (*c4_b_info)[11].fileLength = 0U;
  (*c4_b_info)[11].fileTime1 = 0U;
  (*c4_b_info)[11].fileTime2 = 0U;
  (*c4_b_info)[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[12].name = "class";
  (*c4_b_info)[12].dominantType = "double";
  (*c4_b_info)[12].resolved = "[B]class";
  (*c4_b_info)[12].fileLength = 0U;
  (*c4_b_info)[12].fileTime1 = 0U;
  (*c4_b_info)[12].fileTime2 = 0U;
  (*c4_b_info)[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c4_b_info)[13].name = "not";
  (*c4_b_info)[13].dominantType = "logical";
  (*c4_b_info)[13].resolved = "[B]not";
  (*c4_b_info)[13].fileLength = 0U;
  (*c4_b_info)[13].fileTime1 = 0U;
  (*c4_b_info)[13].fileTime2 = 0U;
  sf_mex_assign(&c4_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14));
  for (c4_i0 = 0; c4_i0 < 14; c4_i0 = c4_i0 + 1) {
    c4_r0 = &c4_info[c4_i0];
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->context)), "context",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c4_r0->name)), "name",
                    "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c4_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", c4_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c4_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c4_i0);
    sf_mex_addfield(c4_m0, sf_mex_create("nameCaptureInfo", &c4_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c4_i0);
  }

  sf_mex_assign(&c4_nameCaptureInfo, c4_m0);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_emlrt_marshallOut(uint8_T c4_u)
{
  const mxArray *c4_y = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0));
  return c4_y;
}

static real_T c4_emlrt_marshallIn(const mxArray *c4_accum, char *c4_name)
{
  real_T c4_y;
  real_T c4_d0;
  sf_mex_import(c4_name, sf_mex_dup(c4_accum), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_accum);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(const mxArray *c4_randOut, char *c4_name)
{
  real_T c4_y;
  real_T c4_d1;
  sf_mex_import(c4_name, sf_mex_dup(c4_randOut), &c4_d1, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d1;
  sf_mex_destroy(&c4_randOut);
  return c4_y;
}

static uint8_T c4_c_emlrt_marshallIn(const mxArray
  *c4_b_is_active_c4_ProposedGaussian, char *c4_name)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  sf_mex_import(c4_name, sf_mex_dup(c4_b_is_active_c4_ProposedGaussian), &c4_u0,
                1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_b_is_active_c4_ProposedGaussian);
  return c4_y;
}

static void init_io_bus_offset(void)
{
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c4_ProposedGaussian_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2486887683U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1707736508U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1989570184U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(618249052U);
}

mxArray *sf_c4_ProposedGaussian_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(2619193864U);
    pr[1] = (double)(1569976591U);
    pr[2] = (double)(1439508450U);
    pr[3] = (double)(2885909114U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c4_ProposedGaussian(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[13],T\"accum\",},{M[1],M[6],T\"randOut\",},{M[8],M[0],T\"is_active_c4_ProposedGaussian\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_ProposedGaussian_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_ProposedGaussianMachineNumber_,
           4,
           1,
           1,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance.chartNumber),
           &(chartInstance.instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_ProposedGaussianMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_ProposedGaussianMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_ProposedGaussianMachineNumber_,
            chartInstance.chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Bit",0,
                              c4_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"LastBit",
                              0,NULL);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "LastAccum",0,NULL);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "LastRand",0,NULL);
          _SFD_SET_DATA_PROPS(4,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"randOut",
                              0,NULL);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"accum",0,
                              NULL);
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of EML Model Coverage */
        _SFD_CV_INIT_EML(0,1,2,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,288);
        _SFD_CV_INIT_EML_IF(0,0,64,81,223,278);
        _SFD_CV_INIT_EML_IF(0,1,113,126,182,222);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c4_Bit;
          real_T *c4_LastBit;
          real_T *c4_LastAccum;
          real_T *c4_LastRand;
          real_T *c4_randOut;
          real_T *c4_accum;
          c4_LastAccum = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c4_Bit = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c4_LastRand = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c4_randOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c4_LastBit = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c4_accum = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          _SFD_SET_DATA_VALUE_PTR(0U, c4_Bit);
          _SFD_SET_DATA_VALUE_PTR(1U, c4_LastBit);
          _SFD_SET_DATA_VALUE_PTR(2U, c4_LastAccum);
          _SFD_SET_DATA_VALUE_PTR(3U, c4_LastRand);
          _SFD_SET_DATA_VALUE_PTR(4U, c4_randOut);
          _SFD_SET_DATA_VALUE_PTR(5U, c4_accum);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ProposedGaussianMachineNumber_,
        chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c4_ProposedGaussian(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c4_ProposedGaussian();
  initialize_c4_ProposedGaussian();
}

static void sf_opaque_enable_c4_ProposedGaussian(void *chartInstanceVar)
{
  enable_c4_ProposedGaussian();
}

static void sf_opaque_disable_c4_ProposedGaussian(void *chartInstanceVar)
{
  disable_c4_ProposedGaussian();
}

static void sf_opaque_gateway_c4_ProposedGaussian(void *chartInstanceVar)
{
  sf_c4_ProposedGaussian();
}

static mxArray* sf_opaque_get_sim_state_c4_ProposedGaussian(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c4_ProposedGaussian();
  return st;
}

static void sf_opaque_set_sim_state_c4_ProposedGaussian(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c4_ProposedGaussian(sf_mex_dup(st));
}

static void sf_opaque_terminate_c4_ProposedGaussian(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c4_ProposedGaussian();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_ProposedGaussian(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_ProposedGaussian();
  }
}

static void mdlSetWorkWidths_c4_ProposedGaussian(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ProposedGaussian","ProposedGaussian",4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ProposedGaussian","ProposedGaussian",4,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("ProposedGaussian",
      "ProposedGaussian",4,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ProposedGaussian",
        "ProposedGaussian",4,4);
      sf_mark_chart_reusable_outputs(S,"ProposedGaussian","ProposedGaussian",4,2);
    }

    sf_set_rtw_dwork_info(S,"ProposedGaussian","ProposedGaussian",4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(4270362667U));
  ssSetChecksum1(S,(1622971805U));
  ssSetChecksum2(S,(195004036U));
  ssSetChecksum3(S,(3303582967U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c4_ProposedGaussian(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ProposedGaussian", "ProposedGaussian",4);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_ProposedGaussian(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_ProposedGaussian;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c4_ProposedGaussian;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c4_ProposedGaussian;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c4_ProposedGaussian;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c4_ProposedGaussian;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_ProposedGaussian;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_ProposedGaussian;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_ProposedGaussian;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c4_ProposedGaussian;
  chartInstance.chartInfo.mdlStart = mdlStart_c4_ProposedGaussian;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_ProposedGaussian;
  chartInstance.chartInfo.extModeExec = NULL;
  chartInstance.chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance.chartInfo.storeCurrentConfiguration = NULL;
  chartInstance.S = S;
  ssSetUserData(S,(void *)(&(chartInstance.chartInfo)));/* register the chart instance with simstruct */
  if (!sim_mode_is_rtw_gen(S)) {
    init_dsm_address_info();
  }

  chart_debug_initialization(S,1);
}

void c4_ProposedGaussian_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_ProposedGaussian(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_ProposedGaussian(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_ProposedGaussian(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_ProposedGaussian_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
