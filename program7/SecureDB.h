
#pragma once

#include "IDatabase.h"

#include <memory>
#include <string>

class SecureDB : public IDatabase {
private:
    std::shared_ptr<IDatabase> db;
    std::shared_ptr<IDatabase> userdb;

    bool authenticated = false;

    void authenticate();

public:
    SecureDB(std::shared_ptr<IDatabase> database,
             std::shared_ptr<IDatabase> users);

    std::string getID() const override;

    bool exists(const std::string& key) override;

    std::string get(const std::string& key) override;
};
