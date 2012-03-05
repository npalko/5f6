#ifndef SECURITY_TYPE_HPP
#define SECURITY_TYPE_HPP

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/cstdint.hpp>
#include <string>
#include <iosfwd>


namespace security {

typedef boost::int32_t Id;
typedef boost::int32_t Market;
typedef boost::posix_time::ptime Datetime;

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
std::ostream& operator<<(std::ostream& os, const Term& term);
  
  
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
std::ostream& operator<<(std::ostream& os, const Underlying& underlying);


class Stub : public Underlying {
 public:
  Stub(Id id, std::string& symbol, Underlying& parent);
  Underlying& parent() const;
 private:
  Underlying* parent_;
};

std::string str(const Stub& stub);
std::ostream& operator<<(std::ostream& os, const Stub& stub);

  
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
  
  
class Dividend {
 public:
  typedef int Cash;
 public:
  Dividend(Id id, Underlying& underlying, Datetime exDate, Cash cash);
  Id id() const;
  Underlying& underlying() const;
  Datetime exDate() const;
  Cash cash() const;
 private:
  Id id_;
  Underlying* underlying_;
  Datetime exDate_;
  Cash cash_;
};
  
std::string str(const Dividend& dividend);  
std::ostream& operator<<(std::ostream& os, const Dividend& dividend);
  
class Option {
 public:
  typedef int Strike;
  enum struct Flavor { Put, Call };
  enum struct Exercise { European, American };
 public:
  Option(Id id, Underlying& underlying, Term& term, Strike strike, 
    Flavor flavor, Exercise exercise);
  Id id() const;
  Underlying& underlying() const;
  Term& term() const;
  Strike strike() const;
  Flavor flavor() const;
  Exercise exercise() const;
 private:
  Id id_;
  Underlying* underlying_;
  Term* term_;
  Strike strike_;
  Flavor flavor_;
  Exercise exercise_;
};

std::string str(const Option& option);
std::ostream& operator<<(std::ostream& os, const Option& option);


  
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

