#include<stdio.h>
#include<stdlib.h>

/* we are making a structure which will store the information about the array 
we are going to make infromation such as capacity , lastindex(basically size),
 and lastly the address of the array we are going to make */

struct arrayADT {
    int capacity; 
    int lastindex;
    int* ptr;
};

/* here are some function and operations we are going to perform on the array
 we going to make */

struct arrayADT* createArray(int capacity);
int getitem (struct arrayADT* arr, int index);
int setitem (struct arrayADT* arr, int index, int value);
int edititem (struct arrayADT* arr, int index, int newvalue);
int countitem (struct arrayADT* arr);
int removeitem (struct arrayADT* arr, int index);
int search (struct arrayADT* arr, int item);
void sort(struct arrayADT* arr);

/*the first function we are making is to create an array
1. the return type of the function is struct arrayADT* means it will be
   address of the structure in which we are going to store information about
   the array
2. then we will assign the memory it will required using the malloc function
3. assign the values of the capacity , lastindex,ptr.
and finally assign the given memory to the array we are making
*/

struct arrayADT* createArray(int capacity){
    struct arrayADT* arr;
    arr =(struct arrayADT*)malloc(sizeof(struct arrayADT));
    arr->capacity = capacity;
    arr->lastindex = -1;
    arr->ptr =(int *)malloc(capacity*sizeof(int));
    return arr;
}

// it will basically gives the value is stored in array at a given index
/* CONDITIONS 
1. The given index is valid or not.
*/

int getitem(struct arrayADT* arr, int index){
    if (index<0 || index>arr->lastindex){
        printf("Invalid Index\n");
        return (0);
    }
    else{
        return (arr->ptr[index]);
    }
}

/*
in the setitem function we can assign the value in the array and we can also 
insert an element using this function also 
CONDITIONS 
1. when the array is already full.
2. when the index provided is less than zero or greater than the
   lastindex+1 because we are inserting element in between no anywhere 
   in the array .
3. if the given index is in between 0 and the lastindex then we will insert 
   the element at that position and shift the next elements by order of 1 
   and also increse the count of lastindex.
4. and lastly if we have to insert an element right after the next index, 
   this will be done without shifting.
*/

int setitem (struct arrayADT* arr, int index, int value){
    int i;
    if (arr->lastindex == arr->capacity -1){
        printf("overflow\n");
        return (0);
    }
    if (index<0 ||index>arr->lastindex+1){
        printf("Invalid Index\n");
        return 0;
    }
    if(index<= arr->lastindex){
        arr->lastindex = arr->lastindex +1;
        i = arr->lastindex;
        while(i!=index){
            arr->ptr[i] = arr->ptr[i-1];
            i--;
        }
        arr->ptr[index]= value;
        return 1;
    }
    if (index == arr->lastindex+1){
        arr->lastindex = arr->lastindex +1;
        arr->ptr[arr->lastindex]= value;
        return 1;
    }
}

/*
in the edititem function we are just going to change the value in the array at a particular index that is provided by the user.
CONDITIONS
check whether th index is valid or not.
*/

int edititem(struct arrayADT* arr, int index, int newvalue){
    if (index<0 || index>arr->lastindex){
        printf("Ivalid Index");
        return 0;
    }
    else{
        arr->ptr[index]=newvalue;
        return 1;
    }
}

/*
  it will just count the number of items present in the array 
  lastindex +1
*/

int countitem(struct arrayADT* arr){
    return arr->lastindex +1;
}

/*
  this function will be used to delete an element in the array 
  and also update the lastindex 
  CONDITION
  1. index valid or not .
  2. index is valid but is between 0 and the lastindex we will delete the 
     element and shift the elements at the next indexs one place leftwards
  3. if the index provided is the lastindex then there is no need to shift 
      the elements
*/

int removeitem(struct arrayADT* arr, int index){
    if(index<0 || index>arr->lastindex){
        printf("invalid index");
        return 0;
    }
    else if (index<arr->lastindex){
        int i;
        i = index;
        while(i<arr->lastindex){
            arr->ptr[i]= arr->ptr[i+1];
            i++;
        }
        arr->lastindex = arr->lastindex-1;
        return 1;
    }
    else if(index == arr->lastindex){
        arr->lastindex = arr->lastindex -1;
        return 1;
    }
}

/*
search whether the element is there in the array or not
USING BINARY SEARCH
*/

int search(struct arrayADT* arr , int item ){
    int i=0;
    int j= arr->lastindex;
    int mid = i + (j-i)/2;
    while(i<=j){
        if (arr->ptr[mid]== item ){
            printf("item found ");
            return mid;
        }
        else if (arr->ptr[mid]>item){
            j= mid -1;
        }
        else {
            i = mid +1;
        }
        mid = i +(j-i)/2;
    }
    return -1;
}
/*search whether is element is ther or not in the array 
using linear search method */
int Lsearch(struct arrayADT* arr ,int item){
    int i = 0;
    int n = arr->lastindex;
    for(int i=0; i<=n;i++){
        if(arr->ptr[i]==item){
            return i;
        }
    }
    return -1;
}
/*
sorting the array using bubble sort technique
*/

void sort(struct arrayADT* arr){
    int r,n,i,t;
    n= arr->lastindex +1;
    for ( r= 1;r<n;r++){
        for (i =0; i<n-r; i++){
            if (arr->ptr[i]>arr->ptr[i+1]){
                t = arr->ptr[i];
                arr->ptr[i]=arr->ptr[i+1];
                arr->ptr[i+1]=t;
            }
        }
    }
}

void printarray(struct arrayADT* arr){
    int i=0; 
    for (i=0;i<countitem(arr);i++){
        printf("%d  ",arr->ptr[i]);
    }
    printf("\n");
}

