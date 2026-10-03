#include <iostream>
#include <string>

template <typename T>
void printElement(const T& val) {
    std::cout << val << std::endl;
}

void test_print_element() {

    // 1. int
    int i = 42;
    printElement(i);

    // 2. double
    double d = 3.14159;
    printElement(d);

    // 3. std::string
    std::string s = "Hello, C++ Templates!";
    printElement(s);
}

int main() {
    test_print_element();
    return 0;
}