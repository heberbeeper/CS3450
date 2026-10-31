//Decorates an iterator to skip rejected elements
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
    std::function<bool(const T&)> predicate; //decides whether that element is accepted.

    void skipRejected();

public:
    FilterIterator(
        std::unique_ptr<Iterator<T>> iterator,
        std::function<bool(const T&)> condition
    );

    void first() override;
    void next() override; //advances the underlying iterator when an element is rejected
    bool isDone() override; //checks the underlying iterator
    T current() override; //gets the element from the underlying iterator
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

//pulls from the iterator it wraps
template<typename T>    
void FilterIterator<T>::skipRejected() {

    while (!wrapped->isDone() && !predicate(wrapped->current())) { //This shows that the filter gets its data through the wrapped iterator interface
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