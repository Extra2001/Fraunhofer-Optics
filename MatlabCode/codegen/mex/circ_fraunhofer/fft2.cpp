//
//  fft2.cpp
//
//  Code generation for function 'fft2'
//


// Include files
#include "fft2.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo r_emlrtRSI = { 60,  // lineNo
  "fft2",                              // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\fft2.m"// pathName 
};

static emlrtRSInfo s_emlrtRSI = { 23,  // lineNo
  "fft",                               // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+fft\\fft.m"// pathName 
};

static emlrtRSInfo t_emlrtRSI = { 52,  // lineNo
  "executeCallback",                   // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\+fft\\fft.m"// pathName 
};

static emlrtRSInfo u_emlrtRSI = { 44,  // lineNo
  "Custom1DFFTCallback/fft",           // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\Custom1DFFTCallback.m"// pathName 
};

static emlrtRSInfo v_emlrtRSI = { 56,  // lineNo
  "Custom1DFFTCallback/fftLoop",       // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\Custom1DFFTCallback.m"// pathName 
};

static emlrtRSInfo w_emlrtRSI = { 57,  // lineNo
  "Custom1DFFTCallback/fftLoop",       // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\Custom1DFFTCallback.m"// pathName 
};

static emlrtRSInfo x_emlrtRSI = { 54,  // lineNo
  "Custom1DFFTCallback/fftLoop",       // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\Custom1DFFTCallback.m"// pathName 
};

static emlrtRTEInfo r_emlrtRTEI = { 56,// lineNo
  15,                                  // colNo
  "Custom1DFFTCallback",               // fName
  "C:\\Program Files\\Matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\Custom1DFFTCallback.m"// pName 
};

static emlrtRTEInfo s_emlrtRTEI = { 54,// lineNo
  13,                                  // colNo
  "Custom1DFFTCallback",               // fName
  "C:\\Program Files\\Matlab\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\Custom1DFFTCallback.m"// pName 
};

static emlrtRTEInfo t_emlrtRTEI = { 60,// lineNo
  1,                                   // colNo
  "fft2",                              // fName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\fft2.m"// pName 
};

// Function Definitions
void fft2(const emlrtStack *sp, const coder::array<creal_T, 2U> &x, coder::array<
          creal_T, 2U> &y)
{
  int32_T lens[2];
  boolean_T guard1 = false;
  int32_T k;
  coder::array<creal_T, 2U> acc;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  lens[0] = x.size(0);
  lens[1] = x.size(1);
  st.site = &r_emlrtRSI;
  guard1 = false;
  if ((x.size(0) == 0) || (x.size(1) == 0)) {
    guard1 = true;
  } else {
    boolean_T b_x;
    boolean_T exitg1;
    b_x = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (0 == lens[k]) {
        b_x = true;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (!b_x) {
      uint32_T xSize_idx_1;
      b_st.site = &s_emlrtRSI;
      c_st.site = &t_emlrtRSI;
      d_st.site = &u_emlrtRSI;
      e_st.site = &v_emlrtRSI;
      emlrtFFTWSetNumThreads(4);
      xSize_idx_1 = static_cast<uint32_T>(x.size(1));
      acc.set_size((&r_emlrtRTEI), (&e_st), x.size(0), (static_cast<int32_T>
        (xSize_idx_1)));
      emlrtFFTW_1D_C2C((real_T *)&(((coder::array<creal_T, 2U> *)&x)->data())[0],
                       (real_T *)&(acc.data())[0], 1, x.size(0), x.size(0),
                       static_cast<int32_T>(xSize_idx_1), -1);
      e_st.site = &w_emlrtRSI;
      f_st.site = &x_emlrtRSI;
      emlrtFFTWSetNumThreads(4);
      xSize_idx_1 = static_cast<uint32_T>(acc.size(0));
      y.set_size((&s_emlrtRTEI), (&f_st), (static_cast<int32_T>(xSize_idx_1)),
                 x.size(1));
      emlrtFFTW_1D_C2C((real_T *)&(acc.data())[0], (real_T *)&(y.data())[0],
                       static_cast<int32_T>(xSize_idx_1), x.size(1), acc.size(1),
                       static_cast<int32_T>(xSize_idx_1), -1);
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    y.set_size((&t_emlrtRTEI), (&st), x.size(0), x.size(1));
    k = x.size(0) * x.size(1);
    for (int32_T i = 0; i < k; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (fft2.cpp)
