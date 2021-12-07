/*
 * File: circ_fraunhofer_initialize.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 07-Dec-2021 13:55:02
 */

/* Include Files */
#include "circ_fraunhofer_initialize.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void circ_fraunhofer_initialize(void)
{
  rt_InitInfAndNaN();
  isInitialized_circ_fraunhofer = true;
}

/*
 * File trailer for circ_fraunhofer_initialize.c
 *
 * [EOF]
 */
