#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//约瑟夫环的实现
using namespace std;
void creat(int , int);
typedef struct node 
{
	int num;
	int data;
	struct node* next;
}Node;


int main() {
    int n, m;
    cout << "请输入总人数为：" << endl;
    cin >> n ;
    cout << "报的数字为：" << endl;
    cin >> m;
    creat(n, m);//创建环
    return 0;
}

void creat(int n, int a) {
    int m = a;//刚开始的终止点
    int flag = 1;
    Node *head, *p, *r;
    head = (Node *)malloc(sizeof(Node));
    head->num = 1;
    head->data = 1;
    head->next = NULL;
    r = head;
    srand((unsigned)time(NULL));
    for(int i = 2; i <= n; i++) {
        p = (Node*)malloc(sizeof(Node));
        p->num = i;//指定每个人的序号
        p->data = rand()%n + 1;//使用随机函数指定数字
        p->next = NULL;
        r->next = p;
        r = p;
    }
    r->next = head;//创建循环链表
    cout << "第一个报数的人的序号为：" << endl;
    //采用随机数函数随机指定一个号码number
    int number = rand()%n + 1;
    cout << number << endl;

    for (int i = 1; i < number; i++) {
        head = head->next;//更改头结点的位置
    }

    while(flag < n) {
        for (int i = 1; i < m; i++) {
            r = head;
            head = head->next;
        }
        cout << head->num << ":" << head->data << endl;
        m = head->data;
        Node *temp = head; //及时删除，防止出现内存泄漏问题
        r->next = head->next;
        head = head->next;
        free(temp);
        flag++;
    }
    cout << head->num << ":" << head->data << endl;
   
}
