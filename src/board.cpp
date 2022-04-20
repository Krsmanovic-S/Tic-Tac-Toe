#include "board.h"

// Default Constructor
Board::Board()
{
    // Textures for the X's and O's.
    texture_x.loadFromFile("Resources/x.png");
    texture_o.loadFromFile("Resources/o.png");
    occupied_cell.setScale(sf::Vector2f(1.3,1.3));

    // Setting up the font/text for winning/drawing/losing.
    text_font.loadFromFile("Resources/LEMONMILK-Regular.otf");

    winning_text.setFont(text_font);
    winning_text.setFillColor(sf::Color::Red);
    winning_text.setPosition(sf::Vector2f(320, 390));
    winning_text.setCharacterSize(50);

    game_over = false;
    is_player_turn = true;
};

// Setters & Getters
std::vector<std::vector<int>> Board::get_field() {
    return this->field;
}
bool Board::get_game_over() {
    return this->game_over;
}
bool Board::get_player_turn() {
    return this->is_player_turn;
}

void Board::set_player_turn() {
    this->is_player_turn = true;
}
void Board::set_field(int i, int j) {
    this->field[i][j] = 2;
}

// Main drawing function, will draw everything
// like the grid, X and O sprites, and text.
void Board::drawBoard(sf::RenderWindow& window) {
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(field[i][j] == 0)
            {
                sf::RectangleShape cell = sf::RectangleShape(sf::Vector2f(295, 295));
                cell.setFillColor(sf::Color(80, 90, 100));
                cell.setOutlineColor(sf::Color(0, 0, 0));
                cell.setOutlineThickness(5.0f);
                cell.setPosition(sf::Vector2f(i * 300, j * 300));

                window.draw(cell);
            }
            else if(field[i][j] == 1)
            {
                sf::RectangleShape cell = sf::RectangleShape(sf::Vector2f(295, 295));
                cell.setFillColor(sf::Color(80, 90, 100));
                cell.setOutlineColor(sf::Color(0, 0, 0));
                cell.setOutlineThickness(5.0f);
                cell.setPosition(sf::Vector2f(i * 300, j * 300));

                window.draw(cell);

                occupied_cell.setTexture(texture_x);
                occupied_cell.setPosition(10 + i * 315, 10 + j * 315);
                window.draw(occupied_cell);              
            }
            else if(field[i][j] == 2)
            {
                sf::RectangleShape cell = sf::RectangleShape(sf::Vector2f(295, 295));
                cell.setFillColor(sf::Color(80, 90, 100));
                cell.setOutlineColor(sf::Color(0, 0, 0));
                cell.setOutlineThickness(5.0f);
                cell.setPosition(sf::Vector2f(i * 300, j * 300));

                window.draw(cell);

                occupied_cell.setTexture(texture_o);
                occupied_cell.setPosition(10 + i * 315, 10 + j * 315);
                window.draw(occupied_cell);                     
            }
        }
    }

    if(game_over)
        window.draw(winning_text);
}

void Board::changeMatrix(sf::Vector2i mousePos) {
    int coordX, coordY;

    coordX = mousePos.x / 300;
    coordY = mousePos.y / 300;

    // We can only play if it is our turn.
    if(is_player_turn)
    {
        // And we clicked on a valid cell.
        if(this->field[coordX][coordY] == 0)
        {
            this->field[coordX][coordY] = 1;
            is_player_turn = false;
        }
    }
}

void Board::checkWinner() {
    // Check rows for a winner.
    for(int i = 0; i < 3; i++)
    {
        if(field[i][0] == 1 && field[i][1] == 1 && field[i][2] == 1)
        {
            this->game_over = true;
            winning_text.setString("YOU WIN!");
            return;
        }
        else if(field[i][0] == 2 && field[i][1] == 2 && field[i][2] == 2)
        {
            this->game_over = true;
            winning_text.setString("YOU LOSE!");
            winning_text.setPosition(310, 400);
            return;
        }
    }

    // Check columns for a winner.
    for(int j = 0; j < 3; j++)
    {
        if(field[0][j] == 1 && field[1][j] == 1 && field[2][j] == 1)
        {
            this->game_over = true;
            winning_text.setString("YOU WIN!");
            return;
        }
        else if(field[0][j] == 2 && field[1][j] == 2 && field[2][j] == 2)
        {
            this->game_over = true;
            winning_text.setString("YOU LOSE!");
            winning_text.setPosition(310, 400);
            return;
        }
    }

    // Check the two diagonals as well.
    if((field[0][0] == 1 && field[1][1] == 1 && field[2][2] == 1) ||
        (field[2][0] == 1 && field[1][1] == 1 && field[0][2] == 1))
    {
        this->game_over = true;
        winning_text.setString("YOU WIN!");
        return;
    }
    if((field[0][0] == 2 && field[1][1] == 2 && field[2][2] == 2) ||
            (field[2][0] == 2 && field[1][1] == 2 && field[0][2] == 2))
    {
        this->game_over = true;
        winning_text.setString("YOU LOSE!");
        winning_text.setPosition(310, 400);
        return;
    }

    // If we still didn't find a winner, go through
    // the grid and look if any cell is not occupied.
    // Return that the game isn't over if you find one.
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(field[i][j] == 0)
            {
                this->game_over = false;
                return;
            }
        }
    }

    // All previous checks have failed and we have a draw.
    this->game_over = true;
    winning_text.setString("DRAW!");
    winning_text.setPosition(360, 405);
    return;        
}

void Board::reset() {
    this->field = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    this->game_over = false;
    this->is_player_turn = true;
}