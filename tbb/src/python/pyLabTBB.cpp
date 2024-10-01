#include <pybind11/chrono.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "wavelet2D.h"
namespace py = pybind11;
using namespace SEP;

namespace gp257 {

PYBIND11_MODULE(pyLabTBB, clsOps) {
  py::class_<wavelet2D, std::shared_ptr<wavelet2D>>(clsOps, "wavelet2D")
      .def(py::init<>(), "Initialize ")
      .def("forwardTransformS",
           (void (wavelet2D::*)(const std::shared_ptr<float2DReg>,
                                std::shared_ptr<float2DReg>)) &
               wavelet2D::forwardTransformS,
           "Forward transform serial")
      .def("inverseTransformS",
           (void (wavelet2D::*)(const std::shared_ptr<float2DReg>,
                                std::shared_ptr<float2DReg>)) &
               wavelet2D::inverseTransformS,
           "Inverse transform serial")
      .def("forwardTransformP",
           (void (wavelet2D::*)(const std::shared_ptr<float2DReg>,
                                std::shared_ptr<float2DReg>)) &
               wavelet2D::forwardTransformP,
           "Forward transform serial")
      .def("inverseTransformP",
           (void (wavelet2D::*)(const std::shared_ptr<float2DReg>,
                                std::shared_ptr<float2DReg>)) &
               wavelet2D::inverseTransformP,
           "Inverse transform serial");
}

}  // namespace gp257
