#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
int fd[2];
pid_t p;
char buffer[50];
pipe(fd);
p=fork();
if(p>0){
printf("\n I am the parent and I will read data \n");
write(fd[1],"LetsProhibitChatGPT",20);
wait(NULL);
}
else{
printf("\nI am child and receiving the datat from parent \n");
int n = read(fd[0],buffer,20);
write(1,buffer,n);
}
}
