#define MAX 101
#define TABLE printf("ROW\tCOL\tVAL\n")
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} element;

int main(void) {
    element a[MAX];
    printf("Enter the number of rows and columns of the matrix : ");
    scanf("%d %d", &a[0].row, &a[0].col);
    printf("Enter the non zero elements of the matrix : ");
    scanf("%d", &a[0].value);
    TABLE;
    for (int i = 1; i <= a[0].value; i++)
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    printf("Given Sparse Matrix is represented as : ");
    for (int i = 1; i <= a[0].value; i++)
        printf("%d\t%d\t%d\n", a[i].row, a[i].col, a[i].value);
    return 0;
}