// This was created with the help of https://flowgpt.com/chat/pseudocode-conversion 
// The prompt that was used was the full question from Assignment 3 Part 3 in Canvas.


#pragma once

#include <iostream>
#include <vector>
using namespace std;

class List {
private:
    vector<int> items;

public:
    void a(int item) {
        items.push_back(item);
    }

    int size() const {
        return items.size();
    }

    int get(int index) const {
        return items[index];
    }
};

class CircularList : List {
private:
    int head;
    int tail;

public:
    CircularList() : head(-1), tail(-1) {}

    void ap(int item) {
        List::a(item);
        if (size() == 1) {
            head = 0;
            tail = 0;
        }
        else {
            tail = (tail + 1) % size();
        }
    }

    vector<int> circle(int start) const {
        vector<int> result;
        if (size() == 0) return result;

        int startIndex = start % size();
        int currentIndex = startIndex;

        for (int i = 0; i < size(); i++) {
            result.push_back(get(currentIndex));
            currentIndex = (currentIndex + 1) % size();
        }

        return result;
    }
};