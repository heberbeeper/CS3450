#pragma once

#include <string>

class Predicate {
public:
    virtual ~Predicate() = default;

    virtual bool execute(const std::string& value) const = 0;
};