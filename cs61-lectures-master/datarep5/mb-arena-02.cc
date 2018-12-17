#include "membench.hh"
#include <stdlib.h>

#define MEMNODE_GROUPSIZE 4095
typedef struct memnode_group {
    struct memnode_group* next;
    memnode nodes[MEMNODE_GROUPSIZE];
} memnode_group;

struct memnode_arena {
    memnode_group* groups;
    memnode* free_list;
};
// Idea: All free memnodes in the arena are linked together by
// their `contents`, which is a void*.

memnode_arena* memnode_arena_new() {
    memnode_arena* a = (memnode_arena*) malloc(sizeof(memnode_arena));
    a->groups = nullptr;
    a->free_list = nullptr;
    return a;
}

void memnode_arena_free(memnode_arena* arena) {
    free(arena);
}

memnode* memnode_alloc(memnode_arena* arena) {
    if (!arena->free_list) {
        // No free nodes, must allocate another group!
        // Use `malloc` to allocate the group. Then add all of the
        // group's memnodes to the free_list.
        memnode_group* mg = (memnode_group*) malloc(sizeof(memnode_group));
        // This links the nodes in reverse order by address.
        // How would you link them in *forward* order by address?
        for (int i = 0; i != MEMNODE_GROUPSIZE; ++i) {
            mg->nodes[i].contents = arena->free_list;
            arena->free_list = &mg->nodes[i];
        }
    }

    // Pop an element off the free list
    memnode* m = arena->free_list;
    arena->free_list = (memnode*) m->contents;
    return m;
}

void memnode_free(memnode_arena* arena, memnode* m) {
    // Push `m` onto the free list
    m->contents = arena->free_list;
    arena->free_list = m;
}
