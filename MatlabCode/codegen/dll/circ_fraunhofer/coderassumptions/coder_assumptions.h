/*
 * File: coder_assumptions.h
 *
 * Abstract: Coder assumptions header file
 */

#ifndef CODER_ASSUMPTIONS_H
#define CODER_ASSUMPTIONS_H

/* include model specific checks */
#include "circ_fraunhofer_ca.h"

/* global results variable mapping for static code */
#define CA_Expected_HWImpl             CA_circ_fraunhofer_ExpHW
#define CA_Actual_HWImpl               CA_circ_fraunhofer_ActHW
#define CA_HWImpl_Results              CA_circ_fraunhofer_HWRes
#define CA_PortableWordSizes_Results   CA_circ_fraunhofer_PWSRes

/* entry point function mapping for static code */
#define CA_Run_Tests                   circ_fraunhofer_caRunTests
#endif                                 /* CODER_ASSUMPTIONS_H */
