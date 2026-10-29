#pragma once

template<typename T>
class Iterator {
    public:
        virtual ~Iterator() = default;

        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool isDone() = 0;
        virtual T current() = 0;
};