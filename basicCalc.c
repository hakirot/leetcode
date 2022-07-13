#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    if(argc != 4 || *argv[2] != '/'){
        printf("\nIncorrect Usage: ./calc [num] / [num]\n");
        exit(1);
    }

    for(int i = 1; i < argc; i++){
        if(*argv[i] == '/'){
            printf("/ ");
        } else {
            printf("%d ", atoi(argv[i]));
        }
    }

    int result = atoi(argv[1]) / atoi(argv[3]);

    printf("= %d\n", result);

    return 0;
}
