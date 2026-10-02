#include <iostream>
#include <vector>
#include <string>
#include <cassert>

template <typename T, typename Predicate>
std::vector<T> filterVector(const std::vector<T>& vec, Predicate pred) {
    std::vector<T> result;
    for (const auto& elem : vec) {
        if (pred(elem)) {
            result.push_back(elem);
        }
    }
    return result;
}

bool isEven(int x) {
    return x % 2 == 0;
}

void test_filter_vector() {
    // 1. Обычный случай: фильтрация чётных чисел
    std::vector<int> v1 = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> expected1 = { 2, 4, 6 };
    assert(filterVector(v1, isEven) == expected1);

    // 2. Крайний случай: ни один элемент не проходит фильтр
    std::vector<int> v2 = { 1, 3, 5 };
    assert(filterVector(v2, isEven).empty());

    // 3. Крайний случай: все элементы проходят фильтр
    std::vector<int> v3 = { 2, 4, 6, 8 };
    assert(filterVector(v3, isEven) == v3);

    // 4. Крайний случай: пустой исходный вектор
    std::vector<int> empty;
    assert(filterVector(empty, isEven).empty());

    // 5. Проверка работы шаблона с лямбда-функцией и типом std::string
    auto isLong = [](const std::string& s) { return s.length() > 3; };
    std::vector<std::string> words = { "cat", "elephant", "dog", "bear" };
    std::vector<std::string> expectedWords = { "elephant", "bear" };
    assert(filterVector(words, isLong) == expectedWords);

    std::cout << "filterVector passed" << std::endl;
}

int main() {
    test_filter_vector();
    return 0;
}