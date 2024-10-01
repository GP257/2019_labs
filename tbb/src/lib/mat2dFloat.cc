#include "mat2dFloat.h"
using namespace gp257;
mat2DFloat::mat2DFloat(const std::shared_ptr<hypercube> hyper) {
  assert(hyper->getNdim() == 2);
  _hyper = hyper->clone();
  _vals.reset(
      new float2D(boost::extents[_hyper->getAxis(1).n][_hyper->getAxis(0).n]));
}
