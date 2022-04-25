#include "Game.hpp"

// Initializers
void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(750, 850), "Tic-Tac-Toe");
}

void Game::initBoard() {
    this->field = new Board();
}

void Game::initAI() {
    this->computer = new AI();
}

void Game::initButton() {
    this->swap_sides = new Button(sf::Vector2f(15, 20), sf::Vector2f(40, 40), "CHANGE SIDES");
    this->reset = new Button(sf::Vector2f(265, 20), sf::Vector2f(340, 40), "RESET");
    this->player_vs_player = new Button(sf::Vector2f(515, 20), sf::Vector2f(565, 40), "VS PLAYER");
}

// Constructor and Destructor
Game::Game() {
    initWindow();
    initBoard();
    initAI();
    initButton();
}

Game::~Game() {
    delete this->window;
    delete this->field;
    delete this->computer;

    delete this->swap_sides;
    delete this->reset;
    delete this->player_vs_player;
}

// Functions
void Game::updateSFMLEvents() {
    while(this->window->pollEvent(this->sfmlEvent))
    {
        if(this->sfmlEvent.type == sf::Event::Closed)
            this->window->close();

        if(this->sfmlEvent.type == sf::Event::MouseButtonPressed)
        {
            if(this->sfmlEvent.key.code == sf::Mouse::Left)
            {
                if(this->reset->isMouseOver(sf::Vector2f(mousePos)))
                    this->field->reset(); 

                if(this->swap_sides->isMouseOver(sf::Vector2f(mousePos)))
                {
                    this->field->set_player_x();
                    this->field->reset();
                }

                if(!this->field->get_game_over() && this->field->get_player_turn())
                    this->field->changeMatrix(this->mousePos);
            }
        }
    }
}

void Game::update() {
    mousePos = sf::Mouse::getPosition(*window);

    this->field->checkWinner();

    if(!this->field->get_player_turn() && !this->field->get_game_over())
        this->computer->generateMove(*field);
}

void Game::render() {
    this->window->clear();

    this->field->drawBoard(*window);

    this->swap_sides->drawButton(*window);
    this->reset->drawButton(*window);  
    this->player_vs_player->drawButton(*window); 

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