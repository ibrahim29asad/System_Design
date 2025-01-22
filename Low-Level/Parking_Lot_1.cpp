
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// Design a parking lot system with different vehicle types (car, bike, truck) and pricing.

/*
safe to assume that say a truck or a SUV can take the same space
spaces are designated
payment is different per type
and needs to handle when cars leave and enter
assume to let user decide type of spaces (small medium or large spaces)
*/
class vehicle{
    public:

    string name;
    int cost;
    string space;
    
    vehicle(string vehicle_name, int vehicle_cost, string vehicle_space){
        name = vehicle_name;
        cost = vehicle_cost;
        space = vehicle_space;
    }
};

class ParkingLot{

public:
unordered_map<string, int> spaces_avalible;
unordered_map<string, int> spaces_occupied;
unordered_map<string, int> quantity; // this will tell me the amount of vehicles i have and give me the details on
unordered_map<string, vehicle> vehicle_types; // type of vehicles
int total = 0; // this will showcase the profit

void SetSpaces(string size, int quantity){
    if(spaces_avalible.count(size) <= 0){
        spaces_avalible[size] = quantity;
        spaces_occupied[size] = 0; // spaces occupied only needs to be updated once since its when you first register it
    }
    else if(spaces_avalible.count(size) > 0 && spaces_avalible[size]+quantity > 0 ) { //cant have negative spaces
        spaces_avalible[size] = spaces_avalible[size] + quantity;
    }
}

void Set_Vehicle(string vehicle_name, int vehicle_cost, string vehicle_space){  // internal system to allow for vehicle prices and spaces to be set
    vehicle newVehicle = vehicle( vehicle_name,  vehicle_cost,  vehicle_space);        
    if(vehicle_types.count(vehicle_name) <= 0){
        // vehicle_names
        vehicle_types[vehicle_name] = newVehicle;
        quantity[vehicle_name] = 0;
    }
}


void Add_Vehicle(string vehicle_name){
    
    if(vehicle_types.count(vehicle_name) > 0){
        // vehicle_names
        vehicle Vehicle = vehicle_types[vehicle_name];
        if(spaces_avalible[Vehicle.space] > spaces_occupied[Vehicle.space]){
            spaces_occupied[Vehicle.space]++;
            total += Vehicle.cost;
            quantity[vehicle_name]++;
        }
        else{
            cout <<  "Not Enough Space" ;
        }
    }
    else{
        cout << "That Vehical is not supported here";
    }
}

void Vehicle_left(string vehicle_name){
    
    if(vehicle_types.count(vehicle_name) > 0){
        // vehicle_names
        if(quantity[vehicle_name] > 0 ){
            vehicle Vehicle = vehicle_types[vehicle_name];
            quantity[vehicle_name]--;
            spaces_occupied[Vehicle.space]--;

        }
        else{
            cout <<  "There was no" << vehicle_name;
        }
    }
    else{
        cout << "That Vehical was not supported here";
    }
}
};

