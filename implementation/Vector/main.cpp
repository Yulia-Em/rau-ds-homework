#include "Vector.h"
#include <cassert>
#include <iostream>

void test_default_constructor() {
    Vector<int> v;
    assert(v.empty());
    assert(v.size() == 0);
    assert(v.capacity() == 0);

    std::cout << "test_default_constructor passed" << std::endl;
}

void test_size_constructor() {
    Vector<int> v(5);
    assert(v.size() == 5);
    assert(v.capacity() == 5);
    assert(v[0] == 0 && v[4] == 0);

    // Граничный случай: размер 0
    Vector<int> zero_v(0);
    assert(zero_v.empty());

    std::cout << "test_size_constructor passed" << std::endl;
}

void test_copy_constructor() {
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);

    // Нормальный случай
    Vector<int> v2(v1);
    assert(v2.size() == 2);
    assert(v2[0] == 10 && v2[1] == 20);

    // Граничный случай: копирование пустого вектора
    Vector<int> empty1;
    Vector<int> empty2(empty1);
    assert(empty2.empty());

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    // Нормальный случай
    Vector<int> v2;
    v2 = v1;
    assert(v2.size() == 2);
    assert(v2[0] == 1 && v2[1] == 2);

    // Граничный случай: присваивание пустого вектора
    Vector<int> empty_v;
    v2 = empty_v;
    assert(v2.empty());

    std::cout << "test_assignment_operator passed" << std::endl;
}

void test_push_back() {
    Vector<int> v;

    // Нормальный случай
    v.push_back(5);
    assert(v.size() == 1);
    assert(v[0] == 5);

    v.push_back(10);
    v.push_back(15);
    assert(v.size() == 3);
    assert(v.back() == 15);

    std::cout << "test_push_back passed" << std::endl;
}

void test_pop_back() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    // Нормальный случай
    v.pop_back();
    assert(v.size() == 1);
    assert(v.back() == 10);

    // Граничный случай: pop_back до пустого состояния
    v.pop_back();
    assert(v.empty());

    // Граничный случай: pop_back на пустом векторе
    v.pop_back();
    assert(v.empty());

    std::cout << "test_pop_back passed" << std::endl;
}

void test_operator_bracket() {
    Vector<int> v;
    v.push_back(100);
    v.push_back(200);

    // Нормальный случай
    assert(v[0] == 100);
    assert(v[1] == 200);

    v[0] = 500;
    assert(v[0] == 500);

    std::cout << "test_operator_bracket passed" << std::endl;
}

void test_at() {
    Vector<int> v;
    v.push_back(10);

    // Нормальный случай
    assert(v.at(0) == 10);

    // Граничный случай: выход за границы
    bool caught = false;
    try {
        v.at(1);
    }
    catch (const std::out_of_range&) {
        caught = true;
    }
    assert(caught);

    std::cout << "test_at passed" << std::endl;
}

void test_front() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    // Нормальный случай
    assert(v.front() == 10);

    // Граничный случай: один элемент
    Vector<int> single;
    single.push_back(7);
    assert(single.front() == 7);

    std::cout << "test_front passed" << std::endl;
}

void test_back() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    // Нормальный случай
    assert(v.back() == 20);

    // Граничный случай: один элемент
    Vector<int> single;
    single.push_back(7);
    assert(single.back() == 7);

    std::cout << "test_back passed" << std::endl;
}

void test_clear() {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);

    // Нормальный случай
    v.clear();
    assert(v.empty());
    assert(v.size() == 0);

    // Граничный случай: повторный clear
    v.clear();
    assert(v.empty());

    std::cout << "test_clear passed" << std::endl;
}

void test_reserve_and_iterators() {
    Vector<int> v;
    v.reserve(10);
    assert(v.capacity() == 10);

    v.push_back(1);
    v.push_back(2);

    assert(*v.begin() == 1);
    assert(*(v.end() - 1) == 2);

    std::cout << "test_reserve_and_iterators passed" << std::endl;
}

int main() {
    std::cout << "Running Vector tests" << std::endl;

    test_default_constructor();
    test_size_constructor();
    test_copy_constructor();
    test_assignment_operator();
    test_push_back();
    test_pop_back();
    test_operator_bracket();
    test_at();
    test_front();
    test_back();
    test_clear();
    test_reserve_and_iterators();

    std::cout << "All tests passed" << std::endl;
    return 0;
}