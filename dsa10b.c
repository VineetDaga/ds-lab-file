#include<stdio.h>
#include<stdlib.h>
#include "sparse.c"

struct sparse * add(struct sparse *s1, struct sparse *s2){
    struct sparse *sum;
    int i,j,k;
    i=j=k=0;

    sum = (struct sparse*)malloc(sizeof(struct sparse));
    sum->ele = (struct element*)malloc((s1->num+s2->num)*sizeof(struct element));

    while(i<s1->num && j<s2->num){

        if(s1->ele[i].i<s2->ele[j].i){
            sum->ele[k++]=s1->ele[i++];
        }
        else if(s1->ele[i].i>s2->ele[j].i){
            sum->ele[k++]=s2->ele[j++];
        }
        else{
            if(s1->ele[i].j<s2->ele[j].j){
               sum->ele[k++]=s1->ele[i++];
            }
            else if(s1->ele[i].j>s2->ele[j].j){
               sum->ele[k++]=s2->ele[j++];
           }
           else{
               sum->ele[k]=s1->ele[i];
               sum->ele[k++].x = s1->ele[i++].x + s2->ele[j++].x;
           }
        }
    }
    for(;i<s1->num;i++){
        sum->ele[k++]=s1->ele[i];
    }
    for(;j<s2->num;j++){
        sum->ele[k++]=s2->ele[j];
    }

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;

    return sum;
}

int main (){
    struct sparse s1,s2,*s3;
    create(&s1);
    create(&s2);

    printf("ADDITION OF SPARSE MATRIX\n");

    s3 = add(&s1,&s2);
    printf("First matrix \n");
    display(&s1);
    printf("Second martrix \n");
    display(&s2);
    printf("sum matrix\n");
    display(s3);
}