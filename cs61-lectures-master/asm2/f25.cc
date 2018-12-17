//! -O1 -fno-if-conversion -fno-if-conversion2

int f(int a, int b) {
    if (a < b) {
        return 0;
    } else {
        return a;
    }
}
