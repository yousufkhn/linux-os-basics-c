#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
struct Nums{
int arr[5];
int max;
int min;
double avg;

};


void *avg(void *avg){
struct Nums* nums =  (struct Nums*) avg;
double sum = 0;

for (int i=0;i<5;++i){
 sum += nums->arr[i];
}

nums->avg=sum/5;

pthread_exit(NULL);
}

void *maxFunction(void* maxFunction){
struct Nums* nums = (struct Nums*)maxFunction;
int max = nums->arr[0];

for (int i = 0;i<5;++i){
if(nums->arr[i] > max){
max=nums->arr[i];
}
}
nums->max = max;


pthread_exit(NULL);
}


void *minFunction(void *minFunction){
struct Nums* nums = (struct Nums*)minFunction;
int min = nums->arr[0];


for (int i=0;i<5;++i){
if(nums->arr[i] < min){
min=nums->arr[i];
}
}
nums->min = min;
pthread_exit(NULL);
}


int main(){

pthread_t avgThread,maxThread,minThread;
struct Nums num={{1,2,3,4,5},0,0,0.0};


pthread_create(&avgThread,NULL,avg,&num);
pthread_join(avgThread,NULL);
pthread_create(&maxThread,NULL,maxFunction,&num);
pthread_join(maxThread,NULL);
pthread_create(&minThread,NULL,minFunction,&num);
pthread_join(minThread,NULL);
printf("Avg- %.2f\n",num.avg);
printf("Max - %d\n",num.max);
printf("Min - %d\n",num.min);
}

