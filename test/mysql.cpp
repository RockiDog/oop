#define MYSQLPP_MYSQL_HEADERS_BURIED

#include <iostream>
#include <string>
#include <vector>
#include <mysql++/mysql++.h>

using namespace std;

namespace
{
    const int paramNum=4;
}

int main(int args, char *argv[])
{
    string database;
    string server;
    string user;
    string password;
    
    if(args == paramNum)
    {
        database = argv[0];
        server = argv[1];
        user = argv[2];
        password = argv[3];
    }
    else
    {
        cout << "Please input [database name] [server name] [user name] [password]: ";
        cin >> database >> server >> user >> password;
    }
    
    //Establish the connection to the database server
    mysqlpp::Connection conn(false);
    conn.connect(database.c_str(), server.c_str(), user.c_str(), password.c_str());
    if(false == conn.connected())
    {
        cout << "Can not establish connection, please check your input!" << endl;
        return -1;
    }
    else
        cout << "Connect successfully!" << endl;
    
    //Test the query
    //Choose database
    mysqlpp::Query query = conn.query("select* from student where id='3120102084'");
    mysqlpp::StoreQueryResult res = query.store();
    for(mysqlpp::StoreQueryResult::size_type i = 0; i != res.num_rows(); ++i)
    {
        cout << res[i]["id"] << res[i]["name"] << res[i]["age"] << res[i]["gpa"] << endl;
    }
    return 0;
}
