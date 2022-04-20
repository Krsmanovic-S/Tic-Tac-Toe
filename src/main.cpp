#include "board.h"
#include "AI.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(900, 900), "Tic-Tac-Toe");
    sf::Event e;

    Board field;
    AI computer;

    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
                window.close();

            if(e.type == sf::Event::MouseButtonPressed)
            {
                if(e.key.code == sf::Mouse::Left)
                {
                    if(field.get_game_over())
                        field.reset();
                        
                    else if(field.get_player_turn())
                        field.changeMatrix(mousePos);
                }
            }
        }
        window.clear();

        field.checkWinner();
        field.drawBoard(window);

        if(!field.get_player_turn() && !field.get_game_over())
            computer.generateMove(field);

        window.display();
    }

    return 0;
}