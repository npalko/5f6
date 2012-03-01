#include <boost/format.hpp>

#include "SecurityMaster.hpp"

using std::string;
using std::ostream;
//using std::map;


namespace security {


Dividend::Dividend(Id id, Datetime exDate, Cash cash) 
  : ReferenceEntity(id),
    exDate_(exDate),
    cash_(cash) {}
Datetime Dividend:exDate() const { 
  return exDate_; 
}
Cash Dividend::cash() const {
  return cash_;
}

Term::Term(Id id, Datetime expire, Datetime settle) 
  : ReferenceEntity(id),
    expire_(expire),
    settle_(settle) {}
Datetime Term::expire() const {
  return expire_;
}
Datetime Term::settle() const {
  return settle_;
}
    
Underlying::Underlying(Id id, const string& symbol) 
  : ReferenceEntity(id),
    symbol_(symbol) {}
string Underlying::symbol() const {
  return symbol_;
}

Stub::Stub(Id id, const string& symbol, const Underlying& parent) 
  : Underlying(id, symbol),
    parent_(parent) {}
Underlying Stub::parent() const {
  return parent_;
}

Future::Future(Id id, const string& symbol, const Underlying& parent, 
  const Term& term)
  : Underlying(id, symbol),
    parent_(parent),
    term_(term) {}
Underlying Future::parent() const {
  return parent_;
}
Future::term() const {
  return term_;
}

Option::Option(Id id, const Underlying& underlying, const Term& term, 
  Strike strike, Flavor flavor)
  : ReferenceEntity(id),
    underlying_(underlying), 
    term_(term), 
    strike_(strike), 
    flavor_(flavor) {}   
Underlying Option::Underlying& underlying() const { 
  return underlying_; 
}
Term Option::Term& term() const { 
  return term_;
}
Strike Option::Strike strike() const {
  return strike_;
}
Flavor Option::Flavor flavor() const { 
  return flavor_; 
}

string toString(const Option& option) {
  
}



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


/*
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
  
  
*/  
  
  
}