#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>

int main() {
    //1.创建通信的套接字
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        exit(0);
    }

    //2.连接服务器
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(10000);   //端口转换成大端端口
    inet_pton(AF_INET, "192.168.30.204 ", &addr.sin_addr.s_addr);
    //ip地址转化成大端

    int ret = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret == -1) {
        perror("connect");
        exit(0);
    }

    //3.和服务器之间进行通信
    int number = 0;
    while(1) {
        //发送数据
        char buf[1024];
        sprintf(buf, "你好，服务器。。。我是你大爷爷%d\n", number++);
        write(fd, buf, sizeof(buf));
        //往fd指向的内核缓冲区内进行写入

        //接受数据
        memset(buf, 0, sizeof(buf));//先把缓冲区内的数据清空再接受数据
        int len = read(fd, buf, sizeof(buf));
        if (len > 0 ) {
            printf("服务器say:%s\n", buf);
        } else if (len == 0) {
            printf("服务器断开了连接。。。\n");
        } else {
            perror("read");
            break;
        }
        sleep(1);   //每隔一秒发送并且接受一次数据
    }

    close(fd);
    return 0;
}
