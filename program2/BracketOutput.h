#pragma once

#include "Output.h"
#include <memory>
#include <string>

class BracketOutput : public Output {
private:
    std::unique_ptr<Output> output;

public:
    explicit BracketOutput(std::unique_ptr<Output> wrappedOutput)
        : output(std::move(wrappedOutput)) {
    }

    void write(const std::string& value) override {
        output->write("[" + value + "]\n");
    }
};