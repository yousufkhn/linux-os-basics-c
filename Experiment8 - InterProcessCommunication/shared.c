#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main(){
int shmid;
void*sm;
char buffer[50];
int key=2945;

shmid=shmget(key,2048,0666|IPC_CREAT);
printf("\n The shared memory id is %d",shmid);
sm = shmat(shmid,NULL,0);
printf("\n The address attached to shared memory segment %p \n",sm);
printf("\n Enter any data \n");
read (0,buffer,50);
strcpy(sm,buffer);
printf("\n You wrote %s",(char*)sm);

}
