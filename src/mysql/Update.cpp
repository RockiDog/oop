/**
 * @copyright 2014, Zhejiang University
 * @author Wang Ru
 * @file Update.cpp
 * @brief Update class defination
 * @date 2014-05-30 Wang Ru: New the file, wrapp API of mysql++ API
 *       2014-06-07 Wang Ru: Bug fixed
 */
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
