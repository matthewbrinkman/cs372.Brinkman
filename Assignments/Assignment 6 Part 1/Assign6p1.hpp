#pragma once

#include <memory>
#include <iostream>
using namespace std;

template <typename T>
class List {
private:
    struct Node {
        T data;
        shared_ptr<Node> next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    size_t size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    void push_back(const T& value) {
        auto newNode = make_shared<Node>(value);
        if (tail) {
            tail->next = newNode;
            tail = newNode;
        }
        else {
            head = tail = newNode;
        }
        ++size;
    }

    void pop_front() {
        if (head) {
            head = head->next;
            if (!head) {
                tail = nullptr;
            }
            --size;
        }
    }

    T& front() {
        if (!head) {
            throw out_of_range("List is empty");
        }
        return head->data;
    }

    const T& front() const {
        if (!head) {
            throw out_of_range("List is empty");
        }
        return head->data;
    }

    size_t get_size() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    void clear() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    class Iterator {
    private:
        shared_ptr<Node> current;

    public:
        Iterator(shared_ptr<Node> node) : current(node) {}

        T& operator*() { return current->data; }
        Iterator& operator++() { current = current->next; return *this; }
        bool operator!=(const Iterator& other) { return current != other.current; }
    };

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
};