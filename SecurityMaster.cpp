#include <boost/format.hpp>
#include "SecurityMaster.hpp"

//using std::map;


namespace security {


using std::string;
/*
Container<Level,T>(*underlying)
-- isn't this just essentially a vector?
and our security master provides indexing into it?


Container<Underlying,T>     // underlying
Container<Term,T>           // underlying|term
Container<Option,T>         // underlying|term|strike|flavor

subset
 .Underlying
 .Term


Container<Option,T>(subset)   -- make an option Container
-- create new each time
-- or reference existing global Tree

*/



Dividend::Dividend(Id id, Datetime exDate, Cash cash) 
  : id_(id),
    exDate_(exDate),
    cash_(cash) {}
Id Divided::id() const { return Id_; }
Datetime Dividend:exDate() const { return exDate_; }
Cash Dividend::cash() const { return cash_; }


Term::Term(Id id, Datetime expire, Datetime settle) 
  : id_(id),
    expire_(expire),
    settle_(settle) {}
Id Term::id() const { return Id_; }    
Datetime Term::expire() const { return expire_; }
Datetime Term::settle() const { return settle_; }

//string toString(const Underlying& underlying) {return "";}


Underlying::Underlying(Id id, const string symbol) 
  : id_(id),
    symbol_(symbol) {}  
Id Underlying::id() const { return Id_; }   
string Underlying::symbol() const { return symbol_; }

//string toString(const Underlying& underlying) {return "";}

/*
Stub::Stub(Id id, const string& symbol, const Underlying& parent) 
  : Underlying(id, symbol),
    parent_(parent) {}
Underlying& Stub::parent() const { return parent_; }


Future::Future(Id id, const string& symbol, const Underlying& parent, 
  const Term& term)
  : id_(id),
    Underlying(id, symbol),
    parent_(parent),
    term_(term) {}
Id Option::id() { return id_; }
Underlying& Future::parent() const { return parent_; }
Term& Future::term() const { return term_; }
*/

//string toString(const Future& future) {return "";}


Option::Option(Id id, const Underlying& underlying, const Term& term, 
  Strike strike, Flavor flavor)
  : id_(id),
    underlying_(underlying), 
    term_(term), 
    strike_(strike), 
    flavor_(flavor) {}
Id Option::id() { return id_; }
Underlying& Option::underlying() const { return underlying_; }
Term& Option::term() const { return term_; }
Strike Option::strike() const { return strike_; }
Flavor Option::flavor() const { return flavor_; }

//string toString(const Option& option) {return "";}

// bool operator<(const Option& lhs, const Option& rhs);


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