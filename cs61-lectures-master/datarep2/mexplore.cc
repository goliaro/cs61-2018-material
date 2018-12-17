#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "hexdump.hh"

char global_ch = 65;
const char const_global_ch = 66;

void f() {
    char local_ch = 67;
    char* allocated_ch = new char(68);
    // C-style allocation:
    // char* allocated_ch = (char*) malloc(sizeof(char));
    // *allocated_ch = 68;

    hexdump(&global_ch, 1);
    hexdump(&const_global_ch, 1);
    hexdump(&local_ch, 1);
    hexdump(allocated_ch, 1);
}

int main() {
    f();
}
