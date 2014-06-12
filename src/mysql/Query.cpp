#include "Query.h"

using namespace OOP_MYSQL;

Query::Query(const mysqlpp::Query& query)
    : executed(false), query(query), needQuote(false), needSub(false)
{
}

Query::Query(Connection& conn, const char* queryStr)
    : executed(false), query(conn.conn.query(queryStr)), needQuote(false), needSub(false)
{
}

Query::Query(const Query& other)
    : executed(false), query(other.getQuery()), needQuote(false), needSub(false)
{
}

Query& Query::operator<<(const std::string& str)
{
    query << str;
    if(true == needSub)
    {
        query << "\%";
        needSub = false;
    }
    
    if (true == needQuote)
    {
        query << "\'";
        needQuote = false;
    }
    return *this;
}

Query& Query::operator<<(const char* str)
{
    query << str;
    if(true == needSub)
    {
        query << "\%";
        needSub = false;
    }
    
    if (true == needQuote)
    {
        query << "\'";
        needQuote = false;
    }
    return *this;
}

Query& Query::operator<<(const Symbol& symbol)
{
    if (QUOTE == symbol)
    {
        query << "\'";
        needQuote = true;
    }
    
    if (SUBSTRING == symbol)
    {
        query << "\%";
        needSub = true;
    }
    return *this;
}
