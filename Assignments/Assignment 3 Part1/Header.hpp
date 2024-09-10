#pragma once

#pragma once
#include <iostream>
#include <list>
using namespace std;

template <typename T>
class List {
private:
    class Node {
    public:
        T  data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
  
public:
   
    void setupList() {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }

    List() {
        setupList();
    }

    List(T newData) {
        setupList();
        head->data = newData;
    }

    ~List() {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }
    bool empty()
    {
        return (head->next == tail);
    }
    List(List& rhs) { // copy constructor
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current.next;
            delete current;
            current = temp;
        }
        head = rhs.head;
        tail = rhs.tail;
    }
    void deleteListContents() {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current.next;
            delete current;
            current = temp;
        };
    }
   
    void push_front(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head->prev = newNode;
        newNode->prev = nullptr;
        head = newNode;
    }
    void push_back(T data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    T front() {
        return (head->data);
    }
    T back() {
        return (tail->data);
    }
    void pop_back() {
        Node* lastNode = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete lastNode;
    }
    void pop_front() {
        Node* firstNode = head;
        head =head->next;
        head->prev = nullptr;
        delete firstNode;
    }
    void printTheList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void traverse(void (*doIt)(T data)) {
        Node* current = head;
        while (current != tail) {
            doIt(current.data);
        }
    }

};