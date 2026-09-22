#pragma once

#include "Output.h"
#include <memory>
#include <string>

class NumberedOutput : public Output {
private:
    std::unique_ptr<Output> output;
    int lineNumber;

public:
    explicit NumberedOutput(std::unique_ptr<Output> wrappedOutput)
        : output(std::move(wrappedOutput)),
          lineNumber(1) {
    }

    void write(const std::string& value) override {
        output->write(
            std::to_string(lineNumber) + ": " + value
        );

        ++lineNumber;
    }
};