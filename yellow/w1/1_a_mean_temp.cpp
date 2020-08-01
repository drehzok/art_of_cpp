#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;


int64_t calcmean(const vector<int64_t>& v){
  int64_t sum = 0;
  for (const auto& i : v){
    sum += i;
  }
  return static_cast<int64_t>(sum) / static_cast<int64_t>(v.size());
}

void printvector(const vector<size_t>& v){
  for (const auto& i : v){
    cout << i << ' ';
  }
  cout << endl;
}

int main(){
  size_t length;
  int64_t temp;
  cin >> length;
  vector<int64_t> m_vec;
  for(size_t i=0; i<length; ++i){
    cin >> temp;
    m_vec.push_back(temp);
  }
  int64_t mean = calcmean(m_vec);
  vector<size_t> poses;
  size_t count = 0;
  for(size_t i = 0; i<length; ++i){
    if (m_vec[i]>mean){
      poses.push_back(i);
      count ++;
    }
  }
  cout << count << endl;
  printvector(poses);

  return 0;
}
