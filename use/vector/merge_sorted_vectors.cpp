#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> mergeSortedVectors(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int> result;
    result.reserve(vec1.size() + vec2.size());

    size_t i = 0, j = 0;
    while (i < vec1.size() && j < vec2.size()) {
        if (vec1[i] <= vec2[j]) {
            result.push_back(vec1[i++]);
        }
        else {
            result.push_back(vec2[j++]);
        }
    }

    while (i < vec1.size()) result.push_back(vec1[i++]);
    while (j < vec2.size()) result.push_back(vec2[j++]);

    return result;
}

void test_merge_sorted_vectors() {
    // 1. Обычный случай
    std::vector<int> v1 = { 1, 3, 5, 7 };
    std::vector<int> v2 = { 2, 4, 6, 8, 9 };
    std::vector<int> expected1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    assert(mergeSortedVectors(v1, v2) == expected1);

    // 2. Крайний случай: один из векторов пустой
    std::vector<int> v3 = { 1, 2, 3 };
    std::vector<int> empty;
    assert(mergeSortedVectors(v3, empty) == v3);
    assert(mergeSortedVectors(empty, v3) == v3);

    // 3. Крайний случай: оба вектора пустые
    assert(mergeSortedVectors(empty, empty).empty());

    // 4. Крайний случай: элементы первого вектора строго меньше элементов второго
    std::vector<int> v4 = { 1, 2 };
    std::vector<int> v5 = { 10, 20 };
    std::vector<int> expected2 = { 1, 2, 10, 20 };
    assert(mergeSortedVectors(v4, v5) == expected2);

    std::cout << "mergeSortedVectors passed" << std::endl;
}

int main() {
    test_merge_sorted_vectors();
    return 0;
}