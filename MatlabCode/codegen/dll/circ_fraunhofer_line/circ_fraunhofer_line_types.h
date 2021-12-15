//
// File: circ_fraunhofer_line_types.h
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Dec-2021 17:38:03
//
#ifndef CIRC_FRAUNHOFER_LINE_TYPES_H
#define CIRC_FRAUNHOFER_LINE_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#ifdef CIRC_FRAUNHOFER_LINE_XIL_BUILD
#if defined(_MSC_VER) || defined(__LCC__)
#define CIRC_FRAUNHOFER_LINE_DLL_EXPORT __declspec(dllimport)
#else
#define CIRC_FRAUNHOFER_LINE_DLL_EXPORT
#endif

#elif defined(BUILDING_CIRC_FRAUNHOFER_LINE)
#if defined(_MSC_VER) || defined(__LCC__)
#define CIRC_FRAUNHOFER_LINE_DLL_EXPORT __declspec(dllexport)
#else
#define CIRC_FRAUNHOFER_LINE_DLL_EXPORT __attribute__ ((visibility("default")))
#endif

#else
#define CIRC_FRAUNHOFER_LINE_DLL_EXPORT
#endif

#ifdef _MSC_VER

#pragma warning(push)
#pragma warning(disable : 4251)

#endif

// Type Definitions
class CIRC_FRAUNHOFER_LINE_DLL_EXPORT FFTImplementationCallback
{
 public:
  static void r2br_r2dit_trig(const coder::array<creal_T, 2U> &x, int
    n1_unsigned, const coder::array<double, 2U> &costab, const coder::array<
    double, 2U> &sintab, coder::array<creal_T, 2U> &y);
  static void dobluesteinfft(const coder::array<creal_T, 2U> &x, int n2blue, int
    nfft, const coder::array<double, 2U> &costab, const coder::array<double, 2U>
    &sintab, const coder::array<double, 2U> &sintabinv, coder::array<creal_T, 2U>
    &y);
  FFTImplementationCallback();
  ~FFTImplementationCallback();
 protected:
  static void r2br_r2dit_trig_impl(const coder::array<creal_T, 1U> &x, int
    unsigned_nRows, const coder::array<double, 2U> &costab, const coder::array<
    double, 2U> &sintab, coder::array<creal_T, 1U> &y);
};

#define MAX_THREADS                    omp_get_max_threads()
#ifdef _MSC_VER

#pragma warning(pop)

#endif
#endif

//
// File trailer for circ_fraunhofer_line_types.h
//
// [EOF]
//
