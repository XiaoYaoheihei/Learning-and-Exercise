#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>

#define MAX 50

int number;

void *fun1 (void *argc) {
    for (int i = 0; i < MAX; i++) {
        int cur = number;
        cur++;
        //usleep(10);
        number = cur;
        printf("thread1 , id = %lu, number = %d\n", pthread_self(), number);
        usleep(5);
    }
    return NULL;
}

void *fun2 (void *argc) {
    for (int i = 0; i < MAX; i++) {
        int cur = number;
        cur++;
        //usleep(10);
        number = cur;
        printf("thread2 , id = %lu, number = %d\n", pthread_self(), number);
        usleep(10);
    }
    return  NULL;

}


int main() {
    pthread_t p1, p2;

    pthread_create(&p1, NULL, fun1, NULL);
    pthread_create(&p2, NULL, fun2, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    return 0;

}
