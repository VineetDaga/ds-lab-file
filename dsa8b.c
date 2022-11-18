#include<stdio.h>
#include<stdlib.h>
#include"stack_impl.c"

void minpush(struct stack * s,int x, int * min){
    if(isfull(s)){
        printf("Error : STACK OVERFLOW");
        return;
    }if(isempty(s)){
        *min = x;
        push(s,x);
    }
    else{
        if(*min>x){
            push(s,2*x - (*min));
            *min = x;
        }
        else{
            push(s,x);
        }
    }
    printf("%d is pushed in the stack\n", x);
}

void minpop(struct stack * s, int * min ){
    if(isempty(s)){
        printf("Error : STACK UNDERFLOW");
        return;
    }
    int d = stacktop(s);
    if(stacktop(s)<(*min)){
        *min = 2*(*min)-stacktop(s);
        pop(s);
    }else{
        pop(s);
    }
    printf("%d is poppd out from the stack", d);
}


int main (){
    struct stack * s;
    s = Cstack(20);
    int n;
    int *min = &n;
    minpush(s,8,min);
    printf("%d is the min element is the stack\n", n);
    minpush(s,3,min);
    printf("%d is the min element is the stack\n", n);
    minpush(s,6,min);
    printf("%d is the min element is the stack\n", n);
    minpush(s,2,min);
    printf("%d is the min element is the stack\n", n);
    minpush(s,8,min);
    printf("%d is the min element is the stack\n", n);
    minpop(s,min);
    printf("%d is the min element is the stack\n", n);
    minpop(s,min);
    printf("%d is the min element is the stack\n", n);
    minpop(s,min);
    printf("%d is the min element is the stack\n", n);
}