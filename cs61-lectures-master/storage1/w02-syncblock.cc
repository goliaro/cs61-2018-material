#include "iobench.hh"

int main() {
    int fd = STDOUT_FILENO;
    if (isatty(fd)) {
        fd = open(DATAFILE, O_WRONLY | O_CREAT | O_TRUNC | O_SYNC, 0666);
    }
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    size_t size = 5120000;
    size_t block_size = 512;
    char* buf = (char*) malloc(block_size);
    memset(buf, '6', block_size);
    double start = tstamp();

    size_t n = 0;
    while (n < size) {
        ssize_t r = write(fd, buf, block_size);
        if ((size_t) r != block_size) {
            perror("write");
            exit(1);
        }
        n += r;
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }
    }

    close(fd);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
