#include <iostream>
#include "MyVector.hpp"

int main() {
	MyVector<int> a;
	a.push_back(37);
	a.push_back(19);
	a.push_back(4);

	a.traverse();
	std::cout << "size: " << a.size() << ", capacity: " << a.capacity();


	return 0;
}