#pragma once

#include "Output.h"
#include <ostream>

class StreamOutput : public Output {
private:
    std::ostream& sink;

public:
    explicit StreamOutput(std::ostream& stream)
        : sink(stream) {
    }

    void write(const std::string& value) override {
        sink << value;
    }
};