#include "Game.hpp"

// Initializers
void Game::initWindow() {
    this->window = std::make_shared<sf::RenderWindow>(sf::VideoMode(750, 850), "Tic-Tac-Toe");
}

void Game::initBoard() {
    this->field = std::make_shared<Board>();
}

void Game::initAI() {
    this->computer = std::make_shared<AI>();
}

void Game::initButton() {
    using namespace sf;

    this->swap_sides = std::make_shared<Button>(Vector2f(15, 20), Vector2f(40, 40), "CHANGE SIDES");
    this->reset = std::make_shared<Button>(Vector2f(265, 20), Vector2f(340, 40), "RESET");
    this->pvp = std::make_shared<Button>(Vector2f(515, 20), Vector2f(565, 40), "VS PLAYER");
}

// Constructor
Game::Game() {
    initWindow();
    initBoard();
    initAI();
    initButton();
}

// Functions
void Game::updateSFMLEvents() {
    while(this->window->pollEvent(this->sfmlEvent))
    {
        if(this->sfmlEvent.type == sf::Event::Closed)
            this->window->close();

        if(this->sfmlEvent.type == sf::Event::MouseButtonPressed &&
           this->sfmlEvent.key.code == sf::Mouse::Left)
        {
            // Clicking on the buttons.
            if(this->mousePos.y < 100)
            {
                if(this->swap_sides->isMouseOver(sf::Vector2f(mousePos)))
                { 
                    this->field->set_player_symbol();
                    this->field->reset();
                }

                if(this->reset->isMouseOver(sf::Vector2f(mousePos)))
                    this->field->reset(); 

                if(this->pvp->isMouseOver(sf::Vector2f(mousePos)))
                    this->field->set_pvp();
            }
            // Clicking on the field itself.
            else if(!this->field->get_game_over() && this->field->get_player_turn())
                this->field->changeMatrix(this->mousePos);
        }
    }
}

void Game::update() {
    mousePos = sf::Mouse::getPosition(*window);

    // Update the button textures if mouse is over them.
    this->swap_sides->adjust_button_texture(sf::Vector2f(mousePos));
    this->reset->adjust_button_texture(sf::Vector2f(mousePos));
    this->pvp->adjust_button_texture(sf::Vector2f(mousePos));

    // Don't need to check for the winner until the  
    // 5th move, there can't be a winner before then.
    if(this->field->get_open_cells() < 6)
        this->field->checkWinner();

    if(!this->field->get_player_turn() && !this->field->get_game_over())
        this->computer->generateMove(*field);
}

void Game::render() {
    this->window->clear();

    this->field->drawBoard(*window);

    this->swap_sides->drawButton(*window);
    this->reset->drawButton(*window);  
    this->pvp->drawButton(*window); 

    this->window->display();
}

void Game::run() {
    while (this->window->isOpen())
    {
        this->updateSFMLEvents();
        this->update();
        this->render();
    }
}