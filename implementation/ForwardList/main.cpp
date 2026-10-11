#include "ForwardList.h"
#include <cassert>
#include <iostream>

void test_default_constructor() {
    ForwardList<int> list;
    assert(list.empty());
    assert(list.size() == 0);
    assert(list.begin() == nullptr);

    std::cout << "test_default_constructor passed" << std::endl;
}

void test_push_front() {
    ForwardList<int> list;

    // Нормальный случай
    list.push_front(1);
    assert(list.size() == 1);
    assert(list.front() == 1);

    list.push_front(2);
    list.push_front(3);
    assert(list.size() == 3);
    assert(list.front() == 3);

    std::cout << "test_push_front passed" << std::endl;
}

void test_pop_front() {
    ForwardList<int> list;
    list.push_front(10);
    list.push_front(20);

    // Нормальный случай
    list.pop_front();
    assert(list.size() == 1);
    assert(list.front() == 10);

    // Граничный случай: удаление последнего элемента
    list.pop_front();
    assert(list.empty());

    // Граничный случай: pop_front на пустом списке
    list.pop_front();
    assert(list.empty());

    std::cout << "test_pop_front passed" << std::endl;
}

void test_front() {
    ForwardList<int> list;
    list.push_front(42);

    // Нормальный случай
    assert(list.front() == 42);

    // Изменение через front()
    list.front() = 99;
    assert(list.front() == 99);

    std::cout << "test_front passed" << std::endl;
}

void test_insert_after() {
    ForwardList<int> list;
    list.push_front(10);

    // Нормальный случай
    auto node = list.begin();
    list.insert_after(node, 20);
    assert(list.size() == 2);

    auto second = list.begin()->next;
    assert(second->data == 20);

    // Граничный случай: передачи nullptr
    list.insert_after(nullptr, 99);
    assert(list.size() == 2);

    std::cout << "test_insert_after passed" << std::endl;
}

void test_erase_after() {
    ForwardList<int> list;
    list.push_front(30);
    list.push_front(20);
    list.push_front(10);

    // Нормальный случай
    auto head = list.begin();
    list.erase_after(head);
    assert(list.size() == 2);
    assert(head->next->data == 30);

    // Граничный случай: узел без следующего элемента
    list.erase_after(head->next);
    assert(list.size() == 2);

    // Граничный случай: передача nullptr
    list.erase_after(nullptr);
    assert(list.size() == 2);

    std::cout << "test_erase_after passed" << std::endl;
}

void test_clear() {
    ForwardList<int> list;
    list.push_front(1);
    list.push_front(2);

    // Нормальный случай
    list.clear();
    assert(list.empty());
    assert(list.size() == 0);
    assert(list.begin() == nullptr);

    // Граничный случай: повторный clear
    list.clear();
    assert(list.empty());

    std::cout << "test_clear passed" << std::endl;
}

void test_reverse() {
    // Граничный случай: пустой список
    ForwardList<int> empty_list;
    empty_list.reverse();
    assert(empty_list.empty());

    // Граничный случай: 1 элемент
    ForwardList<int> single;
    single.push_front(5);
    single.reverse();
    assert(single.front() == 5);

    // Нормальный случай
    ForwardList<int> list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    list.reverse();

    assert(list.front() == 3);
    list.pop_front();
    assert(list.front() == 2);
    list.pop_front();
    assert(list.front() == 1);

    std::cout << "test_reverse passed" << std::endl;
}

void test_copy_constructor() {
    ForwardList<int> list1;
    list1.push_front(20);
    list1.push_front(10);

    // Нормальный случай
    ForwardList<int> list2(list1);
    assert(list2.size() == 2);
    assert(list2.front() == 10);

    list2.pop_front();
    assert(list1.size() == 2);
    assert(list2.size() == 1);

    // Граничный случай: копирование пустого списка
    ForwardList<int> empty1;
    ForwardList<int> empty2(empty1);
    assert(empty2.empty());

    std::cout << "test_copy_constructor passed" << std::endl;
}

void test_assignment_operator() {
    ForwardList<int> list1;
    list1.push_front(200);
    list1.push_front(100);

    // Нормальный случай
    ForwardList<int> list2;
    list2 = list1;
    assert(list2.size() == 2);
    assert(list2.front() == 100);

    // Граничный случай: самоприсваивание
    list2 = list2;
    assert(list2.size() == 2);

    // Граничный случай: присваивание пустого списка
    ForwardList<int> empty_list;
    list2 = empty_list;
    assert(list2.empty());

    std::cout << "test_assignment_operator passed" << std::endl;
}

int main() {
    std::cout << "Running ForwardList tests" << std::endl;

    test_default_constructor();
    test_push_front();
    test_pop_front();
    test_front();
    test_insert_after();
    test_erase_after();
    test_clear();
    test_reverse();
    test_copy_constructor();
    test_assignment_operator();

    std::cout << "All tests passed" << std::endl;
    return 0;
}