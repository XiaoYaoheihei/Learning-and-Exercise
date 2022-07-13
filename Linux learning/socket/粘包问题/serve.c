#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<pthread.h>

#include"socket.h"
struct sockinfo{
    struct sockaddr_in addr;
    int fd;
};
struct sockinfo infos[512];

void *working(void* );
int main() {
    int fd = createSocket();
    if (fd == -1) {
        return -1;
    }
    int ret = setListen(fd, 10000);
    if (ret == -1) {
        return -1;
    }

    int max = sizeof(infos) / sizeof(infos[1]);
    for (int i = 0; i < max; i++) {
        bzero(&infos[i], sizeof(infos[i]));
        infos[i].fd = -1;
    }
    while (1) {
        struct sockinfo* p;
        for (int i = 0; i < max; i++) {
            if (infos[i].fd == -1) {
                p = &infos[i];
                break;
            }
        }
        p->fd = acceptConn(fd, &p->addr);
        //创建线程
        pthread_t pid;
        pthread_create(&pid, NULL, working, p);
        pthread_detach(pid);

    }
    return 0;
}

void* working(void* argc) {
    struct sockinfo *p = (struct sockinfo*)argc;
    //如果成功的话打印客户端的IP信息
    char ip[24] = {0};
    printf("客户端的IP地址为: %s, 端口为: %d\n", inet_ntop(AF_INET, &p->addr.sin_addr.s_addr, ip, sizeof(ip)),
                                            ntohs(p->addr.sin_port));
    //将IP和端口打印之前一定要把大端相应的数据转换成小端之后在打印
    while (1) {
        //char buff[4096];
        //每次可以接收4k大小的内容
        //但是发送端每次只能发送100个字节
        
        char *buff;
        
        //memset(buff, 0, sizeof(buff));
        int len = recvMsg(p->fd, &buff);
        printf("接收数据:%d......\n", len);
        printf("%d\n", len);
        if (len > 0) {
            printf("%s\n\n\n\n", buff);
            free(buff);
        } else if (len == 0) {
            //printf("客户端已经断开了连接。。。\n");
            break;
        } else {
            //perror("recv");
            break;
        }
        sleep(1);
        //发送和接收频率是严重不一样的
        //服务器接收的包是多个粘在一起的
    }
    p->fd = -1;
    //子线程结束
    return NULL;

}