#ifndef OOP_SRC_MYSQL_DELETE_H_
#define OOP_SRC_MYSQL_DELETE_H_

#ifndef MYSQLPP_MYSQL_HEADERS_BURIED
#define MYSQLPP_MYSQL_HEADERS_BURIED
#endif

#include <mysql++/mysql++.h>
#include "Query.h"

namespace OOP_MYSQL
{
    class Delete: public Query
    {
    public:
        Delete(Connection& conn, const char* queryStr = 0);
        Delete(const Delete& other);
    
    public:
        virtual bool exec();
    
    private:
        void operator=(const Delete& other);
    };
}

#endif
