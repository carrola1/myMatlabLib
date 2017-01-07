/* Include files */

#include "blascompat32.h"
#include "ProposedGaussian_sfun.h"
#include "c2_ProposedGaussian.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance.chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance.instanceNumber)
#include "ProposedGaussian_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */
#define c2_IN_NO_ACTIVE_CHILD          (0)

/* Variable Declarations */

/* Variable Definitions */
static SFc2_ProposedGaussianInstanceStruct chartInstance;

/* Function Declarations */
static void initialize_c2_ProposedGaussian(void);
static void initialize_params_c2_ProposedGaussian(void);
static void enable_c2_ProposedGaussian(void);
static void disable_c2_ProposedGaussian(void);
static void c2_update_debugger_state_c2_ProposedGaussian(void);
static const mxArray *get_sim_state_c2_ProposedGaussian(void);
static void set_sim_state_c2_ProposedGaussian(const mxArray *c2_st);
static void finalize_c2_ProposedGaussian(void);
static void sf_c2_ProposedGaussian(void);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshall(void *c2_chartInstance, void *c2_u);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18]);
static const mxArray *c2_emlrt_marshallOut(uint8_T c2_u);
static real_T c2_emlrt_marshallIn(const mxArray *c2_phaseOut, char *c2_name);
static uint8_T c2_b_emlrt_marshallIn(const mxArray
  *c2_b_is_active_c2_ProposedGaussian, char *c2_name);
static void init_io_bus_offset(void);
static void init_dsm_address_info(void);

/* Function Definitions */
static void initialize_c2_ProposedGaussian(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  chartInstance.c2_is_active_c2_ProposedGaussian = 0U;
}

static void initialize_params_c2_ProposedGaussian(void)
{
}

static void enable_c2_ProposedGaussian(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void disable_c2_ProposedGaussian(void)
{
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
}

static void c2_update_debugger_state_c2_ProposedGaussian(void)
{
}

static const mxArray *get_sim_state_c2_ProposedGaussian(void)
{
  const mxArray *c2_st = NULL;
  const mxArray *c2_y = NULL;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  real_T *c2_phaseOut;
  c2_phaseOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2));
  c2_u = *c2_phaseOut;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c2_y, 0, c2_b_y);
  sf_mex_setcell(c2_y, 1, c2_emlrt_marshallOut
                 (chartInstance.c2_is_active_c2_ProposedGaussian));
  sf_mex_assign(&c2_st, c2_y);
  return c2_st;
}

