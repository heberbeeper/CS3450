#pragma once

#include <string>

class IDatabase {
public:
    virtual ~IDatabase() = default;

    virtual std::string getID() const = 0;
    virtual bool exists(const std::string& key) = 0;
    virtual std::string get(const std::string& key) = 0;
};


