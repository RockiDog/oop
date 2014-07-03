/**
 * @copyright 2014, Zhejiang University
 * @author Wang Ru
 * @file Insert.h
 * @brief Insert query inherited from Query
 * @date 2014-05-30 Wang Ru: New the file, wrapp API of mysql++ API
 *       2014-05-31 Wang Ru: Exception added
 *       2014-06-07 Wang Ru: Bug fixed
 */
#ifndef OOP_SRC_MYSQL_INSERT_H_
#define OOP_SRC_MYSQL_INSERT_H_

#ifndef MYSQLPP_MYSQL_HEADERS_BURIED
#define MYSQLPP_MYSQL_HEADERS_BURIED
#endif

#include <mysql++/mysql++.h>
#include "Query.h"

namespace OOP_MYSQL
{
    /**
     * @brief Insert query inherited from Query, just input command and execute
     * @autor Wang Ru
     */
    class Insert: public Query
    {
    public:
        Insert(Connection& conn, const char* queryStr = 0);
        Insert(const Insert& other);

    public:
        virtual bool exec();

    private:
        void operator=(const Insert& other);
    };
}

#endif
