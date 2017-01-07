/* Include files */

#include "blascompat32.h"
#include "ProposedGaussian_sfun.h"
#include "c5_ProposedGaussian.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "ProposedGaussian_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c5_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc5_ProposedGaussianInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c5_ProposedGaussian(void);
static void initialize_params_c5_ProposedGaussian(void);
static void enable_c5_ProposedGaussian(void);
static void disable_c5_ProposedGaussian(void);
static void c5_update_debugger_state_c5_ProposedGaussian(void);
static const mxArray *get_sim_state_c5_ProposedGaussian(void);
static void set_sim_state_c5_ProposedGaussian(const mxArray *c5_st);
static void finalize_c5_ProposedGaussian(void);
static void sf_c5_ProposedGaussian(void);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber);
static const mxArray *c5_sf_marshall(void *c5_chartInstance, void *c5_u);
static const mxArray *c5_emlrt_marshallOut(uint8_T c5_u);
static real_T c5_emlrt_marshallIn(const mxArray *c5_accum, char *c5_name);
static real_T c5_b_emlrt_marshallIn(const mxArray *c5_randNumMem, char *c5_name);
static real_T c5_c_emlrt_marshallIn(const mxArray *c5_randOut, char *c5_name);
static uint8_T c5_d_emlrt_marshallIn(const mxArray
  *c5_b_is_active_c5_ProposedGaussian, char *c5_name);
static void init_io_bus_offset(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c5_ProposedGaussian(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c5_is_active_c5_ProposedGaussian = 0U;
}

static void initialize_params_c5_ProposedGaussian(void)
{
}

static void enable_c5_ProposedGaussian(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c5_ProposedGaussian(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c5_update_debugger_state_c5_ProposedGaussian(void)
{
}

static const mxArray *get_sim_state_c5_ProposedGaussian(void)
{
  const mxArray *c5_st = NULL;
  const mxArray *c5_y = NULL;
  real_T c5_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_d_y = NULL;
  real_T *c5_accum;
  real_T *c5_randNumMem;
  real_T *c5_randOut;
  c5_accum = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c5_randNumMem = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c5_randOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c5_st = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_createcellarray(4));
  c5_u = *c5_accum;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 0, c5_b_y);
  c5_b_u = *c5_randNumMem;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 1, c5_c_y);
  c5_c_u = *c5_randOut;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c5_y, 2, c5_d_y);
  sf_mex_setcell(c5_y, 3, c5_emlrt_marshallOut
                 (chartInstance.c5_is_active_c5_ProposedGaussian));
  sf_mex_assign(&c5_st, c5_y);
  return c5_st;
}

static void set_sim_state_c5_ProposedGaussian(const mxArray *c5_st)
{
  const mxArray *c5_u;
  real_T *c5_accum;
  real_T *c5_randNumMem;
  real_T *c5_randOut;
  c5_accum = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c5_randNumMem = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c5_randOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  chartInstance.c5_doneDoubleBufferReInit = true;
  c5_u = sf_mex_dup(c5_st);
  *c5_accum = c5_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c5_u, 0)), "accum");
  *c5_randNumMem = c5_b_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c5_u, 1)),
    "randNumMem");
  *c5_randOut = c5_c_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c5_u, 2)),
    "randOut");
  chartInstance.c5_is_active_c5_ProposedGaussian = c5_d_emlrt_marshallIn
    (sf_mex_dup(sf_mex_getcell(c5_u, 3)),
     "is_active_c5_ProposedGaussian");
  sf_mex_destroy(&c5_u);
  c5_update_debugger_state_c5_ProposedGaussian();
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_ProposedGaussian(void)
{
}

