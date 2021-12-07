/*
 * File: _coder_circ_fraunhofer_target.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 07-Dec-2021 13:55:02
 */

/* Include Files */
#include "_coder_circ_fraunhofer_target.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_emxutil.h"
#include "circ_fraunhofer_initialize.h"
#include "circ_fraunhofer_terminate.h"

/* Function Declarations */
static void b_xilTargetDeserializer(int *b);
static void b_xilTargetSerializer(const int b[2]);
static void xilTargetDeserializer(double *b);
static void xilTargetSerializer(const emxArray_real_T *b);

/* Function Definitions */

/*
 * Arguments    : int *b
 * Return Type  : void
 */
static void b_xilTargetDeserializer(int *b)
{
  xilReadData((MemUnit_T *)b, sizeof(int));
}

/*
 * Arguments    : const int b[2]
 * Return Type  : void
 */
static void b_xilTargetSerializer(const int b[2])
{
  xilWriteData((MemUnit_T *)&b[0], sizeof(int) << 1);
}

/*
 * Arguments    : double *b
 * Return Type  : void
 */
static void xilTargetDeserializer(double *b)
{
  xilReadData((MemUnit_T *)b, sizeof(double));
}

/*
 * Arguments    : const emxArray_real_T *b
 * Return Type  : void
 */
static void xilTargetSerializer(const emxArray_real_T *b)
{
  b_xilTargetSerializer(*(int (*)[2])b->size);
  xilWriteData((MemUnit_T *)&b->data[0], (unsigned int)(b->size[0] * b->size[1] *
    (int)sizeof(double)));
}

/*
 * Arguments    : unsigned int fcnId
 * Return Type  : void
 */
void XILTarget_initialize(unsigned int fcnId)
{
  /* Calling XIL API before invoke initialize function. */
  xilPreEntryPoint(fcnId);

  /* Invoke initialize function. */
  circ_fraunhofer_initialize();

  /* Calling XIL API after invoke initialize function. */
  xilPostEntryPoint(fcnId);
}

/*
 * Arguments    : unsigned int fcnId
 * Return Type  : void
 */
void XILTarget_terminate(unsigned int fcnId)
{
  /* Calling XIL API before invoke terminate function. */
  xilPreEntryPoint(fcnId);

  /* Invoke terminate function. */
  circ_fraunhofer_terminate();

  /* Calling XIL API after invoke terminate function. */
  xilPostTerminatePoint(fcnId);
}

/*
 * Arguments    : unsigned int fcnId
 * Return Type  : XIL_PROCESSDATA_ERROR_CODE
 */
XIL_PROCESSDATA_ERROR_CODE xilTarget_circ_fraunhofer(unsigned int fcnId)
{
  XIL_PROCESSDATA_ERROR_CODE error_id;
  emxArray_real_T *b_I;
  double L;
  double D;
  int N;
  double f;
  double sita;
  double lambda;
  double xd;
  double yd;
  emxInit_real_T(&b_I, 2);

  /* Deserialize function input L argument. */
  xilTargetDeserializer(&L);

  /* Deserialize function input D argument. */
  xilTargetDeserializer(&D);

  /* Deserialize function input N argument. */
  b_xilTargetDeserializer(&N);

  /* Deserialize function input f argument. */
  xilTargetDeserializer(&f);

  /* Deserialize function input sita argument. */
  xilTargetDeserializer(&sita);

  /* Deserialize function input lambda argument. */
  xilTargetDeserializer(&lambda);

  /* Deserialize function input xd argument. */
  xilTargetDeserializer(&xd);

  /* Deserialize function input yd argument. */
  xilTargetDeserializer(&yd);

  /* Calling XIL API before invoke entry point. */
  xilPreEntryPoint(fcnId);

  /* Invoke target entry point. */
  circ_fraunhofer(L, D, N, f, sita, lambda, xd, yd, b_I);

  /* Calling XIL API after invoke entry point. */
  xilPostEntryPoint(fcnId);

  /* Serialize function output argument I. */
  xilTargetSerializer(b_I);
  error_id = XIL_PROCESSDATA_SUCCESS;
  emxFree_real_T(&b_I);
  return error_id;
}

/*
 * File trailer for _coder_circ_fraunhofer_target.c
 *
 * [EOF]
 */
