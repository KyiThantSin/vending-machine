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
    private:
        vector<MenuItem> items;
    public:
        Menu(VendingMachineDB& db) {
            vector<MenuItem>  menu = {
                {0,"Coffee", 20.0, 10},
                {0,"Tea", 22.0, 10},
                {0,"Milk", 15.00, 10 },
                {0,"Soda", 14.00, 10},
                {0,"Smoothies", 24.00, 10}
            };

            for(const auto& item: menu){
                db.insertItem(item.name, item.price, item.stock);
            };

            items = db.getItems();
        }

        void display(){
            cout <<  setw(20) << "****Menu****" << endl;
            cout << setw(5) << "Code" << setw(20) << "Name" << setw(20) << "Price" << endl;
            if (items.empty()) {
                cout << "No items available in the menu." << endl;
                return;
            }
            for(auto item: items){
                cout << setw(5) << item.id << setw(20) << item.name << setw(20) << fixed << setprecision(2) << item.price << endl;
            }
        }
};

class User{
      private:
        int slected_code;
      public:
        User(VendingMachineDB& db){
            cout << "Enter a code number to choose the item: ";
            cin >> slected_code;
            cout << endl;

            MenuItem item = db.getItemById(slected_code);

            if(item.stock <= 0){
                cout << "Sorry, Your selected item " << item.name << " is OUT OF STOCK." << endl;
                return;
            }
            cout << "Your selected Item: " << endl;
            cout << setw(5) << "Code" << setw(20) << "Name" << setw(20) << "Price" << endl;
            cout << setw(5) << item.id << setw(20) << item.name << setw(20) << item.price << endl;
        }; 
};

int main(){
    string choice;
    cout << "*****Vending Machine*****" << endl;
    cout << "Please choose a login modes \n (1).User (Selling Mode) \n (2).Admin \n Your choice: ";
    cin >> choice;

    //database create
    VendingMachineDB db("vendingMachine.db", "67011158");
    db.createTable();
    Menu menu(db);

    if(choice == "1"){
        menu.display();
        User user(db);

    }else if(choice == "2"){

    }else{
        cout << "Please enter a valid choice." << endl;
    }


    return 0;              
}