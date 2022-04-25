#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
private:
    sf::Texture button_texture;
    sf::Sprite button_sprite;

    sf::Font button_font;
    sf::Text button_text;

    // Initializers
    void initButtonSprite(sf::Vector2f button_pos);
    void initButtonText(sf::Vector2f text_pos, std::string text);
public:
    // Constructor and Destructor
    Button(sf::Vector2f button_pos, sf::Vector2f text_pos, std::string text);

    // Functions
    void drawButton(sf::RenderWindow& window);
    bool isMouseOver(sf::Vector2f mousePos);
};