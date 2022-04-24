#pragma once

#include "board.hpp"

struct AI 
{
public:
    // Constructor
    AI();

    // Functions
    void generateMove(Board& field);
};