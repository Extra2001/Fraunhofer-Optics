//
// File: FFTImplementationCallback.cpp
//
// MATLAB Coder version            : 5.0
// C/C++ source code generated on  : 13-Dec-2021 23:04:07
//

// Include Files
#include "FFTImplementationCallback.h"
#include "circ_fraunhofer.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions

//
// Arguments    : const coder::array<creal_T, 1U> &x
//                int unsigned_nRows
//                const coder::array<double, 2U> &costab
//                const coder::array<double, 2U> &sintab
//                coder::array<creal_T, 1U> &y
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig_impl(const coder::array<creal_T,
  1U> &x, int unsigned_nRows, const coder::array<double, 2U> &costab, const
  coder::array<double, 2U> &sintab, coder::array<creal_T, 1U> &y)
{
  int iDelta2;
  int iy;
  int iheight;
  int nRowsD2;
  int k;
  int ix;
  int ju;
  int i;
  double temp_re;
  double temp_im;
  double twid_re;
  double twid_im;
  y.set_size(unsigned_nRows);
  if (unsigned_nRows > x.size(0)) {
    y.set_size(unsigned_nRows);
    for (iy = 0; iy < unsigned_nRows; iy++) {
      y[iy].re = 0.0;
      y[iy].im = 0.0;
    }
  }

  iDelta2 = x.size(0);
  if (iDelta2 >= unsigned_nRows) {
    iDelta2 = unsigned_nRows;
  }

  iheight = unsigned_nRows - 2;
  nRowsD2 = unsigned_nRows / 2;
  k = nRowsD2 / 2;
  ix = 0;
  iy = 0;
  ju = 0;
  for (i = 0; i <= iDelta2 - 2; i++) {
    boolean_T tst;
    y[iy] = x[ix];
    iy = unsigned_nRows;
    tst = true;
    while (tst) {
      iy >>= 1;
      ju ^= iy;
      tst = ((ju & iy) == 0);
    }

    iy = ju;
    ix++;
  }

  y[iy] = x[ix];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= iheight; i += 2) {
      temp_re = y[i + 1].re;
      temp_im = y[i + 1].im;
      twid_re = y[i].re;
      twid_im = y[i].im;
      y[i + 1].re = y[i].re - y[i + 1].re;
      y[i + 1].im = y[i].im - y[i + 1].im;
      twid_re += temp_re;
      twid_im += temp_im;
      y[i].re = twid_re;
      y[i].im = twid_im;
    }
  }

  iy = 2;
  iDelta2 = 4;
  iheight = ((k - 1) << 2) + 1;
  while (k > 0) {
    int temp_re_tmp;
    for (i = 0; i < iheight; i += iDelta2) {
      temp_re_tmp = i + iy;
      temp_re = y[temp_re_tmp].re;
      temp_im = y[temp_re_tmp].im;
      y[temp_re_tmp].re = y[i].re - y[temp_re_tmp].re;
      y[temp_re_tmp].im = y[i].im - y[temp_re_tmp].im;
      y[i].re = y[i].re + temp_re;
      y[i].im = y[i].im + temp_im;
    }

    ix = 1;
    for (ju = k; ju < nRowsD2; ju += k) {
      int ihi;
      twid_re = costab[ju];
      twid_im = sintab[ju];
      i = ix;
      ihi = ix + iheight;
      while (i < ihi) {
        temp_re_tmp = i + iy;
        temp_re = twid_re * y[temp_re_tmp].re - twid_im * y[temp_re_tmp].im;
        temp_im = twid_re * y[temp_re_tmp].im + twid_im * y[temp_re_tmp].re;
        y[temp_re_tmp].re = y[i].re - temp_re;
        y[temp_re_tmp].im = y[i].im - temp_im;
        y[i].re = y[i].re + temp_re;
        y[i].im = y[i].im + temp_im;
        i += iDelta2;
      }

      ix++;
    }

    k /= 2;
    iy = iDelta2;
    iDelta2 += iDelta2;
    iheight -= iy;
  }
}

