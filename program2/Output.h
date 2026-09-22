#pragma once

#include <string>

class Output {
public:
    virtual ~Output() = default;

    virtual void write(const std::string& value) = 0;
};