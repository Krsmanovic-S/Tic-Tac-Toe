#include "AI.hpp"

// Constructor
AI::AI() {
    srand(time(NULL));
};

// Functions
void AI::generateMove(Board& field) {
    int i, j;

    while(!field.get_player_turn())
    {
        i = rand() % 3;
        j = rand() % 3;
        if(field.get_field()[i][j] == 0) 
        {
            field.set_field(i, j);
            field.set_player_turn();
        }
    }
}