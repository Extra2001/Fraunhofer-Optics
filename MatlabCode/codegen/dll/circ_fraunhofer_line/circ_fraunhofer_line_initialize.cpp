//
// File: circ_fraunhofer_line_initialize.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Dec-2021 17:38:03
//

// Include Files
#include "circ_fraunhofer_line_initialize.h"
#include "circ_fraunhofer_line.h"
#include "circ_fraunhofer_line_data.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void circ_fraunhofer_line_initialize()
{
  rt_InitInfAndNaN();
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_circ_fraunhofer_line = true;
}

//
// File trailer for circ_fraunhofer_line_initialize.cpp
//
// [EOF]
//
