#include "shape.h"
#include <stdlib.h>
#include <stdbool.h>
struct Node *node_init()
{
    struct Node *n = malloc(sizeof(struct Node));
    if (n == NULL)
        return NULL;
    INIT_LIST_HEAD(n);
    return n;
}

// Add a new element at the tail of element list
bool node_add(struct Node *n)
{
    if (n == NULL)
        return false;
    
}