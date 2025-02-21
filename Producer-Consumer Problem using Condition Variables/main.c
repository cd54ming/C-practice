#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_PRODUCERS 100
#define NUM_CONSUMERS 5
#define BUFFER_SIZE 200
#define NUM_ITEMS 10000

typedef struct buffer_t {
    int *buffer;
    int available;
    pthread_mutex_t lock;
    pthread_cond_t not_empty;
    pthread_cond_t not_full;
} buffer_t;

void buffer_init(buffer_t *buffer) {
    buffer->buffer = malloc(BUFFER_SIZE * sizeof(int));
    if (buffer->buffer == NULL) {
        perror("Failed to allocate buffer's memory");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer->buffer[i] = 0;
    }

    buffer->available = BUFFER_SIZE;

    pthread_mutex_init(&buffer->lock, NULL);
    pthread_cond_init(&buffer->not_empty, NULL);
    pthread_cond_init(&buffer->not_full, NULL);
}

void buffer_destroy(buffer_t *buffer) {
    free(buffer->buffer);
    pthread_mutex_destroy(&buffer->lock);
    pthread_cond_destroy(&buffer->not_empty);
    pthread_cond_destroy(&buffer->not_full);
}

void *Producer(void *arg) {
    buffer_t *buffer = (buffer_t *)arg;
    static int produced_count = 0;

    while (1) {
        pthread_mutex_lock(&buffer->lock);

        while (buffer->available == 0) {
            pthread_cond_wait(&buffer->not_full, &buffer->lock);
        }

        if (produced_count == NUM_ITEMS) {
            pthread_cond_broadcast(&buffer->not_empty);
            pthread_mutex_unlock(&buffer->lock);
            break;
        }

        for (int i = 0; i < BUFFER_SIZE; i++) {
            if (buffer->buffer[i] == 0) {
                int produced_item = ++produced_count;
                buffer->buffer[i] = produced_item;
                printf("Producer produce %d in buffer[%d]\n", produced_item, i);
                buffer->available--;
                pthread_cond_signal(&buffer->not_empty);
                break;
            }
        }

        pthread_mutex_unlock(&buffer->lock);
    }

    return NULL;
}

void *Consumer(void *arg) {
    buffer_t *buffer = (buffer_t *)arg;
    static int consumer_count = 0;

    while (1) {
        pthread_mutex_lock(&buffer->lock);

        while (buffer->available == BUFFER_SIZE) {
            if (consumer_count == NUM_ITEMS) {
                // 當某個 Producer 產出最後一個資料後，可能仍有其他 Producer 因為緩衝區已滿而處於等待狀態
                // 因此需要使用 broadcast 通知所有等待中的 Producer，以確保它們能夠正確退出
                pthread_cond_broadcast(&buffer->not_full);
                pthread_mutex_unlock(&buffer->lock);
                return NULL;
            }
            pthread_cond_wait(&buffer->not_empty, &buffer->lock);
        }

        for (int i = 0; i < BUFFER_SIZE; i++) {
            if (buffer->buffer[i] != 0) {
                int consumed_item = ++consumer_count;
                buffer->buffer[i] = 0;
                printf("Consumer consumed %d from buffer[%d]\n", consumed_item, i);
                buffer->available++;
                pthread_cond_signal(&buffer->not_full);
                break;
            }
        }

        pthread_mutex_unlock(&buffer->lock);
    }

    return NULL;
}

int main(void) {
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