#include <iostream>
#include <cassert>
#include <cmath>

template <typename T>
class Range {
private:
    T m_start;
    T m_end;

public:
    Range(T start, T end) : m_start(start), m_end(end) {}

    bool contains(const T& value) const {
        return value >= m_start && value <= m_end;
    }

    auto length() const -> decltype(m_end - m_start) {
        return m_end - m_start;
    }

    void print() const {
        std::cout << "[" << m_start << ", " << m_end << "]" << std::endl;
    }
};

void test_range() {
    // 1. Диапазон int: [3, 10]
    Range<int> r_int(3, 10);
    assert(r_int.contains(3));
    assert(r_int.contains(5));
    assert(r_int.contains(10));
    assert(!r_int.contains(2));
    assert(!r_int.contains(11));
    assert(r_int.length() == 7);
    r_int.print();

    // 2. Диапазон double: [1.5, 5.5]
    Range<double> r_double(1.5, 5.5);
    assert(r_double.contains(3.0));
    assert(!r_double.contains(1.4));
    assert(std::abs(r_double.length() - 4.0) < 1e-9);
    r_double.print();

    // 3. Диапазон char: ['a', 'f']
    Range<char> r_char('a', 'f');
    assert(r_char.contains('c'));
    assert(!r_char.contains('z'));
    assert(r_char.length() == 5); // 'f' - 'a' = 5
    r_char.print();

    std::cout << "test_range passed" << std::endl;
}

int main() {
    test_range();
    return 0;
}