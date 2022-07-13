#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/stat.h>
#include<fcntl.h>
#include"socket.h"

int main() {
    //创建通信套接字
    int fd = createSocket();
    if (fd == -1) {
        return -1;
    }

    //连接服务器
    int ret = connetToHost(fd, "192.168.30.204", 10000);
    if (ret == -1) {
        return -1;
    }

    //进行通信
    
    int fd1 = open("test1.txt", O_RDONLY);
    
    int length = 0;
    char temp[1000];
    while ((length = read(fd1, temp, rand() % 1000)) > 0) {
        //读缓冲区里面的内容
        
        //发送数据
        sendMsg(fd, temp, length);
        //printf("%c", temp[0]);
        //清空缓冲区内容
        memset(temp, 0, sizeof(temp));
        usleep(300);
        //300微妙发送一次
    }
    sleep(10);
    close(fd);

    return 0;
}