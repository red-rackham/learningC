#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int buffer[];
int head;
int tail;
int size;

int pop(int[]);
int push(int[], char[]);
/*
 *
 * Struct
 * -es hat platz
 *  -es hat was 
 *  pthread__mutex_lock
 *  queue.lock
 */

int main(int argc, char **argv)
{
    //DEBUG
  
    head = 0;
    tail = 0;
    size = atoi(argv[1]);
    int buffer[size];
    printf("Buffer mit Grösse %d erstellt.\n", size);
    char input[100] = {"\0"};
    
    for(int i = 0; i < size; i++) {
        buffer[i] = 0;
    }
    
    
    
    char *test1 = "";
    scanf("%s", test1);
    printf("%s,\n", test1);
    
 //   while(getline(stdin) != EOF);
    while(scanf("%s", input) == 1) {
        if(strcmp(input, "get") == 0 || strcmp(input, "g") == 0) {
            pop(buffer);
        } else {
            push(buffer, input);
        }
    }
}


int pop(int buffer[]) 
{
    if( head != tail) {
        printf("%d\n", buffer[head++]);
        if(head < size - 1) {
            head++;
        } else {
            head = 0;
        }
    } else {
        printf("nix im Buffer!\n");
    }
    return 1;
}

int push(int buffer[],char input[]) 
{
    if((head - tail == 1) || (tail == (size -1) && head == 0)) { 
        printf("Buffer ist schon voll!\n");
    } else {
        if(input[0] == 45 || (47 < input[0]) && (input < 58) ) {
    	    buffer[tail] = atoi(input);
            if(tail <  size - 1) {
                tail++;
            } else {
                tail = 0;
            }    
        }
    }
    return 1;
}

int parse(char input[]) {
    int value = NULL;
    if(input[0] == 45 || (47 < input[0]) && (input < 58) ) {
        value = atoi(input);
    }
    return value;
}


