// This is for Assignment 2 Part 1

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
		for (int i = 0; i < vCapacity; i++) {
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
		if (index < 0 || index > length)
		{
			cerr << "Vector: index out of bounds on access" << endl;
		}
		else
		{
			return arr[index];
		}
	}
	int size()
	{
		return length;
	}
	int capacity()
	{
		return vCapacity;

	}
};

// Include help from tutors from Athens State 

