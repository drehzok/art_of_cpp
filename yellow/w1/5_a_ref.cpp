#include <map>
#include <iostream>
#include <utility>
#include <stdexcept>

using namespace std;


template <class Key, class Val>
Val& GetRefStrict(map<Key, Val>& m, const Key& key){
  for(auto& i:m){
    if (i.first == key){
      return i.second;}
  }
  throw runtime_error("Not Found");
}

int main(){
  map<int, string> m = {{0, "value"}};
  string& item = GetRefStrict(m, 0);
  item = "newvalue";
  cout << m[0] << endl; // выведет newvalue
 return 0;
}
