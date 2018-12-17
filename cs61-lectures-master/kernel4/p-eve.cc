#include "process.hh"
#include "lib.hh"

void process_main() {
    unsigned i = 0;

    while (1) {
        ++i;
        if (i % 512 == 0) {
            app_printf(0, "Hi, I'm Eve! #%d\n", i / 512);
        }
        sys_yield();
    }
}
