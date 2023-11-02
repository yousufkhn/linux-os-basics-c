#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

int main(){
int shmid;
char *sm;
int mode;
shmid = shmget(12345,128,0666|IPC_CREAT);

sm = shmat(shmid,NULL,0);

printf("Choose mode 1 for writer,2 for reader");
scanf("%d",&mode);
if(mode ==1){ 
printf("enter message: ");
getchar();
fgets(sm,128,stdin);
printf("Message written : %s",sm);
}
else if(mode == 2){
printf("message is :%s",sm);
}
else{
printf("invalid");
}
shmdt(sm);
return 0;
}
