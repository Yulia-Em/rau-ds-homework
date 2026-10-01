#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createAndFillVector(int n) {
    std::vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    return vec;
}

void test_create_and_fill_vector() {
    // Обычный случай
    std::vector<int> expected5 = { 1, 2, 3, 4, 5 };
    assert(createAndFillVector(5) == expected5);

    // Крайний случай: N = 0 (пустой вектор)
    assert(createAndFillVector(0).empty());

    // Крайний случай: N = 1 (один элемент)
    std::vector<int> expected1 = { 1 };
    assert(createAndFillVector(1) == expected1);

    std::cout << "createAndFillVector passed" << std::endl;
}

int main() {
    test_create_and_fill_vector();
    return 0;
}