//! -O0 -fomit-frame-pointer
extern int g(int a);

int f(int a) {
    return g(a + 1) - 1;
}
