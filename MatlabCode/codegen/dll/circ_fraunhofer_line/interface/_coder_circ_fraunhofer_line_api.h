/*
 * File: _coder_circ_fraunhofer_line_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 14-Dec-2021 17:38:03
 */

#ifndef _CODER_CIRC_FRAUNHOFER_LINE_API_H
#define _CODER_CIRC_FRAUNHOFER_LINE_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#define MAX_THREADS                    omp_get_max_threads()

/* Function Declarations */
extern void circ_fraunhofer_line(real_T D, real_T N, real_T sita, real_T lambda,
  real_T f, real_T xd, real_T yd, emxArray_real_T *II);
extern void circ_fraunhofer_line_api(const mxArray * const prhs[7], int32_T nlhs,
  const mxArray *plhs[1]);
extern void circ_fraunhofer_line_atexit(void);
extern void circ_fraunhofer_line_initialize(void);
extern void circ_fraunhofer_line_terminate(void);
extern void circ_fraunhofer_line_xil_shutdown(void);
extern void circ_fraunhofer_line_xil_terminate(void);

#endif

/*
 * File trailer for _coder_circ_fraunhofer_line_api.h
 *
 * [EOF]
 */
