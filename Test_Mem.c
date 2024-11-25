#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(int argc, char* argv[]){
    if(argc == 2){
        char userMessage[] = atoi(argv[1]);
        int length = strlen(userMessage);
    //length will be compared to pool size
    //if poolsize bigger than length, we can malloc
    //else, we need to realloc

    }
}