#include <iostream>
#include "Assignment4P1.hpp"
using namespace std;

int main() {
    int N, M;
    cout << "Enter the number of players (N): ";
    cin >> N;
    cout << "Enter the number of passes (M): ";
    cin >> M;

    int winner = hotPotato<int>(N, M);
    cout << "The winner is player: " << winner << std::endl;

    return 0;
}