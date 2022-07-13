// Insertion Sort O(n^2)

#include <stdio.h>

void printArray(int array[], int length);

int main(int argc, char * argv[]){

    int length = 10;
    int array[] = {5, 2, 6, 98, 40, 23, 88, 3, 100, 60};

    // Iterate up the array starting from the second element
    for(int i = 1; i < length; i++){
        int key = array[i];
        int j = i;
        while(j > -1 && key < array[j - 1]){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = key;
        printf(" %d", key);
    }

    printArray(array, length);
    return 0;
}

void printArray(int array[], int length){
    printf("\nArray: ");
    for(int i = 0; i < length; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}
