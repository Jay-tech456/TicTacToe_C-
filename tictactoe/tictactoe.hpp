//
//  tictactoe.hpp
//  tictactoe
//
//  Created by Manjesh Prasad on 12/28/20.
//

#ifndef tictactoe_hpp
#define tictactoe_hpp

#include <stdio.h>
#include <array>
using namespace std;

class game {
public:
    game();
    
    void print_Board(array<int, 9>, const int);
    bool checkForDuplicates(array<int, 9>, int, int);
    
    int make_move(array <int, 9>, const int, int move, int);
    bool winner(array <int, 9>);
    
private:
    array<int, 8> win;
};
#endif /* tictactoe_hpp */
