#include "membench.hh"
#include <stdlib.h>

memnode_arena* memnode_arena_new() {
    return nullptr;
}

void memnode_arena_free(memnode_arena*) {
}

memnode* memnode_alloc(memnode_arena*) {
    return (memnode*) malloc(sizeof(memnode));
}

void memnode_free(memnode_arena*, memnode* m) {
    free(m);
}
