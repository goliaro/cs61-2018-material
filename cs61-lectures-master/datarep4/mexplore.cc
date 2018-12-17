#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>
#include "hexdump.hh"

void f() {
    char c[100];
    for (int i = 0; i != 100; ++i) {
        c[i] = '0' + i;
    }

    hexdump(c, sizeof(c));
    hexdump(&c[0], 10 * sizeof(c[0]));
    hexdump(&c[10], 10 * sizeof(c[0]));
}

int main() {
    f();
}
