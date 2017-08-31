#include <rice/Array.hpp>
#include <rice/Class.hpp>

template<>
Rice::Object to_ruby<std::vector<uint64_t>>(std::vector<uint64_t> const &numbers)
{
  Rice::Array rb_numbers;
  for (auto number : numbers) {
    rb_numbers.push(number);
  }
  return rb_numbers;
}

static std::vector<uint64_t>
rb_fib(Rice::Object self, int n)
{
  uint64_t prev = 1;
  uint64_t current = 1;
  std::vector<uint64_t> numbers;
  for (int i = 1; i < n; ++i) {
    numbers.push_back(current);
    auto temp = current;
    current += prev;
    prev = temp;
  }
  return numbers;
}

extern "C"
void Init_fibonacci()
{
  Rice::define_class("Fibonacci").
    define_method("fib", &rb_fib);
}
