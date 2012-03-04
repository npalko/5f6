#ifndef SECURITY_TYPE_HPP
#define SECURITY_TYPE_HPP


//#include <cstdint>
#include <string>
//#include <set>
//#include <ostream>
#include <boost/date_time/posix_time/posix_time.hpp>
//#include "fixed.hpp"



namespace security {

enum struct Flavor { Put, Call };
enum struct Exercise { European, American };

typedef int Id;
typedef int Market;
typedef int Strike;
typedef int Cash;
//typedef fixed<int32_t,6> Strike;
//typedef fixed<int32_t,6> Cash;
typedef boost::posix_time::ptime Datetime;

class Dividend {
 public:
  Dividend(Id id, Datetime exDate, Cash cash);
  Datetime exDate();
  Cash cash();
 private:
  Datetime exDate_;
  Cash cash_;
};

class Term {
 public:
  Term(Id id, Datetime expire, Datetime settle);
  Id id();
  Datetime expire();
  Datetime settle();
 private:
  Id id_;
  Datetime expire_;
  Datetime settle_;
};
  
//std::string toString(Term& term);
  
class Underlying {
 public:
  Underlying(Id id, std::string symbol);
  Id id();
  std::string symbol();
 private:
  Id id_;
  std::string symbol_;
};

/*
class Stub : Underlying {
 public:
  Stub(Id id, Underlying& parent);
  Underlying parent();
 private:
  Underlying& parent_;
};

//std::string toString(Underlying& underlying);
  
class Future : Underlying {
 public:
  Future(Id id, Underlying& parent, Term& term);
  Underlying parent();
  Term term();
 private:
  Underlying& parent_;
  Term& term_;
};
*/
//std::string toString(Future& future);

class Option {
 public:
  Option(Id id, Underlying& underlying, Term& term, Strike strike, 
    Flavor flavor);
  Id id();
  Underlying& underlying();
  Term& term();
  Strike strike();
  Flavor flavor();
 private:
  Id id_;
  Underlying& underlying_;
  Term& term_;
  Strike strike_;
  Flavor flavor_;
};

//std::string toString(Option& option);

/*
template <class T>
std::ostream& operator<<(std::ostream& os, const T& obj);
  os << toString(obj);
  return os;
}
*/

/*
class Master {
 public:
  Master();
 private:
  //typedef map<Underlying,map<Term,map<Strike,map<Flavor,Option*>>>> Optionmap;
  
  std::set<Term> term_;
  std::set<Underlying> underlying_;
  std::set<Stub> stub_;
  std::set<Future> future_;
  std::set<Option> option_;
};
*/

}

#endif

