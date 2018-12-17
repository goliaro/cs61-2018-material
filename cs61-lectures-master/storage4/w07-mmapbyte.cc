#include "iobench.hh"
#include <sys/mman.h>

int main() {
    int fd = STDOUT_FILENO;
    if (isatty(fd)) {
        fd = open(DATAFILE, O_RDWR | O_CREAT | O_TRUNC, 0660);
    }
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    size_t size = 51200000;
    const char* buf = "6";
    double start = tstamp();

    // extend file size first
    int r = ftruncate(fd, size);
    if (r < 0) {
        perror("ftruncate");
        exit(1);
    }

    char* file_data = (char*) mmap(nullptr, size, PROT_WRITE, MAP_SHARED, fd, 0);
    if (file_data == (char*) MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    size_t n = 0;
    while (n < size) {
        memcpy(&file_data[n], buf, 1);
        n += 1;
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }
    }

    munmap(file_data, size);
    close(fd);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
