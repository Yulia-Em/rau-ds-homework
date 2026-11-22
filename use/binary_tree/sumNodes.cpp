#include <iostream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int sumNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void test_sumNodes() {
    // Пустое дерево
    assert(sumNodes(nullptr) == 0);

    // Отрицательные и нулевые значения
    TreeNode* neg = new TreeNode(-5);
    neg->left = new TreeNode(5);
    neg->right = new TreeNode(0);
    assert(sumNodes(neg) == 0);
    deleteTree(neg);

    // Обычный случай
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    assert(sumNodes(root) == 10);
    deleteTree(root);

    std::cout << "sumNodes passed" << std::endl;
}

int main() {
    test_sumNodes();
    return 0;
}