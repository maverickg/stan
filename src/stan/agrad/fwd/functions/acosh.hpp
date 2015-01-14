#ifndef STAN__AGRAD__FWD__FUNCTIONS__ACOSH_HPP
#define STAN__AGRAD__FWD__FUNCTIONS__ACOSH_HPP

#include <cmath>
#include <stan/agrad/fwd/fvar.hpp>
#include <stan/math/functions/square.hpp>

namespace stan {

  namespace agrad {

    template <typename T>
    inline
    fvar<T>
    acosh(const fvar<T>& x) {
      using std::acosh;
      using std::sqrt;
      using stan::math::square;
      return fvar<T>(acosh(x.val_),
                     x.d_ / sqrt(square(x.val_) - 1));
    }

  }

}

#endif
