
#include <cstdint>
#include <ostream>
#include <exception>

#include <boost/operators.hpp>



namespace fixed {
  
  
  
template < >
class Decimal : boost::operators {
 public:
  Decimal() : base_(0) {
  }
  Decimal(int x) {
    
  }
  Decimal(double x)
  
  Decimal(const Decimal &)
  
  
 private:
  Base base_;
  
  
};
  
}