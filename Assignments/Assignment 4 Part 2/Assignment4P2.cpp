#include <iostream>
#include "Assignment4P2.hpp"
using namespace std;



int main() {
    MyVector<int> vec;
    vec.push_back(10);
    vec.push_back(25);
    vec.push_back(30);

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
