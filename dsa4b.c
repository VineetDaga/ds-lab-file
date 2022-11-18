#include<stdio.h>
#include<stdlib.h>

int main(){
    int m,n;
    //m is row capacity
    //n is col capacity
    printf("Enter the capacity in row and col of the 2D array \n");
    scanf("%d %d",&m,&n);
    
    int row, col=4;
    printf("Enter the size in row of the 2D array \n");
    scanf("%d",&row);

    int **arr =(int**)malloc(sizeof(int*)*m);
    for(int i=0;i<row;i++){
        arr[i]=(int*)malloc(sizeof(int)*col);
    }
    int k =1;
    printf("INPUT ELEMENT IN THE 2D ARRAY\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            arr[i][j]=k;
            k++;
        }
    }

    int pos;
    printf("Enter the row you want to delete :");
    scanf("%d",&pos);
    printf("\nBEFORE DELETION\n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    if(pos<0 || pos>row-1){
        printf("invalid index");
    }
    if(pos == row-1){
        free(arr[pos]);
        row--;
    }
    else if(pos<row-1){
        free(arr[pos]);
        int i =pos;
        while(i<row-1){
            arr[i]=arr[i+1];
            i++;
        }
        row--;
    }
    printf("\nAFTER DELETION \n");
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%d  ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
