#include <iostream>

#include  <mysql_connection.h>
#include  <mysql_driver.h>
#include  <cppconn/exception.h>
#include "confidencial.h"
#include "classes.h"

using std::cout;
using std::endl;

int main(void){
    cout << "rodou" << std::endl;
    try {
        sql::Driver *driver;
        sql::Connection *con;
        
        cout << "connecting to mysql server....";
        driver = get_driver_instance();
        con = driver->connect(host, usuario, senha);  
        cout << "connected" << endl;

        delete con;

    } catch (sql::SQLException &e) {    
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

  cout << endl;
    return 0;
}
