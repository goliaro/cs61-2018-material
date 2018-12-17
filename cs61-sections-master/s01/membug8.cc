int main() {
    int* array = new int[10];
    for (int i = 0; i <= 10; ++i) {
        array[i] = 1;
    }
    int* ptr1 = new int(3);
    delete[] array;
    delete ptr1;
}
