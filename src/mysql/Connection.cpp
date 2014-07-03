/**
 * @copyright 2014, Zhejiang University
 * @author Wang Ru
 * @file Connection.cpp
 * @brief Connection class defination
 * @date 2014-05-30 Wang Ru: New the file, wrapp API of mysql++ API
 *       2014-05-31 Wang Ru: Exception added
 *       2014-06-07 Wang Ru: Bug fixed
 *       2014-06-17 Wang Ru: Bug fixed
 */
#include "Connection.h"
#include <iostream>
#include <string>

using namespace std;
using namespace OOP_MYSQL;

Connection::Connection(bool except)
    : conn(except), connected(false)
{
}

Connection::Connection(const Connection& other)
    : conn(other.conn), connected(other.connected)
{
}

///@breif Connect to the database, use C style string
bool Connection::connect(const char* user,
                            const char* password,
                            const char* server,
                            const char* database,
                            unsigned int port)
{
    std::cout << "Connecting to the database " << database
                << " on " << server << "..." << std::endl;

    conn.connect(database, server, user, password, port);
    if(false == conn.connected())
        connected = false;
    else
        connected = true;
    return conn.connected();
}

///@breif Connect to the database, use C++ string
bool Connection::connect(const string user,
                            const string password,
                            const string server,
                            const string database,
                            unsigned int port)
{
    std::cout << "Connecting to the database " << database
                << " on " << server << "..." << std::endl;

    conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str(), port);
    if(false == conn.connected())
        connected = false;
    else
        connected = true;
    return conn.connected();
}

void Connection::disconnect()
{
    conn.disconnect();
    connected = false;
    return;
}
