#include "helpers.hh"

int signalpipe[2];

void signal_handler(int signal) {
    (void) signal;
    ssize_t r = write(signalpipe[1], "!", 1);
    assert(r == 1);
}

int main(int, char** argv) {
    //fprintf(stderr, "Hello from %s parent pid %d\n", argv[0], getpid());

    int r = pipe(signalpipe);
    assert(r >= 0);
    r = set_signal_handler(SIGCHLD, signal_handler);
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

    // Wait for 0.75 sec, or until a byte is written to `signalpipe`,
    // whichever happens first
    struct timeval timeout = { 0, 750000 };
    fd_set fds;
    FD_SET(signalpipe[0], &fds);
    r = select(signalpipe[0] + 1, &fds, nullptr, nullptr, &timeout);

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
