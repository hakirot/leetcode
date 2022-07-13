// C program for Merge Sort O(n log n)
#include <stdio.h>

void PrintArray(int array[], int size);
void Merge(int array[], int l, int m, int r);
void MergeSort(int array[], int l, int r);

int main(int argc, char * argv[]){

    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);
    //printf("Array is size: %d", size);

    PrintArray(array, size);
    MergeSort(array, 0, size - 1);
    PrintArray(array, size);

    return 0;
}

void PrintArray(int array[], int size){
    printf("Array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

// l is for the left index and r is the right index of the subarray of array to be sorted
void MergeSort(int array[], int l, int r){

    if(l < r){
        // Same as (l + r)/ 2, but avoids overflow for large l and h
        // First iteration: 0 + (9 - 0) / 2 = 4
        // m = 4
        int m = l + (r - l) / 2;

        // Sort first and second halves
        MergeSort(array, l, m); // First half (0, 4), then (0, 2), then (0, 1), then (0, 0) aka null operation
        MergeSort(array, m + 1, r); // Second half (5, 9)

        // All MergeSorts are called until they are working with arrays of size one, then they call call Merge
        Merge(array, l, m, r);
    }
}

/* Merges two subarrays if array[]
 * First subarray is array[l .. m]
 * Second subarray is array[m + 1 .. r]
 */
void Merge(int array[], int l, int m, int r){

    int i, j, k = 0;
    int n1 = m - l + 1; // 0 - 0 + 1 -- First iteration: 1 at index 0
    int n2 = r - m;     // 1 - 0 = 1 -- First iteration: 1 at index 1

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for(i = 0; i < n1; i++){
        L[i] = array[l + i];
    }
    for(j = 0; j < n2; j++){
        R[j] = array[m + 1 + j];
    }

    // Merge the temp arrays back into array[l .. r]
    i = 0;
    j = 0;
    k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
    while(i < n1){
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while(j < n2){
        array[k] = R[j];
        j++;
        k++;
    }
    printf("\nL: %d, R: %d\n", l, r);
    PrintArray(array, 10);
}
