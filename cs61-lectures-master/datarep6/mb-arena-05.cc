#include "membench.hh"
#include <vector>
#include <string>

struct memnode {
    const char* file;
    unsigned line;
};


struct memnode_arena {
    union freeable_memnode {
        memnode n;
        freeable_memnode* next_free;
    };

    std::vector<freeable_memnode*> allocated_groups;
    freeable_memnode* free_list;

    memnode_arena()
        : free_list(nullptr) {
    }

    ~memnode_arena() {
        while (!allocated_groups.empty()) {
            delete[] allocated_groups.back();
            allocated_groups.pop_back();
        }
    }

private:
    void refresh_free_list() {
        freeable_memnode* g = new freeable_memnode[2048];
        for (unsigned i = 0; i != 2048; ++i) {
            g[i].next_free = free_list;
            free_list = &g[i];
        }
        allocated_groups.push_back(g);
    }

public:
    memnode* allocate() {
        if (!free_list) {
            refresh_free_list();
        }
        freeable_memnode* fn = free_list;
        free_list = fn->next_free;
        return &fn->n;
    }

    void deallocate(memnode* n) {
        freeable_memnode* fn = (freeable_memnode*) n;
        fn->next_free = free_list;
        free_list = fn;
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