static void sf_c5_ProposedGaussian(void)
{
  uint8_T c5_previousEvent;
  real_T c5_randNum;
  real_T c5_Bit;
  real_T c5_LastBit;
  real_T c5_LastAccum;
  real_T c5_LastRand;
  real_T c5_LastRandNumMem;
  real_T c5_nargout = 3.0;
  real_T c5_nargin = 6.0;
  real_T c5_randNumMem;
  real_T c5_accum;
  real_T c5_randOut;
  real_T c5_a;
  real_T c5_b_a;
  real_T *c5_b_randNum;
  real_T *c5_b_Bit;
  real_T *c5_b_LastBit;
  real_T *c5_b_LastAccum;
  real_T *c5_b_LastRand;
  real_T *c5_b_randOut;
  real_T *c5_b_accum;
  real_T *c5_b_LastRandNumMem;
  real_T *c5_b_randNumMem;
  c5_b_LastRandNumMem = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
  c5_b_LastAccum = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c5_b_accum = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
  c5_b_LastBit = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c5_b_randNumMem = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
  c5_b_randOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c5_b_Bit = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c5_b_randNum = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c5_b_LastRand = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,2);
  _SFD_DATA_RANGE_CHECK(*c5_b_randNum, 0U);
  _SFD_DATA_RANGE_CHECK(*c5_b_Bit, 1U);
  _SFD_DATA_RANGE_CHECK(*c5_b_LastBit, 2U);
  _SFD_DATA_RANGE_CHECK(*c5_b_LastAccum, 3U);
  _SFD_DATA_RANGE_CHECK(*c5_b_LastRand, 4U);
  _SFD_DATA_RANGE_CHECK(*c5_b_randOut, 5U);
  _SFD_DATA_RANGE_CHECK(*c5_b_accum, 6U);
  _SFD_DATA_RANGE_CHECK(*c5_b_LastRandNumMem, 7U);
  _SFD_DATA_RANGE_CHECK(*c5_b_randNumMem, 8U);
  c5_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,2);
  c5_randNum = *c5_b_randNum;
  c5_Bit = *c5_b_Bit;
  c5_LastBit = *c5_b_LastBit;
  c5_LastAccum = *c5_b_LastAccum;
  c5_LastRand = *c5_b_LastRand;
  c5_LastRandNumMem = *c5_b_LastRandNumMem;
  sf_debug_symbol_scope_push(11U, 0U);
  sf_debug_symbol_scope_add("nargout", &c5_nargout, c5_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c5_nargin, c5_sf_marshall);
  sf_debug_symbol_scope_add("randNumMem", &c5_randNumMem, c5_sf_marshall);
  sf_debug_symbol_scope_add("accum", &c5_accum, c5_sf_marshall);
  sf_debug_symbol_scope_add("randOut", &c5_randOut, c5_sf_marshall);
  sf_debug_symbol_scope_add("LastRandNumMem", &c5_LastRandNumMem, c5_sf_marshall);
  sf_debug_symbol_scope_add("LastRand", &c5_LastRand, c5_sf_marshall);
  sf_debug_symbol_scope_add("LastAccum", &c5_LastAccum, c5_sf_marshall);
  sf_debug_symbol_scope_add("LastBit", &c5_LastBit, c5_sf_marshall);
  sf_debug_symbol_scope_add("Bit", &c5_Bit, c5_sf_marshall);
  sf_debug_symbol_scope_add("randNum", &c5_randNum, c5_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  if (CV_EML_IF(0, 0, c5_Bit != c5_LastBit)) {
    _SFD_EML_CALL(0,4);
    if (CV_EML_IF(0, 1, c5_LastRandNumMem == c5_randNum)) {
      _SFD_EML_CALL(0,5);
      c5_accum = c5_LastAccum + 1.0;
      _SFD_EML_CALL(0,6);
      if (CV_EML_IF(0, 2, c5_accum == 4.0)) {
        _SFD_EML_CALL(0,7);
        c5_accum = 0.0;
        _SFD_EML_CALL(0,8);
        c5_a = c5_randNum;
        c5_randOut = c5_a * -1.0;
        _SFD_EML_CALL(0,9);
        c5_b_a = c5_randNum;
        c5_randNumMem = c5_b_a * -1.0;
      } else {
        _SFD_EML_CALL(0,11);
        c5_randOut = c5_randNum;
        _SFD_EML_CALL(0,12);
        c5_randNumMem = c5_randNum;
      }
    } else {
      _SFD_EML_CALL(0,15);
      c5_randOut = c5_randNum;
      _SFD_EML_CALL(0,16);
      c5_randNumMem = c5_randNum;
      _SFD_EML_CALL(0,17);
      c5_accum = 0.0;
    }
  } else {
    _SFD_EML_CALL(0,20);
    c5_accum = 0.0;
    _SFD_EML_CALL(0,21);
    c5_randOut = c5_LastRand;
    _SFD_EML_CALL(0,22);
    c5_randNumMem = c5_LastRandNumMem;
  }

  _SFD_EML_CALL(0,-22);
  sf_debug_symbol_scope_pop();
  *c5_b_randOut = c5_randOut;
  *c5_b_accum = c5_accum;
  *c5_b_randNumMem = c5_randNumMem;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,2);
  _sfEvent_ = c5_previousEvent;
  sf_debug_check_for_state_inconsistency(_ProposedGaussianMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber)
{
}

static const mxArray *c5_sf_marshall(void *c5_chartInstance, void *c5_u)
{
  const mxArray *c5_y = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_y = NULL;
  c5_b_u = *((real_T *)c5_u);
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c5_y, c5_b_y);
  return c5_y;
}

