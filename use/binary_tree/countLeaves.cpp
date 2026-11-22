#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countLeaves(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeaves(root->left) + countLeaves(root->right);
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void test_countLeaves() {
    // Пустое дерево
    assert(countLeaves(nullptr) == 0);

    // Один узел 
    TreeNode* single = new TreeNode(1);
    assert(countLeaves(single) == 1);
    deleteTree(single);

    // Обычное дерево
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    assert(countLeaves(root) == 3);
    deleteTree(root);

    std::cout << "countLeaves passed" << std::endl;
}

int main() {
    test_countLeaves();
    return 0;
}