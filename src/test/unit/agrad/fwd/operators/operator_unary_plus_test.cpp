#include <test/unit/agrad/fwd/test_functionals.hpp>
#include <stan/agrad/fwd/operators/operator_unary_plus.hpp>

struct op_unary_plus_functor {
  template <typename T>
  T operator()(const T& x) const {
    return +x;
  }
};

TEST(AgradFwdOperatorUnaryPlus, All) {
  using stan::test::test_unary;
  op_unary_plus_functor f;
  test_unary(f, 3.0);
  test_unary(f, 0.0);
  test_unary(f, -192.0);
}

