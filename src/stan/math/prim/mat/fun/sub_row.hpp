#ifndef STAN__MATH__PRIM__MAT__FUN__SUB_ROW_HPP
#define STAN__MATH__PRIM__MAT__FUN__SUB_ROW_HPP

#include <stan/math/prim/mat/fun/Eigen.hpp>
#include <stan/math/prim/mat/err/check_row_index.hpp>
#include <stan/math/prim/mat/err/check_column_index.hpp>

namespace stan {

  namespace math {

    /**
     * Return a 1 x nrows subrow starting at (i-1,j-1).
     *
     * @param m Matrix
     * @param i Starting row + 1
     * @param j Starting column + 1
     * @param ncols Number of columns in block
     **/
    template <typename T>
    inline
    Eigen::Matrix<T,1,Eigen::Dynamic>
    sub_row(const Eigen::Matrix<T,Eigen::Dynamic,Eigen::Dynamic>& m,
               size_t i, size_t j, size_t ncols) {
      stan::math::check_row_index("sub_row", "i", m, i);
      stan::math::check_column_index("sub_row", "j", m, j);
      if (ncols > 0)
        stan::math::check_column_index("sub_col", "j+ncols-1", m, j+ncols-1);
      return m.block(i - 1,j - 1,1,ncols);
    }

  }
}

#endif
