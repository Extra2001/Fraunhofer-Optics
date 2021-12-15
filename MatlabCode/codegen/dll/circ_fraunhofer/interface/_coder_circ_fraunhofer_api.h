/*
 * File: _coder_circ_fraunhofer_api.h
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 13-Dec-2021 23:04:07
 */

#ifndef _CODER_CIRC_FRAUNHOFER_API_H
#define _CODER_CIRC_FRAUNHOFER_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "xil_host_interface.h"

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
extern void circ_fraunhoferXilWrapper(real_T D, real_T N, real_T sita, real_T
  lambda, real_T f, real_T xd, real_T yd, emxArray_real_T *b_I);
extern void circ_fraunhofer_api(const mxArray * const prhs[7], int32_T nlhs,
  const mxArray *plhs[1]);
extern void circ_fraunhofer_atexit(void);
extern void circ_fraunhofer_initialize(void);
extern void circ_fraunhofer_terminate(void);
extern void circ_fraunhofer_xil_shutdown(void);
extern void circ_fraunhofer_xil_terminate(void);
extern void xil_terminate(void);

#endif

/*
 * File trailer for _coder_circ_fraunhofer_api.h
 *
 * [EOF]
 */
