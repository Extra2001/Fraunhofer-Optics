/*
 * File: circ_fraunhofer_ca.h
 *
 * Abstract: Tests assumptions in the generated code.
 */

#ifndef CIRC_FRAUNHOFER_CA_H
#define CIRC_FRAUNHOFER_CA_H

/* preprocessor validation checks */
#include "circ_fraunhofer_ca_preproc.h"
#include "coder_assumptions_hwimpl.h"

/* variables holding test results */
extern CA_HWImpl_TestResults CA_circ_fraunhofer_HWRes;
extern CA_PWS_TestResults CA_circ_fraunhofer_PWSRes;

/* variables holding "expected" and "actual" hardware implementation */
extern const CA_HWImpl CA_circ_fraunhofer_ExpHW;
extern CA_HWImpl CA_circ_fraunhofer_ActHW;

/* entry point function to run tests */
void circ_fraunhofer_caRunTests(void);

#endif                                 /* CIRC_FRAUNHOFER_CA_H */
