// #include <stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<malloc.h>
 
// typedef struct Node  //节点
// {
// 	char data;
// 	struct Node *next;
// }Node,*NodePtr;
 
// typedef struct Stak		//栈链表
// {
// 	NodePtr top;
// 	NodePtr bot;
// 	int count;
// }Stak;
 
// //初始化栈
// void InitStak(Stak *ts)		
// {
// 	ts->top = (NodePtr)malloc(sizeof(Node));
// 	if (NULL == ts->top)
// 	{
// 		printf("分配失败");
// 		exit(-1);
// 	}
// 	ts->bot = ts->top;
// 	ts->count = 0;
// 	ts->top->next = NULL;
	
// }
 
// //入栈
// void Push(Stak *S, char e)		
// {
// 	NodePtr pnew = (NodePtr)malloc(sizeof(Node));
// 	pnew->data = e;
// 	pnew->next = S->top;
// 	S->top = pnew;
// 	S->count++;
 
// }
 
// //出栈
// char Pop(Stak *S)		
// {
	
// 	NodePtr p;
// 	if (S->bot == S->top)
// 	{//空时返回1 删除失败
// 		exit(1);
// 	}
// 	p = S->top;
// 	char e = p->data;
// 	S->top = S->top->next;
// 	free(p);
// 	S->count--;
// 	return e;
 
// }
 
// //打印栈
// void prin(Stak *S)
// {
// 	NodePtr p;
// 	p = S->top;
 
// 	while (p != S->bot)
// 	{
// 		printf("%c\n",p->data);
// 		p = p->next;
// 	}
// }
 
// bool EmptyStack(Stak *S)
// //判断是否空栈
// {
// 	if (S->count == 0)
// 		return 1;
// 	return 0;
// }
 
// typedef struct QNode	//队列节点
// {
// 	char data;
// 	struct QNode *next;
// }QNode,*QNodePtr;
 
// typedef struct LinkQueue	//队列链表
// {
// 	QNodePtr front, rear;
// }Queue;
 
// //队列初始化
// void InitQue(Queue *Q)
// {
// 	QNodePtr p = (QNodePtr)malloc(sizeof(QNode));	//p为头节点
// 	p->data = NULL;
// 	p->next = NULL;
// 	Q->front = p;
// 	Q->rear = p;
// }
 
// //入队列
// void EnQue(Queue *Q, char e)
// {
// 	QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
// 	p->data = e;
// 	p->next = NULL;
// 	Q->rear->next = p;
// 	Q->rear = p;
// }
 
// char DeQue(Queue *Q)
// //出队列
// {
// 	QNodePtr p;
// 	char c;
// 	if (Q->front == Q->rear)
// 	{//空时
// 		exit(1);
// 	}
// 	p = Q->front->next;
// 	c = Q->front->next->data;
// 	Q->front->next = p->next;
// 	if (p == Q->rear)
// 	{
// 		Q->rear = Q->front;
// 	}
// 	free(p);
 
// 	return c;
// }
 
// void pri(Queue *Q)
// //打印队列
// {
// 	QNodePtr p;
// 	p = Q->front;
// 	if (p != NULL)
// 	{
// 		while (p != Q->rear)
// 		{
// 			printf("%c", p->next->data);
// 			p = p->next;
// 		}
// 	}
	
// }
 
// bool EmptyQue(Queue *Q)
// {
// 	if (Q->front == Q->rear)
// 		return 1;
// 	return 0;
// }
 
// void Reverse(char M[], Stak *S)
// {
// 	int i;
// 	int len = strlen(M);
// 	int l = 0, r = 0;
// 	for (i =0; i <len; i++)
// 	{
// 		Push(S, M[i]);
// 		if (M[i] == '(')
// 			l++;
// 		if (M[i] == ')')
// 			r++;
// 	}
// 	if (l != r)
// 		exit(1);
// }
 
// void EnA(Queue *Q)
// //规则1
// {
// 	EnQue(Q, 's');
// 	EnQue(Q, 'a');
// 	EnQue(Q, 'e');
// }
 
// void EnB(Queue *Q)
// //规则1
// {
// 	EnQue(Q, 't');
// 	EnA(Q);
// 	EnQue(Q, 'd');
// 	EnA(Q);
// }
 
// void  Fpri(Queue *Q)
// {
// 	char c;
// 	while (!EmptyQue(Q))
// 	{
// 		c = DeQue(Q);
// 		switch (c)
// 		{
//             case 't':printf("天"); break;
//             case 'd':printf("地"); break;
//             case 's':printf("上"); break;
//             case 'a':printf("一只"); break;
//             case 'e':printf("鹅"); break;
//             case 'z':printf("追"); break;
//             case 'g':printf("赶"); break;
//             case 'x':printf("下"); break;
//             case 'n':printf("蛋"); break;
//             case 'h':printf("恨"); break;
//             default: printf("Error");

