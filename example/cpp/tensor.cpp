#include <iostream>
#include <xtensor/xarray.hpp>

int main(void) {
  xt::xarray<double> array = {1.0, 2.0, 3.0};
  auto result = (array + 2.0) * 3.0;
  for (const auto &element : result) {
    std::cout << element << std::endl;
  }
  return 0;
}
