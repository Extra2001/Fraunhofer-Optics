//
// File: circ_fraunhofer_line.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Dec-2021 17:38:03
//
#ifndef CIRC_FRAUNHOFER_LINE_H
#define CIRC_FRAUNHOFER_LINE_H

// Include Files
#include <cstddef>
#include <cstdlib>
#include "rtwtypes.h"
#include "omp.h"
#include "circ_fraunhofer_line_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
CIRC_FRAUNHOFER_LINE_DLL_EXPORT extern void circ_fraunhofer_line(double D,
  double N, double sita, double lambda, double f, double xd, double yd, coder::
  array<double, 2U> &II);

#endif

//
// File trailer for circ_fraunhofer_line.h
//
// [EOF]
//
