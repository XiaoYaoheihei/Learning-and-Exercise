// #include <stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<malloc.h>
 
// typedef struct Node  //�ڵ�
// {
// 	char data;
// 	struct Node *next;
// }Node,*NodePtr;
 
// typedef struct Stak		//ջ����
// {
// 	NodePtr top;
// 	NodePtr bot;
// 	int count;
// }Stak;
 
// //��ʼ��ջ
// void InitStak(Stak *ts)		
// {
// 	ts->top = (NodePtr)malloc(sizeof(Node));
// 	if (NULL == ts->top)
// 	{
// 		printf("����ʧ��");
// 		exit(-1);
// 	}
// 	ts->bot = ts->top;
// 	ts->count = 0;
// 	ts->top->next = NULL;
	
// }
 
// //��ջ
// void Push(Stak *S, char e)		
// {
// 	NodePtr pnew = (NodePtr)malloc(sizeof(Node));
// 	pnew->data = e;
// 	pnew->next = S->top;
// 	S->top = pnew;
// 	S->count++;
 
// }
 
// //��ջ
// char Pop(Stak *S)		
// {
	
// 	NodePtr p;
// 	if (S->bot == S->top)
// 	{//��ʱ����1 ɾ��ʧ��
// 		exit(1);
// 	}
// 	p = S->top;
// 	char e = p->data;
// 	S->top = S->top->next;
// 	free(p);
// 	S->count--;
// 	return e;
 
// }
 
// //��ӡջ
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
// //�ж��Ƿ��ջ
// {
// 	if (S->count == 0)
// 		return 1;
// 	return 0;
// }
 
// typedef struct QNode	//���нڵ�
// {
// 	char data;
// 	struct QNode *next;
// }QNode,*QNodePtr;
 
// typedef struct LinkQueue	//��������
// {
// 	QNodePtr front, rear;
// }Queue;
 
// //���г�ʼ��
// void InitQue(Queue *Q)
// {
// 	QNodePtr p = (QNodePtr)malloc(sizeof(QNode));	//pΪͷ�ڵ�
// 	p->data = NULL;
// 	p->next = NULL;
// 	Q->front = p;
// 	Q->rear = p;
// }
 
// //�����
// void EnQue(Queue *Q, char e)
// {
// 	QNodePtr p = (QNodePtr)malloc(sizeof(QNode));
// 	p->data = e;
// 	p->next = NULL;
// 	Q->rear->next = p;
// 	Q->rear = p;
// }
 
// char DeQue(Queue *Q)
// //������
// {
// 	QNodePtr p;
// 	char c;
// 	if (Q->front == Q->rear)
// 	{//��ʱ
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
// //��ӡ����
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
// //����1
// {
// 	EnQue(Q, 's');
// 	EnQue(Q, 'a');
// 	EnQue(Q, 'e');
// }
 
// void EnB(Queue *Q)
// //����1
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
//             case 't':printf("��"); break;
//             case 'd':printf("��"); break;
//             case 's':printf("��"); break;
//             case 'a':printf("һֻ"); break;
//             case 'e':printf("��"); break;
//             case 'z':printf("׷"); break;
//             case 'g':printf("��"); break;
//             case 'x':printf("��"); break;
//             case 'n':printf("��"); break;
//             case 'h':printf("��"); break;
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
// 			//����2
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
string s;//ȫ�ֱ���
void change();//����1
string find();//����2
void dfs(int);//�ݹ�ȥ������
void translate();//����ħ������
int main () {
	cout << "������ħ������" << endl;
	cin >> s;
	change();//���ù���һ���д�дת����Сд
	string now = find(); //���ù���2ȥ������
	ans = now;
	cout << "����֮���ħ�������ǣ�" << ans << endl;
	cout << "ħ�����Եķ���Ϊ��" << endl;
	translate(); 
}
void change() {
	string news = "";//��ʱ�洢����
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
            cout<<"��";
        } else if(ans[i] == 'd'){
            cout<<"��";
        } else if(ans[i] == 's'){
            cout<<"��";
        } else if(ans[i] == 'a'){
            cout<<"һֻ";
        } else if(ans[i] == 'e'){
            cout<<"��";
        } else if(ans[i] == 'z'){
            cout<<"׷";
        } else if(ans[i] == 'g'){
            cout<<"��";
        } else if(ans[i] == 'x'){
            cout<<"��";
        } else if(ans[i] == 'n'){
            cout<<"��";
        } else if(ans[i] == 'h'){
            cout<<"��";
        }
}
}