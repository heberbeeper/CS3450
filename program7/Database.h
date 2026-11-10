#pragma once

#include "IDatabase.h"
#include <string>
#include <fstream>

class Database : public IDatabase {
private:
    std::string filename;
    std::ifstream file;

public:
    // Constructor
    explicit Database(const std::string& filename);

    // Destructor
    ~Database() override = default;

    // IDatabase interface methods
    std::string getID() const override;

    bool exists(const std::string& key) override;

    std::string get(const std::string& key) override;
};




