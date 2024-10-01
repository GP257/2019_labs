#pragma once
#include <float2DReg.h>

#include <memory>
using namespace SEP;

class wavelet2D {
 public:
  wavelet2D();
  void forwardTransform1D(const int n, const float *ar, const int jar,
                          const int jsm, float *low, float *high);
  void inverseTransform1D(const int n, const float *low, const float *high,
                          const int jsm, const int jar, float *ar);
  void forwardTransformS(const std::shared_ptr<float2DReg> in,
                         std::shared_ptr<float2DReg> out);
  void inverseTransformS(const std::shared_ptr<float2DReg> in,
                         std::shared_ptr<float2DReg> out);
  void forwardTransformP(const std::shared_ptr<float2DReg> in,
                         std::shared_ptr<float2DReg> out);
  void inverseTransformP(const std::shared_ptr<float2DReg> in,
                         std::shared_ptr<float2DReg> out);

 private:
  float g0, g1, g2, g3;
  float h0, h1, h2, h3;
  float ig0, ig1, ig2, ig3;
  float ih0, ih1, ih2, ih3;
};