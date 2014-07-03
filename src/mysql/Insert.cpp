/**
 * @copyright 2014, Zhejiang University
 * @author Wang Ru
 * @file Insert.cpp
 * @brief Insert class defination
 * @date 2014-05-30 Wang Ru: New the file, wrapp API of mysql++ API
 *       2014-06-07 Wang Ru: Bug fixed
 */
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
