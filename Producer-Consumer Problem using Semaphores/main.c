#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <dispatch/dispatch.h>

#define NUM_PRODUCERS 10
#define NUM_CONSUMERS 5
#define BUFFER_SIZE 10
#define NUM_ITEMS 200

typedef struct buffer_t {
    int* buffer;
    pthread_mutex_t lock;

    // ! unnamed POSIX semaphore will be deprecated in macOS
    sem_t empty_slots;
    sem_t filled_slots;
    // * using GCD semaphores instead
    // dispatch_semaphore_t empty_slots;
    // dispatch_semaphore_t filled_slots;
} buffer_t;

void buffer_init (buffer_t *buffer) {
    buffer->buffer = (int *)malloc(BUFFER_SIZE * sizeof(int));
    if (buffer->buffer == NULL) {
        perror("Failed to allocate buffer's memory");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer->buffer[i] = 0;
    }

    pthread_mutex_init(&buffer->lock, NULL);

    sem_init(&buffer->empty_slots, 0, BUFFER_SIZE);
    sem_init(&buffer->filled_slots, 0, 0);
    // * GCD semaphores version
    // buffer->empty_slots = dispatch_semaphore_create(BUFFER_SIZE);
    // buffer->filled_slots = dispatch_semaphore_create(0);
}

void buffer_destroy (buffer_t *buffer) {
    free(buffer->buffer);
    pthread_mutex_destroy(&buffer->lock);

    sem_destroy(&buffer->empty_slots);
    sem_destroy(&buffer->filled_slots);
    // * GCD semaphores do not require explicit destruction
    // * Dispatch semaphores are automatically managed by ARC or can be manually retained/released
}

void *Producer(void *arg) {
    buffer_t *buffer = (buffer_t *)arg;
    static int produced_count = 0;

    while (1) {
        sem_wait(&buffer->empty_slots);
        // * GCD semaphores version
        // dispatch_semaphore_wait(buffer->empty_slots, DISPATCH_TIME_FOREVER);
        pthread_mutex_lock(&buffer->lock);

        if (produced_count == NUM_ITEMS) {
            pthread_mutex_unlock(&buffer->lock);
            sem_post(&buffer->filled_slots);
            // * GCD semaphores version
            // dispatch_semaphore_signal(buffer->filled_slots);
            break;
        }

        for (int i = 0; i < BUFFER_SIZE; i++) {
            if (buffer->buffer[i] == 0) {
                int produced_item = ++produced_count;
                buffer->buffer[i] = produced_item;
                printf("Producer produce %d in buffer[%d]\n", produced_item, i);
                break;
            }
        }

        pthread_mutex_unlock(&buffer->lock);
        sem_post(&buffer->filled_slots);
        // * GCD semaphores version
        // dispatch_semaphore_signal(buffer->filled_slots);
    }

    return NULL;
}

void *Consumer(void *arg) {
    buffer_t *buffer = (buffer_t *)arg;
    static int consumer_count = 0;

    while (1) {
        sem_wait(&buffer->filled_slots);
        // * GCD semaphores version
        // dispatch_semaphore_wait(buffer->filled_slots, DISPATCH_TIME_FOREVER);
        pthread_mutex_lock(&buffer->lock);

        if (consumer_count == NUM_ITEMS) {
            pthread_mutex_unlock(&buffer->lock);
            sem_post(&buffer->empty_slots);
            // * GCD semaphores version
            // dispatch_semaphore_signal(buffer->empty_slots);
            break;
        }

        for (int i = 0; i < BUFFER_SIZE; i++) {
            if (buffer->buffer[i] != 0) {
                int consumed_item = ++consumer_count;
                buffer->buffer[i] = 0;
                printf("Consumer consumed %d from buffer[%d]\n", consumed_item, i);
                break;
            }
        }

        pthread_mutex_unlock(&buffer->lock);
        sem_post(&buffer->empty_slots);
        // * GCD semaphores version
        // dispatch_semaphore_signal(buffer->empty_slots);
    }

    return NULL;
}

int main (void) {
    pthread_t producer_threads[NUM_PRODUCERS], consumer_threads[NUM_CONSUMERS];
    buffer_t buffer;

    buffer_init(&buffer);

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_create(&producer_threads[i], NULL, Producer, (void *)&buffer);
    }
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_create(&consumer_threads[i], NULL, Consumer, (void *)&buffer);
    }

    for (int i = 0; i < NUM_PRODUCERS; i++) {
        pthread_join(producer_threads[i], NULL);
    }
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(consumer_threads[i], NULL);
    }

    buffer_destroy(&buffer);
    return 0;
}