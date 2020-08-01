#include <iostream>
#include <algorithm>
#include <exception>
#include <stdexcept>
using namespace std;

int recursive_div_helper (int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (recursive_div_helper(b, a % b));
}


class Rational {
public:
    Rational() {
      num = 0;
      den = 1;
    }

    Rational (int numerator, int denominator) {
  		if (denominator == 0)
      			throw invalid_argument("zero denominator");

  		int div = recursive_div_helper(numerator, denominator);

  		num = numerator / div;
  		den = denominator / div;

  		if (num < 0) {
  			den *= -1;
  			num *= -1;
  		}
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

// Реализуйте для класса Rational операторы * и /
Rational operator * (const Rational& left, const Rational& right) {
	int l = left.Numerator() * right.Numerator();
	int r = right.Denominator() * left.Denominator();

	return (Rational(l, r));
}

Rational operator / (const Rational& left, const Rational& right) {
	if (right.Numerator() == 0)
		throw domain_error("division by zero");

	return (left * Rational(right.Denominator(), right.Numerator()));
}


int main() {
    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a * b;
        bool equal = c == Rational(8, 9);
        if (!equal) {
            cout << "2/3 * 4/3 != 8/9" << endl;
            return 1;
        }
    }

    {
        Rational a(5, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(2, 3);
        if (!equal) {
            cout << "5/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    {
        Rational a(0, 4);
        Rational b(15, 8);
        Rational c = a / b;
        bool equal = c == Rational(0, 3);
        if (!equal) {
            cout << "0/4 / 15/8 != 2/3" << endl;
            return 2;
        }
    }

    cout << "OK" << endl;
    return 0;
}
