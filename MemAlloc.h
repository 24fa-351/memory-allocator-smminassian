#ifndef MEMALLOC_H
#define MEMALLOC_H

#include <stddef.h>

#define MAX_CHUNKS 128
#define MIN_PAGESIZE 4096


char* xmalloc(size_t size);
void xfree(void *ptr);
#endif

