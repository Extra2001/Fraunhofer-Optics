/*
 * File: circ_fraunhofer.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 07-Dec-2021 13:55:02
 */

/* Include Files */
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "circ_fraunhofer_emxutil.h"
#include "circ_fraunhofer_initialize.h"
#include "circ_fraunhofer_rtwutil.h"
#include "rt_nonfinite.h"
#include "tand.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : double L
 *                double D
 *                int N
 *                double f
 *                double sita
 *                double lambda
 *                double xd
 *                double yd
 *                emxArray_real_T *b_I
 * Return Type  : void
 */
void circ_fraunhofer(double L, double D, int N, double f, double sita, double
                     lambda, double xd, double yd, emxArray_real_T *b_I)
{
  double delta;
  double a;
  double b_tmp;
  emxArray_real_T *fy;
  int ndbl;
  int k;
  double apnd;
  double cdiff;
  emxArray_real_T *x;
  int n;
  emxArray_real_T *x1;
  emxArray_real_T *b_y1;
  double b_k;
  int nx;
  emxArray_real_T *r;
  unsigned int unnamed_idx_0;
  unsigned int unnamed_idx_1;
  emxArray_real_T *z;
  emxArray_int32_T *b_r;
  emxArray_creal_T *aperture;
  emxArray_creal_T *b_aperture;
  double b_x;
  int ii;
  double y_re;
  signed char b_n;
  emxArray_creal_T *result;
  emxArray_creal_T *y;
  double b;
  double y_im;
  int loop_ub;
  double b_b;
  if (!isInitialized_circ_fraunhofer) {
    circ_fraunhofer_initialize();
  }

  delta = L / (double)N;
  a = -(double)N / 2.0;
  b_tmp = (double)N / 2.0;
  emxInit_real_T(&fy, 2);
  if (b_tmp - 1.0 < a) {
    fy->size[0] = 1;
    fy->size[1] = 0;
  } else if (floor(a) == a) {
    k = fy->size[0] * fy->size[1];
    fy->size[0] = 1;
    ndbl = (int)floor((b_tmp - 1.0) - a);
    fy->size[1] = ndbl + 1;
    emxEnsureCapacity_real_T(fy, k);
    for (k = 0; k <= ndbl; k++) {
      fy->data[k] = a + (double)k;
    }
  } else {
    ndbl = (int)floor(((b_tmp - 1.0) - a) + 0.5);
    apnd = a + (double)ndbl;
    cdiff = apnd - (b_tmp - 1.0);
    if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(a), fabs(b_tmp - 1.0)))
    {
      ndbl++;
      apnd = b_tmp - 1.0;
    } else if (cdiff > 0.0) {
      apnd = a + ((double)ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0) {
      n = ndbl;
    } else {
      n = 0;
    }

    k = fy->size[0] * fy->size[1];
    fy->size[0] = 1;
    fy->size[1] = n;
    emxEnsureCapacity_real_T(fy, k);
    if (n > 0) {
      fy->data[0] = a;
      if (n > 1) {
        fy->data[n - 1] = apnd;
        ndbl = (n - 1) / 2;
        for (k = 0; k <= ndbl - 2; k++) {
          nx = k + 1;
          fy->data[k + 1] = a + (double)nx;
          fy->data[(n - k) - 2] = apnd - (double)nx;
        }

        if (ndbl << 1 == n - 1) {
          fy->data[ndbl] = (a + apnd) / 2.0;
        } else {
          fy->data[ndbl] = a + (double)ndbl;
          fy->data[ndbl + 1] = apnd - (double)ndbl;
        }
      }
    }
  }

  emxInit_real_T(&x, 2);
  k = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = fy->size[1];
  emxEnsureCapacity_real_T(x, k);
  ndbl = fy->size[0] * fy->size[1];
  for (k = 0; k < ndbl; k++) {
    x->data[k] = fy->data[k] * delta;
  }

  emxInit_real_T(&x1, 2);
  emxInit_real_T(&b_y1, 2);
  b_k = 6.2831853071795862 / lambda;
  nx = x->size[1] - 1;
  k = x1->size[0] * x1->size[1];
  x1->size[0] = x->size[1];
  x1->size[1] = x->size[1];
  emxEnsureCapacity_real_T(x1, k);
  k = b_y1->size[0] * b_y1->size[1];
  b_y1->size[0] = x->size[1];
  b_y1->size[1] = x->size[1];
  emxEnsureCapacity_real_T(b_y1, k);
  if (x->size[1] != 0) {
    for (n = 0; n <= nx; n++) {
      for (k = 0; k <= nx; k++) {
        x1->data[k + x1->size[0] * n] = x->data[n];
        b_y1->data[k + b_y1->size[0] * n] = x->data[k];
      }
    }
  }

  emxInit_real_T(&r, 2);

  /*  matlab code for evaluating the circ function */
  unnamed_idx_0 = (unsigned int)x1->size[0];
  unnamed_idx_1 = (unsigned int)x1->size[1];
  k = r->size[0] * r->size[1];
  r->size[0] = (int)unnamed_idx_0;
  r->size[1] = (int)unnamed_idx_1;
  emxEnsureCapacity_real_T(r, k);
  nx = (int)unnamed_idx_0 * (int)unnamed_idx_1;
  for (k = 0; k < nx; k++) {
    r->data[k] = x1->data[k] * x1->data[k];
  }

  emxInit_real_T(&z, 2);
  unnamed_idx_0 = (unsigned int)b_y1->size[0];
  unnamed_idx_1 = (unsigned int)b_y1->size[1];
  k = z->size[0] * z->size[1];
  z->size[0] = (int)unnamed_idx_0;
  z->size[1] = (int)unnamed_idx_1;
  emxEnsureCapacity_real_T(z, k);
  nx = (int)unnamed_idx_0 * (int)unnamed_idx_1;
  for (k = 0; k < nx; k++) {
    z->data[k] = b_y1->data[k] * b_y1->data[k];
  }

  ndbl = r->size[0] * r->size[1];
  for (k = 0; k < ndbl; k++) {
    r->data[k] += z->data[k];
  }

  nx = r->size[0] * r->size[1];
  for (k = 0; k < nx; k++) {
    r->data[k] = sqrt(r->data[k]);
  }

  k = z->size[0] * z->size[1];
  z->size[0] = r->size[0];
  z->size[1] = r->size[1];
  emxEnsureCapacity_real_T(z, k);
  apnd = D / 2.0;
  ndbl = r->size[0] * r->size[1];
  for (k = 0; k < ndbl; k++) {
    z->data[k] = (r->data[k] < apnd);
  }

  nx = r->size[0] * r->size[1] - 1;
  ndbl = 0;
  for (k = 0; k <= nx; k++) {
    if (r->data[k] == D / 2.0) {
      ndbl++;
    }
  }

  emxInit_int32_T(&b_r, 1);
  k = b_r->size[0];
  b_r->size[0] = ndbl;
  emxEnsureCapacity_int32_T(b_r, k);
  ndbl = 0;
  for (k = 0; k <= nx; k++) {
    if (r->data[k] == D / 2.0) {
      b_r->data[ndbl] = k + 1;
      ndbl++;
    }
  }

  emxFree_real_T(&r);
  ndbl = b_r->size[0] - 1;
  for (k = 0; k <= ndbl; k++) {
    z->data[b_r->data[k] - 1] = 0.5;
  }

  emxFree_int32_T(&b_r);
  emxInit_creal_T(&aperture, 2);
  k = aperture->size[0] * aperture->size[1];
  aperture->size[0] = z->size[0];
  aperture->size[1] = z->size[1];
  emxEnsureCapacity_creal_T(aperture, k);
  ndbl = z->size[0] * z->size[1];
  for (k = 0; k < ndbl; k++) {
    aperture->data[k].re = z->data[k];
    aperture->data[k].im = 0.0;
  }

  k = x1->size[0];
  if (0 <= x1->size[0] - 1) {
    if (rtIsInf(sita) || rtIsNaN(sita)) {
      b_x = rtNaN;
    } else {
      b_x = rt_remd_snf(sita, 360.0);
      apnd = fabs(b_x);
      if (apnd > 180.0) {
        if (b_x > 0.0) {
          b_x -= 360.0;
        } else {
          b_x += 360.0;
        }

        apnd = fabs(b_x);
      }

      if (apnd <= 45.0) {
        b_x *= 0.017453292519943295;
        b_n = 0;
      } else if (apnd <= 135.0) {
        if (b_x > 0.0) {
          b_x = 0.017453292519943295 * (b_x - 90.0);
          b_n = 1;
        } else {
          b_x = 0.017453292519943295 * (b_x + 90.0);
          b_n = -1;
        }
      } else if (b_x > 0.0) {
        b_x = 0.017453292519943295 * (b_x - 180.0);
        b_n = 2;
      } else {
        b_x = 0.017453292519943295 * (b_x + 180.0);
        b_n = -2;
      }

      if (b_n == 0) {
        b_x = sin(b_x);
      } else if (b_n == 1) {
        b_x = cos(b_x);
      } else if (b_n == -1) {
        b_x = -cos(b_x);
      } else {
        b_x = -sin(b_x);
      }
    }
  }

  emxInit_creal_T(&b_aperture, 2);
  for (ii = 0; ii < k; ii++) {
    apnd = (((double)ii + 1.0) - (double)x1->size[0] / 2.0) * delta * 2.0 *
      3.1415926535897931 * b_x / lambda;
    ndbl = aperture->size[1] - 1;
    cdiff = sin(apnd);
    y_re = cos(apnd) + 0.0 * cdiff;
    n = b_aperture->size[0] * b_aperture->size[1];
    b_aperture->size[0] = 1;
    b_aperture->size[1] = aperture->size[1];
    emxEnsureCapacity_creal_T(b_aperture, n);
    for (n = 0; n <= ndbl; n++) {
      b_aperture->data[n].re = aperture->data[ii + aperture->size[0] * n].re *
        y_re - aperture->data[ii + aperture->size[0] * n].im * cdiff;
      b_aperture->data[n].im = aperture->data[ii + aperture->size[0] * n].re *
        cdiff + aperture->data[ii + aperture->size[0] * n].im * y_re;
    }

    ndbl = b_aperture->size[1];
    for (n = 0; n < ndbl; n++) {
      aperture->data[ii + aperture->size[0] * n] = b_aperture->data[n];
    }
  }

  emxFree_creal_T(&b_aperture);
  emxFree_real_T(&x1);

  /*  imagesc(aperture) */
  a = 3.66 * lambda * f / D;
  k = fy->size[0] * fy->size[1];
  n = fy->size[0] * fy->size[1];
  fy->size[0] = 1;
  emxEnsureCapacity_real_T(fy, n);
  ndbl = k - 1;
  for (k = 0; k <= ndbl; k++) {
    fy->data[k] = a * (2.0 * fy->data[k] / (double)N);
  }

  apnd = sita;
  b_tand(&apnd);
  k = x->size[0] * x->size[1];
  x->size[0] = 1;
  x->size[1] = fy->size[1];
  emxEnsureCapacity_real_T(x, k);
  apnd = xd + f * apnd;
  ndbl = fy->size[0] * fy->size[1];
  for (k = 0; k < ndbl; k++) {
    x->data[k] = fy->data[k] - apnd;
  }

  apnd = sita;
  b_tand(&apnd);
  k = fy->size[0] * fy->size[1];
  n = fy->size[0] * fy->size[1];
  fy->size[0] = 1;
  emxEnsureCapacity_real_T(fy, n);
  apnd = yd + f * apnd;
  ndbl = k - 1;
  for (k = 0; k <= ndbl; k++) {
    fy->data[k] -= apnd;
  }

  nx = x->size[1];
  ndbl = fy->size[1];
  k = z->size[0] * z->size[1];
  z->size[0] = fy->size[1];
  z->size[1] = x->size[1];
  emxEnsureCapacity_real_T(z, k);
  k = b_y1->size[0] * b_y1->size[1];
  b_y1->size[0] = fy->size[1];
  b_y1->size[1] = x->size[1];
  emxEnsureCapacity_real_T(b_y1, k);
  if ((x->size[1] != 0) && (fy->size[1] != 0)) {
    for (n = 0; n < nx; n++) {
      for (k = 0; k < ndbl; k++) {
        z->data[k + z->size[0] * n] = x->data[n];
        b_y1->data[k + b_y1->size[0] * n] = fy->data[k];
      }
    }
  }

  emxFree_real_T(&fy);
  emxFree_real_T(&x);
  emxInit_creal_T(&result, 2);
  k = result->size[0] * result->size[1];
  result->size[0] = N;
  result->size[1] = N;
  emxEnsureCapacity_creal_T(result, k);
  ndbl = N * N;
  for (k = 0; k < ndbl; k++) {
    result->data[k].re = 0.0;
    result->data[k].im = 0.0;
  }

  emxInit_creal_T(&y, 2);
  for (ii = 0; ii < N; ii++) {
    if (0 <= N - 1) {
      b = ((double)ii + 1.0) - b_tmp;
      apnd = 0.0 * b_k;
      if (-b_k == 0.0) {
        y_re = apnd / f;
        y_im = 0.0;
      } else if (apnd == 0.0) {
        y_re = 0.0;
        y_im = -b_k / f;
      } else {
        y_re = rtNaN;
        y_im = -b_k / f;
      }

      loop_ub = z->size[0] * z->size[1];
      b_b = delta * delta;
    }

    for (n = 0; n < N; n++) {
      apnd = ((double)n + 1.0) - b_tmp;
      k = y->size[0] * y->size[1];
      y->size[0] = z->size[0];
      y->size[1] = z->size[1];
      emxEnsureCapacity_creal_T(y, k);
      for (k = 0; k < loop_ub; k++) {
        y->data[k].re = (z->data[k] * b * delta + b_y1->data[k] * apnd * delta) *
          y_re;
        y->data[k].im = (z->data[k] * b * delta + b_y1->data[k] * apnd * delta) *
          y_im;
      }

      nx = y->size[0] * y->size[1];
      for (k = 0; k < nx; k++) {
        if (y->data[k].im == 0.0) {
          y->data[k].re = exp(y->data[k].re);
          y->data[k].im = 0.0;
        } else if (rtIsInf(y->data[k].im) && rtIsInf(y->data[k].re) && (y->
                    data[k].re < 0.0)) {
          y->data[k].re = 0.0;
          y->data[k].im = 0.0;
        } else {
          cdiff = exp(y->data[k].re / 2.0);
          apnd = y->data[k].im;
          y->data[k].re = cdiff * (cdiff * cos(y->data[k].im));
          y->data[k].im = cdiff * (cdiff * sin(apnd));
        }
      }

      ndbl = result->size[0] * result->size[1];
      for (k = 0; k < ndbl; k++) {
        apnd = (aperture->data[ii + aperture->size[0] * n].re * y->data[k].re -
                aperture->data[ii + aperture->size[0] * n].im * y->data[k].im) *
          b_b;
        a = (aperture->data[ii + aperture->size[0] * n].re * y->data[k].im +
             aperture->data[ii + aperture->size[0] * n].im * y->data[k].re) *
          b_b;
        if (a == 0.0) {
          cdiff = apnd / lambda;
          apnd = 0.0;
        } else if (apnd == 0.0) {
          cdiff = 0.0;
          apnd = a / lambda;
        } else {
          cdiff = apnd / lambda;
          apnd = a / lambda;
        }

        if (apnd == 0.0) {
          cdiff /= f;
          apnd = 0.0;
        } else if (cdiff == 0.0) {
          cdiff = 0.0;
          apnd /= f;
        } else {
          cdiff /= f;
          apnd /= f;
        }

        result->data[k].re += cdiff;
        result->data[k].im += apnd;
      }
    }
  }

  emxFree_real_T(&z);
  emxFree_creal_T(&y);
  emxFree_real_T(&b_y1);
  emxFree_creal_T(&aperture);
  k = b_I->size[0] * b_I->size[1];
  b_I->size[0] = result->size[0];
  b_I->size[1] = result->size[1];
  emxEnsureCapacity_real_T(b_I, k);
  ndbl = result->size[0] * result->size[1];
  for (k = 0; k < ndbl; k++) {
    b_I->data[k] = result->data[k].re * result->data[k].re - result->data[k].im *
      -result->data[k].im;
  }

  emxFree_creal_T(&result);
}

/*
 * File trailer for circ_fraunhofer.c
 *
 * [EOF]
 */
