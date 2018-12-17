//! -O1
struct two_words {
    unsigned k;
    unsigned l;
};

int f(struct two_words* a, int x) {
    return a[x].k;
}
