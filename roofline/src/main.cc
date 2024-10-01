#include <iostream>
#include "heat.h"
int main(int argc, char **argv) {
  heatEqFull he = heatEqFull(100, 100);

  std::vector<float> p1(100 * 100, 0.), p2(100 * 100, 0.);

  p1[49 + 100 * 49] = 1.;

  float *t1 = p1.data(), *t2 = p2.data(), *t3;

  for (int it = 0; it < 1000; it++) {
    std::cerr << it << std::endl;
    he.explicitStep(t1, t2);
    t3 = t1;
    t1 = t2;
    t2 = t3;
  }
}
