
// I used https://you.com as a reference guide in creating the first two function for parts 1 and 2.
// The prompts I entered were the entire number 1 and 2 statements into the search bar. 
// I used a variety of other reference webites to help me with the third part.




#include <iostream>
#include <string>
using namespace std;

static void Array(int size)
{
    int* pointer1 = new int[size];
    for (int i = 0; i < size; ++i)
    {
        pointer1[i] = i;
    }
    int* sPtr = pointer1;
    delete[] pointer1;
    cout << "First ten integers pointed to the second pointer: ";
    for (int i = 0; i <= 10; ++i)
    {
        //cout << sPtr[i]; //This is an undefined behavior.
    }
    cout << endl;
}
static void twoPtr(int size)
{
    int* ptr = new int[size];
    for (int i = 0; i < size; ++i)
    {
        ptr[i] = i + 100;
    }
    int* p1 = ptr;
    int* p2 = ptr;
    delete[] p1;
    cout << "Address of second pointer: " << p2 << endl;

}

static string* newString()
{
    string* strPtr = new string("abcdefghijkl");
    return strPtr;
}

static void printString()
{
    string* strPtr = newString();
    string string = *strPtr;
    cout << "The string is: " << string << endl;
    delete strPtr;
}


int main()
{
    int size = 1000;
    Array(size);
    twoPtr(size);
    printString();
    return 0;
}
