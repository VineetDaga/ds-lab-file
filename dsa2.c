#include <stdio.h>

int binarySearch(int array[], int key, int right_index) {
    int left_index = 0;
    while (left_index <= right_index) {
        int mid_index = (left_index + right_index) / 2;
        int middle_element = array[mid_index];
        if (middle_element == key)
            return mid_index;
        else if (middle_element > key)
            right_index = mid_index - 1;
        else
            left_index = mid_index + 1;
    }
    return -1;
}

int main(void) {
    int size, key;
    printf("Input the size of sorted array (ascending) : ");
    scanf("%d", &size);
    int arr[size];
    printf("Input the %d elements : ", size);
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("Element to search for : ");
    scanf("%d", &key);
    int index = binarySearch(arr, key, size);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element doesn't exist in the array\n");
    return 0;
}