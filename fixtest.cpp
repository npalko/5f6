#include "fixed.hpp"
#include <boost/cstdint.hpp>
#include <iostream>

int main(int argc, char** argv) {
  
  
  
  Fixed<boost::int32_t,4> f;
  std::cout << "int32_t = " << sizeof(boost::int32_t)
            << " fixed = " << sizeof(f) << '\n';
            
  
}