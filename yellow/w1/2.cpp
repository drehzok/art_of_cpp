#include <iostream>
#include <vector>
#include <tuple>
#include <utility>

using namespace std;

struct Date {
  int year;
  int month;
  int day;
};



/* Damn wordy
bool operator< (const Date& lhs, const Date& rhs){
  if (lhs.year!=rhs.year){
    return lhs.year < rhs.year;
  }
  if (lhs.month != rhs.month){
    return lhs.month < rhs.month;
  }
  return lhs.day < rhs.day;
}
*/



/*

Not optimal yet

bool operator<(const Date& lhs, const Date& rhs){
  return vector<int>{lhs.year,lhs.month,lhs.day} <
    vector<int>{rhs.year,rhs.month,rhs.day};
}
*/

bool operator<(const Date& lhs, const Date& rhs){
  tuple <const int&, const int&, const int&> lhs_key = tie(lhs.year, rhs.month, lhs.day);
  "Tie does not copy components";
  return tie(lhs.year, lhs.month, lhs.day) <
          tie(rhs.year, rhs.month, rhs.day);
}

//tie => std::tuple




int main(){

  cout << (Date{2017,6,8} < Date{2017, 1, 26})  << endl;

  //"tuple<int, string, bool> t(7,"C++", true)";
  //"However, new C++ allow ommiting <T,T,T>";


  //tuple t(7,"C++",true);
  //only in C++17

  //tie => allocated variables, just references
  auto t1 = make_tuple(7, "C++", true);

  cout << get<1>(t1) << endl;

  pair<int, string> p(7, "C++");
  cout << p.first << " " << p.second << endl;



  return 0;
}
