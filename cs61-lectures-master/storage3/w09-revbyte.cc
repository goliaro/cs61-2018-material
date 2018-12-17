#include "iobench.hh"

int main() {
    int fd = STDOUT_FILENO;
    if (isatty(fd)) {
        fd = open(DATAFILE, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    }
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    size_t size = 5120000;
    const char* buf = "6";
    double start = tstamp();

    size_t pos = size;
    size_t n = 0;
    while (n > 0) {
        pos -= 1;
        if (lseek(fd, pos, SEEK_SET) == (off_t) -1) {
            perror("lseek");
            exit(1);
        }
        ssize_t r = write(fd, buf, 1);
        if (r != 1) {
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
