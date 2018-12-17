#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "hexdump.hh"

int array[10] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

int access1(int i) {
    if (i < 0 || i >= 10) {
        abort();
    }
    int x = array[i];
    // Modern compilers will remove this assert as redundant
    // when optimizations are on.
    assert(i >= 0 && i < 10);
    return x;
}

int access2(int i) {
    int x = array[i];
    // Modern compilers COULD remove THIS assert, too! It is
    // redundant because of undefined behavior reasoning.
    // Since valid C programs won't access out-of-bounds array
    // elements, the compiler knows that `i >= 0 && i < 10`.
    // Your compiler might not remove this assert, but a future
    // compiler (a cleverer compiler) would be allowed to.
    // The undefined behavior sanitizer will catch the error if
    // `access2` is passed an out-of-range value.
    assert(i >= 0 && i < 10);
    return x;
}

void realloc_error(void) {
    int* p = (int*) malloc(sizeof(int));
    int* q = (int*) realloc(p, sizeof(int));
    *p = 1;
    *q = 2;
    if (p == q) {
        printf("%d %d\n", *p, *q);
    }
    // Optimized clang will print `1 2`, which is crazy!
}

int signed_increment(int x) {
    // Modern compilers will remove this assert because of
    // undefined behavior reasoning: signed integer overflow
    // is undefined behavior, so the compiler may assume
    // that `x + 1` never overflows when `x` is signed.
    assert(x + 1 > x);
    return x + 1;
}

int safe_signed_increment(int x) {
    // Unsigned integer overflow is *defined* behavior, so
    // this assertion will be executed.
    assert((int) ((unsigned) x + 1) > x);
    return x + 1;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: ./ubexplore TEST N\n");
        exit(1);
    }

    int test = strtol(argv[1], NULL, 0);
    int x = strtol(argv[2], NULL, 0);

    // Run optimized & unoptimized versions, and try with
    // & without SANITIZE=1.
    if (test == 0) {
        printf("access1(%d) = %d\n", x, access1(x));
    } else if (test == 1) {
        printf("access2(%d) = %d\n", x, access2(x));
    } else if (test == 2) {
        realloc_error();
    } else if (test == 3) {
        printf("signed_increment(%d) = %d\n", x, signed_increment(x));
    } else {
        printf("safe_signed_increment(%d) = %d\n", x, safe_signed_increment(x));
    }
}
