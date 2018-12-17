#include "membench.hh"
#include <vector>
#include <string>

struct memnode {
    const char* file;
    unsigned line;
};


struct memnode_arena {
    std::vector<memnode*> allocated;
    std::vector<memnode*> free_list;

    memnode* allocate() {
        memnode* n;
        if (free_list.empty()) {
            n = new memnode;
            allocated.push_back(n);
        } else {
            n = free_list.back();
            free_list.pop_back();
        }
        return n;
    }

    void deallocate(memnode* n) {
        free_list.push_back(n);
    }
};


unsigned long memnode_benchmark(unsigned noperations, unsigned step) {
    assert(step % 2 == 1);  // `step` must be odd
    long counter = 0;
    memnode_arena arena;

    // Allocate 4096 memnodes.
    const unsigned nnodes = 4096;
    memnode* m[nnodes];
    for (unsigned i = 0; i != nnodes; ++i) {
        m[i] = arena.allocate();
        m[i]->file = "datarep/mb-filename.cc";
        m[i]->line = counter;
        ++counter;
    }

    // Replace one `noperations` times.
    for (unsigned i = 0; i != noperations; ++i) {
        unsigned pos = (i * step) % nnodes;
        arena.deallocate(m[pos]);

        m[pos] = arena.allocate();
        m[pos]->file = "datarep/mb-filename.cc";
        m[pos]->line = counter;
        ++counter;
    }

    // Compute a statistic and free them.
    unsigned long result = 0;
    for (unsigned i = 0; i != nnodes; ++i) {
        result += m[i]->line;
    }

    return result;
}
