#include<iostream>
using namespace std;

int linearSearch(int array[], int size, int key)
{
    for (int i = 0; i < size; i++){
        if (array[i] == key){
            return i;
        }
    }
    return -1;
}

int main(void){
    int arr[10] = {2,7,6,9,11,3,4,15,0,7};

    int location = linearSearch(arr, 10, 3);
    if(location==-1){
        cout << "Element not found in the array" << endl;
    }
    else{
        cout << "Element found at index: " << location << endl;
    }

    location = linearSearch(arr, 10, 8);
    if (location == -1)
    {
        cout << "Element not found in the array" << endl;
    }
    else
    {
        cout << "Element found at index: " << location << endl;
    }
}