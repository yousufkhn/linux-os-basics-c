#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_buffer{
long msg_type;
char msg_text[1024];
}message;

int main(){
int msgId;
char msg[1024];

msgId = msgget(11,0666|IPC_CREAT);

msgrcv(msgId,&message,1024,1,0);
printf("message received : %s",message.msg_text);

msgctl(msgId,IPC_RMID,NULL);
return 0;
}

