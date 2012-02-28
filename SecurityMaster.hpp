
#include <cstdint>
#include <string>
#include <ostream>





namespace security {

enum struct Flavor { Put, Call };
enum struct Style { European, American };

typedef int32_t Id;
typedef int32_t Market;
typedef fixed<> Strike;
typedef fixed<> Cash;
typedef boost::postix_time::ptime Datetime;  
  
class Dividend {
public:
  Dividend(Id id, Datetime exDate, Cash cash);
  Id id();
  Datetime exDate();
  Cash cash();
private:
  Id id_;
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
  Datetune settle_;
}  
  
class Underlying {
 public:
  Underlying(Id id, std::string name);
  Id id();
  std::string name();
 private:
  Id id_;
  std::string name_;
};

class Stub : Underlying {
 public:
  Stub(Id id, Underlying& parent);
 private:
  Underlying& parent_;
};

class Future : Underlying {
 public:
  Future(Id id, Underlying& parent, Term& term);
  Underlying parent();
  Term term();
 private:
  Underlying& parent_;
  Term& term_;
};

class Option {
 public:
  Option(Underlying& underlying, Term& term, Strike strike, Flavor flavor, 
    Id id);
  Equity& equity();
  Term& term();
  Strike strike();
  Flavor flavor();
  Id id();
 private:
  Underlying& underlying_;
  Term& term_;
  Strike strike_;
  Flavor flavor_;
  Id id_;
};


std::string to_str(Underlying& underlying);
std::string to_str(Future& future);
std::string to_str(Term& term);
std::string to_str(Option& option);
  
std::ostream& operator<<(std::ostream& os, Underlying& underlying);
std::ostream& operator<<(std::ostream& os, Future& future);
std::ostream& operator<<(std::ostream& os, Term& term);
std::ostream& operator<<(std::ostream& os, Option& option);

  
  


/*

class SecurityMaster {
 public:
  SecurityMaster () {}
    // terms per underlying
    // strikes per (underlying,term)
    // options per strike
 private:
  typedef map<Equity, map<Term, map<Strike, map<Flavor, Option*>>>> OptionMap;
  typedef map<Equity, map<Term, Future*>> FutureMap;
  // and define iteratiors
  set<Equity> equity_;
  set<Option> option_;
  set<Future> future_;
  set<Market> market_;
}
*/

}