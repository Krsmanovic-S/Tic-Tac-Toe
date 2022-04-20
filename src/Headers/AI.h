#pragma once

#include "board.h"

struct AI 
{
public:
    AI();

    void generateMove(Board& field);
};