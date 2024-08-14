#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
//using namespace std
using json = nlohmann::json;

int main(){
    std::ifstream f("example.json");
    json data = json::parse(f);
    std::cout << data["answer"] << std::endl;

    json ex1 = json::parse(R"(
        {
          "pi": 3.141,
          "happy": true
        }
    )");

    // Using user-defined (raw) string literals
    // using namespace nlohmann::literals;
    // json ex2 = R"(
    //   {
    //     "pi": 3.141,
    //     "happy": true
    //   }
    // )"_json;
    
    // Using initializer lists
    json ex3 = {
      {"happy", true},
      {"pi", 3.141},
    };
    
    std::cout << ex3["pi"] << std::endl;

    return 0;
}

