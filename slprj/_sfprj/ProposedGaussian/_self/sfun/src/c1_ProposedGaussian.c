/* Include files */

#include "blascompat32.h"
#include "ProposedGaussian_sfun.h"
#include "c1_ProposedGaussian.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ProposedGaussian_sfun_debug_macros.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[5] = { "nargin", "nargout", "phase",
  "rand", "i_channel_data" };

/* Function Declarations */
static void initialize_c1_ProposedGaussian(SFc1_ProposedGaussianInstanceStruct
  *chartInstance);
static void initialize_params_c1_ProposedGaussian
  (SFc1_ProposedGaussianInstanceStruct *chartInstance);
static void enable_c1_ProposedGaussian(SFc1_ProposedGaussianInstanceStruct
  *chartInstance);
static void disable_c1_ProposedGaussian(SFc1_ProposedGaussianInstanceStruct
  *chartInstance);
static void c1_update_debugger_state_c1_ProposedGaussian
  (SFc1_ProposedGaussianInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_ProposedGaussian
  (SFc1_ProposedGaussianInstanceStruct *chartInstance);
static void set_sim_state_c1_ProposedGaussian
  (SFc1_ProposedGaussianInstanceStruct *chartInstance, const mxArray *c1_st);
static void finalize_c1_ProposedGaussian(SFc1_ProposedGaussianInstanceStruct
  *chartInstance);
static void sf_c1_ProposedGaussian(SFc1_ProposedGaussianInstanceStruct
  *chartInstance);
static void initSimStructsc1_ProposedGaussian
  (SFc1_ProposedGaussianInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_ProposedGaussianInstanceStruct
  *chartInstance, const mxArray *c1_i_channel_data, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_ProposedGaussianInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_c_emlrt_marshallIn(SFc1_ProposedGaussianInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static uint8_T c1_d_emlrt_marshallIn(SFc1_ProposedGaussianInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_ProposedGaussian, const
  char_T *c1_identifier);
static uint8_T c1_e_emlrt_marshallIn(SFc1_ProposedGaussianInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void init_dsm_address_info(SFc1_ProposedGaussianInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_ProposedGaussian(SFc1_ProposedGaussianInstanceStruct
  *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_is_active_c1_ProposedGaussian = 0U;
}

static void initialize_params_c1_ProposedGaussian
  (SFc1_ProposedGaussianInstanceStruct *chartInstance)
{
}

static void enable_c1_ProposedGaussian(SFc1_ProposedGaussianInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_ProposedGaussian(SFc1_ProposedGaussianInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_ProposedGaussian
  (SFc1_ProposedGaussianInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_ProposedGaussian
  (SFc1_ProposedGaussianInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T *c1_i_channel_data;
  c1_i_channel_data = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(2));
  c1_hoistedGlobal = *c1_i_channel_data;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_ProposedGaussian;
  c1_b_u = c1_b_hoistedGlobal;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 3, 0U, 0U, 0U, 0));
  sf_mex_setcell(c1_y, 1, c1_c_y);
  sf_mex_assign(&c1_st, c1_y);
  return c1_st;
}

static void set_sim_state_c1_ProposedGaussian
  (SFc1_ProposedGaussianInstanceStruct *chartInstance, const mxArray *c1_st)
{
  const mxArray *c1_u;
  real_T *c1_i_channel_data;
  c1_i_channel_data = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_i_channel_data = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "i_channel_data");
  chartInstance->c1_is_active_c1_ProposedGaussian = c1_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
     "is_active_c1_ProposedGaussian");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_ProposedGaussian(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_ProposedGaussian(SFc1_ProposedGaussianInstanceStruct
  *chartInstance)
{
}

static void sf_c1_ProposedGaussian(SFc1_ProposedGaussianInstanceStruct
  *chartInstance)
{
  real_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_phase;
  real_T c1_rand;
  uint32_T c1_debug_family_var_map[5];
  real_T c1_nargin = 2.0;
  real_T c1_nargout = 1.0;
  real_T c1_i_channel_data;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T *c1_b_phase;
  real_T *c1_b_i_channel_data;
  real_T *c1_b_rand;
  c1_b_rand = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_i_channel_data = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_b_phase = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c1_b_phase, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_b_i_channel_data, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_rand, 2U);
  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_b_phase;
  c1_b_hoistedGlobal = *c1_b_rand;
  c1_phase = c1_hoistedGlobal;
  c1_rand = c1_b_hoistedGlobal;
  sf_debug_symbol_scope_push_eml(0U, 5U, 5U, c1_debug_family_names,
    c1_debug_family_var_map);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml_importable(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  sf_debug_symbol_scope_add_eml(&c1_phase, 2U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml(&c1_rand, 3U, c1_sf_marshallOut);
  sf_debug_symbol_scope_add_eml_importable(&c1_i_channel_data, 4U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 3);
  if (CV_EML_IF(0, 0, c1_rand > 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 4);
    c1_x = c1_phase;
    c1_i_channel_data = c1_x;
    c1_b_x = c1_i_channel_data;
    c1_i_channel_data = c1_b_x;
    c1_i_channel_data = muDoubleScalarCos(c1_i_channel_data);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 6);
    c1_c_x = c1_phase;
    c1_i_channel_data = c1_c_x;
    c1_d_x = c1_i_channel_data;
    c1_i_channel_data = c1_d_x;
    c1_i_channel_data = muDoubleScalarSin(c1_i_channel_data);
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -6);
  sf_debug_symbol_scope_pop();
  *c1_b_i_channel_data = c1_i_channel_data;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  sf_debug_check_for_state_inconsistency(_ProposedGaussianMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_ProposedGaussian
  (SFc1_ProposedGaussianInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ProposedGaussianInstanceStruct *chartInstance;
  chartInstance = (SFc1_ProposedGaussianInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_ProposedGaussianInstanceStruct
  *chartInstance, const mxArray *c1_i_channel_data, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_i_channel_data),
    &c1_thisId);
  sf_mex_destroy(&c1_i_channel_data);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_ProposedGaussianInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_i_channel_data;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_ProposedGaussianInstanceStruct *chartInstance;
  chartInstance = (SFc1_ProposedGaussianInstanceStruct *)chartInstanceVoid;
  c1_i_channel_data = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_i_channel_data),
    &c1_thisId);
  sf_mex_destroy(&c1_i_channel_data);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_ProposedGaussian_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[4];
  c1_ResolvedFunctionInfo (*c1_b_info)[4];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i0;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_b_info = (c1_ResolvedFunctionInfo (*)[4])c1_info;
  (*c1_b_info)[0].context = "";
  (*c1_b_info)[0].name = "cos";
  (*c1_b_info)[0].dominantType = "double";
  (*c1_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c1_b_info)[0].fileTimeLo = 1719026944U;
  (*c1_b_info)[0].fileTimeHi = 30108061U;
  (*c1_b_info)[0].mFileTimeLo = 0U;
  (*c1_b_info)[0].mFileTimeHi = 0U;
  (*c1_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c1_b_info)[1].name = "eml_scalar_cos";
  (*c1_b_info)[1].dominantType = "double";
  (*c1_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c1_b_info)[1].fileTimeLo = 1879026944U;
  (*c1_b_info)[1].fileTimeHi = 30108061U;
  (*c1_b_info)[1].mFileTimeLo = 0U;
  (*c1_b_info)[1].mFileTimeHi = 0U;
  (*c1_b_info)[2].context = "";
  (*c1_b_info)[2].name = "sin";
  (*c1_b_info)[2].dominantType = "double";
  (*c1_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c1_b_info)[2].fileTimeLo = 2159026944U;
  (*c1_b_info)[2].fileTimeHi = 30108061U;
  (*c1_b_info)[2].mFileTimeLo = 0U;
  (*c1_b_info)[2].mFileTimeHi = 0U;
  (*c1_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c1_b_info)[3].name = "eml_scalar_sin";
  (*c1_b_info)[3].dominantType = "double";
  (*c1_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c1_b_info)[3].fileTimeLo = 2019026944U;
  (*c1_b_info)[3].fileTimeHi = 30108061U;
  (*c1_b_info)[3].mFileTimeLo = 0U;
  (*c1_b_info)[3].mFileTimeHi = 0U;
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 4));
  for (c1_i0 = 0; c1_i0 < 4; c1_i0++) {
    c1_r0 = &c1_info[c1_i0];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i0);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i0);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0);
  return c1_nameCaptureInfo;
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_ProposedGaussianInstanceStruct *chartInstance;
  chartInstance = (SFc1_ProposedGaussianInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0));
  sf_mex_assign(&c1_mxArrayOutData, c1_y);
  return c1_mxArrayOutData;
}

