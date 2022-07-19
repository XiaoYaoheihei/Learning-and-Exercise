# josn是什么  
具体的解释可以自行查看文档。我只说说自己的理解：josn其实就是一种数据传输时候的交换格式（一种便于理解的规则限制），我们在写数据的时候必须依照josn规定的形式来写数据。  
# 为什么要使用josn  
其实我相信各位通过查询相关的资料也可以找到答案的，在这里我就不多赘述了。  
# josn的数据类型                   
- null:表示为null
- boolean：表示为true或者false  
- number:一般的浮点数表示方式
- string:表示为"..."
- 数组：表示为[...]
- object:表示为{...}，一种键值对的方式

# 如何使用
``首先我使用的第三方库是#include <nlohman/json.hpp>``   
``具体可以查看：https://github.com/nlohmann/json``  
- 创建一个json对象  
**1.ordered_json j；**  
创建一个有序的json对象，到时候输出的时候，会按照创建时候的顺序输出。   
```
#include <iostream>
#include <stdio.h>
#include <nlohman/json.hpp>
//首先声明作用域
using ordered_json = nlohmann::ordered_json;

int main()
{
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
    std::cout << j << '\n';
    // pretty print with indent of 4 spaces
    std::cout << std::setw(4) << j << '\n';

}
``` 
**2.json j;**  
创建一个json对象，但是在输出的时候对象内部的顺序会进行调整。
```
#include <iostream>
#include <stdio.h>
#include <nlohman/json.hpp>

using json = nlohmann::json;
int main () {
    json j1;
    //nlohmann::json j;
    j1["one"] = 1;
    j1["two"] = 2;
    j1["three"] = 3;

    std::cout << j1 << std::endl;
    std::cout << std::setw(4) << j1 << std::endl;

}
```
- 添加一个元素  
``可以直接在[]中访问josn中的内容进行添加或者修改``    
```
#include <iostream>
#include <stdio.h>
#include <nlohman/json.hpp>
//首先声明作用域
using ordered_json = nlohmann::ordered_json;

int main()
{
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
    std::cout << std::setw(4) << j << '\n';
    }

```
- 修改一个元素
```
增加中的代码部分稍加修改就可以使用了
j["list"] = {0, 2};
```
- 删除一个元素
```

```
- 获取一个元素  
```

```
- josn序列化  
``通俗讲呢：对象序列化就是指将对象的状态转换为字符串，然后使用固定的函数打印出来``  
序列化函数1：dump(indent)   
``一般简单的使用的话，只要指定一个参数就好了。``   
``如果 indent是非负数，则数组元素和对象成员将使用该缩进级别进行漂亮打印。缩进级别 0只会插入换行符-1（默认）选择最紧凑的表示。``  
```
#include <iostream>
#include <stdio.h>
#include <nlohman/json.hpp>
//首先声明作用域
using ordered_json = nlohmann::ordered_json;

int main()
{
    ordered_json j1;
    //nlohmann::json j;
    j1["one"] = 1;
    j1["two"] = 2;
    j1["three"] = 3;

    //其中的一种序列化函数
    std::cout << j1.dump() << std::endl;
    std::cout << j1.dump(-1) << std::endl;
    std::cout << j1.dump(0) << std::endl;
    std::cout << j1.dump(2) << '\n';
}
```
序列化函数2：to_string()
``很简单，也没有参数，直接转化成字符串``  
```
#include <iostream>
#include <stdio.h>
#include <nlohman/json.hpp>
//首先声明作用域
using ordered_json = nlohmann::ordered_json;

int main()
{
    ordered_json j1;
    //nlohmann::json j;
    j1["one"] = 1;
    j1["two"] = 2;
    j1["three"] = 3;
    //第二种序列化函数
    auto j2 = to_string(j1);
    std::cout << j2 << std::endl;
```

- josn解析
``将对象转换成josn格式``  
``parse();``  
**首先我们写一个具有josn格式的文本字符串，再使用parse()函数将其转换成josn对象，此对象有规定的格式，可以自行调整文本顺序，再最后观察输出的josn对象的格式。**  
```
#include <iostream>
#include<stdio.h>
#include <nlohman/json.hpp>

using json = nlohmann::json;
int main() {
    // a JSON text
    char text[] = R"(
    {
        "Image": {
        "Width":  800,
        "Height": 600,
        "Title":  "View from 15th Floor",
        "Thumbnail": {
        "Url":    "http://www.example.com/image/481989943",
        "Height": 125,
        "Width":  100
        },
        "Animated" : false,
        "IDs": [116, 943, 234, 38793]
        }
    }
    )";
    printf("%s\n", text);
    // parse and serialize JSON
    json j_complete = json::parse(text);
    std::cout << std::setw(4) << j_complete << "\n\n";
    return 0;

}
```   
``关于开头的R"(),可以把他理解成一种标记，是专门标记这里的josn text``  



