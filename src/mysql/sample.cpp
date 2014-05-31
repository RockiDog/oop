//**************************************************************
//
//  Shows a simple sample that
//  gives the brief usage of the mysql C++ API.
//
//  Tests the features of connecting,
//  inserting, deleting, updating and selecting.
//
//  "libmysql++3" needed,
//  download from http://tangentsoft.net/mysql++/
//
//  Include "<project_name>/src/mysql/MySQL.h".
//  Use the namespace "OOP_MYSQL".
//
//  If your IDE do not compile automatically:
//      +Build from the source
//          -Execute "make" under "<project_name>/src/mysql/"
//          -Or compile and link by yourself,
//           see makefile for more information
//      +Run "./sample"
//
//**************************************************************

#include "MySQL.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
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
    
    try
    {
        //Establish the connection
        //Default connect to the database "test" on "localhost"
        Connection conn(true);
        conn.connect(user.c_str(), password.c_str());
        cout << "Connected!" << endl;
        
        //Test query
        string queryStr;
     
        //Insert
        try
        {
            queryStr = "insert into student values('3120102084', 'Wang Ru', 20, 3.91)";//Give the query
            Insert ins1(conn, queryStr.c_str());//Instantiating an insert query
            ins1.exec();//Execute the Insert, simply return a bool
            cout << "Inserted!" << endl;
            
            queryStr = "insert into student values('3120123456', 'Jack', 20, 4.03)";//Give the query
            Insert ins2(conn, queryStr.c_str());//Instantiating an insert query
            ins2.exec();//Execute the Insert, simply return a bool
            cout << "Inserted!" << endl;
            
            queryStr = "insert into student values('3120234567','Rose',20,3.81)";//Give the query
            Insert ins3(conn, queryStr.c_str());//Instantiating an insert query
            ins3.exec();//Execute the Insert, simply return a bool
            cout << "Inserted!" << endl;
        }
        catch (QueryErr err)
        {
            cout << err.errnum() << ": " << err.what() << endl;
        }
        
        //Delete
        try
        {
            queryStr = "delete from student where id='3120102084'";//Give the query
            Delete del(conn, queryStr.c_str());//Instantiating a delete query
            del.exec();//Execute the Delete, simply return a bool
            cout << "Deleted!" << endl;
        }
        catch (QueryErr err)
        {
            cout << err.errnum() << ": " << err.what() << endl;
        }
        
        //Update
        try
        {
            queryStr = "update student set gpa=3.92 where id='3120102084'";//Give the query
            Update upd(conn, queryStr.c_str());//Instantiating an update query
            upd.exec();//Execute the Update, simply return a bool
            cout << "Updated!" << endl;
        }
        catch (QueryErr err)
        {
            cout << err.errnum() << ": " << err.what() << endl;
        }
        
        //Select
        try
        {
            queryStr = "select* from student";
            Select sel(conn, queryStr.c_str());//
            sel.exec();//Execute the Delete, simply return a bool
            
            //output the result
            cout << left << setw(15) << "[id]";
            cout << left << setw(15) << "[name]";
            cout << left << setw(15) << "[age]";
            cout << left << setw(15) << "[gpa]" << endl;
            while (Tuple tuple = sel.fetchTuple())
            {
                cout << setw(15) << tuple["id"];
                cout << setw(15) << tuple["name"];
                cout << setw(15) << tuple["age"];
                cout << setw(15) << tuple["gpa"] << endl;
            }
        }
        catch (QueryErr err)
        {
            cout << err.errnum() << ": " << err.what() << endl;
        }
    }
    catch (QueryErr err)
    {
        cout << err.errnum() << ": " << err.what() << endl;
    }
    catch (ConnectionErr err)
    {
        cout << err.errnum() << ": " << err.what() << endl;
    }
    
    return 0;
}
