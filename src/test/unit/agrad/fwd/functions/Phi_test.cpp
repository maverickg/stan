#include <test/unit/agrad/fwd/test_functionals.hpp>
#include <stan/agrad/fwd/functions/Phi.hpp>

struct Phi_functor {
  template <typename T>
  T operator()(const T& x) const {
    using stan::math::Phi;
    return Phi(x);
  }
};

TEST(AgradFwdFunctionsPhi, All) {
  using stan::test::test_unary;
  Phi_functor f;
  test_unary(f, -192.0); // underflow
  test_unary(f, 192.0);  // overflow
  for (double x = -35.5; x <= 10.0; x += 0.5)
    test_unary(f, x);
}

