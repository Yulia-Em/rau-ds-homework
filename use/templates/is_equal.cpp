#include <iostream>
#include <cstring>
#include <string>
#include <cassert>

template <typename T>
bool isEqual(const T& a, const T& b) {
    return a == b;
}

template <>
bool isEqual<const char*>(const char* const& a, const char* const& b) {
    if (a == nullptr && b == nullptr) return true;
    if (a == nullptr || b == nullptr) return false;
    return std::strcmp(a, b) == 0;
}

void test_is_equal() {
    // 1. Обычные типы (int, double, std::string)
    assert(isEqual(10, 10));
    assert(!isEqual(10, 20));

    assert(isEqual(3.14, 3.14));
    assert(!isEqual(3.14, 2.71));

    assert(isEqual(std::string("abc"), std::string("abc")));
    assert(!isEqual(std::string("abc"), std::string("xyz")));

    // 2. Специализация для const char* 
    char str1[] = "hello";
    char str2[] = "hello";
    char str3[] = "world";

    // Смотрим массивы находятся по разным адресам в памяти
    assert(static_cast<void*>(str1) != static_cast<void*>(str2));

    const char* p1 = str1;
    const char* p2 = str2;
    const char* p3 = str3;

    // Сравнение по содержимому возвращает true
    assert(isEqual(p1, p2));
    assert(!isEqual(p1, p3));

    // 3. Крайний случай: проверка с nullptr
    const char* null_a = nullptr;
    const char* null_b = nullptr;
    assert(isEqual(null_a, null_b));
    assert(!isEqual(p1, null_a));

    std::cout << "test_is_equal passed" << std::endl;
}

int main() {
    test_is_equal();
    return 0;
}