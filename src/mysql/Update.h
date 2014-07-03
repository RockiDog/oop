/**
 * @copyright 2014, Zhejiang University
 * @author Wang Ru
 * @file Update.h
 * @brief Update query inherited from Query
 * @date 2014-05-30 Wang Ru: New the file, wrapp API of mysql++ API
 *       2014-06-07 Wang Ru: Bug fixed
 */
#ifndef OOP_SRC_MYSQL_UPDATE_H_
#define OOP_SRC_MYSQL_UPDATE_H_

#ifndef MYSQLPP_MYSQL_HEADERS_BURIED
#define MYSQLPP_MYSQL_HEADERS_BURIED
#endif

#include <mysql++/mysql++.h>
#include "Query.h"

namespace OOP_MYSQL
{
    /**
     * @brief Update query inherited from Query, just input command and execute
     * @autor Wang Ru
     */
    class Update: public Query
    {
    public:
        Update(Connection& conn, const char* queryStr = 0);
        Update(const Update& other);

    public:
        virtual bool exec();

    private:
        void operator=(const Update& other);
    };
}

#endif
