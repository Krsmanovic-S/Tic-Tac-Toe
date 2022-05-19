#pragma once

#include <memory>
#include "AI.hpp"
#include "button.hpp"

class Game 
{
public:
    // Constructor
    Game();

    // Functions
    void updateSFMLEvents();
    void update();
    void render();
    void run();

private:
    // Variables
    std::shared_ptr<sf::RenderWindow> window;
    sf::Event sfmlEvent;
    sf::Vector2i mousePos;

    std::shared_ptr<Board> field;
    std::shared_ptr<AI> computer;

    std::shared_ptr<Button> swap_sides;
    std::shared_ptr<Button> reset;
    std::shared_ptr<Button> pvp;

    // Initializers
    void initWindow();
    void initBoard();
    void initAI();
    void initButton();
};