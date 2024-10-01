#pragma once
#include <memory>
#include <vector>
#include "myVector.h"

class stlVector : public myVector {
 public:
  stlVector(const int n);
  virtual void add(const std::shared_ptr<myVector> v2);
  virtual void scale(const float sc);
  virtual std::shared_ptr<myVector> clone() const;
  virtual double dot(const std::shared_ptr<myVector> dot) const;
  virtual bool checkSame(const std::shared_ptr<myVector> v2) const;
  virtual void random();
  std::vector<float> _vals;
};
