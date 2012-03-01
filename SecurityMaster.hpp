
#include <cstdint>
#include <string>
#include <set>
#include <ostream>

#include "fixed.hpp"



namespace security {

enum struct Flavor { Put, Call };
enum struct Style { European, American };

typedef int32_t Id;
typedef int32_t Market;
typedef fixed<int32_t,6> Strike;
typedef fixed<int32_t,6> Cash;
typedef boost::postix_time::ptime Datetime;  

class ReferenceEntity {
 public:
  Entity(Id id);
  Id id();
 private:
  Id id_;
}

class Dividend : ReferenceEntity {
 public:
  Dividend(Id id, Datetime exDate, Cash cash);
  Datetime exDate();
  Cash cash();
 private:
  Datetime exDate_;
  Cash cash_;
};

class Term : ReferenceEntity {
 public:
  Term(Id id, Datetime expire, Datetime settle);
  Datetime expire();
  Datetime settle();
 private:
  Datetime expire_;
  Datetune settle_;
}  
  
std::string toString(Term& term);
  
class Underlying {
 public:
  Underlying(Id id, std::string& symbol);
  std::string symbol();
 private:
  std::string symbol_;
};

class Stub : Underlying {
 public:
  Stub(Id id, Underlying& parent);
 private:
  Underlying& parent_;
};

std::string toString(Underlying& underlying);
  
class Future : Underlying {
 public:
  Future(Id id, Underlying& parent, Term& term);
  Underlying parent();
  Term term();
 private:
  Underlying& parent_;
  Term& term_;
};

std::string toString(Future& future);

class Option : ReferenceEntity {
 public:
  Option(Id id, Underlying& underlying, Term& term, Strike strike, 
    Flavor flavor);
  Underlying& underlying();
  Term& term();
  Strike strike();
  Flavor flavor();
 private:
  Underlying& underlying_;
  Term& term_;
  Strike strike_;
  Flavor flavor_;
};

std::string toString(Option& option);

template <class T>
std::ostream& operator<<(std::ostream& os, const T& obj);
  os << toString(obj);
  return os;
}


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
  

}
