
#include "Database.h"
#include "CacheDB.h"
#include "SecureDB.h"

#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

void test(IDatabase& db) {
    try {
        std::cout << db.get("one") << '\n';
        std::cout << db.get("two") << '\n';
        std::cout << std::boolalpha
                  << db.exists("two") << '\n';
        std::cout << db.get("three") << '\n';
        std::cout << db.get("four") << '\n';
        std::cout << db.get("four") << '\n';
        std::cout << db.get("five") << '\n';
        std::cout << db.get("six") << '\n';
        std::cout << db.get("one") << '\n';
        std::cout << db.get("seven") << '\n';
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }

    std::cout << '\n';
}

int main() {
    try {
        auto db = std::make_shared<Database>("db.txt");
        auto userdb = std::make_shared<Database>("userdb.txt");

        // 1. Database without proxies
        std::cout << "---Database---\n";
        test(*db);

        // 2. SecureDB wrapping Database
        auto secure = std::make_shared<SecureDB>(db, userdb);

        std::cout << "---SecureDB---\n";
        test(*secure);

        // 3. CacheDB wrapping SecureDB
        auto cache = std::make_shared<CacheDB>(secure);

        std::cout << "---CacheDB -> SecureDB---\n";
        test(*cache);

        std::cout << "Cache contents: "
                  << cache->inspect() << "\n\n";

        // 4. Reverse order:
        // SecureDB wrapping CacheDB
        auto reverseCache = std::make_shared<CacheDB>(db);
        auto reverseSecure = std::make_shared<SecureDB>(
            reverseCache, userdb
        );

        std::cout << "---SecureDB -> CacheDB---\n";
        test(*reverseSecure);

        std::cout << "Cache contents: "
                  << reverseCache->inspect() << "\n\n";

        // 5. Missing file test
        std::cout << "Missing File\n";

        try {
            Database missing("noname.txt");
        }
        catch (const std::runtime_error& e) {
            std::cout << e.what() << '\n';
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
