#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;


enum class Denomination : int {
    THB_100 = 100,
    THB_20 = 20,
    THB_10 = 10,
    THB_5 = 5,
    THB_1 = 1
};
struct MenuItem{
    string code;
    string name;
    double price;
    int stock;
};
class Menu{
    public:
        vector<MenuItem> menu;

        Menu() : menu({
            {"011","Coffee", 20.0, 10},
            {"012","Tea", 22.0, 10},
            {"013","Milk", 15.00, 10 },
            {"014","Soda", 14.00, 10},
            {"015","Smoothies", 24.00, 10}
        }){}

        void display(){
            cout << "****Menu****" << endl;
            cout << setw(5) << "Code" << setw(20) << "Name" << setw(20) << "Price" << endl;
            for(auto item: menu){
                cout << setw(5) << item.code << setw(20) << item.name << setw(20) << fixed << setprecision(2) << item.price << endl;
            }
        }
};

int main(){
    string choice;
    cout << "*****Vending Machine*****" << endl;
    cout << "Please choose a login modes \n (1). User (Selling Mode) \n (2).Admin \n Your choice: ";
    cin >> choice;

    if(choice == "1"){
        Menu menu;
        menu.display();

    }else if(choice == "2"){

    }else{
        cout << "Please enter a valid choice." << endl;
    }


    return 0;              
}