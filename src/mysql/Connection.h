/**
 * @copyright 2014, Zhejiang University
 * @author Wang Ru
 * @file Connection.h
 * @brief Database connection class based on mysql++3 API
 * @date 2014-05-30 Wang Ru: New the file, wrapp API of mysql++ API
 *       2014-05-31 Wang Ru: Exception added
 *       2014-06-07 Wang Ru: Bug fixed
 *       2014-06-17 Wang Ru: Bug fixed
 */
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


/**
 * @brief Database connection class
 * @autor Wang Ru
 */
class Connection
    {
    public:

        Connection(bool except = false);
        Connection(const Connection& other);

    public:
        ///@breif Connect to database, default to local
        bool connect(const char* user,
                const char* password,
                const char* server = "localhost",
                const char* database = "oop",
                unsigned int port = 0);

        ///@breif Connect using string
        bool connect(const std::string user,
                const std::string password,
                const std::string server = "localhost",
                const std::string database = "oop",
                unsigned int port = 0);

        ///@breif Disconnect, don't have to disconnect manually
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
