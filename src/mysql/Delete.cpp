/**
 * @copyright 2014, Zhejiang University
 * @author Wang Ru
 * @file Delete.cpp
 * @brief Delete class defination
 * @date 2014-05-30 Wang Ru: New the file, wrapp API of mysql++ API
 *       2014-06-07 Wang Ru: Bug fixed
 */
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
