#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

template <typename T, size_t N>
class FixedArray {
private:
    T data[N]{};

public:
    void set(int index, T value) {
        if (index < 0 || static_cast<size_t>(index) >= N) {
            throw std::out_of_range("Index out of bounds");
        }
        data[index] = value;
    }

    T get(int index) const {
        if (index < 0 || static_cast<size_t>(index) >= N) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    size_t size() const {
        return N;
    }
};

void test_fixed_array() {
    // 1. Работа с целыми числами (int)
    FixedArray<int, 5> arr_int;
    assert(arr_int.size() == 5);
    arr_int.set(0, 100);
    arr_int.set(4, 500);
    assert(arr_int.get(0) == 100);
    assert(arr_int.get(4) == 500);

    // 2. Работа со строками (std::string)
    FixedArray<std::string, 3> arr_str;
    assert(arr_str.size() == 3);
    arr_str.set(1, "Hello");
    assert(arr_str.get(1) == "Hello");

    // 3. Крайний случай: проверка генерации исключения при выходе за границы
    bool exception_caught = false;
    try {
        arr_int.get(10);
    }
    catch (const std::out_of_range&) {
        exception_caught = true;
    }
    assert(exception_caught);

    std::cout << "test_fixed_array passed" << std::endl;
}

int main() {
    test_fixed_array();
    return 0;
}