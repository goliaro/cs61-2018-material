#include <cstdio>
#include <cstdlib>
#include <cassert>

void greet() {
    char buf[16];

    printf("Hello! What is your name?\n");
    scanf("%s", buf);
    printf("Nice to meet you, %s!\n", buf);
}

int main() {
    greet();
    return 0;
}
