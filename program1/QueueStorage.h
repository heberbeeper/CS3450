#pragma once

#include <cstddef>
#include <list>
#include <stdexcept>
#include <vector>

// Strategy interface
template <typename T>
class QueueStorage {
public:
    virtual ~QueueStorage() = default;

    virtual void addBack(const T& value) = 0;
    virtual const T& front() const = 0;
    virtual void removeFront() = 0;
    virtual std::size_t size() const = 0;
    virtual void clear() = 0;
};

// Concrete Strategy #1
template <typename T>
class VectorStorage : public QueueStorage<T> {
private:
    std::vector<T> data;

public:
    void addBack(const T& value) override {
        data.push_back(value);
    }

    const T& front() const override {
        if (data.empty()) {
            throw std::out_of_range("Storage is empty");
        }

        return data.front();
    }

    void removeFront() override {
        if (data.empty()) {
            throw std::out_of_range("Storage is empty");
        }

        data.erase(data.begin());
    }

    std::size_t size() const override {
        return data.size();
    }

    void clear() override {
        data.clear();
    }
};

// Concrete Strategy #2
template <typename T>
class ListStorage : public QueueStorage<T> {
private:
    std::list<T> data;

public:
    void addBack(const T& value) override {
        data.push_back(value);
    }

    const T& front() const override {
        if (data.empty()) {
            throw std::out_of_range("Storage is empty");
        }

        return data.front();
    }

    void removeFront() override {
        if (data.empty()) {
            throw std::out_of_range("Storage is empty");
        }

        data.pop_front();
    }

    std::size_t size() const override {
        return data.size();
    }

    void clear() override {
        data.clear();
    }
};