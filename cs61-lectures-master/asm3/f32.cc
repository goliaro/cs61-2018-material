//! -O2

extern int g(int x);

int f(int x) {
    return g(x + 1);
}
