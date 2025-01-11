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

        void createTable(){
            string table_name = "stock_" + student_id;
            string sql = "CREATE TABLE IF NOT EXISTS " + table_name + 
                R"(
                    ( 
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    name TEXT NOT NULL,
                    price REAL NOT NULL,
                    stock INTEGER NOT NULL
                    )
                )";
            
            char* errMessage = nullptr;
            int res = sqlite3_exec(db, sql.c_str(), nullptr, nullptr , &errMessage );
            if(res != SQLITE_OK){
                cerr << "SQL Error: " << errMessage << endl;
            }
        };  
};

