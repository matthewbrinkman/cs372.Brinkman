
// This code was created using claude.ai. The prompt used was the question from canvas.

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include <ctime>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Tree {
private:
    TreeNode* root;

    void insertHelper(TreeNode*& node, int value) {
        if (node == nullptr) {
            node = new TreeNode(value);
            return;
        }

        if (value < node->data) {
            insertHelper(node->left, value);
        }
        else {
            insertHelper(node->right, value);
        }
    }

    void destroyTree(TreeNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        destroyTree(root);
    }

    void insert(int value) {
        insertHelper(root, value);
    }
};

struct DataStruct {
    size_t size;
    std::vector<int>* numberVector;
    Tree* binarySearchTree;

    ~DataStruct() {
        delete numberVector;
        delete binarySearchTree;
    }
};

DataStruct* createStructure(size_t numElements) {
    DataStruct* structure = new DataStruct;

    structure->size = numElements;

    structure->numberVector = new std::vector<int>;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);

    for (size_t i = 0; i < numElements; i++) {
        structure->numberVector->push_back(dis(gen));
    }

    std::sort(structure->numberVector->begin(), structure->numberVector->end());

    structure->binarySearchTree = new Tree();
    for (const int& num : *(structure->numberVector)) {
        structure->binarySearchTree->insert(num);
    }

    return structure;
}

void deleteStructure(DataStruct* structure) {
    if (structure != nullptr) {
        delete structure;
    }
}

int main() {
    
    DataStruct* myStructure = createStructure(1000);

   
    deleteStructure(myStructure);

    return 0;
}
