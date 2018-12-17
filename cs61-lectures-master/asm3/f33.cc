//! -O1

extern unsigned g(unsigned i);

unsigned f(unsigned n) {
    unsigned sum = 0;
    for (unsigned i = 0; i != n; ++i) {
        sum += g(i);
    }
    return sum;
}
