#include <string.h>
#include <algorithm>

int fun(const char* s) {
    return strtol(s, nullptr, 0) + 1;
}
