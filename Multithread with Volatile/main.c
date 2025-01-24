#include <stdbool.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

volatile bool is_task_2_done = false;

void *process_task_2(void *arg) {
    printf("Starting Task 2...\n");
    sleep(2);
    is_task_2_done = true;
    printf("Task 2 completed!\n");
    return NULL;
}

void *process_task_1(void *arg) {
    printf("Starting Task 1...\n");
    while (!is_task_2_done) {
        // lightweight busy waiting，避免過度佔用 CPU 資源
        // 如果任務處理時間較長，應改用 condition variable
        usleep(100);
    }
    printf("Task 1 completed!\n");
    return NULL;
}

int main(void) {
    pthread_t task_1_thread;
    pthread_t task_2_thread;

    pthread_create(&task_1_thread, NULL, process_task_1, NULL);
    pthread_create(&task_2_thread, NULL, process_task_2, NULL);

    pthread_join(task_1_thread, NULL);
    pthread_join(task_2_thread, NULL);

    return 0;
}