// Insertion Sort O(n^2)

#include <stdio.h>

void printArray(int array[], int size);

int main(int argc, char * argv[]){

    int array[] = {5, 2, 6, 98, 40, 23, 88, 3, 100, 60};
    int size = sizeof(array) / sizeof(array[0]);

    // Iterate up the array starting from the second element
    for(int i = 1; i < size; i++){
        int key = array[i];
        int j = i;
        while(j > -1 && key < array[j - 1]){
            array[j] = array[j - 1];
            j--;

            // Do not compare to values out of array bounds or go negative
            if(j == 0){
                break;
            }
        }
        array[j] = key;
        //printf(" %d", key);
    }

    printArray(array, size);
    return 0;
}

void printArray(int array[], int size){
    printf("\nArray: ");
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}
