#include <cstdio>
#include <thread>
#include <atomic>

std::atomic_flag spinlock = ATOMIC_FLAG_INIT;

void threadfunc(unsigned* x) {
    for (int i = 0; i != 10000000; ++i) {
        while (spinlock.test_and_set()) {
        }

        *x += 1;

        spinlock.clear();
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
