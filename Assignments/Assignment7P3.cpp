// This code was made using both claude.ai and https://flowgpt.com/chat/pseudocode-conversion. The prompt used was the question 
// from canvas while printing the two codes from part 1 and part 2 in order to get this code.

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <memory>
#include <ctime>
#include <iomanip>

using namespace std;
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

    bool search(int value) {
        TreeNode* current = root;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            if (value < current->data) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        return false;
    }
};


struct DataStruct {
    size_t size;
    vector<int>* numberVector;
    Tree* binarySearchTree;

    ~DataStruct() {
        delete numberVector;
        delete binarySearchTree;
    }
};


static DataStruct* createStructure(size_t numElements) {
    DataStruct* structure = new DataStruct;

    structure->size = numElements;
    structure->numberVector = new vector<int>;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);

    for (size_t i = 0; i < numElements; i++) {
        structure->numberVector->push_back(dis(gen));
    }

    sort(structure->numberVector->begin(), structure->numberVector->end());

    structure->binarySearchTree = new Tree();
    for (const int& num : *(structure->numberVector)) {
        structure->binarySearchTree->insert(num);
    }

    return structure;
}

static void deleteStructure(DataStruct* structure) {
    if (structure != nullptr) {
        delete structure;
    }
}

template <typename T>
bool binarySearch(const vector<T>& aSortedVector, T itemToBeFound) {
    int left = 0;
    int right = aSortedVector.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (aSortedVector[mid] == itemToBeFound) {
            return true;
        }

        if (aSortedVector[mid] < itemToBeFound) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    const vector<size_t> sizes = { 1000, 2500, 5000, 10000, 50000 };
    const int searchCount = 100;

    cout << "Performance Comparison: Binary Search vs BST Search" << endl;
    cout << "------------------------------------------------" << endl;
    cout << fixed << setprecision(2);

    for (size_t size : sizes) {
        DataStruct* structure = createStructure(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 10000);

       
        auto startArray = chrono::high_resolution_clock::now();
        for (int i = 0; i < searchCount; ++i) {
            int numberToFind = dis(gen);
            binarySearch(*(structure->numberVector), numberToFind);
        }
        auto endArray = chrono::high_resolution_clock::now();
        auto durationArray = chrono::duration_cast<chrono::microseconds>(endArray - startArray);

      
        auto startTree = chrono::high_resolution_clock::now();
        for (int i = 0; i < searchCount; ++i) {
            int numberToFind = dis(gen);
            structure->binarySearchTree->search(numberToFind);
        }
        auto endTree = chrono::high_resolution_clock::now();
        auto durationTree = chrono::duration_cast<chrono::microseconds>(endTree - startTree);

       
        double avgArrayTime = static_cast<double>(durationArray.count()) / searchCount;
        double avgTreeTime = static_cast<double>(durationTree.count()) / searchCount;

     
        cout << "\nResults for size " << size << ":" << endl;
        cout << "Binary Search average time: " << avgArrayTime << " microseconds" << endl;
        cout << "BST Search average time: " << avgTreeTime << " microseconds" << endl;

        deleteStructure(structure);
    }

    return 0;
}