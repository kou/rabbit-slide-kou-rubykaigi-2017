#include <vector>

#include <iostream>

template <class T>
std::ostream &operator<<(std::ostream &output, const std::vector<T> &vector)
{
  output << "{";
  auto n_elements = vector.size();
  switch (n_elements) {
  case 0:
    break;
  case 1:
    output << vector[0];
    break;
  default:
    output << vector[0];
    for (std::size_t i = 1; i < n_elements; ++i) {
      output << ", ";
      output << vector[i];
    }
    break;
  }
  output << "}";
  return output;
}

namespace {
  std::vector<uint64_t> fib(int n) {
    std::vector<uint64_t> numbers;
    uint64_t prev = 1;
    uint64_t current = 1;
    for (int i = 0; i < n; ++i) {
      numbers.push_back(current);
      auto temp = current;
      current += prev;
      prev = temp;
    }
    return numbers;
  }
}

int
main(int argc, char **argv)
{
  auto numbers = fib(10);
  std::cout << numbers << std::endl;
}
