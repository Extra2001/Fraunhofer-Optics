//
//  circ_fraunhofer_terminate.cpp
//
//  Code generation for function 'circ_fraunhofer_terminate'
//


// Include files
#include "circ_fraunhofer_terminate.h"
#include "_coder_circ_fraunhofer_mex.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "rt_nonfinite.h"

// Function Definitions
void circ_fraunhofer_atexit()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);

  // Free instance data
  covrtFreeInstanceData(&emlrtCoverageInstance);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void circ_fraunhofer_terminate()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

// End of code generation (circ_fraunhofer_terminate.cpp)
