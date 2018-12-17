#include "iobench.hh"
#include <sys/mman.h>

int main() {
    int fd = STDIN_FILENO;
    if (isatty(fd)) {
        fd = open(DATAFILE, O_RDONLY);
    }
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    // track number of characters seen mod 16
    size_t histogram[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    size_t size = filesize(fd);
    char* buf = (char*) malloc(1);
    double start = tstamp();

    char* file_data = (char*) mmap(nullptr, size, PROT_READ, MAP_SHARED, fd, 0);
    if (file_data == (char*) MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    size_t n = 0;
    while (n < size) {
        memcpy(buf, &file_data[n], 1);
        n += 1;
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }
        histogram[(unsigned char) buf[0] % 16] += 1;
    }

    munmap(file_data, size);
    close(fd);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");

    // print histogram
    for (int i = 0; i != 16; ++i) {
        if (histogram[i] != 0) {
            printf("%2d: %8zu\n", i, histogram[i]);
        }
    }
}
