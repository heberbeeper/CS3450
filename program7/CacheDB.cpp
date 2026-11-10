#include "CacheDB.h"

#include <iostream>
#include <stdexcept>

// Constructor
CacheDB::CacheDB(std::shared_ptr<IDatabase> database)
    : db(database)
{
}

// Return the wrapped database ID
std::string CacheDB::getID() const {
    return db->getID();
}


