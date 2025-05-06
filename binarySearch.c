#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int n){

    for(int i = 0; i < n; i++){

        printf("%d ", arr[i]);
    }

}

int binarySearch(int* arr, int target, int start, int end){

    //error exit clause
    if(start > end){
        return -1;
    }

    //initialize the middle for every recursive step

    int middle = start + (end - start)/2;

    if(arr[middle] == target){

        return middle;
    }

    else if(arr[middle] > target){

        return binarySearch(arr, target, start, middle - 1);
    }

    else if (arr[middle] < target){

        return binarySearch(arr, target, middle + 1 , end);
    }

}

int main(void) {

    int target = 5;
    int arr[5] = {1, 3, 5, 7, 9};

    int size = sizeof(arr) / sizeof(arr[0]);

    int end = arr[size-1];

    //printArray(arr, n);

    int result = binarySearch(arr, target, 0, size - 1);

    if(result != -1){
        printf("Target found at index %d\n", result);

    }

    else{

        printf("Target not found.\n", target);
    }

    return 0;

}