#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int front;
    int rear;
    int *arr;
    int capacity;
} queue;

queue *createQ(int capacity) {
    queue *q = malloc(sizeof(queue *));
    q->arr = malloc(sizeof(int) * capacity);
    q->capacity = capacity;
    q->front = q->rear = -1;
    return q;
};

char isQueueEmpty(queue *q) {
    if (q->front == q->rear && q->front == -1)
        return 1;
    return 0;
};

char isQueueFull(queue *q) {
    if (q->rear == q->capacity - 1)
        return 1;
    return 0;
};

void showQ(queue *q) {
    printf("Queue : ");
    for (int i = q->front; i <= q->rear; i++)
        printf("%d ", q->arr[i]);
    printf("\n");
}

void enqueue(queue *q, int value) {
    if (isQueueFull(q)) {
        printf("ERROR : Queue is full\n");
        return;
    }
    if (isQueueEmpty(q)) {
        q->arr[0] = value;
        q->front = q->rear = 0;
        return;
    }
    q->arr[++q->rear] = value;
};

void dequeue(queue *q) {
    if (isQueueEmpty(q)) {
        printf("ERROR : Queue is empty\n");
        return;
    }
    q->front++;
    if (q->front > q->rear){
        q->front = q->rear = -1;
    }
};

int peek(queue *q) {
    if (isQueueEmpty(q)) {
        printf("ERROR : Queue is empty\n");
        exit(-1);
    }
    return q->arr[q->front];
};