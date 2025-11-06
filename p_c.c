#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t e, f, s;
int in=0, out=0;
int buff[5];

void *producer(void *arg) {
    sem_wait(&e);
    sem_wait(&s);
    buff[in]=rand()%10;
    printf("\nProducer has put data=%d", buff[in]);
    in=(in+1)%5;
    sem_post(&s);
    sem_post(&f);
}

void *customer(void *arg) {
    int status;
    do {
        sem_wait(&f);
        sem_wait(&s);
        printf("\n Data consumed by Consumer is %d", buff[out]);
        out=(out+1)%5;
        sem_post(&s);
        sem_post(&e);
        sem_getvalue(&e, &status);
    } while(status != 5);
}

int main() {
    pthread_t p[8], c;
    sem_init(&f, 0, 0);
    sem_init(&e, 0, 5);
    sem_init(&s, 0, 1);
    for(int i=0; i<8; i++) {
        pthread_create(&p[i], NULL, producer, NULL); // Note: producer, not Producer
    }
    pthread_create(&c, NULL, customer, NULL); // Note: customer, not customer
    for(int i=0; i<8; i++) {
        pthread_join(p[i], NULL);
    }
    pthread_join(c, NULL);
    printf("\n");
}
