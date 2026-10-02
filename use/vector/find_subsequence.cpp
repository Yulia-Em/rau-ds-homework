#include <iostream>
#include <vector>
#include <cassert>

int findSubsequence(const std::vector<int>& main_vec, const std::vector<int>& sub_vec) {
    if (sub_vec.empty()) {
        return 0;
    }
    if (sub_vec.size() > main_vec.size()) {
        return -1;
    }

    for (size_t i = 0; i <= main_vec.size() - sub_vec.size(); ++i) {
        bool match = true;
        for (size_t j = 0; j < sub_vec.size(); ++j) {
            if (main_vec[i + j] != sub_vec[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            return static_cast<int>(i);
        }
    }

    return -1;
}

void test_find_subsequence() {
    // 1. Обычный случай: вхождение в середине
    std::vector<int> main1 = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> sub1 = { 3, 4, 5 };
    assert(findSubsequence(main1, sub1) == 2);

    // 2. Обычный случай: подпоследовательность не найдена
    std::vector<int> sub2 = { 7, 8 };
    assert(findSubsequence(main1, sub2) == -1);

    // 3. Крайний случай: вхождение в самом начале
    std::vector<int> sub3 = { 1, 2 };
    assert(findSubsequence(main1, sub3) == 0);

    // 4. Крайний случай: вхождение в самом конце
    std::vector<int> sub4 = { 5, 6 };
    assert(findSubsequence(main1, sub4) == 4);

    // 5. Крайний случай: пустая искомая подпоследовательность
    assert(findSubsequence(main1, {}) == 0);

    // 6. Крайний случай: подпоследовательность длиннее основного вектора
    std::vector<int> long_sub = { 1, 2, 3, 4, 5, 6, 7 };
    assert(findSubsequence(main1, long_sub) == -1);

    std::cout << "findSubsequence passed" << std::endl;
}

int main() {
    test_find_subsequence();
    return 0;
}