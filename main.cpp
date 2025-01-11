#include<iostream>
#include<vector>
#include<iomanip>
#include "controller.h"
using namespace std;


enum class Denomination : int {
    THB_100 = 100,
    THB_20 = 20,
    THB_10 = 10,
    THB_5 = 5,
    THB_1 = 1
};
class Menu{
    public:
        vector<MenuItem> menu;
        vector<MenuItem> items;

        Menu(VendingMachineDB& db) {
            menu = {
                {"Coffee", 20.0, 10},
                {"Tea", 22.0, 10},
                {"Milk", 15.00, 10 },
                {"Soda", 14.00, 10},
                {"Smoothies", 24.00, 10}
            };

            for(const auto& item: menu){
                db.insertItem(item.name, item.price, item.stock);
            };

            items = db.getItems();
        }

        void display(){
            cout <<  setw(20) << "****Menu****" << endl;
            cout << setw(5) << "Code" << setw(20) << "Name" << setw(20) << "Price" << endl;
            for(auto item: items){
                cout << setw(5) << "Code" << setw(20) << item.name << setw(20) << fixed << setprecision(2) << item.price << endl;
            }
        }
};

int main(){
    string choice;
    cout << "*****Vending Machine*****" << endl;
    cout << "Please choose a login modes \n (1). User (Selling Mode) \n (2).Admin \n Your choice: ";
    cin >> choice;

    //database create
    VendingMachineDB db("vendingMachine.db", "67011158");
    db.createTable();
    Menu menu(db);

    if(choice == "1"){
        menu.display();

    }else if(choice == "2"){

    }else{
        cout << "Please enter a valid choice." << endl;
    }


    return 0;              
}