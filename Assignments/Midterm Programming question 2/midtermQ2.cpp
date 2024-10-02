
#include <iostream>
#include <list>
#include "midterm2.hpp"
using namespace std;

int main()
{
    List<int> midterm2 (5);
    midterm2.push_front(7);
    midterm2.push_back(8);
    midterm2.front();
    midterm2.back();
    midterm2.printTheList();
    midterm2.pop_back();
    midterm2.pop_front();
    midterm2.printTheList();
}