static int32_T c1_c_emlrt_marshallIn(SFc1_ProposedGaussianInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i1, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_ProposedGaussianInstanceStruct *chartInstance;
  chartInstance = (SFc1_ProposedGaussianInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static uint8_T c1_d_emlrt_marshallIn(SFc1_ProposedGaussianInstanceStruct
  *chartInstance, const mxArray *c1_b_is_active_c1_ProposedGaussian, const
  char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_is_active_c1_ProposedGaussian), &c1_thisId);
  sf_mex_destroy(&c1_b_is_active_c1_ProposedGaussian);
  return c1_y;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_ProposedGaussianInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void init_dsm_address_info(SFc1_ProposedGaussianInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c1_ProposedGaussian_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2443212618U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2648656950U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3111175560U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1023067001U);
}

mxArray *sf_c1_ProposedGaussian_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateDoubleMatrix(4,1,mxREAL);
    double *pr = mxGetPr(mxChecksum);
    pr[0] = (double)(1627125966U);
    pr[1] = (double)(2153852931U);
    pr[2] = (double)(1379564004U);
    pr[3] = (double)(3086091769U);
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

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c1_ProposedGaussian(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[6],T\"i_channel_data\",},{M[8],M[0],T\"is_active_c1_ProposedGaussian\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_ProposedGaussian_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_ProposedGaussianInstanceStruct *chartInstance;
    chartInstance = (SFc1_ProposedGaussianInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (_ProposedGaussianMachineNumber_,
           1,
           1,
           1,
           3,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_ProposedGaussianMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (_ProposedGaussianMachineNumber_,chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(_ProposedGaussianMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"phase");
          _SFD_SET_DATA_PROPS(1,2,0,1,"i_channel_data");
          _SFD_SET_DATA_PROPS(2,1,1,0,"rand");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,134);
        _SFD_CV_INIT_EML_IF(0,0,43,54,88,129);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c1_phase;
          real_T *c1_i_channel_data;
          real_T *c1_rand;
          c1_rand = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_i_channel_data = (real_T *)ssGetOutputPortSignal(chartInstance->S,
            1);
          c1_phase = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_phase);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_i_channel_data);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_rand);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(_ProposedGaussianMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static void sf_opaque_initialize_c1_ProposedGaussian(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_ProposedGaussianInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_ProposedGaussian((SFc1_ProposedGaussianInstanceStruct*)
    chartInstanceVar);
  initialize_c1_ProposedGaussian((SFc1_ProposedGaussianInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c1_ProposedGaussian(void *chartInstanceVar)
{
  enable_c1_ProposedGaussian((SFc1_ProposedGaussianInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_ProposedGaussian(void *chartInstanceVar)
{
  disable_c1_ProposedGaussian((SFc1_ProposedGaussianInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_ProposedGaussian(void *chartInstanceVar)
{
  sf_c1_ProposedGaussian((SFc1_ProposedGaussianInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_ProposedGaussian(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_ProposedGaussian
    ((SFc1_ProposedGaussianInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ProposedGaussian();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c1_ProposedGaussian(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_ProposedGaussian();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_ProposedGaussian((SFc1_ProposedGaussianInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_ProposedGaussian(SimStruct* S)
{
  return sf_internal_get_sim_state_c1_ProposedGaussian(S);
}

static void sf_opaque_set_sim_state_c1_ProposedGaussian(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c1_ProposedGaussian(S, st);
}

static void sf_opaque_terminate_c1_ProposedGaussian(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_ProposedGaussianInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c1_ProposedGaussian((SFc1_ProposedGaussianInstanceStruct*)
      chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_ProposedGaussian((SFc1_ProposedGaussianInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_ProposedGaussian(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_ProposedGaussian((SFc1_ProposedGaussianInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_ProposedGaussian(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,"ProposedGaussian","ProposedGaussian",1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,"ProposedGaussian","ProposedGaussian",1,
                "RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,"ProposedGaussian",
      "ProposedGaussian",1,"gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,"ProposedGaussian",
        "ProposedGaussian",1,2);
      sf_mark_chart_reusable_outputs(S,"ProposedGaussian","ProposedGaussian",1,1);
    }

    sf_set_rtw_dwork_info(S,"ProposedGaussian","ProposedGaussian",1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(787770629U));
  ssSetChecksum1(S,(3372377191U));
  ssSetChecksum2(S,(1135768261U));
  ssSetChecksum3(S,(225363846U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
}

static void mdlRTW_c1_ProposedGaussian(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    sf_write_symbol_mapping(S, "ProposedGaussian", "ProposedGaussian",1);
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_ProposedGaussian(SimStruct *S)
{
  SFc1_ProposedGaussianInstanceStruct *chartInstance;
  chartInstance = (SFc1_ProposedGaussianInstanceStruct *)malloc(sizeof
    (SFc1_ProposedGaussianInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_ProposedGaussianInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_ProposedGaussian;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_ProposedGaussian;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_ProposedGaussian;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_ProposedGaussian;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_ProposedGaussian;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_ProposedGaussian;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_ProposedGaussian;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_ProposedGaussian;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_ProposedGaussian;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_ProposedGaussian;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_ProposedGaussian;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c1_ProposedGaussian_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_ProposedGaussian(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_ProposedGaussian(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_ProposedGaussian(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_ProposedGaussian_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
