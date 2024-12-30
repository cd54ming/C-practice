#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct counter_t {
    int count;
    sem_t *sem;
} counter_t;

void counter_init(counter_t *counter, const char* sem_name) {
    counter->count = 0;

    // ! sem_init() is deprecated in macOS
    // * 第二個參數設置為 0，表示 semaphore 在同一個程序內的多個執行緒之間共享
    // * 第二個參數設置為 1，表示 semaphore 在多個程序之間共享
    // sem_init(&counter->sem, 0, 1);

    // 使用 sem_open 創建命名信號量，權限模式設置為 0644
    counter->sem = sem_open(sem_name, O_CREAT, 0644, 1);
    if (counter->sem == SEM_FAILED) {
        perror("sem_open failed");
        exit(EXIT_FAILURE);
    }
}

void increase_counter(counter_t *counter) {
    sem_wait(counter->sem);
    counter->count++;
    printf("Incremented: %d\n", counter->count);
    sem_post(counter->sem);
}

void decrease_counter(counter_t *counter) {
    sem_wait(counter->sem);
    counter->count--;
    printf("Decremented: %d\n", counter->count);
    sem_post(counter->sem);
}

void destroy_counter(counter_t *counter, const char *sem_name) {
    // ! sem_destroy deprecated in macOS
    // sem_destroy(&counter->sem);

    sem_close(counter->sem); // 關閉信號量
    sem_unlink(sem_name); // 刪除命名信號量
}

void *thread_function(void *arg) {
    counter_t *counter = (counter_t *)arg;
    for (int i = 0; i < 5; i++) {
        increase_counter(counter);
        sleep(1); // 模擬一些工作需要的時間，測試 semaphore 是否可以避免 Race Condition
        decrease_counter(counter);
    }

    return NULL;
}

int main(void) {
    const char *sem_name = "sem_test";
    counter_t counter;
    counter_init(&counter, sem_name);

    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_function, (void *)&counter);
    pthread_create(&t2, NULL, thread_function, (void *)&counter);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final count: %d\n", counter.count);

    destroy_counter(&counter, sem_name);
    return 0;
}