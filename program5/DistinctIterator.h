
#pragma once

#include "Iterator.h"
#include "DistinctIterator.h"
#include "ReverseIterator.h"
#include <memory>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <utility>

template<typename T>
class DistinctIterator : public Iterator<T> {
private:
    std::unique_ptr<Iterator<T>> wrapped;
    std::vector<T> seen;

    void skipDuplicates() {
        while (!wrapped->isDone()) {
            T value = wrapped->current();

            if (std::find(seen.begin(), seen.end(), value)
                == seen.end()) {
                break;
            }

            wrapped->next();
        }
    }

public:
    explicit DistinctIterator(
        std::unique_ptr<Iterator<T>> iterator
    ) : wrapped(std::move(iterator)) {
        first();
    }

    void first() override {
        seen.clear();
        wrapped->first();
        skipDuplicates();
    }

    void next() override {
        if (!isDone()) {
            seen.push_back(wrapped->current());
            wrapped->next();
            skipDuplicates();
        }
    }

    bool isDone() override {
        return wrapped->isDone();
    }

    T current() override {
        if (isDone()) {
            throw std::out_of_range("Iterator is done");
        }
        return wrapped->current();
    }
};
