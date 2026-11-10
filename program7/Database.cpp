#include "Database.h"

#include <stdexcept>
#include <string>

// Constructor
Database::Database(const std::string& filename)
    : filename(filename), file(filename)
{
    if (!file.is_open()) {
        throw std::runtime_error(filename + " does not exist");
    }
}

// Return the database ID (filename)
std::string Database::getID() const {
    return filename;
}

// Check whether a key exists
bool Database::exists(const std::string& key) {
    file.clear();
    file.seekg(0, std::ios::beg);

    std::string currentKey;
    std::string value;

    while (file >> currentKey) {
        std::getline(file, value);

        if (currentKey == key) {
            return true;
        }
    }

    return false;
}

// Retrieve the value associated with a key
std::string Database::get(const std::string& key) {
    file.clear();
    file.seekg(0, std::ios::beg);

    std::string currentKey;
    std::string value;

    while (file >> currentKey) {
        std::getline(file, value);

        if (currentKey == key) {
            if (!value.empty() && value[0] == ' ') {
                value.erase(0, 1);
            }

            return value;
        }
    }

    throw std::runtime_error("No such record: " + key);
}



