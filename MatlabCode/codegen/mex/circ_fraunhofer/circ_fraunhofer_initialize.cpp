//
//  circ_fraunhofer_initialize.cpp
//
//  Code generation for function 'circ_fraunhofer_initialize'
//


// Include files
#include "circ_fraunhofer_initialize.h"
#include "_coder_circ_fraunhofer_mex.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_data.h"
#include "rt_nonfinite.h"

// Function Declarations
static void circ_fraunhofer_once();

// Function Definitions
static void circ_fraunhofer_once()
{
  mex_InitInfAndNan();

  // Allocate instance data
  covrtAllocateInstanceData(&emlrtCoverageInstance);

  // Initialize Coverage Information
  covrtScriptInit(&emlrtCoverageInstance,
                  "C:\\Users\\jingx\\Projects\\fraunhofer-optics\\MatlabCode\\circ_fraunhofer.m",
                  0U, 1U, 4U, 0U, 0U, 0U, 0U, 2U, 0U, 0U, 0U);

  // Initialize Function Information
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "circ_fraunhofer", 0, -1, 735);

  // Initialize Basic Block Information
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 663, -1, 730);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 518, -1, 649);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 360, -1, 485);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 64, -1, 335);

  // Initialize If Information
  // Initialize MCDC Information
  // Initialize For Information
  covrtForInit(&emlrtCoverageInstance, 0U, 0U, 341, 352, 494);
  covrtForInit(&emlrtCoverageInstance, 0U, 1U, 499, 510, 658);

  // Initialize While Information
  // Initialize Switch Information
  // Start callback for coverage engine
  covrtScriptStart(&emlrtCoverageInstance, 0U);
}

void circ_fraunhofer_initialize()
{
  emlrtStack st = { NULL,              // site
    NULL,                              // tls
    NULL                               // prev
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    circ_fraunhofer_once();
  }
}

// End of code generation (circ_fraunhofer_initialize.cpp)
