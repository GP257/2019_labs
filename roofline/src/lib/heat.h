#include <float2DReg.h>
#pragma once
using namespace SEP;
#include <vector>
class heatEq {
 public:
  heatEq() { ; }
  void allocFill(const std::shared_ptr<float2DReg> in);

  virtual void explicitStep(const std::shared_ptr<float2DReg> in,
                            std::shared_ptr<float2DReg> out) = 0;
  ~heatEq() { ; }
  std::vector<float> _dif;
  int _n1, _n2;

 private:
};

class heatEqFull : public heatEq {
 public:
  heatEqFull(const std::shared_ptr<float2DReg> in);
  virtual void explicitStep(const std::shared_ptr<float2DReg> in,
                            std::shared_ptr<float2DReg> out);
  ~heatEqFull() { ; }
  std::vector<std::vector<float>> _full;
};
class heatEqSparse : public heatEq {
 public:
  heatEqSparse(const std::shared_ptr<float2DReg> in);
  virtual void explicitStep(const std::shared_ptr<float2DReg> in,
                            std::shared_ptr<float2DReg> out);
  ~heatEqSparse() { ; }
};

class heatEqOp : public heatEq {
 public:
  heatEqOp(const std::shared_ptr<float2DReg> in);
  virtual void explicitStep(const std::shared_ptr<float2DReg> in,
                            std::shared_ptr<float2DReg> out);
  ~heatEqOp() { ; }
};