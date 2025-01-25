#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;


//Design a basic calculator supporting addition, subtraction, multiplication, and division.


class Calculator{
// need to allow integer numbers so use either floats or doubles
    double addition(double a, double b){
        cout << "The Sum is: " << a+b << endl;
        return a+b;
    }
    
    double subtraction(double a, double b){
        cout << "The Difference is: " << a-b << endl;
        return a-b;
    }

    double multiply(double a, double b){
        cout << "The Product is: " << a*b << endl;
        return a*b;
    }

    double division(double a, double b) {
    try {
        if (b == 0) {
            throw invalid_argument("Cannot divide by zero.");
        }

        double res = a / b;
        cout << "The quotient is: " << res << endl;
        return res;
    } catch (const invalid_argument &e) {
        cout << "Error: " << e.what() << endl;
        return 0; // Return a default value or handle as needed
    }
    }


    void Operation(){        
        cout << "Select an operation from  *,/,+, or -" << endl;    
        string input;
        while (true) {
            if (cin >> input && (input == "*" || input == "/" || input == "+" || input == "-") ) { // Valid number
                break;
            } else {
            
            cout << "Invalid operation! Please input a valid opertation from *,/,+, or -" << endl;    
            cin.clear();
                        
            // Ignore the rest of the invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        }

        double a, b;

        cout << "Select an operation from  *,/,+, or -" << endl;    
        while (true) {
            if (cin >> a && cin >> b) { // Valid number
                break;
            } else {
            
            cout << "Invalid Input! please enter a valid number" << endl;    
            cin.clear();
                        
            // Ignore the rest of the invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        }

        if(input == "*"){
            double c = multiply(a,b);
        }
        else if(input == "+"){
            double c = addition(a,b);
        }
        else if(input == "-"){
            double c = subtraction(a,b);
        }
        else if(input == "/"){
            double c = division(a,b);
            
        }

    };



};




