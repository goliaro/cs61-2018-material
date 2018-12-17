#include "helpers.hh"

int main() {
    fprintf(stderr, "Hello from parent pid %d\n", getpid());

    // Start a child
    pid_t p1 = fork();
    assert(p1 >= 0);
    if (p1 == 0) {
        usleep(500000);
        fprintf(stderr, "Goodbye from child pid %d\n", getpid());
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
        fprintf(stderr, "Child timed out\n");
    } else if (WIFEXITED(status)) {
        fprintf(stderr, "Child exited with status %d after %g sec\n",
                WEXITSTATUS(status), tstamp() - start_time);
    } else {
        fprintf(stderr, "Child exited abnormally [%x]\n", status);
    }
}
