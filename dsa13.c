#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct deque
{
    int front;
    int rear;
    int size;
    char *ptr;
};

struct deque *create(int size)
{
    struct deque *Q;
    Q = (struct deque *)malloc(sizeof(struct deque));
    Q->rear = -1;
    Q->front = -1;
    Q->size = size;
    Q->ptr = (char *)malloc(sizeof(char) * size);
    return Q;
}

int full(struct deque *Q)
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

int empty(struct deque *Q)
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

void enqueue(struct deque *Q, char data)
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

char dequeue_front(struct deque *Q)
{
    if (empty(Q))
    {
        printf("queue is empty\n");
        return'0' ;
    }
    else
    {
        Q->front = Q->front + 1;
        char data = Q->ptr[Q->front];
        printf("element dequeued is %d\n", data);
        return data;
    }
}
char dequeue_rear(struct deque *Q)
{
    if (empty(Q))
    {
        printf("queue is empty\n");
        return '0';
    }
    else
    {
        char data = Q->ptr[Q->rear];
        Q->rear = Q->rear - 1;
        printf("element dequeued is %d\n", data);
        return data;
    }
}
int main(){
    char str[] = "kanakm";
    struct deque *q = create(6);
    for (int i = 0; i < 6;i++){
        enqueue(q, str[i]);
    }
    int  c = 1;
    for (int i = 0; i < 6 / 2;i++){
        char a = dequeue_front(q);
        char b = dequeue_rear(q);
        if(a!=b){
            c = 0;
            break;
        }
    }
    if(c==1){
        printf("the given string is not palindrome \n");
    }else{
        printf("the given string is not a palindrome \n");
    }
}