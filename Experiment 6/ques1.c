#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
struct Strings{
char str1[20];
char str2[20];
char result[40];
};
void *concatenate(void *concatenate){
struct Strings* strings =  (struct Strings*) concatenate;
strcpy(strings->result,strings->str1);
strcat(strings->result,strings->str2);

pthread_exit(NULL);
}

int main(){

struct Strings string;
strcpy(string.str1,"Hello! ");
strcpy(string.str2,"World");

pthread_t t1;
pthread_create(&t1,NULL,concatenate,&string);
pthread_join(t1,NULL);
printf("Now we are in main function- %s",string.result);

}
