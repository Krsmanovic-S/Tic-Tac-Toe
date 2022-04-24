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

    sf::Text winning_text;
    sf::Font text_font;

    sf::Texture texture_x;
    sf::Texture texture_o;
    sf::Sprite occupied_cell;

    matrix field;

    // Initializers
    void initField();
    void initPlayer();
    void initGameState();
    void initText();
public:
    // Constructor
    Board();

    // Getters 
    matrix get_field();
    bool get_game_over();
    bool get_player_turn();

    // Setters
    void set_player_turn();
    void set_field(int i, int j);

    // Functions
    void drawBoard(sf::RenderWindow& window);
    void changeMatrix(sf::Vector2i mousePos);
    void checkWinner();
    void reset();
};