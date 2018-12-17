#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    assert(argc >= 3);
    unsigned n1 = strtol(argv[1], nullptr, 0);
    unsigned n2 = strtol(argv[2], nullptr, 0);

    for (unsigned i = n1; i <= n2; ++i) {
        printf("%u\n", i);
    }
}
