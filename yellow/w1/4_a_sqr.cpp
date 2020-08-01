#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;


template <class T>
T Sqr(T val);
template <class T>
vector<T> operator *(const vector<T>& c1 ,const vector<T>& c2) ;

template <class First, class Second>
map<First, Second> operator *(const map<First,Second>& c1,const map<First,Second>& c2);

template <class First, class Second>
pair<First,Second> operator *(const pair<First,Second>& c1,const pair<First,Second>& c2);


template <class T>
T Sqr(T val) {
	return val*val;
}


template <class T>
vector<T> operator *(const vector<T>& c1 ,const vector<T>& c2) {
	vector<T> temp(c1);
	for(auto i = 0; i<temp.size(); ++i){
		temp[i] = temp[i]*c2[i];
	}
	return temp;
}


template <class First, class Second>
map<First, Second> operator *(const map<First,Second>& c1,const map<First,Second>& c2) {
	map<First, Second> temp(c1);
	for (auto& item: temp) {
			item.second = c1.at(item.first) * c2.at(item.first);
	}
	return temp;
}

template <class First, class Second>
pair<First,Second> operator *(const pair<First,Second>& c1,const pair<First,Second>& c2) {
	return make_pair(c1.first*c2.first, c1.second*c2.second);
}





int main(){
  vector<int> v = {1, 2, 3};
  cout << "vector:";
  for (int x : Sqr(v)) {
    cout << ' ' << x;
  }
  cout << endl;

	pair<int,int> p1 = {1,2};
	cout << Sqr(p1).first << ' '<<Sqr(p1).second << endl;

  map<int, pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
  };
  cout << "map of pairs:" << endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
  }

  vector<vector<int>> vv = {{1,2,3},{4,5,6}};

  for (const auto& x: Sqr(vv)){
    for (const auto& y : x){
      cout << y;
    }
  }
  cout << endl;

  return 0;
}
