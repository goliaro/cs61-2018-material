#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv) {
    assert(argc >= 3);
    int n1 = strtol(argv[1], nullptr, 0);
    int n2 = strtol(argv[2], nullptr, 0);

    long sum = 0;
    for (int i = n1; i <= n2; ++i) {
        sum += i;
        printf("%d\n", i);
    }
    printf("%ld\n", sum);
}
