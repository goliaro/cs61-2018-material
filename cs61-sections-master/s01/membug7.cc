int main() {
    int* array = new int[10];
    for (int i = 0; i <= 10; ++i)
        array[i] = 1;
    delete[] array;
}
