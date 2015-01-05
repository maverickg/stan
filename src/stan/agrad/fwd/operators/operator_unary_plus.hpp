#ifndef STAN__AGRAD__FWD__OPERATORS__OPERATOR_UNARY_PLUS_HPP
#define STAN__AGRAD__FWD__OPERATORS__OPERATOR_UNARY_PLUS_HPP

#include <stan/agrad/fwd/fvar.hpp>

namespace stan {

  namespace agrad {

    template <typename T>
    inline 
    fvar<T>
    operator+(const fvar<T>& x) {
      return x;
    }

  }

}

#endif
