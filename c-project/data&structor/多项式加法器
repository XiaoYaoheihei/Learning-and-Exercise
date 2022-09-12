#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <stack>
//多项式加法器的实现
using namespace std;
void to_symbol(string&, string&);
void to_answer(string&);

int main() {
    cout << "请输入您的多项式运算式子：" << endl;
    string s, symbol;//一个存中缀，一个存后缀
    cin >> s;
    to_symbol(s, symbol);//中缀转后缀
    to_answer(symbol);//后缀计算结果
    return 0;
}

void to_symbol(string& s1, string& s2) {
    int len = s1.size();
    int i;
    unordered_map<char, int> priority; //运算符优先级
    priority['*'] = 1;
    priority['/'] = 1;
    priority['+'] = 2;
    priority['-'] = 2;
    stack<char> op;//存储符号的栈

    while (i < len) {//开始遍历中缀中的每一项
        if (s1[i] > '0' && s1[i] < '9') {//是数字的话
            s2.push_back(s1[i]);
        } else {//运算符
            if (s1[i] == '(') {//左括号
                op.push(s1[i]);
            } else if (s1[i] == ')') {//右括号
                while (op.empty() != 0 && op.top() != '(') {
                    s2.push_back(op.top());
                    op.pop();
                }
                op.pop();//将"("出栈
            } else {//算数运算符
                while (op.empty()!= 0 && op.top() != '(' && priority[s1[i]] >= priority[op.top()]) {
                    s2.push_back(op.top());
                    op.pop();
                }
                op.push(s1[i]);
            }
        }
        i++;
    }
    while (op.empty() != 0) {//将剩余符号栈中的所有符号全部存入s2中
        s2.push_back(op.top());
        op.pop();
    }
}

void to_answer(string& s) {
    cout << s << endl;
    stack<int> number;
    int len = s.size(), temp;
    for (int i = 0;i < len; i++) {
        if (s[i] > '0' && s[i] < '9') {
            number.push(s[i] - '0');
        } else {
            if (s[i] == '+') {
                auto tail = number.top();
                number.pop();
                auto front = number.top();
                number.pop();
                temp = front + tail;
                number.push(temp); 
            } else if (s[i]== '-') {
                auto tail = number.top();
                number.pop();
                auto front = number.top();
                number.pop();
                temp = front - tail;
                number.push(temp); 
            } else if (s[i] == '*') {
                auto tail = number.top();
                number.pop();
                auto front = number.top();
                number.pop();
                temp = front * tail;
                number.push(temp); 
            } else if (s[i] == '/') {
                auto tail = number.top();
                number.pop();
                auto front = number.top();
                number.pop();
                temp = front / tail;
                number.push(temp); 
            }
        }
    }
    cout << "最后的结果为：" << number.top() << endl;
    //使用迭代器的方法
    /*for(auto i = s.begin(); i; i++) {

    }*/
}
