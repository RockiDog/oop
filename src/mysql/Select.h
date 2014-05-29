#ifndef OOP_SRC_MYSQL_SELECT_H_
#define OOP_SRC_MYSQL_SELECT_H_

#ifndef MYSQLPP_MYSQL_HEADERS_BURIED
#define MYSQLPP_MYSQL_HEADERS_BURIED
#endif

#include <mysql++/mysql++.h>
#include "Query.h"

namespace OOP_MYSQL
{
    class Select: public Query
    {
    public:
        Select(Connection& conn, const char* queryStr = 0);
        Select(const Select& other);
    
    public:
        virtual bool exec();
        const Tuple& fetchTuple();
    
    private:
        Result result;
        Tuple tuple;
    
    private:
        void operator=(const Select& other);
    };
}

#endif
