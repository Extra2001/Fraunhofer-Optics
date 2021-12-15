//
// File: _coder_circ_fraunhofer_target.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Dec-2021 23:04:07
//
#ifndef _CODER_CIRC_FRAUNHOFER_TARGET_H
#define _CODER_CIRC_FRAUNHOFER_TARGET_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "xil_interface_common.h"
#include "xil_target_interface.h"
#include "circ_fraunhofer_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void XILTarget_initialize(unsigned int fcnId);
extern void XILTarget_terminate(unsigned int fcnId);
extern XIL_PROCESSDATA_ERROR_CODE xilTarget_circ_fraunhofer(unsigned int fcnId);

#endif

//
// File trailer for _coder_circ_fraunhofer_target.h
//
// [EOF]
//
