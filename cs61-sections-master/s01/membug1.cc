int main() {
    char* ptr = new char[2001];
    delete (ptr + 100);
}
