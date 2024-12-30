#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int count;
    pthread_mutex_t lock;
} counter_t;

void counter_init(counter_t *counter) {
    counter->count = 0;
    pthread_mutex_init(&counter->lock, NULL);
}

void increase_counter(counter_t *counter) {
    pthread_mutex_lock(&counter->lock);
    counter->count++;
    printf("Incremented: %d\n", counter->count);
    pthread_mutex_unlock(&counter->lock);
}

void decrease_counter(counter_t *counter) {
    pthread_mutex_lock(&counter->lock);
    counter->count--;
    printf("Decremented: %d\n", counter->count);
    pthread_mutex_unlock(&counter->lock);
}

void counter_destroy(counter_t *counter) {
    pthread_mutex_destroy(&counter->lock);
}

void *thread_function(void *arg) {
    counter_t *counter = (counter_t *)(arg);
    for (int i = 0; i < 5; i++) {
        increase_counter(counter);
    }

    for (int i = 0; i < 2; i++) {
        decrease_counter(counter);
    }

    int *result = malloc(sizeof(int));
    if (result == NULL) {
        perror("failed to allocate memory");
        pthread_exit(NULL);
    }

    *result = counter->count;
    return result;

    // * If the thread's result is not needed, can return NULL
    // return NULL;
}

int main(void) {
    counter_t counter;
    counter_init(&counter);

    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_function, (void *)&counter);
    pthread_create(&t2, NULL, thread_function, (void *)&counter);

    // * Use pthread_join's second parameter to receive the thread's return value
    int *retval1;
    int *retval2;

    pthread_join(t1, (void **)&retval1);
    pthread_join(t2, (void **)&retval2);

    printf("t1 result is: %d\n", *retval1);      // 3
    printf("t2 result is: %d\n", *retval2);      // 6
    printf("final result: %d\n", counter.count); // 6

    free(retval1);
    free(retval2);

    counter_destroy(&counter);
    return 0;
}