#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<arpa/inet.h>
#include"socket.h"

//创建套接字
int createSocket() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        perror("socket");
        exit(0);
    }
    printf("创建成功\n");
    return fd;
}

//绑定本定的端口并且设置监听
int setListen(int lfd, unsigned short port) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;  //地址族协议
    addr.sin_port = htons(port);//绑定的端口，一般5000以下的都归系统使用了
    //这里的端口可以依据情况而定
    addr.sin_addr.s_addr = INADDR_ANY;//绑定的本地的IP地址
    int ret = bind(lfd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret == -1) {
        perror("bind");
        //exit(0);
        printf("绑定失败\n");
        return -1;
    }
    printf("绑定成功!\n");

    ret = listen(lfd, 128);
    if (ret == -1) {
        perror("listen");
        printf("监听失败\n");
        return -1;
    }
    printf("设置监听成功\n");
    
    return ret;
}

//阻塞并等待客户端的连接
int acceptConn(int lfd, struct sockaddr_in *addr) {
    int cfd;    //通信描述符
    if (addr == NULL) {
        //检测是否传入参数是一个空值
        cfd = accept(lfd, NULL, NULL);
    } else {
        int clilen = sizeof(struct sockaddr_in);
        cfd = accept(lfd, (struct sockaddr*)addr, &clilen);
    }
    if (cfd == -1) {
        perror("accept\n");
        return -1;
    }
    printf("成功与客户端建立新连接。。。\n");
    return cfd;
}

//接收指定字节数的字符串
int readn(int fd, char* buf, int size) {
    char *p = buf;          //辅助指针记录位置
    int count = size;
    while (count > 0) {
        int len = recv(fd, p, count, 0);
        if (len == -1) {
            return -1;
        } else if (len == 0) {//发送端端开连接
            return size - count ;//返回总共读到的字节数
        } else {
            p += len;      //有效内存处继续接收数据
            count -= len;   //还有多少没有接收
        }
    }
    return size;
}

//单纯地接受数据
int recvMsg(int cfd, char** msg) {
    //第二个参数是一个传出参数
    //char head[4];
    int len = 0;
    readn(cfd, (char *)&len, 4);//先读取前面4个字节数
    int count = ntohl(len);
    printf("要接收的数据块的大小是:%d\n", count);

    char* data = (char *)malloc(count + 1);
    int length = readn(cfd, data, count);

    if (length != count) {
        printf("接收数据失败\n");
        close(cfd);
        free(data);
        return -1;
    } 

    data[count] = '\0';
    *msg = data;
    return length; 
}

//发送指定长度size的字符串
int writen (int fd, const char* msg, int size) {
    const char* buf = msg;
    int current = size;
    while (current > 0) {
        int len = send(fd, buf, size, 0);
        //往对应的写缓冲区里面写内容，但是缓冲区内容有限
        //返回实际发送的字节数
        if (len == -1) {
            close(fd);
            return -1;
        } else if (len == 0) {
            continue;       //重新发送
        } else {
            buf += len;     //指针偏移
            current -= len; //剩余的字节数量
        }
    }
    return size;
}

//发送数据
int sendMsg(int cfd, const char* msg, int len) {
    if (cfd < 0 || msg == NULL || len <= 0) {
        return -1;
    }
    char* data = (char *)malloc(len + 4);
    int biglen = htonl(len);//将长度转化为网络字节序
    memcpy(data, &biglen, 4);//连续的4个字节数拷贝到内存中去
    memcpy(data + 4, msg, len);//将数据包内容进行发送
    int ret = writen(cfd, data, len + 4);
    if (ret == -1) {
        //perror("send\n");
        close(cfd);
    }
    return ret;
}


//客户端连接服务器
int connetToHost(int fd, const char *ip, unsigned short port) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);   //端口转换成大端端口
    inet_pton(AF_INET, ip, &addr.sin_addr.s_addr);
    //ip地址转化成大端

    int ret = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret == -1) {
        perror("connect");
        return -1;
        //exit(0);
    }
    printf("成功与服务器建立连接。。。\n");
    return ret;

}

//关闭套接字
int closeSocket(int fd) {
    int ret = close(fd);
    if (ret == -1) {
        perror("close");

    }
    return ret;

}