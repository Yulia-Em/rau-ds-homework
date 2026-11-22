#include <iostream>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findMax(TreeNode* root) {
    if (root == nullptr) {
        return INT_MIN;
    }
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    return std::max({ root->data, leftMax, rightMax });
}

int findMin(TreeNode* root) {
    if (root == nullptr) {
        return INT_MAX;
    }
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    return std::min({ root->data, leftMin, rightMin });
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void test_findMinMax() {
    // Один элемент
    TreeNode* single = new TreeNode(7);
    assert(findMax(single) == 7);
    assert(findMin(single) == 7);
    deleteTree(single);

    // Отрицательные числа
    TreeNode* neg = new TreeNode(-10);
    neg->left = new TreeNode(-25);
    neg->right = new TreeNode(-3);
    assert(findMax(neg) == -3);
    assert(findMin(neg) == -25);
    deleteTree(neg);

    // Обычный случай
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(1);
    assert(findMax(root) == 8);
    assert(findMin(root) == 1);
    deleteTree(root);

    std::cout << "findMinMax passed" << std::endl;
}

int main() {
    test_findMinMax();
    return 0;
}