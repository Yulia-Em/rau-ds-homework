#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
void resizeVector(std::vector<T>& vec, size_t new_size, const T& default_value) {
    std::cout << "До изменения размера (size=" << vec.size() << "): ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    vec.resize(new_size, default_value);

    std::cout << "После изменения размера (size=" << vec.size() << "): ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void test_resize_vector() {
    // 1. Обычный случай: увеличение размера с заполнением по умолчанию
    std::vector<int> v1 = { 1, 2, 3 };
    resizeVector(v1, 5, 42);
    assert((v1 == std::vector<int>{1, 2, 3, 42, 42}));

    // 2. Крайний случай: уменьшение размера
    std::vector<int> v2 = { 1, 2, 3, 4, 5 };
    resizeVector(v2, 2, 0);
    assert((v2 == std::vector<int>{1, 2}));

    // 3. Крайний случай: уменьшение до 0 элементов
    std::vector<int> v3 = { 10, 20 };
    resizeVector(v3, 0, 99);
    assert(v3.empty());

    // 4. Крайний случай: изменение размера из пустого вектора
    std::vector<int> v4;
    resizeVector(v4, 3, 7);
    assert((v4 == std::vector<int>{7, 7, 7}));

    std::cout << "resizeVector passed" << std::endl;
}

int main() {
    test_resize_vector();
    return 0;
}