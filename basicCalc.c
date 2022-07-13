#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){

    if((argc != 4) || (*argv[2] != '/' && *argv[2] != 'x' && *argv[2] != '-' && *argv[2] != '+')){
        printf("\nIncorrect Usage: ./calc [num] / [num]\n");
        exit(1);
    }

    int result = 0;

    for(int i = 1; i < argc; i++){
        if(*argv[i] == '/'){
            printf("/ ");
            result = atoi(argv[1]) / atoi(argv[3]);
        } else if (*argv[i] == 'x') {
            printf("* ");
            result = atoi(argv[1]) * atoi(argv[3]);
        } else if (*argv[i] == '-') {
            printf("- ");
            result = atoi(argv[1]) - atoi(argv[3]);
        } else if (*argv[i] == '-') {
            printf("+ ");
            result = atoi(argv[1]) + atoi(argv[3]);
        } else {
            printf("%d ", atoi(argv[i]));
        }
    }

    printf("= %d\n", result);

    return 0;
}
