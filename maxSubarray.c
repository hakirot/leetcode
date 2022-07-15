#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* FindMaxCrossing(int Array[], int low, int mid, int high);
void PrintSolution(int* solution);

int main(int argc, char * argv[]){

    int Array[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    int size = sizeof(Array) / sizeof(Array[0]);

    int mid = (size / 2) - 1;
    printf("mid: %d size: %d\n", mid, size);
    int* solution = FindMaxCrossing(Array, 0, mid, size - 1);

    PrintSolution(solution);

    return 0;
}

int* FindMaxCrossing(int Array[], int low, int mid, int high){

    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int maxLeft = 0;
    int maxRight = 0;

    int sum = 0;
    for(int i = mid; i >= low; i--){
        sum = sum + Array[i];
        if(sum > leftSum){
            leftSum = sum;
            maxLeft = i;
        }
    }

    sum = 0;
    for(int j = mid + 1; j < high; j++){
        sum = sum + Array[j];
        if(sum > rightSum){
            rightSum = sum;
            maxRight = j;
        }
    }

    int * solution = malloc(sizeof(int) * 3);
    solution[0] = maxLeft;
    solution[1] = maxRight;
    solution[2] = leftSum + rightSum;

    return solution;
}

void PrintSolution(int* solution){

    printf("\nSolution: ");

    for(int i = 0; i < 3; i++){
        printf("%d ", solution[i]);
    }

    printf("\n");
}