//             // case 't':printf("t"); break;
//             // case 'd':printf("d"); break;
//             // case 's':printf("s"); break;
//             // case 'a':printf("a"); break;
//             // case 'e':printf("e"); break;
//             // case 'z':printf("z"); break;
//             // case 'g':printf("g"); break;
//             // case 'x':printf("x"); break;
//             // case 'n':printf("n"); break;
//             // case 'h':printf("h"); break;
//             // default: printf("Error");
//         }
 
// 	}
// }
 
// void Tran(Stak *Sbe,Stak *Saf,Queue *Q )
// {
// 	char c;
// 	char d;
// 	int i=0;
// 	while (Sbe->count != 0)
// 	{
// 		c = Pop(Sbe);
// 		if (c == ')')
// 		    i = Saf->count;
// 		else if (c == '(')
// 		{
// 			int j = Saf->count;
// 			while ( j > i )
// 			{
// 				d = Pop(Saf);
// 				EnQue(Q, d);
// 				j--;
// 			}
// 			char e = Q->front->next->data;
// 			DeQue(Q);
// 			while (!EmptyQue(Q))
// 			//规则2
// 			{
// 				char dl = DeQue(Q);
// 				Push(Saf, e);
// 				Push(Saf, dl);
// 			}
// 			Push(Saf, e);
// 		}
// 		else
// 			Push(Saf, c);
// 	}
 
// 	while (Saf->count>0)
// 	{
// 		char en;
// 		en = Pop(Saf);
// 		if (en == 'A')
// 			EnA(Q);
// 		else if (en == 'B')
// 			EnB(Q);
// 		else
// 			EnQue(Q,en);
// 	}
// 	Fpri(Q);
// }
 
 
// int main() 
// {
// 	Stak Sf,St;
// 	InitStak(&Sf);
// 	InitStak(&St);
// 	Queue Qu1;
// 	InitQue(&Qu1);
// 	char M[] = "B(ehnxgz)B";
// 	Reverse(M, &Sf);
// 	Tran(&Sf, &St, &Qu1);
// 	getchar();
// 	return 0;
// }

#include <bits/stdc++.h>
#include <stack>
using namespace std;
string ans;
string s;//全局变量
void change();//规则1
string find();//规则2
void dfs(int);//递归去除括号
void translate();//翻译魔王语言
int main () {
	cout << "请输入魔王语言" << endl;
	cin >> s;
	change();//利用规则一进行大写转化成小写
	string now = find(); //利用规则2去除括号
	ans = now;
	cout << "整理之后的魔王语言是：" << ans << endl;
	cout << "魔王语言的翻译为：" << endl;
	translate(); 
}
void change() {
	string news = "";//临时存储变量
	for (int i = 0; i< s.length(); i++) {
		if (s[i] == 'B') {
			news += "tAdA";
		} else {
			news += s[i];
		}
	}
	s = "";
	for (int i = 0; i < news.length(); i++) {
		if (news[i] == 'A') {
			s += "sae";
		} else {
			s += news[i];
		}
	}
}
string find() {
	string answe = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			dfs(i);
		} else {
			answe += s[i];
		}
	}
	return answe;
}
void dfs(int pos) {
	stack<char> t;
	char s1 = s[pos+1];
	int tail;
	for (int i = pos + 2; i < s.length(); i++) {
		if (s[i] == '(') {
			dfs(i);
		} else if (s[i] == ')') {
			tail = i;
			break;
		} else {
			t.push(s[i]);
		}
	}
	string p1 = s.substr(0, pos+1);
	string p2 = s.substr(tail + 1, s.length());
	string p3 = "";
	while (!t.empty()) {
		p3+=s1;
		p3+=t.top();
		t.pop();
	}
	p3+=s1;
	s = p1+p2+p3;
}
void translate() {
	for(int i = 0;i<ans.length();i++){
        if(ans[i] == 't'){
            cout<<"天";
        } else if(ans[i] == 'd'){
            cout<<"地";
        } else if(ans[i] == 's'){
            cout<<"上";
        } else if(ans[i] == 'a'){
            cout<<"一只";
        } else if(ans[i] == 'e'){
            cout<<"鹅";
        } else if(ans[i] == 'z'){
            cout<<"追";
        } else if(ans[i] == 'g'){
            cout<<"赶";
        } else if(ans[i] == 'x'){
            cout<<"下";
        } else if(ans[i] == 'n'){
            cout<<"蛋";
        } else if(ans[i] == 'h'){
            cout<<"恨";
        }
}
}