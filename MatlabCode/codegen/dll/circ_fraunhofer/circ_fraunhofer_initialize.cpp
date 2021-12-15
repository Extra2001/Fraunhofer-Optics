//
// File: circ_fraunhofer_initialize.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Dec-2021 23:04:07
//

// Include Files
#include "circ_fraunhofer_initialize.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "rt_nonfinite.h"

// Function Definitions

//
// Arguments    : void
// Return Type  : void
//
void circ_fraunhofer_initialize()
{
  rt_InitInfAndNaN();
  omp_init_nest_lock(&emlrtNestLockGlobal);
  isInitialized_circ_fraunhofer = true;
}

//
// File trailer for circ_fraunhofer_initialize.cpp
//
// [EOF]
//
