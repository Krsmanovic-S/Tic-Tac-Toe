#include "AI.hpp"

// Constructor
AI::AI() {
    this->bestMove.first = -1;
    this->bestMove.second = -1;
};

// Functions
bool AI::isMovesLeft(Board& board) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board.field[i][j] == 0)
                return true;
    return false;
}

void AI::generateMove(Board& board) {
    if(board.game_over == false && !board.is_player_turn)
    {
        this->bestMove = findBestMove(board);
        board.set_field(bestMove.first, bestMove.second);
    }
}

int AI::evaluate(Board& board) {
    // Checking rows for X or O victory.
    for(int row = 0; row < 3; row++)
    {
        if(board.field[row][0] == board.field[row][1] &&
           board.field[row][1] == board.field[row][2])
        {
            if (board.field[row][0] == 1)
                return 10;
            else if(board.field[row][0] == 2)
                return -10;
        }
    }
 
    // Checking columns for X or O victory.
    for(int col = 0; col < 3; col++)
    {
        if(board.field[0][col]==board.field[1][col] &&
           board.field[1][col]==board.field[2][col])
        {
            if(board.field[0][col]==1)
                return 10;
            else if(board.field[0][col]==2)
                return -10;
        }
    }
 
    // Checking diagonals for X or O victory.
    if(board.field[0][0] == board.field[1][1] && board.field[1][1] == board.field[2][2])
    {
        if(board.field[0][0] == 1)
            return 10;
        else if(board.field[0][0] == 2)
            return -10;
    }
    if(board.field[0][2] == board.field[1][1] && board.field[1][1] == board.field[2][0])
    {
        if(board.field[0][2] == 1)
            return 10;
        else if(board.field[0][2] == 2)
            return -10;
    }
 
    return 0;
}
 
int AI::minimax(Board& board, bool isMaximizer) {
    int bestScore, currentScore = evaluate(board);
 
    // If Maximizer/Minimizer has won the game return the score.
    if(currentScore == 10 || currentScore == -10)
        return currentScore;
 
    // No moves left and no winner means a tie.
    if(isMovesLeft(board) == false)
        return 0;
 
    if(isMaximizer)
    {
        bestScore = -1000;
 
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board.field[i][j] == 0)
                {
                    // Make the move for the Maximizer, call 
                    // minimax recursively and choose the 
                    // maximum value. After that undo the move.
                    board.field[i][j] = 1;
 
                    bestScore = std::max(bestScore, minimax(board, !isMaximizer));
 
                    board.field[i][j] = 0;
                }
            }
        }
        return bestScore;
    }
    else
    {
        bestScore = 1000;
 
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board.field[i][j] == 0)
                {
                    // Same logic as when it was the maximizer,
                    // only difference is we want the minimum
                    // score on the recursive call to minimax.
                    board.field[i][j] = 2;

                    bestScore = std::min(bestScore, minimax(board, !isMaximizer));
 
                    board.field[i][j] = 0;
                }
            }
        }
        return bestScore;
    }
}
 
std::pair<int, int> AI::findBestMove(Board& board) {
    int bestVal, moveVal;

    if(board.player_symbol == 1)
        bestVal = 1000;
    else
        bestVal = -1000;
 
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (board.field[i][j] == 0)
            {
                if(board.player_symbol == 1)
                    board.field[i][j] = 2;
                else
                    board.field[i][j] = 1;
 
                // Evaluation of this current move.
                if(board.player_symbol == 1)
                    moveVal = minimax(board, true);
                else
                    moveVal = minimax(board, false);
 
                board.field[i][j] = 0;
 
                // If the value of the current move is
                // more/less (depending on the sign the AI plays with) 
                // than the best value, then update the best move.
                if(board.player_symbol == 1 && moveVal < bestVal)
                {
                    this->bestMove.first = i;
                    this->bestMove.second = j;
                    bestVal = moveVal;
                }
                else if(board.player_symbol == 2 && moveVal > bestVal)
                {
                    this->bestMove.first = i;
                    this->bestMove.second = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove;
}