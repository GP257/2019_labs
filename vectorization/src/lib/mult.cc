#include <float1DReg.h>

#include "mult.h"
#include "stdio.h"

void mult(std::shared_ptr<float1DReg> aa, std::shared_ptr<float1DReg> bb) {
  float *a = aa->getVals(), *b = bb->getVals();
  long long n = aa->getHyper()->getN123();

  for (int i = 0; i < n; i++) {
    a[i] = a[i] + b[i];
  }
}