static void set_sim_state_c2_ProposedGaussian(const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_phaseOut;
  c2_phaseOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  chartInstance.c2_doneDoubleBufferReInit = true;
  c2_u = sf_mex_dup(c2_st);
  *c2_phaseOut = c2_emlrt_marshallIn(sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "phaseOut");
  chartInstance.c2_is_active_c2_ProposedGaussian = c2_b_emlrt_marshallIn
    (sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_ProposedGaussian");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_ProposedGaussian();
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_ProposedGaussian(void)
{
}

static void sf_c2_ProposedGaussian(void)
{
  uint8_T c2_previousEvent;
  real_T c2_Init;
  real_T c2_Bit;
  real_T c2_LastBit;
  real_T c2_LastPhase;
  real_T c2_phDirection;
  real_T c2_nargout = 1.0;
  real_T c2_nargin = 5.0;
  real_T c2_phaseOut;
  real_T *c2_b_phaseOut;
  real_T *c2_b_phDirection;
  real_T *c2_b_LastPhase;
  real_T *c2_b_LastBit;
  real_T *c2_b_Bit;
  real_T *c2_b_Init;
  c2_b_phDirection = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
  c2_b_Init = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
  c2_b_LastPhase = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
  c2_b_LastBit = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
  c2_b_phaseOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
  c2_b_Bit = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance.S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG,0);
  _SFD_DATA_RANGE_CHECK(*c2_b_Init, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_Bit, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_LastBit, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_LastPhase, 3U);
  _SFD_DATA_RANGE_CHECK(*c2_b_phDirection, 4U);
  _SFD_DATA_RANGE_CHECK(*c2_b_phaseOut, 5U);
  c2_previousEvent = _sfEvent_;
  _sfEvent_ = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG,0);
  c2_Init = *c2_b_Init;
  c2_Bit = *c2_b_Bit;
  c2_LastBit = *c2_b_LastBit;
  c2_LastPhase = *c2_b_LastPhase;
  c2_phDirection = *c2_b_phDirection;
  sf_debug_symbol_scope_push(8U, 0U);
  sf_debug_symbol_scope_add("nargout", &c2_nargout, c2_sf_marshall);
  sf_debug_symbol_scope_add("nargin", &c2_nargin, c2_sf_marshall);
  sf_debug_symbol_scope_add("phaseOut", &c2_phaseOut, c2_sf_marshall);
  sf_debug_symbol_scope_add("phDirection", &c2_phDirection, c2_sf_marshall);
  sf_debug_symbol_scope_add("LastPhase", &c2_LastPhase, c2_sf_marshall);
  sf_debug_symbol_scope_add("LastBit", &c2_LastBit, c2_sf_marshall);
  sf_debug_symbol_scope_add("Bit", &c2_Bit, c2_sf_marshall);
  sf_debug_symbol_scope_add("Init", &c2_Init, c2_sf_marshall);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0,3);
  if (CV_EML_IF(0, 0, c2_Init == 2.0)) {
    _SFD_EML_CALL(0,4);
    c2_phaseOut = 7.8539816339744828E-001;
  } else {
    _SFD_EML_CALL(0,6);
    if (CV_EML_IF(0, 1, c2_Bit != c2_LastBit)) {
      _SFD_EML_CALL(0,7);
      if (CV_EML_IF(0, 2, c2_Bit == 0.0)) {
        _SFD_EML_CALL(0,8);
        if (CV_EML_IF(0, 3, c2_phDirection > 0.0)) {
          _SFD_EML_CALL(0,9);
          c2_phaseOut = c2_LastPhase + 3.1415926535897931E+000;
        } else {
          _SFD_EML_CALL(0,11);
          c2_phaseOut = c2_LastPhase + 3.1415926535897931E+000;
        }
      } else {
        _SFD_EML_CALL(0,14);
        if (CV_EML_IF(0, 4, c2_phDirection > 0.0)) {
          _SFD_EML_CALL(0,15);
          c2_phaseOut = c2_LastPhase + 3.1415926535897931E+000;
        } else {
          _SFD_EML_CALL(0,17);
          c2_phaseOut = c2_LastPhase + 3.1415926535897931E+000;
        }
      }
    } else {
      _SFD_EML_CALL(0,21);
      c2_phaseOut = c2_LastPhase;
    }
  }

  _SFD_EML_CALL(0,-21);
  sf_debug_symbol_scope_pop();
  *c2_b_phaseOut = c2_phaseOut;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG,0);
  _sfEvent_ = c2_previousEvent;
  sf_debug_check_for_state_inconsistency(_ProposedGaussianMachineNumber_,
    chartInstance.chartNumber, chartInstance.instanceNumber);
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
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

