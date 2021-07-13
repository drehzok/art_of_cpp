# Yandex coursera specialisation: Art of C++

## Week 1

### Hello_world.cpp
```c++
#include <iostream>
using namespace std;

int main(){
  cout << "Hello, world";
  return 0;
}
```
 - `iostream` - for input/output (cout)
 - `int main()` - a must-exist function in c++

### Preview of types
 - c++ is statically typed language - we need type for every variable

```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// custom type of variable
struct Person{
  string name;
  string surname;
  int age;
};

int main(){
  int x = -5;
  double pi = 3.14;
  bool state = true;
  char symbol = 'a';

  string s = "hello, world";
  vector<int> nums = {1,3,5,7};
  cout << nums.size();

  vector<Person> staff;
  staff.push_back({"Sungbae", "Chun", 21})

  cout << staff[0].name << endl;

}
```
