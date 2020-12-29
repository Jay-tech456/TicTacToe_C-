//
//  tictactoe.cpp
//  tictactoe
//
//  Created by Manjesh Prasad on 12/28/20.
//

#include "tictactoe.hpp"
#include <array>
#include <iostream>
using namespace std;

game::game()
{
    win = {0};
}

/*  **************** Printint the board *************** */
void game::print_Board(array<int, 9> board, const int len)
{
    for (int count = 0; count < len; count++) {
        
        if(count == 3 || count == 6) {
            cout <<  "\n- - - - - - "<< endl;
        }
        
        if ((count + 1) % 3 == 0) {                     // the curly braces are here to prevent the dangling
            if(board[count] == 0) {                     // else issue
                cout << "X  ";
            }
            else if (board[count] == 10) {
                cout << "O  ";
            }
            else {
                cout << board[count] << " ";
            }
        }
        else {
            if(board[count] == 0) {
                cout << "X ";
            }
            else if (board[count] == 10) {
                cout << "O ";
            }
            else {
            cout << board[count] << " ";
            }
            cout << " | ";
        }
}

    cout << endl << endl << endl;
    return;
}

// ******************** Checking for duplicate values ********************
bool game::checkForDuplicates(array<int, 9> board, int move, int player)
{
    if(board[move - 1] == 0 || board[move-1] == 10) {                    // if board already has 0 or 10, then the move is a duplicate
           return true;
    }
    else {
        return false;
    }
    
}

int game::make_move(array <int, 9> board, const int len, int move, int player)
{
    cout << "\nPlease enter a move " << endl;
    cin >> move;

    while(checkForDuplicates(board, move, player)) {
        cout << "\nPlease enter a move: ";
        cin >> move;
        cout << " ----------------- " << endl << endl;
        
    }
    return move;
}


bool game::winner(array <int, 9> board)     // Checks for the winners
{
        
            // Virtically
    win[0] = board[0] + board[3] + board[6];
    win[1] = board[1] + board[4] + board[7];
    win[2] = board[2] + board[5] + board[8];

            // Horizontally
    win[3] = board[0] + board[1] + board[2];
    win[4] = board[3] + board[4] + board[5];
    win[5] = board[6] + board[7] + board[8];

            // Diagonally
    win[6] = board[0] + board[4] + board[9];
    win[7] = board[2] + board[4] + board[6];

            // Iterate through the entire board to see if there is a winner
    for(auto& count : win) {
        if(count == 0 || count == 30) {
            return true;
        }
    }

    // if it iterates through the loop without returning true, no winners
    return false;
}
