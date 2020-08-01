#include <iostream>
#include <string>
#include <tuple>
#include <map>
#include <set>


class Cities{
public:
  std::tuple<bool, std::string> FindContry(const std::string& city) const{
    if (city_to_country.count(city) == 1){
      return {true, city_to_country.at(city)};
    } else if (ambiguous_cities.count(city) == 1){
      return {false, "Ambiguous"};
    } else{
      return {false, "Not exist"};
    }
  }

private:
  std::map<std::string,std::string> city_to_country;
  std::set<std::string> ambiguous_cities;
};


int main(){

  Cities cities;
  bool success;
  std::string message;
  std::tie(success, message) = cities.FindContry("Volgograd");

  //more modern ways
  auto [success1, message1] = cities.FindContry("Astana");

  std::cout << message << '\n';

  std::cout << message1 << '\n';

  return 0;

}
