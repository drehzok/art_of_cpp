#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

class Rational {
public:
    Rational() {
      num = 0;
      den = 1;
    }

    Rational(int numerator, int denominator) {
      num = numerator*denominator/abs(denominator*__gcd(numerator,denominator));
      den = abs(denominator/__gcd(numerator,denominator));
    }

    int Numerator() const {
      return num;
    }

    int Denominator() const {
      return den;
    }

private:
  int num;
  int den;

};

// Реализуйте для класса Rational операторы ==, + и -
bool operator==(const Rational& lhs, const Rational& rhs){
  return lhs.Numerator()==rhs.Numerator() ? lhs.Denominator()==rhs.Denominator() : false;
}

Rational operator+(const Rational& lhs, const Rational& rhs){
  return Rational(lhs.Numerator()*rhs.Denominator()
              +rhs.Numerator()*lhs.Denominator(),rhs.Denominator()*lhs.Denominator());
}

Rational operator-(const Rational& lhs, const Rational& rhs){
  return Rational(lhs.Numerator()*rhs.Denominator()
              -rhs.Numerator()*lhs.Denominator(),rhs.Denominator()*lhs.Denominator());
}

// Реализуйте для класса Rational операторы << и >>

ostream& operator<<(ostream& os, const Rational& r){
  os << r.Numerator()<<'/'<<r.Denominator();
  return os;
}
istream& operator>>(istream& is, Rational& r){

  int n = 0;
  int d = 1;
  if  (! (is >> n)) return is;

  is.ignore(1);
  is >> d;
  r = Rational(n,d);

  return is;
}

int main() {
    {
        ostringstream output;
        output << Rational(-6, 8);
        if (output.str() != "-3/4") {
            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
            return 1;
        }
    }

    {
        istringstream input("5/7");
        Rational r;
        input >> r;
        bool equal = r == Rational(5, 7);
        if (!equal) {
            cout << "5/7 is incorrectly read as " << r << endl;
            return 2;
        }
    }

    {
        istringstream input("5/7 10/8");
        Rational r1, r2;
        input >> r1 >> r2;
        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
            return 3;
        }

        input >> r1;
        input >> r2;
        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
        if (!correct) {
            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
            return 4;
        }
    }

    cout << "OK" << endl;
    return 0;
}
