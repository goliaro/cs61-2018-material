#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void check_pointer_wrap(char* x) {
    assert(x + 1 > x);
}

int main(int argc, char** argv) {
    assert(argc >= 2);

    check_pointer_wrap(argv[1]);
    printf("argv = %p, argv + 1 = %p\n", argv[1], argv[1] + 1);

    unsigned long u = strtoul(argv[1], nullptr, 0);
    char* x = reinterpret_cast<char*>(u);
    check_pointer_wrap(x);
    printf("x = %p, x + 1 = %p\n", x, x + 1);
}
