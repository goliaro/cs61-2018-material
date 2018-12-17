#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <getopt.h>
#include <assert.h>
#include <time.h>

double get_time() {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts.tv_sec + 1e-9 * ts.tv_nsec;
}


struct sqmatrix {
    double* v;
    size_t sz;

    sqmatrix(size_t size)
        : v(new double[size * size]), sz(size) {
    }
    ~sqmatrix() {
        delete[] v;
    }

    sqmatrix(const sqmatrix&) = delete;
    sqmatrix& operator=(const sqmatrix&) = delete;

    size_t size() {
        return sz;
    }

    // obtain the matrix element at row `i` and column `j`
    double& operator()(size_t i, size_t j) {
        return v[i * sz + j];
    }
};



// matrix_multiply(c, a, b)
//    `a`, `b`, and `c` are square matrices with dimension `sz`.
//    Computes the matrix product `a x b` and stores it in `c`.
void matrix_multiply(sqmatrix& c, sqmatrix& a, sqmatrix& b) {
    assert(c.size() == a.size() && c.size() == b.size());

    // clear `c`
    for (size_t i = 0; i < c.size(); ++i) {
        for (size_t j = 0; j < c.size(); ++j) {
            c(i, j) = 0;
        }
    }

    // compute product and update `c`
    for (size_t i = 0; i < c.size(); ++i) {
        for (size_t j = 0; j < c.size(); ++j) {
            for (size_t k = 0; k < c.size(); ++k) {
                c(i, j) += a(i, k) * b(k, j);
            }
        }
    }
}


// xrandom()
//    Return a pseudo-random number in the range [0, XRAND_MAX].
//    We use our own generator to ensure values computed on different
//    OSes will follow the same sequence.
#define XRAND_MAX 0x7FFFFFFF
static uint64_t xrandom_seed;
unsigned xrandom() {
    xrandom_seed = xrandom_seed * 6364136223846793005U + 1U;
    return (xrandom_seed >> 32) & XRAND_MAX;
}

struct sqmatrix_statistics {
    double corner[4];
    double diagonal_sum;
};

// compute_statistics(m, sz)
//    Compute and return some statistics about matrix `m`.
sqmatrix_statistics compute_statistics(sqmatrix& m) {
    sqmatrix_statistics mstat;
    mstat.corner[0] = m(0, 0);
    mstat.corner[1] = m(0, m.size() - 1);
    mstat.corner[2] = m(m.size() - 1, 0);
    mstat.corner[3] = m(m.size() - 1, m.size() - 1);
    mstat.diagonal_sum = 0;
    for (size_t i = 0; i < m.size(); ++i) {
        mstat.diagonal_sum += m(i, i);
    }
    return mstat;
}


int main(int argc, char* argv[]) {
    size_t sz = 1000;
    int has_seed = 0;

    // read options
    int opt;
    while ((opt = getopt(argc, argv, "n:d:")) != -1) {
        switch (opt) {
        case 'n':
            sz = strtoul(optarg, nullptr, 0);
            break;
        case 'd':
            xrandom_seed = strtoul(optarg, nullptr, 0);
            has_seed = 1;
            break;
        default:
            fprintf(stderr, "Usage: ./matrixmultiply [-n SIZE] [-d SEED]\n");
            exit(EXIT_FAILURE);
        }
    }

    assert(sz > 0);
    assert(sz < (size_t) sqrt(SIZE_MAX / sizeof(double)));
    if (!has_seed) {
        union { double d; uint64_t x; } u;
        u.d = get_time();
        xrandom_seed = u.x;
    }
    printf("size %zu, seed %" PRIu64 "\n", sz, xrandom_seed);

    // allocate matrices
    sqmatrix a(sz);
    sqmatrix b(sz);
    sqmatrix c(sz);

    // fill in source matrices
    for (size_t i = 0; i < sz; ++i) {
        for (size_t j = 0; j < sz; ++j) {
            a(i, j) = xrandom() / (double) XRAND_MAX;
        }
    }

    for (size_t i = 0; i < sz; ++i) {
        for (size_t j = 0; j < sz; ++j) {
            b(i, j) = xrandom() / (double) XRAND_MAX;
        }
    }

    // compute `c = a x b`
    double t0 = get_time();
    matrix_multiply(c, a, b);
    double t1 = get_time();
    sqmatrix_statistics mstat = compute_statistics(c);

    // compute times, print times and ratio
    printf("multiply time %.09f\n", t1 - t0);

    // print statistics and differences
    for (int i = 0; i < 4; ++i) {
        printf("corner statistic %d: %g (%a)\n",
               i, mstat.corner[i], mstat.corner[i]);
    }
    printf("diagonal sum statistic: %g (%a)\n",
           mstat.diagonal_sum, mstat.diagonal_sum);
}
