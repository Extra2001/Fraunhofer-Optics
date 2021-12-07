/*
 * File: tand.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 07-Dec-2021 13:55:02
 */

/* Include Files */
#include "tand.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_rtwutil.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : double *x
 * Return Type  : void
 */
void b_tand(double *x)
{
  double absx;
  signed char n;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = rtNaN;
  } else {
    *x = rt_remd_snf(*x, 360.0);
    absx = fabs(*x);
    if (absx > 180.0) {
      if (*x > 0.0) {
        *x -= 360.0;
      } else {
        *x += 360.0;
      }

      absx = fabs(*x);
    }

    if (absx <= 45.0) {
      *x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (*x > 0.0) {
        *x = 0.017453292519943295 * (*x - 90.0);
        n = 1;
      } else {
        *x = 0.017453292519943295 * (*x + 90.0);
        n = -1;
      }
    } else if (*x > 0.0) {
      *x = 0.017453292519943295 * (*x - 180.0);
      n = 2;
    } else {
      *x = 0.017453292519943295 * (*x + 180.0);
      n = -2;
    }

    *x = tan(*x);
    if ((n == 1) || (n == -1)) {
      absx = 1.0 / *x;
      *x = -(1.0 / *x);
      if (rtIsInf(*x) && (n == 1)) {
        *x = absx;
      }
    }
  }
}

/*
 * File trailer for tand.c
 *
 * [EOF]
 */