const mxArray *sf_c2_ProposedGaussian_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_ResolvedFunctionInfo c2_info[18];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 18));
  for (c2_i0 = 0; c2_i0 < 18; c2_i0 = c2_i0 + 1) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved"
                    , "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileLength,
      7, 0U, 0U, 0U, 0), "fileLength", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime1, 7,
      0U, 0U, 0U, 0), "fileTime1", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTime2, 7,
      0U, 0U, 0U, 0), "fileTime2", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[18])
{
  c2_info[0].context = "";
  c2_info[0].name = "eq";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved = "[B]eq";
  c2_info[0].fileLength = 0U;
  c2_info[0].fileTime1 = 0U;
  c2_info[0].fileTime2 = 0U;
  c2_info[1].context = "";
  c2_info[1].name = "pi";
  c2_info[1].dominantType = "";
  c2_info[1].resolved = "[B]pi";
  c2_info[1].fileLength = 0U;
  c2_info[1].fileTime1 = 0U;
  c2_info[1].fileTime2 = 0U;
  c2_info[2].context = "";
  c2_info[2].name = "mrdivide";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[2].fileLength = 771U;
  c2_info[2].fileTime1 = 1219774536U;
  c2_info[2].fileTime2 = 0U;
  c2_info[3].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[3].name = "nargin";
  c2_info[3].dominantType = "";
  c2_info[3].resolved = "[B]nargin";
  c2_info[3].fileLength = 0U;
  c2_info[3].fileTime1 = 0U;
  c2_info[3].fileTime2 = 0U;
  c2_info[4].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[4].name = "ge";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved = "[B]ge";
  c2_info[4].fileLength = 0U;
  c2_info[4].fileTime1 = 0U;
  c2_info[4].fileTime2 = 0U;
  c2_info[5].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[5].name = "isscalar";
  c2_info[5].dominantType = "double";
  c2_info[5].resolved = "[B]isscalar";
  c2_info[5].fileLength = 0U;
  c2_info[5].fileTime1 = 0U;
  c2_info[5].fileTime2 = 0U;
  c2_info[6].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.m";
  c2_info[6].name = "rdivide";
  c2_info[6].dominantType = "double";
  c2_info[6].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[6].fileLength = 620U;
  c2_info[6].fileTime1 = 1213948366U;
  c2_info[6].fileTime2 = 0U;
  c2_info[7].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[7].name = "gt";
  c2_info[7].dominantType = "double";
  c2_info[7].resolved = "[B]gt";
  c2_info[7].fileLength = 0U;
  c2_info[7].fileTime1 = 0U;
  c2_info[7].fileTime2 = 0U;
  c2_info[8].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[8].name = "isa";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved = "[B]isa";
  c2_info[8].fileLength = 0U;
  c2_info[8].fileTime1 = 0U;
  c2_info[8].fileTime2 = 0U;
  c2_info[9].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[9].name = "isempty";
  c2_info[9].dominantType = "double";
  c2_info[9].resolved = "[B]isempty";
  c2_info[9].fileLength = 0U;
  c2_info[9].fileTime1 = 0U;
  c2_info[9].fileTime2 = 0U;
  c2_info[10].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[10].name = "not";
  c2_info[10].dominantType = "logical";
  c2_info[10].resolved = "[B]not";
  c2_info[10].fileLength = 0U;
  c2_info[10].fileTime1 = 0U;
  c2_info[10].fileTime2 = 0U;
  c2_info[11].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[11].name = "strcmp";
  c2_info[11].dominantType = "char";
  c2_info[11].resolved = "[B]strcmp";
  c2_info[11].fileLength = 0U;
  c2_info[11].fileTime1 = 0U;
  c2_info[11].fileTime2 = 0U;
  c2_info[12].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[12].name = "eml_warning";
  c2_info[12].dominantType = "char";
  c2_info[12].resolved =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m";
  c2_info[12].fileLength = 274U;
  c2_info[12].fileTime1 = 1227634996U;
  c2_info[12].fileTime2 = 0U;
  c2_info[13].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  c2_info[13].name = "eml_div";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[13].fileLength = 4269U;
  c2_info[13].fileTime1 = 1227634986U;
  c2_info[13].fileTime2 = 0U;
  c2_info[14].context = "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  c2_info[14].name = "isinteger";
  c2_info[14].dominantType = "double";
  c2_info[14].resolved = "[B]isinteger";
  c2_info[14].fileLength = 0U;
  c2_info[14].fileTime1 = 0U;
  c2_info[14].fileTime2 = 0U;
  c2_info[15].context =
    "[I]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m/eml_fldiv";
  c2_info[15].name = "isreal";
  c2_info[15].dominantType = "double";
  c2_info[15].resolved = "[B]isreal";
  c2_info[15].fileLength = 0U;
  c2_info[15].fileTime1 = 0U;
  c2_info[15].fileTime2 = 0U;
  c2_info[16].context = "";
  c2_info[16].name = "ne";
  c2_info[16].dominantType = "double";
  c2_info[16].resolved = "[B]ne";
  c2_info[16].fileLength = 0U;
  c2_info[16].fileTime1 = 0U;
  c2_info[16].fileTime2 = 0U;
  c2_info[17].context = "";
  c2_info[17].name = "plus";
  c2_info[17].dominantType = "double";
  c2_info[17].resolved = "[B]plus";
  c2_info[17].fileLength = 0U;
  c2_info[17].fileTime1 = 0U;
  c2_info[17].fileTime2 = 0U;
}

