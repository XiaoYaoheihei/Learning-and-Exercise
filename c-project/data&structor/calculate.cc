#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>
#include <stack>
//����ʽ�ӷ�����ʵ��
using namespace std;
void to_symbol(string&, string&);
void to_answer(string&);

int main() {
    cout << "���������Ķ���ʽ����ʽ�ӣ�(��������=)" << endl;
    string s, symbol;//һ������׺��һ�����׺
    cin >> s;
    to_symbol(s, symbol);//��׺ת��׺
    to_answer(symbol);//��׺������
    return 0;
}

void to_symbol(string& s1, string& s2) {
    int len = s1.size();
    // cout << "len = " << len << endl;
    unordered_map<char, int> priority; //��������ȼ�
    priority['*'] = 1;
    priority['/'] = 1;
    priority['+'] = 2;
    priority['-'] = 2;
    stack<char> op;//�洢���ŵ�ջ
    for (int i = 0; i < len; i++) {//��ʼ������׺�е�ÿһ��
        if (s1[i] > '0' && s1[i] < '9') {//�����ֵĻ�
            // cout << i << s1[i] << endl;
            s2.push_back(s1[i]);
        } else {//�����
            if (s1[i] == '(') {//������
                op.push(s1[i]);
            } else if (s1[i] == ')') {//������
                while (!op.empty() && op.top() != '(') {
                    s2.push_back(op.top());
                    op.pop();
                }
                op.pop();//��"("��ջ
            } else {//���������
                // cout << i << s1[i] << endl;
                while (!op.empty() && op.top() != '(' && priority[s1[i]] >= priority[op.top()]) {
                    s2.push_back(op.top());
                    op.pop();
                }
                op.push(s1[i]);
                // cout << op.top() << endl;
            }
        }
    }
    // cout << op.empty() << endl;
    while (!op.empty()) {//��ʣ�����ջ�е����з���ȫ������s2��
        s2.push_back(op.top());
        op.pop();
    }
}

void to_answer(string& s) {
    cout << "��׺���ʽΪ:" << s << endl;
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
    cout << "���Ľ��Ϊ��" << number.top() << endl;
}
