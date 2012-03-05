#ifndef SECURITY_TYPE_HPP
#define SECURITY_TYPE_HPP

//#include "fixed.hpp"
#include <boost/date_time/posix_time/posix_time.hpp>
//#include <cstdint>
#include <string>
//#include <set>
#include <iosfwd>





namespace security {

typedef int Id;
typedef int Market;
typedef boost::posix_time::ptime Datetime;

class Dividend {
 public:
  typedef int Cash;
 public:
  // add pointer to underlying
  Dividend(Id id, Datetime exDate, Cash cash);
  Id id() const;
  Datetime exDate() const;
  Cash cash() const;
 private:
  Id id_;
  Datetime exDate_;
  Cash cash_;
};
  
std::string str(const Dividend& dividend);  

  
class Term {
 public:
  Term(Id id, Datetime expire, Datetime settle);
  Term(Id id, const std::string& expire, const std::string& settle);
  Id id() const;
  Datetime expire() const;
  Datetime settle() const;
 private:
  Id id_;
  Datetime expire_;
  Datetime settle_;
};
  
std::string str(const Term& term);
  
  
class Underlying {
 public:
  Underlying(Id id, const std::string& symbol);
  Id id() const;
  std::string symbol() const;
  std::string str() const;
 private:
  Id id_;
  std::string symbol_;
};
  
std::string str(const Underlying& underlying);

  
class Stub : public Underlying {
 public:
  Stub(Id id, std::string& symbol, Underlying& parent);
  Underlying& parent() const;
 private:
  Underlying* parent_;
};

std::string str(const Stub& stub);
  
  
class Future : public Underlying {
 public:
  Future(Id id, const std::string& symbol, Underlying& parent, Term& term);
  Underlying& parent() const;
  Term& term() const;
 private:
  Underlying* parent_;
  Term* term_;
};

std::string str(const Future& future);
std::ostream& operator<<(std::ostream& os, const Future& future);

  
class Option {
 public:
  enum struct Flavor { Put, Call };
  enum struct Exercise { European, American };
  typedef int Strike;
 public:
  Option(Id id, Underlying& underlying, Term& term, Strike strike, 
    Flavor flavor);
  Id id() const;
  Underlying& underlying() const;
  Term& term() const;
  Strike strike() const;
  Flavor flavor() const;
 private:
  Id id_;
  Underlying* underlying_;
  Term* term_;
  Strike strike_;
  Flavor flavor_;
};

std::string str(const Option& option);



  
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

