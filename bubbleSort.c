#include <stdio.h>
#include <stdlib.h>

void makeArray(int n, int* arr, int max, int min){


    for(int i = 0; i < n; i++){

        *(arr + i) = rand()%(max - min + 1) + min;
    }

    return;
}

void printArray(int* arr, int n){

    for(int i = 0; i < n; i++){

        printf("%d \n", *(arr + i));
    }
}

void bubbleSort(int* arr, int n){

    while(1 == 1){

        int swap = 0;
        int i = 0;

        while(i < n - 1){

            if(arr[i] > arr[i+1]){

                //bubble it up -> arr[i] < arr[i+1] => bubble it down

                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;

                swap = 1;
            }
            i = i + 1;

        }
        
        if(swap == 0){

            break;
        }

    }

}

int main(void) {

    int max = 500;
    int min = 100;

    int n; 
    scanf("%d", &n);

    int* arr = malloc(n*sizeof(int)); 

    makeArray(n, arr, max, min);

    printf("Before: \n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("After: \n");
    printArray(arr, n);

    free(arr);

}