//
//  power.cpp
//
//  Code generation for function 'power'
//


// Include files
#include "power.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo l_emlrtRSI = { 70,  // lineNo
  "power",                             // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\power.m"// pathName 
};

static emlrtRSInfo m_emlrtRSI = { 79,  // lineNo
  "fltpower",                          // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\power.m"// pathName 
};

static emlrtRSInfo n_emlrtRSI = { 66,  // lineNo
  "applyBinaryScalarFunction",         // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"// pathName 
};

static emlrtRSInfo o_emlrtRSI = { 188, // lineNo
  "flatIter",                          // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\applyBinaryScalarFunction.m"// pathName 
};

static emlrtRTEInfo q_emlrtRTEI = { 79,// lineNo
  5,                                   // colNo
  "power",                             // fName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\power.m"// pName
};

// Function Definitions
void power(const emlrtStack *sp, const coder::array<real_T, 2U> &a, coder::array<
           real_T, 2U> &y)
{
  uint32_T unnamed_idx_0;
  uint32_T unnamed_idx_1;
  int32_T nx;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &l_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &m_emlrtRSI;
  unnamed_idx_0 = static_cast<uint32_T>(a.size(0));
  unnamed_idx_1 = static_cast<uint32_T>(a.size(1));
  y.set_size((&q_emlrtRTEI), (&b_st), (static_cast<int32_T>(unnamed_idx_0)), (
              static_cast<int32_T>(unnamed_idx_1)));
  c_st.site = &n_emlrtRSI;
  nx = static_cast<int32_T>(unnamed_idx_0) * static_cast<int32_T>(unnamed_idx_1);
  d_st.site = &o_emlrtRSI;
  overflow = ((1 <= nx) && (nx > 2147483646));
  if (overflow) {
    e_st.site = &i_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (int32_T k = 0; k < nx; k++) {
    y[k] = a[k] * a[k];
  }
}

// End of code generation (power.cpp)
