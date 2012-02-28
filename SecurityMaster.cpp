

namespace security {
  
Id Dividend::Id() {
    return id_;
}

  
  
  
}


class Underlying {
 public:
  Underlying(Id id) : id_(id) {}
  Id id() const { return id_ };
 private:
  Id id_;
}

class Stub : Underlying {
 public:
  
 private:
  Underlying& parent_;
}

class Future : Underlying {
 public:
  
 private:
  Underlying& parent_;
  Term& term_;
}


class Term {
 public:
  Term(Id id) : id_(id) {}
  Id id() const { return id_; }
 private:
  boost::postix_time::ptime expire_;
  boost::postix_time::ptime settle_;
  Id id_;
}

operator<< (,const Term& term) {
  
}


class Option {
 public:
  Option(const Underlying& underlying, const Term& term, Strike strike, Flavor flavor, 
    Id id)
    : underlying_(underlying), 
      term_(term), 
      strike_(strike), 
      flavor_(flavor), 
      id_(id) {}
  Equity& equity() const { return equity_; }
  Term& term() const { return term_; }
  Strike strike() const { return strike_; }
  Flavor flavor() const { return flavor_; }
  Id id() const { return id_; }
 private:
  Underlying& underlying_;
  Term& term_;
  Strike strike_;
  Flavor flavor_;
  Id id_;
};

std::ostream& operator<< (std::ostream& os, const Option& option) {
  
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