#include <rescale.h>
#include <cassert>
#include <omp.h>

using namespace gp257;

void rescale2D::forwardS(const std::shared_ptr<float2DReg> mod,
                         std::shared_ptr<float2DReg> dat) {
  const std::shared_ptr<hypercube> hM = mod->getHyper(), hD = dat->getHyper();
  assert((hM->getAxis(1).n - 1) * _rescale == hD->getAxis(1).n);
  assert((hM->getAxis(2).n - 1) * _rescale == hD->getAxis(2).n);
  float db = 1. / (float)_rescale;
    
  for (int i2 = 0; i2 < hM->getAxis(2).n - 1; i2++) {
    for (int i1 = 0; i1 < hM->getAxis(1).n - 1; i1++) {
      float b11 = (*mod->_mat)[i2][i1], b21 = (*mod->_mat)[i2][i1 + 1],
            b12 = (*mod->_mat)[i2 + 1][i1], b22 = (*mod->_mat)[i2 + 1][i1 + 1];
      float f2 = 0;
      for (int ir2 = 0, id2 = i2 * _rescale; ir2 < _rescale;
           ir2++, id2++, f2 += db) {
        float f1 = 0;
        for (int ir1 = 0, id1 = i1 * _rescale; ir1 < _rescale;
             ir1++, id1++, f1 += db) {
          (*dat->_mat)[id2][id1] = (1. - f1) * (1. - f2) * b11 +
                                   (f1) * (1. - f2) * b21 +
                                   (1. - f1) * (f2)*b12 + f1 * f2 * b22;
        }
      }
    }
  }
}
        
void rescale2D::forwardP(const std::shared_ptr<float2DReg> mod,
                         std::shared_ptr<float2DReg> dat) {}

void rescale2D::forwardP2(const std::shared_ptr<float2DReg> mod,
                          std::shared_ptr<float2DReg> dat) {}
        
void rescale2D::adjointS(std::shared_ptr<float2DReg> mod,
                         const std::shared_ptr<float2DReg> dat) {
  const std::shared_ptr<hypercube> hM = mod->getHyper(), hD = dat->getHyper();
  assert((hM->getAxis(1).n - 1) * _rescale == hD->getAxis(1).n);
  assert((hM->getAxis(2).n - 1) * _rescale == hD->getAxis(2).n);
  float db = 1. / (float)_rescale;

  for (int i2 = 0; i2 < hM->getAxis(2).n; i2++) {
    for (int i1 = 0; i1 < hM->getAxis(1).n; i1++) {
      (*mod->_mat)[i2][i1] = 0;
    }
  }

  for (int i2 = 0; i2 < hM->getAxis(2).n - 1; i2++) {
    for (int i1 = 0; i1 < hM->getAxis(1).n - 1; i1++) {
      float f2 = 0;
      for (int ir2 = 0, id2 = i2 * _rescale; ir2 < _rescale;
           ir2++, id2++, f2 += db) {
        float f1 = 0;
        for (int ir1 = 0, id1 = i1 * _rescale; ir1 < _rescale;
             ir1++, id1++, f1 += db) {
          (*mod->_mat)[i2][i1] +=
              (1. - f1) * (1. - f2) * (*dat->_mat)[id2][id1];
          (*mod->_mat)[i2][i1 + 1] += (f1) * (1. - f2) * (*dat->_mat)[id2][id1];
          (*mod->_mat)[i2 + 1][i1] += (1. - f1) * (f2) * (*dat->_mat)[id2][id1];
          (*mod->_mat)[i2 + 1][i1 + 1] += (f1) * (f2) * (*dat->_mat)[id2][id1];
        }
      }
    }
  }
}

void rescale2D::adjointP(std::shared_ptr<float2DReg> mod,
              const std::shared_ptr<float2DReg> dat) {}

void rescale2D::adjointP2(std::shared_ptr<float2DReg> mod,
               const std::shared_ptr<float2DReg> dat) {}