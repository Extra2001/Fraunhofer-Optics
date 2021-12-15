/*
 * File: _coder_circ_fraunhofer_line_mex.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 14-Dec-2021 17:38:03
 */

/* Include Files */
#include "_coder_circ_fraunhofer_line_mex.h"
#include "_coder_circ_fraunhofer_line_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void c_circ_fraunhofer_line_mexFunct(int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[7]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[7]
 * Return Type  : void
 */
void c_circ_fraunhofer_line_mexFunct(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[7])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        20, "circ_fraunhofer_line");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 20,
                        "circ_fraunhofer_line");
  }

  /* Call the function. */
  circ_fraunhofer_line_api(prhs, nlhs, outputs);

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
  mexAtExit(&circ_fraunhofer_line_atexit);

  /* Module initialization. */
  circ_fraunhofer_line_initialize();

  /* Dispatch the entry-point. */
  c_circ_fraunhofer_line_mexFunct(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  circ_fraunhofer_line_terminate();
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
 * File trailer for _coder_circ_fraunhofer_line_mex.c
 *
 * [EOF]
 */
