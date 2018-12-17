#include <cstdio>
#include <thread>
#include <mutex>

std::mutex mutex;

void threadfunc(unsigned* x) {
    for (int i = 0; i != 10000000; ++i) {
        mutex.lock();
        *x += 1;
        mutex.unlock();
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
