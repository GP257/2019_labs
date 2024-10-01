#include <pybind11/chrono.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "mult.h"
#include "wavelet2D.h"
namespace py = pybind11;
using namespace SEP;

namespace gp257 {

PYBIND11_MODULE(pyLabISPC, clsOps) {
  clsOps.def("mult", &mult, "A function that multiplies two vectors");
  clsOps.def("multISPC", &multI,
             "A function that multiplies two vectors using ISPC");
    
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
      .def("forwardTransformV",
           (void (wavelet2D::*)(const std::shared_ptr<float2DReg>,
                                std::shared_ptr<float2DReg>)) &
               wavelet2D::forwardTransformV,
           "Forward transform vectorized")
      .def("inverseTransformV",
           (void (wavelet2D::*)(const std::shared_ptr<float2DReg>,
                                std::shared_ptr<float2DReg>)) &
               wavelet2D::inverseTransformV,
           "Inverse transform vectorized")
      .def("forwardTransformVP",
           (void (wavelet2D::*)(const std::shared_ptr<float2DReg>,
                                std::shared_ptr<float2DReg>)) &
               wavelet2D::forwardTransformVP,
           "Forward transform parallelized and vectorized")
      .def("inverseTransformVP",
           (void (wavelet2D::*)(const std::shared_ptr<float2DReg>,
                                std::shared_ptr<float2DReg>)) &
               wavelet2D::inverseTransformVP,
           "Inverse transform parallelized and vectorized");
}

}  // namespace gp257
