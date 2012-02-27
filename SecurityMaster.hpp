
#include <cstdint>
#include <string>
#include <ostream>





namespace security {

enum struct Flavor { Put, Call };
enum struct Style { European, American };

typedef int32_t Id;
typedef int32_t Market;
typedef fixed<> Strike;


class Underlying {
 public:
  Underlying(Id id, std::string name);
  Id id();
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
  Future(Id id, Underlying& parent);
 private:
  Underlying& parent_;
  Term& term_;
};

 
  
class Term {
 public:
  Term(Id id);
  Id id();
 private:
  boost::postix_time::ptime expire_;
  boost::postix_time::ptime settle_;
  Id id_;
}



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

  
std::string to_str(Term& term);
std::string to_str(Option& option);
  
  
std::ostream& operator<<(std::ostream& os, Underlying& underlying); 
std::ostream& operator<<(std::ostream& os, Term& term);
std::ostream& operator<<(std::ostream& os, Option& option);

  
  

/*
 
 one security master object
 SecurityMaster sm;
 
 multiple collections of objects that can be indexed in the same way as the 
 security master
 - current prices
 - current risk
 - per-option data
 - per-strike
 - per-term
 
 sm.collection<(Option,term,strike,underlying),T>

 
 # strike risk
 sm.set<Option,T>
 = position*param, + (nearby strikes * param)
 
 updates on: position, param, 
 
 
 # rate fit
 snap: 
  market data - prices of all options
  parameters
  dividend
  
 
  = ratefit( 
   rate::fit(mktdata(und,term), param(under,term), dividend(under)
 
 
 
 to the ratedata structure: here's the (underlying,term)
   -- goes to sm, says give me address for (underlying,term)
   -- sm returns address to go into ratedata structure
 
 this seems like a mess!!
 
 
 
 
 someT = sm.subtregen<Option,T>('AAPL',2012-1-1)
 
 price = sm.subtregen<Option,Price>('AAPL',2012-1-1)
 params = sm.subtregen<Option,VolParam>('AAPL',2012-1-1) 
 snap(price,feedhandler)
 snap(params,pserver)
 
 
 ratefit = fit(price,params)
 
 volfit = sm.subtregren<Option,VolFit>('AAPL,2012-1-1)
 fit(price,params, &volfit)
 
 
 
 
 someT is now (strike,flavor,option*)
 each node has T
 option* still pointer to sm structure - maybe a reference?
 
 
 
 
*/


map<Underlying, map<Date, Dividend>> 



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