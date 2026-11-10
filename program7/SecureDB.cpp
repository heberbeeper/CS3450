
#include "SecureDB.h"

#include <iostream>
#include <stdexcept>
#include <string>

// Constructor
SecureDB::SecureDB(
    std::shared_ptr<IDatabase> database,
    std::shared_ptr<IDatabase> users)
    : db(database), userdb(users)
{
}

// Authenticate on first access
void SecureDB::authenticate() {
    if (authenticated) {
        return;
    }

    std::string username;
    std::string password;

    std::cout << "Enter username: ";
    std::cin >> username;

    std::cout << "Enter password: ";
    std::cin >> password;

    if (!std::cin ||
        !userdb->exists(username) ||
        userdb->get(username) != password) {
        throw std::runtime_error(
            "Authentication failed"
        );
    }

    authenticated = true;
}

// Return wrapped database ID
std::string SecureDB::getID() const {
    return db->getID();
}

// Check if key exists
bool SecureDB::exists(const std::string& key) {
    authenticate();
    return db->exists(key);
}

// Retrieve value
std::string SecureDB::get(const std::string& key) {
    authenticate();
    return db->get(key);
}
