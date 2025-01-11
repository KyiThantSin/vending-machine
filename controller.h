#include <sqlite3.h>
#include <string>
using namespace std;

class VendingMachineDB
{
private:
    sqlite3 *db;
    string student_id;
    string db_name;

public:
    VendingMachineDB(string name, string id) : db_name(name), student_id(id)
    {
        if (sqlite3_open(db_name.c_str(), &db) != SQLITE_OK)
        {
            throw runtime_error("Error opening database: " + string(sqlite3_errmsg(db)));
        }
    };

    // clean up (close db )
    ~VendingMachineDB()
    {
        if (db)
        {
            sqlite3_close(db);
        }
    };

    void createTable()
    {
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

        char *errMessage = nullptr;
        int res = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMessage);
        if (res != SQLITE_OK)
        {
            cerr << "SQL Error: " << errMessage << endl;
        }
    };

    void insertItem(const string name, double price, int stock)
    {
        string table_name = "stock_" + student_id;
        string sql = "INSERT INTO " + table_name + "(name, price, stock) VALUES (?,?,?);";

        sqlite3_stmt *stmt; // where the prepared sql is stored
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK)
        {
            sqlite3_bind_text(stmt, 1, name.c_str(), -1, SQLITE_STATIC);
            sqlite3_bind_double(stmt, 2, price);
            sqlite3_bind_int(stmt, 3, stock);

            if (sqlite3_step(stmt) != SQLITE_DONE)
            {
                std::cerr << "Error inserting item.\n";
            }
            sqlite3_finalize(stmt);
        }
        else
        {
            std::cerr << "Error preparing statement.\n";
        }
    }
};
