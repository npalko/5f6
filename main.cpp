
#include "SecurityMaster.hpp"
#include <iostream>
#include <vector>


int main(int argc, char** argv) {
  
  using namespace security;
  
  Term t(1,"2002-01-20 23:59:59.000","2002-01-20 23:59:59.000");
  Underlying u(2,"AAPL");
  Future f(5,"ES",u,t);
  Option opt(3,u,t,30,Option::Flavor::Put,Option::Exercise::American);

  std::cout << str(opt) << '\n';
  
  
  std::vector<Future> v;
  v.push_back(f);

  
  std::cout << v[0] << '\n';
}
