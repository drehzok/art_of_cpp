#include <iostream>
#include <vector>
#include <sstream>
#include <utility>
#include <map>

using namespace std;


template <typename T>
ostream& operator << (ostream& out , const vector<T>& vi){
  for (const auto& i : vi){
    cout << i << ' ';
  }
  return out;
}

template <typename First, typename Second>
ostream & operator << (ostream& out , const pair<First, Second>& p){
    out << p.first << "," << p.second;
    return out;
}


template <typename Key, typename Val>
ostream& operator << (ostream& out , const map<Key, Val>& vi){
  for (const auto& i : vi){
    cout << i << ' ';
  }
  return out;
}

int main(){
  vector<double> v = {1,2,3};
  cout << v << endl;

  map<int, double> m = {{1,2.2},{2,3.3}};
  cout << m << endl;
  return 0;
}
