#include "types.h"

typedef void (*Destructor)(void *, s32);

typedef struct DestructorEntry {
    struct DestructorEntry *next;
    Destructor destroy;
    void *object;
} DestructorEntry;

DestructorEntry *__global_destructor_chain __attribute__((aligned(32)));

void __destroy_global_chain(void) {
    DestructorEntry *node;

    while (__global_destructor_chain != 0) {
        node = __global_destructor_chain;
        __global_destructor_chain = node->next;
        node->destroy(node->object, -1);
    }
}


/* The runtime's .dtors entry: __fini (via _dtors) calls the chain at exit. */
__declspec(section ".dtors") static void *const __destroy_global_chain_reference = __destroy_global_chain;
