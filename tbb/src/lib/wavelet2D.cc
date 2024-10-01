#include <wavelet2D.h>

wavelet2D::wavelet2D() {
  const double sqrt_3 = sqrt(3);
  const double denom = 4 * sqrt(2);

  //
  // forward transform scaling (smoothing) coefficients
  //
  h0 = (1 + sqrt_3) / denom;
  h1 = (3 + sqrt_3) / denom;
  h2 = (3 - sqrt_3) / denom;
  h3 = (1 - sqrt_3) / denom;
  //
  // forward transform wavelet coefficients
  //
  g0 = h3;
  g1 = -h2;
  g2 = h1;
  g3 = -h0;

  ih0 = h2;
  ih1 = g2;  // h1
  ih2 = h0;
  ih3 = g0;  // h3

  ig0 = h3;
  ig1 = g3;  // -h0
  ig2 = h1;
  ig3 = g1;  // -h2
}
void wavelet2D::forwardTransform1D(const int n, const float *ar, const int jar,
                                   const int jsm, float *low, float *high) {
  int ismIndex = 0;
  int ibgIndex = 0;
  for (int i = 0, j = 0; j < n - 3; j += 2, i++) {
    low[ismIndex] = ar[ibgIndex] * h0 + ar[ibgIndex + jar] * h1 +
                    ar[ibgIndex + 2 * jar] * h2 + ar[ibgIndex + 3 * jar] * h3;
    high[ismIndex] = ar[ibgIndex] * g0 + ar[ibgIndex + jar] * g1 +
                     ar[ibgIndex + 2 * jar] * g2 + ar[ibgIndex + 3 * jar] * g3;
    ibgIndex += 2 * jar;
    ismIndex += jsm;
  }

  low[ismIndex] =
      ar[ibgIndex] * h0 + ar[ibgIndex] * h1 + ar[0] * h2 + ar[jar] * h3;
  high[ismIndex] =
      ar[ibgIndex] * g0 + ar[ibgIndex] * g1 + ar[0] * g2 + ar[jar] * g3;
}
void wavelet2D::forwardTransformP(const std::shared_ptr<float2DReg> in,
                                  std::shared_ptr<float2DReg> out) {}
void wavelet2D::forwardTransformS(const std::shared_ptr<float2DReg> in,
                                  std::shared_ptr<float2DReg> out) {
  int n2 = in->getHyper()->getAxis(2).n, n1 = in->getHyper()->getAxis(1).n;
  float *tmpS = new float[n2 * n1 / 2];
  float *tmpH = new float[n2 * n1 / 2];
  // Inner transform
  for (int i2 = 0; i2 < n2; i2++) {
    forwardTransform1D(n1, in->getVals() + n1 * i2, 1, 1, tmpS + i2 * n1 / 2,
                       tmpH + i2 * n1 / 2);
  }
  // float *junk = new float[n1 * n2];

  // Outer transform
  // Build matrix
  // LL  LH
  // HL  HH
  // start points
  for (int i1 = 0; i1 < n1 / 2; i1++) {
    //  (*out->_mat)[i2][i1] = tmpS[i2 * n1 / 2 + i1];
    // (*out->_mat)[i2][i1 + n1 / 2] = tmpH[i2 * n1 / 2 + i1];

    // forwardTransform1D(n2, tmpS + i1, n1 / 2, n1, out->getVals() + i1,
    // junk);
    forwardTransform1D(n2, tmpS + i1, n1 / 2, n1, out->getVals() + i1,
                       out->getVals() + i1 + n1 / 2);
    forwardTransform1D(n2, tmpH + i1, n1 / 2, n1,
                       out->getVals() + i1 + n1 * n2 / 2,
                       out->getVals() + i1 + n1 * n2 / 2 + n1 / 2);
  }
  delete[] tmpS;
  delete[] tmpH;
  // delete[] junk;
}

void wavelet2D::inverseTransform1D(const int n, const float *low,
                                   const float *high, const int jsm,
                                   const int jar, float *ar) {
  const int half = n / 2;

  //      last smooth val  last coef.  first smooth  first coef
  ar[0] = low[half - jsm] * ih0 + high[n - 1] * ih1 + low[0] * ih2 +
          high[half] * ih3;
  ar[jar] = low[half - jsm] * ig0 + low[n - 1] * ig1 + low[0] * ig2 +
            high[half] * ig3;
  int ismIndex = 0, ibgIndex = 2 * jar;
  for (int i = 0, j = 2; i < half - 1; i++) {
    //     smooth val     coef. val       smooth val    coef. val
    ar[ibgIndex] = low[ismIndex] * ih0 + high[ismIndex] * ih1 +
                   low[ismIndex + jsm] * ih2 + high[ismIndex + jsm] * ih3;
    ibgIndex += jar;
    ar[ibgIndex] = low[ismIndex] * ig0 + high[ismIndex] * ig1 +
                   low[ismIndex + jsm] * ig2 + high[ismIndex + jsm] * ig3;
    ibgIndex += jar;
    ismIndex += jsm;
  }
}
void wavelet2D::inverseTransformS(const std::shared_ptr<float2DReg> in,
                                  std::shared_ptr<float2DReg> out) {
  int n2 = in->getHyper()->getAxis(2).n, n1 = in->getHyper()->getAxis(1).n;
  float *tmpS = new float[n2 * n1 / 2];
  float *tmpH = new float[n2 * n1 / 2];
  // Outer transform

  for (int i1 = 0; i1 < n1 / 2; i1++) {
    inverseTransform1D(n2, out->getVals() + i1, out->getVals() + i1 + n1 / 2,
                       n1, n1 / 2, tmpS + i1);
    inverseTransform1D(n2, out->getVals() + i1 + n1 * n2 / 2,
                       out->getVals() + i1 + n1 * n2 / 2 + n1 / 2, n1, n1 / 2,
                       tmpH + i1);
  }

  for (int i2 = 0; i2 < n2; i2++) {
    inverseTransform1D(n1, tmpS + i2 * n1 / 2, tmpH + i2 * n1 / 2, 1, 1,
                       out->getVals());
  }

  delete[] tmpS;
  delete[] tmpH;
}
void wavelet2D::inverseTransformP(const std::shared_ptr<float2DReg> in,
                                  std::shared_ptr<float2DReg> out) {}
