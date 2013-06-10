#include <stan/agrad/fwd/matrix/mdivide_right_tri_low.hpp>
#include <gtest/gtest.h>
#include <stan/agrad/fwd/matrix/typedefs.hpp>
#include <stan/agrad/var.hpp>
#include <stan/agrad/rev/matrix/multiply.hpp>

using stan::agrad::fvar;
TEST(AgradFwdMatrix, mdivide_right_tri_low_rowvector_fv_matrix_fv) {
  using stan::agrad::matrix_fv;
  using stan::agrad::row_vector_fv;

  matrix_fv Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;
   Y(0,0).d_ = 2.0;
   Y(0,1).d_ = 2.0;
   Y(0,2).d_ = 2.0;
   Y(1,0).d_ = 2.0;
   Y(1,1).d_ = 2.0;
   Y(1,2).d_ = 2.0;
   Y(2,0).d_ = 2.0;
   Y(2,1).d_ = 2.0;
   Y(2,2).d_ = 2.0;

   row_vector_fv Z(3);
   Z << 1, 2, 3;
    Z(0).d_ = 2.0;
    Z(1).d_ = 2.0;
    Z(2).d_ = 2.0;

  matrix_fv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_);
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_);
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_);
  EXPECT_FLOAT_EQ(5.0 / 3.0,output(0,0).d_);
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,1).d_);
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,2).d_);
}
TEST(AgradFwdMatrix, mdivide_right_tri_low_rowvector_matrix_fv) {
  using stan::agrad::matrix_fv;
  using stan::math::row_vector_d;

  matrix_fv Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;
   Y(0,0).d_ = 2.0;
   Y(0,1).d_ = 2.0;
   Y(0,2).d_ = 2.0;
   Y(1,0).d_ = 2.0;
   Y(1,1).d_ = 2.0;
   Y(1,2).d_ = 2.0;
   Y(2,0).d_ = 2.0;
   Y(2,1).d_ = 2.0;
   Y(2,2).d_ = 2.0;

   row_vector_d Z(3);
   Z << 1, 2, 3;

  matrix_fv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_);
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_);
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_);
  EXPECT_FLOAT_EQ(11.0 / 9.0,output(0,0).d_);
  EXPECT_FLOAT_EQ(5.0 / 90.0,output(0,1).d_);
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,2).d_);
}
TEST(AgradFwdMatrix, mdivide_right_tri_low_rowvector_fv_matrix) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_fv;
  using stan::agrad::row_vector_fv;

  matrix_d Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;

  row_vector_fv Z(3);
  Z << 1, 2, 3;
   Z(0).d_ = 2.0;
   Z(1).d_ = 2.0;
   Z(2).d_ = 2.0;

  matrix_fv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_);
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_);
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_);
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(0,0).d_);
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(0,1).d_);
  EXPECT_FLOAT_EQ(3.0 / 9.0,output(0,2).d_);
}
TEST(AgradFwdMatrix, mdivide_right_tri_low_matrix_fv_matrix_fv) {
  using stan::agrad::matrix_fv;
  using stan::agrad::row_vector_fv;

  matrix_fv Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;
   Y(0,0).d_ = 2.0;
   Y(0,1).d_ = 2.0;
   Y(0,2).d_ = 2.0;
   Y(1,0).d_ = 2.0;
   Y(1,1).d_ = 2.0;
   Y(1,2).d_ = 2.0;
   Y(2,0).d_ = 2.0;
   Y(2,1).d_ = 2.0;
   Y(2,2).d_ = 2.0;

  matrix_fv Z(3,3);
  Z << 1, 2, 3,
    6, 5, 4,
    7, 8, 9;
   Z(0,0).d_ = 2.0;
   Z(0,1).d_ = 2.0;
   Z(0,2).d_ = 2.0;
   Z(1,0).d_ = 2.0;
   Z(1,1).d_ = 2.0;
   Z(1,2).d_ = 2.0;
   Z(2,0).d_ = 2.0;
   Z(2,1).d_ = 2.0;
   Z(2,2).d_ = 2.0;

  matrix_fv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_);
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_);
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_);
  EXPECT_FLOAT_EQ(20.0 / 9.0,output(1,0).val_);
  EXPECT_FLOAT_EQ(5.0 / 9.0,output(1,1).val_);
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(1,2).val_);
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(2,0).val_);
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(2,1).val_);
  EXPECT_FLOAT_EQ(1.5,output(2,2).val_);
  EXPECT_FLOAT_EQ(15.0 / 9.0,output(0,0).d_);
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,1).d_);
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,2).d_);
  EXPECT_FLOAT_EQ(-14.0 / 3.0,output(1,0).d_);
  EXPECT_FLOAT_EQ(-3.0 / 9.0,output(1,1).d_);
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(1,2).d_);
  EXPECT_FLOAT_EQ(-5.0 / 3.0,output(2,0).d_);
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(2,1).d_);
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(2,2).d_);
}
TEST(AgradFwdMatrix, mdivide_right_tri_low_matrix_fv_matrix) {
  using stan::agrad::matrix_fv;
  using stan::math::matrix_d;
  using stan::agrad::row_vector_fv;

  matrix_d Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;

  matrix_fv Z(3,3);
  Z << 1, 2, 3,
    6, 5, 4,
    7, 8, 9;
   Z(0,0).d_ = 2.0;
   Z(0,1).d_ = 2.0;
   Z(0,2).d_ = 2.0;
   Z(1,0).d_ = 2.0;
   Z(1,1).d_ = 2.0;
   Z(1,2).d_ = 2.0;
   Z(2,0).d_ = 2.0;
   Z(2,1).d_ = 2.0;
   Z(2,2).d_ = 2.0;

  matrix_fv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_);
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_);
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_);
  EXPECT_FLOAT_EQ(20.0 / 9.0,output(1,0).val_);
  EXPECT_FLOAT_EQ(5.0 / 9.0,output(1,1).val_);
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(1,2).val_);
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(2,0).val_);
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(2,1).val_);
  EXPECT_FLOAT_EQ(1.5,output(2,2).val_);
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(0,0).d_);
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(0,1).d_);
  EXPECT_FLOAT_EQ(2.0 / 6.0,output(0,2).d_);
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(1,0).d_);
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(1,1).d_);
  EXPECT_FLOAT_EQ(3.0 / 9.0,output(1,2).d_);
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(2,0).d_);
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(2,1).d_);
  EXPECT_FLOAT_EQ(2.0 / 6.0,output(2,2).d_);
}
TEST(AgradFwdMatrix, mdivide_right_tri_low_matrix_matrix_fv) {
  using stan::agrad::matrix_fv;
  using stan::math::matrix_d;
  using stan::agrad::row_vector_fv;

  matrix_fv Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;
   Y(0,0).d_ = 2.0;
   Y(0,1).d_ = 2.0;
   Y(0,2).d_ = 2.0;
   Y(1,0).d_ = 2.0;
   Y(1,1).d_ = 2.0;
   Y(1,2).d_ = 2.0;
   Y(2,0).d_ = 2.0;
   Y(2,1).d_ = 2.0;
   Y(2,2).d_ = 2.0;

  matrix_d Z(3,3);
  Z << 1, 2, 3,
    6, 5, 4,
    7, 8, 9;

  matrix_fv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_);
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_);
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_);
  EXPECT_FLOAT_EQ(20.0 / 9.0,output(1,0).val_);
  EXPECT_FLOAT_EQ(5.0 / 9.0,output(1,1).val_);
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(1,2).val_);
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(2,0).val_);
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(2,1).val_);
  EXPECT_FLOAT_EQ(1.5,output(2,2).val_);
  EXPECT_FLOAT_EQ(11.0 / 9.0,output(0,0).d_);
  EXPECT_FLOAT_EQ(5.0 / 90.0,output(0,1).d_);
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,2).d_);
  EXPECT_FLOAT_EQ(-46.0 / 9.0,output(1,0).d_);
  EXPECT_FLOAT_EQ(-4.0 / 9.0,output(1,1).d_);
  EXPECT_FLOAT_EQ(-2.0 / 9.0,output(1,2).d_);
  EXPECT_FLOAT_EQ(-19.0 / 9.0,output(2,0).d_);
  EXPECT_FLOAT_EQ(-25.0 / 90.0,output(2,1).d_);
  EXPECT_FLOAT_EQ(-3.0 / 6.0,output(2,2).d_);
}
TEST(AgradFwdMatrix, mdivide_right_tri_low_rowvector_matrix_exceptions) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_fv;
  using stan::agrad::row_vector_fv;
  using stan::math::row_vector_d;
  using stan::agrad::mdivide_right_tri_low;

  row_vector_fv fv1(4), fv2(3);
  row_vector_d v1(4), v2(3);
  matrix_fv fvm1(4,4), fvm2(3,3);
  matrix_d vm1(4,4), vm2(3,3);

  EXPECT_THROW(mdivide_right_tri_low(fv1,fvm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fv1,vm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(v1,fvm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fv2,fvm1), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fv2,vm1), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(v2,fvm1), std::domain_error);
}
TEST(AgradFwdMatrix, mdivide_right_tri_low_matrix_matrix_exceptions) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_fv;
  using stan::agrad::mdivide_right_tri_low;

  matrix_fv fvm1(4,4), fvm2(3,3);
  matrix_d vm1(4,4), vm2(3,3);

  EXPECT_THROW(mdivide_right_tri_low(fvm1,fvm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fvm1,vm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(vm1,fvm2), std::domain_error);
}
TEST(AgradFwdFvarVarMatrix, mdivide_right_tri_low_rowvector_fvv_matrix_fvv) {
  using stan::agrad::matrix_fvv;
  using stan::agrad::row_vector_fvv;

  matrix_fvv Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;
   Y(0,0).d_ = 2.0;
   Y(0,1).d_ = 2.0;
   Y(0,2).d_ = 2.0;
   Y(1,0).d_ = 2.0;
   Y(1,1).d_ = 2.0;
   Y(1,2).d_ = 2.0;
   Y(2,0).d_ = 2.0;
   Y(2,1).d_ = 2.0;
   Y(2,2).d_ = 2.0;

   row_vector_fvv Z(3);
   Z << 1, 2, 3;
    Z(0).d_ = 2.0;
    Z(1).d_ = 2.0;
    Z(2).d_ = 2.0;

  matrix_fvv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(5.0 / 3.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,2).d_.val());
}
TEST(AgradFwdFvarVarMatrix, mdivide_right_tri_low_rowvector_matrix_fvv) {
  using stan::agrad::matrix_fvv;
  using stan::math::row_vector_d;

  matrix_fvv Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;
   Y(0,0).d_ = 2.0;
   Y(0,1).d_ = 2.0;
   Y(0,2).d_ = 2.0;
   Y(1,0).d_ = 2.0;
   Y(1,1).d_ = 2.0;
   Y(1,2).d_ = 2.0;
   Y(2,0).d_ = 2.0;
   Y(2,1).d_ = 2.0;
   Y(2,2).d_ = 2.0;

   row_vector_d Z(3);
   Z << 1, 2, 3;

  matrix_fvv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(11.0 / 9.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(5.0 / 90.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,2).d_.val());
}
TEST(AgradFwdFvarVarMatrix, mdivide_right_tri_low_rowvector_fvv_matrix) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_fvv;
  using stan::agrad::row_vector_fvv;

  matrix_d Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;

  row_vector_fvv Z(3);
  Z << 1, 2, 3;
   Z(0).d_ = 2.0;
   Z(1).d_ = 2.0;
   Z(2).d_ = 2.0;

  matrix_fvv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(3.0 / 9.0,output(0,2).d_.val());
}
TEST(AgradFwdFvarVarMatrix, mdivide_right_tri_low_matrix_fvv_matrix_fvv) {
  using stan::agrad::matrix_fvv;
  using stan::agrad::row_vector_fvv;

  matrix_fvv Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;
   Y(0,0).d_ = 2.0;
   Y(0,1).d_ = 2.0;
   Y(0,2).d_ = 2.0;
   Y(1,0).d_ = 2.0;
   Y(1,1).d_ = 2.0;
   Y(1,2).d_ = 2.0;
   Y(2,0).d_ = 2.0;
   Y(2,1).d_ = 2.0;
   Y(2,2).d_ = 2.0;

  matrix_fvv Z(3,3);
  Z << 1, 2, 3,
    6, 5, 4,
    7, 8, 9;
   Z(0,0).d_ = 2.0;
   Z(0,1).d_ = 2.0;
   Z(0,2).d_ = 2.0;
   Z(1,0).d_ = 2.0;
   Z(1,1).d_ = 2.0;
   Z(1,2).d_ = 2.0;
   Z(2,0).d_ = 2.0;
   Z(2,1).d_ = 2.0;
   Z(2,2).d_ = 2.0;

  matrix_fvv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(20.0 / 9.0,output(1,0).val_.val());
  EXPECT_FLOAT_EQ(5.0 / 9.0,output(1,1).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(1,2).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(2,0).val_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(2,1).val_.val());
  EXPECT_FLOAT_EQ(1.5,output(2,2).val_.val());
  EXPECT_FLOAT_EQ(15.0 / 9.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,2).d_.val());
  EXPECT_FLOAT_EQ(-14.0 / 3.0,output(1,0).d_.val());
  EXPECT_FLOAT_EQ(-3.0 / 9.0,output(1,1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(1,2).d_.val());
  EXPECT_FLOAT_EQ(-5.0 / 3.0,output(2,0).d_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(2,1).d_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(2,2).d_.val());
}
TEST(AgradFwdFvarVarMatrix, mdivide_right_tri_low_matrix_fvv_matrix) {
  using stan::agrad::matrix_fvv;
  using stan::math::matrix_d;
  using stan::agrad::row_vector_fvv;

  matrix_d Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;

  matrix_fvv Z(3,3);
  Z << 1, 2, 3,
    6, 5, 4,
    7, 8, 9;
   Z(0,0).d_ = 2.0;
   Z(0,1).d_ = 2.0;
   Z(0,2).d_ = 2.0;
   Z(1,0).d_ = 2.0;
   Z(1,1).d_ = 2.0;
   Z(1,2).d_ = 2.0;
   Z(2,0).d_ = 2.0;
   Z(2,1).d_ = 2.0;
   Z(2,2).d_ = 2.0;

  matrix_fvv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(20.0 / 9.0,output(1,0).val_.val());
  EXPECT_FLOAT_EQ(5.0 / 9.0,output(1,1).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(1,2).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(2,0).val_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(2,1).val_.val());
  EXPECT_FLOAT_EQ(1.5,output(2,2).val_.val());
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(2.0 / 6.0,output(0,2).d_.val());
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(1,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(1,1).d_.val());
  EXPECT_FLOAT_EQ(3.0 / 9.0,output(1,2).d_.val());
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(2,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(2,1).d_.val());
  EXPECT_FLOAT_EQ(2.0 / 6.0,output(2,2).d_.val());
}
TEST(AgradFwdFvarVarMatrix, mdivide_right_tri_low_matrix_matrix_fvv) {
  using stan::agrad::matrix_fvv;
  using stan::math::matrix_d;
  using stan::agrad::row_vector_fvv;

  matrix_fvv Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;
   Y(0,0).d_ = 2.0;
   Y(0,1).d_ = 2.0;
   Y(0,2).d_ = 2.0;
   Y(1,0).d_ = 2.0;
   Y(1,1).d_ = 2.0;
   Y(1,2).d_ = 2.0;
   Y(2,0).d_ = 2.0;
   Y(2,1).d_ = 2.0;
   Y(2,2).d_ = 2.0;

  matrix_d Z(3,3);
  Z << 1, 2, 3,
    6, 5, 4,
    7, 8, 9;

  matrix_fvv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(20.0 / 9.0,output(1,0).val_.val());
  EXPECT_FLOAT_EQ(5.0 / 9.0,output(1,1).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(1,2).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(2,0).val_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(2,1).val_.val());
  EXPECT_FLOAT_EQ(1.5,output(2,2).val_.val());
  EXPECT_FLOAT_EQ(11.0 / 9.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(5.0 / 90.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,2).d_.val());
  EXPECT_FLOAT_EQ(-46.0 / 9.0,output(1,0).d_.val());
  EXPECT_FLOAT_EQ(-4.0 / 9.0,output(1,1).d_.val());
  EXPECT_FLOAT_EQ(-2.0 / 9.0,output(1,2).d_.val());
  EXPECT_FLOAT_EQ(-19.0 / 9.0,output(2,0).d_.val());
  EXPECT_FLOAT_EQ(-25.0 / 90.0,output(2,1).d_.val());
  EXPECT_FLOAT_EQ(-3.0 / 6.0,output(2,2).d_.val());
}
TEST(AgradFwdFvarVarMatrix, mdivide_right_tri_low_rowvector_matrix_exceptions) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_fvv;
  using stan::agrad::row_vector_fvv;
  using stan::math::row_vector_d;
  using stan::agrad::mdivide_right_tri_low;

  row_vector_fvv fv1(4), fv2(3);
  row_vector_d v1(4), v2(3);
  matrix_fvv fvm1(4,4), fvm2(3,3);
  matrix_d vm1(4,4), vm2(3,3);

  EXPECT_THROW(mdivide_right_tri_low(fv1,fvm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fv1,vm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(v1,fvm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fv2,fvm1), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fv2,vm1), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(v2,fvm1), std::domain_error);
}
TEST(AgradFwdFvarVarMatrix, mdivide_right_tri_low_matrix_matrix_exceptions) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_fvv;
  using stan::agrad::mdivide_right_tri_low;

  matrix_fvv fvm1(4,4), fvm2(3,3);
  matrix_d vm1(4,4), vm2(3,3);

  EXPECT_THROW(mdivide_right_tri_low(fvm1,fvm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fvm1,vm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(vm1,fvm2), std::domain_error);
}
TEST(AgradFwdFvarFvarMatrix, mdivide_right_tri_low_rowvector_ffv_matrix_ffv) {
  using stan::agrad::matrix_ffv;
  using stan::agrad::row_vector_ffv;

  fvar<fvar<double> > a,b,c,d,e,f,g;

  a.val_.val_ = 1.0;
  b.val_.val_ = 2.0;
  c.val_.val_ = 3.0;
  d.val_.val_ = 4.0;
  e.val_.val_ = 5.0;
  f.val_.val_ = 6.0;
  g.val_.val_ = 0.0;
  a.d_.val_ = 2.0;
  b.d_.val_ = 2.0;
  c.d_.val_ = 2.0;
  d.d_.val_ = 2.0;
  e.d_.val_ = 2.0;
  f.d_.val_ = 2.0;
  g.d_.val_ = 2.0;

  matrix_ffv Y(3,3);
  Y << a,g,g,b,c,g,d,e,f;

   row_vector_ffv Z(3);
   Z <<a,b,c;

  matrix_ffv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(5.0 / 3.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,2).d_.val());
}
TEST(AgradFwdFvarFvarMatrix, mdivide_right_tri_low_rowvector_matrix_ffv) {
  using stan::agrad::matrix_ffv;
  using stan::math::row_vector_d;

  fvar<fvar<double> > a,b,c,d,e,f,g;

  a.val_.val_ = 1.0;
  b.val_.val_ = 2.0;
  c.val_.val_ = 3.0;
  d.val_.val_ = 4.0;
  e.val_.val_ = 5.0;
  f.val_.val_ = 6.0;
  g.val_.val_ = 0.0;
  a.d_.val_ = 2.0;
  b.d_.val_ = 2.0;
  c.d_.val_ = 2.0;
  d.d_.val_ = 2.0;
  e.d_.val_ = 2.0;
  f.d_.val_ = 2.0;
  g.d_.val_ = 2.0;

  matrix_ffv Y(3,3);
  Y << a,g,g,b,c,g,d,e,f;

   row_vector_d Z(3);
   Z << 1, 2, 3;

  matrix_ffv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(11.0 / 9.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(5.0 / 90.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,2).d_.val());
}
TEST(AgradFwdFvarFvarMatrix, mdivide_right_tri_low_rowvector_ffv_matrix) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_ffv;
  using stan::agrad::row_vector_ffv;

  matrix_d Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;


  fvar<fvar<double> > a,b,c;

  a.val_.val_ = 1.0;
  b.val_.val_ = 2.0;
  c.val_.val_ = 3.0;
  a.d_.val_ = 2.0;
  b.d_.val_ = 2.0;
  c.d_.val_ = 2.0;

  row_vector_ffv Z(3);
  Z << a,b,c;

  matrix_ffv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(3.0 / 9.0,output(0,2).d_.val());
}
TEST(AgradFwdFvarFvarMatrix, mdivide_right_tri_low_matrix_ffv_matrix_ffv) {
  using stan::agrad::matrix_ffv;
  using stan::agrad::row_vector_ffv;

  fvar<fvar<double> > a,b,c,d,e,f,g,h,i,j;

  a.val_.val_ = 1.0;
  b.val_.val_ = 2.0;
  c.val_.val_ = 3.0;
  d.val_.val_ = 4.0;
  e.val_.val_ = 5.0;
  f.val_.val_ = 6.0;
  h.val_.val_ = 7.0;
  i.val_.val_ = 8.0;
  j.val_.val_ = 9.0;
  g.val_.val_ = 0.0;
  a.d_.val_ = 2.0;
  b.d_.val_ = 2.0;
  c.d_.val_ = 2.0;
  d.d_.val_ = 2.0;
  e.d_.val_ = 2.0;
  f.d_.val_ = 2.0;
  g.d_.val_ = 2.0;
  h.d_.val_ = 2.0;
  i.d_.val_ = 2.0;
  j.d_.val_ = 2.0;

  matrix_ffv Y(3,3);
  Y << a,g,g,b,c,g,d,e,f;

  matrix_ffv Z(3,3);
  Z << a,b,c,f,e,d,h,i,j;

  matrix_ffv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(20.0 / 9.0,output(1,0).val_.val());
  EXPECT_FLOAT_EQ(5.0 / 9.0,output(1,1).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(1,2).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(2,0).val_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(2,1).val_.val());
  EXPECT_FLOAT_EQ(1.5,output(2,2).val_.val());
  EXPECT_FLOAT_EQ(15.0 / 9.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(0,2).d_.val());
  EXPECT_FLOAT_EQ(-14.0 / 3.0,output(1,0).d_.val());
  EXPECT_FLOAT_EQ(-3.0 / 9.0,output(1,1).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(1,2).d_.val());
  EXPECT_FLOAT_EQ(-5.0 / 3.0,output(2,0).d_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(2,1).d_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(2,2).d_.val());
}
TEST(AgradFwdFvarFvarMatrix, mdivide_right_tri_low_matrix_ffv_matrix) {
  using stan::agrad::matrix_ffv;
  using stan::math::matrix_d;
  using stan::agrad::row_vector_ffv;

  fvar<fvar<double> > a,b,c,d,e,f,g,h,i,j;

  a.val_.val_ = 1.0;
  b.val_.val_ = 2.0;
  c.val_.val_ = 3.0;
  d.val_.val_ = 4.0;
  e.val_.val_ = 5.0;
  f.val_.val_ = 6.0;
  h.val_.val_ = 7.0;
  i.val_.val_ = 8.0;
  j.val_.val_ = 9.0;
  g.val_.val_ = 0.0;
  a.d_.val_ = 2.0;
  b.d_.val_ = 2.0;
  c.d_.val_ = 2.0;
  d.d_.val_ = 2.0;
  e.d_.val_ = 2.0;
  f.d_.val_ = 2.0;
  g.d_.val_ = 2.0;
  h.d_.val_ = 2.0;
  i.d_.val_ = 2.0;
  j.d_.val_ = 2.0;

  matrix_d Y(3,3);
  Y << 1, 0, 0,
    2, 3, 0,
    4, 5, 6;

  matrix_ffv Z(3,3);
  Z << a,b,c,f,e,d,h,i,j;

  matrix_ffv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(20.0 / 9.0,output(1,0).val_.val());
  EXPECT_FLOAT_EQ(5.0 / 9.0,output(1,1).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(1,2).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(2,0).val_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(2,1).val_.val());
  EXPECT_FLOAT_EQ(1.5,output(2,2).val_.val());
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(2.0 / 6.0,output(0,2).d_.val());
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(1,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(1,1).d_.val());
  EXPECT_FLOAT_EQ(3.0 / 9.0,output(1,2).d_.val());
  EXPECT_FLOAT_EQ(4.0 / 9.0,output(2,0).d_.val());
  EXPECT_FLOAT_EQ(1.0 / 9.0,output(2,1).d_.val());
  EXPECT_FLOAT_EQ(2.0 / 6.0,output(2,2).d_.val());
}
TEST(AgradFwdFvarFvarMatrix, mdivide_right_tri_low_matrix_matrix_ffv) {
  using stan::agrad::matrix_ffv;
  using stan::math::matrix_d;
  using stan::agrad::row_vector_ffv;

  fvar<fvar<double> > a,b,c,d,e,f,g;

  a.val_.val_ = 1.0;
  b.val_.val_ = 2.0;
  c.val_.val_ = 3.0;
  d.val_.val_ = 4.0;
  e.val_.val_ = 5.0;
  f.val_.val_ = 6.0;
  g.val_.val_ = 0.0;
  a.d_.val_ = 2.0;
  b.d_.val_ = 2.0;
  c.d_.val_ = 2.0;
  d.d_.val_ = 2.0;
  e.d_.val_ = 2.0;
  f.d_.val_ = 2.0;
  g.d_.val_ = 2.0;

  matrix_ffv Y(3,3);
  Y << a,g,g,b,c,g,d,e,f;

  matrix_d Z(3,3);
  Z << 1, 2, 3,
    6, 5, 4,
    7, 8, 9;

  matrix_ffv output = stan::agrad::mdivide_right_tri_low(Z,Y);

  EXPECT_FLOAT_EQ(-2.0 / 3.0,output(0,0).val_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,1).val_.val());
  EXPECT_FLOAT_EQ(0.5,output(0,2).val_.val());
  EXPECT_FLOAT_EQ(20.0 / 9.0,output(1,0).val_.val());
  EXPECT_FLOAT_EQ(5.0 / 9.0,output(1,1).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(1,2).val_.val());
  EXPECT_FLOAT_EQ(6.0 / 9.0,output(2,0).val_.val());
  EXPECT_FLOAT_EQ(1.0 / 6.0,output(2,1).val_.val());
  EXPECT_FLOAT_EQ(1.5,output(2,2).val_.val());
  EXPECT_FLOAT_EQ(11.0 / 9.0,output(0,0).d_.val());
  EXPECT_FLOAT_EQ(5.0 / 90.0,output(0,1).d_.val());
  EXPECT_FLOAT_EQ(-1.0 / 6.0,output(0,2).d_.val());
  EXPECT_FLOAT_EQ(-46.0 / 9.0,output(1,0).d_.val());
  EXPECT_FLOAT_EQ(-4.0 / 9.0,output(1,1).d_.val());
  EXPECT_FLOAT_EQ(-2.0 / 9.0,output(1,2).d_.val());
  EXPECT_FLOAT_EQ(-19.0 / 9.0,output(2,0).d_.val());
  EXPECT_FLOAT_EQ(-25.0 / 90.0,output(2,1).d_.val());
  EXPECT_FLOAT_EQ(-3.0 / 6.0,output(2,2).d_.val());
}
TEST(AgradFwdFvarFvarMatrix, mdivide_right_tri_low_rowvector_matrix_exceptions) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_ffv;
  using stan::agrad::row_vector_ffv;
  using stan::math::row_vector_d;
  using stan::agrad::mdivide_right_tri_low;

  row_vector_ffv fv1(4), fv2(3);
  row_vector_d v1(4), v2(3);
  matrix_ffv fvm1(4,4), fvm2(3,3);
  matrix_d vm1(4,4), vm2(3,3);

  EXPECT_THROW(mdivide_right_tri_low(fv1,fvm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fv1,vm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(v1,fvm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fv2,fvm1), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fv2,vm1), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(v2,fvm1), std::domain_error);
}
TEST(AgradFwdFvarFvarMatrix, mdivide_right_tri_low_matrix_matrix_exceptions) {
  using stan::math::matrix_d;
  using stan::agrad::matrix_ffv;
  using stan::agrad::mdivide_right_tri_low;

  matrix_ffv fvm1(4,4), fvm2(3,3);
  matrix_d vm1(4,4), vm2(3,3);

  EXPECT_THROW(mdivide_right_tri_low(fvm1,fvm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(fvm1,vm2), std::domain_error);
  EXPECT_THROW(mdivide_right_tri_low(vm1,fvm2), std::domain_error);
}
