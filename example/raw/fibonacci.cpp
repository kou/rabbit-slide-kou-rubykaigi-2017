#include <ruby.h>

namespace {
  static VALUE
  rb_fib(VALUE self, VALUE rb_n)
  {
    int n = NUM2INT(rb_n);
    uint64_t prev = 1;
    uint64_t current = 1;
    VALUE rb_numbers = rb_ary_new_capa(n);
    for (int i = 1; i < n; ++i) {
      rb_ary_push(rb_numbers, ULL2NUM(current));
      auto temp = current;
      current += prev;
      prev = temp;
    }
    return rb_numbers;
  }
}

extern "C"
void Init_fibonacci()
{
  VALUE rb_cFibonacci = rb_define_class("Fibonacci", rb_cObject);
  rb_define_method(rb_cFibonacci,
                   "fib",
                   RUBY_METHOD_FUNC(rb_fib),
                   1);
}
