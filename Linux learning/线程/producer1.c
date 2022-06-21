//采用链表来表示生产者生产的东西
struct node {
    int number;
    struct node *next;
};

pthread_cond_t cond;
//定义条件变量，控制所有的消费者线程
pthread_mutex_t mutex;
//互斥锁变量

struct node *head = NULL;
//采用的是头插法

//生产者进行的函数
void *producer(void *argc) {
    while (1) {
        pthread_mutex_lock(&mutex);
        struct node *pnew = (struct node *)malloc(sizeof(struct node));
        pnew->next = head;
        pnew->number = rand() % 1000;
        //添加链表节点中的内容
        head = pnew;
        printf("+++producer, number = %d, tid = %ld\n", pnew->number, pthread_self());
        pthread_mutex_unlock(&mutex);

        pthread_cond_broadcast(&cond);
        //生产了东西之后，通知消费者
        //让其阻塞的函数都恢复工作

        sleep(rand() % 3);
    }
    return NULL;
}

//消费者进行的函数
void *consumer (void *argc) {
    while (1) {
        pthread_mutex_lock(&mutex);
        while (head == NULL) {
            //任务队列头节点如果一直是空的话就会被阻塞住
            //所有进入循环被阻塞的线程都被记录在cond函数里面
            //同时进入循环的线程对应的锁都将被重新打开
            //当消费者线程被解除阻塞之后，函数内部会自动给上锁
            //这个时候又重新保证了读取数据的安全性
            pthread_cond_wait(&cond, &mutex);
        }
        //取出头节点然后咔嚓掉
        struct node *pnode = head;
        printf("--consumer: number: %d, tid = %ld\n", pnode->number, pthread_self());
        head = head->next;
        free(pnode);
        pthread_mutex_unlock(&mutex);

        sleep(rand() % 3);
    }
    return NULL;
}

int main() {
    //初始化条件变量
    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);
    
    //创建生产者和消费者线程
    pthread_t ptid[5];
    pthread_t ctid[5];
    for (int i = 0; i < 5; i++) {
        pthread_create(&ptid[i], NULL, producer, NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_create(&ctid[i], NULL, consumer, NULL);
    }

    //释放资源
    for (int i = 0; i < 5; i++) {
        //阻塞等待子线程退出
        pthread_join(ptid[i], NULL);
    }
    for (int i = 0; i < 5; i++) {
        pthread_join(ctid[i], NULL);
    }
    // 销毁条件变量
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}
