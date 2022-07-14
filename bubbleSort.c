#include <stdio.h>
#include <stdlib.h>


void BubbleSort(int array[], int size);
void PrintArray(int array[], int size);

int main(int argc, char * argv[]){

    int array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(array) / sizeof(array[0]);

    BubbleSort(array, size);
    PrintArray(array, size);

    return 0;
}

void BubbleSort(int array[], int size){
    for(int i = 0; i < size; i++){
        for(int j = size - 1; j > i; j--){
            if(array[j] < array[j - 1]){
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

void PrintArray(int array[], int size){
    printf("Array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

