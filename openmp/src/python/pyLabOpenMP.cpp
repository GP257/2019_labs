#include <pybind11/chrono.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "rescale.h"
namespace py = pybind11;
using namespace SEP;

namespace gp257 {

PYBIND11_MODULE(pyLabOpenMP, clsOps) {
  py::class_<rescale2D, std::shared_ptr<rescale2D>>(clsOps, "rescale2D")
    .def(py::init<const int>(), "Initialize ")
    .def("forwardS",
           (void (rescale2D::*)(const std::shared_ptr<float2DReg>,
                                std::shared_ptr<float2DReg>)) &
               rescale2D::forwardS,
           "Linear Forward operator serial")
    .def("adjointS",
           (void (rescale2D::*)(std::shared_ptr<float2DReg>,
                                const std::shared_ptr<float2DReg>)) &
               rescale2D::adjointS,
           "Linear Adjoint operator serial")
    .def("forwardP",
       (void (rescale2D::*)(const std::shared_ptr<float2DReg>,
                            std::shared_ptr<float2DReg>)) &
           rescale2D::forwardP,
       "Linear Forward operator parallel inner loop")
    .def("forwardP2",
       (void (rescale2D::*)(const std::shared_ptr<float2DReg>,
                            std::shared_ptr<float2DReg>)) &
           rescale2D::forwardP2,
       "Linear Forward operator parallel outer loop")
    .def("adjointP",
           (void (rescale2D::*)(std::shared_ptr<float2DReg>,
                                const std::shared_ptr<float2DReg>)) &
               rescale2D::adjointP,
           "Linear Adjoint operator parallel v1")
    .def("adjointP2",
       (void (rescale2D::*)(std::shared_ptr<float2DReg>,
                            const std::shared_ptr<float2DReg>)) &
           rescale2D::adjointP2,
       "Linear Adjoint operator parallel v2");
}

}  // namespace gp257
