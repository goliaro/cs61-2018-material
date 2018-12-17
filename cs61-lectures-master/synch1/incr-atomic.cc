#include <cstdio>
#include <thread>
#include <atomic>

void threadfunc(std::atomic<unsigned>* x) {
    for (int i = 0; i != 10000000; ++i) {
        x->fetch_add(1);
        // `*x += 1` and `(*x)++` also work!
    }
}

int main() {
    std::thread th[4];
    std::atomic<unsigned> n = 0;
    for (int i = 0; i != 4; ++i) {
        th[i] = std::thread(threadfunc, &n);
    }
    for (int i = 0; i != 4; ++i) {
        th[i].join();
    }
    printf("%u\n", n.load());
}
