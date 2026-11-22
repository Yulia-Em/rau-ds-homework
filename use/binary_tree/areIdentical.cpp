#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool areIdentical(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == nullptr && tree2 == nullptr) {
        return true;
    }
    if (tree1 == nullptr || tree2 == nullptr) {
        return false;
    }
    return (tree1->data == tree2->data) &&
        areIdentical(tree1->left, tree2->left) &&
        areIdentical(tree1->right, tree2->right);
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void test_areIdentical() {
    // Два пустых дерева
    assert(areIdentical(nullptr, nullptr) == true);

    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    // Одно пустое, второе нет
    assert(areIdentical(tree1, nullptr) == false);

    // Идентичные деревья
    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    assert(areIdentical(tree1, tree2) == true);

    // Разные значения
    tree2->right->data = 99;
    assert(areIdentical(tree1, tree2) == false);

    // Разная структура
    tree2->right->data = 3;
    tree2->left->left = new TreeNode(4);
    assert(areIdentical(tree1, tree2) == false);

    deleteTree(tree1);
    deleteTree(tree2);

    std::cout << "areIdentical passed" << std::endl;
}

int main() {
    test_areIdentical();
    return 0;
}