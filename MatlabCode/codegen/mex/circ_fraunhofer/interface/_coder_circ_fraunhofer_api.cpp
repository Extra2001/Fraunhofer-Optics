//
//  _coder_circ_fraunhofer_api.cpp
//
//  Code generation for function '_coder_circ_fraunhofer_api'
//


// Include files
#include "_coder_circ_fraunhofer_api.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *D, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u);

// Function Definitions
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *D, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = const_cast<const char *>(identifier);
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(D), &thisId);
  emlrtDestroyArray(&D);
  return y;
}

static const mxArray *emlrt_marshallOut(const coder::array<real_T, 2U> &u)
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &(((coder::array<real_T, 2U> *)&u)->data())[0]);
  emlrtSetDimensions((mxArray *)m, ((coder::array<real_T, 2U> *)&u)->size(), 2);
  emlrtAssign(&y, m);
  return y;
}

void circ_fraunhofer_api(const mxArray * const prhs[7], int32_T, const mxArray
  *plhs[1])
{
  real_T D;
  real_T N;
  real_T sita;
  real_T lambda;
  real_T f;
  real_T xd;
  real_T yd;
  coder::array<real_T, 2U> b_I;
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);

  // Marshall function inputs
  D = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "D");
  N = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "N");
  sita = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sita");
  lambda = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "lambda");
  f = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "f");
  xd = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "xd");
  yd = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "yd");

  // Invoke the target function
  circ_fraunhofer(&st, D, N, sita, lambda, f, xd, yd, b_I);

  // Marshall function outputs
  b_I.no_free();
  plhs[0] = emlrt_marshallOut(b_I);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

// End of code generation (_coder_circ_fraunhofer_api.cpp)
