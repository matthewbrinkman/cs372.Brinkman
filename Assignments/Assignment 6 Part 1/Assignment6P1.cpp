#include <cassert>
# include <iostream>
#include "Assign6p1.hpp"
using namespace std;

static void runTests() {
    List<int> list;

    assert(list.empty());
    assert(list.get_size() == 0);

    list.push_back(1);
    assert(!list.empty());
    assert(list.get_size() == 1);
    assert(list.front() == 1);

    list.push_back(2);
    assert(list.get_size() == 2);
    assert(list.front() == 1);

    list.pop_front();
    assert(list.get_size() == 1);
    assert(list.front() == 2);

    list.pop_front();
    assert(list.empty());

    try {
        list.front();
        assert(false); 
    }
    catch (const out_of_range& e) { }

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.clear();
    assert(list.empty());

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    int sum = 0;
    for (const auto& value : list) {
        sum += value;
    }
    assert(sum == 6);

    cout << "All tests passed!" << endl;
}

int main() {
    runTests();
    return 0;
}