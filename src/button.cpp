#include "button.hpp"

// Initializers
void Button::initButtonSprite(sf::Vector2f button_pos) {
    this->button_texture.loadFromFile("Resources/button.png");
    this->mouse_over_button.loadFromFile("Resources/hover_over.png");

    this->button_sprite.setTexture(button_texture);
    this->button_sprite.setScale(0.85, 0.85);
    this->button_sprite.setPosition(button_pos);
}

void Button::initButtonText(sf::Vector2f text_pos, std::string text) {
    this->button_font.loadFromFile("Resources/LEMONMILK-Regular.otf");
    this->button_text.setFont(button_font);

    this->button_text.setFillColor(sf::Color::Black);
    this->button_text.setCharacterSize(20);

    this->button_text.setPosition(text_pos);
    this->button_text.setString(text);
}

// Constructor
Button::Button(sf::Vector2f button_pos, sf::Vector2f text_pos, std::string text) {
    initButtonSprite(button_pos);
    initButtonText(text_pos, text);
}

// Functions
bool Button::isMouseOver(sf::Vector2f mousePos) {
    if(this->button_sprite.getGlobalBounds().contains(mousePos.x, mousePos.y))
        return true;
    else
        return false;
}

void Button::drawButton(sf::RenderWindow& window) {
    window.draw(this->button_sprite);
    window.draw(this->button_text);
}

void Button::adjust_button_texture(sf::Vector2f mousePos) {
    if(isMouseOver(mousePos))
        this->button_sprite.setTexture(mouse_over_button);
    else
        this->button_sprite.setTexture(button_texture);
}