#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "hexdump.hh"

int global_i = 65000000;
const int const_global_i = 66;

void f() {
    int local_i = 1;
    int local_n = -1;
    long long local_ll = 83421972397451239;
    int* allocated_i = new int(68);

    printf("%d\n", global_i);
    hexdump(&global_i, sizeof(int));
    hexdump(&const_global_i, sizeof(int));
    hexdump(&local_i, sizeof(local_i));
    hexdump(&local_n, sizeof(local_n));
    hexdump(&local_ll, sizeof(local_ll));
    hexdump(allocated_i, sizeof(int));
    hexdump(&allocated_i, sizeof(allocated_i));
}

int main() {
    f();
}