const mxArray *sf_c5_ProposedGaussian_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_ResolvedFunctionInfo c5_info[14];
  c5_ResolvedFunctionInfo (*c5_b_info)[14];
  const mxArray *c5_m0 = NULL;
  int32_T c5_i0;
  c5_ResolvedFunctionInfo *c5_r0;
  c5_nameCaptureInfo = NULL;
  c5_b_info = (c5_ResolvedFunctionInfo (*)[14])c5_info;
  (*c5_b_info)[0].context = "";
  (*c5_b_info)[0].name = "ne";
  (*c5_b_info)[0].dominantType = "double";
  (*c5_b_info)[0].resolved = "[B]ne";
  (*c5_b_info)[0].fileLength = 0U;
  (*c5_b_info)[0].fileTime1 = 0U;
  (*c5_b_info)[0].fileTime2 = 0U;
  (*c5_b_info)[1].context = "";
  (*c5_b_info)[1].name = "eq";
  (*c5_b_info)[1].dominantType = "double";
  (*c5_b_info)[1].resolved = "[B]eq";
  (*c5_b_info)[1].fileLength = 0U;
  (*c5_b_info)[1].fileTime1 = 0U;
  (*c5_b_info)[1].fileTime2 = 0U;
  (*c5_b_info)[2].context = "";
  (*c5_b_info)[2].name = "plus";
  (*c5_b_info)[2].dominantType = "double";
  (*c5_b_info)[2].resolved = "[B]plus";
  (*c5_b_info)[2].fileLength = 0U;
  (*c5_b_info)[2].fileTime1 = 0U;
  (*c5_b_info)[2].fileTime2 = 0U;
  (*c5_b_info)[3].context = "";
  (*c5_b_info)[3].name = "uminus";
  (*c5_b_info)[3].dominantType = "double";
  (*c5_b_info)[3].resolved = "[B]uminus";
  (*c5_b_info)[3].fileLength = 0U;
  (*c5_b_info)[3].fileTime1 = 0U;
  (*c5_b_info)[3].fileTime2 = 0U;
  (*c5_b_info)[4].context = "";
  (*c5_b_info)[4].name = "mtimes";
  (*c5_b_info)[4].dominantType = "double";
  (*c5_b_info)[4].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[4].fileLength = 2408U;
  (*c5_b_info)[4].fileTime1 = 1227635002U;
  (*c5_b_info)[4].fileTime2 = 0U;
  (*c5_b_info)[5].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[5].name = "nargin";
  (*c5_b_info)[5].dominantType = "";
  (*c5_b_info)[5].resolved = "[B]nargin";
  (*c5_b_info)[5].fileLength = 0U;
  (*c5_b_info)[5].fileTime1 = 0U;
  (*c5_b_info)[5].fileTime2 = 0U;
  (*c5_b_info)[6].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[6].name = "gt";
  (*c5_b_info)[6].dominantType = "double";
  (*c5_b_info)[6].resolved = "[B]gt";
  (*c5_b_info)[6].fileLength = 0U;
  (*c5_b_info)[6].fileTime1 = 0U;
  (*c5_b_info)[6].fileTime2 = 0U;
  (*c5_b_info)[7].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[7].name = "isa";
  (*c5_b_info)[7].dominantType = "double";
  (*c5_b_info)[7].resolved = "[B]isa";
  (*c5_b_info)[7].fileLength = 0U;
  (*c5_b_info)[7].fileTime1 = 0U;
  (*c5_b_info)[7].fileTime2 = 0U;
  (*c5_b_info)[8].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[8].name = "isinteger";
  (*c5_b_info)[8].dominantType = "double";
  (*c5_b_info)[8].resolved = "[B]isinteger";
  (*c5_b_info)[8].fileLength = 0U;
  (*c5_b_info)[8].fileTime1 = 0U;
  (*c5_b_info)[8].fileTime2 = 0U;
  (*c5_b_info)[9].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[9].name = "isscalar";
  (*c5_b_info)[9].dominantType = "double";
  (*c5_b_info)[9].resolved = "[B]isscalar";
  (*c5_b_info)[9].fileLength = 0U;
  (*c5_b_info)[9].fileTime1 = 0U;
  (*c5_b_info)[9].fileTime2 = 0U;
  (*c5_b_info)[10].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[10].name = "strcmp";
  (*c5_b_info)[10].dominantType = "char";
  (*c5_b_info)[10].resolved = "[B]strcmp";
  (*c5_b_info)[10].fileLength = 0U;
  (*c5_b_info)[10].fileTime1 = 0U;
  (*c5_b_info)[10].fileTime2 = 0U;
  (*c5_b_info)[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[11].name = "size";
  (*c5_b_info)[11].dominantType = "double";
  (*c5_b_info)[11].resolved = "[B]size";
  (*c5_b_info)[11].fileLength = 0U;
  (*c5_b_info)[11].fileTime1 = 0U;
  (*c5_b_info)[11].fileTime2 = 0U;
  (*c5_b_info)[12].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[12].name = "class";
  (*c5_b_info)[12].dominantType = "double";
  (*c5_b_info)[12].resolved = "[B]class";
  (*c5_b_info)[12].fileLength = 0U;
  (*c5_b_info)[12].fileTime1 = 0U;
  (*c5_b_info)[12].fileTime2 = 0U;
  (*c5_b_info)[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c5_b_info)[13].name = "not";
  (*c5_b_info)[13].dominantType = "logical";
  (*c5_b_info)[13].resolved = "[B]not";
  (*c5_b_info)[13].fileLength = 0U;
  (*c5_b_info)[13].fileTime1 = 0U;
  (*c5_b_info)[13].fileTime2 = 0U;
  sf_mex_assign(&c5_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14));
  for (c5_i0 = 0; c5_i0 < 14; c5_i0 = c5_i0 + 1) {
    c5_r0 = &c5_info[c5_i0];
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->context)), "context",
                    "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c5_r0->name)), "name",
                    "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c5_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", c5_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c5_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c5_i0);
    sf_mex_addfield(c5_m0, sf_mex_create("nameCaptureInfo", &c5_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c5_i0);
  }

  sf_mex_assign(&c5_nameCaptureInfo, c5_m0);
  return c5_nameCaptureInfo;
}

