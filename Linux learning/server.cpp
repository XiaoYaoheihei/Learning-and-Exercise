#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#define BACKLOG 3
#define PORT 7777
#define IP "127.0.0.1"
int file_access(int fd);
int file_imformation_accept(int fd,char buff[],unsigned long int *file_size);
//默认接收文件路径
static char filepath[50] = "/home/ffj/fileTtest/";
struct file_imformation{
	char file_name[120];
	unsigned long int file_length;
};
int main(int argc,char* argv[]){
	
	int fd;
	struct sockaddr_in daddr;
	char buff[1024];
	int err;
	
	//建立套接字
	fd = socket(AF_INET,SOCK_STREAM,0);
	if(fd < 0){
		printf("套接字建立失败!\n");
	}
	//初始化服务器地址
	memset(&daddr,0,sizeof(struct sockaddr));
	daddr.sin_family = AF_INET;
	daddr.sin_port = htons(PORT);
	daddr.sin_addr.s_addr = inet_addr(IP);
	//套接字绑定ip
	err = bind(fd,(struct sockaddr*)&daddr,sizeof(struct sockaddr));
	if(err < 0){
		printf("绑定失败\n");
	}
	//监听端口
	err = listen(fd,BACKLOG);
	if(err < 0){
		printf("监听错误！\n");
	}
	//接受连接	
	socklen_t len = sizeof(struct sockaddr);
	int acfd = accept(fd,(struct sockaddr*)&daddr,&len);
	file_access(acfd);
	close(acfd);		
	close(fd);
	return 0;
}
//接收文件内容
int file_access(int fd){
	unsigned long int size = -1;
	unsigned long int recv_size = 0;
	unsigned long int file_size;
	char buffer[1024];
	char file_url[200] = {0};
	//创建并打开文件
	memset(file_url,0,sizeof(file_url));
	memset(buffer,0,sizeof(buffer));
	//获取客户端发送信息
	file_imformation_accept(fd,file_url,&file_size);
	//创建接收文件
	int filefd = open(file_url,O_RDWR|O_CREAT,0777);
	if(filefd == -1){
		perror("文件打开失败");
		return -1;
	}
	//从套接字中读取数据并写入文件
	while(size){
		size = read(fd,buffer,sizeof(buffer));
		if(size == -1){
			printf("文件传输错误\n");
			remove(file_url);
			close(filefd);
			return -1;
		}else if(size > 0){
			recv_size += size;
			write(filefd,buffer,size);
			memset(buffer,0,sizeof(buffer));
		}else{
			if(recv_size != file_size){
				printf("错误：文件传输失败，文件大小不一致！\n");
				remove(file_url);
			}else{
				printf("接收文件成功！\n");
			}
			close(filefd);
			return 0;
		}
	}
}
//在接受文件内容前，接受文件信息
int file_imformation_accept(int fd,char buff[],unsigned long int *file_size){
	int i = 0;
	struct file_imformation file_im;
	while(i < strlen(filepath)){
		buff[i] = filepath[i];
		i++;
	}
	int len = read(fd,&file_im,sizeof(struct file_imformation));
	if(len <= 0){
		printf("错误：接收文件信息为空");
	}
	printf("接收文件名称为%s\n",file_im.file_name);
	printf("接收文件大小为%ld\n",file_im.file_length);
	//获取文件大小
	*file_size = file_im.file_length;
	//获取文件名
	if(NULL == strcpy(&buff[i],file_im.file_name)){
		printf("错误：获取文件名失败\n");
	}
	printf("文件url是%s\n",buff);
	return 0;
}