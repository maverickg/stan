#ifndef STAN__AGRAD__FWD__FUNCTIONS__EXP_HPP
#define STAN__AGRAD__FWD__FUNCTIONS__EXP_HPP

#include <stan/agrad/fwd/fvar.hpp>
#include <cmath>

namespace stan {

  namespace agrad {

    template <typename T>
    inline
    fvar<T> exp(const fvar<T>& x) {
      double exp_x = std::exp(x.val_);
      return fvar<T>(exp_x, x.d_ * exp_x);
    }

  }
}
#endif
