#ifndef OOP_SRC_MYSQL_INSERT_H_
#define OOP_SRC_MYSQL_INSERT_H_

#ifndef MYSQLPP_MYSQL_HEADERS_BURIED
#define MYSQLPP_MYSQL_HEADERS_BURIED
#endif

#include <mysql++/mysql++.h>
#include "Query.h"

namespace OOP_MYSQL
{
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
