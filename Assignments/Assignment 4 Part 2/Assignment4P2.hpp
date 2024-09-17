// This was created with the help the help of https://flowgpt.com/pseudocode-conversion and the prompt that was used was 
// " In c++ add iterators in my code" then I placed my vector class in the search bar.

#pragma once
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class MyVector
{
private:
    T* arr = new T[1];
    int vCapacity = 1;
    int length = 0;

    void expand(int newCapacity) {
        T* newArr = new T[newCapacity];
        for (int i = 0; i < vCapacity; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        vCapacity = newCapacity;
    }

public:
    MyVector() {};
    MyVector(T item) {
        length = 1;
        arr[0] = item;
    }
    ~MyVector() {
        delete[] arr;
        arr = nullptr;
    }

    void push_back(T data) {
        if (length == vCapacity) {
            expand(2 * vCapacity);
        }
        arr[length] = data;
        length++;
    }

    void put(T data, int pos) {
        assert(pos <= length && pos >= 0);
        if (pos == length) {
            push_back(data);
        }
        else {
            arr[pos] = data;
        }
    }

    void traverse() {
        for (int i = 0; i < length; i++) {
            cout << arr[i] << endl;
        }
        cout << endl;
    }

    T& at(int index)
    {
        if (index < 0 || index >= length) 
        {
            cerr << "Vector: index out of bounds on access" << endl;
            exit(EXIT_FAILURE); 
        }
        return arr[index];
    }

    int size() const {
        return length;
    }

    int capacity() const {
        return vCapacity;
    }

    
    class Iterator {
    private:
        MyVector<T>* vector; 
        int index;           

    public:
        Iterator(MyVector<T>* vec, int idx) : vector(vec), index(idx) {}

        T& operator*() {
            return vector->at(index);
        }

        Iterator& operator++() {
            ++index;
            return *this; 
        }

        
        Iterator operator++(int) {
            Iterator temp = *this; 
            ++index;
            return temp; 
        }

        bool operator!=(const Iterator& other) const {
            return index != other.index;
        }

        bool operator==(const Iterator& other) const {
            return index == other.index; 
        }
    };

    
    Iterator begin() {
        return Iterator(this, 0); 
    }

    Iterator end() {
        return Iterator(this, length); 
    }
};
