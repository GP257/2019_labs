#include <gtest/gtest.h>  // googletest header file
#include <iostream>
#include <string>
#include "stlVector.h"
using std::string;
TEST(checkCreate, stlVector) {
  std::shared_ptr<stlVector> z(new stlVector(10));
  EXPECT_EQ(z->_vals.size(), 10);
}
