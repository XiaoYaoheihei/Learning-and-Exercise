#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
//#include "socket.h"

void *working (int , int);

//server
int main() {
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1) {
        perror("socket errror");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(10000);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (ret == -1) {
        perror("bind error");
        exit(1);
    }

    ret = listen(lfd, 64);
    if (ret == -1) {
        perror("listen perror");
        exit(1);
    }
    //现在只有监听的文件描述符
    //开始创建一个epoll模型来检测所有的文件描述符
    int epfd = epoll_create(1);
    //printf("连接成功\n");
    
    if (epfd == -1) {
        perror("epoll_create");
        exit(0);
    }
    
    //向epoll中添加需要检测的节点
    //当前只有监听的文件描述符
    struct epoll_event ev;
    ev.events = EPOLLIN;    //检测读缓冲区是否有数据
    ev.data.fd = lfd;       //记录下来此文件描述，方便返回查看
    //printf("连接成功\n");
    ret = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);
    //printf("连接成功\n");
    if (ret == -1) {
        perror("epoll_ctl");
        exit(0);
    }
    //printf("连接成功\n");

    struct epoll_event evs[1024];
    //用来存放已经就绪的文件描述符的结构体数组
    int size = sizeof(evs)/sizeof(evs[0]);
    
    while (1) {
        //开始持续检测有哪些文件描述符就绪
        //printf("连接成功\n");
        int num = epoll_wait(epfd, evs, size, -1);
        printf("%d\n", num);
        //printf("连接成功\n");
        for (int i = 0; i < num; i++) {
            //取出这个结构体里面的文件描述符
            int currfd = evs[i].data.fd;
            //判断这个文件描述符是哪个
            if (currfd == lfd) {
                //是监听的
                //开始建立新的连接
                printf("连接成功\n");
                int cfd = accept(currfd, NULL, NULL);
                //将新得到的通信描述符添加到epoll模型当中去
                //再次持续检测文件描述符的时候就可以检测到了
                ev.events = EPOLLIN;
                //检测通信描述符的读缓冲区
                ev.data.fd = cfd;
                ret = epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
                if (ret == -1) {
                    perror("epoll_ctl-accept");
                    exit(0);
                }
            } else {
                //通信描述符
                //开始接收并且发送数据
                working(epfd, currfd);
        
                /*printf("开始通信了\n");
                char buff[10];
                //memset(buff, 0 ,sizeof(buff));
                int len = recv(currfd, buff, sizeof(buff), 0);
                //int len = recv(currfd, buff, sizeof(buff), 0);
                if (len == 0) {
                    printf("客户端已经断开了连接\n");
                    //断开连接之后我们就把对应的文件描述符从epoll模型里面删除
                    epoll_ctl(epfd, EPOLL_CTL_DEL, currfd, NULL);
                    close(currfd);
                } else if (len > 0) {
                    printf("客户端say:%s\n", buff);
                    for(int i = 0; i < len; i++) {
                        buff[i] = toupper(buff[i]);
                        //小写转化成大小，方便观察
                    }
                    printf("after buff = %s\n", buff);
                    
                    //往客户端发送信息
                    //scanf("%s", buff);
                    //send(currfd, buff, len , 0);
                } else if (len == -1){
                    perror("recv");
                    exit(0);
                }*/
            }
        }
    }

    return 0;
}

void *working (int epfd, int currfd) {
    char buff[10];
    //memset(buff, 0 ,sizeof(buff));
    int len = recv(currfd, buff, sizeof(buff), 0);
    //int len = recv(currfd, buff, sizeof(buff), 0);
    if (len == 0) {
        printf("客户端已经断开了连接\n");
        //断开连接之后我们就把对应的文件描述符从epoll模型里面删除
        epoll_ctl(epfd, EPOLL_CTL_DEL, currfd, NULL);
        close(currfd);
    } else if (len > 0) {
        printf("客户端say:%s\n", buff);
        for(int i = 0; i < len; i++) {
            buff[i] = toupper(buff[i]);
            //小写转化成大小，方便观察
        }
        printf("after buff = %s\n", buff);
                    
        //往客户端发送信息
        //scanf("%s", buff);
        //send(currfd, buff, len , 0);
    } else if (len == -1){
        perror("recv");
        exit(0);
    }
    return NULL;
}