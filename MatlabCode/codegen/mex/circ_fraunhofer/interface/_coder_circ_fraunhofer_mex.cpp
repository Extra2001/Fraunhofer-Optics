//
//  _coder_circ_fraunhofer_mex.cpp
//
//  Code generation for function '_coder_circ_fraunhofer_mex'
//


// Include files
#include "_coder_circ_fraunhofer_mex.h"
#include "_coder_circ_fraunhofer_api.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "circ_fraunhofer_initialize.h"
#include "circ_fraunhofer_terminate.h"

// Function Declarations
MEXFUNCTION_LINKAGE void circ_fraunhofer_mexFunction(int32_T nlhs, mxArray *
  plhs[1], int32_T nrhs, const mxArray *prhs[7]);

// Function Definitions
void circ_fraunhofer_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[7])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;

  // Check for proper number of arguments.
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 7, 4,
                        15, "circ_fraunhofer");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 15,
                        "circ_fraunhofer");
  }

  // Call the function.
  circ_fraunhofer_api(prhs, nlhs, outputs);

  // Copy over outputs to the caller.
  emlrtReturnArrays(1, plhs, &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(&circ_fraunhofer_atexit);

  // Module initialization.
  circ_fraunhofer_initialize();

  // Dispatch the entry-point.
  circ_fraunhofer_mexFunction(nlhs, plhs, nrhs, prhs);

  // Module termination.
  circ_fraunhofer_terminate();
}

emlrtCTX mexFunctionCreateRootTLS()
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

// End of code generation (_coder_circ_fraunhofer_mex.cpp)
