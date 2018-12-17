#include "membench.hh"
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

static unsigned noperations;

void benchmark() {
    // allocate a new memory arena for this thread.
    // An "arena" is an object that encapsulates a set of memory allocations.
    // Arenas can capture allocation statistics and improve speed.
    memnode_arena* arena = memnode_arena_new();

    // Allocate 4096 memnodes.
    memnode* m[4096];
    for (int i = 0; i != 4096; ++i) {
        m[i] = memnode_alloc(arena);
    }

    // `noperations` times, free a memnode and then allocate another one.
    for (unsigned i = 0; i != noperations; ++i) {
        unsigned pos = i % 4096;
        memnode_free(arena, m[pos]);
        m[pos] = memnode_alloc(arena);
    }

    // Free the remaining memnodes and the arena.
    for (int i = 0; i != 4096; ++i) {
        memnode_free(arena, m[i]);
    }
    memnode_arena_free(arena);
}

void* benchmark_thread(void* user_data) {
    (void) user_data;
    benchmark();
    return nullptr;
}

int main(int argc, char** argv) {
    noperations = 10000000;
    if (argc >= 2) {
        noperations = strtoul(argv[1], nullptr, 0);
    }
    int nthreads = 1;
    if (argc >= 3) {
        nthreads = strtol(argv[2], nullptr, 0);
    }

    if (nthreads <= 1) {
        // Run the benchmark.
        benchmark();
    } else {
        // Run `nthreads` threads, each running the benchmark.
        pthread_t threads[100];
        assert(nthreads <= 100);
        for (int i = 0; i != nthreads; ++i) {
            pthread_create(&threads[i], nullptr, benchmark_thread, nullptr);
        }
        for (int i = 0; i != nthreads; ++i) {
            pthread_join(threads[i], nullptr);
        }
    }
}
