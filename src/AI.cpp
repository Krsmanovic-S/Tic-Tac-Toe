#include "AI.hpp"

// Constructor
AI::AI() {
    srand(time(NULL));
};

// Functions
void AI::generateMove(Board& board) {
    int i, j;

    while(!board.get_player_turn())
    {
        i = rand() % 3;
        j = rand() % 3;
        if(board.field[i][j] == 0) 
        {
            board.set_field(i, j);
            board.set_player_turn();
        }
    }
}