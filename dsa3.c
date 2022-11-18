#include <stdio.h>
int *insertX(int n, int arr[], int x, int pos)
{
    int i;
    n++;
    for (i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = x;
    return arr;
}
int main()
{
    int arr[100] = {0};
    int i, x, pos, n = 10;
    // initial array of size 10
    for (i = 0; i < 10; i++)
        arr[i] = i + 1;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    x = 0;
    pos = n / 2;
    insertX(n, arr, x, pos);
    for (i = 0; i < n + 1; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}