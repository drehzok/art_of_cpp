#include <iostream>
#include <utility>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


// Avoiding duplication

template <typename Collection>
string Join(const Collection& c, char d){
  stringstream ss;
  bool first = true;
  for (const auto& i : c){
    if (!first){
      ss << d;
    }
    first = false;
    ss << i;
  }
  return ss.str();
}

template <typename T>
ostream& operator << (ostream& out, const vector<T> & v){
  return out << '['<< Join(v, ',') << ']';
}

template <typename Key, typename Value>
ostream& operator << (ostream& out, const map<Key, Value>& m){
  return out << '{' << Join(m, ',') << '}';
}

template <typename F, typename S>
ostream& operator << (ostream& out, const pair<F,S>& p){
  return out << '(' << p.first << ',' << p.second << ')';
}

//Parametrized types
template <typename T>
T Max(T a, T b){
  if (b < a){
    return a;
  }
  return b;
}


int main(){

  vector<int> v = {1,2,4,5,6,3,2,1};

  cout << v << endl;

  map<int,string> m = {{1,"Sungbae"}, {2,"Jk"}, {3,"V"}};

  cout << m << endl;

  vector<vector<int>> v1 = { {1,2},{2,3} };
  cout << v1 << endl;

  cout << Max(2,3) << endl;
  // Max(2,3.4) => compiler : "what should I do?"

  cout << Max<double>(2,3.4) << endl;

  cout << max<double>(2,3.5) << endl;

  //template <class T> <=> template <typenmae T>

  return 0;
}
