#include "helpers.hh"

void signal_handler(int signal) {
    (void) signal;
}

int main(int, char** argv) {
    fprintf(stderr, "Hello from %s parent pid %d\n", argv[0], getpid());

    // Demand that SIGCHLD interrupt system calls
    int r = set_signal_handler(SIGCHLD, signal_handler);
    assert(r >= 0);

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
    r = usleep(750000);
    if (r == -1 && errno == EINTR) {
        fprintf(stderr, "%s parent interrupted by signal after %g sec\n",
                argv[0], tstamp() - start_time);
    }

    int status;
    pid_t exited_pid = waitpid(p1, &status, WNOHANG);
    assert(exited_pid == 0 || exited_pid == p1);
    if (exited_pid == 0) {
        fprintf(stderr, "%s child %d timed out\n", argv[0], p1);
    } else if (WIFEXITED(status)) {
        double lifetime = tstamp() - start_time;
        fprintf(stderr, "%s child %d exited with status %d after %g sec\n",
                argv[0], p1, WEXITSTATUS(status), lifetime);
    } else {
        fprintf(stderr, "%s child %d exited abnormally [%x]\n",
                argv[0], p1, status);
    }
}