//
// Arguments    : const coder::array<creal_T, 2U> &x
//                int n2blue
//                int nfft
//                const coder::array<double, 2U> &costab
//                const coder::array<double, 2U> &sintab
//                const coder::array<double, 2U> &sintabinv
//                coder::array<creal_T, 2U> &y
// Return Type  : void
//
void FFTImplementationCallback::dobluesteinfft(const coder::array<creal_T, 2U>
  &x, int n2blue, int nfft, const coder::array<double, 2U> &costab, const coder::
  array<double, 2U> &sintab, const coder::array<double, 2U> &sintabinv, coder::
  array<creal_T, 2U> &y)
{
  int nInt2m1;
  coder::array<creal_T, 1U> wwc;
  int idx;
  int rt;
  int nInt2;
  int k;
  int b_y;
  coder::array<creal_T, 1U> fv;
  coder::array<creal_T, 1U> fy;
  coder::array<creal_T, 1U> r;
  int xoff;
  int minNrowsNx;
  int b_k;
  int temp_re_tmp;
  int iy;
  int ihi;
  int nRowsD2;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double twid_re;
  double twid_im;
  nInt2m1 = (nfft + nfft) - 1;
  wwc.set_size(nInt2m1);
  idx = nfft;
  rt = 0;
  wwc[nfft - 1].re = 1.0;
  wwc[nfft - 1].im = 0.0;
  nInt2 = nfft << 1;
  for (k = 0; k <= nfft - 2; k++) {
    double nt_im;
    double nt_re;
    b_y = ((k + 1) << 1) - 1;
    if (nInt2 - rt <= b_y) {
      rt += b_y - nInt2;
    } else {
      rt += b_y;
    }

    nt_im = -3.1415926535897931 * static_cast<double>(rt) / static_cast<double>
      (nfft);
    if (nt_im == 0.0) {
      nt_re = 1.0;
      nt_im = 0.0;
    } else {
      nt_re = std::cos(nt_im);
      nt_im = std::sin(nt_im);
    }

    wwc[idx - 2].re = nt_re;
    wwc[idx - 2].im = -nt_im;
    idx--;
  }

  idx = 0;
  b_y = nInt2m1 - 1;
  for (k = b_y; k >= nfft; k--) {
    wwc[k] = wwc[idx];
    idx++;
  }

  idx = x.size(0);
  y.set_size(nfft, x.size(1));
  if (nfft > x.size(0)) {
    nInt2m1 = x.size(1);
    for (b_y = 0; b_y < nInt2m1; b_y++) {
      rt = y.size(0);
      for (nInt2 = 0; nInt2 < rt; nInt2++) {
        y[nInt2 + y.size(0) * b_y].re = 0.0;
        y[nInt2 + y.size(0) * b_y].im = 0.0;
      }
    }
  }

  nInt2m1 = x.size(1) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(fv,fy,r,xoff,minNrowsNx,b_k,temp_re_tmp,iy,ihi,nRowsD2,ix,ju,i,tst,temp_re,temp_im,twid_re,twid_im)

  for (int chan = 0; chan <= nInt2m1; chan++) {
    xoff = chan * idx;
    r.set_size(nfft);
    if (nfft > x.size(0)) {
      r.set_size(nfft);
      for (minNrowsNx = 0; minNrowsNx < nfft; minNrowsNx++) {
        r[minNrowsNx].re = 0.0;
        r[minNrowsNx].im = 0.0;
      }
    }

    minNrowsNx = x.size(0);
    if (nfft < minNrowsNx) {
      minNrowsNx = nfft;
    }

    for (b_k = 0; b_k < minNrowsNx; b_k++) {
      temp_re_tmp = (nfft + b_k) - 1;
      r[b_k].re = wwc[temp_re_tmp].re * x[xoff].re + wwc[temp_re_tmp].im *
        x[xoff].im;
      r[b_k].im = wwc[temp_re_tmp].re * x[xoff].im - wwc[temp_re_tmp].im *
        x[xoff].re;
      xoff++;
    }

    minNrowsNx++;
    for (b_k = minNrowsNx; b_k <= nfft; b_k++) {
      r[b_k - 1].re = 0.0;
      r[b_k - 1].im = 0.0;
    }

    fy.set_size(n2blue);
    if (n2blue > r.size(0)) {
      fy.set_size(n2blue);
      for (minNrowsNx = 0; minNrowsNx < n2blue; minNrowsNx++) {
        fy[minNrowsNx].re = 0.0;
        fy[minNrowsNx].im = 0.0;
      }
    }

    iy = r.size(0);
    ihi = n2blue;
    if (iy < n2blue) {
      ihi = iy;
    }

    xoff = n2blue - 2;
    nRowsD2 = n2blue / 2;
    b_k = nRowsD2 / 2;
    ix = 0;
    iy = 0;
    ju = 0;
    for (i = 0; i <= ihi - 2; i++) {
      fy[iy] = r[ix];
      minNrowsNx = n2blue;
      tst = true;
      while (tst) {
        minNrowsNx >>= 1;
        ju ^= minNrowsNx;
        tst = ((ju & minNrowsNx) == 0);
      }

      iy = ju;
      ix++;
    }

    fy[iy] = r[ix];
    if (n2blue > 1) {
      for (i = 0; i <= xoff; i += 2) {
        temp_re = fy[i + 1].re;
        temp_im = fy[i + 1].im;
        twid_re = fy[i].re;
        twid_im = fy[i].im;
        fy[i + 1].re = fy[i].re - fy[i + 1].re;
        fy[i + 1].im = fy[i].im - fy[i + 1].im;
        twid_re += temp_re;
        twid_im += temp_im;
        fy[i].re = twid_re;
        fy[i].im = twid_im;
      }
    }

    minNrowsNx = 2;
    xoff = 4;
    iy = ((b_k - 1) << 2) + 1;
    while (b_k > 0) {
      for (i = 0; i < iy; i += xoff) {
        temp_re_tmp = i + minNrowsNx;
        temp_re = fy[temp_re_tmp].re;
        temp_im = fy[temp_re_tmp].im;
        fy[temp_re_tmp].re = fy[i].re - fy[temp_re_tmp].re;
        fy[temp_re_tmp].im = fy[i].im - fy[temp_re_tmp].im;
        fy[i].re = fy[i].re + temp_re;
        fy[i].im = fy[i].im + temp_im;
      }

      ix = 1;
      for (ju = b_k; ju < nRowsD2; ju += b_k) {
        twid_re = costab[ju];
        twid_im = sintab[ju];
        i = ix;
        ihi = ix + iy;
        while (i < ihi) {
          temp_re_tmp = i + minNrowsNx;
          temp_re = twid_re * fy[temp_re_tmp].re - twid_im * fy[temp_re_tmp].im;
          temp_im = twid_re * fy[temp_re_tmp].im + twid_im * fy[temp_re_tmp].re;
          fy[temp_re_tmp].re = fy[i].re - temp_re;
          fy[temp_re_tmp].im = fy[i].im - temp_im;
          fy[i].re = fy[i].re + temp_re;
          fy[i].im = fy[i].im + temp_im;
          i += xoff;
        }

        ix++;
      }

      b_k /= 2;
      minNrowsNx = xoff;
      xoff += xoff;
      iy -= minNrowsNx;
    }

    FFTImplementationCallback::r2br_r2dit_trig_impl((wwc), (n2blue), (costab),
      (sintab), (fv));
    iy = fy.size(0);
    for (minNrowsNx = 0; minNrowsNx < iy; minNrowsNx++) {
      twid_im = fy[minNrowsNx].re * fv[minNrowsNx].im + fy[minNrowsNx].im *
        fv[minNrowsNx].re;
      fy[minNrowsNx].re = fy[minNrowsNx].re * fv[minNrowsNx].re - fy[minNrowsNx]
        .im * fv[minNrowsNx].im;
      fy[minNrowsNx].im = twid_im;
    }

    FFTImplementationCallback::r2br_r2dit_trig_impl((fy), (n2blue), (costab),
      (sintabinv), (fv));
    if (fv.size(0) > 1) {
      twid_re = 1.0 / static_cast<double>(fv.size(0));
      iy = fv.size(0);
      for (minNrowsNx = 0; minNrowsNx < iy; minNrowsNx++) {
        fv[minNrowsNx].re = twid_re * fv[minNrowsNx].re;
        fv[minNrowsNx].im = twid_re * fv[minNrowsNx].im;
      }
    }

    iy = 0;
    minNrowsNx = wwc.size(0);
    for (b_k = nfft; b_k <= minNrowsNx; b_k++) {
      r[iy].re = wwc[b_k - 1].re * fv[b_k - 1].re + wwc[b_k - 1].im * fv[b_k - 1]
        .im;
      r[iy].im = wwc[b_k - 1].re * fv[b_k - 1].im - wwc[b_k - 1].im * fv[b_k - 1]
        .re;
      iy++;
    }

    iy = r.size(0);
    for (minNrowsNx = 0; minNrowsNx < iy; minNrowsNx++) {
      y[minNrowsNx + y.size(0) * chan] = r[minNrowsNx];
    }
  }
}

