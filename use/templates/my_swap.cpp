#include <iostream>
#include <string>
#include <cassert>
#include <utility>

template <typename T>
void mySwap(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

void test_my_swap() {
    // 1. int
    int a1 = 10, b1 = 20;
    mySwap(a1, b1);
    assert(a1 == 20 && b1 == 10);

    // 2. double
    double a2 = 1.5, b2 = 9.8;
    mySwap(a2, b2);
    assert(a2 == 9.8 && b2 == 1.5);

    // 3. std::string
    std::string a3 = "first", b3 = "second";
    mySwap(a3, b3);
    assert(a3 == "second" && b3 == "first");

    // 4. Граничный случай: обмен переменной самой с собой
    int self = 100;
    mySwap(self, self);
    assert(self == 100);

    std::cout << "test_my_swap passed" << std::endl;
}

int main() {
    test_my_swap();
    return 0;
}