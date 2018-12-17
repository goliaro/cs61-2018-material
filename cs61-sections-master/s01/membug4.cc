#include <stdio.h>

int main() {
    int* ptr1 = new int[3];
    delete[] ptr1;
    printf("ptr1 = %p\n", ptr1);
    *ptr1 = 1;
    printf("*ptr1 = %d\n", *ptr1);

    int* ptr2;
    printf("ptr2 = %p\n", ptr2);
    *ptr2 = 2;
    printf("*ptr2 = %d\n", *ptr2);
}
