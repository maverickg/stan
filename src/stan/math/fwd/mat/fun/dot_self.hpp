#ifndef STAN__MATH__FWD__MAT__FUN__DOT_SELF_HPP
#define STAN__MATH__FWD__MAT__FUN__DOT_SELF_HPP

#include <vector>
#include <stan/math/prim/mat/fun/Eigen.hpp>
#include <stan/math/prim/mat/fun/typedefs.hpp>
#include <stan/math/prim/mat/err/check_vector.hpp>
#include <stan/math/fwd/core.hpp>
#include <stan/math/fwd/mat/fun/dot_product.hpp>

namespace stan {
  namespace agrad {

    template<typename T, int R, int C>
    inline fvar<T>
    dot_self(const Eigen::Matrix<fvar<T>, R, C>& v) {
      stan::math::check_vector("dot_self",
                                         "v", v);
      return dot_product(v, v);
    }
  }
}
#endif
