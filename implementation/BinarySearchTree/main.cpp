#include "BinarySearchTree.h"
#include <cassert>
#include <iostream>
#include <sstream>

void test_insert() {
    BinarySearchTree<int> bst;
    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);

    bst.insert(50);
    assert(!bst.is_empty());
    assert(bst.size() == 1);
    assert(bst.height() == 1);
    assert(bst.find(50));

    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(30);
    assert(bst.size() == 5);
    assert(bst.height() == 3);
    assert(bst.find(30));
    assert(bst.find(70));

    std::cout << "test_insert passed" << std::endl;
}

void test_remove() {
    BinarySearchTree<int> bst;
    bst.remove(10);

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    bst.remove(999);
    assert(bst.size() == 7);

    bst.remove(20);
    assert(!bst.find(20));
    assert(bst.size() == 6);

    bst.remove(30);
    assert(!bst.find(30));
    assert(bst.find(40));
    assert(bst.size() == 5);

    bst.remove(50);
    assert(!bst.find(50));
    assert(bst.find(60));
    assert(bst.find(70));
    assert(bst.size() == 4);

    std::cout << "test_remove passed" << std::endl;
}

void test_find() {
    BinarySearchTree<int> bst;
    assert(!bst.find(10));

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);

    assert(bst.find(10));
    assert(bst.find(5));
    assert(bst.find(15));
    assert(!bst.find(99));

    std::cout << "test_find passed" << std::endl;
}

void test_copy_and_assign() {
    BinarySearchTree<int> bst1;
    bst1.insert(50);
    bst1.insert(30);
    bst1.insert(70);

    BinarySearchTree<int> bst2(bst1);
    assert(bst2.size() == 3);
    assert(bst2.find(30));

    bst1.remove(30);
    assert(!bst1.find(30));
    assert(bst2.find(30));

    BinarySearchTree<int> bst3;
    bst3.insert(100);
    bst3 = bst2;
    assert(bst3.size() == 3);
    assert(!bst3.find(100));
    assert(bst3.find(70));

    bst3 = bst3;
    assert(bst3.size() == 3);
    assert(bst3.find(50));

    std::cout << "test_copy_and_assign passed" << std::endl;
}

void test_traversals_and_clear() {
    BinarySearchTree<int> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    bst.inorder();
    assert(buffer.str() == "30 50 70 \n");
    buffer.str("");

    bst.preorder();
    assert(buffer.str() == "50 30 70 \n");
    buffer.str("");

    bst.postorder();
    assert(buffer.str() == "30 70 50 \n");

    std::cout.rdbuf(old);

    bst.clear();
    assert(bst.is_empty());
    assert(bst.size() == 0);
    assert(bst.height() == 0);

    std::cout << "test_traversals_and_clear passed" << std::endl;
}

int main() {
    std::cout << "Running BinarySearchTree tests" << std::endl;
    test_insert();
    test_remove();
    test_find();
    test_copy_and_assign();
    test_traversals_and_clear();
    std::cout << "All tests passed" << std::endl;
    return 0;
}