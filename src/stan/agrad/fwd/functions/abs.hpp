#ifndef STAN__AGRAD__FWD__FUNCTIONS__ABS_HPP
#define STAN__AGRAD__FWD__FUNCTIONS__ABS_HPP

#include <stan/agrad/fwd/fvar.hpp>
#include <stan/math/functions/abs.hpp>
#include <stan/math/functions/constants.hpp>

namespace stan {

  namespace agrad {

    /**
     * zeroes derivative if input has zero value
     */
    template <typename T>
    inline
    fvar<T>
    abs(const fvar<T>& x) {
      using stan::math::abs;
      if (x.val_ > 0.0)
        return x;
      else if (x.val_ == 0.0)
        return fvar<T>(0,0); // zeroes derivative here
      else if (x.val_ < 0.0)
        return fvar<T>(-x.val_, -x.d_);
      else // x.val_ is nan
        return fvar<T>(stan::math::NOT_A_NUMBER,
                       stan::math::NOT_A_NUMBER);
    }

  }

}

#endif
