/*
 * File: _coder_circ_fraunhofer_mex.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 13-Dec-2021 23:04:07
 */

#ifndef _CODER_CIRC_FRAUNHOFER_MEX_H
#define _CODER_CIRC_FRAUNHOFER_MEX_H

/* Include Files */
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "_coder_circ_fraunhofer_api.h"
#define MAX_THREADS                    omp_get_max_threads()

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
  const mxArray *prhs[]);
extern emlrtCTX mexFunctionCreateRootTLS(void);

#endif

/*
 * File trailer for _coder_circ_fraunhofer_mex.h
 *
 * [EOF]
 */