static const mxArray *c5_emlrt_marshallOut(uint8_T c5_u)
{
  const mxArray *c5_y = NULL;
  c5_y = NULL;
  sf_mex_assign(&c5_y, sf_mex_create("y", &c5_u, 3, 0U, 0U, 0U, 0));
  return c5_y;
}

static real_T c5_emlrt_marshallIn(const mxArray *c5_accum, char *c5_name)
{
  real_T c5_y;
  real_T c5_d0;
  sf_mex_import(c5_name, sf_mex_dup(c5_accum), &c5_d0, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d0;
  sf_mex_destroy(&c5_accum);
  return c5_y;
}

static real_T c5_b_emlrt_marshallIn(const mxArray *c5_randNumMem, char *c5_name)
{
  real_T c5_y;
  real_T c5_d1;
  sf_mex_import(c5_name, sf_mex_dup(c5_randNumMem), &c5_d1, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d1;
  sf_mex_destroy(&c5_randNumMem);
  return c5_y;
}

static real_T c5_c_emlrt_marshallIn(const mxArray *c5_randOut, char *c5_name)
{
  real_T c5_y;
  real_T c5_d2;
  sf_mex_import(c5_name, sf_mex_dup(c5_randOut), &c5_d2, 1, 0, 0U, 0, 0U, 0);
  c5_y = c5_d2;
  sf_mex_destroy(&c5_randOut);
  return c5_y;
}

static uint8_T c5_d_emlrt_marshallIn(const mxArray
  *c5_b_is_active_c5_ProposedGaussian, char *c5_name)
{
  uint8_T c5_y;
  uint8_T c5_u0;
  sf_mex_import(c5_name, sf_mex_dup(c5_b_is_active_c5_ProposedGaussian), &c5_u0,
                1, 3, 0U, 0, 0U, 0);
  c5_y = c5_u0;
  sf_mex_destroy(&c5_b_is_active_c5_ProposedGaussian);
  return c5_y;
}

static void init_io_bus_offset(void)
{
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c5_ProposedGaussian_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2763967881U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(249261906U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4089539330U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3148730212U);
}

mxArray *sf_c5_ProposedGaussian_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(642061745U);
    pr[1] = (double)(190878576U);
    pr[2] = (double)(685824992U);
    pr[3] = (double)(518349104U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c5_ProposedGaussian(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[13],T\"accum\",},{M[1],M[16],T\"randNumMem\",},{M[1],M[6],T\"randOut\",},{M[8],M[0],T\"is_active_c5_ProposedGaussian\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_ProposedGaussian_get_check_sum(&mxChecksum);
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
           5,
           1,
           1,
           9,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"randNum",
                              0,c5_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Bit",0,
                              NULL);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"LastBit",
                              0,NULL);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "LastAccum",0,NULL);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "LastRand",0,NULL);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"randOut",
                              0,NULL);
          _SFD_SET_DATA_PROPS(6,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"accum",0,
                              NULL);
          _SFD_SET_DATA_PROPS(7,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "LastRandNumMem",0,NULL);
          _SFD_SET_DATA_PROPS(8,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "randNumMem",0,NULL);
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
        _SFD_CV_INIT_EML(0,1,3,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,571);
        _SFD_CV_INIT_EML_IF(0,0,98,115,481,561);
        _SFD_CV_INIT_EML_IF(0,1,120,148,390,480);
        _SFD_CV_INIT_EML_IF(0,2,188,201,304,385);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c5_randNum;
          real_T *c5_Bit;
          real_T *c5_LastBit;
          real_T *c5_LastAccum;
          real_T *c5_LastRand;
          real_T *c5_randOut;
          real_T *c5_accum;
          real_T *c5_LastRandNumMem;
          real_T *c5_randNumMem;
          c5_LastRandNumMem = (real_T *)ssGetInputPortSignal(chartInstance.S, 5);
          c5_LastAccum = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c5_accum = (real_T *)ssGetOutputPortSignal(chartInstance.S, 2);
          c5_LastBit = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c5_randNumMem = (real_T *)ssGetOutputPortSignal(chartInstance.S, 3);
          c5_randOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c5_Bit = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c5_randNum = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c5_LastRand = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          _SFD_SET_DATA_VALUE_PTR(0U, c5_randNum);
          _SFD_SET_DATA_VALUE_PTR(1U, c5_Bit);
          _SFD_SET_DATA_VALUE_PTR(2U, c5_LastBit);
          _SFD_SET_DATA_VALUE_PTR(3U, c5_LastAccum);
          _SFD_SET_DATA_VALUE_PTR(4U, c5_LastRand);
          _SFD_SET_DATA_VALUE_PTR(5U, c5_randOut);
          _SFD_SET_DATA_VALUE_PTR(6U, c5_accum);
          _SFD_SET_DATA_VALUE_PTR(7U, c5_LastRandNumMem);
          _SFD_SET_DATA_VALUE_PTR(8U, c5_randNumMem);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ProposedGaussianMachineNumber_,
        chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c5_ProposedGaussian(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c5_ProposedGaussian();
  initialize_c5_ProposedGaussian();
}

