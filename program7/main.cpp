#include "Database.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        Database db("db.txt");

        std::cout << "ID: " << db.getID() << '\n';
        std::cout << db.get("one") << '\n';
        std::cout << db.get("two") << '\n';
        std::cout << std::boolalpha
                  << db.exists("three") << '\n';
        std::cout << db.get("seven") << '\n';

    } catch (const std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
