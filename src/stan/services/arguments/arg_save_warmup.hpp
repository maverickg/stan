#ifndef STAN__SERVICES__ARGUMENTS__OUTPUT__SAVE__WARMUP__HPP
#define STAN__SERVICES__ARGUMENTS__OUTPUT__SAVE__WARMUP__HPP

#include <stan/services/arguments/singleton_argument.hpp>

namespace stan {
  
  namespace services {
    
    class arg_save_warmup: public bool_argument {
      
    public:
      
      arg_save_warmup(): bool_argument() {
        _name = "save_warmup";
        _description = "Stream warmup samples to output?";
        _validity = "[0, 1]";
        _default = "0";
        _default_value = false;
        _constrained = false;
        _good_value = 1;
        _value = _default_value;
      };
      
    };
    
  } // services
  
} // stan

#endif

