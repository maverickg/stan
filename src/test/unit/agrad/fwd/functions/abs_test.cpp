#include <test/unit/agrad/fwd/test_functionals.hpp>
#include <stan/agrad/fwd/functions/abs.hpp>

struct abs_functor {
  template <typename T>
  T operator()(const T& x) const {
    using stan::math::abs;
    return abs(x);
  }
};

TEST(AgradFwdFunctionsAbs, All) {
  using stan::test::test_unary;
  abs_functor f;
  test_unary(f, -2.7);
  test_unary(f, 0.0);
  test_unary(f, 2.9);
}


