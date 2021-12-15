//
//  fftshift.cpp
//
//  Code generation for function 'fftshift'
//


// Include files
#include "fftshift.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo bb_emlrtRSI = { 11, // lineNo
  "fftshift",                          // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\fftshift.m"// pathName 
};

static emlrtRSInfo cb_emlrtRSI = { 165,// lineNo
  "eml_fftshift",                      // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fftshift.m"// pathName 
};

static emlrtRSInfo db_emlrtRSI = { 158,// lineNo
  "eml_fftshift",                      // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fftshift.m"// pathName 
};

static emlrtRSInfo eb_emlrtRSI = { 155,// lineNo
  "eml_fftshift",                      // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fftshift.m"// pathName 
};

static emlrtRSInfo fb_emlrtRSI = { 143,// lineNo
  "eml_fftshift",                      // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fftshift.m"// pathName 
};

static emlrtRSInfo gb_emlrtRSI = { 137,// lineNo
  "eml_fftshift",                      // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fftshift.m"// pathName 
};

static emlrtRSInfo hb_emlrtRSI = { 134,// lineNo
  "eml_fftshift",                      // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fftshift.m"// pathName 
};

static emlrtRSInfo ib_emlrtRSI = { 34, // lineNo
  "eml_fftshift",                      // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\datafun\\private\\eml_fftshift.m"// pathName 
};

// Function Definitions
void fftshift(const emlrtStack *sp, coder::array<creal_T, 2U> &x)
{
  int32_T vlend2;
  int32_T npages;
  int32_T k;
  int32_T vspread;
  int32_T midoffset;
  int32_T i2;
  boolean_T overflow;
  int32_T i;
  int32_T i1;
  int32_T j;
  int32_T ia;
  int32_T ib;
  real_T xtmp_re;
  real_T xtmp_im;
  int32_T ic;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (x.size(0) > 1) {
    vlend2 = x.size(0) / 2;
    b_st.site = &ib_emlrtRSI;
    npages = 1;
    for (k = 2; k < 3; k++) {
      npages *= x.size(1);
    }

    vspread = x.size(0) - 1;
    midoffset = vlend2 - 1;
    if (vlend2 << 1 == x.size(0)) {
      i2 = 0;
      b_st.site = &hb_emlrtRSI;
      overflow = ((1 <= npages) && (npages > 2147483646));
      if (overflow) {
        c_st.site = &i_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (i = 0; i < npages; i++) {
        i1 = i2;
        i2 += vspread;
        b_st.site = &gb_emlrtRSI;
        for (j = 0; j < 1; j++) {
          i1++;
          i2++;
          ia = i1 - 1;
          ib = i1 + midoffset;
          b_st.site = &fb_emlrtRSI;
          for (k = 0; k < vlend2; k++) {
            xtmp_re = x[ia].re;
            xtmp_im = x[ia].im;
            x[ia] = x[ib];
            x[ib].re = xtmp_re;
            x[ib].im = xtmp_im;
            ia++;
            ib++;
          }
        }
      }
    } else {
      i2 = 0;
      b_st.site = &eb_emlrtRSI;
      overflow = ((1 <= npages) && (npages > 2147483646));
      if (overflow) {
        c_st.site = &i_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (i = 0; i < npages; i++) {
        i1 = i2;
        i2 += vspread;
        b_st.site = &db_emlrtRSI;
        for (j = 0; j < 1; j++) {
          i1++;
          i2++;
          ia = i1 - 1;
          ib = i1 + midoffset;
          xtmp_re = x[ib].re;
          xtmp_im = x[ib].im;
          b_st.site = &cb_emlrtRSI;
          for (k = 0; k < vlend2; k++) {
            ic = ib + 1;
            x[ib] = x[ia];
            x[ia] = x[ic];
            ia++;
            ib = ic;
          }

          x[ib].re = xtmp_re;
          x[ib].im = xtmp_im;
        }
      }
    }
  }

  st.site = &bb_emlrtRSI;
  if (x.size(1) > 1) {
    vlend2 = x.size(1) / 2;
    b_st.site = &ib_emlrtRSI;
    npages = 1;
    for (k = 0; k < 1; k++) {
      npages *= x.size(0);
    }

    vspread = (x.size(1) - 1) * npages;
    midoffset = vlend2 * npages - 1;
    if (vlend2 << 1 == x.size(1)) {
      i2 = 0;
      b_st.site = &hb_emlrtRSI;
      overflow = ((1 <= npages) && (npages > 2147483646));
      for (i = 0; i < 1; i++) {
        i1 = i2;
        i2 += vspread;
        b_st.site = &gb_emlrtRSI;
        if (overflow) {
          c_st.site = &i_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (j = 0; j < npages; j++) {
          i1++;
          i2++;
          ia = i1 - 1;
          ib = i1 + midoffset;
          b_st.site = &fb_emlrtRSI;
          for (k = 0; k < vlend2; k++) {
            xtmp_re = x[ia].re;
            xtmp_im = x[ia].im;
            x[ia] = x[ib];
            x[ib].re = xtmp_re;
            x[ib].im = xtmp_im;
            ia += npages;
            ib += npages;
          }
        }
      }
    } else {
      i2 = 0;
      b_st.site = &eb_emlrtRSI;
      overflow = ((1 <= npages) && (npages > 2147483646));
      for (i = 0; i < 1; i++) {
        i1 = i2;
        i2 += vspread;
        b_st.site = &db_emlrtRSI;
        if (overflow) {
          c_st.site = &i_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }

        for (j = 0; j < npages; j++) {
          i1++;
          i2++;
          ia = i1 - 1;
          ib = i1 + midoffset;
          xtmp_re = x[ib].re;
          xtmp_im = x[ib].im;
          b_st.site = &cb_emlrtRSI;
          for (k = 0; k < vlend2; k++) {
            ic = ib + npages;
            x[ib] = x[ia];
            x[ia] = x[ic];
            ia += npages;
            ib = ic;
          }

          x[ib].re = xtmp_re;
          x[ib].im = xtmp_im;
        }
      }
    }
  }
}

// End of code generation (fftshift.cpp)
