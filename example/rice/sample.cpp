#include <rice/Class.hpp>

static const char * // Not VALUE!
rb_sample_hello(Rice::Object self)
{
  return "Hello";
}

extern "C"
void Init_sample()
{
  Rice::define_class("Sample").
    define_method("hello", &rb_sample_hello);
}
