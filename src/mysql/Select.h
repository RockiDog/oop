/**
 * @copyright 2014, Zhejiang University
 * @author Wang Ru
 * @file Select.h
 * @brief Select query inherited from Query
 * @date 2014-05-30 Wang Ru: New the file, wrapp API of mysql++ API
 *       2014-06-07 Wang Ru: Bug fixed
 */
#ifndef OOP_SRC_MYSQL_SELECT_H_
#define OOP_SRC_MYSQL_SELECT_H_

#ifndef MYSQLPP_MYSQL_HEADERS_BURIED
#define MYSQLPP_MYSQL_HEADERS_BURIED
#endif

#include <mysql++/mysql++.h>
#include "Query.h"

namespace OOP_MYSQL
{
    /**
     * @brief Select query inherited from Query
     * @autor Wang Ru
     */
    class Select: public Query
    {
    public:
        Select(Connection& conn, const char* queryStr = 0);
        Select(const Select& other);

    public:
        ///@breif Execute select query
        virtual bool exec();

        ///@breif The select result returned tuple by tuple
        const Tuple& fetchTuple();

    private:
        Result result;
        Tuple tuple;

    private:
        void operator=(const Select& other);
    };
}

#endif
