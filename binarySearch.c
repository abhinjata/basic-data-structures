#include <stdio.h>

int binarySearch(int start, int end, int* arr, int target){

    if(start > end){
        return -1;
    }

    int middle = start + (end - start)/2;

    if(arr[middle] == target){

        return middle;
    }

    else if(arr[middle] > target){

        return binarySearch(start, middle - 1, arr, target);
    }

    else if(arr[middle] < target){

        return binarySearch(middle + 1, end, arr, target);
    }

}

