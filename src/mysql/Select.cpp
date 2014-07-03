/**
 * @copyright 2014, Zhejiang University
 * @author Wang Ru
 * @file Select.cpp
 * @brief Select class defination
 * @date 2014-05-30 Wang Ru: New the file, wrapp API of mysql++ API
 *       2014-06-07 Wang Ru: Bug fixed
 */
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

///@breif Fetch tuple one at a time
const Tuple& Select::fetchTuple()
{
    tuple = result.fetch_row();
    return tuple;
}
