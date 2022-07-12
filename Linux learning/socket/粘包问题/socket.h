#ifndef _SOCKET_H
#define _SOCKET_H
//服务器端
int bindSocket(int lfd, unsigned short port);
int setListen(int lfd, unsigned short port);
int acceptConn(int lfd, struct sockaddr_in *addr);

//客户端
int connetToHost(int fd, const char *ip, unsigned short port);

//共用
int createSocket();
int sendMsg(int cfd, const char* msg, int len);
int recvMsg(int cfd, char** msg);
int closeSocket(int fd);
int readn(int fd, char *buff, int size);
int writen(int fd, const char* msg, int size);

#endif