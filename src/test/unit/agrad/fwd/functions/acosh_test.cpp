#include <test/unit/agrad/fwd/test_functionals.hpp>
#include <stan/agrad/fwd/functions/acosh.hpp>

struct acosh_functor {
  template <typename T>
  T operator()(const T& x) const {
    using std::acosh;
    return acosh(x);
  }
};

TEST(AgradFwdFunctionsAcosh, All) {
  using stan::test::test_unary;
  acosh_functor f;
  test_unary(f, -2.7);
  test_unary(f, 0.0);
  test_unary(f, 2.9);
}




