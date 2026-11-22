#include <iostream>
#include <algorithm>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int treeHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void test_treeHeight() {
    // Пустое дерево
    assert(treeHeight(nullptr) == 0);

    // Один узел
    TreeNode* single = new TreeNode(5);
    assert(treeHeight(single) == 1);
    deleteTree(single);

    // Обычное дерево
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    assert(treeHeight(root) == 3);
    deleteTree(root);

    
    TreeNode* skew = new TreeNode(1);
    skew->right = new TreeNode(2);
    skew->right->right = new TreeNode(3);
    assert(treeHeight(skew) == 3);
    deleteTree(skew);

    std::cout << "treeHeight passed" << std::endl;
}

int main() {
    test_treeHeight();
    return 0;
}