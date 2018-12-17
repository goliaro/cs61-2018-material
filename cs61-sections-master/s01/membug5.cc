int main() {
    int* ptr1 = new int(1);
    int* ptr2 = new int(2);
    delete ptr1;
    delete ptr1;
}
