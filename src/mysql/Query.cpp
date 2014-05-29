#include "Query.h"

using namespace OOP_MYSQL;

Query::Query(const mysqlpp::Query& query)
    : query(query), executed(false)
{
}

Query::Query(Connection& conn, const char* queryStr)
    : query(conn.conn.query(queryStr)), executed(false)
{
}

Query::Query(const Query& other)
    : query(other.getQuery()), executed(false)
{
}
