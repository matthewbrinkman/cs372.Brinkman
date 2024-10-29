// This was created with the help of claude.ai

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;

class Person {
public:
    string name;
    vector<Person*> friends;

    Person(const string& n) : name(n) {}

    void addFriend(Person* friend_ptr) 
    {
        friends.push_back(friend_ptr);
        bool already_friends = false;
        for (Person* p : friend_ptr->friends)
        {
            if (p->name == this->name) 
            {
                already_friends = true;
                break;
            }
        }
        if (!already_friends) 
        {
            friend_ptr->friends.push_back(this);
        }
    }
};

class SocialGraph {
private:
    vector<Person*> people;
    Person* kevin_bacon{ nullptr };
    Person* you{ nullptr };

public:
    SocialGraph() 
    {
        vector<string> names = {
            "You", "Kevin Bacon", "Alice", "Bob", "Charlie",
            "David", "Emma", "Frank", "Grace", "Henry",
            "Isabel", "Jack", "Kate", "Liam", "Mia",
            "Noah", "Olivia", "Peter", "Quinn", "Rachel"
        };

        for (const auto& name : names)
        {
            Person* person = new Person(name);
            people.push_back(person);
            if (name == "Kevin Bacon") kevin_bacon = person;
            if (name == "You") you = person;
        }

        for (size_t i = 0; i < people.size(); ++i)
        {
            int num_connections = 2 + (rand() % 3);
            for (int j = 0; j < num_connections; ++j) 
            {
                size_t friend_idx = rand() % people.size();
                if (friend_idx != i) 
                {
                    people[i]->addFriend(people[friend_idx]);
                }
            }
        }
    }

    ~SocialGraph() 
    {
        for (Person* p : people)
        {
            delete p;
        }
    }

    bool findPathToKevinBacon(vector<string>& path) 
    {
        queue<Person*> q;
        unordered_map<Person*, Person*> previous;
        unordered_set<Person*> visited;

        q.push(you);
        visited.insert(you);

        while (!q.empty()) 
        {
            Person* current = q.front();
            q.pop();

            if (current == kevin_bacon)
            {
                Person* p = current;
                while (p != nullptr) 
                {
                    path.insert(path.begin(), p->name);
                    p = previous[p];
                }
                return true;
            }

            for (Person* friend_ptr : current->friends) 
            {
                if (visited.find(friend_ptr) == visited.end())
                {
                    visited.insert(friend_ptr);
                    previous[friend_ptr] = current;
                    q.push(friend_ptr);
                }
            }
        }

        path.clear();  
        return false;
    }

    void printGraph()
    {
        for (Person* p : people) {
            cout << p->name << " is friends with: ";
            for (Person* friend_ptr : p->friends) {
                cout << friend_ptr->name << ", ";
            }
            cout << std::endl;
        }
    }
};
