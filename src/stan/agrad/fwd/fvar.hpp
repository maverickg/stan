#ifndef STAN__AGRAD__FWD__FVAR__HPP
#define STAN__AGRAD__FWD__FVAR__HPP

#include <ostream>
#include <boost/math/special_functions/fpclassify.hpp>
#include <stan/meta/likely.hpp>

namespace stan {

  namespace agrad {

    template <typename T>
    struct fvar {

      double val_; 
      T d_;   

      double val() { 
        return val_; 
      }

      T tangent() { 
        return d_; 
      }

      typedef fvar value_type;

      fvar(double val, const T& d) 
        : val_(val), 
          d_(d) 
      {  } 

      fvar(double val) 
      : val_(val), 
        d_(0.0)
      {  }
      
      fvar() 
        : val_(0.0), 
          d_(0.0)
      { }

      inline
      fvar<T>& operator+=(const fvar<T>& x2) {
        val_ += x2.val_;
        d_ += x2.d_;
        return *this;
      }
      inline
      fvar<T>& operator+=(double x2) {
        val_ += x2;
        return *this;
      }

      inline
      fvar<T>& operator-=(const fvar<T>& x2) {
        val_ -= x2.val_;
        d_ -= x2.d_;
        return *this;
      }
      inline
      fvar<T>& operator-=(double x2) {
        val_ -= x2;
        return *this;
      }

      inline
      fvar<T>& operator*=(const fvar<T>& x2) {
        d_ = d_ * x2.val_ + val_ * x2.d_;
        val_ *= x2.val_;
        return *this;
      }
      inline
      fvar<T>& operator*=(double x2) {
        val_ *= x2;
        d_ *= x2;
        return *this;
      }

      // SPEEDUP: specialize for T2 == var with d_ function

      inline
      fvar<T>& operator/=(const fvar<T>& x2) {
        d_ = (d_ * x2.val_ - val_ * x2.d_) / ( x2.val_ * x2.val_);
        val_ /= x2.val_;
        return *this;
      }
      inline
      fvar<T>&
      operator/=(double x2) {
        val_ /= x2;
        d_ /= x2;
        return *this;
      }

      inline
      fvar<T>&
      operator++() {
        ++val_;
        return *this;
      }

      inline
      fvar<T> operator++(int /*dummy*/) {
        fvar<T> result(val_,d_);
        ++val_;
        return result;
      }

      inline
      fvar<T>& operator--() {
        --val_;
        return *this;
      }

      inline
      fvar<T> operator--(int /*dummy*/) {
        fvar<T> result(val_,d_);
        --val_;
        return result;
      }

      friend
      std::ostream& operator<<(std::ostream& os, const fvar<T>& v) {
         return os << v.val_ << ':' << v.d_;
      }
    };
  }
}
#endif
