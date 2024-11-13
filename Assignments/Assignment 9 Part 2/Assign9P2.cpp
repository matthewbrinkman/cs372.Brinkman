// This was created with claude.ai. The prompt used was the question in canvas along with the hash.cpp file from the first assignment.
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include "ExtendedHash.hpp"

static void testProbingMethod(HashTable<int, std::string>::ProbeType probeType) {
    std::string probeName;
    switch (probeType) {
    case HashTable<int, std::string>::ProbeType::LINEAR:
        probeName = "Linear Probing";
        break;
    case HashTable<int, std::string>::ProbeType::QUADRATIC:
        probeName = "Quadratic Probing";
        break;
    case HashTable<int, std::string>::ProbeType::DOUBLE_HASH:
        probeName = "Double Hashing";
        break;
    }

    std::cout << "\nTesting " << probeName << "..." << std::endl;

 
    HashTable<int, std::string> ht(5);

    try {
        for (int i = 0; i < 4; i++) {
            ht.insert(i * 5, "value" + std::to_string(i), probeType); 
        }

     
        std::string value;
        for (int i = 0; i < 4; i++) {
            assert(ht.get(i * 5, value, probeType));
            assert(value == "value" + std::to_string(i));
        }

        assert(ht.remove(5, probeType));
        ht.insert(20, "new_value", probeType);
        assert(ht.get(20, value, probeType));
        assert(value == "new_value");

        std::cout << probeName << " tests passed!" << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << probeName << " caused an error: " << e.what() << std::endl;
    }
}

static void testCollisionPatterns(HashTable<int, std::string>::ProbeType probeType) {
    std::string probeName;
    switch (probeType) {
    case HashTable<int, std::string>::ProbeType::LINEAR:
        probeName = "Linear Probing";
        break;
    case HashTable<int, std::string>::ProbeType::QUADRATIC:
        probeName = "Quadratic Probing";
        break;
    case HashTable<int, std::string>::ProbeType::DOUBLE_HASH:
        probeName = "Double Hashing";
        break;
    }

    std::cout << "\nTesting " << probeName << " Collision Patterns..." << std::endl;

    HashTable<int, std::string> ht(7);  

    
    std::vector<int> keys = { 7, 14, 21, 28, 35 }; 

    try {
        for (size_t i = 0; i < keys.size(); i++) {
            ht.insert(keys[i], "value" + std::to_string(keys[i]), probeType);
        }

     
        std::string value;
        for (int key : keys) {
            assert(ht.get(key, value, probeType));
            assert(value == "value" + std::to_string(key));
        }

        std::cout << probeName << " collision pattern tests passed!" << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cout << probeName << " collision pattern test caused an error: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Starting HashTable Probing Tests..." << std::endl;

    testProbingMethod(HashTable<int, std::string>::ProbeType::LINEAR);
    testProbingMethod(HashTable<int, std::string>::ProbeType::QUADRATIC);
    testProbingMethod(HashTable<int, std::string>::ProbeType::DOUBLE_HASH);

    testCollisionPatterns(HashTable<int, std::string>::ProbeType::LINEAR);
    testCollisionPatterns(HashTable<int, std::string>::ProbeType::QUADRATIC);
    testCollisionPatterns(HashTable<int, std::string>::ProbeType::DOUBLE_HASH);

    std::cout << "\nAll probing tests completed!" << std::endl;
    return 0;
}