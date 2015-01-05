#include <test/unit/agrad/fwd/test_functionals.hpp>
#include <boost/math/tools/promotion.hpp>
#include <stan/agrad/fwd/operators/operator_addition.hpp>

struct op_add_functor {
  template <typename T1, typename T2>
  typename boost::math::tools::promote_args<T1,T2>::type
  operator()(const T1& x1, const T2& x2) const {
    return x1 + x2;
  }
};

TEST(AgradFwdOperatorAddition, All) {
  using stan::test::test_binary;
  test_binary(op_add_functor(), 0.3, 9.7);
  test_binary(op_add_functor(), -12.2, 15.0);
}

