#include <iostream>
#include "Assign3P3.hpp"
using namespace std;

int main() {
    CircularList circularList;
    circularList.ap(1);
    circularList.ap(2);
    circularList.ap(3);

    vector<int> result = circularList.circle(0);
    for (int item : result) {
        cout << item << std::endl; 
    }

    return 0;
}