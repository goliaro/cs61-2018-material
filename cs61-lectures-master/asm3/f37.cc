//! -O2

int f(int x) {
    if (x > 0) {
        return x * f(x - 1);
    } else {
        return 1;
    }
}
