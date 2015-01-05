#include <test/unit/agrad/fwd/test_functionals.hpp>
#include <boost/math/tools/promotion.hpp>
#include <stan/agrad/fwd/operators/operator_subtraction.hpp>

struct op_subtract_functor {
  template <typename T1, typename T2>
  typename boost::math::tools::promote_args<T1,T2>::type
  operator()(const T1& x1, const T2& x2) const {
    return x1 - x2;
  }
};

TEST(AgradFwdOperatorSubtraction, All) {
  using stan::test::test_binary;
  op_subtract_functor f;
  test_binary(f, 0.3, 9.7);
  test_binary(f, -12.2, 15.0);
}

