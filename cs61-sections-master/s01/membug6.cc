int main() {
    char* str = new char[10];
    for (int i = 0; i < 10; ++i) {
        str[i] = 'A';
    }

    str = new char[10];
    for (int i = 0; i < 10; ++i) {
        str[i] = 'B';
    }
    delete[] str;
}
