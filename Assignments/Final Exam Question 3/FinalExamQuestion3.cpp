// This was created with claude.ai and the prompt was to create a main function to run examples for the revised code.
#include "FinalExamQ3.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Record {
    int key;
    std::string name;
    double value;
};

static void printRecord(const Record& rec) {
    cout << "Key: " << setw(5) << rec.key << " | Name: " << setw(15) << rec.name
        << " | Value: " << fixed << std::setprecision(2) << rec.value << endl;
}

static void printStatus(const string& operation, bool success, int key) {
    cout << operation << " key " << key << ": "<< (success ? "Successful" : "Failed") << endl;
}

int main() {
    Table<Record> hashTable;

    cout << "Demonstrating Hash Table with Quadratic Probing\n";
    cout << "=============================================\n\n";

    Record records[] = {
        {42, "Alice", 95.5},
        {853, "Bob", 88.3},
        {123, "Charlie", 91.7},
        {456, "David", 76.9},
        {789, "Eve", 98.2},
        {1642, "Frank", 85.4},  
        {2453, "Grace", 92.1}   
    };

    cout << "Inserting Records:\n";
    cout << "-----------------\n";
    for (const auto& record : records) {
        try {
            hashTable.insert(record);
            cout << "Inserted: ";
            printRecord(record);
        }
        catch (const runtime_error& e) {
            cout << "Failed to insert key " << record.key << ": " << e.what() << endl;
        }
    }
    cout << "\nCurrent table size: " << hashTable.size() << endl;

    cout << "\nSearching for Records:\n";
    cout << "--------------------\n";
    int searchKeys[] = { 42, 853, 999 }; 
    for (int key : searchKeys) {
        bool found;
        Record result;
        hashTable.find(key, found, result);
        if (found) {
            cout << "Found: ";
            printRecord(result);
        }
        else {
            cout << "Key " << key << " not found\n";
        }
    }

    std::cout << "\nRemoving Records:\n";
    std::cout << "----------------\n";
    int removeKeys[] = { 123, 456, 999 }; 
    for (int key : removeKeys) {
        bool wasPresent = hashTable.isPresent(key);
        hashTable.remove(key);
        printStatus("Removing", wasPresent, key);
    }
    cout << "\nCurrent table size: " << hashTable.size() << endl;

    cout << "\nInserting New Record in Freed Slot:\n";
    cout << "--------------------------------\n";
    Record newRecord = { 321, "Zack", 88.9 };
    try {
        hashTable.insert(newRecord);
        cout << "Inserted: ";
        printRecord(newRecord);
    }
    catch (const std::runtime_error& e) {
        cout << "Failed to insert: " << e.what() << endl;
    }

    cout << "\nFinal table size: " << hashTable.size() << endl;

    return 0;
}