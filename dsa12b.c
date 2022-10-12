#include "queue.c"
#include "stack_impl.c"

void reverse(struct QUEUE *q, int k)
{
    int size = q->rear;
    if (empty(q) || k > size)
    {
        printf("ERROR\n");
        return;
    }
    struct stack *s;
    s = Cstack(k);
    for (int i = 0; i < k; i++)
    {
        push(s, dequeue(q));
    }
    for (int i = 0; i < k; i++)
    {
        enqueue(q, pop(s));
    }
    for (int i = 0; i < (size - k + 1); i++)
    {
        push(s, dequeue(q));
        enqueue(q, pop(s));
    }
}

void print(struct QUEUE *q)
{
    int k = q->rear;
    if (empty(q))
    {
        printf("EMPTY QUEUE");
        return;
    }
    for (int i = k; i != q->front; i--)
    {
        printf("%d \n", q->ptr[i]);
    }
}

int main()
{
    struct QUEUE *q;
    q = create(18);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    enqueue(q, 7);
    printf("queue before reversal\n");
    print(q);
    int k;
    printf("enter the value of k :");
    scanf("%d", &k);
    reverse(q, k);
    printf("queue after reversion\n");
    print(q);
}