/**
 * @copyright 2014, Zhejiang University
 * @author Wang Ru
 * @file Query.h
 * @brief Base class of SQL query
 * @date 2014-05-30 Wang Ru: New the file, wrapp API of mysql++ API
 *       2014-05-31 Wang Ru: Exception added
 *       2014-06-07 Wang Ru: Bug fixed
 */
#ifndef OOP_SRC_MYSQL_QUERY_H_
#define OOP_SRC_MYSQL_QUERY_H_

#ifndef MYSQLPP_MYSQL_HEADERS_BURIED
#define MYSQLPP_MYSQL_HEADERS_BURIED
#endif

#include "Connection.h"
#include <mysql++/mysql++.h>

#include <string>

namespace OOP_MYSQL
{
    typedef mysqlpp::Row Tuple;
    typedef mysqlpp::UseQueryResult Result;
    typedef mysqlpp::BadQuery QueryErr;
    typedef mysqlpp::ConnectionFailed ConnectionErr;

    enum Symbol
    {
        QUOTE,
        SUBSTRING
    };

    /**
     * @brief Base query class, abstract class
     * @autor Wang Ru
     */
    class Query
    {
    public:
        Query(const mysqlpp::Query& query);
        Query(Connection& conn, const char* queryStr);
        Query(const Query& other);

    public:
        ///@breif Execute the query, must be overloaded
        virtual bool exec() = 0;

        bool isExecuted()
        {
            return executed;
        }

        ///@breif Return row number affected by a query
        unsigned long long affectedRows()
        {
            return query.affected_rows();
        }

        const mysqlpp::Query& getQuery() const
        {
            return query;
        }

        ///@breif Return row number affected by a query
        mysqlpp::Query& getQuery()
        {
            return query;
        }

        ///@breif You can input the query using strings like cout
        Query& operator<<(const std::string& str);
        Query& operator<<(const char* str);
        Query& operator<<(const Symbol& symbol);

    protected:
        bool executed;

    private:
        mysqlpp::Query query;
        bool needQuote;
        bool needSub;
    };
}

#endif
