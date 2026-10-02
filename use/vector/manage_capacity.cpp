#include <iostream>
#include <vector>
#include <cassert>

void manageCapacity(std::vector<int>& vec) {
    std::cout << "Начальный размер: " << vec.size()
        << ", вместимость: " << vec.capacity() << std::endl;

    vec.reserve(vec.size() + 500);

    std::cout << "После reserve() вместимость: " << vec.capacity() << std::endl;

    for (int i = 1; i <= 500; ++i) {
        vec.push_back(i);
    }

    std::cout << "Конечный размер: " << vec.size()
        << ", вместимость: " << vec.capacity() << std::endl;
}

void test_manage_capacity() {
    // 1. Обычный случай: вектор с начальными элементами
    std::vector<int> v1 = { 10, 20, 30 };
    size_t initial_size = v1.size();
    manageCapacity(v1);
    assert(v1.size() == initial_size + 500);
    assert(v1.capacity() >= initial_size + 500);
    assert(v1.back() == 500);

    // 2. Крайний случай: пустой вектор
    std::vector<int> v2;
    manageCapacity(v2);
    assert(v2.size() == 500);
    assert(v2.capacity() >= 500);
    assert(v2.front() == 1);
    assert(v2.back() == 500);

    std::cout << "manageCapacity passed" << std::endl;
}

int main() {
    test_manage_capacity();
    return 0;
}