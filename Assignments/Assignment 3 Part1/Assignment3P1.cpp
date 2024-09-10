#include <iostream>
#include <list>
#include "Header.hpp"
using namespace std;

int main()
{
	List<int> Assign3P1 (5);
    Assign3P1.push_front(7);
    Assign3P1.push_back(8);
    Assign3P1.front();
    Assign3P1.back();
    Assign3P1.printTheList();
    Assign3P1.pop_back();
    Assign3P1.pop_front();
    Assign3P1.printTheList();
}