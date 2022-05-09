#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Board
{
    typedef std::vector<std::vector<int>> matrix;
private:
    // Variables
    bool is_player_turn;
    bool game_over;
    bool player_vs_player;

    sf::Texture texture_x;
    sf::Texture texture_o;
    sf::Sprite occupied_cell;
    sf::Color cell_color;

    int player_symbol;
    int open_cells;
    
    matrix field;
    std::vector<std::pair<int, int>> winningIndex;

    // Initializers
    void initField();
    void initPlayer();
    void initGameState();
    void initTextAndColor();

    // Friends
    friend class AI;
public:
    // Constructor
    Board();

    // Getters 
    bool get_game_over();
    bool get_player_turn();

    int get_player_symbol();
    int get_open_cells();

    // Setters
    void set_player_turn();
    void set_player_symbol();
    void set_pvp();
    void set_field(int i, int j);
    void set_cell(sf::RectangleShape& cell, sf::Vector2f cell_pos);

    // Functions
    void drawBoard(sf::RenderWindow& window);
    void changeMatrix(sf::Vector2i mousePos);
    void checkWinner();
    void reset();
};