#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pass{
	char zhang[20];
	char word[20];
	struct pass *next;
}*m;

typedef struct users {	//登陆的帐号以及密码 
	char zhang[50];
	char word[50];
	struct users* next;
}*node1;

typedef struct list {	//店面界面的信息 
	char name[20];		//汉字一个字占两个字节 
	char number[20];	//序号
	int perfor;			//业绩
	struct list *next;
}*s;

void com();	//公司负责人登陆之后的主界面 
void save_inf3 (struct list *h, char *s); //保存基本信息到指定文件当中去（专属于2和3的 
void fenxi(struct list *h); //成绩分析并打印出来你的成绩地位 
void save_inf2 (struct list *h) ;//保存基本信息到指定文件当中去（专属于另一个文件的 
struct list *creat_inf();	//尾插法建立数据单链表
void save_inf1(struct list *h, char *s);	//保存基本信息到指定文件当中去（专属增加的 
struct list *read(char *s);	//从指定文件中读取信息
void print_inf1 (struct list *h);	//打印并且显示单链表中的基本信息 

void fencom();	//分公司登陆之后的主界面 
void fenxi_stu(struct list *h);			//业绩分析 
int judge (int a, int b); 		//要给说的话 
struct list *creat_inf();	//尾插法建立数据单链表
void save_inf(struct list *h);	//保存基本信息到指定文件当中去
struct list *read_inf1(char *s);	//从指定文件中读取信息
void print_inf (struct list *h);	//打印并且显示单链表中的基本信息 

void guanliyuan();	//管理员登录的界面 
void add();				//增加账号以及密码 
struct pass *creat1();	//尾插法建立数据单链表
void save1(struct pass *h);	//保存基本信息到指定文件当中去
struct pass *read1();	//从指定文件中读取信息
void print1(struct pass *h);	//打印并且显示单链表中的基本信息 
void delate();
void save2 (struct pass *h);	//把文件里面的密码全部删除掉 
void xiugai();					//修改账号以及密码 
void find_pass();		//查找账号及密码 
void restart();			//录入所有账号及密码 
void shuchu();			//输出所有账号 
void handshu();			//手动重新输入学生信息 
void menu();			//返回上一层菜单 
void save(struct pass *h);//保存基本信息到指定文件当中去
void save1(struct pass *h) ;//保存基本信息到指定文件当中去
struct list *creat_inf5();	//尾插法建立数据单链表
void save_inf5(struct list *h);	//保存基本信息到指定文件当中去
struct list *read_inf5();	//从指定文件中读取信息
void print_inf5 (struct list *h);	//打印并且显示单链表中的基本信息 
void find_op() ; //查看申诉内容
void menu();		//主界面
void fencom_login();
void com_login();
void guanli_login();
void fencom_regis();
void com_regis();
struct users *readz();
void save_zhuce(struct users *h);
void paixu();	//对内容进行排序
struct list* shengxu(struct list *, int );

