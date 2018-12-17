#include "iobench.hh"

int main() {
    int fd = STDIN_FILENO;
    if (isatty(fd)) {
        fd = open(DATAFILE, O_RDONLY);
    }
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    size_t size = filesize(fd);
    size_t block_size = 512;
    char* buf = (char*) malloc(block_size);
    double start = tstamp();

    off_t pos = size - (size % block_size);
    size_t n = 0;
    while (pos > 0) {
        pos -= block_size;
        if (lseek(fd, pos, SEEK_SET) == (off_t) -1) {
            perror("lseek");
            exit(1);
        }
        ssize_t r = read(fd, buf, block_size);
        if (r == -1) {
            perror("read");
            exit(1);
        } else if (r != (ssize_t) block_size) {
            break;
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
