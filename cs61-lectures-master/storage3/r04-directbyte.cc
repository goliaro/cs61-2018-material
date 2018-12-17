#include "iobench.hh"

int main() {
#ifndef O_DIRECT
    fprintf(stderr, "ERROR: O_DIRECT not supported here\n");
# define O_DIRECT 0
#endif

    int fd = STDIN_FILENO;
    if (isatty(fd)) {
        fd = open(DATAFILE, O_RDONLY | O_DIRECT);
    }
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    size_t size = filesize(fd);
    char* buf = (char*) malloc(1);
    double start = tstamp();
    // NB: direct I/O works ONLY on units of 512 bytes,
    // so we expect this to fail!

    size_t n = 0;
    while (n < size) {
        ssize_t r = read(fd, buf, 1);
        if (r == -1) {
            perror("read");
            exit(1);
        } else if (r != 1) {
            break;
        }
        n += r;
        printf("saw %c\n", buf[0]);
        sleep(1);
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }
    }

    close(fd);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
