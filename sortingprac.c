#include <stdio.h>
#include <stdlib.h>

#define B 10

void printArray(int n, int* arr);
void bubbleSort(int n, int* arr);
void insertionSort(int n, int* arr);
void selectionSort(int n, int* arr);
void bucketSort(int n, int* arr);
void quickSort(int* arr, int low, int high);
int partition(int* arr, int low, int high);
void mergeBuckets(int* arr, int buckets[B][100], int bucketSizes[B]);

int main(void){

    int n = 6; 

    int arr[6] = {3, 2 , 5, 1 ,2 };

    printf("Before: ");
    printArray(n , arr);

    printf("After: ");
    printArray(n, arr);

}

void printArray(int n, int* arr){

    for(int i = 0; i < n; i++){

        printf("%d", *(arr + i));

    }
}

void insertionSort(int n, int* arr){

    for(int i = 1; i < n; i++){

        int key = arr[i];
        int j = i - 1;

        while(j > 0 && arr[j] > arr[key]){

            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = arr[key];
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

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

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

            i++;
        }
        if (swap == 0) {

            break;
        }


    }

}

int selectionSort(int n, int * arr){

    for(int i = 0; i < n - 1; i++){

        int min_index = i;

        for(int j = i - 1; j < n; j++){

            if(arr[j] < arr[min_index]){

                min_index = j;
            }

        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }

}

void insertionSort(int n, int* arr){

    for(int i = 0; i < n - 1; i++){

        int key = arr[i];
        int j = i - 1;

        while(j > 0 && arr[j] > arr[key]){

            arr[j + 1] = arr[j];
            j--;

        }
        arr[j + 1] = arr[key];

    }

}

void bucketSort(int n, int* arr){

    //1. find max and min

    int max = arr[0], min = arr[0];

    for(int i = 0; i < n; i ++){

        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];

    }

    int range = (max - min + 1)/B + 1;

    int buckets[B][n];
    int bucketCount[B] = {0};
    
    for(int i = 0; i < n; i++){

        int bucketIndex = (arr[i] - min) / range;
        if(bucketIndex >= B) bucketIndex = B - 1; 

        buckets[bucketIndex][bucketCount[bucketIndex++]] = arr[i];

    }

    for(int i = 0; i < B; i++){

        if(i % 2 == 0) insertionSort(bucketCount[i], buckets[i]);
        else selectionSort(bucketCount[i], buckets[i]);

    }

}

void mergeBuckets(int* arr, int buckets[B][100], int bucketSizes[B]){

    int index = 0;

    for(int i = 0; i < B; i++){

        for(int j = 0; j < bucketSizes[i]; j++){

            arr[index++] = buckets[i][j];

        }

    }


}