static void sf_opaque_enable_c5_ProposedGaussian(void *chartInstanceVar)
{
  enable_c5_ProposedGaussian();
}

static void sf_opaque_disable_c5_ProposedGaussian(void *chartInstanceVar)
{
  disable_c5_ProposedGaussian();
}

static void sf_opaque_gateway_c5_ProposedGaussian(void *chartInstanceVar)
{
  sf_c5_ProposedGaussian();
}

static mxArray* sf_opaque_get_sim_state_c5_ProposedGaussian(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c5_ProposedGaussian();
  return st;
}

static void sf_opaque_set_sim_state_c5_ProposedGaussian(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c5_ProposedGaussian(sf_mex_dup(st));
}

static void sf_opaque_terminate_c5_ProposedGaussian(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c5_ProposedGaussian();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_ProposedGaussian(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c5_ProposedGaussian();
  }
}

static void mdlSetWorkWidths_c5_ProposedGaussian(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ProposedGaussian","ProposedGaussian",5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ProposedGaussian","ProposedGaussian",5,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("ProposedGaussian",
      "ProposedGaussian",5,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ProposedGaussian",
        "ProposedGaussian",5,6);
      sf_mark_chart_reusable_outputs(S,"ProposedGaussian","ProposedGaussian",5,3);
    }

    sf_set_rtw_dwork_info(S,"ProposedGaussian","ProposedGaussian",5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1866871747U));
  ssSetChecksum1(S,(1324301106U));
  ssSetChecksum2(S,(486674967U));
  ssSetChecksum3(S,(1771746865U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c5_ProposedGaussian(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ProposedGaussian", "ProposedGaussian",5);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_ProposedGaussian(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c5_ProposedGaussian;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c5_ProposedGaussian;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c5_ProposedGaussian;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c5_ProposedGaussian;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c5_ProposedGaussian;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c5_ProposedGaussian;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c5_ProposedGaussian;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c5_ProposedGaussian;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c5_ProposedGaussian;
  chartInstance.chartInfo.mdlStart = mdlStart_c5_ProposedGaussian;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c5_ProposedGaussian;
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

void c5_ProposedGaussian_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_ProposedGaussian(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_ProposedGaussian(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_ProposedGaussian(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_ProposedGaussian_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
