#include <iostream>
#include <sstream>
#include <utility>
// TEMPLATE

using namespace std;

/*
int Sqr(int x){
  return x*x;
}

double Sqr(double x){
  return x*x;
}


THIS IS WORDY
*/


template <typename T>
T Sqr(T x){
  return x * x;
}

template <typename First, typename Second>
pair<First, Second> operator * (const pair<First, Second>& p1, const pair<First, Second>& p2){
  First f = p1.first * p2.first;
  Second s = p1.second * p2.second;
  return make_pair(f,s);
}




int main(){

  auto p = make_pair(2,1.5); // what do we need? => define the product
  p = Sqr(p);
  cout << p.first << endl;
  cout << p.second << endl;

  return 0;
}
