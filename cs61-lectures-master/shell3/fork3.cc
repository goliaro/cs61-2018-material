#include "helpers.hh"

int main() {
    printf("Hello from initial pid %d\n", getpid());

    pid_t p1 = fork();
    assert(p1 >= 0);

    pid_t p2 = fork();
    assert(p2 >= 0);

    printf("Hello from final pid %d\n", getpid());
}
