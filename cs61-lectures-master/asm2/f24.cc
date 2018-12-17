//! -O1 -fno-if-conversion -fno-if-conversion2

int f(int a, int b, int c) {
    if (b == c) {
        return a;
    } else {
        return b;
    }
}
