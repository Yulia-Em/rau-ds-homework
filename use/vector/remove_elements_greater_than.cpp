#include <iostream>
#include <vector>
#include <cassert>

int removeElementsGreaterThan(std::vector<int>& vec, int t) {
    int removed = 0;

    while (!vec.empty() && vec.back() > t) {
        vec.pop_back();
        removed++;
    }

    return removed;
}

void test_remove_elements_greater_than() {
    // 1. Обычный случай
    std::vector<int> v1 = { 1, 3, 5, 7, 9 };
    assert(removeElementsGreaterThan(v1, 5) == 2);
    assert((v1 == std::vector<int>{1, 3, 5}));

    // 2. Крайний случай: пустой вектор
    std::vector<int> v2 = {};
    assert(removeElementsGreaterThan(v2, 5) == 0);
    assert(v2.empty());

    // 3. Крайний случай: один элемент (меньше/равен порогу)
    std::vector<int> v3 = { 3 };
    assert(removeElementsGreaterThan(v3, 5) == 0);
    assert((v3 == std::vector<int>{3}));

    // 4. Крайний случай: один элемент (больше порога)
    std::vector<int> v4 = { 7 };
    assert(removeElementsGreaterThan(v4, 5) == 1);
    assert(v4.empty());

    // 5. Крайний случай: ни один элемент не больше порога
    std::vector<int> v5 = { 1, 2, 3 };
    assert(removeElementsGreaterThan(v5, 10) == 0);
    assert((v5 == std::vector<int>{1, 2, 3}));

    // 6. Крайний случай: все элементы больше порога
    std::vector<int> v6 = { 10, 20, 30 };
    assert(removeElementsGreaterThan(v6, 5) == 3);
    assert(v6.empty());

    std::cout << "removeElementsGreaterThan passed" << std::endl;
}

int main() {
    test_remove_elements_greater_than();
    return 0;
}