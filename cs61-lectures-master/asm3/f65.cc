//! -O1

#include <stdio.h>

void f(int n, const char* name) {
    printf("Hello.\n");
    printf("This is Dr. Evil.\n");
    printf("I am calling from inside the house.\n");
    int r = printf("I can count: %d %d %d %d %d %d %d %d\n",
                   n, n+1, n+2, n+3, n+4, n+5, n+6, n+7);
    printf("I hate you, %s. Printed %d chars.\n", name, r);
}

int main(int argc, char** argv) {
    f(argc, argv[0]);
}
