#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

struct demoUP{
int a,b;
};
void *sum(void *sum){
struct demoUP *O = sum;
int c = O->a+O->b;
printf("\n The sum is %d",c);
pthread_exit(NULL);
}
void *sub(void *sub){
struct demoUP *O = sub;
int c =  O->a-O->b;
printf("\nThe subtraction results %d",c);
pthread_exit(NULL);
}

int main(){

struct demoUP O;
O.a=45;
O.b=5;

pthread_t t1,t2;
pthread_create(&t1,NULL,sum,&O);
pthread_join(t1,NULL);
pdthread_create(&t2,NULL,sub,&O);
pthread_join(t2,NULL);
printf("Now we are in main function");


}
