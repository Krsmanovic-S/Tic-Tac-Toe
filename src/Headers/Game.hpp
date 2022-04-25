#pragma once

#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "AI.hpp"
#include "button.hpp"

class Game 
{
private:
    // Variables
    sf::RenderWindow* window;
    sf::Event sfmlEvent;
    sf::Vector2i mousePos;

    Board* field;
    AI* computer;

    Button* swap_sides;
    Button* reset;
    Button* player_vs_player;

    // Initializers
    void initWindow();
    void initBoard();
    void initAI();
    void initButton();
public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Functions
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};