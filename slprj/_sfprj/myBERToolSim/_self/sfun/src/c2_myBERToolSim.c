/* Include files */

#include "blascompat32.h"
#include "myBERToolSim_sfun.h"
#include "c2_myBERToolSim.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "myBERToolSim_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_myBERToolSimInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_myBERToolSim(void);
static void initialize_params_c2_myBERToolSim(void);
static void enable_c2_myBERToolSim(void);
static void disable_c2_myBERToolSim(void);
static void c2_update_debugger_state_c2_myBERToolSim(void);
static const mxArray *get_sim_state_c2_myBERToolSim(void);
static void set_sim_state_c2_myBERToolSim(const mxArray *c2_st);
static void finalize_c2_myBERToolSim(void);
static void sf_c2_myBERToolSim(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static real_T c2_mpower(real_T c2_a);
static void c2_eml_error(void);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[31]);
static const mxArray *c2_emlrt_marshallOut(uint8_T c2_u);
static real_T c2_emlrt_marshallIn(const mxArray *c2_y, char *c2_name);
static uint8_T c2_b_emlrt_marshallIn(const mxArray
  *c2_b_is_active_c2_myBERToolSim, char *c2_name);
static void init_io_bus_offset(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_myBERToolSim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_myBERToolSim = 0U;
}

static void initialize_params_c2_myBERToolSim(void)
{
}

static void enable_c2_myBERToolSim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_myBERToolSim(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c2_update_debugger_state_c2_myBERToolSim(void)
{
}

static const mxArray *get_sim_state_c2_myBERToolSim(void)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T *c2_c_y;
  c2_c_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_u = *c2_c_y;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  sf_mex_setcell(c2_y, 1, c2_emlrt_marshallOut
                 (chartInstance.c2_is_active_c2_myBERToolSim));
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_myBERToolSim(const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_y;
  c2_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  chartInstance.c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *c2_y = c2_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c2_u, 0)), "y");
  chartInstance.c2_is_active_c2_myBERToolSim = c2_b_emlrt_marshallIn(sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "is_active_c2_myBERToolSim");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_myBERToolSim();
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_myBERToolSim(void)
{
}

static void sf_c2_myBERToolSim(void)
{
  uint8_T c2_previousEvent;
  real_T c2_a;
  real_T c2_b;
  real_T c2_nargout = 1.0;
  real_T c2_nargin = 2.0;
  real_T c2_y;
  real_T c2_x;
  real_T c2_b_x;
  real_T *c2_b_a;
  real_T *c2_b_y;
  real_T *c2_b_b;
  c2_b_a = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c2_b_b = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  c2_b_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c2_b_a, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_y, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_b, 2U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_a = *c2_b_a;
  c2_b = *c2_b_b;
  sf_debug_symbol_scope_push(5U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_sf_marshall);
  sf_debug_symbol_scope_add("y", &c2_y, c2_sf_marshall);
  sf_debug_symbol_scope_add("b", &c2_b, c2_sf_marshall);
  sf_debug_symbol_scope_add("a", &c2_a, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,4);
  c2_x = c2_mpower(c2_a) + c2_mpower(c2_b);
  c2_y = c2_x;
  if (c2_y < 0.0) {
    c2_eml_error();
  }

  c2_b_x = c2_y;
  c2_y = c2_b_x;
  c2_y = muDoubleScalarSqrt(c2_y);
  _SFD_EML_CALL(0,-4);
  sf_debug_symbol_scope_pop();
  *c2_b_y = c2_y;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_myBERToolSimMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static real_T c2_mpower(real_T c2_a)
{
  real_T c2_b_a;
  real_T c2_ak;
  c2_b_a = c2_a;
  c2_ak = c2_b_a;
  return muDoubleScalarPower(c2_ak, 2.0);
}

static void c2_eml_error(void)
{
  int32_T c2_i0;
  static char_T c2_cv0[77] = { 'D', 'o', 'm', 'a', 'i', 'n', ' ', 'e', 'r', 'r',
    'o', 'r', '.', ' ', 'T', 'o', ' ', 'c', 'o', 'm', 'p'
    , 'u', 't', 'e', ' ', 'c', 'o', 'm', 'p', 'l', 'e', 'x', ' ', 'r', 'e', 's',
    'u', 'l', 't', 's', ' ',
    'f', 'r', 'o', 'm', ' ', 'r', 'e', 'a', 'l', ' ', 'x', ',', ' ', 'u', 's',
    'e', ' ', '\'', 's', 'q',
    'r', 't', '(', 'c', 'o', 'm', 'p', 'l', 'e', 'x', '(', 'x', ')', ')', '\'',
    '.' };

  char_T c2_u[77];
  const mxArray *c2_y = NULL;
  int32_T c2_i1;
  static char_T c2_cv1[31] = { 'E', 'm', 'b', 'e', 'd', 'd', 'e', 'd', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'q', 'r', 't', ':', 'd'
    , 'o', 'm', 'a', 'i', 'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c2_b_u[31];
  const mxArray *c2_b_y = NULL;
  for (c2_i0 = 0; c2_i0 < 77; c2_i0 = c2_i0 + 1) {
    c2_u[c2_i0] = c2_cv0[c2_i0];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 10, 0U, 1U, 0U, 2, 1, 77));
  for (c2_i1 = 0; c2_i1 < 31; c2_i1 = c2_i1 + 1) {
    c2_b_u[c2_i1] = c2_cv1[c2_i1];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 10, 0U, 1U, 0U, 2, 1, 31));
  sf_mex_call_debug("error", 0U, 2U, 14, c2_b_y, 14, c2_y);
}

