#include "Insert.h"

using namespace OOP_MYSQL;

Insert::Insert(Connection& conn, const char* queryStr)
    : Query(conn, queryStr)
{
}

Insert::Insert(const Insert& other)
    : Query(other)
{
}

bool Insert::exec()
{
    executed = getQuery().exec();
    return executed;
}