void guanliyuan() {		//管理员登录的界面
	char password[]="12345";
	char zhanghao[]="12345";
	char zhanghao1[6], password1[6];
	printf("请输入管理员账号：");
	scanf("%s", zhanghao1);
	fflush(stdin);
	printf("请输入管理员密码：");
	scanf("%s", password1);
	fflush(stdin);
	while ((strcmp(password1, password) != 0) && (strcmp(zhanghao1, zhanghao) != 0) && (strlen(zhanghao1) != 5) && (strlen(password1) != 5)) {
		fflush(stdin);
		system("cls");
		printf("\n密码或者账号不正确,请重新输入：\n");
		printf("请输入账号：");
		scanf("%s",zhanghao1);
		printf("请输入密码：");
		scanf("%s",password1);
	}
	fflush(stdin);
	//system("cls");
	printf("\033c");
	int n;
	printf("请选择指令：\n\n");
	printf("            1.    查 看 申 诉 选 项\n\n");
	printf("            2.    进 入 公 司 端 进 行 信 息 修 改\n\n");
	printf("            3.    增 加 账 号 及 密 码\n\n"); 
	printf("            4.    删 除 账 号 及 密 码\n\n"); 
	printf("            5.    修 改 账 号 及 密 码\n\n"); 
	printf("            6.    查 找 账 号 及 密 码\n\n");
	printf("            7.    录 入 所 有 账 号 及 密 码\n\n");
	printf("            8.    输 出 所 有 账 号 及 密 码\n\n");
	//printf("            9.    手 动 录 入 分 店 面 信 息\n\n");
	printf("            9.    返 回 到 上 一 层\n\n");
	//printf("            10.   对 业 绩 进 行 排 序\n\n");
	printf("            0.    退 出\n\n"); 
	printf("请输入指令：");
	scanf("%d", &n);
	while (n < 0 || n > 10) {
		fflush(stdin);
		printf("\033c");
		printf("\n输入了错误的指令(请输入0~9及a的指令)\n");
		printf("请选择指令：\n\n");
		printf("            1.    查 看 申 诉 选 项\n\n");
		printf("            2.    进 入 公 司 端 进 行 信 息 修 改\n\n");
		printf("            3.    增 加 账 号 及 密 码\n\n"); 
		printf("            4.    删 除 账 号 及 密 码\n\n"); 
		printf("            5.    修 改 账 号 及 密 码\n\n"); 
		printf("            6.    查 找 账 号 及 密 码\n\n");
		printf("            7.    录 入 所 有 账 号 及 密 码\n\n");
		printf("            8.    输 出 所 有 账 号 及 密 码\n\n");
		//printf("            9.    手 动 录 入 分 店 面 信 息\n\n");
		printf("            9.    返 回 到 上 一 层\n\n");
		//printf("            10.   对 业 绩 进 行 排 序\n\n");
		printf("            0.    退 出\n\n"); 
		printf("请输入指令：");
		scanf("%d", &n);
	}
	if (n == 0) {
		printf("\033c");
		printf("\n您已退出成功!\n");		
	}
	if (n == 1) {
		find_op();	
	}
	if (n == 2) {	//完成 
		com();
	}
	if (n == 3) {	//完成 
		add();
	}
	if (n == 4) {	//完成 
		delate();
	}
	if (n == 5) {	//正在完成中 
		xiugai();
	}
	if (n == 6) {	//完成 
		find_pass();
	}
	if (n == 7) {	//完成 
		restart();
	}
	if (n == 8) {	//完成 
		shuchu();
	}
	// if (n == 10) {	//完成 
	// 	paixu();
	// }
	if (n == 9) {	//完成 
		menu();
	}
}
void paixu() {
	printf("请输入你要对第几天的业绩进行排序：\n");
	char st[1];
	scanf("%s", st); 
	FILE *fp;
	if (st[0] == '1') {
		if ((fp = fopen("c1.txt","r+")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[0] == '2') {
		if ((fp = fopen("c2.txt","r+")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[0] == '3') {
		if ((fp = fopen("c3.txt","r+")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	}
	if (st[0] == '4') {
		if ((fp = fopen("c4.txt","r+")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[0] == '5') {
		if ((fp = fopen("c5.txt","r+")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	s head = (struct  list*)malloc(sizeof(struct list));
	head->next = NULL;
	s r = head; //记录头结点
	int count = 0;//记录节点数量
	while (feof(fp) == 0) {	//对文件的位置进行更改 
		s stu = (struct list*)malloc(sizeof(struct list));
		fscanf(fp, "%s %s %d\n", stu->name, stu->number, &stu->perfor);
		head->next = stu;
		head = stu; 
		count++;
	}
	head->next = NULL;
	fclose(fp);
	//升序排列
	s pre = shengxu(r->next, count);
	int i = 0;
	while (i < count) {
		printf("%d  ", pre->perfor);
		pre = pre->next;
		i++;
	}
	printf("\n排序完毕,请按回车键返回上一层\n");
	fflush(stdin);
	char ch = getchar();
	guanliyuan();
}

struct list* shengxu(struct list *r, int count) {
	int i, num;
	s qian, hou,tail;
	for (i = 0; i < count - 1; i++) {
		num = count - i - 1;
		qian = r;
		hou = qian->next;
		tail = r;
		while(num--) {
			if (qian->perfor > hou->perfor) {
				qian->next = hou->next;
				hou->next = qian;
				tail->next = hou;
			}
			tail = tail->next;
			qian = tail->next;
			hou = qian->next;
		}
	}
	return r;
}
void find_op() {
	m head1 = (struct pass*)malloc(sizeof(struct pass));
	head1->next = read1();
	print1(head1);
	printf("\n查看完毕,请按回车键返回上一层\n");
	char ch = getchar();
	guanliyuan();
}
void xiugai() {				//修改账号以及密码 
	printf("请选择指令:\n\n");
	printf("1.通过账号修改\n");
	printf("2.通过密码修改\n");
	printf("请输入指令:");
	int q ;
	scanf("%d", &q); 
	while (q < 1 || q > 2) {
		fflush(stdin);
		printf("\033c");
		printf("输入了错误的指令，请输入对应的数字\n");
		printf("请选择指令:\n\n");
		printf("1.通过账号修改\n");
		printf("2.通过密码修改\n");
		printf("请输入指令:");
		scanf("%d", &q); 
	}
	if (q == 1) {	//账号修改 
		char zhang1[20];
		int flag = 0;
		printf("请输入你的账号:\n");
		scanf("%s", zhang1);
		fflush(stdin);
		m head1 = (struct pass*)malloc(sizeof(struct pass));
		m head2 = (struct pass*)malloc(sizeof(struct pass));
		head1->next = read1();
		head2->next = head1;
		while (head1) {
			if (strcmp(head1->zhang, zhang1) == 0) {
				flag = 1;
				break;
			}
			head1 = head1->next;
		}
		if (flag == 0) {
			fflush(stdin);
			printf("不存在此账号\n");
			printf("请按回车键返回上一层\n");
			char ch = getchar();
			guanliyuan();
		} 
			printf("请输入你要修改的账号：\n");
			scanf("%s", zhang1);
			strcpy(head1->zhang, zhang1);
			fflush(stdin);
			save(head2->next);
			guanliyuan();
	}
	if (q == 2) {	//密码修改 
		char zhang1[20];
		char word1[20]; 
		printf("请输入你的密码:\n");
		scanf("%s", word1);
		fflush(stdin);
		int flag = 0;
		m head1 = (struct pass*)malloc(sizeof(struct pass));
		m head2 = (struct pass*)malloc(sizeof(struct pass));
		head1->next = read1();
		head2->next = head1;
		while (head1) {
			if (strcmp(head1->word, word1) == 0) {
				flag = 1;
				break;
			}
			head1 = head1->next;
		}
		if (flag == 0) {
			fflush(stdin);
			printf("此密码对应的账号不存在\n");
			printf("请按回车键返回上一层\n");
			char ch = getchar();
			guanliyuan();
		} else {
			printf("请输入你要修改的密码：\n");
			scanf("%s", word1);
			fflush(stdin);
			strcpy(head1->word, word1);
			save(head2->next);	
			fflush(stdin);
			printf("修改完毕，请按回车键返回上一层\n");
			char ch = getchar();
			guanliyuan();
		}	
	}
	
}
void save(struct pass *h) {//保存基本信息到指定文件当中去
	m stu = h->next;
	FILE *fp;
	if ((fp = fopen("密码.txt","w")) == NULL) {
		printf("打开文件失败");
		exit(0);
	}
	while (stu) {
		fprintf(fp, "%s %s\n", stu->zhang, stu->word);
		stu = stu->next;
	}
	fclose(fp);	
}
void handshu() {		//手动重新输入分公司信息
	printf("请问你要输入哪个分公司的业绩：\n");
	char st[1];
	scanf("%s", st); 
	FILE *fp;
	if (st[1] == '1') {
		if ((fp = fopen("c1.txt","rt")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '2') {
		if ((fp = fopen("c2.txt","rt")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '3') {
		if ((fp = fopen("c3.txt","rt")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	}
	if (st[1] == '4') {
		if ((fp = fopen("c4.txt","rt")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '5') {
		if ((fp = fopen("c5.txt","rt")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
		//printf("打开成功\n");
		s head1, head2;
		head1 = creat_inf();	//创建基本信息链表
		save_inf1(head1, st);		//保存基本信息到指定文件中
		fflush(stdin);
		printf("此功能已经完成，请按回车键返回上一层\n");
		char ch = getchar();
		guanliyuan();
	}
void shuchu() {		//输出所有账号 
	FILE *fp;
	if ((fp = fopen("密码.txt", "r")) == NULL) {
		printf("打开失败");
		exit(0);		//1表示非正常运行导致退出程序，0表示正常运行程序退出程序 
	} else {
		printf("打开成功\n");
		m head1;
		head1 = read1();	//从指定文件中读取信息
		print1(head1);	//打印并且显示单链表中的基本信息 
	}	
		fflush(stdin);
		printf("\n输出完毕,请按回车键返回上一层\n");
		char ch = getchar();
		guanliyuan();
}
void restart() {		//录入所有账号及密码 
	FILE *fp;
	if ((fp = fopen("密码.txt", "a+")) == NULL) {
		printf("打开失败");
		exit(0);		//1表示非正常运行导致退出程序，0表示正常运行程序退出程序 
	} else {
		printf("打开成功\n");
		m head1;
		head1 = creat1();	//创建信息链表
		save1(head1);		//保存基本信息到指定文件中
	}
	fflush(stdin);
	printf("\n录入完毕,请按回车键返回上一层\n");
	char ch = getchar();
	guanliyuan();
}
void find_pass() {		//查找账号及密码 
	m head1;
	head1 = read1();	//从指定文件中读取信息
	print1(head1);	//打印并且显示单链表中的基本信息 
	fflush(stdin);
	printf("\n查找完毕,请按回车键返回上一层\n");
	char ch = getchar();
	guanliyuan();	
}
void delate() {	//删除账号以及密码
	m head2;
	head2 = read1();	//从指定文件中读取信息
	head2 = NULL;
	save2(head2);
	fflush(stdin);
	printf("删除完毕，请按回车键返回上一层\n");
	char ch = getchar();
	guanliyuan();
}
void add () {	//增加账号以及密码 
	FILE *fp;
	if ((fp = fopen("密码.txt", "a+")) == NULL) {
		printf("打开失败");
		exit(0);		//1表示非正常运行导致退出程序，0表示正常运行程序退出程序 
	} else {
		printf("打开成功\n");
		m head1;
		head1 = creat1();	//创建信息链表
		save1(head1);		//保存基本信息到指定文件中
		//head2 = read1();	//从指定文件中读取信息
		//print1(head2);	//打印并且显示单链表中的基本信息 
	}
	fflush(stdin);
	printf("增加完毕，请按回车键返回上一层\n");
	char ch = getchar();
	guanliyuan();
}
struct pass *creat1() {	//尾插法建立数据单链表
	int i = 1;
	m head = (struct pass*)malloc(sizeof(struct pass));
	head->next = NULL;
	m temp = head; 	//记录头结点
	while(i)
	{
		m stu = (struct pass*)malloc(sizeof(struct pass));
		printf("请输入你的账号：\n");
		scanf("%s", stu->zhang);
		printf("请输入你的密码：\n");
		scanf("%s", stu->word);
		head->next = stu;
		head = stu;
		printf("请输入你接下来的操作\n");
		printf("继续输入/停止输入(>0/0)\n");
		fflush(stdin);
		scanf("%d", &i);
	} 
	head->next = NULL;
	return temp;	//返回记录的头结点 
}	
void save1(struct pass *h) {//保存基本信息到指定文件当中去
	m stu = h->next;
	FILE *fp;
	if ((fp = fopen("密码.txt","a+")) == NULL) {
		printf("打开文件失败");
		exit(0);
	}
	while (stu) {
		fprintf(fp, "%s %s\n", stu->zhang, stu->word);
		stu = stu->next;
	}
	fclose(fp);	
}
struct pass *read1() {	//从指定文件中读取信息
	FILE *fp;
	if ((fp = fopen("密码.txt","rt")) == NULL) {
		printf("打开文件失败");
		exit(0);
	}
	m head = (struct pass *)malloc(sizeof(struct pass));
	head->next = NULL;
	m r = head; //记录头结点
	
	while (feof(fp) == 0) {	//对文件的位置进行更改 
		m stu = (struct pass*)malloc(sizeof(struct pass));
		fscanf(fp, "%s %s\n", stu->zhang, stu->word);
		head->next = stu;
		head = stu; 
	}
	head->next = NULL;
	fclose(fp);
	printf("\n文件中的信息已经被正确读出,请按任意键返回！\n");
	//char ch = getchar();
	printf("\033c");
	return r->next;
}
void print1(struct pass *h) {	//打印并且显示单链表中的基本信息 
	m stu = h;
	while (stu) {
		printf("%s %s\n", stu->zhang, stu->word);
		stu = stu->next;
	}
}
void save2 (struct pass *h) {	//把文件里面的密码全部删除掉 
	FILE *fp;
	if ((fp = fopen("密码.txt","w")) == NULL) {
		printf("打开文件失败");
		exit(0);
	}
	fclose(fp);
//	remove("C:\\Users\\Administrator\\Desktop\\coding master\\密码.txt");
//	fp = fopen("C:\\Users\\Administrator\\Desktop\\coding master\\密码.txt","w");
//	fclose(fp);
}
struct list *creat_inf5() {		//创建基本信息链表
	int i = 0;	//记录人的序号 
	char choice;//记录你此时的是否继续操作 
	s head = (struct list *)malloc(sizeof(struct list));
	head->next = NULL;
	s temp = head;//记录头结点 
	
	do {
		s stu = (struct list *)malloc(sizeof(struct list));
		printf("\n\n第%d个人的信息为:\n", ++i);
		printf("店名\t营业执照号码后5位\t业绩\n");
		scanf("%s", stu->name);
		scanf("%s", stu->number);
		//fflush(stdin);
		scanf("%d", &stu->perfor);
		//fflush(stdin);
		head->next = stu;
		head = stu;
		printf("请输入你接下来的操作\n");
		printf("继续输入/停止输入(y/n)\n");
		fflush(stdin);
		choice = getchar();
		printf("\033c");
	}while (choice == 'Y' || choice == 'y');
	head->next = NULL;
	return temp;	//返回记录的头结点 	
}	
void save_inf5 (struct list *h) {//保存基本信息到指定文件当中去
	s stu = h->next;
	FILE *fp;
	if ((fp = fopen("管理系统.txt","w")) == NULL) {
		printf("打开文件失败");
		exit(0);
	}
	while (stu) {
		fprintf(fp, "%s %s %d\n", stu->name, stu->number, stu->perfor);
		stu = stu->next;
	}
	fclose(fp);
}

void fencom() {
	//printf("\033c");
	printf("\n"); 
	char number1[20];
	printf("请再次输入你的序号\n");
	scanf("%s",number1);
	fflush(stdin);
	printf("\033c");
	int ch;
	printf("请选择指令：\n\n");
	printf("            1.    业 绩 查 询\n\n");
	//printf("            2.    查 询 本 月 业 绩\n\n");
	printf("            2.    业 绩 分 析\n\n"); 
	printf("            3.    业 绩 申 诉\n\n"); 
	printf("            4.    返 回 上 一 层\n\n"); 
	printf("            0.    退 出\n\n"); 
	printf("请输入指令：");
	scanf("%d", &ch);
	while (ch < 0 || ch > 4) {
		fflush(stdin);
		printf("\033c");
		printf("输入了错误的指令，请输入对应的数字\n");
		printf("请选择指令：\n\n");
		printf("            1.    业 绩 查 询\n\n");
		//printf("            2.    查 询 本 月 业 绩\n\n");
		printf("            2.    业 绩 分 析\n\n"); 
		printf("            3.    业 绩 申 诉\n\n"); 
		printf("            4.    返 回 上 一 层\n\n"); 
		printf("            0.    退 出\n\n"); 
		printf("请输入指令：");
		scanf("%d", &ch);
	}
	if (ch == 0) {
		printf("\033c");
		printf("您已经成功退出!");
		
	}
	if (ch == 1) {	//自己业绩查询 
		// printf("请选择指令:\n\n");
		// printf("1.输入名字查询\n");
		// printf("2.输入序号查询\n");
		// printf("请输入指令:");
		// int m ;
		// scanf("%d", &m); 
		// while (m < 1 || m > 2) {
		// 	fflush(stdin);
		// 	system("cls");
		// 	printf("输入了错误的指令，请输入对应的数字\n");
		// 	printf("请选择指令:\n\n");
		// 	printf("1.输出名字查询\n");
		// 	printf("2.输入序号查询\n");
		// 	printf("请输入指令:");
		// 	scanf("%d", &m); 
		// }
		// if (m == 1) {	//名字查询 
		// 	char name1[20];
		// 	printf("请输入你的名字:\n");
		// 	scanf("%s",&name1);
		// 	fflush(stdin);
		// 	int flag = 0 ;
		// 	s head2 = (struct list *)malloc(sizeof(struct list));
		// 	s head3 = (struct list *)malloc(sizeof(struct list));
		// 	head2->next = read_inf1();		//从指定文件中读取信息
		// 	head3->next = head2;			//记录结点 
		// 	while (head2) {
		// 		if (strcmp(head2->name, name1) == 0) {
		// 			flag = 1;
		// 			break;
		// 		}
		// 		head2 = head2->next;
		// 	}
		// 	if (flag == 0) {
		// 		printf("不存在此人\n");
		// 		system("cls");
		// 	} else {
		// 		printf("%s %s %s %d %d %d\n", head2->name, head2->number, head2->classm, head2->computer, head2->math, head2->english);
		// 	}
		// 	fflush(stdin);
		// 	printf("请按任意键返回上一层");
		// 	char ch = getchar();
		// 	xuesheng(); 
		// }
		// if (m == 2) {	//序号查询 
		// 	char number1[20];
		// 	printf("请再次输入你的序号\n");
		// 	scanf("%s",&number1);
			int flag = 0;
			s head2 = (struct list *)malloc(sizeof(struct list));
			s head3 = (struct list *)malloc(sizeof(struct list));
			head2->next = read_inf1(number1);		//从指定文件中读取信息
			head3->next = head2;			//记录结点 
				
			while (head2) {
				if (strcmp(head2->number, number1) == 0) {
					flag = 1;
					break;
				}
				head2 = head2->next;
			}
			if (flag == 0) {
				printf("不存在此人\n");
				printf("\033c");
			} else {
				printf("%s %s %d\n", head2->name, head2->number, head2->perfor);
			}
			printf("请按任意键返回上一层");
			char ch = getchar();
			//break;
			fencom(); 
			//返回上一层 
	//	}
	}

/*	if (ch == 2) {	//查询本班成绩
//		char number1[20];
//		printf("请再次输入你的序号\n");
//		scanf("%s",&number1);
		s head2 = read_inf1(number1);		//从指定文件中读取信息
		print_inf (head2);	//打印并且显示单链表中的基本信息 
		fflush(stdin);
		printf("请按任意键返回上一层");
		char ch = getchar();
		fencom();
	}
*/	
	if (ch == 2) {	//成绩分析
//		char number1[20];
//		printf("请再次输入你的序号\n");
//		scanf("%s",&number1);
		s head2 = read_inf1(number1);		//从指定文件中读取信息
		fenxi_stu(head2);			//学生自己的成绩分析 
		fflush(stdin);
		printf("请按任意键返回上一层");
		char ch = getchar();
		printf("\033c");
		fencom();
	}
	
	if (ch == 3) {	//成绩申诉 //在处理意见的时候还没有解决如何换行 
		printf("\033c");
		printf("请输入你要反馈的问题:\n");
		char s[1000000];
		FILE *fp;
		if ((fp = fopen("申诉.txt","a+")) == NULL) {
			printf("打开文件失败\n");
			exit(0);
		}
		scanf("%s", s);
		fflush(stdin);
		fprintf(fp, "%s\n", s);
		fclose(fp);
		printf("感谢您提供的宝贵的意见，我们会即使处理的。\n");
		fflush(stdin);
		printf("请按任意键返回上一层");
		char ch = getchar();
		fencom();
	}

	if (ch == 4) {	
		menu();
	}
}
struct list *read_inf1(char *st) {//从指定文件中读取信息
	FILE *fp;
	if (st[1] == '1') {
		if ((fp = fopen("c1.txt","rt")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '2') {
		if ((fp = fopen("c2.txt","rt")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '3') {
		if ((fp = fopen("c3.txt","rt")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	}
	if (st[1] == '4') {
		if ((fp = fopen("c4.txt","rt")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '5') {
		if ((fp = fopen("c5.txt","rt")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	s head = (struct list *)malloc(sizeof(struct list));
	head->next == NULL;
	s r = head;	//记录头结点
	
	while (feof(fp) == 0) {	//对文件的位置进行更改 
		s stu = (struct list *)malloc(sizeof(struct list));
		fscanf(fp, "%s %s %d\n", stu->name, stu->number, &stu->perfor);
		head->next = stu;
		head = stu; 
	}
	head->next = NULL;
	fclose(fp);
	printf("\n文件中的信息已经被正确读出,请按任意键返回！\n");
	char ch = getchar();
	printf("\033c");
	return r->next;
}	
void print_inf (struct list *h) {//打印并且显示单链表中的基本信息 
	s stu = h;
	while (stu) {
		printf("%s %s %d\n", stu->name, stu->number, stu->perfor);
		stu = stu->next;
	}
}
void fenxi_stu(struct list *h) {			//自己的成绩分析 
	int maxc = 0, cur;
	s stu = h;
	while (stu) {
		if (stu->perfor > maxc) {
			maxc = stu->perfor;
		}
		stu = stu->next;
	}
	printf("请输入你自己的业绩：\n");
	scanf("%d", &cur);
	int i = judge(cur, maxc);
	if (i == 0) {
		printf("业绩太低了哦，还看什么看，还不赶紧滚去干活！！！\n");
		printf("一定要加油哦！！！快赶紧干活！！！\n"); 
	} else {
		printf("再接再厉，为自己打工");
	}
	char ch = getchar();
}
int judge (int a, int b) {	//要给自己说的话 
	if (a > b) {
		return 1;
	}
	else {
		return 0;
	}
}

void com() {	//总公司负责人登陆之后的主界面 
	printf("为了方便查询请再次输入您的账号：\n");
	char number1[20];
	scanf("%s",number1);
	fflush(stdin);
	printf("\033c");
	int ch;
	printf("请选择指令:\n\n");
	printf("            1.    增加新的店面信息\n\n");
	printf("            2.    删除店面信息\n\n");
	printf("            3.    修改店面信息\n\n"); 
	printf("            4.    查询店面信息\n\n"); 
	printf("            5.    输出当天业绩\n\n"); 
	printf("            6.    下载到文件中\n\n");
	printf("            7.    业绩分析\n\n");
	printf("            8.    提醒管理员进行成绩的更新\n\n");
	printf("            9.    返回上一层\n\n");
	printf("            0.    退出\n\n"); 
	printf("请输入指令：");
	scanf("%d", &ch);
	while (ch < 0 || ch > 9) {
		fflush(stdin);
		printf("\033c");
		printf("输入了错误的指令，请输入对应的数字\n");
		printf("请选择指令:\n\n");
		printf("            1.    增加新的店面信息\n\n");
		printf("            2.    删除店面信息\n\n");
		printf("            3.    修改店面信息\n\n"); 
		printf("            4.    查询店面信息\n\n"); 
		printf("            5.    输出当天业绩\n\n"); 
		printf("            6.    下载到文件中\n\n");
		printf("            7.    业绩分析\n\n");
		printf("            8.    提醒管理员进行成绩的更新\n\n");
		printf("            9.    返回上一层\n\n");
		printf("            0.    退出\n\n"); 
		printf("请输入指令：");
		scanf("%d", &ch);
	}
	if (ch == 0) { 
		printf("\033c");
		printf("您已经成功退出!");	
	}
	if (ch == 1) {	//增加新的信息
			fflush(stdin);
			printf("\033c");
			s head1; 
			head1 = creat_inf();	//创建基本信息链表
			save_inf1(head1, number1);		//保存基本信息到指定文件中
			printf("请按任意键返回上一层\n");
			fflush(stdin);
			char ch = getchar();
			com();
	}
	if (ch == 2) {	//删除的信息 
		fflush(stdin);
		printf("\033c");
		int m ;
		printf("请选择指令:\n\n");
		printf("1.通过输入名字删除\n");
		printf("2.通过输入序号删除\n\n");
		printf("请输入指令:");
		scanf("%d", &m);
		while (m < 1 || m > 2) {
			fflush(stdin);
			system("cls");
			printf("输入了错误的指令，请输入对应的数字\n");
			printf("请选择指令:\n\n");
			printf("1.通过输入名字删除\n");
			printf("2.通过输入序号删除\n\n");
			printf("请输入指令:");
			scanf("%d", &m);
		}
		if (m == 1) {		//输入名字 
			fflush(stdin);
			printf("\033c");
			printf("请输入要删除的名字:\n");
			char name1[20];
			scanf("%s",name1);
			int flag = 0;
			s head2 = (struct list *)malloc(sizeof(struct list)); 
			s head3 = (struct list *)malloc(sizeof(struct list));
			
			head2->next = read(number1);		//从指定文件中读取信息
			head3->next = head2;			//记录结点 
			while (head2->next) {
				if (strcmp(head2->next->name, name1) == 0) {
					flag = 1;
					break;
				}
				head2 = head2->next;
			}
			if (flag == 0) {
				printf("不存在此人\n");
				printf("请按任意键返回上一层\n");
				fflush(stdin);
				char ch = getchar();
				com();
			} else {
				head2->next = head2->next->next;	//删除掉这一部分 
				save_inf3(head3->next, number1);		//保存基本信息到指定文件
				printf("已经删除完成\n");
				printf("请按任意键返回上一层\n");
				fflush(stdin);
				char ch = getchar();
				com();
			}
		}
		if (m == 2) {		//输入序号 
			fflush(stdin);
			printf("\033c");
			printf("请输入要删除的序号:\n");
			char number1[20];
			scanf("%s",number1);
			int flag = 0;
			s head2 = (struct list *)malloc(sizeof(struct list));
			s head3 = (struct list *)malloc(sizeof(struct list));
			head2->next = read(number1);		//从指定文件中读取信息
			head3->next = head2;			//记录结点 
			
			while (head2->next) {
				if (strcmp(head2->next->number, number1) == 0) {
					flag = 1;
					break;
				}
				head2 = head2->next;
			}
			if (flag == 0) {
				printf("不存在此人\n");
				printf("请按任意键返回上一层\n");
				fflush(stdin);
				char ch = getchar();
				com();
			} else {
				head2->next = head2->next->next;	//删除掉这一部分 
				save_inf3(head3->next, number1);		//保存基本信息到指定文件
				printf("已经删除完成\n");
				printf("请按任意键返回上一层\n");
				fflush(stdin);
				char ch = getchar();
				com();
			}
		}
	}
	if (ch == 3) {	//修改的信息 	
		fflush(stdin);
		printf("\033c");
		int m ;
		printf("请选择指令:\n\n");
		printf("1.通过输入名字修改\n");
		printf("2.通过输入序号修改\n\n");
		printf("请输入指令:");
		scanf("%d", &m);
		while (m < 1 || m > 2) {
			fflush(stdin);
			printf("\033c");
			printf("输入了错误的指令，请输入对应的数字\n");
			printf("请选择指令:\n\n");
			printf("1.通过输入名字修改\n");
			printf("2.通过输入序号修改\n\n");
			printf("请输入指令:");
			scanf("%d", &m);
		}
		if (m == 1) {		//输入名字 
			fflush(stdin);
			printf("\033c");
			printf("请输入要修改的的名字:\n");
			char name1[20];
			scanf("%s", name1);	
			int flag = 0;
			s head2 = (struct list *)malloc(sizeof(struct list)); 
			s head3 = (struct list *)malloc(sizeof(struct list)); 
			head2->next = read(number1);		//从指定文件中读取信息
			head3->next = head2->next;		//记录头结点 
			while (head2) {
				if (strcmp(head2->name, name1) == 0) {
					flag = 1;
					break;
				}
				head2 = head2->next;
			}
			if (flag == 0) {
				printf("不存在此人\n");
				printf("请按任意键返回上一层\n");
				fflush(stdin);
				char ch = getchar();
				com();
			} 
			printf("%s %s %d\n", head2->name, head2->number, head2->perfor);
			printf("如果要修改,请按1\n如果不需要,请按2\n");
			int n;
			scanf("%d", &n);
			if (n == 1) {
				printf("请输入你要修改的内容：\n");
				printf("1.名字\n2.序号\n3.业绩\\n");
				printf("请输入选项前面的序号：\n");
				int a;
				scanf("%d", &n);
				fflush(stdin);
				while (n < 1||n > 3) {
					printf("\033c");
					fflush(stdin);
					printf("请按照要求输入正确的序号：\n");
					printf("1.名字\n2.序号\n3.业绩\n");
					printf("请输入选项前面的序号：\n");
					scanf("%d", &n);
				}
				if (n == 1) {	//修改名字 
					printf("\033c");
					printf("请输入你要修改的名字：\n");
					char name1[20];
					scanf("%s", name1);
					strcpy(head2->name, name1);
					fflush(stdin);
				}
				if (n == 2) {//序号 
					printf("\033c");
					printf("请输入你要修改的序号：\n");
					char xuhao1[20];
					scanf("%s", xuhao1);
					strcpy(head2->number, xuhao1);
					fflush(stdin);
				}
				if (n == 3) {//业绩
					printf("\033c");
					printf("请输入你要修改的计算机成绩：\n"); 
					int c;
					scanf("%d", &c);
					head2->perfor = c;
					fflush(stdin);
				}
			} else {
				com();
			}
			printf("修改完成\n");
			save_inf3 (head3, number1);
			fflush(stdin);
			printf("请按任意键返回上一层");
			char ch = getchar();
			com();
		}
		if (m == 2) {		//输入序号 
			fflush(stdin);
			printf("\033c");
			printf("请输入要修改的的学号:\n");
			char number1[20];
			scanf("%s", number1);
			s head2 = (struct list *)malloc(sizeof(struct list));
			s head3 = (struct list *)malloc(sizeof(struct list)); 
			head2->next = read(number1);		//从指定文件中读取信息
			head3->next = head2->next;
			int flag = 0;
				while (head2) {
				if (strcmp(head2->number, number1) == 0) {
					flag = 1;
					break;
				}
				head2 = head2->next;
			}
			if (flag == 0) {
				printf("不存在此人\n");
				printf("请按任意键返回上一层\n");
				fflush(stdin);
				char ch = getchar();
				com();
			} 
			printf("%s %s %d\n", head2->name, head2->number, head2->perfor);
			printf("如果要修改,请按1\n如果不需要,请按2\n");
			int n;
			scanf("%d", &n);
			if (n == 1) {
				printf("请输入你要修改的内容：\n");
				printf("1.名字\n2.序号\n3.业绩\n");
				printf("请输入选项前面的序号：\n");
				int a;
				scanf("%d", &n);
				fflush(stdin);
				while (n < 1||n > 6) {
					system("cls");
					fflush(stdin);
					printf("请按照要求输入正确的序号：\n");
					printf("1.名字\n2.序号\n3.业绩\n\n");
					printf("请输入选项前面的序号：\n");
					scanf("%d", &n);
				}
				if (n == 1) {	//修改名字 
					printf("\033c");
					printf("请输入你要修改的名字：\n");
					char name1[20];
					scanf("%s", name1);
					strcpy(head2->name, name1);
					fflush(stdin);
				}
				if (n == 2) {//序号 
					printf("\033c");
					printf("请输入你要修改的序号：\n");
					char xuhao1[20];
					scanf("%s", xuhao1);
					strcpy(head2->number, xuhao1);
					fflush(stdin);
				}
				if (n == 3) {//业绩
					printf("\033c");
					printf("请输入你要修改的业绩：\n"); 
					int c;
					scanf("%d", &c);
					head2->perfor = c;
					fflush(stdin);
				}
			} else {
				com();
			}
			printf("修改完成\n");
			save_inf3(head3, number1);
			fflush(stdin);
			printf("请按任意键返回上一层");
			char ch = getchar();
			com();
		}
	}
	if (ch == 4) {	//查询信息
		fflush(stdin);
		printf("\033c");
		int m ;
		printf("请选择指令:\n\n");
		printf("1.通过输入名字查询\n");
		printf("2.通过输入序号查询\n\n");
		printf("请输入指令:");
		scanf("%d", &m);
		while (m < 1 || m > 2) {
			fflush(stdin);
			printf("\033c");
			printf("输入了错误的指令，请输入对应的数字\n");
			printf("请选择指令:\n\n");
			printf("1.通过输入名字查询\n");
			printf("2.通过输入序号查询\n\n");
			printf("请输入指令:");
			scanf("%d", &m);
		}
		if (m == 1) {		//输入名字 
			fflush(stdin);
			printf("\033c");
			printf("请输入要查找的的名字:\n");
			char name1[20];
			scanf("%s",name1);	
			int flag = 0;
			s head2 = (struct list *)malloc(sizeof(struct list)); 
			head2->next = read(number1);		//从指定文件中读取信息
			while (head2) {
				if (strcmp(head2->name, name1) == 0) {
					flag = 1;
					break;
				}
				head2 = head2->next;
			}
			if (flag == 0) {
				printf("不存在此人\n");
				printf("请按任意键返回上一层\n");
				fflush(stdin);
				char ch = getchar();
				com();
			} 
			printf("%s %s %d \n", head2->name, head2->number, head2->perfor);
			printf("查询成功！\n");
			fflush(stdin);
			printf("请按任意键返回上一层\n");
			char ch = getchar();
			com();
		}
		if (m == 2) {		//输入序号 
			fflush(stdin);
			printf("\033c");
			printf("请输入要查找的的学号:\n");
			char number1[20];
			scanf("%s",number1);
			int flag = 0;
			s head2 = (struct list *)malloc(sizeof(struct list));
			head2->next = read(number1);		//从指定文件中读取信息
			
			while (head2) {
				if (strcmp(head2->number, number1) == 0) {
					flag = 1;
					break;
				}
				head2 = head2->next;
			}
			if (flag == 0) {
				printf("不存在此人\n");
				printf("请按任意键返回上一层\n");
				fflush(stdin);
				char ch = getchar();
				com();
			} 
			printf("%s %s %d\n", head2->name, head2->number, head2->perfor);
			printf("查询成功！\n");
			printf("请按任意键返回上一层\n");
			fflush(stdin);
			char ch = getchar();
			com();
		}	 
		
	}
	if (ch == 5) {	//输出当天业绩  
		s head2;
		head2 = read(number1);		//从指定文件中读取信息
		print_inf1(head2);		//打印并且显示单链表中的基本信息 	
		fflush(stdin);
		printf("请按任意键返回上一层");
		char ch = getchar();
		com();
	}
	if (ch == 6) {	//下载到另外一个文件当中去 
		s head2;
		head2 = read(number1);		//从指定文件中读取信息(专属于另一个文件的 
		save_inf2(head2);		//保存基本信息到指定文件中
		fflush(stdin);
		printf("请按任意键返回上一层");
		char ch = getchar();
		com();
	}
	if (ch == 7) {	//业绩分析 
		s head2;
		head2 = read(number1);		//从指定文件中读取信息
		fenxi(head2);
		fflush(stdin);
		printf("请按任意键返回上一层");
		char ch = getchar();
		com();
	}
	if (ch == 8) {	//向管理员申诉内容 
		char s[1000000];
		FILE *fp;
		if ((fp = fopen("申诉.txt","a+")) == NULL) {
			printf("打开文件失败\n");
			exit(0);
		}
		printf("请输入你要反馈的内容：\n");
		scanf("%s", s);
		fprintf(fp, "%s\n", s);
		fclose(fp);
		fflush(stdin);
		printf("请按任意键返回上一层");
		char ch = getchar();
		com();		
	}
	if (ch == 9) {	//	
		menu();
	}
}
void save_inf3 (struct list *h, char *st) { //保存基本信息到指定文件当中去（专属于2和3的 
	s stu = h->next;
	FILE *fp;
	if (st[1] == '1') {
		if ((fp = fopen("c1.txt","w")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '2') {
		if ((fp = fopen("c2.txt","w")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '3') {
		if ((fp = fopen("c3.txt","w")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	}
	if (st[1] == '4') {
		if ((fp = fopen("c4.txt","w")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '5') {
		if ((fp = fopen("c5.txt","w")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	while (stu) {
		fprintf(fp, "%s %s %d\n", stu->name, stu->number, stu->perfor);
		stu = stu->next;
	}
	fclose(fp);
}
struct list *creat_inf() {		//创建基本信息链表
	//int i = 0;	//记录人的序号 
	char choice;//记录你此时的是否继续操作 
	s head = (struct list *)malloc(sizeof(struct list));
	head->next = NULL;
	s temp = head;//记录头结点 
	
	do {
		s stu = (struct list *)malloc(sizeof(struct list));
		//printf("\n\n第%d个人的信息为:\n", ++i);
		printf("姓名\t序号\t业绩\n");
		scanf("%s", stu->name);
		scanf("%s", stu->number);
		//fflush(stdin);
		scanf("%d", &stu->perfor);
		//fflush(stdin);
		head->next = stu;
		head = stu;
		printf("请输入你接下来的操作\n");
		printf("继续输入/停止输入(y/n)\n");
		fflush(stdin);
		choice = getchar();
		printf("\033c");
	}while (choice == 'Y' || choice == 'y');
	head->next = NULL;
	return temp;	//返回记录的头结点 
	
}	
void save_inf1 (struct list *h, char *st) { //保存基本信息到指定文件当中去(专属于增加的 
	s stu = h->next;
	FILE *fp;
	if (st[1] == '1') {
		if ((fp = fopen("c1.txt","a+")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '2') {
		if ((fp = fopen("c2.txt","a+")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '3') {
		if ((fp = fopen("c3.txt","a+")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	}
	if (st[1] == '4') {
		if ((fp = fopen("c4.txt","a+")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '5') {
		if ((fp = fopen("c5.txt","a+")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	while (stu) {
		fprintf(fp, "%s %s %d\n", stu->name, stu->number, stu->perfor);
		stu = stu->next;
	}
	fclose(fp);
}
struct list *read(char *st) {	//从指定文件中读取信息
	FILE *fp;
	if (st[1] == '1') {
		if ((fp = fopen("c1.txt","r")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '2') {
		if ((fp = fopen("c2.txt","r")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '3') {
		if ((fp = fopen("c3.txt","r")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	}
	if (st[1] == '4') {
		if ((fp = fopen("c4.txt","r")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	if (st[1] == '5') {
		if ((fp = fopen("c5.txt","r")) == NULL) {
			printf("打开文件失败");
			exit(0);
		}
	} 
	
	s head = (struct list *)malloc(sizeof(struct list));
	head->next == NULL;
	s r = head;	//记录头结点
	
	while (feof(fp) == 0) {	//对文件的位置进行更改 
		s stu = (struct list *)malloc(sizeof(struct list));
		fscanf(fp, "%s %s %d\n", stu->name, stu->number, &stu->perfor);
		head->next = stu;
		head = stu; 
	}
	head->next = NULL;
	fclose(fp);
	printf("\n文件中的信息已经被正确读出,请按任意键返回！\n");
	//char ch = getchar();
	printf("\033c");
	return r->next;
	
}
void print_inf1 (struct list *h) {//打印并且显示单链表中的基本信息 
	s stu = h;
	while (stu) {
		printf("%s %s %d\n", stu->name, stu->number, stu->perfor);
		stu = stu->next;
	}
}
void save_inf2 (struct list *h) {//保存基本信息到指定文件当中去（专属于另一个文件的 
	s stu = h->next;
	FILE *fp;
	if ((fp = fopen("新的文件夹.txt","a+")) == NULL) {
		printf("打开文件失败");
		exit(0);
	}
	while (stu) {
		fprintf(fp, "%s %s %d\n", stu->name, stu->number, stu->perfor);
		stu = stu->next;
	}
	fclose(fp);
}
void fenxi(struct list *h) {	//成绩分析并打印出来你的成绩地位 
	int maxc = 0;
	int priv = 0;
	int count = 0;
	s stu = h;
	while (stu) {
		priv += stu->perfor;
		count++;
		if (stu->perfor > maxc) {
			maxc = stu->perfor;
		}
		stu = stu->next;
	}
	printf("最高业绩为%d单,平均业绩为%d单\n\n", maxc, priv/count); 
}

void menu() {	//主界面 
	printf("\033c");
	fflush(stdin);
	printf(" \n\n============= 西 安 市 二 刀 流 店 面 管 理 系 统 =============\n\n");
	printf("******************** 请选择登录方式 ********************\n\n");
	printf("                1.    分 店 面 登 录\n\n");
	printf("                2.    总 公 司 登 录\n\n"); 
	printf("                3.    管 理 员 登 录\n\n");
	printf("                4.    店 面 注 册\n\n");
	printf("                5.    公 司 人 员 注 册\n\n");
	printf("                0.    退 出\n\n");
	printf(" 请选择：");
	char n[50];
	scanf("%s", n);
	while (n[0] < '0' || n[0] > '5' || strlen(n) > 1) {
		fflush(stdin);//很重要，用来清除键盘的缓冲区，不然会导致下面的scanf无法正常运行 （因为被上一次的代码执行后时的键盘缓存自动填入，导致程序运行错误）
		printf("\033c");
		printf("\n输入了错误的指令（请输入0~5的指令）\n");
		printf("******************** 请选择登录方式 ********************\n\n");
		printf("            1.    分 店 面 登 录\n\n");
	    printf("            2.    总 公 司 登 录\n\n"); 
	    printf("            3.    管 理 员 登 录\n\n");
	    printf("            4.    店 面 注 册\n\n");
	    printf("            5.    公 司 人 员 注 册\n\n");
	    printf("            0.    退 出\n\n");
	    printf(" 请选择：");
		printf("\n请重新输入：");
		scanf("%s", n);
	}
	if (n[0] == '0' && n[1] == '\0') {
		printf("\033c");
		printf("您已经成功退出!");
	}
	if (n[0] == '1' && n[1] == '\0') {	//分店面登录 
		fencom_login();
	}
	if (n[0] == '2' && n[1] == '\0') {	//总公司登录 
		com_login();
	}
	if (n[0] == '3' && n[1] == '\0') {	//管理员登录 
		guanli_login();
	}
	if (n[0] == '4' && n[1] == '\0') {	//店面注册 
		fencom_regis();
	}
	if (n[0] == '5' && n[1] == '\0') {	//公司人员注册 
		com_regis();
	}
}
void fencom_login() {	//分店面登陆
	fflush(stdin);
	printf("\033c");
	printf("请分别输入店面账号和店面密码：\n");
	char zhang1[50];
	char word1[50];
	scanf("%s %s", zhang1, word1);
	fflush(stdin);
	int flag = 0;
	node1 head1 = (struct users*)malloc(sizeof(struct users));
	head1->next = readz();
	while (head1) {
		if ((strcmp(head1->zhang, zhang1) == 0) && (strcmp(head1->word, word1) == 0) ){
			flag = 1;
			break;
		}
		head1 = head1->next;
	}
	if (flag == 1) {
		fflush(stdin);
		printf("登录成功,请按任意键进入店面界面");
		char ch = getchar();
		fencom();
	} else {
		printf("不存在此账号\n请按任意键返回上一层进行注册\n"); 
		char ch = getchar();
		menu(); 
	}
}
void com_login() {	//总公司登录 
	fflush(stdin);
	printf("\033c");
	printf("请分别输入公司主管人员账号和主管人员密码：\n");
	char zhang1[50];
	char word1[50];
	scanf("%s %s", zhang1, word1);
	fflush(stdin);
	int flag = 0; 
	node1 head1 = (struct users*)malloc(sizeof(struct users));
	head1->next = readz();
	while (head1) {
		if ((strcmp(head1->zhang, zhang1) == 0) && strcmp(head1->word, word1) == 0) {
			flag = 1;
			break;
		}
		head1 = head1->next;
	}
	if (flag == 1) {
		fflush(stdin);
		printf("登录成功,请按任意键进入总公司登录界面\n");
		char ch = getchar();
		com();
	} else {
		printf("不存在此账号\n请按任意键返回上一层进行注册\n"); 
		char ch = getchar();
		menu(); 
	}
}
void guanli_login() {	//管理员登录 (直接跳转至管理员页面 
	guanliyuan();
}
void fencom_regis() {	//分店面注册 
	fflush(stdin);
	printf("\033c");
	node1 head1 = (struct users*)malloc(sizeof(struct users));
	printf("请输入你要注册的账号:格式为0x0xx\n");
	printf("第一个X代表天数,后两个X代表序号\n");
	scanf("%s", head1->zhang);
	printf("\n");
	printf("请输入你要注册的密码：\n");
	scanf("%s", head1->word);
	fflush(stdin);
	head1->next = NULL;
	save_zhuce(head1);
	printf("您已经注册完毕\n请按任意键返回上一层进行登录\n");
	char ch = getchar();
	fflush(stdin);
	menu();
}
void com_regis() {	//公司主管注册 
	fflush(stdin);
	printf("\033c");
	node1 head1 = (struct users*)malloc(sizeof(struct users));
	printf("请输入你要注册的账号:格式为1x001\n");
	printf("第一个X代表天数\n");
	scanf("%s", head1->zhang);
	printf("\n");
	printf("请输入你要注册的密码：(最多10位)\n");
	scanf("%s", head1->word);
	fflush(stdin);
	head1->next = NULL;
	save_zhuce(head1);
	printf("您已经注册完毕\n请按任意键返回上一层进行登录\n");
	char ch = getchar();
	fflush(stdin);
	menu();
}
struct users *readz() {	//从登陆的专属文件中读取信息
	FILE *fp;
	if ((fp = fopen("登录.txt","rt")) == NULL) {
		printf("打开文件失败");
		exit(0);
	}
	node1 head = (struct users*)malloc(sizeof(struct users));
	head->next = NULL;
	node1 r = head; //记录头结点
	
	while (feof(fp) == 0) {	//对文件的位置进行更改 
		node1 stu = (struct users*)malloc(sizeof(struct users));
		fscanf(fp, "%s %s\n", stu->zhang, stu->word);
		head->next = stu;
		head = stu; 
	}
	
	head->next = NULL;
	fclose(fp);
	printf("\n文件中的信息已经被正确读出,请按任意键返回！\n");
	//char ch = getchar();
	printf("\033c");
	return r->next;
}
void save_zhuce(struct users *h) {	//保存注册的东西到文件中去 
	node1 head1 = h;
	FILE *fp = fopen("登录.txt", "a+");
	if (fp == NULL) {
		printf("打开文件夹失败");
		exit(0); 
	}
	while (head1) {
		fprintf(fp, "%s %s\n", head1->zhang, head1->word);
		head1 = head1->next;
	}
	fclose(fp);
}

int main() {	//主函数进入主界面 
	menu();
	return 0;
}
