#include <iostream>
#include <stdio.h>
#include <nlohman/json.hpp>
//首先声明作用域
using ordered_json = nlohmann::ordered_json;

int main()
{
    // ordered_json j1;
    // //nlohmann::json j;
    // j1["one"] = 1;
    // j1["two"] = 2;
    // j1["three"] = 3;

    // //其中的一种序列化函数
    // std::cout << j1.dump() << std::endl;
    // std::cout << j1.dump(-1) << std::endl;
    // std::cout << j1.dump(0) << std::endl;
    // std::cout << j1.dump(2) << '\n';
    // //第二种序列化函数
    // auto j2 = to_string(j1);
    // std::cout << j2 << std::endl;
    
    //创建一个有序的josn对象
    ordered_json j =
    {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {
            "answer", {
                {"everything", 42}
            }
        },
        {"list", {1, 0, 2}},
        {
            "object", {
                {"currency", "USD"},
                {"value", 42.99}
            }
        }
    };

    // add new values
    j["new"]["key"]["value"] = {"another", "list"};

    // count elements
    auto s = j.size();
    j["size"] = s;

    j["list"] = {0, 2};
    // josn对象序列化
    auto j_str = to_string(j);
    
    std::cout << j << '\n';
    // pretty print with indent of 4 spaces
    std::cout << std::setw(4) << j << '\n';
    //std::cout << j << '\n';
    std::cout << j_str << std::endl;
}
// #include <iostream>
// #include<stdio.h>
// #include <nlohman/json.hpp>

// using json = nlohmann::json;
// int main() {
//     // a JSON text
//     char text[] = R"(
//     {"Image": {"Width":  800,"Height": 600,
//         "Title":  "View from 15th Floor",
//         "Thumbnail": {
//         "Url":    "http://www.example.com/image/481989943",
//         "Height": 125,"Width":  100
//         },
//         "Animated" : false,"IDs": [116, 943, 234, 38793]
//         }
//     }
//     )";
//     printf("%s\n", text);
//     // parse and serialize JSON
//     json j_complete = json::parse(text);
//     std::cout << std::setw(4) << j_complete << "\n\n";
//     return 0;

// }


// #include <iostream>
// #include <stdio.h>
// #include <nlohman/json.hpp>

// using json = nlohmann::json;
// int main () {
//     json j1;
//     //nlohmann::json j;
//     j1["one"] = 1;
//     j1["two"] = 2;
//     j1["three"] = 3;

//     std::cout << j1 << std::endl;
//     std::cout << std::setw(4) << j1 << std::endl;
// }




