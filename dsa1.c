#include <stdio.h>
#include <stdlib.h>

int linearSearch(int array[], int size, int key)
{
    for (int i = 0; i < size; i++){
        if (array[i] == key){
            return i;
        }
    }
    return -1;
}

int main(void)
{
    int size, key;
    printf("Enter the size of array : ");
    scanf("%d", &size);
    int *arr=(int *)malloc(sizeof(int)*size);
    printf("Input the %d elements : ", size);

    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("Element to search for : ");
    scanf("%d", &key);
    int index = linearSearch(arr, size, key);
    
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element doesn't exist in the array\n");
    return 0;
}