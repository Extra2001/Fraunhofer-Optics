//
//  circ_fraunhofer.cpp
//
//  Code generation for function 'circ_fraunhofer'
//


// Include files
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "fft2.h"
#include "fftshift.h"
#include "mwmathutil.h"
#include "power.h"
#include "rt_nonfinite.h"

// Variable Definitions
static emlrtRSInfo emlrtRSI = { 6,     // lineNo
  "circ_fraunhofer",                   // fcnName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pathName 
};

static emlrtRSInfo b_emlrtRSI = { 7,   // lineNo
  "circ_fraunhofer",                   // fcnName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pathName 
};

static emlrtRSInfo c_emlrtRSI = { 8,   // lineNo
  "circ_fraunhofer",                   // fcnName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pathName 
};

static emlrtRSInfo d_emlrtRSI = { 20,  // lineNo
  "circ_fraunhofer",                   // fcnName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pathName 
};

static emlrtRSInfo e_emlrtRSI = { 28,  // lineNo
  "colon",                             // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"// pathName 
};

static emlrtRSInfo f_emlrtRSI = { 103, // lineNo
  "colon",                             // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"// pathName 
};

static emlrtRSInfo g_emlrtRSI = { 288, // lineNo
  "eml_float_colon",                   // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"// pathName 
};

static emlrtRSInfo j_emlrtRSI = { 31,  // lineNo
  "meshgrid",                          // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m"// pathName 
};

static emlrtRSInfo k_emlrtRSI = { 32,  // lineNo
  "meshgrid",                          // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\elmat\\meshgrid.m"// pathName 
};

static emlrtRSInfo p_emlrtRSI = { 16,  // lineNo
  "sqrt",                              // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"// pathName 
};

static emlrtRSInfo q_emlrtRSI = { 33,  // lineNo
  "applyScalarFunctionInPlace",        // fcnName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunctionInPlace.m"// pathName 
};

