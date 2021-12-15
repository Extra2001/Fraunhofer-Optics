//
// File: _coder_circ_fraunhofer_target.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Dec-2021 23:04:07
//
#ifndef CIRC_FRAUNHOFER_XIL_BUILD
#define CIRC_FRAUNHOFER_XIL_BUILD
#endif

// Include Files
#include "_coder_circ_fraunhofer_target.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_initialize.h"
#include "circ_fraunhofer_terminate.h"
#include "fft2.h"

// Function Declarations
static void b_xilTargetSerializer(const int b[2]);
static void xilTargetDeserializer(double *b);
static void xilTargetSerializer(const coder::array<double, 2U> &b);

// Function Definitions

//
// Arguments    : const int b[2]
// Return Type  : void
//
static void b_xilTargetSerializer(const int b[2])
{
  xilWriteData((MemUnit_T *)&b[0], sizeof(int) << 1);
}

//
// Arguments    : double *b
// Return Type  : void
//
static void xilTargetDeserializer(double *b)
{
  xilReadData((MemUnit_T *)b, sizeof(double));
}

//
// Arguments    : const coder::array<double, 2U> &b
// Return Type  : void
//
static void xilTargetSerializer(const coder::array<double, 2U> &b)
{
  b_xilTargetSerializer(*(int (*)[2])((coder::array<double, 2U> *)&b)->size());
  xilWriteData((MemUnit_T *)&(((coder::array<double, 2U> *)&b)->data())[0],
               static_cast<unsigned int>(b.size(0) * b.size(1) * static_cast<int>
    (sizeof(double))));
}

//
// Arguments    : unsigned int fcnId
// Return Type  : void
//
void XILTarget_initialize(unsigned int fcnId)
{
  // Calling XIL API before invoke initialize function.
  xilPreEntryPoint(fcnId);

  // Invoke initialize function.
  circ_fraunhofer_initialize();

  // Calling XIL API after invoke initialize function.
  xilPostEntryPoint(fcnId);
}

//
// Arguments    : unsigned int fcnId
// Return Type  : void
//
void XILTarget_terminate(unsigned int fcnId)
{
  // Calling XIL API before invoke terminate function.
  xilPreEntryPoint(fcnId);

  // Invoke terminate function.
  circ_fraunhofer_terminate();

  // Calling XIL API after invoke terminate function.
  xilPostTerminatePoint(fcnId);
}

//
// Arguments    : unsigned int fcnId
// Return Type  : XIL_PROCESSDATA_ERROR_CODE
//
XIL_PROCESSDATA_ERROR_CODE xilTarget_circ_fraunhofer(unsigned int fcnId)
{
  double D;
  double N;
  double sita;
  double lambda;
  double f;
  double xd;
  double yd;
  coder::array<double, 2U> b_I;

  // Deserialize function input D argument.
  xilTargetDeserializer(&D);

  // Deserialize function input N argument.
  xilTargetDeserializer(&N);

  // Deserialize function input sita argument.
  xilTargetDeserializer(&sita);

  // Deserialize function input lambda argument.
  xilTargetDeserializer(&lambda);

  // Deserialize function input f argument.
  xilTargetDeserializer(&f);

  // Deserialize function input xd argument.
  xilTargetDeserializer(&xd);

  // Deserialize function input yd argument.
  xilTargetDeserializer(&yd);

  // Calling XIL API before invoke entry point.
  xilPreEntryPoint(fcnId);

  // Invoke target entry point.
  circ_fraunhofer(D, N, sita, lambda, f, xd, yd, b_I);

  // Calling XIL API after invoke entry point.
  xilPostEntryPoint(fcnId);

  // Serialize function output argument I.
  xilTargetSerializer(b_I);
  return XIL_PROCESSDATA_SUCCESS;
}

//
// File trailer for _coder_circ_fraunhofer_target.cpp
//
// [EOF]
//
