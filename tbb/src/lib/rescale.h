
#pragma once

#include "float2DReg.h"

using namespace SEP;
namespace gp257 {
class rescale2D {
 public:
  rescale2D(const int rescale) : _rescale(rescale) { ; }
  void forwardS(const std::shared_ptr<float2DReg> mod,
                std::shared_ptr<float2DReg> dat);
  void adjointS(std::shared_ptr<float2DReg> mod,
                const std::shared_ptr<float2DReg> dat);
  void forwardP(const std::shared_ptr<float2DReg> mod,
                std::shared_ptr<float2DReg> dat);
  void forwardP2(const std::shared_ptr<float2DReg> mod,
                 std::shared_ptr<float2DReg> dat);
  void adjointP(std::shared_ptr<float2DReg> mod,
                const std::shared_ptr<float2DReg> dat);
  void adjointP2(std::shared_ptr<float2DReg> mod,
                 const std::shared_ptr<float2DReg> dat);

 private:
  int _rescale;
  std::vector<std::vector<int> > _ind1, _ind;
  std::vector<std::vector<float> > _f1, _f2;
};
}  // namespace gp257
