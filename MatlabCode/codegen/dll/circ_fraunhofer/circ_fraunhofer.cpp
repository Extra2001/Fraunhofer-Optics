//
// File: circ_fraunhofer.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Dec-2021 23:04:07
//

// Include Files
#include "circ_fraunhofer.h"
#include "FFTImplementationCallback.h"
#include "circ_fraunhofer_data.h"
#include "circ_fraunhofer_initialize.h"
#include "fft2.h"
#include "rt_nonfinite.h"
#include <cfloat>
#include <cmath>

// Function Declarations
static double rt_remd_snf(double u0, double u1);

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
FFTImplementationCallback::~FFTImplementationCallback()
{
}

//
// Arguments    : void
// Return Type  : void
//
FFTImplementationCallback::FFTImplementationCallback()
{
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_remd_snf(double u0, double u1)
{
  double y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = rtNaN;
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    double b_u1;
    if (u1 < 0.0) {
      b_u1 = std::ceil(u1);
    } else {
      b_u1 = std::floor(u1);
    }

    if ((u1 != 0.0) && (u1 != b_u1)) {
      b_u1 = std::abs(u0 / u1);
      if (!(std::abs(b_u1 - std::floor(b_u1 + 0.5)) > DBL_EPSILON * b_u1)) {
        y = 0.0 * u0;
      } else {
        y = std::fmod(u0, u1);
      }
    } else {
      y = std::fmod(u0, u1);
    }
  }

  return y;
}

