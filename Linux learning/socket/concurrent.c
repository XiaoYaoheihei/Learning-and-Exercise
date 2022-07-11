#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<pthread.h>

struct sockinfo{
    struct sockaddr_in addr;
    int fd;
};
struct sockinfo infos[512];

void *working(void* );

int main() {
    //1.创建一个监听的套接字
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        exit(0);
    }

    //2.和本地的IP地址以及端口绑定
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;  //地址族协议
    addr.sin_port = htons(10000);//绑定的端口，一般5000以下的都归系统使用了
    addr.sin_addr.s_addr = INADDR_ANY;//绑定的本地的IP地址
    //这个INADDR_ANY代表的是本机所有的IP地址
    //这个宏可以表示任何一个IP地址
    //这个宏一般用于本地IP的绑定操作
    //宏的值为0 == 0.0.0.0
    int ret = bind(fd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret == -1) {
        perror("bind");
        exit(0);
    }

    //3.设置监听步骤
    ret = listen(fd, 128);
    if (ret == -1) {
        perror("listen");
        exit(0);
    }

    //初始化这个结构体数组
    int max = sizeof(infos) / sizeof(infos[1]);
    for (int i = 0; i < max; i++) {
        bzero(&infos[i], sizeof(infos[i]));
        infos[i].fd = -1;
    }

    //4.阻塞并且等待客户端的连接
    struct sockaddr_in cliaddr;//把客户端的IP写到这个结构体里面
    int clilen = sizeof(cliaddr);
    while (1) {
        struct sockinfo* p;
        for (int i = 0; i < max; i++) {
            if (infos[i].fd == -1) {
                p = &infos[i];
                break;
            }
        }
        //开始创建子线程来进行进行通信
        int nfd = accept(fd, (struct sockaddr*)&p->addr, &clilen);
        //新的通信描述符
        p->fd = nfd;

        if (nfd == -1) {
            perror("accpet");
            //exit(0);
            continue;
        }

        //创建线程
        pthread_t pid;
        pthread_create(&pid, NULL, working, p);
        pthread_detach(pid);

    }
    close(fd);

    return 0;
}

void* working(void* argc) {
    struct sockinfo *p = (struct sockinfo*)argc;
    //如果成功的话打印客户端的IP信息
    char ip[24] = {0};
    printf("客户端的IP地址为: %s, 端口为: %d\n", inet_ntop(AF_INET, &p->addr.sin_addr.s_addr, ip, sizeof(ip)),
                                            ntohs(p->addr.sin_port));
    //将IP和端口打印之前一定要把大端相应的数据转换成小端之后在打印

    //5.接受数据并且发送数据
    while (1) {
        //使用recv接受数据
        char buff[1024];//是为了把通信文件描述符对应的内核读缓冲区中的内容写进内存中
        int len = recv(p->fd, buff, sizeof(buff), 0);
        if (len > 0) {
            printf("client say : %s\n", buff);
            
            static int number = 0;
            memset(buff, 0, sizeof(buff));
            sprintf(buff, "你好，客户端。。。收到收到%d\n", number++);
            
            send(p->fd, buff, len, 0);//通信描述符所对应的写缓冲区中写对应的内容然后发送
        } else if (len == 0) {
            printf("客户端已经断开了连接。。。\n");
            break;
        } else {
            perror("recv");
            break;
        }
    }

    //6.关闭文件描述符
    close(p->fd);
    p->fd = -1;

    return NULL;
}
