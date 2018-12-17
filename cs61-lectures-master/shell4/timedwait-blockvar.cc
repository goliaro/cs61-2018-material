#include "helpers.hh"

static volatile sig_atomic_t got_signal;

void signal_handler(int signal) {
    (void) signal;
    got_signal = 1;
}

int main(int, char** argv) {
    //fprintf(stderr, "Hello from %s parent pid %d\n", argv[0], getpid());

    // Demand that SIGCHLD interrupt system calls
    int r = set_signal_handler(SIGCHLD, signal_handler);
    assert(r >= 0);

    // Start a child
    pid_t p1 = fork();
    assert(p1 >= 0);
    if (p1 == 0) {
        //usleep(500000);
        //fprintf(stderr, "Goodbye from %s child pid %d\n", argv[0], getpid());
        exit(0);
    }
    double start_time = tstamp();

    // Wait for the child and print its status
    if (!got_signal) {
        r = usleep(750000);
    }

    int status;
    pid_t exited_pid = waitpid(p1, &status, WNOHANG);
    assert(exited_pid == 0 || exited_pid == p1);
    if (exited_pid == 0) {
        fprintf(stderr, "%s child %d timed out\n", argv[0], p1);
    } else if (WIFEXITED(status)) {
        double lifetime = tstamp() - start_time;
        if (lifetime > 0.1) {
            fprintf(stderr,
                    "%s child %d exited with status %d after %g sec\n",
                    argv[0], p1, WEXITSTATUS(status), lifetime);
        }
    } else {
        fprintf(stderr, "%s child %d exited abnormally [%x]\n",
                argv[0], p1, status);
    }
}
