#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int shared=10;
//pthread_mutex_t l;
sem_t s;

void *func1(void *func1){
int x;
//pthread_mutex_lock(&l);
sem_wait(&s); 
x=shared;
x++;
sleep(5);
shared=x;
printf("\n The value of shared variable is : %d",shared);
//pthread_mutex_unlock(&l);
sem_post(&s);
}

void *func2(void *func2){
int y;
//pthread_mutex_lock(&l);
sem_wait(&s);
y=shared;
y--;
sleep(5);
shared=y;
printf("\n The shared variable value is : %d\n",shared);
//pthread_mutex_unlock(&l);
sem_post(&s);
}


int main(){
pthread_t t1,t2;
//pthread_mutex_init(&l,NULL);
sem_init(&s,0,1);
pthread_create(&t1,NULL,func1,NULL);
pthread_create(&t2,NULL,func2,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
sem_destroy(&s);
}
