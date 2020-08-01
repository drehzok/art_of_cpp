#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;



int main(){
  uint64_t R;
  uint64_t N;

  unsigned long res=0;

  cin >> N >> R;

  for(uint64_t i = 0; i<N; ++i){
    uint64_t W,H,D;

    cin >> W >> H >> D;
    res += W*H*D;
  }
  res *= R;

  cout << res << endl;

  return 0;
}
