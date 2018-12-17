#include "helpers.hh"

void signal_handler(int signal) {
    (void) signal;
}

int main(int, char** argv) {
    fprintf(stderr, "Hello from %s parent pid %d\n", argv[0], getpid());

    // Demand that SIGALRM interrupt system calls
    int r = set_signal_handler(SIGALRM, signal_handler);
    assert(r >= 0);
    // Set the timer
    struct itimerval itimer;
    timerclear(&itimer.it_interval);
    itimer.it_value.tv_sec = 0;
    itimer.it_value.tv_usec = 750000;
    r = setitimer(ITIMER_REAL, &itimer, nullptr);
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
    int status;
    pid_t exited_pid = waitpid(p1, &status, 0);
    if (exited_pid == -1 && errno == EINTR) {
        fprintf(stderr, "%s parent interrupted by signal after %g sec\n",
                argv[0], tstamp() - start_time);
        exit(0);
    }

    assert(exited_pid == 0 || exited_pid == p1);
    if (exited_pid == 0) {
        fprintf(stderr, "%s child timed out\n", argv[0]);
    } else if (WIFEXITED(status)) {
        fprintf(stderr, "%s child exited with status %d after %g sec\n",
                argv[0], WEXITSTATUS(status), tstamp() - start_time);
    } else {
        fprintf(stderr, "%s child exited abnormally [%x]\n", argv[0], status);
    }
}