//
// Arguments    : const coder::array<creal_T, 2U> &x
//                int n1_unsigned
//                const coder::array<double, 2U> &costab
//                const coder::array<double, 2U> &sintab
//                coder::array<creal_T, 2U> &y
// Return Type  : void
//
void FFTImplementationCallback::r2br_r2dit_trig(const coder::array<creal_T, 2U>
  &x, int n1_unsigned, const coder::array<double, 2U> &costab, const coder::
  array<double, 2U> &sintab, coder::array<creal_T, 2U> &y)
{
  int nrows;
  int loop_ub;
  coder::array<creal_T, 1U> r;
  int xoff;
  int iy;
  int iDelta2;
  int j;
  int iheight;
  int nRowsD2;
  int k;
  int ju;
  int b_i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double twid_re;
  double twid_im;
  int temp_re_tmp;
  nrows = x.size(0);
  y.set_size(n1_unsigned, x.size(1));
  if (n1_unsigned > x.size(0)) {
    loop_ub = x.size(1);
    for (int i = 0; i < loop_ub; i++) {
      int b_loop_ub;
      b_loop_ub = y.size(0);
      for (int i1 = 0; i1 < b_loop_ub; i1++) {
        y[i1 + y.size(0) * i].re = 0.0;
        y[i1 + y.size(0) * i].im = 0.0;
      }
    }
  }

  loop_ub = x.size(1) - 1;

#pragma omp parallel for \
 num_threads(omp_get_max_threads()) \
 private(r,xoff,iDelta2,iy,j,iheight,nRowsD2,k,ju,b_i,tst,temp_re,temp_im,twid_re,twid_im,temp_re_tmp)

  for (int chan = 0; chan <= loop_ub; chan++) {
    xoff = chan * nrows;
    r.set_size(n1_unsigned);
    if (n1_unsigned > x.size(0)) {
      r.set_size(n1_unsigned);
      for (iDelta2 = 0; iDelta2 < n1_unsigned; iDelta2++) {
        r[iDelta2].re = 0.0;
        r[iDelta2].im = 0.0;
      }
    }

    iy = x.size(0);
    j = n1_unsigned;
    if (iy < n1_unsigned) {
      j = iy;
    }

    iheight = n1_unsigned - 2;
    nRowsD2 = n1_unsigned / 2;
    k = nRowsD2 / 2;
    iy = 0;
    ju = 0;
    for (b_i = 0; b_i <= j - 2; b_i++) {
      r[iy] = x[xoff];
      iDelta2 = n1_unsigned;
      tst = true;
      while (tst) {
        iDelta2 >>= 1;
        ju ^= iDelta2;
        tst = ((ju & iDelta2) == 0);
      }

      iy = ju;
      xoff++;
    }

    r[iy] = x[xoff];
    if (n1_unsigned > 1) {
      for (b_i = 0; b_i <= iheight; b_i += 2) {
        temp_re = r[b_i + 1].re;
        temp_im = r[b_i + 1].im;
        twid_re = r[b_i].re;
        twid_im = r[b_i].im;
        r[b_i + 1].re = r[b_i].re - r[b_i + 1].re;
        r[b_i + 1].im = r[b_i].im - r[b_i + 1].im;
        twid_re += temp_re;
        twid_im += temp_im;
        r[b_i].re = twid_re;
        r[b_i].im = twid_im;
      }
    }

    iy = 2;
    iDelta2 = 4;
    iheight = ((k - 1) << 2) + 1;
    while (k > 0) {
      for (b_i = 0; b_i < iheight; b_i += iDelta2) {
        temp_re_tmp = b_i + iy;
        temp_re = r[temp_re_tmp].re;
        temp_im = r[temp_re_tmp].im;
        r[temp_re_tmp].re = r[b_i].re - r[temp_re_tmp].re;
        r[temp_re_tmp].im = r[b_i].im - r[temp_re_tmp].im;
        r[b_i].re = r[b_i].re + temp_re;
        r[b_i].im = r[b_i].im + temp_im;
      }

      ju = 1;
      for (j = k; j < nRowsD2; j += k) {
        twid_re = costab[j];
        twid_im = sintab[j];
        b_i = ju;
        xoff = ju + iheight;
        while (b_i < xoff) {
          temp_re_tmp = b_i + iy;
          temp_re = twid_re * r[temp_re_tmp].re - twid_im * r[temp_re_tmp].im;
          temp_im = twid_re * r[temp_re_tmp].im + twid_im * r[temp_re_tmp].re;
          r[temp_re_tmp].re = r[b_i].re - temp_re;
          r[temp_re_tmp].im = r[b_i].im - temp_im;
          r[b_i].re = r[b_i].re + temp_re;
          r[b_i].im = r[b_i].im + temp_im;
          b_i += iDelta2;
        }

        ju++;
      }

      k /= 2;
      iy = iDelta2;
      iDelta2 += iDelta2;
      iheight -= iy;
    }

    iy = r.size(0);
    for (iDelta2 = 0; iDelta2 < iy; iDelta2++) {
      y[iDelta2 + y.size(0) * chan] = r[iDelta2];
    }
  }
}

//
// File trailer for FFTImplementationCallback.cpp
//
// [EOF]
//
