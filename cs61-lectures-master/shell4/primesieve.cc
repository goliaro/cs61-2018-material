#include "helpers.hh"

void add_filter(const char* const* argv) {
    int pipefd[2];
    int r = pipe(pipefd);
    assert(r >= 0);

    pid_t pid = fork();
    assert(pid >= 0);

    if (pid == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        execvp(argv[0], (char**) argv);
        assert(0);
    }

    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
}

int main() {
    // We never want buffering on stdin or stdout.
    setvbuf(stdin, nullptr, _IONBF, 0);
    setvbuf(stdout, nullptr, _IONBF, 0);

    // sieve of Eratosthenes!
    // Start with a sequence of all numbers, starting from 2
    {
        const char* argv[] = { "seq", "2", "1000000", nullptr };
        add_filter(argv);
    }

    // Repeatedly:
    // 1. Read a number (the next prime)
    // 2. Cross off all multiples of that number by
    //    introducing another filter
    int last_prime;
    while (scanf("%d", &last_prime) == 1) {
        printf("%d\n", last_prime);

        char buf[20];
        sprintf(buf, "%d", last_prime);
        const char* argv[] = { "./filtermultiples", buf, nullptr };
        add_filter(argv);
    }
}
