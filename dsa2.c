#include <stdio.h>
#include <stdlib.h>

int binarySearch(int array[], int key, int right_index)
{
    int left_index = 0;
    while (left_index <= right_index)
    {
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

int main(void)
{
    int arr[10] = {0, 2, 3, 9, 11, 15, 22, 27, 37, 42};

    int index = binarySearch(arr, 22, 10);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element doesn't exist in the array\n");

    index = binarySearch(arr, 16, 10);
    if (index != -1)
        printf("Element found at index %d\n", index);
    else
        printf("Element doesn't exist in the array\n");

    return 0;
}