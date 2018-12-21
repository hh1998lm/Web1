#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
    int fd_src,fd_des;
    char buf[128];
    int num;
    if(argc-3)
    {
    print("error");
    exit(0);
    }
    if((fd_src=open(argv[1],O_READONLY))==-1)
    {
	perror("open1");
	exit(0);
    }
    if((fd_des=open(argv[2],O_CREAT|O_EXCL|O_WRONLY,0644))==-1)
    {
	perror("open2");
	exit(0);
    }
    do
    {
	num = read(fd_src,buf,128);
	write(fd_des,buf,num);
    }while(num==128);

    close(fd_src);
    close(fd_des);
   
    return 0;
}
