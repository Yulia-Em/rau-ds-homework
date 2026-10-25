#include "Stack.h"
#include <cassert>
#include <iostream>

void test_default_constructor() {
    Stack<int> s;
    assert(s.is_empty() == true);
    assert(s.size() == 0);
    assert(s.capacity() > 0);

    std::cout << "test_default_constructor passed" << std::endl;
}

void test_push() {
    Stack<int> s;

    // Стандартное добавление
    s.push(5);
    assert(s.size() == 1);
    assert(s.top() == 5);
    assert(s.is_empty() == false);

    s.push(10);
    s.push(15);
    assert(s.size() == 3);
    assert(s.top() == 15);

    // Граничный случай: превышение стартовой вместимости
    int old_cap = s.capacity();
    for (int i = 0; i < 10; ++i) {
        s.push(i);
    }
    assert(s.size() == 13);
    assert(s.capacity() > old_cap);
    assert(s.top() == 9);

    std::cout << "test_push passed" << std::endl;
}

void test_pop() {
    Stack<int> s;
    s.push(10);
    s.push(20);

    // Стандартное удаление
    s.pop();
    assert(s.size() == 1);
    assert(s.top() == 10);

    // Граничный случай: очистка до нуля
    s.pop();
    assert(s.is_empty() == true);
    assert(s.size() == 0);

    // Граничный случай: pop() на пустом стеке
    s.pop();
    assert(s.is_empty() == true);
    assert(s.size() == 0);

    std::cout << "test_pop passed" << std::endl;
}

void test_top_and_peek() {
    Stack<int> s;
    s.push(42);

    // Проверка top() и peek()
    assert(s.top() == 42);
    assert(s.peek() == 42);

    // Изменение через ссылки top() и peek()
    s.top() = 100;
    assert(s.peek() == 100);

    s.peek() = 200;
    assert(s.top() == 200);

    std::cout << "test_top_and_peek passed" << std::endl;
}

void test_clear() {
    Stack<int> s;
    s.push(1);
    s.push(2);

    s.clear();
    assert(s.is_empty() == true);
    assert(s.size() == 0);

    // Граничный случай: повторный clear()
    s.clear();
    assert(s.is_empty() == true);

    // Добавление элементов после очистки
    s.push(99);
    assert(s.size() == 1);
    assert(s.top() == 99);

    std::cout << "test_clear passed" << std::endl;
}

void test_copy_constructor() {
    Stack<int> s1;
    s1.push(10);
    s1.push(20);

    // Глубокое копирование
    Stack<int> s2(s1);
    assert(s2.size() == 2);
    assert(s2.top() == 20);

    // Независимость копии
    s2.pop();
    assert(s1.size() == 2);
    assert(s2.size() == 1);

    // Копирование пустого стека
    Stack<int> empty1;
    Stack<int> empty2(empty1);
    assert(empty2.is_empty() == true);

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    Stack<int> s1;
    s1.push(100);
    s1.push(200);

    Stack<int> s2;
    s2 = s1;
    assert(s2.size() == 2);
    assert(s2.top() == 200);

    // Самоприсваивание
    s2 = s2;
    assert(s2.size() == 2);
    assert(s2.top() == 200);

    // Присваивание пустого стека
    Stack<int> empty_stack;
    s2 = empty_stack;
    assert(s2.is_empty() == true);

    std::cout << "test_assignment_operator passed" << std::endl;
}

int main() {
    std::cout << "Running Stack tests" << std::endl;

    test_default_constructor();
    test_push();
    test_pop();
    test_top_and_peek();
    test_clear();
    test_copy_constructor();
    test_assignment_operator();

    std::cout << "All tests passed" << std::endl;
    return 0;
}