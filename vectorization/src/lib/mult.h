#include "float1DReg.h"

#include "kernel.h"

using namespace SEP;

inline void multI(std::shared_ptr<float1DReg> aa,
                  std::shared_ptr<float1DReg> bb) {
  multISPC(aa->getVals(), bb->getVals(), aa->getHyper()->getN123());
}

void mult(std::shared_ptr<float1DReg> aa, std::shared_ptr<float1DReg> bb);