static const mxArray *c2_emlrt_marshallOut(uint8_T c2_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0));
  return c2_y;
}

static real_T c2_emlrt_marshallIn(const mxArray *c2_phaseOut, char *c2_name)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_name, sf_mex_dup(c2_phaseOut), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_phaseOut);
  return c2_y;
}

static uint8_T c2_b_emlrt_marshallIn(const mxArray
  *c2_b_is_active_c2_ProposedGaussian, char *c2_name)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_name, sf_mex_dup(c2_b_is_active_c2_ProposedGaussian), &c2_u0,
                1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_is_active_c2_ProposedGaussian);
  return c2_y;
}

static void init_io_bus_offset(void)
{
}

static void init_dsm_address_info(void)
{
}

/* SFunction Glue Code */
void sf_c2_ProposedGaussian_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4069034841U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3370497219U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3848231086U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1471683344U);
}

mxArray *sf_c2_ProposedGaussian_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,4,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(3714143773U);
    pr[1] = (double)(3581978421U);
    pr[2] = (double)(2597330206U);
    pr[3] = (double)(2631250106U);
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

static mxArray *sf_get_sim_state_info_c2_ProposedGaussian(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"phaseOut\",},{M[8],M[0],T\"is_active_c2_ProposedGaussian\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_ProposedGaussian_get_check_sum(&mxChecksum);
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
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Init",0,
                              c2_sf_marshall);
          _SFD_SET_DATA_PROPS(1,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"Bit",0,
                              NULL);
          _SFD_SET_DATA_PROPS(2,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,"LastBit",
                              0,NULL);
          _SFD_SET_DATA_PROPS(3,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "LastPhase",0,NULL);
          _SFD_SET_DATA_PROPS(4,1,1,0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "phDirection",0,NULL);
          _SFD_SET_DATA_PROPS(5,2,0,1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,
                              "phaseOut",0,NULL);
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
        _SFD_CV_INIT_EML(0,1,5,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,526);
        _SFD_CV_INIT_EML_IF(0,0,65,77,99,521);
        _SFD_CV_INIT_EML_IF(0,1,108,125,475,517);
        _SFD_CV_INIT_EML_IF(0,2,134,145,304,470);
        _SFD_CV_INIT_EML_IF(0,3,158,176,232,295);
        _SFD_CV_INIT_EML_IF(0,4,321,339,395,458);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        {
          real_T *c2_Init;
          real_T *c2_Bit;
          real_T *c2_LastBit;
          real_T *c2_LastPhase;
          real_T *c2_phDirection;
          real_T *c2_phaseOut;
          c2_phDirection = (real_T *)ssGetInputPortSignal(chartInstance.S, 4);
          c2_Init = (real_T *)ssGetInputPortSignal(chartInstance.S, 0);
          c2_LastPhase = (real_T *)ssGetInputPortSignal(chartInstance.S, 3);
          c2_LastBit = (real_T *)ssGetInputPortSignal(chartInstance.S, 2);
          c2_phaseOut = (real_T *)ssGetOutputPortSignal(chartInstance.S, 1);
          c2_Bit = (real_T *)ssGetInputPortSignal(chartInstance.S, 1);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_Init);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_Bit);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_LastBit);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_LastPhase);
          _SFD_SET_DATA_VALUE_PTR(4U, c2_phDirection);
          _SFD_SET_DATA_VALUE_PTR(5U, c2_phaseOut);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ProposedGaussianMachineNumber_,
        chartInstance.chartNumber,chartInstance.instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c2_ProposedGaussian(void *chartInstanceVar)
{
  chart_debug_initialization(chartInstance.S,0);
  initialize_params_c2_ProposedGaussian();
  initialize_c2_ProposedGaussian();
}

