enum struct Flavor { Put, Call };
enum struct Style { European, American };

typedef Id int64;
typedef Strike fixed<>
typedef Market int64
typedef Underlying int64;

struct Term {
  Term(Date label, DateTime expire, Id id) : label(label), expire(expire), id(id) {}
  const Date label;
  const DateTime expire;
  const Id id;
};

struct Option {
  Option(Underlying& underlying, Term& term, Strike& strike, Flavor flavor, Id id) :
     underlying(underlying), term(term), strike(strike), flavor(flavor), id(id) {}
  const Underlying& underlying;
  const Term& term;
  const Strike& strike;
  const Flavor flavor;
  const Id id;
};




class SecurityMaster {
 public:
 private:
  set<Id, Underlying>
  set<Id, Option>
  set<Id, Future>
  
  set<Underlying, set<Term, set<Strike, set<Flavor, Option*>>>>
  set<Underlying, set<Term, Future*>>
  
  
}