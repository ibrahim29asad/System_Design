#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Implement a vending machine that handles product selection, payment, and inventory management.

/*
My Assumptions
You can set the amount of variety of snacks per 'aisle'
setpassword to adjust inventory per 'aisle' will not take money or you can use it to take out total cash, credit, or both
You can set the price
handles product selection 
can take cash or card - if card assume they have enough 
doesnt need refunds unless not taken and cash
*/

class aisles{
    
    public:
    string product_code; //sets the code this will be our unique identifier 

    double product_price; // cost
    string product_name; // tells us what in that specific one
    int product_quantity; // how many are in that aisle

    aisles(string code, string name, double price, int inventory){
        product_code =code;
        product_name =name;
        product_price =price;
        product_quantity = inventory;
    };

};


class Vending{
    
    private:
    string password = "password";

    public:
    int depth = 0; // how many snacks in each 
    // width and length to determine how many aisles
    int width = 0; 
    int length = 0;
    double cash = 0;
    double credit = 0;
    int total_rows = 0;
    unordered_map<string, aisles> rows; 

    Vending(int d, int l, int w){
        depth = d;
        length = l;
        width = w;
        total_rows = l*w;
    };

    void add_rows(string code, string name, double price, int inventory){
        if(rows.size() < total_rows){
            if(inventory > depth){
                cout<< "Cannot add that much you have to much quanity for the amount allowed, total maxium per row is " << depth;
            }
            else{

                if(rows.count(code) > 0){
                    cout << "The Code " << code << " already exists";
                }
                else{
                    aisles newRow = aisles(code, name, price, inventory);
                }
            }
        }
        else{
            cout << "cannot add anymore you have reached the maximum amount of rows";
        }
    }

    void take_cash(string pass){

        if(pass == password){
            cout << "You Have taken " << cash << "$ out \n";
            cash = 0;
        }
        else{
            cout << "incorrect password cannot take money out";
        }


    }

    void take_credit(string pass){

        if(pass == password){
            cout << "You Have taken " << cash << "$ out \n";
            credit = 0;
        }
        else{
            cout << "incorrect password cannot take money out";
        }


    }

    void take_all(string pass){

        if(pass == password){
            double total_money = cash + credit;
            cout << "You Have taken " << total_money << "$ out \n";
            credit = 0;
            cash = 0;
        }
        else{
            cout << "incorrect password cannot take money out";
        }


    }

    void selection(string code){
        
        if(rows.count(code) > 0){

            if(rows[code].product_quantity <= 0){
                cout<< "Sorry Product is out of stock";
            }
            else{
                cout << "You have chosen the snack " << rows[code].product_name << "\n"; 
                cout << "The price of the snack is " << rows[code].product_price << "\n";
                cout << "Press 1 for Card, Press 2 for Cash \n";
                int option;
                
                while (true) {
                    if (cin >> option) {
                        // Valid number
                        break;
                    } else {
                        // Not a valid number
                        cout << "Invalid input! Please input a valid integer." << endl;
                        
                        // Clear error flag
                        cin.clear();
                        
                        // Ignore the rest of the invalid input
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                if(option == 1){
                    cout << "Thank you for your purchase enjoy your snack \n";
                    credit = credit + rows[code].product_price;
                    rows[code].product_quantity--;
                }
                else if(option == 2){
                    double total_coins = 0;
                    bool continue_adding = true;
                    cout << "Please place your cash \n";
                    while (total_coins < rows[code].product_price && continue_adding){
                    
                    double coins;
                    while (true) {
                    if (cin >> coins) {
                        // Valid number
                        break;
                    } else {
                        // Not a valid number
                        cout << "Invalid input! Please input a valid amount." << endl;
                        
                        // Clear error flag
                        cin.clear();
                        
                        // Ignore the rest of the invalid input
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    }

                    total_coins = total_coins + coins;
                    if(total_coins < rows[code].product_price){
                        cout << "If you would like to quit please enter any number other then 1 \n";
                    int x;
                    while (true) {
                    if (cin >> x) {
                        // Valid number
                        break;
                    } else {
                        // Not a valid number
                        cout << "Invalid input! Please input a valid input." << endl;
                        
                        // Clear error flag
                        cin.clear();
                        
                        // Ignore the rest of the invalid input
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    }

                    if(x!=1){
                        cout << "Goodbye\n";
                        continue_adding = false;
                    }
                    

                    }


                    }
                    
                    cout << "Thank you for your purchase enjoy your snack \n";
                    cash = cash + rows[code].product_price;
                    rows[code].product_quantity--;
                    double refund = total_coins - rows[code].product_price;
                    cout << "Your total refund is " << refund << "$ \n";
                }
                else{
                    cout << "Invalid Choice Goodbye\n";
                }
            }



        }
        else{
            cout << "Code does not exist please try again";
        }

    }


    void change_name(string code, string nameChange){
        
        if(rows.count(code) > 0){
            rows[code].product_name = nameChange;
        }
    }

    void update_inv(string code, int inventory){
        
        if(rows.count(code) > 0){
            int newtotal = inventory + rows[code].product_quantity;
            if(newtotal >= 0 && newtotal <= depth){
                rows[code].product_quantity = newtotal;
            }
        }
    }


    void alter_price(string code, double price){
        
        if(rows.count(code) > 0){
            rows[code].product_price = price;   
        }
    }


};