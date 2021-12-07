using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
using System;

public static class Calculate
{
    [DllImport("circ_fraunhofer.dll")]
    public extern static void circ_fraunhofer(double L, double D, int N,
        double f, double sita, double lambda, double xd, double yd, IntPtr b_I);
}
