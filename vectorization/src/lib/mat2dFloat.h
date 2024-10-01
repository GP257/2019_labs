#include <cassert>
#include "boost/multi_array.hpp"
#include "hypercube.h"
using namespace SEP;
typedef boost::multi_array<float, 2> float2D;
namespace gp257 {
class mat2DFloat {
 public:
  mat2DFloat(const std::shared_ptr<hypercube> hyp);

  std::unique_ptr<float2D> _vals;
  const std::shared_ptr<hypercube> getHyper() const { return _hyper; }

 private:
  std::shared_ptr<hypercube> _hyper;
};
}  // namespace gp257
