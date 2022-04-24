#include "AI.hpp"

// Constructor
AI::AI() {
    srand(time(NULL));
};

// Functions
void AI::generateMove(Board& field) {
    int i = rand() % 3;
    int j = rand() % 3;

    if(field.get_field()[i][j] == 0) {
        field.set_field(i, j);
        field.set_player_turn();
    }
}