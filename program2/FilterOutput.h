#pragma once

#include "Output.h"
#include "Predicate.h"
#include <memory>
#include <string>

class FilterOutput : public Output {
private:
    std::unique_ptr<Output> output;
    std::unique_ptr<Predicate> predicate;

public:
    FilterOutput(
        std::unique_ptr<Output> wrappedOutput,
        std::unique_ptr<Predicate> suppliedPredicate
    )
        : output(std::move(wrappedOutput)),
          predicate(std::move(suppliedPredicate)) {
    }

    void write(const std::string& value) override {
        if (predicate->execute(value)) {
            output->write(value);
        }
    }
};