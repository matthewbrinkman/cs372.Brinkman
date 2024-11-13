// This code was created with the help of claude.ai. The prompt used was the question from canvas.
#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

template<typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key;
        V value;
        bool isOccupied;
        bool isDeleted;

        Entry() : isOccupied(false), isDeleted(false) {}
    };

    Entry* table;
    int capacity;
    int size;
    const float LOAD_FACTOR_THRESHOLD = 0.7f;

    int hash(const K& key) const {
        return std::hash<K>{}(key) % capacity;
    }

    int findNextSlot(int currentIndex) const {
        return (currentIndex + 1) % capacity;
    }

    void resize() {
        int oldCapacity = capacity;
        Entry* oldTable = table;

        capacity *= 2;
        size = 0;
        table = new Entry[capacity];

        for (int i = 0; i < oldCapacity; i++) {
            if (oldTable[i].isOccupied && !oldTable[i].isDeleted) {
                insert(oldTable[i].key, oldTable[i].value);
            }
        }

        delete[] oldTable;
    }

public:
    HashTable(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
        table = new Entry[capacity];
    }

    ~HashTable() {
        delete[] table;
    }

    void insert(const K& key, const V& value) {
        if (static_cast<float>(size) / capacity >= LOAD_FACTOR_THRESHOLD) {
            resize();
        }

        int index = hash(key);
        int originalIndex = index;
        bool inserted = false;

        do {
            if (!table[index].isOccupied || table[index].isDeleted) {
                table[index].key = key;
                table[index].value = value;
                table[index].isOccupied = true;
                table[index].isDeleted = false;
                size++;
                inserted = true;
                break;
            }
            else if (table[index].key == key && !table[index].isDeleted) {
                table[index].value = value;  // Update existing value
                inserted = true;
                break;
            }

            index = findNextSlot(index);
        } while (index != originalIndex);

        if (!inserted) {
            throw std::runtime_error("Hash table is full!");
        }
    }

    bool get(const K& key, V& value) const {
        int index = hash(key);
        int originalIndex = index;

        do {
            if (!table[index].isOccupied) {
                return false;
            }

            if (table[index].isOccupied && !table[index].isDeleted && table[index].key == key) {
                value = table[index].value;
                return true;
            }

            index = findNextSlot(index);
        } while (index != originalIndex);

        return false;
    }

    bool remove(const K& key) {
        int index = hash(key);
        int originalIndex = index;

        do {
            if (!table[index].isOccupied) {
                return false;
            }

            if (table[index].isOccupied && !table[index].isDeleted && table[index].key == key) {
                table[index].isDeleted = true;
                size--;
                return true;
            }

            index = findNextSlot(index);
        } while (index != originalIndex);

        return false;
    }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
};
