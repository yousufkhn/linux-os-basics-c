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

msgId = msgget(11,0666|IPC_CREAT);

message.msg_type = 1;
printf("enter a message: ");
getchar();
fgets(message.msg_text,1024,stdin);
msgsnd(msgId,&message,1024,0);
printf("message send : %s",message.msg_text);
return 0;
}
