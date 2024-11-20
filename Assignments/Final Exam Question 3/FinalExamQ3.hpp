// This program was creared using claude.ai and the prompt was the question along with the twemplate that was provided.
#pragma once
#include <iostream>
#include <cassert>

template <class RecordType>
class Table {
public:
    static const size_t CAPACITY = 811;

    Table() : used(0) {
        for (size_t i = 0; i < CAPACITY; ++i) {
            data[i].key = NEVERUSED;
        }
    }

    void insert(const RecordType& entry) {
        bool alreadyPresent;
        size_t index;
        assert(entry.key >= 0);
        findIndex(entry.key, alreadyPresent, index);

        if (!alreadyPresent) {
            assert(size() < CAPACITY);
            index = hash(entry.key);

            if (!isVacant(index)) {
                quadProbe(index);
            }
            ++used;
        }
        data[index] = entry;
    }

    void remove(int key) {
        bool found;
        size_t index;
        assert(key >= 0);
        findIndex(key, found, index);
        if (found) {
            data[index].key = PREVIOUSLYUSED;
            --used;
        }
    }

    bool isPresent(int key) const {
        bool found;
        size_t index;
        findIndex(key, found, index);
        return found;
    }

    void find(int key, bool& found, RecordType& result) const {
        size_t index;
        findIndex(key, found, index);
        if (found) {
            result = data[index];
        }
    }

    size_t size() const { return used; }

private:
    static const int NEVERUSED = -1;
    static const int PREVIOUSLYUSED = -2;
    RecordType data[CAPACITY];
    size_t used;

    size_t hash(int key) const {
        return key % CAPACITY;
    }

    void quadProbe(size_t& index) const {
        size_t originalIndex = index;
        size_t i = 1;

        while (!isVacant(index) && i < CAPACITY) {
            index = (originalIndex + i * i) % CAPACITY;
            ++i;
        }

        if (i >= CAPACITY) {
            throw std::runtime_error("Hash table is full or no available slot found");
        }
    }

    void findIndex(int key, bool& found, size_t& index) const {
        size_t count = 0;
        size_t originalIndex = hash(key);
        index = originalIndex;
        size_t i = 1;

        while ((count < CAPACITY) &&
            (!neverUsed(data[index].key)) &&
            (data[index].key != key)) {
            index = (originalIndex + i * i) % CAPACITY;
            ++count;
            ++i;
        }

        found = (data[index].key == key);
    }

    bool neverUsed(int key) const {
        return (key == NEVERUSED);
    }

    bool isVacant(size_t index) const {
        return (data[index].key == NEVERUSED || data[index].key == PREVIOUSLYUSED);
    }
};