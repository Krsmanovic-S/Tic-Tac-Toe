#include "board.hpp"
#include <iostream>

// Initializers
void Board::initField() {
    this->field = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    this->open_cells = 9;
}

void Board::initPlayer() {
    this->is_player_turn = true;
    this->player_vs_player = false;
    this->player_symbol = 1;
}

void Board::initGameState() {
    this->game_over = false;
}

void Board::initTextAndColor() {
    // Textures for the X's and O's.
    this->texture_x.loadFromFile("Resources/x.png");
    this->texture_o.loadFromFile("Resources/o.png");

    // Default cell color.
    this->cell_color = sf::Color(212, 220, 228);
}

// Constructor
Board::Board()
{
    initField();
    initPlayer();
    initGameState();
    initTextAndColor();
};

// Getters 
bool Board::get_game_over() {
    return this->game_over;
}

bool Board::get_player_turn() {
    return this->is_player_turn;
}

int Board::get_player_symbol() {
    return this->player_symbol;
}

int Board::get_open_cells() {
    return this->open_cells;
}

// Setters
void Board::set_player_turn() {
    this->is_player_turn = true;
}

void Board::set_player_symbol() {
    if(player_symbol == 1)
        this->player_symbol = 2;
    else
        this->player_symbol = 1;
}

void Board::set_pvp() {
    if(!this->player_vs_player)
        this->player_vs_player = true;
    else
    {
        this->player_symbol = 1;
        this->player_vs_player = false;
    }
}

void Board::set_field(int i, int j) {
    if(this->player_symbol == 1)
        this->field[i][j] = 2;
    else
        this->field[i][j] = 1;

    this->is_player_turn = true;
    this->open_cells--;
}

void Board::setCell(sf::RectangleShape& cell, sf::Vector2f cell_pos) {
    cell.setFillColor(cell_color);
    cell.setOutlineColor(sf::Color(0, 0, 0));
    cell.setOutlineThickness(2.5f);
    cell.setPosition(cell_pos);
}

// Functions
void Board::drawBoard(sf::RenderWindow& window) {
    sf::Vector2f cell_position;
    sf::RectangleShape cell;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cell = sf::RectangleShape(sf::Vector2f(295, 295));
            cell_position = sf::Vector2f(i * 250, j * 250 + 100);
            setCell(cell, cell_position);

            window.draw(cell);

            if(field[i][j] == 1)
            {
                occupied_cell.setTexture(texture_x);
                occupied_cell.setPosition(i * 250, j * 250 + 100);
                window.draw(occupied_cell);              
            }
            else if(field[i][j] == 2)
            {
                occupied_cell.setTexture(texture_o);
                occupied_cell.setPosition(i * 250, j * 250 + 100);
                window.draw(occupied_cell);                     
            }
        }
    }
}

void Board::changeMatrix(sf::Vector2i mousePos) {
    int coordX, coordY;

    coordX = mousePos.x / 250;
    coordY = (mousePos.y + 100) / 350;

    // We can only play if it is our turn and we clicked on a valid cell.
    if(is_player_turn && this->field[coordX][coordY] == 0)
    {
        this->field[coordX][coordY] = this->player_symbol;

        if(!this->player_vs_player)
            is_player_turn = false;
        else
            set_player_symbol();

        this->open_cells--;
    }
}

void Board::checkWinner() {
    // Check rows for a winner.
    for(int i = 0; i < 3; i++)
    {
        if(field[i][0] == 1 && field[i][1] == 1 && field[i][2] == 1)
        {
            this->game_over = true;
            return;
        }
        else if(field[i][0] == 2 && field[i][1] == 2 && field[i][2] == 2)
        {
            this->game_over = true;
            return;
        }
    }

    // Check columns for a winner.
    for(int j = 0; j < 3; j++)
    {
        if(field[0][j] == 1 && field[1][j] == 1 && field[2][j] == 1)
        {
            this->game_over = true;
            return;
        }
        else if(field[0][j] == 2 && field[1][j] == 2 && field[2][j] == 2)
        {
            this->game_over = true;
            return;
        }
    }

    // Check the two diagonals as well.
    if((field[0][0] == 1 && field[1][1] == 1 && field[2][2] == 1) ||
       (field[2][0] == 1 && field[1][1] == 1 && field[0][2] == 1))
    {
        this->game_over = true;
        return;
    }
    if((field[0][0] == 2 && field[1][1] == 2 && field[2][2] == 2) ||
       (field[2][0] == 2 && field[1][1] == 2 && field[0][2] == 2))
    {
        this->game_over = true;
        return;
    }

    // Check for a draw.
    if(this->open_cells == 0)
        this->game_over = true;        
}

void Board::reset() {
    this->field = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    this->game_over = false;
    this->open_cells = 9;

    if(!this->player_vs_player)
    {
        if(this->player_symbol == 1)
            this->is_player_turn = true;
        else
            this->is_player_turn = false;
    }
    else
    {
        this->is_player_turn = true;
        if(this->player_symbol == 2)
            set_player_symbol();
    }
}