#include<stdio.h>
#include<stdlib.h>
#include "stack_impl.c"

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
}

void minpop(struct stack * s, int * min ){
    if(isempty(s)){
        printf("Error : STACK UNDERFLOW");
        return;
    }
    if(stacktop(s)<(*min)){
        *min = 2*(*min)-stacktop(s);
        pop(s);
    }else{
        pop(s);
    }
}


int main (){
    struct stack * s;
    s = Cstack(20);
    int n;
    int *min = &n;
    minpush(s,8,min);
    minpush(s,3,min);
    minpush(s,6,min);
    minpush(s,2,min);
    minpush(s,8,min);
    minpop(s,min);
    minpop(s,min);
    minpop(s,min);
    printf("%d",*min);


}