#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char * Trim(char * string);

int main(int argc, char * argv[]){

    if(argc != 2){
        printf("Incorrect Usage: ./binary [int]");
        exit(1);
    }

    int decimal = atoi(argv[1]);

    char string[16] = "0000000000000000";

    int i = 0;
    while(decimal > 0){

        int j = 15 - i;
        int test = 1;

        while(j > 0){
            test = test * 2;
            j--;
        }

        //printf("%d\n", test);

        if(decimal / test > 0){
            //printf("decimal mod test = %d\n", decimal % test);
            string[i] = '1';
            decimal = decimal - test;
        } else {
            string[i] = '0';
        }
        i++;
    }
    char * trimmed = Trim(string);

    //printf(string);
    printf(trimmed);
    printf("\n");

    return 0;
}

char * Trim(char * string){
    int flag = 0;
    int i = 0;
    while(flag == 0){
        if(string[i] == '1'){
            flag = 1;
            break;
        }
        i++;
    }
    int j = 0;
    while(i < 16){
        string[j] = string[i];
        j++;
        i++;
    }
    string[j] = '\0';

    return string;
}
