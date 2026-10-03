#include <iostream>
#include <string>
#include <cassert>
#include <cmath>

template <typename T>
T sumArray(const T* arr, size_t size) {
    T sum{};
    for (size_t i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

void test_sum_array() {
    // 1. int
    int int_arr[] = { 1, 2, 3, 4, 5 };
    assert(sumArray(int_arr, 5) == 15);

    // 2. double
    double double_arr[] = { 1.1, 2.2, 3.3 };
    assert(std::abs(sumArray(double_arr, 3) - 6.6) < 1e-9);

    // 3. std::string (конкатенация)
    std::string string_arr[] = { "C++", " ", "Templates" };
    assert(sumArray(string_arr, 3) == "C++ Templates");

    // 4. Граничный случай: массив из одного элемента
    int single_elem[] = { 42 };
    assert(sumArray(single_elem, 1) == 42);

    // 5. Граничный случай: нулевой размер
    int empty_arr[] = { 0 };
    assert(sumArray(empty_arr, 0) == 0);

    std::cout << "test_sum_array passed" << std::endl;
}

int main() {
    test_sum_array();
    return 0;
}