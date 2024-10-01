// This was created with the help of https://flowgpt.com/chat/pseudocode-conversion. The prompt used was 
// " Using either the STL stack class or your own Stack class, write a small program that, given a string 
// input by the user from the keyboard, will tell the user whether or not the string contains a matching 
// number of parentheses."


#include <iostream>
#include <stack>
#include <string>
using namespace std;

static bool BalPar(const string& input)
{
    stack<char> stack;

    for (char c : input)
    {
        if (c == '(') {
            stack.push(c);
        }
        else if (c == ')') 
        {
            if (stack.empty())
                return false;
            stack.pop();
        }
    }

    return stack.empty();
}

int main()
{
    string userInput;
    cout << "Input a sentence with parentheses: ";
    getline(cin, userInput);

    if (BalPar(userInput)) 
    {
        cout << "The parentheses are balanced." << endl;
    }
    else 
    {
        cout << "The parentheses are not balanced." << endl;
    }

    return 0;
}