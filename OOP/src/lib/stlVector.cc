#include "stlVector.h"
#include <stdlib.h>
#include <time.h>
#include <cassert>

stlVector::stlVector(const int n) { _vals.resize(n); }

void stlVector::add(const std::shared_ptr<myVector> v2) {
  // ------------------------
  //  FILL IN THIS FUNCTION
  // ------------------------
}


void stlVector::scale(const float sc) {
  // ------------------------
  //  FILL IN THIS FUNCTION
  // ------------------------
}

std::shared_ptr<myVector> stlVector::clone() const {
  std::shared_ptr<stlVector> v(new stlVector(_vals.size()));
  for (auto i = 0; i < _vals.size(); i++) 
    v->_vals[i] = _vals[i];
  return v;
}
            
bool stlVector::checkSame(const std::shared_ptr<myVector> v2) const {
  std::shared_ptr<stlVector> v = std::dynamic_pointer_cast<stlVector>(v2);
  // Check to make sure the vectors are the same size
  assert(v);
  assert(v->_vals.size() == _vals.size());
  return true;
}
    
double stlVector::dot(const std::shared_ptr<myVector> v2) const {
  checkSame(v2);
  std::shared_ptr<stlVector> v = std::dynamic_pointer_cast<stlVector>(v2);
  double dot = 0;
  for (unsigned int i = 0; i < _vals.size(); i++)
    dot += _vals[i] * v->_vals[i];
  return dot;
}
    
void stlVector::random() {
  srand(time(0));
  for (unsigned int i = 0; i < _vals.size(); i++)
    _vals[i] = (float)rand() / RAND_MAX;
}
