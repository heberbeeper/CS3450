#pragma once

#include "QueueStorage.h"
#include <memory>
#include <stdexcept>
#include <utility>

template <typename T>
class Queue {
private:
    std::unique_ptr<QueueStorage<T>> impl;

public:
    // No no-argument constructor.
    Queue() = delete;

    // Requirement 7:
    // Takes initial storage and empties it.
    explicit Queue(std::unique_ptr<QueueStorage<T>> initialImpl)
        : impl(std::move(initialImpl)) {

        if (!impl) {
            throw std::invalid_argument("Queue requires a storage implementation");
        }

        impl->clear();
    }

    // Requirement 8: Queue cannot be copied or assigned.
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

    // Also prevent moving/assignment to keep the restriction simple.
    Queue(Queue&&) = delete;
    Queue& operator=(Queue&&) = delete;

    // Requirement 1
    void add(const T& element) {
        impl->addBack(element);
    }

    // Requirement 2
    const T& get() const {
        if (impl->size() == 0) {
            throw std::out_of_range("Queue is empty");
        }

        return impl->front();
    }

    // Requirement 3
    void remove() {
        if (impl->size() == 0) {
            throw std::out_of_range("Queue is empty");
        }

        impl->removeFront();
    }
    const T& peekLast() const {
        if (impl->size() == 0) {
            throw std::out_of_range("Queue is empty");
        }

        return impl->peekLast();
    }
    
    // Requirement 4
    std::size_t size() const {
        return impl->size();
    }

    // Requirement 5
    void clear() {
        impl->clear();
    }

    // Requirement 6
    // Notice: exactly ONE changeImpl().
    void changeImpl(std::unique_ptr<QueueStorage<T>> newImpl) {
        if (!newImpl) {
            throw std::invalid_argument("Queue requires a storage implementation");
        }

        // Empty the incoming implementation first.
        newImpl->clear();

        // Transfer current contents in FIFO order.
        while (impl->size() > 0) {
            newImpl->addBack(impl->front());
            impl->removeFront();
        }

        // Switch strategies.
        impl = std::move(newImpl);
    }
};