#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>
#include "hexdump.hh"

struct x_t {
    int i1;
    char c1;
    int i2;
    int i3;
    char c2;
    char c3;
};

void f() {
    {
        x_t* x = new x_t;
        x->i1 = 1;

        hexdump(&x, sizeof(x));
        hexdump(&x->i1, sizeof(x->i1));
        hexdump(&x->i2, sizeof(x->i2));
        hexdump(&x->i3, sizeof(x->i3));
        hexdump(&x->c1, sizeof(x->c1));
        hexdump(&x->c2, sizeof(x->c2));
        hexdump(&x->c3, sizeof(x->c3));

        delete x;
    }
}

int main() {
    f();
}
