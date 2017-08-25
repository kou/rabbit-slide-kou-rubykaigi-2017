#include <ruby.hpp>

namespace {
  VALUE rb_hello(VALUE self) {
    return rb_str_new_cstr("Hello");
  }

  VALUE rb_named_hello(int argc, VALUE *argv, VALUE self) {
    VALUE rb_name;
    rb_scan_args(argc, argv, "10", &rb_name);
    return rb_str_plus(rb_str_new_cstr("Hello "), rb_name);
  }
}

extern "C" void
Init_fibonacci(void)
{
  rb::Class(rb_cObject).
    define_method("fib_cpp", [](int argc, VALUE *argv, VALUE self) {
        VALUE rb_n;
        rb_scan_args(argc, argv, "1", &rb_n);

        auto n = rb::from_ruby<int>(rb_n);
        VALUE rb_results = rb_ary_new_capa(n);
        uint64_t prev = 1;
        uint64_t current = 1;
        for (int i = 0; i < n; ++i) {
          rb_ary_push(rb_results, rb::to_ruby(current));
          auto temp = current;
          current += prev;
          prev = temp;
        }
        return rb_results;
      });
}
