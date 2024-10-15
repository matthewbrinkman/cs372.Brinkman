// This code was made with the help of claude.ai. The prompt used was the full question.

#pragma once

#include <list>
#include <stdexcept>
#include <memory>
#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair() : first(), second() {}
    Pair(const T1& f, const T2& s) : first(f), second(s) {}
};

template <typename KeyType, typename ValueType>
class Dictionary {
private:
    struct Node 
    {
        Pair<KeyType, ValueType> data;
        unique_ptr<Node> left;
        unique_ptr<Node> right;
        Node(const KeyType& key, const ValueType& value)
            : data(key, value), left(nullptr), right(nullptr) {}
    };

    unique_ptr<Node> root;

    Node* find(const KeyType& key) const 
    {
        Node* current = root.get();
        while (current != nullptr)
        {
            if (key == current->data.first) return current;
            if (key < current->data.first) current = current->left.get();
            else current = current->right.get();
        }
        return nullptr;
    }

    void insert(const KeyType& key, const ValueType& value) 
    {
        if (!root) 
        {
            root = make_unique<Node>(key, value);
            return;
        }
        Node* current = root.get();
        while (true) 
        {
            if (key == current->data.first) 
            {
                current->data.second = value;
                return;
            }
            if (key < current->data.first) 
            {
                if (!current->left)
                {
                    current->left = make_unique<Node>(key, value);
                    return;
                }
                current = current->left.get();
            }
            else
            {
                if (!current->right) 
                {
                    current->right = make_unique<Node>(key, value);
                    return;
                }
                current = current->right.get();
            }
        }
    }

    void inorderTraversal(Node* node, list<KeyType>& keys, list<ValueType>& values) const
    {
        if (node) 
        {
            inorderTraversal(node->left.get(), keys, values);
            keys.push_back(node->data.first);
            values.push_back(node->data.second);
            inorderTraversal(node->right.get(), keys, values);
        }
    }

public:
    ValueType& get(const KeyType& key) 
    {
        Node* node = find(key);
        if (!node) throw std::out_of_range("Key not found");
        return node->data.second;
    }

    void set(const KeyType& key, const ValueType& value) 
    {
        insert(key, value);
    }

    list<KeyType> getKeys() const
    {
        list<KeyType> keys;
        list<ValueType> dummy;
        inorderTraversal(root.get(), keys, dummy);
        return keys;
    }

    list<ValueType> getValues() const 
    {
        list<KeyType> dummy;
        list<ValueType> values;
        inorderTraversal(root.get(), dummy, values);
        return values;
    }

    ValueType& operator[](const KeyType& key) 
    {
        return get(key);
    }
};