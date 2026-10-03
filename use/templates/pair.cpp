#include <iostream>
#include <string>
#include <cassert>

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair() : first{}, second{} {}
    Pair(const T1& f, const T2& s) : first(f), second(s) {}

    void print() const {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }
};

void test_pair() {
    // 1. Пара (int, double)
    Pair<int, double> p1(10, 3.14);
    assert(p1.first == 10);
    assert(p1.second == 3.14);
    p1.print();

    // 2. Пара (std::string, int)
    Pair<std::string, int> p2("Age", 25);
    assert(p2.first == "Age");
    assert(p2.second == 25);
    p2.print();

    // 3. Крайний случай: проверка конструктора по умолчанию
    Pair<int, std::string> p3;
    assert(p3.first == 0);
    assert(p3.second == "");

    std::cout << "test_pair passed" << std::endl;
}

int main() {
    test_pair();
    return 0;
}