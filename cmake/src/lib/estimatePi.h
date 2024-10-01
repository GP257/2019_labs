#pragma once
#include <cstdlib>
#include <ctime>

class estimatePi {
 public:
  estimatePi() {
    srand((unsigned)time(0));
  }
  double run(const long n_trys);
};
