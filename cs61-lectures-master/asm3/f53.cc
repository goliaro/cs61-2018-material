//! -O1
struct four_bytes {
    char k;
    char l;
    char m;
    char n;
};

int f(struct four_bytes* a, int x) {
    return a[x].n;
}
