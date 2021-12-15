//
//  fft2.h
//
//  Code generation for function 'fft2'
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
void fft2(const emlrtStack *sp, const coder::array<creal_T, 2U> &x, coder::array<
          creal_T, 2U> &y);

// End of code generation (fft2.h)
