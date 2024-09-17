// This was created with the help of https://flowgpt.com/chat/pseudocode-conversion and the prompt I used was just copying the 
// question from canvas and pasting it here.

#pragma once

#include <iostream>
#include <list>
using namespace std;

template <typename T>
T hotPotato(int N, int M) {
    
    list<T> players;
    for (T i = 1; i <= N; ++i) 
    {
        players.push_back(i);
    }
    auto it = players.begin();
    while (players.size() > 1) 
    {
        for (int count = 0; count < M; ++count) 
        {
            if (it == players.end()) 
            {
                it = players.begin();
            }
            ++it;
        }
        if (it == players.end())
        {
            it = players.begin();
        }
        it = players.erase(it);
        if (it == players.end()) 
        {
            it = players.begin();
        }
    }

    return players.front();
}


