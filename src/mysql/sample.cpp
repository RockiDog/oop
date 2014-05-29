//this file shows a simple sample for the customer mysql C++ API,
//give the brief usage,
//test the features of connecting to a database,
//inserting, deleting, updating and selecting
//you only need to include the head file <project>/src/mysql/MySQL.h
//and use the namespace OOP_MYSQL

#include "MySQL.h"
#include <iostream>
#include <string>
using namespace std;
using namespace OOP_MYSQL;

int main()
{
    string user;
    string password;
    
    //Input
    cout << "Please input your: [user name] [password]: ";
    cin >> user >> password;
    
    //Establish the connection
    //Default connect to the database "test" on "localhost"
    Connection conn;
    conn.connect(user.c_str(), password.c_str());
    if(false == conn.isConnected())
    {
        cout << "Can not connect to mysql!" << endl;
        return -1;
    }
    else
    {
        cout << "Connected!" << endl;
    }
    
    //Test query
    string queryStr;
    
    //Insert
    queryStr = "insert into student values('3120102084', 'Wang Ru', 20, 3.91)";//Give the query
    Insert ins1(conn, queryStr.c_str());//Instantiating an insert query
    ins1.exec();//Execute the Insert, simply return a bool
    if (false == ins1.isExecuted())
    {
        cout << "Can not insert!" << endl;
        return -1;
    }
    else
    {
        cout << "Inserted!" << endl;
    }
    
    queryStr = "insert into student values('3120123456', 'Jack', 20, 4.03)";//Give the query
    Insert ins2(conn, queryStr.c_str());//Instantiating an insert query
    ins2.exec();//Execute the Insert, simply return a bool
    if (false == ins2.isExecuted())
    {
        cout << "Can not insert!" << endl;
        return -1;
    }
    else
    {
        cout << "Inserted!" << endl;
    }
    
    queryStr = "insert into student values('3120234567','Rose',20,3.81)";//Give the query
    Insert ins3(conn, queryStr.c_str());//Instantiating an insert query
    ins3.exec();//Execute the Insert, simply return a bool
    if (false == ins3.isExecuted())
    {
        cout << "Can not insert!" << endl;
        return -1;
    }
    else
    {
        cout << "Inserted!" << endl;
    }
    
    //Delete
    /*
    queryStr = "delete from student where id = '3102102084'";//Give the query
    Delete del(conn, queryStr.c_str());//Instantiating a delete query
    del.exec();//Execute the Delete, simply return a bool
    if (false == del.isExecuted())
    {
        cout << "Can not delete!" << endl;
        return -1;
    }
    else
    {
        cout << "Deleted!" << endl;
    }
    */
    
    //Update
    /*
    queryStr = "update student set gpa=3.92 where id='3120123456'";//Give the query
    Update upd(conn, queryStr.c_str());//Instantiating an update query
    upd.exec();//Execute the Delete, simply return a bool
    if (false == upd.exec())
    {
        cout << "Can not update!" << endl;
        return -1;
    }
    else
    {
        cout << "Updated!" << endl;
    }
    */
    
    //Select
    queryStr = "select* from student where gpa>3.50";
    Select sel(conn, queryStr.c_str());//
    sel.exec();//Execute the Delete, simply return a bool
    if (false == sel.isExecuted())
    {
        cout << "Can not select!" << endl;
        return -1;
    }
    else
    {
        while (Tuple tuple = sel.fetchTuple())
        {
            cout << "[id]\t" << "[name]\t" << "[age]\t" << "[gpa]\t\n"
                << tuple["id"] << "\t"
                << tuple["name"] << "\t"
                << tuple["age"] << "\t"
                << tuple["gpa"] << "\t" << endl;
        }
    }
    
    return 0;
}
