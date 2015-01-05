#include <gtest/gtest.h>
#include <sstream>

#include <stan/agrad/fwd/fvar.hpp>


TEST(AgradFwdFvar,ctor) {
  using stan::agrad::fvar;

  fvar<double> a;
  EXPECT_FLOAT_EQ(0.0, a.val_);
  EXPECT_FLOAT_EQ(0.0, a.d_);

  fvar<double> b(1.9);
  EXPECT_FLOAT_EQ(1.9, b.val_);
  EXPECT_FLOAT_EQ(0.0, b.d_);

  fvar<double> c(1.93, -27.832);
  EXPECT_FLOAT_EQ(1.93, c.val_);
  EXPECT_FLOAT_EQ(-27.832, c.d_);
}

TEST(AgradFwdFvar, plusEqVar) {
  using stan::agrad::fvar;

  fvar<double> d(2.0,3.0);
  fvar<double> e(5.0,7.0);
  d += e;
  EXPECT_FLOAT_EQ(7.0, d.val_);
  EXPECT_FLOAT_EQ(10.0, d.d_);

  EXPECT_FLOAT_EQ(7, (d++).val_);
  EXPECT_FLOAT_EQ(8, d.val_);

  EXPECT_FLOAT_EQ(9, (++d).val_);
  EXPECT_FLOAT_EQ(9, d.val_);

  EXPECT_FLOAT_EQ(10.0,d.d_);
}
TEST(AgradFwdFvar, plusEqDouble) {
  using stan::agrad::fvar;

  fvar<double> a(2.0,3.0);
  a += 5;
  EXPECT_FLOAT_EQ(7.0, a.val_);
  EXPECT_FLOAT_EQ(3.0, a.d_);
}

TEST(AgradFwdFvar, minusEqVar) {
  using stan::agrad::fvar;

  fvar<double> d(2.0,1.5);
  fvar<double> e(5.0);
  d -= e;
  EXPECT_FLOAT_EQ(-3.0, d.val_);

  EXPECT_FLOAT_EQ(-3.0, (d++).val_);
  EXPECT_FLOAT_EQ(-2.0, d.val_);

  EXPECT_FLOAT_EQ(-1.0, (++d).val_);
  EXPECT_FLOAT_EQ(-1.0, d.val_);

  EXPECT_FLOAT_EQ(1.5, d.d_);
}
TEST(AgradFwdFvar, minusEqDouble) {
  using stan::agrad::fvar;

  fvar<double> a(2.0,3.0);
  a -= 5;
  EXPECT_FLOAT_EQ(-3.0, a.val_);
  EXPECT_FLOAT_EQ(3.0, a.d_);
}


TEST(AgradFwdFvar, timesEqVar) {
  using stan::agrad::fvar;

  fvar<double> d(2.0,3.0);
  fvar<double> e(5.0,7.0);
  d *= e;

  EXPECT_FLOAT_EQ(10, d.val_);
  EXPECT_FLOAT_EQ(29, d.d_);
}
TEST(AgradFwdFvar, timesEqDouble) {
  using stan::agrad::fvar;

  fvar<double> a(2.0,3.0);
  a *= 5.0;

  EXPECT_FLOAT_EQ(10, a.val_);
  EXPECT_FLOAT_EQ(15, a.d_);
}

// (d * e^-1)' = d' / e  -  d / e^2  * e'

TEST(AgradFwdFvar, divEqVar) {
  using stan::agrad::fvar;

  fvar<double> d(2.0,3.0);
  fvar<double> e(5.0,7.0);
  d /= e;

  EXPECT_FLOAT_EQ(0.4, d.val_);
  EXPECT_FLOAT_EQ(3.0 / 5.0 - 2.0 / (5.0 * 5.0) * 7.0,
                  d.d_);
}
TEST(AgradFwdFvar, divEqDouble) {
  using stan::agrad::fvar;

  fvar<double> a(2.0,3.0);
  a /= 5.0;

  EXPECT_FLOAT_EQ(0.4, a.val_);
  EXPECT_FLOAT_EQ(0.6, a.d_);
}


TEST(AgradFwdFvar,OpOutStream) {
  using stan::agrad::fvar;

  std::stringstream s;
  s << fvar<double>(2.0,3.0);
  EXPECT_EQ("2:3", s.str());
}


