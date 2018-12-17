#include "process.hh"
#include "lib.hh"

void process_main() {
    char buf[128];
    sys_getsysname(buf);
    app_printf(1, "Welcome to %s\n", buf);

    unsigned i = 0;
    while (1) {
        ++i;
        if (i % 512 == 0) {
            app_printf(1, "Hi, I'm Alice! #%d\n", i / 512);
        }
        sys_yield();
    }
}
