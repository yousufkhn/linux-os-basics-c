#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
int fd1;
mkfifo("myPipe",0666);
char str1[20],str2[20];
while(1){
fd1=open("myPipe",O_RDONLY);
read(fd1,str1,20);
printf("user1: %s",str1);
close(fd1);

fd1=open("myPipe",O_WRONLY);
fgets(str2,20,stdin);
write(fd1,str2,strlen(str2)+1);
close(fd1);
}
return 0;
}
