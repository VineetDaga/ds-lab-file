#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int* ptr;
};

struct stack* Cstack(int size){
    struct stack* STACK;
    STACK = (struct stack*)malloc(sizeof(struct stack));
    STACK->size = size;
    STACK->top = -1;
    STACK->ptr = (int*)malloc(size*sizeof(int));
    return STACK;
}

int isfull(struct stack* STACK){
    if (STACK->top == STACK->size -1){
        return 1 ;
    }
    else{
        return 0;
    }
}

int isempty(struct stack* STACK){
    if(STACK->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* STACK,int value){
    if (isfull(STACK)){
        printf("STACK OVERFLOW \n");
        return ;
    }
    else{
        STACK->top++;
        STACK->ptr[STACK->top]= value;
    }
}

int pop(struct stack* STACK){
    if (isempty(STACK)){
        printf("STACK UNDERFLOW \n");
        return 0;
    }
    else{
        int value = STACK->ptr[STACK->top];
        STACK->top--;
        return value;
    }
}

int peek(struct stack* STACK, int position){
    if(position<0 || position>STACK->top){
        printf("INVALID POSITION \n");
        return 0;
    }
    else{
        int index = STACK->top - position +1;
        int value;
        value = STACK->ptr[index];
        return value;
    }
}

int stacktop(struct stack* STACK){
    if(isempty(STACK)){
        printf("STACK IS EMPTY \n");
        return 0;
    }
    else{
        return STACK->ptr[STACK->top];
    }
}

int stackbottom(struct stack* STACK){
    if(isempty(STACK)){
        printf("STACK IS EMPTY \n");
        return 0;
    }
    else{
        int bottom;
        bottom = STACK->ptr[0];
        return bottom;
    }
}


void minpush(struct stack * s,struct stack *ss,int x){
    if(isfull(s)){
        printf("Error: STACK OVERFLOW");
        return;
    }
    if(isempty(s) || stacktop(ss)>x){
        push(s,x);
        push(ss,x);
    }
     else{
        push(s,x);
     }
     return;
}

void minpop(struct stack *s,struct stack*ss){
    if(isempty(s)){
        printf("Error: STACK UNDERFLOW");
        return;
    }
    else if(stacktop(s)==stacktop(ss)){
        pop(s);
        pop(ss);
    }
    else{
        pop(s);
    }
    return;
}

int min(struct stack * ss){
    if(isempty(ss)){
        printf("NO ELEMENT IN THE STACK");
        return -1;
    }else{
        return stacktop(ss);
    }
}

int main (){
   struct stack *s;
    struct stack *ss;
    s = Cstack(20);
    ss = Cstack(20);
    minpush(s,ss,9);
    minpush(s,ss,5);
    minpush(s,ss,78);
    minpush(s,ss,12);
    minpush(s,ss,3);
    minpop(s,ss);
    printf("%d",min(ss));
    
   printf("hello");
    printf("\n");
return 0;
}