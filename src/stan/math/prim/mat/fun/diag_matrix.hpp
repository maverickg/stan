#ifndef STAN__MATH__PRIM__MAT__FUN__DIAG_MATRIX_HPP
#define STAN__MATH__PRIM__MAT__FUN__DIAG_MATRIX_HPP

#include <stan/math/prim/mat/fun/Eigen.hpp>

namespace stan {
  namespace math {

    /**
     * Return a square diagonal matrix with the specified vector of
     * coefficients as the diagonal values.
     * @param[in] v Specified vector.
     * @return Diagonal matrix with vector as diagonal values.
     */
    template <typename T>
    inline
    Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>
    diag_matrix(const Eigen::Matrix<T,Eigen::Dynamic,1>& v) {
      return v.asDiagonal();
    }

  }
}
#endif
