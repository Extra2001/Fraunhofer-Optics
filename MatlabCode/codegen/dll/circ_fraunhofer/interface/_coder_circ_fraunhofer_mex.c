/*
 * File: _coder_circ_fraunhofer_mex.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 07-Dec-2021 13:55:02
 */

/* Include Files */
#include "_coder_circ_fraunhofer_mex.h"
#include "_coder_circ_fraunhofer_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void circ_fraunhofer_mexFunction(int32_T nlhs, mxArray *
  plhs[1], int32_T nrhs, const mxArray *prhs[8]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[8]
 * Return Type  : void
 */
void circ_fraunhofer_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[8])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4,
                        15, "circ_fraunhofer");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 15,
                        "circ_fraunhofer");
  }

  /* Call the function. */
  circ_fraunhofer_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&circ_fraunhofer_atexit);

  /* Module initialization. */
  circ_fraunhofer_initialize();

  /* Dispatch the entry-point. */
  circ_fraunhofer_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  circ_fraunhofer_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_circ_fraunhofer_mex.c
 *
 * [EOF]
 */
