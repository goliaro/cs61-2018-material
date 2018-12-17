//! -O2

extern int g(int x);

int f(int x) {
    return 1 + g(x);
}
