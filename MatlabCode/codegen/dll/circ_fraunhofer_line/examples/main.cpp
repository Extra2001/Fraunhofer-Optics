//
// File: main.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 14-Dec-2021 17:38:03
//

//***********************************************************************
// This automatically generated example C++ main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************

// Include Files
#include "main.h"
#include "circ_fraunhofer_line.h"
#include "circ_fraunhofer_line_terminate.h"
#include "rt_nonfinite.h"

// Function Declarations
static double argInit_real_T();
static void main_circ_fraunhofer_line();

// Function Definitions

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_circ_fraunhofer_line()
{
  double D_tmp;
  coder::array<double, 2U> II;

  // Initialize function 'circ_fraunhofer_line' input arguments.
  D_tmp = argInit_real_T();

  // Call the entry-point 'circ_fraunhofer_line'.
  circ_fraunhofer_line(D_tmp, D_tmp, D_tmp, D_tmp, D_tmp, D_tmp, D_tmp, II);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // The initialize function is being called automatically from your entry-point function. So, a call to initialize is not included here. 
  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_circ_fraunhofer_line();

  // Terminate the application.
  // You do not need to do this more than one time.
  circ_fraunhofer_line_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
