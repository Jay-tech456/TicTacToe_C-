//
//  main.cpp
//  tic_Tac_Toe
//
//  Created by Manjesh Prasad on 12/28/20.
//

#include <iostream>
#include "tictactoe.hpp"
#include <array>
using namespace std;


    // Where the main begins
int main() {
    game tictactoe;             // class object
    
    const int SIZE = 9;
    int totalMovesLeft = 9;
    
    int player1 = 0;           // player 1 will be 0
    int player2 = 10;           // player 2 will be 10
    
    int move = 0;           // to mark the board
    
    bool win = false;
    
    array<int, SIZE> board{ 1, 2, 3, 4, 5, 6, 7, 8, 9};     // Declare the board
    
        while(totalMovesLeft != 0 && win == false) {
            tictactoe.print_Board(board, SIZE);
            
                
                    // Player 1's moves
            move = tictactoe.make_move(board,  SIZE, move, player1);
            board[move - 1] = player1;                              // mark the board
            totalMovesLeft -= 1;
            win = tictactoe.winner(board);                          // update win
            tictactoe.print_Board(board, SIZE);                     // print the board
            
            
                    
            if(totalMovesLeft == 0 || win == true) {
                break;
            }
            
            // Player 2's move
            move = tictactoe.make_move(board,  SIZE, move, player2);
            board[move - 1] = player2;                         // mark the board
            totalMovesLeft -= 1;                            // decrease the total moves by 1
            win = tictactoe.winner(board);
            
            tictactoe.print_Board(board, SIZE);
        }
    
    if(totalMovesLeft == 0) {
        cout << "No more Moves " << endl;
    }
    
    array<int, 8> winner;
    winner[0] = board[0] + board[3] + board[6];
    winner[1] = board[1] + board[4] + board[7];
    winner[2] = board[2] + board[5] + board[8];
    
    winner[3] = board[0] + board[1] + board[2];
    winner[4] = board[3] + board[4] + board[5];
    winner[5] = board[6] + board[7] + board[8];
    
    winner[6] = board[0] + board[4] + board[9];
    winner[7] = board[2] + board[4] + board[6];
    
    for(auto& count : winner) {
        if(count == 0) {
            cout << "Player 1 wins " << endl;
            break;
        }
        else if(count == 30) {
            cout << "Player 2 wins " << endl;
            break;
        }

    }
    
    return 0;
}
