#include <stdio.h>
#include <stdlib.h>


int main(int argc, char * argv[]){

    int array[] = {11, 5, 13, 4 , 5};

    int sum = array[0] + array[1] + array[2];
    float answer = (float)sum / 3;

    printf("%0.2f\n", answer);

    return 0;
}
