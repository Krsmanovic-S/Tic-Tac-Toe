#pragma once

#include <SFML/Graphics.hpp>
#include "board.hpp"
#include "AI.hpp"

class Game 
{
private:
    // Variables
    sf::RenderWindow* window;
    sf::Event sfmlEvent;
    Board* field;
    AI* computer;
    sf::Vector2i mousePos;

    // Initializers
    void initWindow();
    void initBoard();
    void initAI();
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