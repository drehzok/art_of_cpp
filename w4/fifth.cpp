#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

class Rational {
public:
    Rational() {
      num = 0;
      den = 1;
    }

    Rational(int numerator, int denominator) {
      if (numerator==0){
        den = 1;
        num = 0;
      }
      else{
      num = numerator*denominator/abs(denominator*__gcd(numerator,denominator));
      den = abs(denominator/__gcd(numerator,denominator));
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
// Реализуйте для класса Rational оператор(ы), необходимые для использования его
// в качестве ключа map'а и элемента set'а
Rational operator-(const Rational& lhs, const Rational& rhs){
  return Rational(lhs.Numerator()*rhs.Denominator()
              -rhs.Numerator()*lhs.Denominator(),rhs.Denominator()*lhs.Denominator());
}


bool operator<(const Rational& lhs, const Rational& rhs){
  return (lhs-rhs).Numerator()<0;
}

int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl;
            return 1;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
