#pragma once

#include <SFML/Graphics.hpp>
#include <string>

// Need to do the button hovering-over / clicking correctly.

class Button
{
private:
    bool change_button_texture;

    sf::Texture mouse_over_button;
    sf::Texture button_texture;
    sf::Sprite button_sprite;

    sf::Font button_font;
    sf::Text button_text;

    // Initializers
    void initButtonSprite(sf::Vector2f button_pos);
    void initButtonText(sf::Vector2f text_pos, std::string text);
public:
    // Constructor
    Button(sf::Vector2f button_pos, sf::Vector2f text_pos, std::string text);

    // Functions
    void drawButton(sf::RenderWindow& window);
    void adjust_button_texture(sf::Vector2f mousePos);
    bool isMouseOver(sf::Vector2f mousePos);
};