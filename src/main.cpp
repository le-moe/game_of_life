#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <stdlib.h> // srand rand
#include <time.h> //time
#include "board.hpp"
#include "config.hpp"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(WINW, WINH), "Game of Life");

    // Create board
    Board board = Board(WIDTH, HEIGHT, SCALE);
    board.randomize();

    // board.printCells();
    board.toArray();
    // board.Debug();
    board.printBoard();
    board.printBoardNeighbour();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        if(Mouse::isButtonPressed(Mouse::Left))
        {
            // Vector2i pos = Mouse::getPosition(window);
            // printf("x: %i, y: %i\n", pos.x, pos.y);
        }


        Image img;
        img.create(WINW, WINH, board.getPixels());

        Texture texture;
        texture.create(WINW,WINH);
        texture.loadFromImage(img);

        Sprite sprite;
        sprite.setTexture(texture);
        window.clear();
        window.draw(sprite);
        window.display();
        
        // sf::sleep(sf::seconds(1));
        // board.epoch();
        // board.toArray();
    }

    return 0;
}
