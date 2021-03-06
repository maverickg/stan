#ifndef STAN__MATH__PRIM__MAT__ERR__CONSTRAINT_TOLERANCE_HPP
#define STAN__MATH__PRIM__MAT__ERR__CONSTRAINT_TOLERANCE_HPP

namespace stan {
  namespace math {

    /**
     * The tolerance for checking arithmetic bounds In rank and in
     * simplexes.  The default value is <code>1E-8</code>.
     */
    const double CONSTRAINT_TOLERANCE = 1E-8;

  }
}
#endif
