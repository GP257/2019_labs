#pragma once

class myVector {
 public:
  myVector() { ; }

  virtual void add(const std::shared_ptr<myVector> v2) = 0;
  virtual void scale(const float sc) = 0;
  virtual std::shared_ptr<myVector> clone() const = 0;
  virtual bool checkSame(const std::shared_ptr<myVector> v2) const = 0;
  virtual double dot(const std::shared_ptr<myVector> v2) const = 0;
  virtual void random() = 0;
};
