#include <iostream>
#include <algorithm>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void mirrorTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    std::swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void test_mirrorTree() {
    // Пустое дерево 
    mirrorTree(nullptr);

    // Один узел
    TreeNode* single = new TreeNode(1);
    mirrorTree(single);
    assert(single->data == 1 && single->left == nullptr && single->right == nullptr);
    deleteTree(single);

    // Обычный случай
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    mirrorTree(root);

    assert(root->data == 1);
    assert(root->right != nullptr && root->right->data == 2);
    assert(root->left != nullptr && root->left->data == 3);
    assert(root->right->right != nullptr && root->right->right->data == 4);
    assert(root->right->left == nullptr);

    deleteTree(root);
    std::cout << "mirrorTree passed" << std::endl;
}

int main() {
    test_mirrorTree();
    return 0;
}