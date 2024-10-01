#include "heat.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

void heatEq::allocFill(const std::shared_ptr<float2DReg> in) {
  _n1 = in->getHyper()->getAxis(1).n;
  _n2 = in->getHyper()->getAxis(2).n;
  _dif.resize(_n1 * _n2);
  srand(time(NULL));
    
  for (int i = 0; i < _n1 * _n2; i++) {
    _dif[i] = .05 + .1 * (((float)rand() / (float)RAND_MAX) - .5);
  }
}

heatEqFull::heatEqFull(const std::shared_ptr<float2DReg> in) {
  allocFill(in);
  for (int i2 = 0; i2 < _n2; i2++) {
    for (int i1 = 0; i1 < _n1; i1++) {
      std::vector<float> v(_n1 * _n2, 0.);
      if (i2 > 1 && i2 < _n2 - 1 && i1 > 1 && i1 < _n1 - 1) {
        v[i1 + i2 * _n1] = -4 * _dif[i1 + i2 * _n1] + 1;
        v[i1 + i2 * _n1 - 1] = _dif[i1 + i2 * _n1];
        v[i1 + i2 * _n1 + 1] = _dif[i1 + i2 * _n1];
        v[i1 + i2 * _n1 + _n1] = _dif[i1 + i2 * _n1];
        v[i1 + i2 * _n1 - _n1] = _dif[i1 + i2 * _n1];
      }
      _full.push_back(v);
    }
  }
}

void heatEqFull::explicitStep(const std::shared_ptr<float2DReg> in,
                              std::shared_ptr<float2DReg> out) {
  int i = 0;
  for (int i2 = 0; i2 < _n2; i2++) {
    for (int i1 = 0; i1 < _n1; i1++, i++) {
      (*out->_mat)[i2][i1] = 0;
      int j = 0;
      for (int j2 = 0; j2 < _n2; j2++) {
        for (int j1 = 0; j1 < _n1; j1++, j++) {
          (*out->_mat)[i2][i1] += (*in->_mat)[j2][j1] * _full[i][j];
        }
      }
    }
  }
}

heatEqSparse::heatEqSparse(const std::shared_ptr<float2DReg> in) {
  allocFill(in);
}
        
void heatEqSparse::explicitStep(const std::shared_ptr<float2DReg> in,
                                std::shared_ptr<float2DReg> out) {}

heatEqOp::heatEqOp(const std::shared_ptr<float2DReg> in) { 
  allocFill(in);
}
        
void heatEqOp::explicitStep(const std::shared_ptr<float2DReg> in,
                            std::shared_ptr<float2DReg> out) {}
