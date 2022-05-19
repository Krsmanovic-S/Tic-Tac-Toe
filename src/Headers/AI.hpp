#pragma once

#include "board.hpp"
#include <algorithm>

class AI 
{
public:
    // Constructor
    AI();

    // Functions
    bool isMovesLeft(Board& board);
    void generateMove(Board& field);
    int evaluate(Board& board);
    int minimax(Board& board, bool isMaximizer);
    std::pair<int, int> findBestMove(Board& board);
    
private:
    std::pair<int, int> bestMove;
};