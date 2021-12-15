//
// File: circ_fraunhofer.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Dec-2021 23:04:07
//
#ifndef CIRC_FRAUNHOFER_H
#define CIRC_FRAUNHOFER_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "circ_fraunhofer_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
CIRC_FRAUNHOFER_DLL_EXPORT extern void circ_fraunhofer(double D, double N,
  double sita, double lambda, double f, double xd, double yd, coder::array<
  double, 2U> &b_I);

#endif

//
// File trailer for circ_fraunhofer.h
//
// [EOF]
//
