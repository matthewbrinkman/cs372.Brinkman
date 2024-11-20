//This code was made with claude.ai and the question was used as the prompt
#pragma once
#include <list>
#include <memory>
#include <iostream>
#include <string>


template<typename T>
void partition(const T& splitter, const std::list<T>& input,
    std::list<T>* less, std::list<T>* greater) {
    less->clear();
    greater->clear();

    for (const T& value : input) {
        if (value < splitter) {
            less->push_back(value);
        }
        else if (value > splitter) {
            greater->push_back(value);
        }
    }
}

template<typename T>
std::list<T>* quicksort(const std::list<T>& input) {
  
    if (input.size() <= 1) {
        return new std::list<T>(input);
    }

    T splitter = input.front();

    std::list<T> less, greater;

    partition(splitter, input, &less, &greater);

    std::list<T>* sortedLess = quicksort(less);
    std::list<T>* sortedGreater = quicksort(greater);

    std::list<T>* result = new std::list<T>();

    result->splice(result->end(), *sortedLess);

    result->push_back(splitter);

    result->splice(result->end(), *sortedGreater);

    delete sortedLess;
    delete sortedGreater;

    return result;
}


template<typename T>
void printList(const std::list<T>& lst, const std::string& message = "") {
    if (!message.empty()) {
        std::cout << message << ": ";
    }
    for (const T& value : lst) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}