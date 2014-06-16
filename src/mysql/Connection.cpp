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

bool Connection::connect(const char* user,
                            const char* password,
                            const char* server, 
                            const char* database, 
                            unsigned int port)
{
    std::cout << "Connecting to the database " << database
                << " on " << server << "..." << std::endl;
    
    conn.connect("test", server, user, password, port);
    if(false == conn.connected())
        connected = false;
    else
        connected = true;
    return conn.connected();
}

bool Connection::connect(const string user,
                            const string password,
                            const string server,
                            const string database,
                            unsigned int port)
{
    std::cout << "Connecting to the database " << database
                << " on " << server << "..." << std::endl;
    
    conn.connect("test", server.c_str(), user.c_str(), password.c_str(), port);
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
