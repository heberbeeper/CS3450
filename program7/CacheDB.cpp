
#include "CacheDB.h"

#include <iostream>
#include <stdexcept>
#include <string>

// Constructor
CacheDB::CacheDB(std::shared_ptr<IDatabase> database)
    : db(database)
{
}

// Return the wrapped database ID
std::string CacheDB::getID() const {
    return db->getID();
}

// Check if a key exists (do not cache)
bool CacheDB::exists(const std::string& key) {
    return db->exists(key);
}

// Retrieve a value, using the cache when possible
std::string CacheDB::get(const std::string& key) {

    // Check if the key is already cached. 
    auto it = cache.find(key);  //this is the telling line where it decides to forward the call or answer it itself

    if (it != cache.end()) {
        // Cache hit
        std::cout << "found key \"" << key
                  << "\" in cache\n";

        // Move key to the front (MRU)
        order.remove(key);
        order.push_front(key);

        return it->second;
    }

    // Cache miss: retrieve from wrapped database
    std::string value = db->get(key);

    // Evict least recently used entry if full
    if (cache.size() >= MAX_SIZE) {
        std::string lru = order.back();

        order.pop_back();
        cache.erase(lru);
    }

    // Add new entry as most recently used
    cache[key] = value;
    order.push_front(key);

    return value;
}

// Return cached keys in MRU order
std::string CacheDB::inspect() const {
    std::string result;

    for (const auto& key : order) {
        result += "[" + key + "], ";
    }

    return result;
}
