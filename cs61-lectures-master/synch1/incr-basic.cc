#include <cstdio>
#include <thread>

void threadfunc(unsigned* x) {
    // This is a correct way to increment a shared variable!
    // ... OR IS IT?!?!?!?!?!?!??!?!
    for (int i = 0; i != 10000000; ++i) {
        *x += 1;
    }
}

int main() {
    std::thread th[4];
    unsigned n = 0;
    for (int i = 0; i != 4; ++i) {
        th[i] = std::thread(threadfunc, &n);
    }
    for (int i = 0; i != 4; ++i) {
        th[i].join();
    }
    printf("%u\n", n);
}
