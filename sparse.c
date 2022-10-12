#include<stdio.h>
#include<stdlib.h>

struct element {
    int i;
    int j;
    int x;
};

struct sparse {
    int m;
    int n;
    int num;
    struct element *ele;
};

void create(struct sparse *s){
    printf("Enter dimensions :");
    scanf(" %d %d",&s->m,&s->n);
    printf("Number of non- zero elements :");
    scanf("%d",&s->num);

    s->ele = (struct element *)malloc(sizeof(struct element)* s->num);
    printf("Enter non zero elements\n");
    for(int i=0;i<s->num;i++){
        printf("Enter row :");
        scanf("%d",&s->ele[i].i);
        printf("Enter col :");
        scanf("%d",&s->ele[i].j);
        printf("Enter element :");
        scanf("%d",&s->ele[i].x);
    }
}

void display(struct sparse *s){
    int i,j,k=0;
    for(i=0;i<s->m;i++){
        for(j=0;j<s->n;j++){
            if(i == s->ele[k].i && j == s->ele[k].j){
                printf("%d ",s->ele[k++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}