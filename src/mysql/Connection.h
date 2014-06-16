#ifndef OOP_SRC_MYSQL_CONNECTION_H_
#define OOP_SRC_MYSQL_CONNECTION_H_

#ifndef MYSQLPP_MYSQL_HEADERS_BURIED
#define MYSQLPP_MYSQL_HEADERS_BURIED
#endif

#include <string>

#include <mysql++/mysql++.h>

namespace OOP_MYSQL
{
    class Query;
    
    class Connection
    {
    public:
        Connection(bool except = false);
        Connection(const Connection& other);
    
    public:
        bool connect(const char* user,
                const char* password,
                const char* server = "localhost",
                const char* database = "oop",
                unsigned int port = 0);
        
        bool connect(const std::string user,
                const std::string password,
                const std::string server = "localhost",
                const std::string database = "oop",
                unsigned int port = 0);
        
        void disconnect();
        
        bool isConnected()
        {
            return connected;
        }
    
    public:
        friend class Query;
    
    private:
        mysqlpp::Connection conn;
        bool connected;
    
    private:
        void operator=(const Connection& other);
    };
}

#endif
