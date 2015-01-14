#ifndef STAN__AGRAD__FWD__FUNCTIONS__PHI_HPP
#define STAN__AGRAD__FWD__FUNCTIONS__PHI_HPP

#include <stan/agrad/fwd/fvar.hpp>
#include <stan/math/functions/Phi.hpp>
#include <stan/math/functions/square.hpp>
#include <stan/math/functions/constants.hpp>

namespace stan {

  namespace agrad {

    template <typename T>
    inline fvar<T> Phi(const fvar<T>& x) {
      using stan::math::Phi;
      using stan::math::square;
      using std::exp;
      using std::sqrt;
      T xv = x.val_;
      return fvar<T>(Phi(xv),
                     x.d_ * exp((-0.5) * square(xv)) * (1.0 / sqrt(2.0 * stan::math::pi())));
    }

  }

}

#endif
