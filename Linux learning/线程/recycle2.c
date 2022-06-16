//使用主线程栈回收数据
//注意对比和全局变量的应用区别
void* work(void* arg) {
    struct persion *p = (struct persion*)arg;
    printf("我是子线程,线程id为: %ld \n", pthread_self());
    for (int i = 0; i < 8; i++) {
        printf("child = %d\n", i);
        if ( i == 6 ) {
            //使用主函数的栈内存
            p->age = 12;
            strcpy(p->name, "jack");
            p->id = 100;
            //该函数将该参数的地址传递给了主线程的join()
            pthread_exit(&p);
        }
    }
    return NULL;
}
int main() {
    //创建一个线程
    pthread_t tid;
    struct persion p;
    ...
    //ptr是一个传出参数，他里面存的内容是返回的指针地址
    void *ptr = NULL;
    pthread_join(tid, &ptr);

    /*这个时候我们只是用ptr来记录真实的一个存储地址，他的地址实际上就是前面我们的结构体的
    地址，因此我么也可以直接去访问结构体的地址*/
    printf("子线程返回数据:name:%s, age:%d ,id:%d\n", p.name, p.age, p.id);
    return 0;
}
