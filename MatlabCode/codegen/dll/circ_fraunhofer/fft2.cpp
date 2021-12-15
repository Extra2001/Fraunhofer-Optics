//
// File: fft2.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Dec-2021 23:04:07
//

// Include Files
#include "fft2.h"
#include "FFTImplementationCallback.h"
#include "circ_fraunhofer.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions

//
// Arguments    : const coder::array<creal_T, 2U> *x
//                coder::array<creal_T, 2U> *y
// Return Type  : void
//
void fft2(const coder::array<creal_T, 2U> &x, coder::array<creal_T, 2U> &y)
{
  int lens[2];
  boolean_T guard1 = false;
  int pmax;
  int i;
  coder::array<double, 2U> costab1q;
  coder::array<double, 2U> costab;
  coder::array<double, 2U> sintab;
  coder::array<double, 2U> sintabinv;
  coder::array<creal_T, 2U> acc;
  coder::array<creal_T, 2U> xPerm;
  lens[0] = x.size(0);
  lens[1] = x.size(1);
  guard1 = false;
  if ((x.size(0) == 0) || (x.size(1) == 0)) {
    guard1 = true;
  } else {
    boolean_T useRadix2;
    int k;
    boolean_T exitg1;
    useRadix2 = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 2)) {
      if (0 == lens[k]) {
        useRadix2 = true;
        exitg1 = true;
      } else {
        k++;
      }
    }

    if (useRadix2) {
      guard1 = true;
    } else {
      int pmin;
      int n;
      double e;
      int pow2p;
      useRadix2 = ((x.size(0) > 0) && ((x.size(0) & (x.size(0) - 1)) == 0));
      pmin = 1;
      if (useRadix2) {
        pmax = x.size(0);
      } else {
        if (x.size(0) > 0) {
          n = (x.size(0) + x.size(0)) - 1;
          pmax = 31;
          if (n <= 1) {
            pmax = 0;
          } else {
            pmin = 0;
            exitg1 = false;
            while ((!exitg1) && (pmax - pmin > 1)) {
              k = (pmin + pmax) >> 1;
              pow2p = 1 << k;
              if (pow2p == n) {
                pmax = k;
                exitg1 = true;
              } else if (pow2p > n) {
                pmax = k;
              } else {
                pmin = k;
              }
            }
          }

          pmin = 1 << pmax;
        }

        pmax = pmin;
      }

      e = 6.2831853071795862 / static_cast<double>(pmax);
      n = pmax / 2 / 2;
      costab1q.set_size(1, (n + 1));
      costab1q[0] = 1.0;
      pmax = n / 2 - 1;
      for (k = 0; k <= pmax; k++) {
        costab1q[k + 1] = std::cos(e * (static_cast<double>(k) + 1.0));
      }

      i = pmax + 2;
      pow2p = n - 1;
      for (k = i; k <= pow2p; k++) {
        costab1q[k] = std::sin(e * static_cast<double>(n - k));
      }

      costab1q[n] = 0.0;
      if (!useRadix2) {
        n = costab1q.size(1) - 1;
        pmax = (costab1q.size(1) - 1) << 1;
        costab.set_size(1, (pmax + 1));
        sintab.set_size(1, (pmax + 1));
        costab[0] = 1.0;
        sintab[0] = 0.0;
        sintabinv.set_size(1, (pmax + 1));
        for (k = 0; k < n; k++) {
          sintabinv[k + 1] = costab1q[(n - k) - 1];
        }

        i = costab1q.size(1);
        for (k = i; k <= pmax; k++) {
          sintabinv[k] = costab1q[k - n];
        }

        for (k = 0; k < n; k++) {
          costab[k + 1] = costab1q[k + 1];
          sintab[k + 1] = -costab1q[(n - k) - 1];
        }

        i = costab1q.size(1);
        for (k = i; k <= pmax; k++) {
          costab[k] = -costab1q[pmax - k];
          sintab[k] = -costab1q[k - n];
        }
      } else {
        n = costab1q.size(1) - 1;
        pmax = (costab1q.size(1) - 1) << 1;
        costab.set_size(1, (pmax + 1));
        sintab.set_size(1, (pmax + 1));
        costab[0] = 1.0;
        sintab[0] = 0.0;
        for (k = 0; k < n; k++) {
          costab[k + 1] = costab1q[k + 1];
          sintab[k + 1] = -costab1q[(n - k) - 1];
        }

        i = costab1q.size(1);
        for (k = i; k <= pmax; k++) {
          costab[k] = -costab1q[pmax - k];
          sintab[k] = -costab1q[k - n];
        }

        sintabinv.set_size(1, 0);
      }

      if (useRadix2) {
        FFTImplementationCallback::r2br_r2dit_trig((x), (x.size(0)), (costab),
          (sintab), (acc));
      } else {
        FFTImplementationCallback::dobluesteinfft((x), (pmin), (x.size(0)),
          (costab), (sintab), (sintabinv), (acc));
      }

      xPerm.set_size(acc.size(1), acc.size(0));
      pmax = acc.size(0);
      for (i = 0; i < pmax; i++) {
        pmin = acc.size(1);
        for (pow2p = 0; pow2p < pmin; pow2p++) {
          xPerm[pow2p + xPerm.size(0) * i] = acc[i + acc.size(0) * pow2p];
        }
      }

      useRadix2 = ((x.size(1) > 0) && ((x.size(1) & (x.size(1) - 1)) == 0));
      pmin = 1;
      if (useRadix2) {
        pmax = x.size(1);
      } else {
        if (x.size(1) > 0) {
          n = (x.size(1) + x.size(1)) - 1;
          pmax = 31;
          if (n <= 1) {
            pmax = 0;
          } else {
            pmin = 0;
            exitg1 = false;
            while ((!exitg1) && (pmax - pmin > 1)) {
              k = (pmin + pmax) >> 1;
              pow2p = 1 << k;
              if (pow2p == n) {
                pmax = k;
                exitg1 = true;
              } else if (pow2p > n) {
                pmax = k;
              } else {
                pmin = k;
              }
            }
          }

          pmin = 1 << pmax;
        }

        pmax = pmin;
      }

      e = 6.2831853071795862 / static_cast<double>(pmax);
      n = pmax / 2 / 2;
      costab1q.set_size(1, (n + 1));
      costab1q[0] = 1.0;
      pmax = n / 2 - 1;
      for (k = 0; k <= pmax; k++) {
        costab1q[k + 1] = std::cos(e * (static_cast<double>(k) + 1.0));
      }

      i = pmax + 2;
      pow2p = n - 1;
      for (k = i; k <= pow2p; k++) {
        costab1q[k] = std::sin(e * static_cast<double>(n - k));
      }

      costab1q[n] = 0.0;
      if (!useRadix2) {
        n = costab1q.size(1) - 1;
        pmax = (costab1q.size(1) - 1) << 1;
        costab.set_size(1, (pmax + 1));
        sintab.set_size(1, (pmax + 1));
        costab[0] = 1.0;
        sintab[0] = 0.0;
        sintabinv.set_size(1, (pmax + 1));
        for (k = 0; k < n; k++) {
          sintabinv[k + 1] = costab1q[(n - k) - 1];
        }

        i = costab1q.size(1);
        for (k = i; k <= pmax; k++) {
          sintabinv[k] = costab1q[k - n];
        }

        for (k = 0; k < n; k++) {
          costab[k + 1] = costab1q[k + 1];
          sintab[k + 1] = -costab1q[(n - k) - 1];
        }

        i = costab1q.size(1);
        for (k = i; k <= pmax; k++) {
          costab[k] = -costab1q[pmax - k];
          sintab[k] = -costab1q[k - n];
        }
      } else {
        n = costab1q.size(1) - 1;
        pmax = (costab1q.size(1) - 1) << 1;
        costab.set_size(1, (pmax + 1));
        sintab.set_size(1, (pmax + 1));
        costab[0] = 1.0;
        sintab[0] = 0.0;
        for (k = 0; k < n; k++) {
          costab[k + 1] = costab1q[k + 1];
          sintab[k + 1] = -costab1q[(n - k) - 1];
        }

        i = costab1q.size(1);
        for (k = i; k <= pmax; k++) {
          costab[k] = -costab1q[pmax - k];
          sintab[k] = -costab1q[k - n];
        }

        sintabinv.set_size(1, 0);
      }

      if (useRadix2) {
        FFTImplementationCallback::r2br_r2dit_trig((xPerm), (x.size(1)), (costab),
          (sintab), (acc));
      } else {
        FFTImplementationCallback::dobluesteinfft((xPerm), (pmin), (x.size(1)),
          (costab), (sintab), (sintabinv), (acc));
      }

      y.set_size(acc.size(1), acc.size(0));
      pmax = acc.size(0);
      for (i = 0; i < pmax; i++) {
        pmin = acc.size(1);
        for (pow2p = 0; pow2p < pmin; pow2p++) {
          y[pow2p + y.size(0) * i] = acc[i + acc.size(0) * pow2p];
        }
      }
    }
  }

  if (guard1) {
    y.set_size(x.size(0), x.size(1));
    pmax = x.size(0) * x.size(1);
    for (i = 0; i < pmax; i++) {
      y[i].re = 0.0;
      y[i].im = 0.0;
    }
  }
}

//
// File trailer for fft2.cpp
//
// [EOF]
//
