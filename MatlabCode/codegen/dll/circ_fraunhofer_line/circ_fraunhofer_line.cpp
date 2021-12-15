//
// File: circ_fraunhofer_line.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Dec-2021 17:38:03
//

// Include Files
#include "circ_fraunhofer_line.h"
#include "FFTImplementationCallback.h"
#include "circ_fraunhofer_line_data.h"
#include "circ_fraunhofer_line_initialize.h"
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
//                coder::array<double, 2U> *II
// Return Type  : void
//
void circ_fraunhofer_line(double D, double N, double sita, double lambda, double
  f, double xd, double yd, coder::array<double, 2U> &II)
{
  int i;
  int nx;
  int nm1d2;
  double delta;
  double a;
  double b;
  double b_D;
  double apnd;
  coder::array<double, 2U> x;
  coder::array<double, 2U> aperture;
  coder::array<double, 2U> b_y1;
  coder::array<int, 1U> r;
  coder::array<creal_T, 2U> b_aperture;
  coder::array<creal_T, 2U> result;
  coder::array<creal_T, 2U> c_aperture;
  coder::array<creal_T, 1U> d_aperture;
  int i2;
  int ia;
  int ib;
  if (!isInitialized_circ_fraunhofer_line) {
    circ_fraunhofer_line_initialize();
  }

  i = static_cast<int>(N);
  II.set_size(i, i);
  nx = i * i;
  for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
    II[nm1d2] = 0.0;
  }

  delta = f * N * lambda / 0.01 / N;
  a = -N / 2.0;
  b = N / 2.0 - 1.0;
  b_D = D / 2.0;
  for (int iii = 0; iii < 5; iii++) {
    double absx;
    double sital;
    double cdiff;
    int j;
    unsigned int unnamed_idx_0;
    unsigned int unnamed_idx_1;
    int b_i;
    int k;
    int vlend2;
    int midoffset;
    int i1;
    int ic;
    apnd = sita + (static_cast<double>(iii) + -2.0);
    if (rtIsInf(apnd) || rtIsNaN(apnd)) {
      apnd = rtNaN;
    } else {
      signed char n;
      apnd = rt_remd_snf(apnd, 360.0);
      absx = std::abs(apnd);
      if (absx > 180.0) {
        if (apnd > 0.0) {
          apnd -= 360.0;
        } else {
          apnd += 360.0;
        }

        absx = std::abs(apnd);
      }

      if (absx <= 45.0) {
        apnd *= 0.017453292519943295;
        n = 0;
      } else if (absx <= 135.0) {
        if (apnd > 0.0) {
          apnd = 0.017453292519943295 * (apnd - 90.0);
          n = 1;
        } else {
          apnd = 0.017453292519943295 * (apnd + 90.0);
          n = -1;
        }
      } else if (apnd > 0.0) {
        apnd = 0.017453292519943295 * (apnd - 180.0);
        n = 2;
      } else {
        apnd = 0.017453292519943295 * (apnd + 180.0);
        n = -2;
      }

      apnd = std::tan(apnd);
      if ((n == 1) || (n == -1)) {
        absx = 1.0 / apnd;
        apnd = -(1.0 / apnd);
        if (rtIsInf(apnd) && (n == 1)) {
          apnd = absx;
        }
      }
    }

    sital = std::atan((yd + f * apnd) / f);
    if (b < a) {
      x.set_size(1, 0);
    } else if ((rtIsInf(a) || rtIsInf(b)) && (a == b)) {
      x.set_size(1, 1);
      x[0] = rtNaN;
    } else if (std::floor(a) == a) {
      nx = static_cast<int>(std::floor(b - a));
      x.set_size(1, (nx + 1));
      for (nm1d2 = 0; nm1d2 <= nx; nm1d2++) {
        x[nm1d2] = a + static_cast<double>(nm1d2);
      }
    } else {
      double u0;
      double u1;
      absx = std::floor((b - a) + 0.5);
      apnd = a + absx;
      cdiff = apnd - b;
      u0 = std::abs(a);
      u1 = std::abs(b);
      if ((u0 > u1) || rtIsNaN(u1)) {
        u1 = u0;
      }

      if (std::abs(cdiff) < 4.4408920985006262E-16 * u1) {
        absx++;
        apnd = b;
      } else if (cdiff > 0.0) {
        apnd = a + (absx - 1.0);
      } else {
        absx++;
      }

      if (absx >= 0.0) {
        nx = static_cast<int>(absx);
      } else {
        nx = 0;
      }

      x.set_size(1, nx);
      if (nx > 0) {
        x[0] = a;
        if (nx > 1) {
          x[nx - 1] = apnd;
          nm1d2 = (nx - 1) / 2;
          for (k = 0; k <= nm1d2 - 2; k++) {
            vlend2 = k + 1;
            x[k + 1] = a + static_cast<double>(vlend2);
            x[(nx - k) - 2] = apnd - static_cast<double>(vlend2);
          }

          if (nm1d2 << 1 == nx - 1) {
            x[nm1d2] = (a + apnd) / 2.0;
          } else {
            x[nm1d2] = a + static_cast<double>(nm1d2);
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
        for (b_i = 0; b_i <= nx; b_i++) {
          aperture[b_i + aperture.size(0) * j] = x[j];
          b_y1[b_i + b_y1.size(0) * j] = x[b_i];
        }
      }
    }

    unnamed_idx_0 = static_cast<unsigned int>(aperture.size(0));
    unnamed_idx_1 = static_cast<unsigned int>(aperture.size(1));
    x.set_size((static_cast<int>(unnamed_idx_0)), (static_cast<int>
                (unnamed_idx_1)));
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
    nx = x.size(0) * x.size(1);
    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      aperture[nm1d2] = (x[nm1d2] < b_D);
    }

    nm1d2 = x.size(0) * x.size(1) - 1;
    nx = 0;
    for (b_i = 0; b_i <= nm1d2; b_i++) {
      if (x[b_i] == D / 2.0) {
        nx++;
      }
    }

    r.set_size(nx);
    nx = 0;
    for (b_i = 0; b_i <= nm1d2; b_i++) {
      if (x[b_i] == D / 2.0) {
        r[nx] = b_i + 1;
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

    for (vlend2 = 0; vlend2 < i; vlend2++) {
      absx = ((static_cast<double>(vlend2) + 1.0) - N / 2.0) * delta * 2.0 *
        3.1415926535897931 * std::sin(sital) / lambda;
      nx = b_aperture.size(1) - 1;
      cdiff = std::sin(absx);
      apnd = std::cos(absx) + 0.0 * cdiff;
      c_aperture.set_size(1, b_aperture.size(1));
      for (nm1d2 = 0; nm1d2 <= nx; nm1d2++) {
        c_aperture[nm1d2].re = b_aperture[vlend2 + b_aperture.size(0) * nm1d2].
          re * apnd - b_aperture[vlend2 + b_aperture.size(0) * nm1d2].im * cdiff;
        c_aperture[nm1d2].im = b_aperture[vlend2 + b_aperture.size(0) * nm1d2].
          re * cdiff + b_aperture[vlend2 + b_aperture.size(0) * nm1d2].im * apnd;
      }

      nx = c_aperture.size(1);
      for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
        b_aperture[vlend2 + b_aperture.size(0) * nm1d2] = c_aperture[nm1d2];
      }
    }

    for (vlend2 = 0; vlend2 < i; vlend2++) {
      absx = ((static_cast<double>(vlend2) + 1.0) - N / 2.0) * delta * 2.0 *
        3.1415926535897931 * std::sin(std::atan(xd / f)) / lambda;
      nx = b_aperture.size(0) - 1;
      cdiff = std::sin(absx);
      apnd = std::cos(absx) + 0.0 * cdiff;
      d_aperture.set_size(b_aperture.size(0));
      for (nm1d2 = 0; nm1d2 <= nx; nm1d2++) {
        d_aperture[nm1d2].re = b_aperture[nm1d2 + b_aperture.size(0) * vlend2].
          re * apnd - b_aperture[nm1d2 + b_aperture.size(0) * vlend2].im * cdiff;
        d_aperture[nm1d2].im = b_aperture[nm1d2 + b_aperture.size(0) * vlend2].
          re * cdiff + b_aperture[nm1d2 + b_aperture.size(0) * vlend2].im * apnd;
      }

      nx = d_aperture.size(0);
      for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
        b_aperture[nm1d2 + b_aperture.size(0) * vlend2] = d_aperture[nm1d2];
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
        for (b_i = 0; b_i < nm1d2; b_i++) {
          i1 = i2;
          i2 += nx;
          for (j = 0; j < 1; j++) {
            i1++;
            i2++;
            ia = i1 - 1;
            ib = i1 + midoffset;
            for (k = 0; k < vlend2; k++) {
              apnd = result[ia].re;
              absx = result[ia].im;
              result[ia] = result[ib];
              result[ib].re = apnd;
              result[ib].im = absx;
              ia++;
              ib++;
            }
          }
        }
      } else {
        i2 = 0;
        for (b_i = 0; b_i < nm1d2; b_i++) {
          i1 = i2;
          i2 += nx;
          for (j = 0; j < 1; j++) {
            i1++;
            i2++;
            ia = i1 - 1;
            ib = i1 + midoffset;
            apnd = result[ib].re;
            absx = result[ib].im;
            for (k = 0; k < vlend2; k++) {
              ic = ib + 1;
              result[ib] = result[ia];
              result[ia] = result[ic];
              ia++;
              ib = ic;
            }

            result[ib].re = apnd;
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
        for (b_i = 0; b_i < 1; b_i++) {
          i1 = i2;
          i2 += nx;
          for (j = 0; j < nm1d2; j++) {
            i1++;
            i2++;
            ia = i1 - 1;
            ib = i1 + midoffset;
            for (k = 0; k < vlend2; k++) {
              apnd = result[ia].re;
              absx = result[ia].im;
              result[ia] = result[ib];
              result[ib].re = apnd;
              result[ib].im = absx;
              ia += nm1d2;
              ib += nm1d2;
            }
          }
        }
      } else {
        i2 = 0;
        for (b_i = 0; b_i < 1; b_i++) {
          i1 = i2;
          i2 += nx;
          for (j = 0; j < nm1d2; j++) {
            i1++;
            i2++;
            ia = i1 - 1;
            ib = i1 + midoffset;
            apnd = result[ib].re;
            absx = result[ib].im;
            for (k = 0; k < vlend2; k++) {
              ic = ib + nm1d2;
              result[ib] = result[ia];
              result[ia] = result[ic];
              ia += nm1d2;
              ib = ic;
            }

            result[ib].re = apnd;
            result[ib].im = absx;
          }
        }
      }
    }

    nx = II.size(0) * II.size(1);
    for (nm1d2 = 0; nm1d2 < nx; nm1d2++) {
      II[nm1d2] = II[nm1d2] + (result[nm1d2].re * result[nm1d2].re -
        result[nm1d2].im * -result[nm1d2].im);
    }
  }
}

//
// File trailer for circ_fraunhofer_line.cpp
//
// [EOF]
//
