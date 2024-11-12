
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "Hash.hpp"
using namespace std;

static void testBasicOperations() {
    cout << "\nTesting Basic Operations..." << endl;

    HashTable<int, string> ht(5);

    ht.insert(1, "one");
    ht.insert(2, "two");
    ht.insert(3, "three");

    string value;
    assert(ht.get(1, value) && value == "one");
    assert(ht.get(2, value) && value == "two");
    assert(ht.get(3, value) && value == "three");
    assert(!ht.get(4, value));

    cout << "Basic operations passed!" << endl;
}

static void testCollisions() {
    cout << "\nTesting Collision Handling..." << endl;

    HashTable<int, string> ht(3);

    ht.insert(0, "zero");
    ht.insert(3, "three");  
    ht.insert(6, "six");   

    std::string value;
    assert(ht.get(0, value) && value == "zero");
    assert(ht.get(3, value) && value == "three");
    assert(ht.get(6, value) && value == "six");

    ht.insert(3, "new_three");
    assert(ht.get(3, value) && value == "new_three");

    cout << "Collision handling passed!" << endl;
}

static void testRemoval() {
    cout << "\nTesting Removal..." << endl;

    HashTable<int, string> ht(5);

    ht.insert(1, "one");
    ht.insert(2, "two");
    ht.insert(3, "three");

    assert(ht.remove(2));
    assert(!ht.remove(4)); 

    std::string value;
    assert(!ht.get(2, value)); 
    assert(ht.get(1, value) && value == "one");  
    assert(ht.get(3, value) && value == "three");

    ht.insert(4, "four"); 
    assert(ht.get(4, value) && value == "four");

    cout << "Removal operations passed!" << endl;
}

static void testResizing() {
    cout << "\nTesting Automatic Resizing..." << endl;

    HashTable<int, string> ht(3);  

    int initialCapacity = ht.getCapacity();

    for (int i = 0; i < 10; i++) {
        ht.insert(i, "value" + to_string(i));
    }

    assert(ht.getCapacity() > initialCapacity);

    string value;
    for (int i = 0; i < 10; i++) {
        assert(ht.get(i, value) && value == "value" + to_string(i));
    }

    cout << "Resizing operations passed!" << endl;
}

static void testFullTable() {
    cout << "\nTesting Full Table Behavior..." << endl;

    HashTable<int, string> ht(3);

    try {
        for (int i = 0; i < 100; i++) {
            ht.insert(i, "value");
        }
        cout << "Table handled overflow through resizing" << endl;
    }
    catch (const runtime_error& e) {
        cout << "Expected exception caught: " << e.what() << endl;
    }
}

int main() {
    cout << "Starting HashTable Tests..." << endl;

    testBasicOperations();
    testCollisions();
    testRemoval();
    testResizing();
    testFullTable();

    cout << "\nAll tests completed successfully!" << endl;
    return 0;
}