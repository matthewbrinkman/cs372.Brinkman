// This was created with the guidence of a Athens State Tutor.
#pragma once
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Assign2P2
{
private:
	T* arr = nullptr;
	int vCapacity = 1;
	int length = 0;
public:
	Assign2P2(size_t size) {
		arr = new T[size];
		vCapacity = size;
		length = 0;
	}
	~Assign2P2() {
		delete[] arr;
		arr = nullptr;
	}

	void push_back(T data) {
		if (length == vCapacity) {
			cout << "Error" << endl;
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

