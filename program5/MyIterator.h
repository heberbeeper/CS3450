#pragma once

#include "Iterator.h"
#include "MyArray.h"
#include <stdexcept>

template<typename T>
class MyIterator : public Iterator<T> {
    private:
        MyArray<T>& array;
        int index;
    
    public:
        explicit MyIterator(MyArray<T>& arr) : array(arr), index(0) {}

        void first() override {
            index = 0;
        }

        void next() override{
            if (!isDone()) {
            return ++index;
            }
        }

        bool isDone() override {
            return index >= array.size();
        }

        T current() override {
            if (isDone()) {
                throw std::out_of_range("Iterator is done.");
            }

            return array.get(index);
        }
};