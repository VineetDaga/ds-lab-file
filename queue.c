// implementation queue

#include <stdio.h>
#include <stdlib.h>

struct QUEUE
{
    int front;
    int rear;
    int size;
    int *ptr;
};

struct QUEUE *create(int size)
{
    struct QUEUE *Q;
    Q = (struct QUEUE *)malloc(sizeof(struct QUEUE));
    Q->rear = -1;
    Q->front = -1;
    Q->size = size;
    Q->ptr = (int *)malloc(sizeof(int) * size);
    return Q;
}

int full(struct QUEUE *Q)
{
    if (Q->rear + 1 == Q->size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int empty(struct QUEUE *Q)
{
    if (Q->rear == Q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct QUEUE *Q, int data)
{
    if (full(Q))
    {
        printf("queue is full\n");
    }
    else
    {
        Q->rear = Q->rear + 1;
        Q->ptr[Q->rear] = data;
        printf("element enqueued is %d\n", data);
    }
}

int dequeue(struct QUEUE *Q)
{
    if (empty(Q))
    {
        printf("queue is empty\n");
        return -1;
    }
    else
    {
        
        int data = Q->ptr[Q->front];
        Q->front = Q->front + 1;
        printf("element dequeued is %d\n", data);
        return data;
    }
}

// circular queue

/*
   circular queue mei kuch nhi hota bas ek circular array bna dete h
   with the help of this syntax

   Q->rear ++ ke jagah hum use karte h
   Q->rear = (Q->rear +1)%Q->size;
   and we initiate the queue with
   rear = 0;
   front =0;
*/

/*
struct CQUEUE{
    int front;
    int rear;
    int size;
    int *ptr;
};

struct CQUEUE* create(int size){
    struct QUEUE* Q;
    Q = (struct CQUEUE*)malloc(sizeof(struct CQUEUE));
    Q->rear = 0;
    Q->front =0;
    Q->size = size;
    Q->ptr = (int *)malloc(sizeof(int)*size);
    return Q;
}

int isfull(struct CQUEUE* Q){
    //if(Q->rear +1== Q->size){
    if((Q->rear +1)%Q->size == Q->front){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(struct CQUEUE* Q){
    //  it will remain same
    if(Q->rear == Q->front){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct CQUEUE* Q, int data ){
    if(isfull(Q)){
        printf("queue is full");
    }
    else{
        Q->rear = (Q->rear +1)%Q->size;
        Q->ptr[Q->rear]= data;
        printf("element enqueued is %d",data);

    }
}

int dequeue(struct CQUEUE*Q){
    if(isempty(Q)){
        printf("queue is empty");
        return -1;
    }
    else{
        Q->front = (Q->front+1)%Q->size;
        int data = Q->ptr[Q->front];
        printf("element dequeued is %d",data);
        return data;
    }
}

*/
