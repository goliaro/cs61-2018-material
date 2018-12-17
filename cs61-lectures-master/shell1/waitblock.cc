#include "helpers.hh"

void signal_handler(int signal) {
    (void) signal;
}

int main() {
    fprintf(stderr, "Hello from parent pid %d\n", getpid());

    // Demand that SIGCHLD interrupt system calls
    int r = set_signal_handler(SIGCHLD, signal_handler);
    assert(r >= 0);

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
    r = usleep(750000);
    if (r == -1 && errno == EINTR) {
        fprintf(stderr, "usleep interrupted by signal after %g sec\n",
                tstamp() - start_time);
    }

    int status;
    pid_t exited_pid = waitpid(p1, &status, WNOHANG);
    assert(exited_pid == 0 || exited_pid == p1);
    if (exited_pid == 0) {
        fprintf(stderr, "Child timed out\n");
    } else if (WIFEXITED(status)) {
        fprintf(stderr, "Child exited with status %d after %g sec\n",
                WEXITSTATUS(status), tstamp() - start_time);
    } else {
        fprintf(stderr, "Child exited abnormally [%x]\n", status);
    }
}
