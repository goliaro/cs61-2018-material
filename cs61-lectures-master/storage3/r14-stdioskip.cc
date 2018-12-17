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
    size_t read_size = 8192;
    size_t skip_size = read_size * 256;
    double start = tstamp();

    size_t n = 0;
    for (size_t pos = 0; pos < size; pos += skip_size) {
        fseek(f, pos, SEEK_SET);

        size_t start_n = n;
        while (n < start_n + read_size) {
            int ch = fgetc(f);
            if (ch == EOF && ferror(f)) {
                perror("fgetc");
                exit(1);
            } else if (ch == EOF) {
                break;
            }
            n += 1;
            if (n % PRINT_FREQUENCY == 0) {
                report(n, tstamp() - start);
            }
        }
    }

    fclose(f);
    report(n, tstamp() - start);
    fprintf(stderr, "\n");
}
