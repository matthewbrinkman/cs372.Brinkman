// This code was created with the help of https://flowgpt.com/chat/pseudocode-conversion. The prompt that was entered was the 
// the question along with the linked list code from the lectures that you said to use. 
#pragma once
#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        Node* prev;
        Node* next;
        bool isDeleted; 

        Node(const T& value) : data(value), prev(nullptr), next(nullptr), isDeleted(false) {}
    };

    Node* head;
    Node* tail;
    int count;          
    int deletedCount;   

    void deleteNodes() {
        Node* current = head;
        while (current != nullptr) {
            if (current->isDeleted) {
                Node* toDelete = current;
                if (current->prev) {
                    current->prev->next = current->next;
                }
                else {
                    head = current->next; 
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                else {
                    tail = current->prev; 
                }
                current = current->next; 
                delete toDelete; 
                deletedCount--;
            }
            else {
                current = current->next; 
            }
        }
    }

public:
    List() : head(nullptr), tail(nullptr), count(0), deletedCount(0) {}

    List(T newData) : List() {
        push_back(newData);
    }

    ~List() {
        clear();
    }

    void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        count = 0;
        deletedCount = 0;
    }

    bool empty() {
        return count == 0;
    }

    void push_front(T data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head) {
            head->prev = newNode;
        }
        else {
            tail = newNode; 
        }
        head = newNode;
        count++;
    }

    void push_back(T data) {
        Node* newNode = new Node(data);
        newNode->prev = tail;
        if (tail) {
            tail->next = newNode;
        }
        else {
            head = newNode; 
        }
        tail = newNode;
        count++;
    }

    T front() {
        if (!empty()) {
            return head->data;
        }
        throw out_of_range("List is empty");
    }

    T back() {
        if (!empty()) {
            return tail->data;
        }
        throw out_of_range("List is empty");
    }

    void pop_back() {
        if (empty()) {
            throw out_of_range("List is empty");
        }
        if (tail->isDeleted) {
            tail->isDeleted = true;
            deletedCount++;
        }
        else {
            Node* lastNode = tail;
            tail = tail->prev;
            if (tail) {
                tail->next = nullptr;
            }
            else {
                head = nullptr; 
            }
            delete lastNode;
            count--;
        }
        if (deletedCount == count) {
            deleteNodes(); 
        }
    }

    void pop_front() 
    {
        if (empty()) {
            throw out_of_range("List is empty");
        }
        if (head->isDeleted) {
            head->isDeleted = true;
            deletedCount++;
        }
        else {
            Node* firstNode = head;
            head = head->next;
            if (head) {
                head->prev = nullptr;
            }
            else {
                tail = nullptr; 
            }
            delete firstNode;
            count--;
        }

        if (deletedCount == count) 
        {
            deleteNodes();
        }
    }
    void printTheList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};