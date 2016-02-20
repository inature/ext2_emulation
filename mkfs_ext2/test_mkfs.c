/*把disk文件格式化为ext2*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include"../include/file.h"
#define DISK "../disk"
int main(int argc,char *argv[]){
	int fd;
	if((fd=open(DISK,O_RDONLY))==-1){
		perror("fail to open file");
		exit(EXIT_FAILURE);
	}
	/*为引导块预留1KB*/
	if(lseek(fd,1024,SEEK_CUR)==-1){
		perror("file lseek");
		exit(EXIT_FAILURE);
	}
	/*将超级块数据写入*/
	struct ext2_super_block super_block;
	read(fd,&super_block,sizeof(struct ext2_super_block));
	printf("%d\n",super_block.s_wtime);
	close(fd);
	return 0;
}
