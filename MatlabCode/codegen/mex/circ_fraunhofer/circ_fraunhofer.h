//
//  circ_fraunhofer.h
//
//  Code generation for function 'circ_fraunhofer'
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
CODEGEN_EXPORT_SYM void circ_fraunhofer(const emlrtStack *sp, real_T D, real_T N,
  real_T sita, real_T lambda, real_T f, real_T xd, real_T yd, coder::array<
  real_T, 2U> &b_I);

// End of code generation (circ_fraunhofer.h)
