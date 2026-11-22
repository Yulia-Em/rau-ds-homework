#include <iostream>
#include <sstream>
#include <cassert>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preorder(TreeNode* root, std::ostream& out = std::cout) {
    if (root == nullptr) return;
    out << root->data << " ";
    preorder(root->left, out);
    preorder(root->right, out);
}

void inorder(TreeNode* root, std::ostream& out = std::cout) {
    if (root == nullptr) return;
    inorder(root->left, out);
    out << root->data << " ";
    inorder(root->right, out);
}

void postorder(TreeNode* root, std::ostream& out = std::cout) {
    if (root == nullptr) return;
    postorder(root->left, out);
    postorder(root->right, out);
    out << root->data << " ";
}

void deleteTree(TreeNode* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void test_traversals() {
    // Пустое дерево
    std::stringstream ss_empty;
    preorder(nullptr, ss_empty);
    inorder(nullptr, ss_empty);
    postorder(nullptr, ss_empty);
    assert(ss_empty.str().empty());

    // Обычное дерево
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::stringstream ss_pre, ss_in, ss_post;
    preorder(root, ss_pre);
    inorder(root, ss_in);
    postorder(root, ss_post);

    assert(ss_pre.str() == "1 2 3 ");
    assert(ss_in.str() == "2 1 3 ");
    assert(ss_post.str() == "2 3 1 ");

    deleteTree(root);
    std::cout << "traversals passed" << std::endl;
}

int main() {
    test_traversals();
    return 0;
}