static emlrtBCInfo emlrtBCI = { -1,    // iFirst
  -1,                                  // iLast
  10,                                  // lineNo
  5,                                   // colNo
  "aperture",                          // aName
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo emlrtECI = { 2,     // nDims
  8,                                   // lineNo
  14,                                  // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo emlrtRTEI = { 12,  // lineNo
  12,                                  // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtBCInfo b_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  14,                                  // lineNo
  36,                                  // colNo
  "aperture",                          // aName
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo c_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  14,                                  // lineNo
  18,                                  // colNo
  "aperture",                          // aName
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo b_emlrtECI = { -1,  // nDims
  14,                                  // lineNo
  9,                                   // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo b_emlrtRTEI = { 16,// lineNo
  12,                                  // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtBCInfo d_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  18,                                  // lineNo
  39,                                  // colNo
  "aperture",                          // aName
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m",// pName 
  0                                    // checkKind
};

static emlrtBCInfo e_emlrtBCI = { -1,  // iFirst
  -1,                                  // iLast
  18,                                  // lineNo
  21,                                  // colNo
  "aperture",                          // aName
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m",// pName 
  0                                    // checkKind
};

static emlrtECInfo c_emlrtECI = { -1,  // nDims
  18,                                  // lineNo
  9,                                   // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtECInfo d_emlrtECI = { 2,   // nDims
  21,                                  // lineNo
  12,                                  // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo c_emlrtRTEI = { 13,// lineNo
  9,                                   // colNo
  "sqrt",                              // fName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"// pName
};

static emlrtRTEInfo d_emlrtRTEI = { 405,// lineNo
  15,                                  // colNo
  "assert_pmaxsize",                   // fName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"// pName
};

static emlrtRTEInfo f_emlrtRTEI = { 103,// lineNo
  9,                                   // colNo
  "colon",                             // fName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"// pName
};

static emlrtRTEInfo g_emlrtRTEI = { 28,// lineNo
  9,                                   // colNo
  "colon",                             // fName
  "C:\\Program Files\\Matlab\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"// pName
};

static emlrtRTEInfo h_emlrtRTEI = { 6, // lineNo
  5,                                   // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo i_emlrtRTEI = { 7, // lineNo
  5,                                   // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo j_emlrtRTEI = { 9, // lineNo
  5,                                   // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo k_emlrtRTEI = { 1, // lineNo
  14,                                  // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo l_emlrtRTEI = { 11,// lineNo
  5,                                   // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo m_emlrtRTEI = { 14,// lineNo
  27,                                  // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo n_emlrtRTEI = { 18,// lineNo
  27,                                  // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo o_emlrtRTEI = { 21,// lineNo
  20,                                  // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

static emlrtRTEInfo p_emlrtRTEI = { 21,// lineNo
  5,                                   // colNo
  "circ_fraunhofer",                   // fName
  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m"// pName 
};

// Function Definitions
void circ_fraunhofer(const emlrtStack *sp, real_T D, real_T N, real_T sita,
                     real_T lambda, real_T f, real_T xd, real_T yd, coder::array<
                     real_T, 2U> &b_I)
{
  real_T x;
  real_T absx;
  real_T delta;
  coder::array<real_T, 2U> b_x;
  int32_T nx;
  int32_T i;
  coder::array<real_T, 2U> aperture;
  coder::array<real_T, 2U> b_y1;
  coder::array<real_T, 2U> r;
  boolean_T overflow;
  int32_T nm1d2;
  int32_T k;
  int32_T x_tmp;
  coder::array<int32_T, 1U> b_r;
  coder::array<creal_T, 2U> b_aperture;
  int32_T iv[2];
  coder::array<creal_T, 2U> result;
  coder::array<creal_T, 2U> r1;
  coder::array<creal_T, 1U> r2;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  covrtLogFcn(&emlrtCoverageInstance, 0, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 0);
  if (muDoubleScalarIsInf(sita) || muDoubleScalarIsNaN(sita)) {
    x = rtNaN;
  } else {
    int8_T n;
    x = muDoubleScalarRem(sita, 360.0);
    absx = muDoubleScalarAbs(x);
    if (absx > 180.0) {
      if (x > 0.0) {
        x -= 360.0;
      } else {
        x += 360.0;
      }

      absx = muDoubleScalarAbs(x);
    }

    if (absx <= 45.0) {
      x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (x > 0.0) {
        x = 0.017453292519943295 * (x - 90.0);
        n = 1;
      } else {
        x = 0.017453292519943295 * (x + 90.0);
        n = -1;
      }
    } else if (x > 0.0) {
      x = 0.017453292519943295 * (x - 180.0);
      n = 2;
    } else {
      x = 0.017453292519943295 * (x + 180.0);
      n = -2;
    }

    x = muDoubleScalarTan(x);
    if ((n == 1) || (n == -1)) {
      absx = 1.0 / x;
      x = -(1.0 / x);
      if (muDoubleScalarIsInf(x) && (n == 1)) {
        x = absx;
      }
    }
  }

  sita = muDoubleScalarAtan((yd + f * x) / f);
  delta = f * N * lambda / 0.01 / N;
  st.site = &emlrtRSI;
  absx = -N / 2.0;
  x = N / 2.0 - 1.0;
  b_st.site = &e_emlrtRSI;
  if (muDoubleScalarIsNaN(absx) || muDoubleScalarIsNaN(x)) {
    b_x.set_size((&g_emlrtRTEI), (&b_st), 1, 1);
    b_x[0] = rtNaN;
  } else if (x < absx) {
    b_x.set_size((&g_emlrtRTEI), (&b_st), 1, 0);
  } else if ((muDoubleScalarIsInf(absx) || muDoubleScalarIsInf(x)) && (absx == x))
  {
    b_x.set_size((&g_emlrtRTEI), (&b_st), 1, 1);
    b_x[0] = rtNaN;
  } else if (muDoubleScalarFloor(absx) == absx) {
    nx = static_cast<int32_T>(muDoubleScalarFloor(x - absx));
    b_x.set_size((&g_emlrtRTEI), (&b_st), 1, (nx + 1));
    for (i = 0; i <= nx; i++) {
      b_x[i] = absx + static_cast<real_T>(i);
    }
  } else {
    real_T ndbl;
    real_T apnd;
    real_T cdiff;
    real_T absa;
    real_T absb;
    c_st.site = &f_emlrtRSI;
    ndbl = muDoubleScalarFloor((x - absx) + 0.5);
    apnd = absx + ndbl;
    cdiff = apnd - x;
    absa = muDoubleScalarAbs(absx);
    absb = muDoubleScalarAbs(x);
    if (absa > absb) {
      absb = absa;
    }

    if (muDoubleScalarAbs(cdiff) < 4.4408920985006262E-16 * absb) {
      ndbl++;
      apnd = x;
    } else if (cdiff > 0.0) {
      apnd = absx + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      nx = static_cast<int32_T>(ndbl);
    } else {
      nx = 0;
    }

    d_st.site = &g_emlrtRSI;
    if (ndbl > 2.147483647E+9) {
      emlrtErrorWithMessageIdR2018a(&d_st, &d_emlrtRTEI, "Coder:MATLAB:pmaxsize",
        "Coder:MATLAB:pmaxsize", 0);
    }

    b_x.set_size((&f_emlrtRTEI), (&c_st), 1, nx);
    if (nx > 0) {
      b_x[0] = absx;
      if (nx > 1) {
        b_x[nx - 1] = apnd;
        nm1d2 = (nx - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          x_tmp = k + 1;
          b_x[k + 1] = absx + static_cast<real_T>(x_tmp);
          b_x[(nx - k) - 2] = apnd - static_cast<real_T>(x_tmp);
        }

        if (nm1d2 << 1 == nx - 1) {
          b_x[nm1d2] = (absx + apnd) / 2.0;
        } else {
          b_x[nm1d2] = absx + static_cast<real_T>(nm1d2);
          b_x[nm1d2 + 1] = apnd - static_cast<real_T>(nm1d2);
        }
      }
    }
  }

  i = b_x.size(0) * b_x.size(1);
  b_x.set_size((&h_emlrtRTEI), sp, 1, b_x.size(1));
  nx = i - 1;
  for (i = 0; i <= nx; i++) {
    b_x[i] = b_x[i] * delta;
  }

  st.site = &b_emlrtRSI;
  nx = b_x.size(1);
  aperture.set_size((&i_emlrtRTEI), (&st), b_x.size(1), b_x.size(1));
  b_y1.set_size((&i_emlrtRTEI), (&st), b_x.size(1), b_x.size(1));
  if (b_x.size(1) != 0) {
    b_st.site = &j_emlrtRSI;
    if (b_x.size(1) > 2147483646) {
      c_st.site = &i_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }

    if (0 <= b_x.size(1) - 1) {
      overflow = ((1 <= b_x.size(1)) && (b_x.size(1) > 2147483646));
    }

    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      b_st.site = &k_emlrtRSI;
      if (overflow) {
        c_st.site = &i_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (x_tmp = 0; x_tmp < nx; x_tmp++) {
        aperture[x_tmp + aperture.size(0) * nm1d2] = b_x[nm1d2];
        b_y1[x_tmp + b_y1.size(0) * nm1d2] = b_x[x_tmp];
      }
    }
  }

  st.site = &c_emlrtRSI;
  power(&st, aperture, r);
  st.site = &c_emlrtRSI;
  power(&st, b_y1, aperture);
  emlrtSizeEqCheckNDR2012b(r.size(), aperture.size(), &emlrtECI, sp);
  st.site = &c_emlrtRSI;
  nx = r.size(0) * r.size(1);
  for (i = 0; i < nx; i++) {
    r[i] = r[i] + aperture[i];
  }

  overflow = false;
  i = r.size(0) * r.size(1);
  for (k = 0; k < i; k++) {
    if (overflow || (r[k] < 0.0)) {
      overflow = true;
    }
  }

  if (overflow) {
    emlrtErrorWithMessageIdR2018a(&st, &c_emlrtRTEI,
      "Coder:toolbox:ElFunDomainError", "Coder:toolbox:ElFunDomainError", 3, 4,
      4, "sqrt");
  }

  b_st.site = &p_emlrtRSI;
  nx = r.size(0) * r.size(1);
  c_st.site = &q_emlrtRSI;
  overflow = ((1 <= nx) && (nx > 2147483646));
  if (overflow) {
    d_st.site = &i_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k < nx; k++) {
    r[k] = muDoubleScalarSqrt(r[k]);
  }

  aperture.set_size((&j_emlrtRTEI), sp, r.size(0), r.size(1));
  absx = D / 2.0;
  nx = r.size(0) * r.size(1);
  for (i = 0; i < nx; i++) {
    aperture[i] = (r[i] < absx);
  }

  nm1d2 = r.size(0) * r.size(1) - 1;
  nx = 0;
  for (x_tmp = 0; x_tmp <= nm1d2; x_tmp++) {
    if (r[x_tmp] == D / 2.0) {
      nx++;
    }
  }

  b_r.set_size((&k_emlrtRTEI), sp, nx);
  nx = 0;
  for (x_tmp = 0; x_tmp <= nm1d2; x_tmp++) {
    if (r[x_tmp] == D / 2.0) {
      b_r[nx] = x_tmp + 1;
      nx++;
    }
  }

  nx = b_r.size(0) - 1;
  i = aperture.size(0) * aperture.size(1);
  for (nm1d2 = 0; nm1d2 <= nx; nm1d2++) {
    if ((b_r[nm1d2] < 1) || (b_r[nm1d2] > i)) {
      emlrtDynamicBoundsCheckR2012b(b_r[nm1d2], 1, i, &emlrtBCI, sp);
    }

    aperture[b_r[nm1d2] - 1] = 0.5;
  }

  b_aperture.set_size((&l_emlrtRTEI), sp, aperture.size(0), aperture.size(1));
  nx = aperture.size(0) * aperture.size(1);
  for (i = 0; i < nx; i++) {
    b_aperture[i].re = aperture[i];
    b_aperture[i].im = 0.0;
  }

  i = static_cast<int32_T>(N);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, N, mxDOUBLE_CLASS, static_cast<int32_T>
    (N), &emlrtRTEI, sp);
  if (0 <= i - 1) {
    iv[0] = 1;
  }

  for (x_tmp = 0; x_tmp < i; x_tmp++) {
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 1);
    absx = ((static_cast<real_T>(x_tmp) + 1.0) - N / 2.0) * delta * 2.0 *
      3.1415926535897931 * muDoubleScalarSin(sita) / lambda;
    nm1d2 = x_tmp + 1;
    if ((nm1d2 < 1) || (nm1d2 > b_aperture.size(0))) {
      emlrtDynamicBoundsCheckR2012b(nm1d2, 1, b_aperture.size(0), &c_emlrtBCI,
        sp);
    }

    nm1d2 = static_cast<int32_T>(x_tmp + 1U);
    if ((nm1d2 < 1) || (nm1d2 > b_aperture.size(0))) {
      emlrtDynamicBoundsCheckR2012b(nm1d2, 1, b_aperture.size(0), &b_emlrtBCI,
        sp);
    }

    x = muDoubleScalarSin(absx);
    absx = muDoubleScalarCos(absx) + 0.0 * x;
    nx = b_aperture.size(1);
    r1.set_size((&m_emlrtRTEI), sp, 1, b_aperture.size(1));
    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      r1[nm1d2].re = b_aperture[x_tmp + b_aperture.size(0) * nm1d2].re * absx -
        b_aperture[x_tmp + b_aperture.size(0) * nm1d2].im * x;
      r1[nm1d2].im = b_aperture[x_tmp + b_aperture.size(0) * nm1d2].re * x +
        b_aperture[x_tmp + b_aperture.size(0) * nm1d2].im * absx;
    }

    iv[1] = b_aperture.size(1);
    emlrtSubAssignSizeCheckR2012b(&iv[0], 2, r1.size(), 2, &b_emlrtECI, sp);
    nx = r1.size(1);
    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      b_aperture[x_tmp + b_aperture.size(0) * nm1d2] = r1[nm1d2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 0, 0, 0, 0);
  emlrtForLoopVectorCheckR2012b(1.0, 1.0, N, mxDOUBLE_CLASS, static_cast<int32_T>
    (N), &b_emlrtRTEI, sp);
  for (x_tmp = 0; x_tmp < i; x_tmp++) {
    covrtLogFor(&emlrtCoverageInstance, 0, 0, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0, 2);
    absx = ((static_cast<real_T>(x_tmp) + 1.0) - N / 2.0) * delta * 2.0 *
      3.1415926535897931 * muDoubleScalarSin(muDoubleScalarAtan(xd / f)) /
      lambda;
    nm1d2 = x_tmp + 1;
    if ((nm1d2 < 1) || (nm1d2 > b_aperture.size(1))) {
      emlrtDynamicBoundsCheckR2012b(nm1d2, 1, b_aperture.size(1), &e_emlrtBCI,
        sp);
    }

    nm1d2 = static_cast<int32_T>(x_tmp + 1U);
    if ((nm1d2 < 1) || (nm1d2 > b_aperture.size(1))) {
      emlrtDynamicBoundsCheckR2012b(nm1d2, 1, b_aperture.size(1), &d_emlrtBCI,
        sp);
    }

    x = muDoubleScalarSin(absx);
    absx = muDoubleScalarCos(absx) + 0.0 * x;
    nx = b_aperture.size(0);
    r2.set_size((&n_emlrtRTEI), sp, b_aperture.size(0));
    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      r2[nm1d2].re = b_aperture[nm1d2 + b_aperture.size(0) * x_tmp].re * absx -
        b_aperture[nm1d2 + b_aperture.size(0) * x_tmp].im * x;
      r2[nm1d2].im = b_aperture[nm1d2 + b_aperture.size(0) * x_tmp].re * x +
        b_aperture[nm1d2 + b_aperture.size(0) * x_tmp].im * absx;
    }

    emlrtSubAssignSizeCheckR2012b(b_aperture.size(), 1, r2.size(), 1,
      &c_emlrtECI, sp);
    nx = r2.size(0);
    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      b_aperture[nm1d2 + b_aperture.size(0) * x_tmp] = r2[nm1d2];
    }

    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  covrtLogFor(&emlrtCoverageInstance, 0, 0, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0, 3);
  st.site = &d_emlrtRSI;
  fft2(&st, b_aperture, result);
  st.site = &d_emlrtRSI;
  fftshift(&st, result);
  b_aperture.set_size((&o_emlrtRTEI), sp, result.size(0), result.size(1));
  nx = result.size(0) * result.size(1);
  for (i = 0; i < nx; i++) {
    b_aperture[i].re = result[i].re;
    b_aperture[i].im = -result[i].im;
  }

  emlrtSizeEqCheckNDR2012b(result.size(), b_aperture.size(), &d_emlrtECI, sp);
  b_I.set_size((&p_emlrtRTEI), sp, result.size(0), result.size(1));
  nx = result.size(0) * result.size(1);
  for (i = 0; i < nx; i++) {
    b_I[i] = result[i].re * b_aperture[i].re - result[i].im * b_aperture[i].im;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

// End of code generation (circ_fraunhofer.cpp)
