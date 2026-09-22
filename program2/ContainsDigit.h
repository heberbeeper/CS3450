#pragma once

#include "Predicate.h"
#include <cctype>
#include <string>

class ContainsDigit : public Predicate {
public:
    bool execute(const std::string& value) const override {
        for (char ch : value) {
            if (std::isdigit(static_cast<unsigned char>(ch))) {
                return true;
            }
        }

        return false;
    }
};