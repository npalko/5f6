#ifndef FIXED_HPP
#define FIXED_HPP

// http://www.boost.org/doc/libs/1_34_1/libs/numeric/conversion/doc/converter.html#synopsis

#include <boost/operators.hpp>
#include <iosfwd>
#include <exception>

namespace fixed {


template <class Base, std::size_t N>
class Fixed : boost::operators<Fixed<Base,N>> {
 public: // constructors
  Fixed() : data_(0) {
  };
  Fixed(int n) {
    
  };
  Fixed(double n) {
    
  };
  Fixed(const std::string& s) {
    
  };
 public: // cast operators
  operator int() const {
    
  };
  operator double() const {
    
  };
 public: // special case for std::ostream
  friend std::ostream& operator<<(std::ostream& os, const Fixed &f) {
    os << "";
    return os;
  };
 public: // boost::operators
  bool operator<(const Fixed& x) const {
    return false;
  };
  bool operator==(const Fixed& x) const {
    return false;
  };
  Fixed& operator+=(const Fixed& x) {
    return Fixed(0);
  };
  Fixed& operator-=(const Fixed& x) {
    return Fixed(0);
  };
  Fixed& operator*=(const Fixed& x) {
    return Fixed(0);
  };
  Fixed& operator/=(const Fixed& x) {
    return Fixed(0);
  };
  Fixed& operator%=(const Fixed& x) {
    return Fixed(0);
  };
  Fixed& operator|=(const Fixed& x) {
    return Fixed(0);
  };
  Fixed& operator&=(const Fixed& x) {
    return Fixed(0);
  };
  Fixed& operator^=(const Fixed& x) {
    return Fixed(0);
  };
  Fixed& operator++() {
    return Fixed(0);
  };
  Fixed& operator--() {
    return Fixed(0);
  };
 private:
  Base data_;
  static const size_t N_ = N;
};



#endif

  
