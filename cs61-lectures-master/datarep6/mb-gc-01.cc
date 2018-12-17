#include "membench.hh"
#include <vector>
#include <string>

struct allocation {
    uintptr_t addr;
    size_t sz;
};

static std::vector<allocation, system_allocator<allocation>> blocks;
void gc();


void* operator new(size_t sz) {
    blocks.reserve(10000);

    void* p = malloc(sz);
    if (!p) {
        gc();
        p = malloc(sz);
    }
    if (p) {
        blocks.push_back(allocation{(uintptr_t) p, sz});
    }
    return p;
}

void operator delete(void*) noexcept {
}

void gc() {
    abort();
}

COMPLETE_ALLOCATION_OPERATORS;


struct memnode {
    const char* file;
    unsigned line;
};

unsigned long memnode_benchmark(unsigned noperations, unsigned step) {
    assert(step % 2 == 1);  // `step` must be odd
    long counter = 0;

    // Allocate 4096 memnodes.
    const unsigned nnodes = 4096;
    memnode* m[nnodes];
    for (unsigned i = 0; i != nnodes; ++i) {
        m[i] = new memnode;
        m[i]->file = "datarep/mb-filename.cc";
        m[i]->line = counter;
        ++counter;
    }

    // Replace one `noperations` times.
    for (unsigned i = 0; i != noperations; ++i) {
        unsigned pos = (i * step) % nnodes;
        delete m[pos];

        m[pos] = new memnode;
        m[pos]->file = "datarep/mb-filename.cc";
        m[pos]->line = counter;
        ++counter;
    }

    // Compute a statistic and free them.
    unsigned long result = 0;
    for (unsigned i = 0; i != nnodes; ++i) {
        result += m[i]->line;
        delete m[i];
    }

    return result;
}
