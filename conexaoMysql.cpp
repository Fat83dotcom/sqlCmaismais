#include <iostream>

#include  <mysql_connection.h>
#include  <mysql_driver.h>
#include  <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "confidencial.h"

using std::cout;
using std::cin;
using std::stringstream;
using std::endl;
using std::getline;

int main(void){
    cout << "rodou" << std::endl;
    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::PreparedStatement *prep_stmt;
        
        cout << "connecting to mysql server....";
        driver = get_driver_instance();
        con = driver->connect(host, usuario, senha);  
        cout << "connected" << endl;

        con->setSchema("teste");
        prep_stmt = con->prepareStatement("INSERT INTO cliente(nome) VALUES(?)");
        
        string nome;
    
        cout << "Insira 10 nomes: ";
        for(int i = 0; i < 10; i++) {
            getline(cin, nome);
            prep_stmt->setString(1,nome);
            prep_stmt->execute();
        }
        cout << "done" << endl;
        delete prep_stmt;
        delete con;

    } catch (sql::SQLException &e) {    
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

  cout << endl;
    return 0;
}
