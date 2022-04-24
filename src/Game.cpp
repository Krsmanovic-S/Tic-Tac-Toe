#include "Game.hpp"

// Initializers
void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(900, 900), "Tic-Tac-Toe");
}

void Game::initBoard() {
    this->field = new Board();
}

void Game::initAI() {
    this->computer = new AI();
}

// Constructor and Destructor
Game::Game() {
    initWindow();
    initBoard();
    initAI();
}

Game::~Game() {
    delete this->window;
    delete this->field;
    delete this->computer;
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
                if(this->field->get_game_over())
                    this->field->reset();
                    
                else if(this->field->get_player_turn())
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