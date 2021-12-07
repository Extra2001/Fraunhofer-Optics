/*
 * File: _coder_circ_fraunhofer_target.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 07-Dec-2021 13:55:02
 */

#ifndef _CODER_CIRC_FRAUNHOFER_TARGET_H
#define _CODER_CIRC_FRAUNHOFER_TARGET_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "xil_interface_common.h"
#include "xil_target_interface.h"
#include "circ_fraunhofer_types.h"

/* Function Declarations */
#ifdef __cplusplus

extern "C" {

#endif

  extern void XILTarget_initialize(unsigned int fcnId);
  extern void XILTarget_terminate(unsigned int fcnId);
  extern XIL_PROCESSDATA_ERROR_CODE xilTarget_circ_fraunhofer(unsigned int fcnId);

#ifdef __cplusplus

}
#endif
#endif

/*
 * File trailer for _coder_circ_fraunhofer_target.h
 *
 * [EOF]
 */
