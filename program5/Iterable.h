#pragma once

#include "Iterator.h"
#include <memory>

template<typename T>
class Iterable {
    public:
        virtual ~Iterable() = default;

        virtual std::unique_ptr<Iterator<T>> getIterator() = 0;
};