static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u)
{
  const mxArray *c2_y = NULL;
  real_T c2_b_u;
  const mxArray *c2_b_y = NULL;
  c2_y = NULL;
  c2_b_u = *((real_T *)c2_u);
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c2_y, c2_b_y);
  return c2_y;
}

const mxArray *sf_c2_myBERToolSim_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[31];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i2;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 31));
  for (c2_i2 = 0; c2_i2 < 31; c2_i2 = c2_i2 + 1) {
    c2_r0 = &c2_info[c2_i2];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i2);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i2);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[31])
{
  c2_info[0].context = "";
  c2_info[0].name = "mpower";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[0].fileLength = 3623U;
  c2_info[0].fileTime1 = 1227635002U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[1].name = "nargin";
  c2_info[1].dominantType = "";
  c2_info[1].resolved = "[B]nargin";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[2].name = "gt";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[B]gt";
  c2_info[2].fileLength = 0U;
  c2_info[2].fileTime1 = 0U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[3].name = "isa";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved = "[B]isa";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[4].name = "isinteger";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]isinteger";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[5].name = "isscalar";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]isscalar";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[6].name = "ndims";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[B]ndims";
  c2_info[6].fileLength = 0U;
  c2_info[6].fileTime1 = 0U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[7].name = "eq";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]eq";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[8].name = "size";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]size";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m";
  c2_info[9].name = "power";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[9].fileLength = 5380U;
  c2_info[9].fileTime1 = 1227635002U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[10].name = "eml_scalar_eg";
  c2_info[10].dominantType = "double";
  c2_info[10].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[10].fileLength = 3524U;
  c2_info[10].fileTime1 = 1227634994U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/any_enums";
  c2_info[11].name = "false";
  c2_info[11].dominantType = "";
  c2_info[11].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[11].fileLength = 238U;
  c2_info[11].fileTime1 = 1192488320U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elmat/false.m";
  c2_info[12].name = "logical";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved = "[B]logical";
  c2_info[12].fileLength = 0U;
  c2_info[12].fileTime1 = 0U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[13].name = "isstruct";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[B]isstruct";
  c2_info[13].fileLength = 0U;
  c2_info[13].fileTime1 = 0U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[14].name = "class";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]class";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[15].name = "cast";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[15].fileLength = 889U;
  c2_info[15].fileTime1 = 1226011042U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[16].name = "ge";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]ge";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[17].name = "ischar";
  c2_info[17].dominantType = "char";
  c2_info[17].resolved = "[B]ischar";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
  c2_info[18].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/datatypes/cast.m";
  c2_info[18].name = "double";
  c2_info[18].dominantType = "double";
  c2_info[18].resolved = "[B]double";
  c2_info[18].fileLength = 0U;
  c2_info[18].fileTime1 = 0U;
  c2_info[18].fileTime2 = 0U;
  c2_info[19].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/zerosum";
  c2_info[19].name = "plus";
  c2_info[19].dominantType = "double";
  c2_info[19].resolved = "[B]plus";
  c2_info[19].fileLength = 0U;
  c2_info[19].fileTime1 = 0U;
  c2_info[19].fileTime2 = 0U;
  c2_info[20].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m/allreal";
  c2_info[20].name = "isreal";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved = "[B]isreal";
  c2_info[20].fileLength = 0U;
  c2_info[20].fileTime1 = 0U;
  c2_info[20].fileTime2 = 0U;
  c2_info[21].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[21].name = "eml_scalexp_alloc";
  c2_info[21].dominantType = "double";
  c2_info[21].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[21].fileLength = 794U;
  c2_info[21].fileTime1 = 1227634994U;
  c2_info[21].fileTime2 = 0U;
  c2_info[22].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[22].name = "minus";
  c2_info[22].dominantType = "double";
  c2_info[22].resolved = "[B]minus";
  c2_info[22].fileLength = 0U;
  c2_info[22].fileTime1 = 0U;
  c2_info[22].fileTime2 = 0U;
  c2_info[23].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c2_info[23].name = "not";
  c2_info[23].dominantType = "logical";
  c2_info[23].resolved = "[B]not";
  c2_info[23].fileLength = 0U;
  c2_info[23].fileTime1 = 0U;
  c2_info[23].fileTime2 = 0U;
  c2_info[24].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[24].name = "lt";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved = "[B]lt";
  c2_info[24].fileLength = 0U;
  c2_info[24].fileTime1 = 0U;
  c2_info[24].fileTime2 = 0U;
  c2_info[25].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[25].name = "eml_scalar_floor";
  c2_info[25].dominantType = "double";
  c2_info[25].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[25].fileLength = 260U;
  c2_info[25].fileTime1 = 1209352390U;
  c2_info[25].fileTime2 = 0U;
  c2_info[26].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[26].name = "ne";
  c2_info[26].dominantType = "double";
  c2_info[26].resolved = "[B]ne";
  c2_info[26].fileLength = 0U;
  c2_info[26].fileTime1 = 0U;
  c2_info[26].fileTime2 = 0U;
  c2_info[27].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m";
  c2_info[27].name = "eml_error";
  c2_info[27].dominantType = "char";
  c2_info[27].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[27].fileLength = 315U;
  c2_info[27].fileTime1 = 1213948346U;
  c2_info[27].fileTime2 = 0U;
  c2_info[28].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[28].name = "strcmp";
  c2_info[28].dominantType = "char";
  c2_info[28].resolved = "[B]strcmp";
  c2_info[28].fileLength = 0U;
  c2_info[28].fileTime1 = 0U;
  c2_info[28].fileTime2 = 0U;
  c2_info[29].context = "";
  c2_info[29].name = "sqrt";
  c2_info[29].dominantType = "double";
  c2_info[29].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[29].fileLength = 572U;
  c2_info[29].fileTime1 = 1203469646U;
  c2_info[29].fileTime2 = 0U;
  c2_info[30].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  c2_info[30].name = "eml_scalar_sqrt";
  c2_info[30].dominantType = "double";
  c2_info[30].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  c2_info[30].fileLength = 664U;
  c2_info[30].fileTime1 = 1209352394U;
  c2_info[30].fileTime2 = 0U;
}

