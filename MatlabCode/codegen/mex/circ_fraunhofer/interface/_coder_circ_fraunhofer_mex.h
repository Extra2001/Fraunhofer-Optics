//
//  _coder_circ_fraunhofer_mex.h
//
//  Code generation for function '_coder_circ_fraunhofer_mex'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "covrt.h"
#include "rtwtypes.h"
#include "circ_fraunhofer_types.h"

// Function Declarations
MEXFUNCTION_LINKAGE void circ_fraunhofer_mexFunction(int32_T nlhs, mxArray *
  plhs[1], int32_T nrhs, const mxArray *prhs[7]);
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
  const mxArray *prhs[]);
emlrtCTX mexFunctionCreateRootTLS();

// End of code generation (_coder_circ_fraunhofer_mex.h)
