#include <stan/math/matrix/minus.hpp>
#include <gtest/gtest.h>
#include <stan/math/matrix/typedefs.hpp>
#include <stan/agrad/fwd/matrix/typedefs.hpp>
#include <stan/agrad/fvar.hpp>
#include <stan/agrad/var.hpp>

using stan::agrad::fvar;

TEST(AgradFwdMatrix, minus_scalar) {
  using stan::math::minus;
  double x = 10;
  fvar<double> v = 11;
   v.d_ = 1.0;
  
  EXPECT_FLOAT_EQ(-10, minus(x));
  EXPECT_FLOAT_EQ(-11, minus(v).val_);
  EXPECT_FLOAT_EQ( -1, minus(v).d_);
}
TEST(AgradFwdMatrix, minus_vector) {
  using stan::math::vector_d;
  using stan::agrad::vector_fv;
  using stan::math::minus;

  vector_d d(3);
  vector_fv v(3);

  d << -100, 0, 1;
  v << -100, 0, 1;
   v(0).d_ = 1.0;
   v(1).d_ = 1.0;
   v(2).d_ = 1.0;
  
  vector_d output_d;
  output_d = minus(d);
  EXPECT_FLOAT_EQ(100, output_d[0]);
  EXPECT_FLOAT_EQ(0, output_d[1]);
  EXPECT_FLOAT_EQ(-1, output_d[2]);

  vector_fv output;
  output = minus(v);
  EXPECT_FLOAT_EQ(100, output[0].val_);
  EXPECT_FLOAT_EQ(0, output[1].val_);
  EXPECT_FLOAT_EQ(-1, output[2].val_);
  EXPECT_FLOAT_EQ(-1, output[0].d_);
  EXPECT_FLOAT_EQ(-1, output[1].d_);
  EXPECT_FLOAT_EQ(-1, output[2].d_);
}
TEST(AgradFwdMatrix, minus_rowvector) {
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fv;
  using stan::math::minus;

  row_vector_d d(3);
  row_vector_fv v(3);

  d << -100, 0, 1;
  v << -100, 0, 1;
   v(0).d_ = 1.0;
   v(1).d_ = 1.0;
   v(2).d_ = 1.0;
  
  row_vector_d output_d;
  output_d = minus(d);
  EXPECT_FLOAT_EQ(100, output_d[0]);
  EXPECT_FLOAT_EQ(0, output_d[1]);
  EXPECT_FLOAT_EQ(-1, output_d[2]);

  row_vector_fv output;
  output = minus(v);
  EXPECT_FLOAT_EQ(100, output[0].val_);
  EXPECT_FLOAT_EQ(0, output[1].val_);
  EXPECT_FLOAT_EQ(-1, output[2].val_);
  EXPECT_FLOAT_EQ(-1, output[0].d_);
  EXPECT_FLOAT_EQ(-1, output[1].d_);
  EXPECT_FLOAT_EQ(-1, output[2].d_);
}
TEST(AgradFwdMatrix, minus_matrix) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_fv;
  using stan::math::minus;

  matrix_d d(2, 3);
  matrix_fv v(2, 3);

  d << -100, 0, 1, 20, -40, 2;
  v << -100, 0, 1, 20, -40, 2;
   v(0,0).d_ = 1.0;
   v(0,1).d_ = 1.0;
   v(0,2).d_ = 1.0;
   v(1,0).d_ = 1.0;
   v(1,1).d_ = 1.0;
   v(1,2).d_ = 1.0;

  matrix_d output_d = minus(d);
  EXPECT_FLOAT_EQ(100, output_d(0,0));
  EXPECT_FLOAT_EQ(  0, output_d(0,1));
  EXPECT_FLOAT_EQ( -1, output_d(0,2));
  EXPECT_FLOAT_EQ(-20, output_d(1,0));
  EXPECT_FLOAT_EQ( 40, output_d(1,1));
  EXPECT_FLOAT_EQ( -2, output_d(1,2));

  matrix_fv output = minus(v);
  EXPECT_FLOAT_EQ(100, output(0,0).val_);
  EXPECT_FLOAT_EQ(  0, output(0,1).val_);
  EXPECT_FLOAT_EQ( -1, output(0,2).val_);
  EXPECT_FLOAT_EQ(-20, output(1,0).val_);
  EXPECT_FLOAT_EQ( 40, output(1,1).val_);
  EXPECT_FLOAT_EQ( -2, output(1,2).val_);
  EXPECT_FLOAT_EQ( -1, output(0,0).d_);
  EXPECT_FLOAT_EQ( -1, output(0,1).d_);
  EXPECT_FLOAT_EQ( -1, output(0,2).d_);
  EXPECT_FLOAT_EQ( -1, output(1,0).d_);
  EXPECT_FLOAT_EQ( -1, output(1,1).d_);
  EXPECT_FLOAT_EQ( -1, output(1,2).d_);
}
TEST(AgradFwdFvarVarMatrix, minus_scalar) {
  using stan::math::minus;
  using stan::agrad::var;
  double x = 10;
  fvar<var> v = 11;
   v.d_ = 1.0;
  
  EXPECT_FLOAT_EQ(-10, minus(x));
  EXPECT_FLOAT_EQ(-11, minus(v).val_.val());
  EXPECT_FLOAT_EQ( -1, minus(v).d_.val());
}
TEST(AgradFwdFvarVarMatrix, minus_vector) {
  using stan::math::vector_d;
  using stan::agrad::vector_fvv;
  using stan::math::minus;

  vector_d d(3);
  vector_fvv v(3);

  d << -100, 0, 1;
  v << -100, 0, 1;
   v(0).d_ = 1.0;
   v(1).d_ = 1.0;
   v(2).d_ = 1.0;
  
  vector_d output_d;
  output_d = minus(d);
  EXPECT_FLOAT_EQ(100, output_d[0]);
  EXPECT_FLOAT_EQ(0, output_d[1]);
  EXPECT_FLOAT_EQ(-1, output_d[2]);

  vector_fvv output;
  output = minus(v);
  EXPECT_FLOAT_EQ(100, output[0].val_.val());
  EXPECT_FLOAT_EQ(0, output[1].val_.val());
  EXPECT_FLOAT_EQ(-1, output[2].val_.val());
  EXPECT_FLOAT_EQ(-1, output[0].d_.val());
  EXPECT_FLOAT_EQ(-1, output[1].d_.val());
  EXPECT_FLOAT_EQ(-1, output[2].d_.val());
}
TEST(AgradFwdFvarVarMatrix, minus_rowvector) {
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_fvv;
  using stan::math::minus;

  row_vector_d d(3);
  row_vector_fvv v(3);

  d << -100, 0, 1;
  v << -100, 0, 1;
   v(0).d_ = 1.0;
   v(1).d_ = 1.0;
   v(2).d_ = 1.0;
  
  row_vector_d output_d;
  output_d = minus(d);
  EXPECT_FLOAT_EQ(100, output_d[0]);
  EXPECT_FLOAT_EQ(0, output_d[1]);
  EXPECT_FLOAT_EQ(-1, output_d[2]);

  row_vector_fvv output;
  output = minus(v);
  EXPECT_FLOAT_EQ(100, output[0].val_.val());
  EXPECT_FLOAT_EQ(0, output[1].val_.val());
  EXPECT_FLOAT_EQ(-1, output[2].val_.val());
  EXPECT_FLOAT_EQ(-1, output[0].d_.val());
  EXPECT_FLOAT_EQ(-1, output[1].d_.val());
  EXPECT_FLOAT_EQ(-1, output[2].d_.val());
}
TEST(AgradFwdFvarVarMatrix, minus_matrix) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_fvv;
  using stan::math::minus;

  matrix_d d(2, 3);
  matrix_fvv v(2, 3);

  d << -100, 0, 1, 20, -40, 2;
  v << -100, 0, 1, 20, -40, 2;
   v(0,0).d_ = 1.0;
   v(0,1).d_ = 1.0;
   v(0,2).d_ = 1.0;
   v(1,0).d_ = 1.0;
   v(1,1).d_ = 1.0;
   v(1,2).d_ = 1.0;

  matrix_d output_d = minus(d);
  EXPECT_FLOAT_EQ(100, output_d(0,0));
  EXPECT_FLOAT_EQ(  0, output_d(0,1));
  EXPECT_FLOAT_EQ( -1, output_d(0,2));
  EXPECT_FLOAT_EQ(-20, output_d(1,0));
  EXPECT_FLOAT_EQ( 40, output_d(1,1));
  EXPECT_FLOAT_EQ( -2, output_d(1,2));

  matrix_fvv output = minus(v);
  EXPECT_FLOAT_EQ(100, output(0,0).val_.val());
  EXPECT_FLOAT_EQ(  0, output(0,1).val_.val());
  EXPECT_FLOAT_EQ( -1, output(0,2).val_.val());
  EXPECT_FLOAT_EQ(-20, output(1,0).val_.val());
  EXPECT_FLOAT_EQ( 40, output(1,1).val_.val());
  EXPECT_FLOAT_EQ( -2, output(1,2).val_.val());
  EXPECT_FLOAT_EQ( -1, output(0,0).d_.val());
  EXPECT_FLOAT_EQ( -1, output(0,1).d_.val());
  EXPECT_FLOAT_EQ( -1, output(0,2).d_.val());
  EXPECT_FLOAT_EQ( -1, output(1,0).d_.val());
  EXPECT_FLOAT_EQ( -1, output(1,1).d_.val());
  EXPECT_FLOAT_EQ( -1, output(1,2).d_.val());
}
TEST(AgradFwdFvarFvarMatrix, minus_scalar) {
  using stan::math::minus;
  double x = 10;
  fvar<fvar<double> > v = 11;
   v.d_ = 1.0;
  
  EXPECT_FLOAT_EQ(-10, minus(x));
  EXPECT_FLOAT_EQ(-11, minus(v).val_.val());
  EXPECT_FLOAT_EQ( -1, minus(v).d_.val());
}
TEST(AgradFwdFvarFvarMatrix, minus_vector) {
  using stan::math::vector_d;
  using stan::agrad::vector_ffv;
  using stan::math::minus;

  vector_d d(3);
  vector_ffv v(3);
  fvar<fvar<double> > a,b,c;
  a.val_.val_ = -100.0;
  b.val_.val_ = 0.0;
  c.val_.val_ = 1.0;
  a.d_.val_ = 1.0;
  b.d_.val_ = 1.0;
  c.d_.val_ = 1.0;

  d << -100, 0, 1;
  v << a,b,c;
  
  vector_d output_d;
  output_d = minus(d);
  EXPECT_FLOAT_EQ(100, output_d[0]);
  EXPECT_FLOAT_EQ(0, output_d[1]);
  EXPECT_FLOAT_EQ(-1, output_d[2]);

  vector_ffv output;
  output = minus(v);
  EXPECT_FLOAT_EQ(100, output[0].val_.val());
  EXPECT_FLOAT_EQ(0, output[1].val_.val());
  EXPECT_FLOAT_EQ(-1, output[2].val_.val());
  EXPECT_FLOAT_EQ(-1, output[0].d_.val());
  EXPECT_FLOAT_EQ(-1, output[1].d_.val());
  EXPECT_FLOAT_EQ(-1, output[2].d_.val());
}
TEST(AgradFwdFvarFvarMatrix, minus_rowvector) {
  using stan::math::row_vector_d;
  using stan::agrad::row_vector_ffv;
  using stan::math::minus;

  row_vector_d d(3);
  row_vector_ffv v(3);
  fvar<fvar<double> > a,b,c;
  a.val_.val_ = -100.0;
  b.val_.val_ = 0.0;
  c.val_.val_ = 1.0;
  a.d_.val_ = 1.0;
  b.d_.val_ = 1.0;
  c.d_.val_ = 1.0;

  d << -100, 0, 1;
  v << a,b,c;
  
  row_vector_d output_d;
  output_d = minus(d);
  EXPECT_FLOAT_EQ(100, output_d[0]);
  EXPECT_FLOAT_EQ(0, output_d[1]);
  EXPECT_FLOAT_EQ(-1, output_d[2]);

  row_vector_ffv output;
  output = minus(v);
  EXPECT_FLOAT_EQ(100, output[0].val_.val());
  EXPECT_FLOAT_EQ(0, output[1].val_.val());
  EXPECT_FLOAT_EQ(-1, output[2].val_.val());
  EXPECT_FLOAT_EQ(-1, output[0].d_.val());
  EXPECT_FLOAT_EQ(-1, output[1].d_.val());
  EXPECT_FLOAT_EQ(-1, output[2].d_.val());
}
TEST(AgradFwdFvarFvarMatrix, minus_matrix) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_ffv;
  using stan::math::minus;

  matrix_d dd(2, 3);
  matrix_ffv v(2, 3);
  fvar<fvar<double> > a,b,c,d,e,f;
  a.val_.val_ = -100.0;
  b.val_.val_ = 0.0;
  c.val_.val_ = 1.0;
  d.val_.val_ = 20.0;
  e.val_.val_ = -40.0;
  f.val_.val_ = 2.0;
  a.d_.val_ = 1.0;
  b.d_.val_ = 1.0;
  c.d_.val_ = 1.0;
  d.d_.val_ = 1.0;
  e.d_.val_ = 1.0;
  f.d_.val_ = 1.0;

  dd << -100, 0, 1, 20, -40, 2;
  v << a,b,c,d,e,f;

  matrix_d output_d = minus(dd);
  EXPECT_FLOAT_EQ(100, output_d(0,0));
  EXPECT_FLOAT_EQ(  0, output_d(0,1));
  EXPECT_FLOAT_EQ( -1, output_d(0,2));
  EXPECT_FLOAT_EQ(-20, output_d(1,0));
  EXPECT_FLOAT_EQ( 40, output_d(1,1));
  EXPECT_FLOAT_EQ( -2, output_d(1,2));

  matrix_ffv output = minus(v);
  EXPECT_FLOAT_EQ(100, output(0,0).val_.val());
  EXPECT_FLOAT_EQ(  0, output(0,1).val_.val());
  EXPECT_FLOAT_EQ( -1, output(0,2).val_.val());
  EXPECT_FLOAT_EQ(-20, output(1,0).val_.val());
  EXPECT_FLOAT_EQ( 40, output(1,1).val_.val());
  EXPECT_FLOAT_EQ( -2, output(1,2).val_.val());
  EXPECT_FLOAT_EQ( -1, output(0,0).d_.val());
  EXPECT_FLOAT_EQ( -1, output(0,1).d_.val());
  EXPECT_FLOAT_EQ( -1, output(0,2).d_.val());
  EXPECT_FLOAT_EQ( -1, output(1,0).d_.val());
  EXPECT_FLOAT_EQ( -1, output(1,1).d_.val());
  EXPECT_FLOAT_EQ( -1, output(1,2).d_.val());
}
