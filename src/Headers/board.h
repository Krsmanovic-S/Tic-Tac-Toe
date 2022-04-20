#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Board
{
private:
    bool is_player_turn;
    bool game_over;

    sf::Text winning_text;
    sf::Font text_font;

    sf::Texture texture_x;
    sf::Texture texture_o;
    sf::Sprite occupied_cell;

    std::vector<std::vector<int>> field = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
public:
    Board();

    void drawBoard(sf::RenderWindow& window);

    std::vector<std::vector<int>> get_field();

    bool get_game_over();
    bool get_player_turn();

    void set_player_turn();
    void set_field(int i, int j);

    void changeMatrix(sf::Vector2i mousePos);

    void checkWinner();

    void reset();
};