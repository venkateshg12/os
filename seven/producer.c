#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int count = 0;
sem_t mutex;
sem_t full;
sem_t empty;

void *producer(void* arg){
    int item = 1;
    while(1) {
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[count] = item;
        printf("Producer produced item %d at position %d\n", item , count);
        count++;
        item++;
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
}

void *consumer(void * arg){
    while(1){
        sem_wait(&full);
        sem_wait(&mutex);
        int item = buffer[count - 1];
        printf("Consumer problem item %d  from position %d\n", item ,count - 1);
        count--;
        sem_post(&mutex);
        sem_post(&empty);
        sleep(1);
    }
}

int main() {
    pthread_t prod, cons;

    sem_init(&mutex , 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, BUFFER_SIZE);

    pthread_create(&prod,NULL,producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&mutex);
    sem_destroy(&full);
    sem_destroy(&empty);
    return 0;
}