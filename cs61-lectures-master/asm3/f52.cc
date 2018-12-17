//! -O1
struct four_words {
    unsigned k;
    unsigned l;
    unsigned m;
    unsigned n;
};

int f(struct four_words* a, int x) {
    return a[x].k;
}
