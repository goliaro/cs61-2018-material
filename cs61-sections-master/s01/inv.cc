#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    if (isatty(STDIN_FILENO) || isatty(STDOUT_FILENO)) {
        fprintf(stderr, "Usage: ./inv < INPUT.ppm > OUTPUT.ppm\n");
        exit(1);
    }

    // get file size
    struct stat st;
    int r = fstat(STDIN_FILENO, &st);
    assert(r == 0);

    // read entire file into dynamically-allocated array
    char* data = new char[st.st_size + 1];
    size_t nread = read(STDIN_FILENO, data, st.st_size);
    assert(nread == (size_t) st.st_size);
    data[nread] = 0; // ensure NUL termination

    // check magic number
    if (data[0] != 'P' || data[1] != '6') {
        fprintf(stderr, "input not a PPM\n");
        exit(1);
    }

    // read size and maximum pixel value
    int w, h, maxval, nchars_read;
    r = sscanf(data, "P6 %u %u %u%n", &w, &h, &maxval, &nchars_read);
    assert(r == 3);
    assert(w > 0 && h > 0 && maxval > 0 && maxval <= 255);

    // skip to first pixel (must be unsigned char!) and invert RGBs
    // can use the same memory since the image doesn't change size!

    // YOUR CODE HERE

    // write entire file from array to stdout
    size_t nwrote = write(STDOUT_FILENO, data, st.st_size);
    assert(nwrote == (size_t) st.st_size);

    delete[] data;
    return 0;
}
