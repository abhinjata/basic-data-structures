#include <stdio.h>

int printArray(int n, int* arr);
void insertionSort(int n, int* arr);
void bubbleSort(int n, int* arr);
void selectionSort(int n, int* arr);


int main(void){

    int n = 6;

    int arr[6] = {1, 3, 4, 2, 5, 6};

    printf("Before:");
    printArray(n, arr);

    printf("After:");
    selectionSort(n, arr);
    printArray(n, arr);


}

int printArray(int n, int* arr){

    for(int i = 0; i < n; i++){

        printf("%d ", *(arr + i));

    }

}

void insertionSort(int n, int* arr){

    for(int i = 1; i < n; i++){

        int key = arr[i]; //element to be sorted 
        int j = i - 1;

        //insertion clause
        while(j >= 0 /* for the smallest element*/ && arr[j] > key){

            arr[j + 1] = arr[j];
            j--;

        }
        arr[j + 1] = key;

    }


}

void bubbleSort(int n, int* arr){

    while(1==1){
        int i = 0;
        int swap = 0;

        while(i < n - 1){

            if(arr[i] > arr[i + 1]){

                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                swap = 1;
            }

            i = i + 1;
            

        }

        if(swap == 0){

            break;
        }

    }
}

void selectionSort(int n, int* arr){

    for(int i = 0; i < n - 1; i++){

        int min_index = i; 

        for(int j = i + 1; j < n; j++){

            if(arr[j] < arr[min_index]){

                min_index = j;

            }

        }

        if(min_index != i){

            //swap

            int temp = arr[min_index];
            arr[i] = arr[min_index];
            arr[min_index] = temp;

        }

    }
    
}