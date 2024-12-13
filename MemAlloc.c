#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

#include "MemAlloc.h"


chunk FreeList[MAX_CHUNKS];
int numOfFreeInList = 0;

chunk AllocatedList[MAX_CHUNKS];
int numOfAllocatedInList = 0;


char* xmalloc(size_t size){
   int pageSize = size;
    if(pageSize < MIN_PAGESIZE){
        pageSize = MIN_PAGESIZE;
    }
    char* newPage = sbrk(pageSize);
    for(int ix = 0; ix < numOfFreeInList; ix++){
        if(FreeList[ix].size >= size){
            fprintf(stderr, "Hi");
            //return this to user
            AllocatedList[numOfAllocatedInList].size = size;
            AllocatedList[numOfAllocatedInList].address = &newPage[FreeList[ix].size - size];

            char *ptr =  AllocatedList[numOfAllocatedInList].address;

            numOfAllocatedInList++;

            FreeList[ix].size -= size;
            
            fprintf(stderr, "Hola");
            if(FreeList[ix].size == 0){
                for(int wx = ix + 1; wx < numOfFreeInList; wx++){
                    FreeList[wx-1] = FreeList[wx];
                }
                numOfFreeInList--;
            }
            return ptr;
        }
    }
    //did not chunk on free list
    

    if(pageSize > size){
        FreeList[numOfFreeInList].size = pageSize - size;
        FreeList[numOfFreeInList].address = &newPage[size];
        numOfFreeInList++;
    }
    

    AllocatedList[numOfAllocatedInList].address = newPage;
    AllocatedList[numOfAllocatedInList].size = size;
    numOfAllocatedInList++;

        
    char *ptr = newPage;

    fprintf(stderr, __FILE__ ": %d malloc(%lu) = %p\n", __LINE__, size, ptr);
    return ptr;
}

void xfree(void *ptr){
    for(int jx = 0; jx < numOfAllocatedInList; jx++){
        if(ptr == AllocatedList[jx].address){
            //we found the match, move from alloc list to free list
            FreeList[numOfFreeInList++] = AllocatedList[jx];
            for(int wx = jx + 1; wx < numOfAllocatedInList; wx++){
                    AllocatedList[wx-1] = AllocatedList[wx];
                }
                numOfAllocatedInList--;
        }
    }
  
}