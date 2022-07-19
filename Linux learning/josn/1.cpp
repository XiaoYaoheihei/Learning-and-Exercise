// #include <iostream>
// #include <string>
// // 使用 nlohmann_json 库只需包含即可, 无需链接
// #include <nlohman/json.hpp>
// namespace OVL {
// // 注意 From_Json 函数 To_Json 对象必须在同一 namespace 中
// class User {
// public:
//     std::string name;
//     uint64_t age;
//     std::string number;
//     std::string password;// JSON => class
// static void From_Json (const nlohmann::json& jn, User& user) {
//     jn.at("name").get_to(user.name);
//     jn.at("age").get_to(user.age);
//     jn.at("number").get_to(user.number);
//     jn.at("password").get_to(user.password);
// }
// // class => JSON
// static void To_Json (nlohmann::json& jn, const User& user) {
//     jn = nlohmann::json{
//     {"name", user.name},
//     {"age", user.age},
//     {"number", user.number},
//     {"password", user.password}
//     };
// }
// void PrintInfo() {
//     printf("name = %s\nage = %ld \nnumber = %s \npassword = %s\n", \
//     name.c_str(), age, number.c_str(), password.c_str());
// }
// };
// }

// int main(void) {
//     // 1. 在序列化字符串之后加入 _json后缀.
//     nlohmann::json jn_1 = "{\"name\": \"xiao_hong\", \
//     \"age\": 12, \
//     \"number\": \"123\", \
//     \"password\": \"456\" }"_json;
//     OVL::User xiao_hong;
//     OVL::User::From_Json(jn_1, xiao_hong);
//     xiao_hong.PrintInfo();
// // 3. 直接构造
//     nlohmann::json jn_3 {
//     { "name", "xiao_lan"},
//     { "age", 12},
//     { "number", "123"},
//     { "password", "123"}
//     };
// // 2. 显示的调用 json::parse 推荐
//     auto jn_2 = nlohmann::json::parse(R"(
//     {
//     "name": "xiao_ming",
//     "age": 12,
//     "number": "123",
//     "password": "234"
//     }
//     )");
//     OVL::User xiao_ming;
//     OVL::User::From_Json(jn_2, xiao_ming);
//     xiao_ming.PrintInfo();
//     nlohmann::json xiao_ming_json;
//     OVL::User::To_Json(xiao_ming_json, xiao_ming);
//     // nlohmann::json.dump 函数返回一个 json 字符串
//     std::string xiao_ming_json_string = xiao_ming_json.dump();
//     printf("%s\n", xiao_ming_json_string.c_str());
// /*
// * 当然我们也可以直接更改json 对象的某一个字段
// * at 方法, 当字段不存在时会抛出一个 out_of_range异常
// */
//     xiao_ming_json["name"] = "xiao_gang";
//     xiao_ming_json.at("name") = "xiao_gang";
// /*
// * 查找
// */
//     auto find_obj = xiao_ming_json.find("password");
// // 直接访问
//     std::cout << xiao_ming_json["password"] << " " << find_obj.key() << std::endl;
//     return 0;
// }

#include <iostream>
#include <unordered_map>
#include <nlohman/json.hpp>
#include <leveldb/db.h>
using json = nlohmann::json;

int main()
{
    // create a JSON value with different types
    // json json_types =
    // {
    //     {"boolean", true},
    //     {
    //         "number", {
    //             {"integer", 42},
    //             {"floating-point", 17.23}
    //         }
    //     },
    //     {"string", "Hello, world!"},
    //     {"array", {1, 2, 3, 4, 5}},
    //     {"null", nullptr}
    // };

    // // use explicit conversions
    // auto v1 = json_types["boolean"].get<bool>();
    // auto v2 = json_types["number"]["integer"].get<int>();
    // auto v3 = json_types["number"]["integer"].get<short>();
    // auto v4 = json_types["number"]["floating-point"].get<float>();
    // auto v5 = json_types["number"]["floating-point"].get<int>();
    // auto v6 = json_types["string"].get<std::string>();
    // auto v7 = json_types["array"].get<std::vector<short>>();
    // auto v8 = json_types.get<std::unordered_map<std::string, json>>();

    // // print the conversion results
    // std::cout << v1 << '\n';
    // std::cout << v2 << ' ' << v3 << '\n';
    // std::cout << v4 << ' ' << v5 << '\n';
    // std::cout << v6 << '\n';



    std::string jn_1= R"(
                {
                    "useid":"11111111",
                    "usename":"yeye",
                    "password":"11111111",
                    "friends":["nobody"]
                }
                )";
    // //解析  
    //auto jn_2 = nlohmann::ordered_json::parse(jn_1);
    // std::cout << std::setw(2) << jn_2 << std::endl;
    // auto v = jn_2["useid"].get<std::string>();
    // std::cout << v << std::endl;

    leveldb::DB *db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/home/xiaoyao/database", &db);
    if(status.ok()) {
        std::cout << status.ToString() << std::endl;
    }

    leveldb::Slice key("1111");
    std::string value = jn_1;
    status = db->Put(leveldb::WriteOptions(), key, value);
    if (status.ok()) {
        std::cout << "key: " << key.ToString() << "\n" << "value: " << value << "\n写入成功。" << std::endl;
    }
    auto jn_2 = nlohmann::ordered_json::parse(jn_1);
    std::cout << std::setw(2) << jn_2 << std::endl;
    
    return 0;
}
