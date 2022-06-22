//server
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

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

    //4.阻塞并且等待客户端的连接
    struct sockaddr_in cliaddr;//把客户端的IP写到这个结构体里面
    int clilen = sizeof(cliaddr);
    int nfd = accept(fd, (struct sockaddr*)&cliaddr, &clilen);
    //新的通信描述符
    if (nfd == -1) {
        perror("accpet");
        exit(0);
    }
    //如果成功的话打印客户端的IP信息
    char ip[24] = {0};
    printf("客户端的IP地址为: %s, 端口为: %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, sizeof(ip)),
                                            ntohs(cliaddr.sin_port));
    //将IP和端口打印之前一定要把大端相应的数据转换成小端之后在打印

    //5.接受数据
    while (1) {
        //使用recv接受数据
        char buff[1024];
        int len = recv(nfd, buff, sizeof(buff), 0);
        if (len > 0) {
            printf("client say : %s\n", buff);
            send(nfd, buff, len, 0);
        } else if (len == 0) {
            printf("客户端已经断开了连接。。。\n");
            break;
        } else {
            perror("recv");
            break;
        }
    }

    //6.关闭文件描述符
    close(fd);
    close(nfd);

    return 0;
}
