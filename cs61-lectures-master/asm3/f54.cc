//! -O1
struct four_bytes {
    char k;
    char l;
    char m;
    char n;
};

char* f(struct four_bytes* a, int x) {
    return &a[x].n;
}
