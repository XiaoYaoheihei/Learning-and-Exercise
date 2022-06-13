#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
# define BUFSIZE 1000
int main() {
    int len, i, apipe[2];
    char buf[BUFSIZ];//缓冲区
    if (pipe(apipe) == -1) {
        perror("could not make pipe");
        exit(1);
    }
    printf("got a pipe:%d %d", apipe[0], apipe[1]);//3 4
    while (fgets(buf, BUFSIZ, stdin)) {
        len = strlen(buf);
        if (write(apipe[1], buf, len) != len) {
            //往管道里面写的字节数量不等
            perror("writing to pipe");
            break;
        }
        for (i = 0; i < len; i++) {
            buf[i] = 'x';
        }
        len = read(apipe[0], buf, BUFSIZ);
        //读管道里面的东西
        if (len == -1) {
            perror("reading from pipe");
            break;
        }
        if (write(1, buf, len) != len) {
            //把管道里面的东西往标准输出弄
            perror("writing to stdout");
            break;
        }
    }
}
