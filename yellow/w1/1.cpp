#include <iostream>
#include <vector>
//#include <cstdint>
#include <limits>
//can know limits of types

using namespace std;

int main() {
  vector<int> t = {-8,-7,3};
  int sum = 0;

  for (int x: t){
    sum += x;
  }
  int avg = sum / t.size();
  // size cannot contain negative -> strange result

  // note that 20000 == 20'000

/*

int is the most efficient -> as translated to processors easily

unsigned int
== unsigned

2^32 values for int

size_t - 2^(processor)


#include <cstdint>

int32_t, uint32_t, etc...



*/

  cout << avg << endl;
  cout << "size of int: " << sizeof(int) << endl;
  cout << "size of int16_t: " << sizeof(int16_t) << endl;
  cout << "int range: " << numeric_limits<int>::min() <<' '
        << numeric_limits<int>::max() << endl;

  cout << "long max: " << numeric_limits<long>::max()<<endl;
  cout << "long int min: " << numeric_limits<long int>::min()<<endl;

  cout << "\n\n\n\n";

  int x = 2'000'000'000;
  int y = 1'000'000'000;

  cout << "Mean of "<< x << ' '<< y << " is "<<(x+y)/2 << endl;
  cout << "Overflew"<<endl;


  //What was the problem is the average of t?
  //t.size() was unsigned int

  //rule: unsgined vs signed and same size => unsigned wins

  // int / size_t => size_t
  // int32_t + int8_t => int32_t

  //how to check for the type?
  //add "impossible" and compiler will complain
  // int avg = sum / t.size() + vector<char>{};
  //we see size_t

  // x = 1u == unsigned int x = -1


 // g++ <file> -Wall -Werror => warnings as errors
 cout << (static_cast<unsigned int>(-1 ) < 1u) << endl;

 cout << static_cast<unsigned int>(-1)<<endl;

 avg = sum / static_cast<int>(t.size());
 cout << avg << endl;
  return 0;
}