static const mxArray *c2_emlrt_marshallOut(uint8_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0));
  return c2_y;
}

static real_T c2_emlrt_marshallIn(const mxArray *c2_y, char *c2_name)
{
  real_T c2_b_y;
  real_T c2_d0;
  sf_mex_import(c2_name, sf_mex_dup(c2_y), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_b_y = c2_d0;
  sf_mex_destroy(&c2_y);
  return c2_b_y;
}

static uint8_T c2_b_emlrt_marshallIn(const mxArray
  *c2_b_is_active_c2_myBERToolSim, char *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_myBERToolSim), &c2_u0, 1,
                3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_myBERToolSim);
  return c2_y;
}

static void init_io_bus_offset(void)
{
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_myBERToolSim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2801831818U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2790329811U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1256665177U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3873046457U);
}

mxArray *sf_c2_myBERToolSim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1384561657U);
    pr[1] = (double)(1455029273U);
    pr[2] = (double)(3184958246U);
    pr[3] = (double)(174247001U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  return(mxAutoinheritanceInfo);
}

static mxArray *sf_get_sim_state_info_c2_myBERToolSim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_myBERToolSim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_myBERToolSim_get_check_sum(&mxChecksum);
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
          (_myBERToolSimMachineNumber_,
           2,
           1,
           1,
           3,
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
          init_script_number_translation(_myBERToolSimMachineNumber_,
            chartInstance.chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_myBERToolSimMachineNumber_,chartInstance.chartNumber,1);
          sf_debug_set_chart_event_thresholds(_myBERToolSimMachineNumber_,
            chartInstance.chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"a",0,
                              c2_sf_marshall);
          _SFD_SET_DATA_PROPS(1,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"y",0,
                              NULL);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"b",0,
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
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,49);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c2_a;
          real_T *c2_y;
          real_T *c2_b;
          c2_a = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c2_b = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          c2_y = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_a);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_y);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_b);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_myBERToolSimMachineNumber_,
        chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_myBERToolSim(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_myBERToolSim();
  initialize_c2_myBERToolSim();
}

