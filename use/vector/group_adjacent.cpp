#include <iostream>
#include <vector>
#include <cassert>

std::vector<std::vector<int>> groupAdjacent(const std::vector<int>& vec) {
    std::vector<std::vector<int>> result;
    if (vec.empty()) {
        return result;
    }

    std::vector<int> current_group = { vec[0] };

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] == vec[i - 1]) {
            current_group.push_back(vec[i]);
        }
        else {
            result.push_back(current_group);
            current_group = { vec[i] };
        }
    }
    result.push_back(current_group);

    return result;
}

void test_group_adjacent() {
    // 1. Обычный случай из примера
    std::vector<int> v1 = { 1, 1, 2, 2, 2, 3, 1, 1 };
    std::vector<std::vector<int>> expected1 = { { 1, 1 },{ 2, 2, 2 },{ 3 },{ 1, 1 } };
    assert(groupAdjacent(v1) == expected1);

    // 2. Крайний случай: пустой вектор
    assert(groupAdjacent({}).empty());

    // 3. Крайний случай: один элемент
    std::vector<std::vector<int>> expected2 = { { 5 } };
    assert(groupAdjacent({ 5 }) == expected2);

    // 4. Крайний случай: все элементы одинаковые
    std::vector<std::vector<int>> expected3 = { { 4, 4, 4 } };
    assert(groupAdjacent({ 4, 4, 4 }) == expected3);

    // 5. Крайний случай: все элементы уникальны (группы по 1 элементу)
    std::vector<std::vector<int>> expected4 = { { 1 },{ 2 },{ 3 } };
    assert(groupAdjacent({ 1, 2, 3 }) == expected4);

    std::cout << "groupAdjacent passed" << std::endl;
}

int main() {
    test_group_adjacent();
    return 0;
}