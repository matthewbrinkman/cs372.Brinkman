// This was created with claude.ai and the prompt was the question itself.

#include <vector>
#include <iostream>
using namespace std;

template <typename T>
bool binarySearch(vector<T> aSortedVector, T itemToBeFound, bool printDebugData = false) {
private:
    bool searchHelper(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        
        if (node->data == value) {
            return true;
        }
        
        if (value < node->data) {
            return searchHelper(node->left, value);
        }
        return searchHelper(node->right, value);
    }
    
public:
    bool search(int value) {
        return searchHelper(root, value);
    }
    
    int left = 0;
    int right = aSortedVector.size() - 1;
    int itemsExamined = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        itemsExamined++;

        if (aSortedVector[mid] == itemToBeFound) {
            if (printDebugData) {
                cout << "Items examined: " << itemsExamined << endl;
            }
            return true;
        }

        if (aSortedVector[mid] < itemToBeFound) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    if (printDebugData) {
        cout << "Items examined: " << itemsExamined << endl;
    }
    return false;
}
