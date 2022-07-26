/* There is a path problem that describes a 3x3 grid in which an object can only move either down or right,
 * while starting on the top left and must travel to the bottom right. Write an algorithm that can be used
 * to print every path that the object can take
 *
 * The key here is that no matter what, the object must go exactly 3 down and 3 right to reach the 
 * destination, therefore every path will contain 3 'D' and 3 'R'
 *
 * As I already predicted by hand, 20 permutations exist for this path
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node
{
    char data[7];
    Node* next;
};

Node * List = NULL;

void swap(char* x, char* y);
void permute(char* s, int l, int r);

void Insert(char* x);
int Contains(char* x);
void Print();


int main(int argc, char * argv[]){

    char str[] = "DDDRRR";
    int n = strlen(str);
    permute(str, 0, n - 1);
    Print();

    return 0;
}

void swap(char * x, char * y){

    char temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string.
 * This function takes three parameters:
 * 1. String (s)
 * 2. Starting index of the string (l)
 * 3. Ending index of the string   (r)
 */
void permute(char * s, int l, int r){
    if(l == r){
        if(!Contains(s)) Insert(s);
    } else {
        for(int i = l; i <= r; i++){
            swap((s + l), (s + i));
            permute(s, l + 1, r);
            swap((s + l), (s + i)); // Swap back
        }
    }
}

void Insert(char * x){

    Node * temp = (Node *)malloc(sizeof(Node));

    //temp->data = x;
    memset(temp->data, '\0', sizeof(temp->data));
    strcpy(temp->data, x);
    temp->next = List;
    List = temp;
}

void Print(){

    Node * temp = List;

    while(temp != NULL){
        printf(" %s\n", temp->data);
        temp = temp->next;
    }
}

int Contains(char* x){

    Node * temp = List;

    while(temp != NULL){
        if(strcmp(temp->data, x) == 0){
            // Found
            return 1;
        }
        // Not Found
        temp = temp->next;
    }
    return 0;
}
