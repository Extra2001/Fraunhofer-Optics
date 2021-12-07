/*
 * File: circ_fraunhofer_rtwutil.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 07-Dec-2021 13:55:02
 */

/* Include Files */
#include "circ_fraunhofer_rtwutil.h"
#include "circ_fraunhofer.h"
#include "rt_nonfinite.h"
#include <float.h>
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
double rt_remd_snf(double u0, double u1)
{
  double y;
  double q;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = rtNaN;
  } else if (rtIsInf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != trunc(u1))) {
    q = fabs(u0 / u1);
    if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

/*
 * File trailer for circ_fraunhofer_rtwutil.c
 *
 * [EOF]
 */
