#include "helpers.hh"

int main(int, char** argv) {
    fprintf(stderr, "Hello from %s parent pid %d\n", argv[0], getpid());

    // Start a child
    pid_t p1 = fork();
    assert(p1 >= 0);
    if (p1 == 0) {
        usleep(500000);
        fprintf(stderr, "Goodbye from %s child pid %d\n", argv[0], getpid());
        exit(0);
    }
    double start_time = tstamp();

    // Wait for the child and print its status
    int status;
    pid_t exited_pid = 0;
    while (tstamp() - start_time < 0.75 && exited_pid == 0) {
        exited_pid = waitpid(p1, &status, WNOHANG);
        assert(exited_pid == 0 || exited_pid == p1);
    }

    if (exited_pid == 0) {
        fprintf(stderr, "%s child timed out\n", argv[0]);
    } else if (WIFEXITED(status)) {
        fprintf(stderr, "%s child exited with status %d after %g sec\n",
                argv[0], WEXITSTATUS(status), tstamp() - start_time);
    } else {
        fprintf(stderr, "%s child exited abnormally [%x]\n", argv[0], status);
    }
}
