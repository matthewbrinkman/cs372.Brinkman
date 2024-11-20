//This code was made with claude.ai and the question was used as the prompt
#include "FinalExamQ2.hpp"
#include <iostream>
#include <list>


int main() {
    
    std::list<int> numbers = { 64, 34, 25, 12, 22, 11, 90 };
    std::cout << "Sorting integers:" << std::endl;
    printList(numbers, "Original list");
    std::list<int>* sortedNumbers = quicksort(numbers);
    printList(*sortedNumbers, "Sorted list");
    delete sortedNumbers;
}