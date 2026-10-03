#include <iostream>
#include <vector>
#include <string>
#include <cassert>

template <typename T>
int linearSearch(const std::vector<T>& vec, const T& target) {
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

void test_linear_search() {
    // 1. int
    std::vector<int> int_vec = { 10, 20, 30, 40, 50 };
    assert(linearSearch(int_vec, 30) == 2);
    assert(linearSearch(int_vec, 99) == -1);

    // 2. double
    std::vector<double> double_vec = { 1.1, 2.2, 3.3 };
    assert(linearSearch(double_vec, 2.2) == 1);
    assert(linearSearch(double_vec, 4.4) == -1);

    // 3. std::string
    std::vector<std::string> string_vec = { "apple", "banana", "cherry" };
    assert(linearSearch(string_vec, std::string("banana")) == 1);
    assert(linearSearch(string_vec, std::string("grape")) == -1);

    // 4. Граничный случай: пустой вектор
    std::vector<int> empty_vec;
    assert(linearSearch(empty_vec, 5) == -1);

    // 5. Граничный случай: элемент в самом начале / конце
    assert(linearSearch(int_vec, 10) == 0);
    assert(linearSearch(int_vec, 50) == 4);

    std::cout << "test_linear_search passed" << std::endl;
}

int main() {
    test_linear_search();
    return 0;
}