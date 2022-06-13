//将stdin定向到文件中
//方法一：close then open
int main() {
    int fd;
    char line[100];
    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(line, 100, stdin);
    printf(line, 100, stdin);
    //重定向标准输入
    close(0);
    fd = open("/etc/password", O_RDONLY);
    if (fd != 0) {
        fprintf(stderr, "could not open data as fd 0\n");
        exit(1);
    }
    //从重定向后的文件中读取信息
    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(line, 100, stdin);
    printf("%s", line);
    fgets(line, 100, stdin);
    printf(line, 100, stdin);
}
