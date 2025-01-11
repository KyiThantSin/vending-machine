#include<sqlite3.h>
#include<string>
using namespace std;

class VendingMachineDB{
    private:
        sqlite3* db;
        string student_id;
        string db_name;
    public:
        VendingMachineDB(string name, string id) : db_name(name),student_id(id) {
            if(sqlite3_open(db_name.c_str(), &db) != SQLITE_OK ){
                throw runtime_error("Error opening database: " + string(sqlite3_errmsg(db)));
            }
        };

        // clean up (close db )
        ~VendingMachineDB(){
            if(db){
                sqlite3_close(db);
            }
        };
};