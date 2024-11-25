#include<stdlib.h>

#ifndef
#define MALLOC_H

//char* xmalloc(size_t size);
//void xfree(void *ptr);

typedef struct chunk {
    int size;
    bool isFree;
}chunk


const POOl_SIZE = 100;

chunk* chunks[POOL_SIZE];


chunk* malloc(int size);
chunk* findBestFit(int size, chunk* chunks);
chunk* heap_insert(int size, chunk* chunks);
void chunk* initialize();
chunk* realloc(int size, chunk* chunks);

#endif

