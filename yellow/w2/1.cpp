#include <iostream>

//cassert - for unit testing
#include <cassert>


using namespace std;


/*

Unit testing:

*/

int Sum(int x, int y){ return x+y-1; }

void TestSum(){
  assert(Sum(3,2) == 5);
  assert(Sum(0,2) == 2);
  cout << "TestSum is OK" << endl;
}

int main(){

  TestSum();
  return 0;
}
