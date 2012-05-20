#ifndef ASSET_HPP
#define ASSET_HPP

#include "fixed/fixed.hpp"

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/cstdint.hpp>
#include <string>
#include <iosfwd>
#include <vector>


namespace asset {

/** Immutable surrogate identity for every entity in the system */
typedef boost::int32_t Id;
typedef boost::posix_time::ptime Datetime;

class Term {
 public:
  Term(Id id, Datetime expire);
  Id id() const;
  Datetime expire() const;
 private:
  Id id_;
  Datetime expire_;
};
  
std::string str(const Term& term);
std::ostream& operator<<(std::ostream& os, const Term& term);
  
  
class Underlying {
 public:
  Underlying(Id id, const std::string& symbol);
  Id id() const;
  std::string symbol() const;
 private:
  Id id_;
  std::string symbol_;
};
  
std::string str(const Underlying& underlying);
std::ostream& operator<<(std::ostream& os, const Underlying& underlying);


class Stub : public Underlying {
 public:
  Stub(Id id, std::string& symbol, Underlying& parent);
  const Underlying& parent() const;
 private:
  Underlying* parent_;
};

std::string str(const Stub& stub);
std::ostream& operator<<(std::ostream& os, const Stub& stub);

  
class Future : public Underlying {
 public:
  Future(Id id, const std::string& symbol, Underlying& parent, Term& term);
  const Underlying& parent() const;
  const Term& term() const;
 private:
  Underlying* parent_;
  Term* term_;
};

std::string str(const Future& future);
std::ostream& operator<<(std::ostream& os, const Future& future);
  
  
class Dividend {
 public:
  typedef fixed::int32p6_t Cash;
 public:
  Dividend(Id id, Underlying& underlying, Datetime exDate, Cash cash);
  Id id() const;
  const Underlying& underlying() const;
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

/** 
 */

class Option {
 public:
  typedef fixed::int32p4_t Strike;
  typedef fixed::int32p4_t Delivery;
  enum struct Flavor { Put, Call };
  enum struct Exercise { European, American };
 public:
  /** 
   @param id
   @param underlying
   @param term
   @param strike
   @param flavor 
   */
  Option(Id id, Underlying& underlying, Term& term, Strike strike, 
    Flavor flavor);
  Id id() const;
  const Underlying& underlying() const;
  const Term& term() const;
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
//std::string osi(const Option& option);
std::ostream& operator<<(std::ostream& os, const Option& option);


template<class T>
class TermTree {
 public:
 private:
  std::vector<Term> term_;
  std::vector<Underlying> underlying_;
  std::vector<Stub> stub_;
  std::vector<Future> future_;
  std::vector<T> data_;
};

template<class T>
class OptionTree {
 public:
  //Tree() 
 private:
  //typedef map<Underlying,map<Term,map<Strike,map<Flavor,Option*>>>> Optionmap;
  std::vector<Term> term_;
  std::vector<Underlying> underlying_;
  std::vector<Stub> stub_;
  std::vector<Future> future_;
  std::vector<Option> option_;
  std::vector<T> data_;
};


}

#endif

