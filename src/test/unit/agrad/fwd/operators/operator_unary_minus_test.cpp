#include <test/unit/agrad/fwd/test_functionals.hpp>
#include <stan/agrad/fwd/operators/operator_unary_minus.hpp>

struct op_minus_functor {
  template <typename T>
  T operator()(const T& x) const {
    return -x;
  }
};

TEST(AgradFwdOperatorUnaryMinus, All) {
  using stan::test::test_unary;
  op_minus_functor f;
  test_unary(f, 3.0);
  test_unary(op_minus_functor(), 0.0);
  test_unary(op_minus_functor(), -192.0);
}