int partition(int* arr, int low, int high){

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){

        if(arr[j] < pivot){

            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

}

void quickSort(int* arr, int low, int high){

    if(low > high){

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
    
}

int partition(int* arr, int low, int high){

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){

        if(arr[i] < pivot){

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
        }

    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i  + 1;

}

void quickSort(int* arr, int low, int high){

    if(low < high){

        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);

    }

}

int binarySearch(int target, int low, int high, int* arr){

    if(low > high){

        return -1;

    }

    int middle = low + (high - low)/2;

    if(arr[middle] == target){

        return middle;

    }

    else if((arr[middle]) > target){

        return binarySearch(target, middle + 1, high, arr);

    }

    else if((arr[middle]) < target){

        return binarySearch(target, low, middle - 1, arr);

    }
}

void merge(int* arr, int low, int middle, int high){

    int leftSize = middle - low + 1;
    int rightSize = high - middle;

    //temp arrays

    int leftArr[leftSize], rightArr[rightSize];

    //COPYING the data into temp arrays

    for(int i = 0; i < leftSize; i++) leftArr[i] = arr[low + i];

    for(int j = 0; j < rightSize; j++) rightArr[j] = arr[middle + 1 + j];

    // merge the temp arrays back into the original array 

    int leftIndex = 0, rightIndex = 0, mergeIndex = low;

    while(leftIndex < leftSize && rightIndex < rightSize){

        if(leftArr[leftIndex] <= rightArr[rightIndex]){

            arr[mergeIndex] = leftArr[leftIndex];
            leftIndex++;
        }

        else{

            arr[mergeIndex] = rightArr[rightIndex];
            rightIndex++;

        }
        mergeIndex++;

    }

    while(leftIndex < leftSize){

        arr[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;

    }

    while (rightIndex < rightSize)
    {
        arr[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
    }

}

void mergeSort(int* arr, int low, int high){

    if(low < high){

        int middle = low + (high - low)/2;

        mergeSort(arr, low, middle - 1);
        mergeSort(arr, middle + 1, high);
        merge(arr, low, middle, high);

    }

}

void merge(int* arr, int low, int middle, int high){

    //1. Initialize the left and right sizes

    int leftSize = middle - low + 1;
    int rightSize = high - middle;

    //1.2 make temp arrays

    int leftArr[leftSize], rightArr[rightSize];

    //1.3 copy the data into the temp arrays 

    for(int i = 0; i < leftSize; i++) leftArr[leftSize] = arr[low + i];
    for(int j = 0; j < rightSize; j++) rightArr[rightSize] = arr[middle + 1 + j];

    //1.4 merge the temp arrays into the original array

    int leftIndex = 0, rightIndex = 0, mergeIndex = low;

    while(leftIndex < leftSize && rightIndex < rightSize){

        if(leftArr[leftIndex] <= rightArr[rightIndex]){

            arr[mergeIndex] = leftArr[leftIndex];
            leftIndex++;

        }

        else{

            arr[mergeIndex] = rightArr[rightIndex];
            rightIndex++;

        }

        mergeIndex++;

    }

    while (leftIndex < leftSize){

        arr[mergeIndex] = leftArr[leftIndex];
        leftIndex++;
        mergeIndex++;
    }

    while(rightIndex < rightSize){

        arr[mergeIndex] = rightArr[rightIndex];
        rightIndex++;
        mergeIndex++;
        
    }
    
}

void mergeSort(int* arr, int low, int high){

    if(low < high){

        int middle = low + (high - low)/2;

        mergeSort(arr, low, middle - 1);
        mergeSort(arr, middle + 1, high);
        merge(arr, low, middle, high);

    }
}

void bucketSort(int n, int* arr){

    //1. find max and min

    int max = arr[0], min = arr[0];

    for(int i = 0; i < n; i ++){

        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];

    }

    int range = (max - min + 1)/B + 1;

    int buckets[B][n];
    int bucketCount[B] = {0};
    
    for(int i = 0; i < n; i++){

        int bucketIndex = (arr[i] - min) / range;
        if(bucketIndex >= B) bucketIndex = B - 1; 

        buckets[bucketIndex][bucketCount[bucketIndex++]] = arr[i];

    }

    for(int i = 0; i < B; i++){

        if(i % 2 == 0) insertionSort(bucketCount[i], buckets[i]);
        else selectionSort(bucketCount[i], buckets[i]);

    }

}

void mergeBuckets(int* arr, int buckets[B][100], int bucketSizes[B]){

    int index = 0;

    for(int i = 0; i < B; i++){

        for(int j = 0; j < bucketSizes[i]; j++){

            arr[index++] = buckets[i][j];

        }

    }


}

void bucketSort(int* arr, int n){

    //1. find the min and max

    int max = arr[0], min = arr[0];

    for(int i = 0; i < n; i++){

        if(arr[i] > max) max = arr[i];
        if(arr[i] < min) min = arr[i];
    }

    //1.2 initialize the range

    int range = (max - min + 1)/B + 1;

    //1.3 initialize the buckets and their count

    int buckets = [B][n];
    int bucketsCount[B] = 0;
    
    for(int i = 0; i < n; i++){

        int bucketIndex = (arr[i] - min)/ range;

        if(bucketIndex >= B){

            bucketIndex = B - 1;
            
        }

        buckets[bucketIndex][bucketCount[bucketIndex++]] = arr[i];

    }

    for(int i = 0; i < B; i++){

        if(i % 2 == 0) selectionSort(bucketsCount[i], buckets[i]);
        else quickSort(bucketsCount[i], buckets[i]);

    }


}

void mergeBuckets(int* arr, int buckets[B][100], int bucketSizes[B]){

    int index = 0;

    for(int i = 0; i < B; i++){

        for(int j = 0; j < bucketSizes[i]; j++){

            arr[index++] = buckets[i][j];

        }

    }

}

int partition(int* arr, int low, int high){

    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){

        if(arr[j] < pivot){

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;

}

void quickSort(int* arr, int low, int high){

    int(low < high){

        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);

        
    }

}