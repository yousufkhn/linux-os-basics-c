#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>


int main(){
int fd;
mkfifo("myPipe",0666);
char arr1[20];
char arr2[20];
while(1){
fd = open("myPipe",O_WRONLY);
fgets(arr2,20,stdin);
write(fd,arr2,20);
close(fd);
fd=open("myPipe",O_RDONLY);
read(fd,arr1,sizeof(arr1));
printf("user 2: %s\n",arr1);
close(fd);
}
return 0;
}
