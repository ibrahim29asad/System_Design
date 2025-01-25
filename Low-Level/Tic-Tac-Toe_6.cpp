#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class tic_tac_toe{

vector<vector<string>> Board;
// could put a set but it adds more space used when it is not needed
int move = 0; // will only check for wins once the 5th move and makes sure to keep 9 moves



tic_tac_toe(){
    Board = vector<vector<string>>(3, vector<string>(3, "-")); // creates your instance of the board
}

// postion
bool place(int position, string marker){
    
    int postionX = position/3;
    int positionY = position%3;
    if(Board[postionX][positionY] == "-"){
        Board[postionX][positionY] = marker;
        cout << "The " << marker <<" placed at the position: " << position <<  endl;
        move++;
        return true;
    }
    cout << "The " << marker <<" cannot be placed at the position: " << position <<  endl;

    
    return false;
    

}


void displayBoard(){
    cout << "The Current Board and the placments\n";
    cout << "Player 1 is X & Player 2 is O\n\n";
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << Board[i][j] << "  "; 

        }
        cout << "        ";
        int postionAdjust = i * 3;
        for(int j = 0; j < 3; j++){
            cout << postionAdjust + j << "  "; 
        }
        cout << endl;

    }

}


bool checkWinner(string marker){
    // checks each row and coloumn simmilar way how you did it for sudoko use one for loop to do both operations
    for(int i = 0; i < 3; i++){
        if(Board[i][0] == marker && Board[i][1] == marker && Board[i][2] == marker){
            return true;
        }

        if(Board[0][i] == marker && Board[1][i] == marker && Board[2][i] == marker){
            return true;
        }
    }

    //checks diagonals
    if (Board[0][0] == marker && Board[1][1] == marker && Board[2][2] == marker){
        return true;
    }
    
    if (Board[0][2] == marker && Board[1][1] == marker && Board[2][0] == marker){
        return true;
    }
    return false;

}



int start_game(){

   
    displayBoard();
    bool noWinner = false;
    int currentPlayer = 1; // first will be X or O, for this instance i just said X
    string marker = "X";
    
    while(!noWinner){
        displayBoard();
        cout << "Player " << currentPlayer << " please place your marker";
        int pos;
        while (true) {
            if (cin >> pos && pos >= 0 && pos < 9 && place(pos, marker)) { // Valid number
                break;
            } else {
            
            cout << "Invalid input! Please input a valid integer from 0-8." << endl;    
            cin.clear();
                        
            // Ignore the rest of the invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        }


        if(move > 4 ){
            noWinner= checkWinner(marker);
        }
        else if(move == 9){
            cout << "\n -------it is a draw :(-------\n";
            noWinner = true;
        }

        if(currentPlayer == 1){
            currentPlayer = 2;
            marker = "O";
        }
        else{
            currentPlayer = 1;
            marker = "X";
        }

    }





    return 0;
}

};




