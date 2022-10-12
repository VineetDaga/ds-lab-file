#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top1;
    int top2;
    int capacity;
    int *array;
} dualstack;

dualstack *createDualStack(int capacity) {
    dualstack *s = (dualstack *)malloc(sizeof(dualstack));
    s->array = (int *)malloc(sizeof(int) * capacity);
    s->top1 = -1;
    s->top2 = capacity;
    return s;
}

int isEmpty(dualstack *s, int stack_id) {
    if (stack_id == 1)
        return s->top1 == -1;
    if (stack_id == 2)
        return s->top2 == s->capacity;
    else
        printf("Invalid Stack ID");
    return 0;
}

void push(dualstack *s, int x, int stack_id) {
    if (s->top1 + 1 == s->top2) {
        printf("Error : Stack Overflow\n");
        return;
    }
    if (stack_id == 1){
        s->top1++;
        s->array[s->top1] = x;
    }
    else if (stack_id == 2){
        s->top2--;
        s->array[s->top2] = x;
    }
    else
        printf("Invalid Stack ID\n");
}

void pop(dualstack *s, int stack_id) {
    if (stack_id == 1) {
        if (s->top1 != -1)
            s->top1--;
        else
            printf("Stack 1 is already empty\n");
    } else if (stack_id == 2) {
        if (s->top2 != s->capacity)
            s->top2++;
        else
            printf("Stack 2 is already empty\n");
    } else
        printf("Invalid Stack ID\n");
}

int top(dualstack *s, int stack_id) {
    if (stack_id == 1) {
        if (!isEmpty(s, 1))
            return s->array[s->top1];
    } else if (stack_id == 2) {
        if (!isEmpty(s, 2))
            return s->array[s->top2];
    } else
        printf("Invalid Stack ID");
    return -1;
}
void displayStackTop(dualstack *s) {
    printf("Stack 1 : %d\n", top(s, 1));
    printf("Stack 2 : %d\n\n", top(s, 2));
}

int isFull(dualstack *s) { return s->top1 == s->top2 - 1; }

int main(void) {
    dualstack *s = createDualStack(10);

    printf("Stack 1 is empty : %d\n", isEmpty(s, 1));
    printf("Stack 2 is empty : %d\n", isEmpty(s, 2));
    printf("Stack is full : %d\n\n", isFull(s));

    push(s, 1, 1);
    push(s, 2, 2);
    push(s, 3, 1);
    push(s, 4, 1);
    push(s, 5, 2);
    push(s, 6, 1);
    displayStackTop(s);

    pop(s, 1);
    displayStackTop(s);

    push(s, 7, 1);
    push(s, 8, 2);
    push(s, 9, 2);
    displayStackTop(s);

    push(s, 10, 1);
    push(s, 11, 2);
    displayStackTop(s);

    push(s, 12, 1); // should give stack overflow
    pop(s, 2);      // make space from stack 2
    push(s, 12, 1); // use that empty space for stack 1
    displayStackTop(s);

    printf("Stack 1 is empty : %d\n", isEmpty(s, 1));
    printf("Stack 2 is empty : %d\n", isEmpty(s, 2));
    printf("Stack is full : %d\n", isFull(s));

    return 0;
}