#pragma once

#include "Iterable.h"
#include "Sequence.h"

template<typename T>
class IterableSequence :
    public Iterable<T>,
    public Sequence<T> {
        public:
            virtual ~IterableSequence() = default;
    };