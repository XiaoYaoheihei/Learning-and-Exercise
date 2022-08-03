
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>

#define PORT 7777
#define IP "127.0.0.1"
struct file_imformation{
	char file_name[120];    //文件名字
	unsigned long int file_length;//文件长度
};
int file_transfer(int fd,char* path,unsigned long int file_size);
int file_imformation_transfer(int server_fd);
void show(int count);

int main(int argc,char* argv[]){
	
	int fd;
	struct sockaddr_in daddr;
	int err;
	//建立套接字
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd < 0){
		printf("socket create fail!\n");
	}
	//初始化服务器地址
	memset(&daddr,0,sizeof(struct sockaddr));
	daddr.sin_family = AF_INET;
	daddr.sin_port = htons(PORT);
	daddr.sin_addr.s_addr = inet_addr(IP);
	//建立连接
	err = connect(fd,(struct sockaddr*)&daddr,sizeof(struct sockaddr));
	if(err < 0){
		printf("connect fail!\n");
	}
	file_imformation_transfer(fd);
	close(fd);
    return 0;
}
//传输文件内容
int file_transfer(int fd,char* path,unsigned long int file_size){
	int size = 0;
	unsigned long sum = 0;
	int n = 0;
	char buffer[1024];
	memset(buffer,0,sizeof(buffer));
	int filefd = open(path,O_RDWR);
	if(filefd == -1){
		perror("file open fail");
	}
	while(1){
		size = read(filefd,buffer,sizeof(buffer));
		if(size == -1){
			printf("文件传输错误\n");
			close(filefd);
			return -1;
		}else if(size > 0){
			size = write(fd,buffer,size);
			sum += size;
			unsigned long int p = (sum * 100)/file_size;
			printf("\r文件已传输%ld\%%",p);
		}else{
			//当读取为0时，表示文件读取完毕
			printf("传输成功 %ld byte！\n",sum);
			close(filefd);
			return 0;
		}
	}
}
//在传输文件内容之前，先传送文件信息，比如文件名
int file_imformation_transfer(int server_fd){
	struct file_imformation file_im;
	struct stat sta;    //文件属性信息
	char path[200];
	
	memset(path,0,sizeof(path));
	memset(&file_im,0,sizeof(struct file_imformation));
	memset(&sta,0,sizeof(struct stat));
	printf("请输入文件路径和文件名：\n");
	scanf("%s",path);
	/*	
		1.获取文件名
		2.根据文件路径path确定文件名
		3.假如输入path为"/home/my/text.txt"那么i定位到最后一个
        反斜杠，然后将文件名复制到file_im.file_name中
	*/
	int i = strlen(path) - 1;			
	while(path[i] != '/' && i >= 0){
		i--;
	}
	i++;
	for(int j = 0;i < strlen(path)+1;j++){
		file_im.file_name[j] = path[i];
		i++;
	}
	printf("文件名为：%s\n",file_im.file_name);
	/*
		文件大小的获取
	*/
	if(stat(path,&sta) == -1){
		perror("获取文件信息错误");
		return -1;
	}
	file_im.file_length = sta.st_size;//文件大小
	printf("文件大小为%ld\n",file_im.file_length);
	//向服务器发送文件名
	write(server_fd,&file_im,sizeof(struct file_imformation));
	//开始文件传输
	file_transfer(server_fd,path,sta.st_size);
	return 0;
}
void show(int count){
	while(count >0 ){
		write(1,"#",1);
		count--;
	}
}