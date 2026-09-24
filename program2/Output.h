#pragma once

#include <utility>
#include <string>

class Output {
public:
    virtual ~Output() = default;

    virtual void write(const std::string& value) = 0;
};