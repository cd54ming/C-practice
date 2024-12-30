#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

typedef struct counter_t {
    int count;
} counter_t;

void increase_counter(counter_t *counter) {
    // counter = counter + 1; // have race condition
    __sync_fetch_and_add(&counter->count, 1);
    printf("Incremented: %d\n", counter->count);
}

void decrease_counter(counter_t *counter) {
    // counter = counter - 1; // have race condition
    __sync_fetch_and_sub(&counter->count, 1);
    printf("Decremented: %d\n", counter->count);
}

void *thread_function(void *arg) {
    counter_t *counter = (counter_t *)arg;
    for (int i = 0; i < 10; i++) {
        increase_counter(counter);
    }

    for (int i = 0; i < 5; i++) {
        decrease_counter(counter);
    }

    return NULL;
}

int main(void) {
    counter_t counter = {0};

    pthread_t t1, t2;

    pthread_create(&t1, NULL, thread_function, (void *)&counter);
    pthread_create(&t2, NULL, thread_function, (void *)&counter);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final count: %d\n", counter.count);

    return 0;
}