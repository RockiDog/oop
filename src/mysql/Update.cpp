#include "Update.h"

using namespace OOP_MYSQL;

Update::Update(Connection& conn, const char* queryStr)
    : Query(conn, queryStr)
{
}

Update::Update(const Update& other)
    : Query(other)
{
}

bool Update::exec()
{
    executed = getQuery().exec();
    return executed;
}
