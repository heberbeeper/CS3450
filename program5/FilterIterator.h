
#pragma once

#include "Iterator.h"
#include <functional>
#include <memory>
#include <utility>
#include <stdexcept>

template<typename T>
class FilterIterator : public Iterator<T> {
private:
    std::unique_ptr<Iterator<T>> wrapped;
    std::function<bool(const T&)> predicate;

    void skipRejected();

public:
    FilterIterator(
        std::unique_ptr<Iterator<T>> iterator,
        std::function<bool(const T&)> condition
    );

    void first() override;
    void next() override;
    bool isDone() override;
    T current() override;
};

template<typename T>
FilterIterator<T>::FilterIterator(
    std::unique_ptr<Iterator<T>> iterator,
    std::function<bool(const T&)> condition
)
    : wrapped(std::move(iterator)), predicate(std::move(condition)) {

    if (!wrapped) {
        throw std::invalid_argument("Iterator cannot be null");
    }

    if (!predicate) {
        throw std::invalid_argument("Predicate cannot be empty");
    }

    first();
}

template<typename T>    
void FilterIterator<T>::skipRejected() {

    while (!wrapped->isDone() && !predicate(wrapped->current())) {
        wrapped->next();
    }
}

template<typename T>
void FilterIterator<T>::first() {

    wrapped->first();
    skipRejected();
}

template<typename T>
void FilterIterator<T>::next() {

    if (!wrapped->isDone()) {
        wrapped->next();
        skipRejected();
    }
}

template<typename T>
bool FilterIterator<T>::isDone() {
    return wrapped->isDone();
}

template<typename T>
T FilterIterator<T>::current() {
    if (isDone()) {
        throw std::out_of_range("Iterator is done");
    }
    return wrapped->current();
}