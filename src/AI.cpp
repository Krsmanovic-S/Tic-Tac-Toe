#include "AI.h"

AI::AI() {
    srand(time(NULL));
};

void AI::generateMove(Board& field) {
    int i = rand() % 3;
    int j = rand() % 3;

    // We will see if we can place the tile first,
    // if not this function will be called again from main.
    if(field.get_field()[i][j] == 0) {
        field.set_field(i, j);
        field.set_player_turn();
    }
}