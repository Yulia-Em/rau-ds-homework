#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> workWithEmptyVector() {
    std::vector<int> vec;

    for (int i = 1; i <= 10; i++) {
        vec.push_back(i);
        std::cout << vec.size() << " " << vec.capacity() << std::endl;
    }
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return vec;
}

void test_work_with_empty_vector() {
    // Обычный случай: проверка результирующего вектора и его размера
    std::vector<int> result = workWithEmptyVector();
    std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    assert(result == expected);
    assert(result.size() == 10);
    assert(result.capacity() >= 10);

    std::cout << "workWithEmptyVector passed" << std::endl;
}

int main() {
    test_work_with_empty_vector();
    return 0;
}