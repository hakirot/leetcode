// Quicksort in C

#include <stdio.h>

// Function to swap elements
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high){

    // Select the rightmost element as pivot
    int pivot = array[high];

    // Pointer for greater element
    int i = (low - 1);

    // Traverse each element of the array               int data[] = {8, 7, 2, 1, 0, 9, 6};
    // Compare them with the pivot
    for(int j = low; j < high; j++){
        if(array[j] <= pivot){

            // If element smaller than pivot is found, swap it with the greater element pointed by i
            i++;

            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }

    // Swap the pivot element with the greater element at i
    swap(&array[i + 1], &array[high]);

    // Return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high){
    if(low < high){
        // Find the pivot element such that elements smaller than pivot are left of pivot, and
        // elements greater tha pivot are on the right of pivot
        int pi = partition(array, low, high);

        // Recursive call on the left of pivot
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void printArray(int array[], int size){
    for(int i = 0; i < size; i++){
        printf("%d  ", array[i]);
    }
    printf("\n");
}

int main(int argc, char * argv[]){

    int data[] = {8, 7, 2, 1, 0, 9, 6};

    int n = sizeof(data) / sizeof(data[0]);

    printf("Unsorted Array:\n");
    printArray(data, n);

    // do quicksort
    quickSort(data, 0, n - 1);

    printf("Sorted Array:\n");
    printArray(data, n);

    return 0;
}
