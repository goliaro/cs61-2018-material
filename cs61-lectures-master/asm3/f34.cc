//! -O3

static unsigned g(unsigned i) {
    return i;
}

unsigned f(unsigned n) {
    unsigned sum = 0;
    for (unsigned i = 0; i != n; ++i) {
        sum += g(i);
    }
    return sum;
}
