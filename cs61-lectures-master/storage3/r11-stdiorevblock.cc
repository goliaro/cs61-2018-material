#include "iobench.hh"

int main() {
    FILE* f = stdin;
    if (isatty(fileno(f))) {
        f = fopen(DATAFILE, "r");
    }
    if (!f) {
        perror("fopen");
        exit(1);
    }

    size_t size = filesize(fileno(f));
    size_t block_size = 512;
    char* buf = (char*) malloc(block_size);
    double start = tstamp();

    off_t pos = size - (size % block_size);
    size_t n = 0;
    while (pos > 0) {
        pos -= block_size;
        if (fseek(f, pos, SEEK_SET) == -1) {
            perror("fseek");
            exit(1);
        }
        size_t r = fread(buf, 1, block_size, f);
        if (r == 0 && ferror(f)) {
            perror("read");
            exit(1);
        } else if (r != block_size) {
            break;
        }
        n += r;
        if (n % PRINT_FREQUENCY == 0) {
            report(n, tstamp() - start);
        }
    }

    fclose(f);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
