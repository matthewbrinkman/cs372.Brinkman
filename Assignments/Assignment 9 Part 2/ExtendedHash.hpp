// This was created with claude.ai. The prompt used was the question in canvas along with the hash.cpp file from the first assignment.
#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include <functional>

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

    // Second hash function h2(x) = 7 - (x mod 7)
    int hash2(const K& key) const {
        return 7 - (std::hash<K>{}(key) % 7);
    }

    void linearProbe(int initialIndex, int& currentIndex, int step) const {
        currentIndex = (initialIndex + step) % capacity;
    }

    void quadraticProbe(int initialIndex, int& currentIndex, int step) const {
        currentIndex = (initialIndex + step * step) % capacity;
    }

    void doubleHash(int initialIndex, int& currentIndex, int step, const K& key) const {
        int h2 = hash2(key);
        currentIndex = (initialIndex + step * h2) % capacity;
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
    enum class ProbeType {
        LINEAR,
        QUADRATIC,
        DOUBLE_HASH
    };

    HashTable(int initialCapacity = 10) : capacity(initialCapacity), size(0) {
        table = new Entry[capacity];
    }

    ~HashTable() {
        delete[] table;
    }

    void insert(const K& key, const V& value, ProbeType probeType = ProbeType::LINEAR) {
        if (static_cast<float>(size) / capacity >= LOAD_FACTOR_THRESHOLD) {
            resize();
        }

        int initialIndex = hash(key);
        int currentIndex = initialIndex;
        int step = 0;
        bool inserted = false;

        while (step < capacity) {
            if (!table[currentIndex].isOccupied || table[currentIndex].isDeleted) {
                table[currentIndex].key = key;
                table[currentIndex].value = value;
                table[currentIndex].isOccupied = true;
                table[currentIndex].isDeleted = false;
                size++;
                inserted = true;
                break;
            }
            else if (table[currentIndex].key == key && !table[currentIndex].isDeleted) {
                table[currentIndex].value = value;
                inserted = true;
                break;
            }

            step++;
            switch (probeType) {
            case ProbeType::LINEAR:
                linearProbe(initialIndex, currentIndex, step);
                break;
            case ProbeType::QUADRATIC:
                quadraticProbe(initialIndex, currentIndex, step);
                break;
            case ProbeType::DOUBLE_HASH:
                doubleHash(initialIndex, currentIndex, step, key);
                break;
            }
        }

        if (!inserted) {
            throw std::runtime_error("Hash table is full!");
        }
    }

    bool get(const K& key, V& value, ProbeType probeType = ProbeType::LINEAR) const {
        int initialIndex = hash(key);
        int currentIndex = initialIndex;
        int step = 0;

        while (step < capacity) {
            if (!table[currentIndex].isOccupied) {
                return false;
            }
            if (table[currentIndex].isOccupied && !table[currentIndex].isDeleted &&
                table[currentIndex].key == key) {
                value = table[currentIndex].value;
                return true;
            }

            step++;
            switch (probeType) {
            case ProbeType::LINEAR:
                linearProbe(initialIndex, currentIndex, step);
                break;
            case ProbeType::QUADRATIC:
                quadraticProbe(initialIndex, currentIndex, step);
                break;
            case ProbeType::DOUBLE_HASH:
                doubleHash(initialIndex, currentIndex, step, key);
                break;
            }
        }
        return false;
    }

    bool remove(const K& key, ProbeType probeType = ProbeType::LINEAR) {
        int initialIndex = hash(key);
        int currentIndex = initialIndex;
        int step = 0;

        while (step < capacity) {
            if (!table[currentIndex].isOccupied) {
                return false;
            }
            if (table[currentIndex].isOccupied && !table[currentIndex].isDeleted &&
                table[currentIndex].key == key) {
                table[currentIndex].isDeleted = true;
                size--;
                return true;
            }

            step++;
            switch (probeType) {
            case ProbeType::LINEAR:
                linearProbe(initialIndex, currentIndex, step);
                break;
            case ProbeType::QUADRATIC:
                quadraticProbe(initialIndex, currentIndex, step);
                break;
            case ProbeType::DOUBLE_HASH:
                doubleHash(initialIndex, currentIndex, step, key);
                break;
            }
        }
        return false;
    }

    int getSize() const { return size; }
    int getCapacity() const { return capacity; }
};
