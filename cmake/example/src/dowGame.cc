#include <iostream>
#include "dow30.h"

int main(int argc, char **argv) {
  dow30 dow = dow30();
  std::cerr << dow.randCompany() << " just filed for bankruptcy." << std::endl;
}