static void sf_opaque_enable_c2_myBERToolSim(void *chartInstanceVar)
{
  enable_c2_myBERToolSim();
}

static void sf_opaque_disable_c2_myBERToolSim(void *chartInstanceVar)
{
  disable_c2_myBERToolSim();
}

static void sf_opaque_gateway_c2_myBERToolSim(void *chartInstanceVar)
{
  sf_c2_myBERToolSim();
}

static mxArray* sf_opaque_get_sim_state_c2_myBERToolSim(void *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_myBERToolSim();
  return st;
}

static void sf_opaque_set_sim_state_c2_myBERToolSim(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c2_myBERToolSim(sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_myBERToolSim(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_myBERToolSim();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_myBERToolSim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_myBERToolSim();
  }
}

static void mdlSetWorkWidths_c2_myBERToolSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("myBERToolSim","myBERToolSim",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("myBERToolSim","myBERToolSim",2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("myBERToolSim",
      "myBERToolSim",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"myBERToolSim","myBERToolSim",2,2);
      sf_mark_chart_reusable_outputs(S,"myBERToolSim","myBERToolSim",2,1);
    }

    sf_set_rtw_dwork_info(S,"myBERToolSim","myBERToolSim",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(1238943398U));
  ssSetChecksum1(S,(199642814U));
  ssSetChecksum2(S,(3591634328U));
  ssSetChecksum3(S,(3679799179U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_myBERToolSim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "myBERToolSim", "myBERToolSim",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_myBERToolSim(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway = sf_opaque_gateway_c2_myBERToolSim;
  chartInstance.chartInfo.initializeChart = sf_opaque_initialize_c2_myBERToolSim;
  chartInstance.chartInfo.terminateChart = sf_opaque_terminate_c2_myBERToolSim;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_myBERToolSim;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_myBERToolSim;
  chartInstance.chartInfo.getSimState = sf_opaque_get_sim_state_c2_myBERToolSim;
  chartInstance.chartInfo.setSimState = sf_opaque_set_sim_state_c2_myBERToolSim;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_myBERToolSim;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_myBERToolSim;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_myBERToolSim;
  chartInstance.chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_myBERToolSim;
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

void c2_myBERToolSim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_myBERToolSim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_myBERToolSim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_myBERToolSim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_myBERToolSim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
