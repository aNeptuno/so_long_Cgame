
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size) //, const char *file, int line, const char *function)
{
    void *ptr = malloc(size);
    if (!ptr)
    {
        //fprintf(stderr, "Error allocating memory (%s) at %s:%d in function %s\n", strerror(errno), file, line, function);
        return NULL;
    }
    return ptr;
}
