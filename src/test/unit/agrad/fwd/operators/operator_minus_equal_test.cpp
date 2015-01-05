#include <test/unit/agrad/fwd/test_functionals.hpp>
#include <boost/math/tools/promotion.hpp>
#include <stan/agrad/fwd/fvar.hpp>

struct op_minus_equal_functor {
  template <typename T1, typename T2>
  typename boost::math::tools::promote_args<T1,T2>::type
  operator()(const T1& x1, const T2& x2) const {
    T1 x1_copy(x1);
    return x1_copy -= x2;
  }
};

TEST(AgradFwdOperatorMultiplication, All) {
  using stan::test::test_binary_op_eq;
  op_minus_equal_functor f;
  test_binary_op_eq(f, 0.3, 9.7);
  test_binary_op_eq(f, -12.2, 15.0);
}


