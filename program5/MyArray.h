// Implements fixed-capacity array storage
#pragma once

#include "IterableSequence.h"
#include <memory>
#include <stdexcept>

template<typename T>
class MyArray : public IterableSequence<T> {
    private:
        std::unique_ptr<T[]> data;
        int count;
        int maxCapacity;

    public:
        explicit MyArray(int capacity);

        void add(T value) override;
        int size() override;
        int capacity() override;
        T get(int index) override;

        std::unique_ptr<Iterator<T>> getIterator() override;
};

template<typename T>
MyArray<T>::MyArray(int capacity) : count(0), maxCapacity(capacity) {
    if (capacity < 0) {
        throw std::invalid_argument("Capacity cannot be negative.");
    }

    data = std::make_unique<T[]>(capacity);
}

template<typename T>
void MyArray<T>::add(T value) {
    if (count >= maxCapacity) {
        throw std::overflow_error("Array is full.");
    }

    data[count] = value;
    count++;
}

template<typename T>
int MyArray<T>::capacity() {
    return maxCapacity;
}

template<typename T>
int MyArray<T>::size() {
    return count;
}

template<typename T>
T MyArray<T>::get(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Invalid array index.");
    }
    
    return data[index];
}

#include "MyIterator.h"

template<typename T>
std::unique_ptr<Iterator<T>> MyArray<T>::getIterator() {
    return std::make_unique<MyIterator<T>>(*this);
}