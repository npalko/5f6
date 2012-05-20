#include "asset.hpp"
#include <boost/date_time.hpp>
#include <boost/format.hpp>


using std::string;
using std::ostream;
using boost::format;
using boost::gregorian::to_iso_extended_string;


namespace asset {

// Term 

Term::Term(Id id, Datetime expire) 
  : id_(id),
    expire_(expire) {}
inline Id Term::id() const { 
  return id_; 
}    
inline Datetime Term::expire() const { 
  return expire_; 
}
string str(const Term& term) {
  format f("%1% (%2%)");
  f % to_iso_extended_string(term.expire().date()) % term.id();
  return f.str();
}
ostream& operator<<(ostream& os, const Term& term) {
  os << str(term);
  return os;
}

// Underlying

Underlying::Underlying(Id id, const string& symbol) 
  : id_(id),
    symbol_(symbol) {} 
inline Id Underlying::id() const { 
  return id_; 
}   
inline string Underlying::symbol() const { 
  return symbol_; 
		}
string str(const Underlying& underlying) {
  format f("%1% (%2%)");
  f % underlying.id() % underlying.symbol();
  return f.str();
}
ostream& operator<<(ostream& os, const Underlying& underlying) {
  os << str(underlying);
  return os;
}

// Stub 
           
Stub::Stub(Id id, string& symbol, Underlying& parent) 
  : Underlying(id, symbol),
    parent_(&parent) {}
inline const Underlying& Stub::parent() const { 
  return *parent_; 
}
string str(const Stub& stub) {
  return "";
  }
ostream& operator<<(ostream& os, const Stub& stub) {
  os << str(stub);
  return os;
}

// Future 

Future::Future(Id id, const string& symbol, Underlying& parent, Term& term)
  : Underlying(id, symbol),
    parent_(&parent),
    term_(&term) {}
inline const Underlying& Future::parent() const { 
  return *parent_; 
}
inline const Term& Future::term() const { 
  return *term_; 
}
string str(const Future& future) {
  format f("%1% %2% (%3%)");
  f % future.symbol();
  f % to_iso_extended_string(future.term().expire().date());
  f % future.id();
  return f.str();
}
ostream& operator<<(ostream& os, const Future& future) {
  os << str(future);
  return os;
}

// Dividend
  
Dividend::Dividend(Id id, Underlying& underlying, Datetime exDate, Cash cash) 
  : id_(id),
  underlying_(&underlying),
  exDate_(exDate),
  cash_(cash) {}
Id Dividend::id() const { 
  return id_; 
}
inline const Underlying& Dividend::underlying() const {
  return *underlying_;
}
Datetime Dividend::exDate() const { 
  return exDate_; 
}
Dividend::Cash Dividend::cash() const { 
  return cash_; 
}
string str(const Dividend& dividend) {
  return "";
}  
ostream& operator<<(ostream& os, const Dividend& dividend) {
  os << str(dividend);
  return os;
}
  
// Option

Option::Option(Id id, Underlying& underlying, Term& term, Strike strike, 
  Flavor flavor)
  : id_(id),
    underlying_(&underlying), 
    term_(&term), 
    strike_(strike), 
    flavor_(flavor) {}
inline Id Option::id() const { 
  return id_; }
inline const Underlying& Option::underlying() const { 
  return *underlying_; 
}
inline const Term& Option::term() const { 
  return *term_; 
}
inline Option::Strike Option::strike() const { 
  return strike_; 
}
inline Option::Flavor Option::flavor() const { 
  return flavor_; 
}
string str(const Option& option) {
  format f("%-5s %s %d%s");
  f % option.underlying().symbol();
  f % to_iso_extended_string(option.term().expire().date());
  f % option.strike();
  f % ((option.flavor() == Option::Flavor::Call) ? "C" : "P");
  return f.str();
}
ostream& operator<<(ostream& os, const Option& option) {
  os << str(option);
  return os;
}
  





// bool operator<(const Option& lhs, const Option& rhs);

  
  
  
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