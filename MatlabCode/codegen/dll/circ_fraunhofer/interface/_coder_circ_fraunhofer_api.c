/*
 * File: _coder_circ_fraunhofer_api.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 13-Dec-2021 23:04:07
 */

/* Include Files */
#include "_coder_circ_fraunhofer_api.h"
#include "_coder_circ_fraunhofer_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
static boolean_T xilAlreadyInited;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131594U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "circ_fraunhofer",                   /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void b_xilHostDeserializer(int32_T b[2]);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static void circ_fraunhofer_once(void);
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *D, const
  char_T *identifier);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void xilHostDeserializer(emxArray_real_T *b);
static void xilHostSerializer(const real_T *b);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : int32_T b[2]
 * Return Type  : void
 */
static void b_xilHostDeserializer(int32_T b[2])
{
  xilReadData((uint8_T *)&b[0], (size_t)2, MEM_UNIT_INT32_TYPE);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void circ_fraunhofer_once(void)
{
  xilAlreadyInited = false;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *D
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *D, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(D), &thisId);
  emlrtDestroyArray(&D);
  return y;
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m;
  static const int32_T iv[2] = { 0, 0 };

  y = NULL;
  m = emlrtCreateNumericArray(2, &iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, &u->data[0]);
  emlrtSetDimensions((mxArray *)m, u->size, 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void *)
      &emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : emxArray_real_T *b
 * Return Type  : void
 */
static void xilHostDeserializer(emxArray_real_T *b)
{
  int32_T sizeVal[2];
  int32_T i;
  b_xilHostDeserializer(sizeVal);
  i = b->size[0] * b->size[1];
  b->size[0] = sizeVal[0];
  b->size[1] = sizeVal[1];
  emxEnsureCapacity_real_T(b, i);
  xilReadData((uint8_T *)&b->data[0], (size_t)(b->size[0] * b->size[1]),
              MEM_UNIT_DOUBLE_TYPE);
}

/*
 * Arguments    : const real_T *b
 * Return Type  : void
 */
static void xilHostSerializer(const real_T *b)
{
  xilWriteData((uint8_T *)b, (size_t)1, MEM_UNIT_DOUBLE_TYPE);
}

/*
 * Arguments    : real_T D
 *                real_T N
 *                real_T sita
 *                real_T lambda
 *                real_T f
 *                real_T xd
 *                real_T yd
 *                emxArray_real_T *b_I
 * Return Type  : void
 */
void circ_fraunhoferXilWrapper(real_T D, real_T N, real_T sita, real_T lambda,
  real_T f, real_T xd, real_T yd, emxArray_real_T *b_I)
{
  /* Serialize function input argument D. */
  xilHostSerializer(&D);

  /* Serialize function input argument N. */
  xilHostSerializer(&N);

  /* Serialize function input argument sita. */
  xilHostSerializer(&sita);

  /* Serialize function input argument lambda. */
  xilHostSerializer(&lambda);

  /* Serialize function input argument f. */
  xilHostSerializer(&f);

  /* Serialize function input argument xd. */
  xilHostSerializer(&xd);

  /* Serialize function input argument yd. */
  xilHostSerializer(&yd);

  /* Calling XIL to invoke target side. */
  xilEntryPointHost(1U);

  /* Deserialize function output argument I. */
  xilHostDeserializer(b_I);
}

/*
 * Arguments    : const mxArray * const prhs[7]
 *                int32_T nlhs
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void circ_fraunhofer_api(const mxArray * const prhs[7], int32_T nlhs, const
  mxArray *plhs[1])
{
  emxArray_real_T *b_I;
  real_T D;
  real_T N;
  real_T sita;
  real_T lambda;
  real_T f;
  real_T xd;
  real_T yd;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &b_I, 2, true);

  /* Marshall function inputs */
  D = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "D");
  N = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "N");
  sita = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "sita");
  lambda = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "lambda");
  f = emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "f");
  xd = emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "xd");
  yd = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "yd");

  /* Calling XIL to setup. */
  xilPreEntryPointHost(1U);

  /* Invoke the wrapper function */
  circ_fraunhoferXilWrapper(D, N, sita, lambda, f, xd, yd, b_I);

  /* Calling Xil to clean-up. */
  xilPostEntryPointHost(1U);

  /* Marshall function outputs */
  b_I->canFreeData = false;
  plhs[0] = emlrt_marshallOut(b_I);
  emxFree_real_T(&b_I);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void circ_fraunhofer_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  circ_fraunhofer_xil_terminate();
  circ_fraunhofer_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void circ_fraunhofer_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    circ_fraunhofer_once();
  }

  if (!xilAlreadyInited) {
    xilInitializeHost(&xil_terminate);
    xilAlreadyInited = true;
  }
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void circ_fraunhofer_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void xil_terminate(void)
{
  xilAlreadyInited = false;
  circ_fraunhofer_terminate();
}

/*
 * File trailer for _coder_circ_fraunhofer_api.c
 *
 * [EOF]
 */
