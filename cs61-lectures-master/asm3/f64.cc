//! -O0
extern int g(int a);

int f(int a) {
    return g(a + 1);
}
