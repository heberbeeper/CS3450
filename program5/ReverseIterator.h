#pragma once
#include "Iterator.h"
#include <memory>
#include <stdexcept>
#include <utility>
#include <vector>

template<typename T>
class ReverseIterator : public Iterator<T> {
    private:
        std::unique_ptr<Iterator<T>> wrapped;
        std::vector<T> items;
        std::size_t position = 0;
    public:
        explicit ReverseIterator(std::unique_ptr<Iterator<T>> iterator)
            : wrapped(std::move(iterator)) {
            if (!wrapped) throw std::invalid_argument("Iterator cannot be null");
            wrapped->first();
            while (!wrapped->isDone()) {
                items.push_back(wrapped->current());
                wrapped->next();
            }
            first();
        }
        void first() override { 
            position = items.size(); 
        }
        void next() override { 
            if (!isDone()) --position; 
        }
        bool isDone() override { 
            return position == 0; 
        }
        T current() override {
            if (isDone()) throw std::out_of_range("Reverse iterator is done");
            return items[position - 1];
        }
};
