#include <stdio.h>

int main(void) {
    int n, top;
    printf("Input max array size : ");
    scanf("%d", &n);
    int a[n];
    printf("Input number of array elements : ");
    scanf("%d", &top);
    printf("Input array elements : ");
    for (int i = 0; i < top; i++)
        scanf("%d", &a[i]);
    printf("Array elements : ");
    for (int i = 0; i < top; i++)
        printf("%d ", a[i]);
    int mid = top / 2;
    for (int i = top; i > mid; i--)
        a[i] = a[i - 1];
    printf("\nInput the element to be inserted : ");
    scanf("%d", &a[mid]);
    top++;
    printf("Array elements after insertion : ");
    for (int i = 0; i < top; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}