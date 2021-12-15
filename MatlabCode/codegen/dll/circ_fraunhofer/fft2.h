//
// File: fft2.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Dec-2021 23:04:07
//
#ifndef FFT2_H
#define FFT2_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "circ_fraunhofer_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
extern void fft2(const coder::array<creal_T, 2U> &x, coder::array<creal_T, 2U>
                 &y);

#endif

//
// File trailer for fft2.h
//
// [EOF]
//
