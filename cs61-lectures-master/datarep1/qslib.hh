#ifndef QSLIB_HH
#define QSLIB_HH
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

struct qs_info {
    int* array;
    int size;
    bool execute;
    unsigned checksum;
};
qs_info parse_arguments(int argc, char** argv);


inline unsigned ints_checksum(const int* array, int n) {
    unsigned sum = 0;
    for (int i = 0; i != n; ++i) {
        sum += (unsigned) array[i];
    }
    return sum;
}

inline bool ints_sorted(const int* array, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

void ints_print(const int* array, int n);


inline unsigned ints_checksum(const std::list<int>& list) {
    unsigned sum = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        sum += (unsigned) *it;
    }
    return sum;
}

inline bool ints_sorted(const std::list<int>& list) {
    if (!list.empty()) {
        auto it = list.begin();
        int last = *it;
        for (++it; it != list.end(); ++it) {
            if (last > *it) {
                return false;
            }
            last = *it;
        }
    }
    return true;
}

inline std::list<int> ints_append(const std::list<int>& a,
                                  const std::list<int>& b) {
    std::list<int> x;
    std::copy(a.begin(), a.end(), std::back_inserter(x));
    std::copy(b.begin(), b.end(), std::back_inserter(x));
    return x;
}

void ints_print(const std::list<int>& list);


inline unsigned ints_checksum(const std::vector<int>& list) {
    unsigned sum = 0;
    for (auto it = list.begin(); it != list.end(); ++it) {
        sum += (unsigned) *it;
    }
    return sum;
}

inline bool ints_sorted(const std::vector<int>& list) {
    if (!list.empty()) {
        auto it = list.begin();
        int last = *it;
        for (++it; it != list.end(); ++it) {
            if (last > *it) {
                return false;
            }
            last = *it;
        }
    }
    return true;
}

inline std::vector<int> ints_append(const std::vector<int>& a,
                                    const std::vector<int>& b) {
    std::vector<int> x;
    std::copy(a.begin(), a.end(), std::back_inserter(x));
    std::copy(b.begin(), b.end(), std::back_inserter(x));
    return x;
}

void ints_print(const std::vector<int>& list);

#endif
