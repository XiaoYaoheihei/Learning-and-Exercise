//使用全局变量回收数据
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
struct persion {
    int id;
    char name[36];
    int age;
};
struct persion p;//使用全局变量
//子线程处理的部分
void* work(void* arg) {
    //sleep(2);
    printf("我是子线程,线程id为: %ld \n", pthread_self());
    for (int i = 0; i < 8; i++) {
        printf("child = %d\n", i);
        if ( i == 6 ) {
            p.age = 12;
            strcpy(p.name, "jack");
            p.id = 100;
            //该函数将该参数的地址传递给了主线程的join()
            pthread_exit(&p);
        }
    }
    return NULL;
}
int main() {
    //创建一个线程
    pthread_t tid;
    pthread_create(&tid, NULL, work, NULL);

    printf("子线程创建成功,线程id: %ld \n", tid);
    printf("我是主线程,线程id为 %ld \n", pthread_self());
    //pthread_t pthread_self(void);返回当前进程的id
    for (int i =0; i < 3; i++) {
        printf("i = %d\n", i);
    }
    //ptr是一个传出参数，他里面存的内容是返回的指针地址
    void *ptr = NULL;
    pthread_join(tid, &ptr);

    struct persion *pre = (struct persion *)ptr;
    printf("子线程返回数据:name:%s, age:%d ,id:%d\n", pre->name, pre->age, pre->id);
    return 0;
}
