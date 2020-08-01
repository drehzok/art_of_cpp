#include <iostream>
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



int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
