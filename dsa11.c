// implementation queue 

#include<stdio.h>
#include<stdlib.h>


struct QUEUE{
    int front;
    int rear;
    int size;
    int *ptr;
};

struct QUEUE* create(int size){
    struct QUEUE* Q;
    Q = (struct QUEUE*)malloc(sizeof(struct QUEUE));
    Q->rear = -1;
    Q->front =-1;
    Q->size = size;
    Q->ptr = (int *)malloc(sizeof(int)*size);
    return Q;
}

int isfull(struct QUEUE* Q){
    if(Q->rear +1== Q->size){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(struct QUEUE* Q){
    if(Q->rear == Q->front){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(struct QUEUE* Q, int data ){
    if(isfull(Q)){
        printf("queue is full\n");
    }
    else{
        Q->rear = Q->rear +1;
        Q->ptr[Q->rear]= data;
        printf("element enqueued is %d\n",data);
        
    }
}

int dequeue(struct QUEUE*Q){
    if(isempty(Q)){
        printf("queue is empty\n");
        return -1;
    }
    else{
        Q->front = Q->front+1;
        int data = Q->ptr[Q->front];
        printf("element dequeued is %d\n",data);
        return data;
    }
}
/*
int main(){
    struct QUEUE *q;
    q = create(5);
    enqueue(q,5);
    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,8);
    enqueue(q,9);
    enqueue(q,10);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
}*/