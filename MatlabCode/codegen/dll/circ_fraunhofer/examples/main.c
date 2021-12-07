/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.0
 * C/C++ source code generated on  : 07-Dec-2021 13:55:02
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "circ_fraunhofer.h"
#include "circ_fraunhofer_emxAPI.h"
#include "circ_fraunhofer_terminate.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static int argInit_int32_T(void);
static double argInit_real_T(void);
static void main_circ_fraunhofer(void);

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : int
 */
static int argInit_int32_T(void)
{
  return 0;
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_circ_fraunhofer(void)
{
  emxArray_real_T *b_I;
  double L_tmp;
  emxInitArray_real_T(&b_I, 2);

  /* Initialize function 'circ_fraunhofer' input arguments. */
  L_tmp = argInit_real_T();

  /* Call the entry-point 'circ_fraunhofer'. */
  circ_fraunhofer(L_tmp, L_tmp, argInit_int32_T(), L_tmp, L_tmp, L_tmp, L_tmp,
                  L_tmp, b_I);
  emxDestroyArray_real_T(b_I);
}

/*
 * Arguments    : int argc
 *                const char * const argv[]
 * Return Type  : int
 */
int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_circ_fraunhofer();

  /* Terminate the application.
     You do not need to do this more than one time. */
  circ_fraunhofer_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
