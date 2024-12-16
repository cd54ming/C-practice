#include <pthread.h>
#include <stdio.h>

const short NUM_THREADS = 3;

void *addOne(void *arg) {
    int *num = (int *)arg;
    (*num)++;
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    for (short i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, addOne, (void *)&thread_args[i]);
    }

    for (short i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    for (short i = 0; i < NUM_THREADS; i++) {
        printf("thread[%d]'s arg now is: %d\n", i, thread_args[i]);
    }

    return 0;
}