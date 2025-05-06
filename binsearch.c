#include <stdio.h>

void printArray(int n, int* arr); 
void insertionSort(int n, int* arr);
int binarySearch(int* arr, int start, int end, int target);
void selectionSort(int n, int* arr);

int main(void){

    int n = 5;
    int arr[5] = {2, 3, 4, 1, 5};

    int size = sizeof(arr)/sizeof(arr[0]);

    printArray(n, arr);
    printf("\n");

    selectionSort(n, arr);

    printArray(n, arr);

    int result = binarySearch(arr, 0, size - 1, 4);

    if(result != -1){

        printf("Item found at index %d!", result);

    }

    else{

        printf("Target not found.\n");
    }

    return 0;

}

void printArray(int n, int* arr){

    for(int i = 0; i < n; i++){

        printf("%d ", *(arr + i));
        
    }

}

void insertionSort(int n, int* arr){

    for(int i = 1; i <  n; i++){

        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){

            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

    }

}

void selectionSort(int n, int* arr){

    for(int i = 0; i < n - 1; i++){

        int min_index = i;

        for(int j = i + 1; j < n; j++){

            if(arr[min_index] > arr[j]){

                min_index = j;
            }

        }

        if(min_index != i){

            int temp = arr[min_index];
            arr[min_index] = arr[i];
            arr[i] = temp;

        }

    }
}

int binarySearch(int* arr, int start, int end, int target){

    if(start > end){

        return -1;
    }


    int middle = start + (end - start)/2;

    if(arr[middle] == target){

        return middle;

    }


    else if(arr[middle] > target){

        return binarySearch(arr, start, middle - 1, target);    
        
    }

    else if(arr[middle] < target){

        return binarySearch(arr, middle + 1, end, target);

    }


}