//! -O1
struct four_bytes {
    unsigned char k;
    unsigned char l;
    unsigned char m;
    unsigned char n;
};

int f(struct four_bytes* a, int x) {
    return a[x].k;
}
