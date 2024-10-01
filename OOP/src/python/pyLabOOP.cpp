#include <pybind11/chrono.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "stlVector.h"
namespace py = pybind11;

namespace gp257 {

PYBIND11_MODULE(pyLabOOP, clsOps) {
  py::class_<myVector, std::shared_ptr<myVector>>(clsOps, "myVector");

  py::class_<stlVector, myVector, std::shared_ptr<stlVector>>(
      clsOps, "stlVector", py::buffer_protocol())
      .def(py::init<const int>(), "Initialize ")
      .def("add",
           (void (stlVector::*)(const std::shared_ptr<myVector>)) &
               stlVector::add,
           "Add vector to current vector")
      .def("scale", (void (stlVector::*)(const float)) & stlVector::scale,
           "Scale vector to current vector")
      .def("clone",
           (std::shared_ptr<myVector>(stlVector::*)()) & stlVector::clone,
           "Clone a vector")
      .def("dot",
           (double (stlVector::*)(
               const std::shared_ptr<myVector>)) &
               stlVector::dot,
           "Dot current vector with another vector")
      .def("checkSame",
           (bool (stlVector::*)(const std::shared_ptr<myVector>)) &
               stlVector::checkSame,
           "Check vectors are the same size")
      .def("random", (void (stlVector::*)()) & stlVector::random,
           "FIll vector with random numbers")
      .def_buffer([](stlVector &m) -> py::buffer_info {
        return py::buffer_info(m._vals.data(), sizeof(float),
                               py::format_descriptor<float>::format(), 1,
                               {m._vals.size()}, {sizeof(float)});
      });
}
}  // namespace gp257