//
// Arguments    : double D
//                double N
//                double sita
//                double lambda
//                double f
//                double xd
//                double yd
//                coder::array<double, 2U> *b_I
// Return Type  : void
//
void circ_fraunhofer(double D, double N, double sita, double lambda, double f,
                     double xd, double yd, coder::array<double, 2U> &b_I)
{
  double xtmp_re;
  double absx;
  double delta;
  coder::array<double, 2U> x;
  double ndbl;
  int nx;
  int nm1d2;
  coder::array<double, 2U> aperture;
  coder::array<double, 2U> b_y1;
  int j;
  unsigned int unnamed_idx_0;
  unsigned int unnamed_idx_1;
  int i;
  int k;
  int vlend2;
  coder::array<int, 1U> r;
  coder::array<creal_T, 2U> b_aperture;
  coder::array<creal_T, 2U> result;
  coder::array<creal_T, 2U> c_aperture;
  int midoffset;
  coder::array<creal_T, 1U> d_aperture;
  int i2;
  int i1;
  int ia;
  int ib;
  int ic;
  if (!isInitialized_circ_fraunhofer) {
    circ_fraunhofer_initialize();
  }

  if (rtIsInf(sita) || rtIsNaN(sita)) {
    xtmp_re = rtNaN;
  } else {
    signed char n;
    xtmp_re = rt_remd_snf(sita, 360.0);
    absx = std::abs(xtmp_re);
    if (absx > 180.0) {
      if (xtmp_re > 0.0) {
        xtmp_re -= 360.0;
      } else {
        xtmp_re += 360.0;
      }

      absx = std::abs(xtmp_re);
    }

    if (absx <= 45.0) {
      xtmp_re *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (xtmp_re > 0.0) {
        xtmp_re = 0.017453292519943295 * (xtmp_re - 90.0);
        n = 1;
      } else {
        xtmp_re = 0.017453292519943295 * (xtmp_re + 90.0);
        n = -1;
      }
    } else if (xtmp_re > 0.0) {
      xtmp_re = 0.017453292519943295 * (xtmp_re - 180.0);
      n = 2;
    } else {
      xtmp_re = 0.017453292519943295 * (xtmp_re + 180.0);
      n = -2;
    }

    xtmp_re = std::tan(xtmp_re);
    if ((n == 1) || (n == -1)) {
      absx = 1.0 / xtmp_re;
      xtmp_re = -(1.0 / xtmp_re);
      if (rtIsInf(xtmp_re) && (n == 1)) {
        xtmp_re = absx;
      }
    }
  }

  sita = std::atan((yd + f * xtmp_re) / f);
  delta = f * N * lambda / 0.01 / N;
  absx = -N / 2.0;
  xtmp_re = N / 2.0 - 1.0;
  if (rtIsNaN(absx) || rtIsNaN(xtmp_re)) {
    x.set_size(1, 1);
    x[0] = rtNaN;
  } else if (xtmp_re < absx) {
    x.set_size(1, 0);
  } else if ((rtIsInf(absx) || rtIsInf(xtmp_re)) && (absx == xtmp_re)) {
    x.set_size(1, 1);
    x[0] = rtNaN;
  } else if (std::floor(absx) == absx) {
    nx = static_cast<int>(std::floor(xtmp_re - absx));
    x.set_size(1, (nx + 1));
    for (nm1d2 = 0; nm1d2 <= nx; nm1d2++) {
      x[nm1d2] = absx + static_cast<double>(nm1d2);
    }
  } else {
    double apnd;
    double cdiff;
    double u0;
    double u1;
    ndbl = std::floor((xtmp_re - absx) + 0.5);
    apnd = absx + ndbl;
    cdiff = apnd - xtmp_re;
    u0 = std::abs(absx);
    u1 = std::abs(xtmp_re);
    if ((u0 > u1) || rtIsNaN(u1)) {
      u1 = u0;
    }

    if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
      ndbl++;
      apnd = xtmp_re;
    } else if (cdiff > 0.0) {
      apnd = absx + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      nx = static_cast<int>(ndbl);
    } else {
      nx = 0;
    }

    x.set_size(1, nx);
    if (nx > 0) {
      x[0] = absx;
      if (nx > 1) {
        x[nx - 1] = apnd;
        nm1d2 = (nx - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          vlend2 = k + 1;
          x[k + 1] = absx + static_cast<double>(vlend2);
          x[(nx - k) - 2] = apnd - static_cast<double>(vlend2);
        }

        if (nm1d2 << 1 == nx - 1) {
          x[nm1d2] = (absx + apnd) / 2.0;
        } else {
          x[nm1d2] = absx + static_cast<double>(nm1d2);
          x[nm1d2 + 1] = apnd - static_cast<double>(nm1d2);
        }
      }
    }
  }

  nm1d2 = x.size(0) * x.size(1);
  x.set_size(1, x.size(1));
  nx = nm1d2 - 1;
  for (nm1d2 = 0; nm1d2 <= nx; nm1d2++) {
    x[nm1d2] = x[nm1d2] * delta;
  }

  nx = x.size(1) - 1;
  aperture.set_size(x.size(1), x.size(1));
  b_y1.set_size(x.size(1), x.size(1));
  if (x.size(1) != 0) {
    for (j = 0; j <= nx; j++) {
      for (i = 0; i <= nx; i++) {
        aperture[i + aperture.size(0) * j] = x[j];
        b_y1[i + b_y1.size(0) * j] = x[i];
      }
    }
  }

  unnamed_idx_0 = static_cast<unsigned int>(aperture.size(0));
  unnamed_idx_1 = static_cast<unsigned int>(aperture.size(1));
  x.set_size((static_cast<int>(unnamed_idx_0)), (static_cast<int>(unnamed_idx_1)));
  nx = static_cast<int>(unnamed_idx_0) * static_cast<int>(unnamed_idx_1);
  for (k = 0; k < nx; k++) {
    x[k] = aperture[k] * aperture[k];
  }

  unnamed_idx_0 = static_cast<unsigned int>(b_y1.size(0));
  unnamed_idx_1 = static_cast<unsigned int>(b_y1.size(1));
  aperture.set_size((static_cast<int>(unnamed_idx_0)), (static_cast<int>
    (unnamed_idx_1)));
  nx = static_cast<int>(unnamed_idx_0) * static_cast<int>(unnamed_idx_1);
  for (k = 0; k < nx; k++) {
    aperture[k] = b_y1[k] * b_y1[k];
  }

  nx = x.size(0) * x.size(1);
  for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
    x[nm1d2] = x[nm1d2] + aperture[nm1d2];
  }

  nx = x.size(0) * x.size(1);
  for (k = 0; k < nx; k++) {
    x[k] = std::sqrt(x[k]);
  }

  aperture.set_size(x.size(0), x.size(1));
  absx = D / 2.0;
  nx = x.size(0) * x.size(1);
  for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
    aperture[nm1d2] = (x[nm1d2] < absx);
  }

  nm1d2 = x.size(0) * x.size(1) - 1;
  nx = 0;
  for (i = 0; i <= nm1d2; i++) {
    if (x[i] == D / 2.0) {
      nx++;
    }
  }

  r.set_size(nx);
  nx = 0;
  for (i = 0; i <= nm1d2; i++) {
    if (x[i] == D / 2.0) {
      r[nx] = i + 1;
      nx++;
    }
  }

  nx = r.size(0) - 1;
  for (nm1d2 = 0; nm1d2 <= nx; nm1d2++) {
    aperture[r[nm1d2] - 1] = 0.5;
  }

  b_aperture.set_size(aperture.size(0), aperture.size(1));
  nx = aperture.size(0) * aperture.size(1);
  for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
    b_aperture[nm1d2].re = aperture[nm1d2];
    b_aperture[nm1d2].im = 0.0;
  }

  nm1d2 = static_cast<int>(N);
  for (vlend2 = 0; vlend2 < nm1d2; vlend2++) {
    absx = ((static_cast<double>(vlend2) + 1.0) - N / 2.0) * delta * 2.0 *
      3.1415926535897931 * std::sin(sita) / lambda;
    nx = b_aperture.size(1) - 1;
    ndbl = std::sin(absx);
    xtmp_re = std::cos(absx) + 0.0 * ndbl;
    c_aperture.set_size(1, b_aperture.size(1));
    for (midoffset = 0; midoffset <= nx; midoffset++) {
      c_aperture[midoffset].re = b_aperture[vlend2 + b_aperture.size(0) *
        midoffset].re * xtmp_re - b_aperture[vlend2 + b_aperture.size(0) *
        midoffset].im * ndbl;
      c_aperture[midoffset].im = b_aperture[vlend2 + b_aperture.size(0) *
        midoffset].re * ndbl + b_aperture[vlend2 + b_aperture.size(0) *
        midoffset].im * xtmp_re;
    }

    nx = c_aperture.size(1);
    for (midoffset = 0; midoffset < nx; midoffset++) {
      b_aperture[vlend2 + b_aperture.size(0) * midoffset] = c_aperture[midoffset];
    }
  }

  for (vlend2 = 0; vlend2 < nm1d2; vlend2++) {
    absx = ((static_cast<double>(vlend2) + 1.0) - N / 2.0) * delta * 2.0 *
      3.1415926535897931 * std::sin(std::atan(xd / f)) / lambda;
    nx = b_aperture.size(0) - 1;
    ndbl = std::sin(absx);
    xtmp_re = std::cos(absx) + 0.0 * ndbl;
    d_aperture.set_size(b_aperture.size(0));
    for (midoffset = 0; midoffset <= nx; midoffset++) {
      d_aperture[midoffset].re = b_aperture[midoffset + b_aperture.size(0) *
        vlend2].re * xtmp_re - b_aperture[midoffset + b_aperture.size(0) *
        vlend2].im * ndbl;
      d_aperture[midoffset].im = b_aperture[midoffset + b_aperture.size(0) *
        vlend2].re * ndbl + b_aperture[midoffset + b_aperture.size(0) * vlend2].
        im * xtmp_re;
    }

    nx = d_aperture.size(0);
    for (midoffset = 0; midoffset < nx; midoffset++) {
      b_aperture[midoffset + b_aperture.size(0) * vlend2] = d_aperture[midoffset];
    }
  }

  fft2(b_aperture, result);
  if (result.size(0) > 1) {
    vlend2 = result.size(0) / 2;
    nm1d2 = 1;
    for (k = 2; k < 3; k++) {
      nm1d2 *= result.size(1);
    }

    nx = result.size(0) - 1;
    midoffset = vlend2 - 1;
    if (vlend2 << 1 == result.size(0)) {
      i2 = 0;
      for (i = 0; i < nm1d2; i++) {
        i1 = i2;
        i2 += nx;
        for (j = 0; j < 1; j++) {
          i1++;
          i2++;
          ia = i1 - 1;
          ib = i1 + midoffset;
          for (k = 0; k < vlend2; k++) {
            xtmp_re = result[ia].re;
            absx = result[ia].im;
            result[ia] = result[ib];
            result[ib].re = xtmp_re;
            result[ib].im = absx;
            ia++;
            ib++;
          }
        }
      }
    } else {
      i2 = 0;
      for (i = 0; i < nm1d2; i++) {
        i1 = i2;
        i2 += nx;
        for (j = 0; j < 1; j++) {
          i1++;
          i2++;
          ia = i1 - 1;
          ib = i1 + midoffset;
          xtmp_re = result[ib].re;
          absx = result[ib].im;
          for (k = 0; k < vlend2; k++) {
            ic = ib + 1;
            result[ib] = result[ia];
            result[ia] = result[ic];
            ia++;
            ib = ic;
          }

          result[ib].re = xtmp_re;
          result[ib].im = absx;
        }
      }
    }
  }

  if (result.size(1) > 1) {
    vlend2 = result.size(1) / 2;
    nm1d2 = 1;
    for (k = 0; k < 1; k++) {
      nm1d2 *= result.size(0);
    }

    nx = (result.size(1) - 1) * nm1d2;
    midoffset = vlend2 * nm1d2 - 1;
    if (vlend2 << 1 == result.size(1)) {
      i2 = 0;
      for (i = 0; i < 1; i++) {
        i1 = i2;
        i2 += nx;
        for (j = 0; j < nm1d2; j++) {
          i1++;
          i2++;
          ia = i1 - 1;
          ib = i1 + midoffset;
          for (k = 0; k < vlend2; k++) {
            xtmp_re = result[ia].re;
            absx = result[ia].im;
            result[ia] = result[ib];
            result[ib].re = xtmp_re;
            result[ib].im = absx;
            ia += nm1d2;
            ib += nm1d2;
          }
        }
      }
    } else {
      i2 = 0;
      for (i = 0; i < 1; i++) {
        i1 = i2;
        i2 += nx;
        for (j = 0; j < nm1d2; j++) {
          i1++;
          i2++;
          ia = i1 - 1;
          ib = i1 + midoffset;
          xtmp_re = result[ib].re;
          absx = result[ib].im;
          for (k = 0; k < vlend2; k++) {
            ic = ib + nm1d2;
            result[ib] = result[ia];
            result[ia] = result[ic];
            ia += nm1d2;
            ib = ic;
          }

          result[ib].re = xtmp_re;
          result[ib].im = absx;
        }
      }
    }
  }

  b_I.set_size(result.size(0), result.size(1));
  nx = result.size(0) * result.size(1);
  for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
    b_I[nm1d2] = result[nm1d2].re * result[nm1d2].re - result[nm1d2].im *
      -result[nm1d2].im;
  }
}

//
// File trailer for circ_fraunhofer.cpp
//
// [EOF]
//
