

#include <boost/cstdint.hpp>
#include <boost/operators.hpp>
#include <iosfwd>
#include <exception>




class Decimal : boost::operators {
 public:
  Decimal() : base_(0) {
  }

  
 private:
  Base base_;
  
  
};
  
