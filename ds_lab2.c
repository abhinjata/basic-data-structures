
#include <stdio.h>
#include <stdlib.h>

#define B 10

//i learnt signatures in CS50 i didnt gpt this

void printArray(int n, int* arr);
void bubbleSort(int n, int* arr, int showSteps);
void insertionSort(int* arr, int n, int showSteps);
void selectionSort(int* arr, int n, int showSteps);
void quickSort(int* arr, int low, int high, int showSteps);
int partition(int* arr, int low, int high, int showSteps);
void bucketSort(int* arr, int n, int showSteps);

int main(void) {
    int choice, n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0){

        printf("Invalid array size!!\n");
        return 1;
    }
    
    int arr[n];

    printf("Enter array elements (space-separated): ");

    for (int i = 0; i < n; i++){

        scanf("%d", &arr[i]);
    }
    
    printf("Sorting Algorithm Menu:\n");
    printf("1. Insertion Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Quick Sort\n");
    printf("5. Bucket Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    char showStep;
    printf("Do you want to see intermediate passes? (y/n): ");

    scanf(" %c", &showStep);

    int showSteps;
    if (showStep == 'Y' || showStep == 'y'){
        showSteps = 1;
    } 
    else {
        showSteps = 0;
    }
    
    if (choice == 1){
        insertionSort(arr, n, showSteps);
    } 
    else if (choice == 2){
        selectionSort(arr, n, showSteps);
    } 
    else if (choice == 3){
        bubbleSort(n, arr, showSteps);
    } 
    else if (choice == 4){
        quickSort(arr, 0, n - 1, showSteps);
    } 
    else if (choice == 5){
        bucketSort(arr, n, showSteps);
    }
    else{
        printf("Invalid choice!\n");
        return 1;
    }
    
    printf("Sorted Array: ");
    printArray(n, arr);
    return 0;
}

void printArray(int n, int* arr){

    for (int i = 0; i < n; i++){

        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void bubbleSort(int n, int* arr, int showSteps){

    while(1==1){
      
        int swap = 0;
        int i = 0; 
      
        while(i < n - 1){

            if(arr[i] > arr[i + 1]){

                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
              
                swap = 1;
            }
            i++;

            if (showSteps){
                printf("Pass %d: ", i + 1);
                printArray(n, arr);
            }
        }
        if(swap == 0){

            break;
        }
    }
}

void insertionSort(int* arr, int n, int showSteps){
    for (int i = 1; i < n; i++){
      
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
  
            arr[j + 1] = arr[j];
            j--;
          
        }
        arr[j + 1] = key;
      
        if (showSteps){
            printf("Pass %d: ", i);
            printArray(n, arr);
        }
    }
}

void selectionSort(int* arr, int n, int showSteps){

    for (int i = 0; i < n - 1; i++){

        int minIdx = i;

        for (int j = i + 1; j < n; j++){

            if (arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }

        //swap
        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;

        if(showSteps){
            printf("Pass %d: ", i + 1);
            printArray(n, arr);
        }
    }
}

int partition(int* arr, int low, int high, int showSteps){

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){

        if (arr[j] < pivot){
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    if(showSteps){
        printf("Partition step: ");
        printArray(high - low + 1, &arr[low]);
    }
    return i + 1;
}

void quickSort(int* arr, int low, int high, int showSteps){

    if(low < high){

        int pi = partition(arr, low, high, showSteps);
        quickSort(arr, low, pi - 1, showSteps);
        quickSort(arr, pi + 1, high, showSteps);

    }
}

void bucketSort(int* arr, int n, int showSteps){

    int min = arr[0], max = arr[0];

    for(int i = 1; i < n; i++) {  

        if(arr[i] > max) max = arr[i];  

        if(arr[i] < min) min = arr[i];  
    }


    int range = (max - min + 1)/ B + 1;

    int buckets[B][n];
    int bucketSizes[B] = {0};

    for(int i = 0; i < n; i++){

        int bucketIndex = (arr[i] - min) / range;
        if (bucketIndex >= B) bucketIndex = B - 1;
        
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];

    }

    for(int i = 0; i < 2; i++){

        if(i % 2 == 0) insertionSort(bucketSizes[i], buckets[i]);

        else selectionSort(bucketSizes[i], buckets[i]);

    }

    if(showSteps){

        for (int i = 0; i < BUCKET_SIZE; i++){

            if (bucketCount[i] > 0) {
                printf("Bucket %d: ", i);
                printArray(bucketCount[i], buckets[i]);
            }
        }
    }

    mergeBuckets(arr, buckets, bucketSizes);

}

void mergeBuckets(int* arr, int buckets[B][100], int bucketSizes[B]){

    int index = 0; 

    for(int i = 0; i < 2; i++){

        for(int j = 0; j < bucketSizes[i]; j++){

            arr[index++] = buckets[i][j];

        }

    }


}