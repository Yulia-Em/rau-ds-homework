#include <iostream>
#include <queue>
#include <sstream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void levelOrder(TreeNode* root, std::ostream& out = std::cout) {
    if (root == nullptr) return;

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        out << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void test_levelOrder() {
    // Пустое дерево
    std::stringstream ss_empty;
    levelOrder(nullptr, ss_empty);
    assert(ss_empty.str().empty());

    // Один узел
    TreeNode* single = new TreeNode(42);
    std::stringstream ss_single;
    levelOrder(single, ss_single);
    assert(ss_single.str() == "42 ");
    deleteTree(single);

    // Обычное дерево
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::stringstream ss;
    levelOrder(root, ss);
    assert(ss.str() == "1 2 3 4 5 ");
    deleteTree(root);

    std::cout << "levelOrder passed" << std::endl;
}

int main() {
    test_levelOrder();
    return 0;
}