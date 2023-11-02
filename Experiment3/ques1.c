#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

int main(){
char buffer[50];
int fd1,j,fd2,fd3,fd4,m;
fd1=open("text.txt",O_RDWR);
j=lseek(fd1,0,SEEK_SET);
read(fd1,buffer,20);
fd2=open("newFile.txt",O_WRONLY);
write(fd2,buffer,20);
fd3=open("text.txt",O_RDWR);
m=lseek(fd3,-20,SEEK_END);
read(fd3,buffer,20);
fd4=open("newFile2.txt",O_WRONLY);
write(fd4,buffer,20);
}
