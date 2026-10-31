//Traverses the array using an index, implementing the Iterator interface
#pragma once

#include "Iterator.h"
#include "Sequence.h"
#include <stdexcept>

template<typename T>
class MyIterator : public Iterator<T> {
private:
    Sequence<T>& array;
    int index;

public:
    explicit MyIterator(Sequence<T>& arr)
        : array(arr), index(0) {}

    void first() override {
        index = 0;
    }

    void next() override {
        if (!isDone()) {
            ++index;
        }
    }

    bool isDone() override {
        return index >= array.size();
    }

    T current() override {
        if (isDone()) {
            throw std::out_of_range(
                "Iterator is finished"
            );
        }

        return array.get(index);
    }
};
