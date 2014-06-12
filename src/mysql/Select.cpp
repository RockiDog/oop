#include "Select.h"

using namespace OOP_MYSQL;

Select::Select(Connection& conn, const char* queryStr)
    : Query(conn, queryStr)
{
}

Select::Select(const Select& other)
    : Query(other)
{
}

bool Select::exec()
{
    if ((result = getQuery().use()))
        executed = true;
    else
        executed = false;
    return executed;
}

const Tuple& Select::fetchTuple()
{
    tuple = result.fetch_row();
    return tuple;
}
