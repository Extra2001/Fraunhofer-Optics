/*
 * File: circ_fraunhofer_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "circ_fraunhofer_ca.h"

CA_HWImpl_TestResults CA_circ_fraunhofer_HWRes;
CA_PWS_TestResults CA_circ_fraunhofer_PWSRes;
const CA_HWImpl CA_circ_fraunhofer_ExpHW = {
  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  64,                                  /* BitPerPointer */
  64,                                  /* BitPerSizeT */
  64,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */
  1,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "Generic->MATLAB Host Computer",     /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_circ_fraunhofer_ActHW;
void circ_fraunhofer_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_circ_fraunhofer_ActHW, &CA_circ_fraunhofer_ExpHW,
    &CA_circ_fraunhofer_PWSRes);
  caVerifyHWImpl(&CA_circ_fraunhofer_ActHW, &CA_circ_fraunhofer_ExpHW,
                 &CA_circ_fraunhofer_HWRes);
}
