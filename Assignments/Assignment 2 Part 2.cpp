#include <iostream>
#include "Assignment2P2.hpp"
using namespace std;

int main() {
	Assign2P2<int> a(10);
	a.push_back(37);
	a.push_back(19);
	a.push_back(4);

	a.traverse();
	cout << "size: " << a.size() << ", capacity: " << a.capacity();


	return 0;
}