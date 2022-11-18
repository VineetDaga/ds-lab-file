#include<stdio.h>
#include<stdlib.h>
#include"stack_impl.c"

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
     printf("%d is pushed in the stack\n",x);
     return;
}

void minpop(struct stack *s,struct stack*ss){
    if(isempty(s)){
        printf("Error: STACK UNDERFLOW");
        return;
    }
    int d = stacktop(s);
    if(stacktop(s)==stacktop(ss)){
        pop(s);
        pop(ss);
    }
    else{
        pop(s);
    }
    printf("%d is poppd out from the stack",d);
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
    printf("%d is the min element is the stack\n", min(ss));
    minpush(s,ss,5);
    printf("%d is the min element is the stack\n", min(ss));
    minpush(s,ss,78);
    printf("%d is the min element is the stack\n", min(ss));
    minpush(s,ss,12);
    printf("%d is the min element is the stack\n", min(ss));
    minpush(s,ss,3);
    printf("%d is the min element is the stack\n", min(ss));
    minpop(s,ss);
    printf("%d is the min element is the stack\n",min(ss));
return 0;
}