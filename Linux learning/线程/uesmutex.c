#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>

#define MAX 50

int number;

pthread_mutex_t mutex;
//创建一把互斥锁
//全局变量，多个线程共享

void *fun1 (void *argc) {
    for (int i = 0; i < MAX; i++) {
        //线程1如果加锁成功，不会进行阻塞
        //如果其他线程加锁成功，会把线程1阻塞
        pthread_mutex_lock(&mutex);
        int cur = number;
        cur++;
        //usleep(10);
        number = cur;
        printf("thread1 , id = %lu, number = %d\n", pthread_self(), number);
        pthread_mutex_unlock(&mutex);
        usleep(5);
    }
    return NULL;
}

void *fun2 (void *argc) {
    for (int i = 0; i < MAX; i++) {
        //如果线程1加锁成功的话，那么线程2访问这把锁的时候是锁定的
        //线程2这个时候被阻塞，直到1解锁
        //线程2这个时候再加锁
        pthread_mutex_lock(&mutex);
        int cur = number;
        cur++;
        //usleep(10);
        number = cur;
        printf("thread2 , id = %lu, number = %d\n", pthread_self(), number);
        pthread_mutex_unlock(&mutex);
        usleep(10);
    }
    return  NULL;

}


int main() {
    pthread_t p1, p2;

    //初始化互斥锁
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p1, NULL, fun1, NULL);
    pthread_create(&p2, NULL, fun2, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    pthread_mutex_destroy(&mutex);
    //销毁互斥锁
    //线程销毁之后再去销毁锁
    return 0;

}
