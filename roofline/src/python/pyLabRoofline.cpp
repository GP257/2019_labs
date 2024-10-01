#include <pybind11/chrono.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "heat.h"
namespace py = pybind11;
using namespace SEP;

namespace gp257 {

PYBIND11_MODULE(pyLabRoofline, clsOps) {
  py::class_<heatEqFull, std::shared_ptr<heatEqFull>>(clsOps, "heatEqFull")
      .def(py::init<const std::shared_ptr<float2DReg>>(), "Initialize ")
      .def("explicitStep",
           (void (heatEqFull::*)(const std::shared_ptr<float2DReg>,
                                 std::shared_ptr<float2DReg>)) &
               heatEqFull::explicitStep,
           "Explicit step");

  py::class_<heatEqSparse, std::shared_ptr<heatEqSparse>>(clsOps,
                                                          "heatEqSparse")
      .def(py::init<const std::shared_ptr<float2DReg>>(), "Initialize ")
      .def("explicitStep",
           (void (heatEqSparse::*)(const std::shared_ptr<float2DReg>,
                                   std::shared_ptr<float2DReg>)) &
               heatEqSparse::explicitStep,
           "Explicit step");
  py::class_<heatEqOp, std::shared_ptr<heatEqOp>>(clsOps, "heatEquationOp")
      .def(py::init<const std::shared_ptr<float2DReg>>(), "Initialize ")
      .def("explicitStep",
           (void (heatEqOp::*)(const std::shared_ptr<float2DReg>,
                               std::shared_ptr<float2DReg>)) &
               heatEqOp::explicitStep,
           "Explicit step");
}

}  // namespace gp257
