#pragma once

template <typename T>
class Sequence {
    public:
        virtual ~Sequence() = default;

        virtual void add(T value) = 0;
        virtual int size() = 0;
        virtual int capacity() = 0;
        virtual T get(int index) = 0;
};