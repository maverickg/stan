#include <test/unit/agrad/fwd/test_functionals.hpp>
#include <stan/agrad/fwd/operators/operator_not_equal.hpp>

struct operator_not_equal_functor {
  template <typename T1, typename T2>
  bool operator()(const T1& x1, const T2& x2) const {
    return x1 != x2;
  }
};

TEST(AgradFwdOperatorNotEqual, All) {
  using stan::test::test_binary_relation;
  operator_not_equal_functor f;
  test_binary_relation(f, 1.2, 1.2);
  test_binary_relation(f, 1.2, 3.5);
  
  double nan = std::numeric_limits<double>::quiet_NaN();
  test_binary_relation(f, nan, 1);
  test_binary_relation(f, 1, nan);
  test_binary_relation(f, nan, nan);
}
