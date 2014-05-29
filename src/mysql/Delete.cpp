#include "Delete.h"

using namespace OOP_MYSQL;

Delete::Delete(Connection& conn, const char* queryStr)
    : Query(conn, queryStr)
{
}

Delete::Delete(const Delete& other)
    : Query(other)
{
}

bool Delete::exec()
{
    executed = getQuery().exec();
    return executed;
}
