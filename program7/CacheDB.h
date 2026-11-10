#pragma once

#include "IDatabase.h"

#include <list>
#include <memory>
#include <string>
#include <unordered_map>

class CacheDB : public IDatabase {
private:
    std::shared_ptr<IDatabase> db;

    // Front = Most Recently Used
    std::list<std::string> order;

    // Key -> Cached value
    std::unordered_map<std::string, std::string> cache;

    static constexpr std::size_t MAX_SIZE = 5;

public:
    explicit CacheDB(std::shared_ptr<IDatabase> database);

    std::string getID() const override;

    bool exists(const std::string& key) override;

    std::string get(const std::string& key) override;

    std::string inspect() const;
};

