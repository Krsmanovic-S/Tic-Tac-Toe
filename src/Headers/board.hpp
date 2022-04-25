#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Board
{
    typedef std::vector<std::vector<int>> matrix;
private:
    // Variables
    bool is_player_turn;
    bool is_player_x;
    bool game_over;

    sf::Texture texture_x;
    sf::Texture texture_o;
    sf::Sprite occupied_cell;
    sf::Color cell_color;

    matrix field;
    int open_cells;

    // Initializers
    void initField();
    void initPlayer();
    void initGameState();
    void initTextAndColor();
public:
    // Constructor
    Board();

    // Getters 
    matrix get_field();
    bool get_game_over();
    bool get_player_turn();
    int get_open_cells();

    // Setters
    void set_player_turn();
    void set_player_x();
    void set_field(int i, int j);
    void setCell(sf::RectangleShape& cell, sf::Vector2f cell_pos);

    // Functions
    void drawBoard(sf::RenderWindow& window);
    void changeMatrix(sf::Vector2i mousePos);
    void checkWinner();
    void reset();
};