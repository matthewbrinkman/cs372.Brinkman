//This code was made with the help of https://flowgpt.com/chat/pseudocode-conversion. The prompt used is the question from canvas.

#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};


static bool isLeaf(TreeNode* node) {
    return (node != nullptr) && (node->left == nullptr && node->right == nullptr);
}

static TreeNode* removeLeaves(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    root->left = removeLeaves(root->left);
    root->right = removeLeaves(root->right);

    if (isLeaf(root)) {
        delete root; 
        return nullptr;
    }
    return root;
}

static void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->value << " ";
    printTree(root->right);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original tree (In-Order): ";
    printTree(root);
    cout << endl;

    TreeNode* newTree = removeLeaves(root);

    cout << "New tree without leaves (In-Order): ";
    printTree(newTree);
    cout << endl;

    delete newTree; 

    return 0;
}