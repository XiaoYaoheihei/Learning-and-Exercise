//采用链表来表示生产者生产的东西
struct node {
    int number;
    struct node *next;
};

sem_t psem;
//生产者线程信号量
sem_t csem;
//消费者线程信号量
pthread_mutex_t mutex;
//互斥锁变量

struct node *head = NULL;
//采用的是头插法

//生产者进行的函数
void *producer(void *argc) {
    while (1) {
        //生产者生产消耗一个资源
        sem_wait(&psem);
        pthread_mutex_lock(&mutex);
        struct node *pnew = (struct node *)malloc(sizeof(struct node));
        pnew->next = head;
        pnew->number = rand() % 1000;
        //添加链表节点中的内容
        head = pnew;
        printf("+++producer, number = %d, tid = %ld\n", pnew->number, pthread_self());
        pthread_mutex_unlock(&mutex);

        sem_post(&csem);
        //生产了东西之后，通知消费者
        //让消费者的资源数加一

        sleep(rand() % 3);
    }
    return NULL;
}

//消费者进行的函数
void *consumer (void *argc) {
    while (1) {
        sem_wait(&csem);
        pthread_mutex_lock(&mutex);
        //取出头节点然后咔嚓掉
        struct node *pnode = head;
        printf("--consumer: number: %d, tid = %ld\n", pnode->number, pthread_self());
        head = head->next;
        free(pnode);
        pthread_mutex_unlock(&mutex);
        //消费者消费完成之后，通知生产者，给生产者加信号灯
        sem_post(&psem);

        sleep(rand() % 7);
    }
    return NULL;
}

int main() {
    //初始化信号量
    sem_init(&psem, 0 , 5);
    sem_init(&csem, 0, 0);
    //初始化互斥锁
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
    // 销毁信号灯
    sem_destroy(&psem);
    sem_destroy(&csem);
    pthread_mutex_destroy(&mutex);
    
    return 0;
}