static void sf_opaque_enable_c2_ProposedGaussian(void *chartInstanceVar)
{
  enable_c2_ProposedGaussian();
}

static void sf_opaque_disable_c2_ProposedGaussian(void *chartInstanceVar)
{
  disable_c2_ProposedGaussian();
}

static void sf_opaque_gateway_c2_ProposedGaussian(void *chartInstanceVar)
{
  sf_c2_ProposedGaussian();
}

static mxArray* sf_opaque_get_sim_state_c2_ProposedGaussian(void
  *chartInstanceVar)
{
  mxArray *st = (mxArray *) get_sim_state_c2_ProposedGaussian();
  return st;
}

static void sf_opaque_set_sim_state_c2_ProposedGaussian(void *chartInstanceVar,
  const mxArray *st)
{
  set_sim_state_c2_ProposedGaussian(sf_mex_dup(st));
}

static void sf_opaque_terminate_c2_ProposedGaussian(void *chartInstanceVar)
{
  if (sim_mode_is_rtw_gen(chartInstance.S) || sim_mode_is_external
      (chartInstance.S)) {
    sf_clear_rtw_identifier(chartInstance.S);
  }

  finalize_c2_ProposedGaussian();
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_ProposedGaussian(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_ProposedGaussian();
  }
}

static void mdlSetWorkWidths_c2_ProposedGaussian(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable("ProposedGaussian","ProposedGaussian",2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop("ProposedGaussian","ProposedGaussian",2,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop("ProposedGaussian",
      "ProposedGaussian",2,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ProposedGaussian",
        "ProposedGaussian",2,5);
      sf_mark_chart_reusable_outputs(S,"ProposedGaussian","ProposedGaussian",2,1);
    }

    sf_set_rtw_dwork_info(S,"ProposedGaussian","ProposedGaussian",2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  }

  ssSetChecksum0(S,(3995150774U));
  ssSetChecksum1(S,(3130056911U));
  ssSetChecksum2(S,(793002458U));
  ssSetChecksum3(S,(731857841U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c2_ProposedGaussian(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ProposedGaussian", "ProposedGaussian",2);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_ProposedGaussian(SimStruct *S)
{
  chartInstance.chartInfo.chartInstance = NULL;
  chartInstance.chartInfo.isEMLChart = 1;
  chartInstance.chartInfo.chartInitialized = 0;
  chartInstance.chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_ProposedGaussian;
  chartInstance.chartInfo.initializeChart =
    sf_opaque_initialize_c2_ProposedGaussian;
  chartInstance.chartInfo.terminateChart =
    sf_opaque_terminate_c2_ProposedGaussian;
  chartInstance.chartInfo.enableChart = sf_opaque_enable_c2_ProposedGaussian;
  chartInstance.chartInfo.disableChart = sf_opaque_disable_c2_ProposedGaussian;
  chartInstance.chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_ProposedGaussian;
  chartInstance.chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_ProposedGaussian;
  chartInstance.chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_ProposedGaussian;
  chartInstance.chartInfo.zeroCrossings = NULL;
  chartInstance.chartInfo.outputs = NULL;
  chartInstance.chartInfo.derivatives = NULL;
  chartInstance.chartInfo.mdlRTW = mdlRTW_c2_ProposedGaussian;
  chartInstance.chartInfo.mdlStart = mdlStart_c2_ProposedGaussian;
  chartInstance.chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_ProposedGaussian;
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

void c2_ProposedGaussian_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_ProposedGaussian(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_ProposedGaussian(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_ProposedGaussian(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_ProposedGaussian_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
